# Near-miss database

`db.jsonl` is the persistent store of close-but-not-matched function attempts -- compiling
C from the fan-out (and hand-cracking) that did not byte-match, kept forever and ranked by
how few instructions diverge from the ROM. These are the most valuable byproduct of the
matching effort: logically correct, already compiling, often 1-4 instructions from done.

Why keep them: re-deriving a near-match costs LLM tokens; finishing one is cheap (a small
fix, the permuter, or a stronger future model). This pre-positions the hard residue at ~95%
so the final push is fast and cheap instead of starting from scratch.

One record per (module, addr), keeping the CLOSEST candidate:
  {module, addr, name, size, target_hex, lang, divergences, c_source, source}

Managed by `tools/nearmiss_db.py` (ingest / stats / list / export-close / bank-matches).
Run `python tools/permuter/crunch.py` to grind the closest ones through the permuter locally
(free), banking any that reach a match.

## Standing rule: every batch feeds this DB

A harvest/fan-out batch must save its misses, not just its matches. Do not let this starve.

1. The fan-out agent prompt MUST ask each agent to emit a SECOND file of near-misses next to
   its matches: compiling, structurally-correct C that did not byte-match, as
   `{name, module, addr, c_source}`. The permuter only fixes register allocation and
   instruction ordering, so the seed must have the right instructions in the right shape -- a
   draft missing instructions (e.g. base-materialization floor) is not useful fuel.
2. After banking the matches, ingest the misses:
   `python tools/nearmiss_db.py ingest --seeds <file> --label <batch>`.
3. Work the backlog: `list --max-div 4` is the closest-first by-hand queue; `export-close` +
   `tools/permuter/batch.py --seeds` (or `crunch.py`) grinds them; `bank-matches` re-checks all
   entries and banks any that now reach a byte match.

Why: re-deriving a 95%-done attempt costs tokens; finishing one (a small fix, the permuter, or a
stronger model later) is cheap. The misses are the most valuable byproduct of every batch.
