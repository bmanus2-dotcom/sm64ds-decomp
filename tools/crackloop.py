"""One-command driver for the crack loop. Wraps the full runbook sequence so a
batch is exactly three steps: prep -> Workflow -> land.

  python tools/crackloop.py prep --min 0x100 --max 0x280 --limit 30
      coddog-schedules a fresh spread worklist to progress/wl_ab.jsonl, locks the
      module spans via the claims service (skipped gracefully on a public clone
      without tools/claims.py), trims the worklist to the modules actually locked,
      and prints the names array to paste into the Workflow launch:
        Workflow({ scriptPath: "tools/sched_run.js", args: <names> })

  python tools/crackloop.py land --output <the Workflow task .output file>
      banks the result (independent re-verify, parks misses, ingests near-misses),
      runs the free post-pass (clone + paramclone), releases the claims, and
      prints fresh progress.

  python tools/crackloop.py refine --max-div 6 --limit 20
      exports the closest fixable near-misses from nearmiss/db.jsonl (category-routed,
      see tools/refine_wl.py) and prints the refine_run.js launch line. Land a refine
      batch with:  python tools/crackloop.py land --output <out> --refine

Every underlying tool still works standalone; this only sequences them.
"""
import argparse
import json
import pathlib
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
TOOLS = REPO / "tools"
WL = REPO / "progress" / "wl_ab.jsonl"


def run(script, *args, check=True):
    cmd = [sys.executable, str(TOOLS / script), *args]
    print(f"\n>> {script} {' '.join(args)}")
    return subprocess.run(cmd, check=check).returncode


def prep(a):
    active = REPO / "progress" / "claims_active.json"
    if active.exists():
        print("a batch appears to be in flight (progress/claims_active.json exists).\n"
              "Regenerating the worklist now would swap target bytes under running agents.\n"
              "Land it first (crackloop.py land) or release: python tools/claims.py release-active")
        sys.exit(1)
    cd = ["--min", hex(a.min), "--max", hex(a.max), "--limit", str(a.limit),
          "--out", str(WL)]
    if a.module:
        cd += ["--module", a.module]
    if not a.no_spread:
        cd += ["--spread"]
    run("coddog.py", *cd)

    rows = [json.loads(l) for l in WL.read_text(encoding="utf-8").splitlines() if l.strip()]
    if not rows:
        print("worklist is empty - nothing to do"); sys.exit(1)

    try:
        sys.path.insert(0, str(TOOLS))
        import claims
        ids = claims.lock_worklist(str(WL))
        (REPO / "progress" / "claims_active.json").write_text(json.dumps(ids))
        if ids:
            kept = [r for r in rows if r["module"] in ids]
            if len(kept) != len(rows):
                WL.write_text("".join(json.dumps(r) + "\n" for r in kept), encoding="utf-8")
                print(f"trimmed worklist to locked modules: {len(kept)}/{len(rows)} rows kept")
            rows = kept
        else:
            print("WARNING: no locks obtained (service down?) - keeping the full "
                  "worklist; coordinate manually via CLAIMS.md")
    except ImportError:
        print("tools/claims.py not present (public clone) - skipping the lock step; "
              "coordinate via CLAIMS.md")

    names = [r["name"] for r in rows]
    print(f"\n{len(names)} functions ready. Launch:")
    print(f'Workflow({{ scriptPath: "tools/sched_run.js", args: {json.dumps(names)} }})')


def refine(a):
    run("refine_wl.py", "--max-div", str(a.max_div), "--limit", str(a.limit))
    print("\nthen land with: python tools/crackloop.py land --output <task.output> --refine")


def land(a):
    wl = str(REPO / "progress" / ("wl_refine.jsonl" if a.refine else "wl_ab.jsonl"))
    bank = ["--output", a.output, "--wl", a.wl or wl]
    if a.refine:
        bank.append("--no-park")
    run("bank_run.py", *bank, check=False)
    run("clone.py", check=False)
    run("paramclone.py", check=False)
    if not a.refine:
        try:
            sys.path.insert(0, str(TOOLS))
            import claims  # noqa: F401
            subprocess.run([sys.executable, str(TOOLS / "claims.py"), "release-active"], check=False)
        except ImportError:
            pass
    run("progress.py", check=False)
    print("\nbatch landed. Commit when ready: git add src/ nearmiss/ README.md && "
          "git commit -m \"Match N functions via coddog fan-out (XX.X%)\"")


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("prep", help="build + claim + trim a fresh worklist")
    p.add_argument("--min", type=lambda x: int(x, 0), default=0x100)
    p.add_argument("--max", type=lambda x: int(x, 0), default=0x280)
    p.add_argument("--limit", type=int, default=30)
    p.add_argument("--module", default=None)
    p.add_argument("--no-spread", action="store_true")
    p.set_defaults(fn=prep)
    p = sub.add_parser("refine", help="export closest fixable near-misses for refine_run.js")
    p.add_argument("--max-div", type=int, default=6)
    p.add_argument("--limit", type=int, default=20)
    p.set_defaults(fn=refine)
    p = sub.add_parser("land", help="bank + free post-pass + release + progress")
    p.add_argument("--output", required=True, help="Workflow task .output file")
    p.add_argument("--refine", action="store_true",
                   help="refine batch: use wl_refine.jsonl, no parking, no claims")
    p.add_argument("--wl", default=None, help="explicit worklist override")
    p.set_defaults(fn=land)
    a = ap.parse_args()
    a.fn(a)


if __name__ == "__main__":
    main()
