# The last two arm9 functions: why 1.2 can't match them, and the 2.0-vs-asm-hatch decision

**TL;DR** — arm9 has two remaining functions that cannot be matched by writing better C.
It is **proven** they were not built by mwccarm 1.2 (the compiler this project uses); their
byte layout is unreachable from any 1.2 source. The fingerprint points to a **later mwccarm
(the 2.0 family)** as what actually built them — that part is a strong inference, not a
reproduced fact (see *How sure are we?* below). Either way, closing them needs a
project-level decision: **(A)** wire a 2.0 compiler into the build for these files, or
**(B)** accept a hand-written assembly ("asm hatch"). This is a maintainer call, not more
matching effort.

---

## The two functions

| Function | Module | Address | Size | What it is |
|---|---|---|---|---|
| `func_0206e4a4` | arm9 | `0x0206e4a4` | 0x83c (2108 B) | MSL `__pformatter` — the core of `printf` |
| `func_0206f46c` | arm9 | `0x0206f46c` | 0x3b4 (948 B) | MSL `float2hex` — `%a`/`%A` hex-float formatting |

Both are internals of **MSL** (Metrowerks Standard Library), the C runtime that ships
*with* the compiler rather than being written by the game's developers.

## What "matching" requires

This project doesn't just need C that behaves correctly — it needs C that, compiled by
**one specific compiler (mwccarm 1.2/sp2p3)**, produces the **exact same bytes** as the
retail cartridge. Byte-identical, or it doesn't count.

## The root cause: the ROM wasn't built by only one compiler

A shipped game is assembled from many pieces, compiled at different times. The bulk of
SM64DS was built with **mwccarm 1.2**. These two MSL objects were not — their code-generation
fingerprint is one 1.2 never produces.

The tell is in how the **stack** (the CPU's scratch workspace during a function call) is used
to pass a struct argument by value:

- The **ROM's** code stages the by-value struct *below* the stack pointer with **no stack
  adjustment and no frame pointer** — a compact, bookkeeping-free sequence
  (`add r0,sp,#0x34; sub r5,sp,#8; ldm r0,{r0-r3}; stm r5,{r0-r3}`).
- **1.2 cannot emit that.** From *every* source phrasing it instead emits
  `sub ip,sp,#8; mov sp,ip; … add sp,ip,#8`, which pins `mov fp,sp`, pulls the frame-pointer
  register into the saved-register set, and grows the stack frame (0x244 → 0x24c).

Those extra instructions shift every subsequent stack offset in the function. The divergence
is baked into the compiler's code-generation habits, **below the level any C source can
control**.

## How sure are we? (proven vs. inferred)

Being explicit, because "compiled with 2.0" is easy to overstate:

**Proven — 1.2 cannot produce these bytes.** Verified exhaustively this project: multiple
agents drove `func_0206e4a4` from 872 down to a hard floor of 253 differing instructions
(the honest by-value draft of `func_0206f46c` floors at 149), across 1.2 base/sp2/sp2p3/sp3/sp4
and ~75 flag combinations, C and C++. The residual is entirely the stack-frame shape above and
is invariant to source phrasing. **This is the claim that matters** for "can we match at 1.2":
the answer is no, and it is a reproduced fact.

**Strong inference — the culprit is the 2.0-family compiler.** This is *not* a reproduced
byte-match; nobody has compiled these two functions with a 2.0 compiler and shown byte
identity (doing so requires a 2.0 toolchain the project does not yet have — that is Option A).
It rests on three converging pieces of evidence:

1. **Corpus fingerprint.** The below-`sp`, no-frame-pointer staging idiom appears **nowhere in
   the entire 1.2-matched corpus** (hundreds of functions). It is not a phrasing we haven't
   found — it is a shape 1.2 does not emit, while it is a documented trait of the later
   mwccarm (2.0) code generator.
2. **A sibling family that *was* test-compiled with 2.0.** A separate group in the ROM — the
   four `ActorBase::Process` pointer-to-member wrappers — shows the same fixed-frame staging
   idiom and is likewise unmatchable at 1.2. Those were actually compiled with a 2.0 compiler
   and came within **one instruction** of the ROM. That is the closest thing to direct 2.0
   evidence, though it is a different set of functions.
3. **External corroboration.** pokediamond (another DS decomp) treats its Nintendo-built
   `__pformatter` as hand-written assembly, still unmatched `.s` after years — the same
   function hitting the same wall in a sibling project.

**Bottom line:** "not 1.2" is a fact; "2.0 specifically" is a best-fit attribution from the
fingerprint plus a sibling-family measurement. The clean way to *confirm* it is the same as
fixing it — compile these two with a 2.0 compiler and check for a byte-match (Option A below).

## The two ways to close them

### Option A — the "2.0 path" (the correct fix, and the way to confirm the diagnosis)

Obtain a **mwccarm 2.0** compiler, wire it into the build, and compile *just these MSL files*
with it. If they byte-match, the inference above becomes a confirmed fact and the functions are
matched in one stroke.

- **Pro:** genuine, readable C; matches the way the ROM was actually produced; simultaneously
  proves the 2.0 attribution.
- **Con:** a real infrastructure change — sourcing, integrating, and configuring a second
  compiler version in the build, plus per-file compiler selection. (And a small residual risk:
  if 2.0 does *not* byte-match, the attribution was wrong and only Option B remains.)

### Option B — the "asm hatch" (the pragmatic fix)

"Asm hatch" = *assembly escape hatch*. Instead of C, drop in the exact machine instructions
(raw assembly) for these two functions and tell the build to use those bytes verbatim rather
than compile anything.

- **Pro:** guaranteed byte-match immediately; small, contained; does not depend on the 2.0
  attribution being correct.
- **Con:** not truly "decompiled" — it's a transcription, not readable C. Standard practice in
  decomp projects for a handful of genuinely unreachable functions.

## Recommendation

Both are legitimate. Most decomp projects take the **asm hatch** for isolated library-runtime
functions like these and reserve the effort of integrating a second compiler for cases where
many functions need it. If a 2.0-built layer turns out to contribute *many* functions across
the ROM (the MSL and PTMF-wrapper findings suggest there may be more than these two), the
**2.0 path** pays for itself and confirms the diagnosis; if it's just a handful, the **asm
hatch** is the lower-cost close.

Either way, no amount of additional C-matching effort will crack them — the decision is about
how the project wants to handle compiler-version-mismatched library code.

---

*Context: these two are the only functions blocking a literal 100% match of the arm9 module.
The rest of arm9's remaining work is ordinary near-misses (register-allocation /
instruction-ordering residuals) that are being closed the normal way. The codegen evidence
above is recorded in more detail in `notes/mwccarm-codegen.md` section 9.*
