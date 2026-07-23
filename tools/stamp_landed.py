"""Stamp match provenance for functions that became matched in a commit range.

The provenance ledger (config/match_provenance.jsonl) answers HOW a function was
matched, as opposed to contributions.json which answers WHO matched it. Both stores
existed for weeks with zero rows, because stamping was a manual step
(tools/stamp_provenance.py) that nobody ran per function. Reconstructing it later is
mostly impossible: only ~13% of matched functions land in a commit that names a model,
and the rest arrived in early bulk commits like "Add matched functions, taking progress
to 25.9%". So the method has to be captured as the match lands or not at all.

This runs as a CI backstop over whatever range was just pushed, so every landing gets
stamped regardless of who pushed it -- Console batches, agent PRs, and hand-written
work all go through main. Anything the Console stamps precisely at bank time wins,
because existing ids are never overwritten.

IT DECLINES TO GUESS. A row is written only when the landing commit actually names a
method, or the source is hand-written assembly. An unlabelled commit leaves the
function unstamped, which reads as "not recorded" rather than inventing a model and a
reasoning level that nobody can vouch for. A sparse honest ledger beats a full fake one.

  python tools/stamp_landed.py --range origin/main~5..origin/main
  python tools/stamp_landed.py --dry-run          # print what it would stamp
"""
import argparse
import json
import os
import pathlib
import re
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import match_provenance as MP  # noqa: E402

BANNER = "// NONMATCHING"

# Ordered: first hit wins, so put the specific patterns above the generic ones.
# harness is the thing that drove the model, not the person operating it.
MODELS = [
    (r"\bglm[- ]?5\.2\b", "glm-5.2"),
    (r"\bglm\b", "glm"),
    (r"\bopus\b", "opus-4.8"),
    (r"\bsonnet\b", "sonnet-5"),
    (r"\bfable\b", "fable"),
    (r"\bdeepseek[- ]?v4[- ]?pro\b", "deepseek-v4-pro"),
    (r"\bdeepseek\b", "deepseek"),
    (r"tangos\(gpt\)|\bgpt-?5\.6\b", "gpt-5.6-luna"),
    (r"\bgrok\b", "grok"),
    (r"\bcodex\b", "codex"),
]
HARNESSES = [
    (r"^tangos\(", "tangos-console"),
    (r"\brefine\b", "refine"),
    (r"\bpermuter\b", "permuter"),
    (r"\bfan-?out\b|\bharvest\b|\bsweep\b|\bbatch\b|\bprobe\b", "fanout"),
]
REASONING = [(r"\bhigh\b", "high"), (r"\bmedium\b", "medium"), (r"\blow\b", "low")]


def sh(*args: str) -> str:
    return subprocess.run(args, cwd=REPO, capture_output=True, text=True,
                          encoding="utf-8", errors="replace").stdout


def blob(rev: str, path: str) -> str:
    return sh("git", "show", f"{rev}:{path}")[:400]


def first(table, text, default=None):
    for pattern, value in table:
        if re.search(pattern, text):
            return value
    return default


def derive(subject: str, src_text: str) -> dict | None:
    """The how-record for this landing, or None when it cannot be established."""
    if "HAND-ASM" in src_text:
        # An asm body is the method: no model wrote C for this one.
        return {"kind": "human", "note": "hand-written assembly"}
    low = subject.lower()
    model = first(MODELS, low)
    if not model:
        return None                      # unlabelled: leave unstamped rather than guess
    return {
        "kind": "ai",
        "model": model,
        # The commit rarely states effort. "unspecified" is a truthful token; it does
        # not claim a level, and it keeps the record distinguishable from a real one.
        "reasoning": first(REASONING, low, "unspecified"),
        "harness": first(HARNESSES, low, "unspecified"),
    }


def symbol_index() -> dict[str, tuple[str, int, int]]:
    """name -> (module, addr, size), read from every committed symbols.txt."""
    out: dict[str, tuple[str, int, int]] = {}
    pattern = re.compile(
        r"^(\S+)\s+kind:function\([^)]*size=(0x[0-9a-fA-F]+)\)\s+addr:(0x[0-9a-fA-F]+)")
    for path in (REPO / "config").rglob("symbols.txt"):
        label = "arm9" if "overlays" not in str(path) else path.parent.name
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            m = pattern.match(line)
            if m:
                out[m.group(1)] = (label, int(m.group(3), 16), int(m.group(2), 16))
    return out


def landings(rev_range: str) -> list[tuple[str, str, str]]:
    """(path, commit subject, blob text) for each src file that BECAME matched here.

    Full history, because `git log -- <path>` prunes commits reached through a merge
    and would silently drop matches that landed on a side branch.
    """
    base, _, head = rev_range.partition("..")
    base, head = base or "HEAD~1", head or "HEAD"
    REC, FLD = "\x01", "\x02"
    out = sh("git", "log", "--full-history", "--reverse", f"--format={REC}%H{FLD}%s",
             "--name-status", "-M", f"{base}..{head}", "--", "src/")
    sha = subject = None
    seen: dict[str, tuple[str, str]] = {}
    for line in out.splitlines():
        if line.startswith(REC):
            sha, _, subject = line[1:].partition(FLD)
            continue
        if not sha or not line.strip():
            continue
        parts = line.split("\t")
        if len(parts) < 2 or parts[0].startswith("D"):
            continue
        path = parts[-1].strip()
        if not path.endswith((".c", ".cpp")):
            continue
        text = blob(sha, path)
        if not text or BANNER in text:
            continue                     # still a draft after this commit
        if BANNER not in blob(f"{base}", path) and blob(f"{base}", path):
            continue                     # already matched before the range
        seen.setdefault(path, (subject, text))
    return [(p, s, t) for p, (s, t) in seen.items()]


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--range", default=None,
                    help="git range, e.g. abc123..def456 (default: the pushed range)")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    rev_range = args.range or (
        f"{os.environ['GITHUB_EVENT_BEFORE']}..{os.environ['GITHUB_SHA']}"
        if os.environ.get("GITHUB_EVENT_BEFORE", "").strip("0") and os.environ.get("GITHUB_SHA")
        else "HEAD~1..HEAD")

    syms = symbol_index()
    ledger = MP.load_ledger()
    stamped = skipped = unlabelled = 0
    for path, subject, text in landings(rev_range):
        name = path.split("/")[-1].rsplit(".", 1)[0]
        info = syms.get(name)
        if not info:
            continue
        module, addr, _ = info
        if MP.make_id(module, addr) in ledger:
            skipped += 1                 # a precise stamp already exists; never overwrite
            continue
        prov = derive(subject, text)
        if not prov:
            unlabelled += 1
            continue
        if args.dry_run:
            print(f"  would stamp {name}  {json.dumps(prov)}")
            stamped += 1
            continue
        try:
            MP.append_ledger_row(module=module, addr=addr, name=name,
                                 provenance=prov, src_path=path)
            stamped += 1
        except MP.ProvenanceError as exc:
            print(f"  skip {name}: {exc}", file=sys.stderr)
    print(f"provenance: stamped {stamped}, already recorded {skipped}, "
          f"unlabelled {unlabelled} ({rev_range})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
