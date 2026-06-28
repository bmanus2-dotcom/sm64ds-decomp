# Credits

This decompilation builds on reverse-engineering knowledge from the SM64DS community.

## Symbol names & struct layouts
- **SplattyDS / DynamicAllocationDecomp** (https://github.com/SplattyDS/DynamicAllocationDecomp)
 , source of verified function/data symbol names (`symbols.x`) and struct/actor-system
  header knowledge for the EU build. We import their **names and field offsets** (facts /
  interface) into our symbol database and notes; we do **not** copy their source code -
  all matching C in `src/` is written from scratch against our own ROM. Their addresses
  were independently verified against our `dsd` analysis (≈72% land exactly on functions
  we found, confirming the same EU build).
- **SplattyDS / SM64DS-ASM-Reference** and **Arisotura / SM64DSe**, upstream symbol /
  level-format documentation the above builds on.

If you contribute, keep this separation: import knowledge, write code.

## Matched-function contributions
- **Ryan Copley** (https://github.com/RyanCopley) - hand-wrote and verified matching C for a
  set of functions across ov002, ov006, arm9, and ov034 (PR #1). 22 of these were ones not
  yet matched here, including the first two functions in ov034 and several that had resisted
  our automated passes; all were independently re-verified byte-for-byte before landing.
- **Andrew Boudreau** (https://github.com/andrewboudreau) - hand-wrote and verified matching C
  for 9 functions across arm9, ov002, ov006, and ov007 (PR #2). These are reloc tail-call,
  guard-return, and call-forwarding shapes the automated passes deliberately skip; all were
  independently re-verified byte-for-byte, identical across the 1.2 base/sp2/sp2p3 trio, before
  landing. Followed up with 33 more matched functions across arm9, ov002, ov004, ov006, ov007,
  ov060, and ov102 (PRs #45 and #48) plus codegen notes; all 33 independently re-verified against
  the ROM before landing.
- **Moundistz** (https://github.com/Moundistz) - contributed 3 matched functions and 8
  nonmatching floor entries, plus a pass of placeholder-to-resolved callee renames across the
  arm9 corpus. Every candidate was independently re-verified against the ROM before landing;
  duplicate re-submissions of already-matched functions and a handful of match-to-nonmatching
  regressions were dropped.

## Tooling contributions
- **webheadvr** (https://github.com/webheadvr) - made the relocation symbol resolver
  module-aware: it now resolves by `(module, address)` instead of address alone, so a
  reloc is no longer mis-resolved to a symbol from a different overlay where overlay
  address ranges overlap. Also added ITCM/DTCM symbol support.
