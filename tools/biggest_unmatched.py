"""List the N biggest UNMATCHED functions (no committed src, not parked, not a thunk).
Reuses coddog.build_corpus so the definition of 'unmatched' matches the scheduler."""
import argparse, pathlib, sys
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import coddog

ap = argparse.ArgumentParser()
ap.add_argument("--limit", type=int, default=20)
ap.add_argument("--min", type=lambda x: int(x, 0), default=0)
ap.add_argument("--max", type=lambda x: int(x, 0), default=0x100000)
a = ap.parse_args()

matched, unmatched, mods = coddog.build_corpus()
rows = [u for u in unmatched if a.min <= u["size"] <= a.max]
rows.sort(key=lambda u: -u["size"])
print(f"{'name':40} {'module':6} {'size':>8}  {'addr':>10}  ops")
for u in rows[:a.limit]:
    print(f"{u['name']:40} {u['module']:6} {u['size']:#8x}  {u['addr']:#010x}  {len(u['ops'])}")
