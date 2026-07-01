"""Coordinate decomp work via the belongto.us claims lock service so multiple bots
do not grind the same address ranges. Programmatic sibling of CLAIMS.md.

Lock flow: try-lock a (module, start, end) span -> renew while working -> release when
done. No auth token. Handle identifies this worker. Endpoints:
  POST /api/claims/try-lock     {module,start,end,handle,note} -> {id,...}
  POST /api/claims/{id}/renew   {handle}
  POST /api/claims/{id}/release {handle}
  GET  /api/claims/check?module=&start=&end=   (read-only preview)

The API key is NOT in this file: it comes from the CLAIMS_API_KEY env var or the
gitignored tools/claims_key.txt. Without a key, check() still works read-only;
lock/renew/release will 401 (coordinate via CLAIMS.md instead).

CLI:
  python tools/claims.py check    --module ov006 --start 0x020f0000 --end 0x020f0100
  python tools/claims.py lock     --module ov006 --start 0x020f0000 --end 0x020f0100 --note "matching"
  python tools/claims.py renew    --id <claim_id>
  python tools/claims.py release  --id <claim_id>
  python tools/claims.py lock-worklist  progress/wl.jsonl     # per-module spans, prints id map
  python tools/claims.py release-ids    id1 id2 ...
"""
import json
import os
import sys
import urllib.request
import urllib.parse

BASE = "https://belongto.us"
HANDLE = "Tango Claude"


def _load_key():
    """CLAIMS_API_KEY env var, else the gitignored tools/claims_key.txt sibling."""
    k = os.environ.get("CLAIMS_API_KEY")
    if k:
        return k.strip()
    import pathlib
    p = pathlib.Path(__file__).resolve().parent / "claims_key.txt"
    if p.is_file():
        return p.read_text(encoding="utf-8").strip()
    return None


API_KEY = _load_key()


def _req(path, payload=None, method="GET"):
    data = json.dumps(payload).encode() if payload is not None else None
    headers = {"Content-Type": "application/json"} if data else {}
    if API_KEY:
        headers["X-Api-Key"] = API_KEY
    req = urllib.request.Request(BASE + path, data=data, headers=headers, method=method)
    try:
        with urllib.request.urlopen(req, timeout=25) as r:
            body = r.read().decode()
            return r.status, (json.loads(body) if body.strip() else {})
    except urllib.error.HTTPError as e:
        return e.code, {"error": e.read().decode()[:300]}
    except Exception as e:
        return None, {"error": str(e)}


def try_lock(module, start, end, handle=HANDLE, note=""):
    return _req("/api/claims/try-lock", {"module": module, "start": start, "end": end,
                                         "handle": handle, "note": note}, "POST")


def renew(claim_id, handle=HANDLE):
    return _req(f"/api/claims/{claim_id}/renew", {"handle": handle}, "POST")


def release(claim_id, handle=HANDLE):
    return _req(f"/api/claims/{claim_id}/release", {"handle": handle}, "POST")


def check(module, start, end):
    q = urllib.parse.urlencode({"module": module, "start": start, "end": end})
    return _req(f"/api/claims/check?{q}")


def _spans(path):
    """{module: (start_hex, end_hex)} covering every function's addr..addr+size."""
    by = {}
    for line in open(path, encoding="utf-8"):
        if not line.strip():
            continue
        r = json.loads(line)
        a = int(r["addr"], 16) if isinstance(r["addr"], str) else r["addr"]
        sz = int(r["size"], 16) if isinstance(r["size"], str) else r["size"]
        lo, hi = by.get(r["module"], (a, a + sz))
        by[r["module"]] = (min(lo, a), max(hi, a + sz))
    return {m: (f"0x{lo:08x}", f"0x{hi:08x}") for m, (lo, hi) in by.items()}


def _claim_id(res):
    """The claim id lives at res['claim']['id'] (try-lock 201 response)."""
    return res.get("claim", {}).get("id") if isinstance(res, dict) else None


def lock_worklist(path, handle=HANDLE, note="crack-loop matching (Tango Claude)"):
    """Lock each module's address span in the worklist. Returns {module: claim_id};
    skips a module the check reports not free (conflicts held by someone else)."""
    ids = {}
    for mod, (start, end) in _spans(path).items():
        st, cur = check(mod, start, end)
        if isinstance(cur, dict) and cur.get("free") is False:
            print(f"  SKIP {mod} {start}-{end}: conflicts={cur.get('conflicts')}")
            continue
        st, res = try_lock(mod, start, end, handle, note)
        cid = _claim_id(res)
        print(f"  LOCK {mod} {start}-{end}: status={st} id={cid}" + ("" if cid else f" resp={res}"))
        if cid:
            ids[mod] = cid
    return ids


def main():
    a = sys.argv
    if len(a) < 2:
        print(__doc__); return
    cmd = a[1]

    def opt(name, default=None):
        return a[a.index(name) + 1] if name in a else default

    if cmd == "check":
        print(json.dumps(check(opt("--module"), opt("--start"), opt("--end")), indent=1))
    elif cmd == "lock":
        print(json.dumps(try_lock(opt("--module"), opt("--start"), opt("--end"),
                                  opt("--handle", HANDLE), opt("--note", "")), indent=1))
    elif cmd == "renew":
        print(json.dumps(renew(opt("--id"), opt("--handle", HANDLE)), indent=1))
    elif cmd == "release":
        print(json.dumps(release(opt("--id"), opt("--handle", HANDLE)), indent=1))
    elif cmd == "lock-worklist":
        import pathlib
        ids = lock_worklist(a[2])
        pathlib.Path("progress/claims_active.json").write_text(json.dumps(ids))
        print("CLAIM_IDS " + json.dumps(ids))
    elif cmd == "release-active":
        import pathlib
        p = pathlib.Path("progress/claims_active.json")
        ids = json.loads(p.read_text()) if p.exists() else {}
        for mod, cid in ids.items():
            print(f"  release {mod} {cid}: {release(cid)}")
        p.unlink(missing_ok=True)
    elif cmd == "release-ids":
        for cid in a[2:]:
            print(cid, release(cid))
    else:
        print(__doc__)


if __name__ == "__main__":
    main()
