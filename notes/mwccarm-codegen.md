# mwccarm codegen notes

How **mwccarm 1.2/sp2p3** (`-O4,p -enum int -lang c99 -char signed -interworking
-proc arm946e -gccext,on -msgstyle gcc`) turns C into the exact ARM bytes in the ROM.

The point of this file: **write the matching C with the compiler's habits in mind, so the
first draft is close and you iterate less.** It does *not* replace the oracle
(`tools/match.py` / `swarm.oracle_ok`) - register allocation in particular is non-local and
cannot be predicted by hand, so every candidate is still compiled and byte-diffed. Think of
this as the priors that get you from "plausible C" to "usually one or two tweaks away."

These rules were learned empirically from the 4,400+ matched (C -> exact-bytes) pairs in
`src/`, and most are encoded as template rules in `tools/swarm.py`. When you discover a new
one, add it here AND, if it recurs, as a rule in `swarm.py` so the free tier can sweep it.

---

## 1. Ground rules of the build

- **Reloc slots are wildcards.** Every `bl`/`blx` target and every pc-relative `ldr` of an
  external address is a relocation the oracle compares as a wildcard. So the *name* you call
  only has to compile - it does not have to be the byte-correct address. Still resolve the
  real callee name (the worklist does this for you) because it makes the C correct and keeps
  arg counts right.
- **Symbol size includes the trailing literal pool.** The pool words after the function
  disassemble as junk (`andeq`/`andseq`). `ins[-1]` is therefore **not** the `bx` - always
  find the epilogue (`mov r0,r4; pop; bx` or `mov r0,#k; add sp; ldm; bx`) by scanning, never
  by negative index.
- **`-O4,p` reorders and merges aggressively.** Pool loads get hoisted above their use;
  repeated globals collapse to a single pool word; loads are batched before stores. Write the
  straightforward C and let the optimizer reorder - do not hand-schedule.

## 2. The register-allocation wall (the dominant blocker)

This is *the* reason hard functions miss, and the one thing understanding-the-compiler can't
fully solve.

- mwccarm's allocator is **non-local**: which physical register a temp lands in depends on
  the whole function's pressure, not just the local statement. An isolated minimal function
  often colors a temp into `r1`; the ROM colored the same temp into `ip`/`r12`. The bytes
  differ only by that coloring (`triage.py` calls this **regperm**).
- You usually **cannot force `ip`/r12 coloring from C source**. Tried and failed: inline
  temporaries, `int` index vars, element-struct rewrites. If a candidate is byte-identical
  except for a consistent register renaming, it's regperm-blocked - flag it and move on, or
  hand-tune by changing the *shape* of the computation (extra/fewer temporaries) to nudge
  pressure. There is no reliable knob.
- Practical tell: if `match.py` shows the diff is only in register fields and the structure
  lines up, you're at the wall. Don't burn iterations re-expressing the same logic.

## 3. Leaf patterns (no calls)

- **Bitfield extract needs an *unsigned* pointer type.** `*(unsigned*)p >> sh & mask` emits
  `lsr`; a signed type emits `asr` and won't match. Same for `unsigned char`/`unsigned short`
  loads when you want zero-extension.
- **Two adjacent words load-load-store-store is a struct copy**, not two scalar assignments:
  `*(P2*)dst = *(P2*)src;` (or `= G;` for a global). mwccarm batches both loads then both
  stores; writing two separate assignments produces different bytes/ordering.
- **`add` folds into the addressing mode.** For `*(T*)(p+off) = 0`, don't model an explicit
  `add` - emit the store and let CW pick add-vs-direct by whether `off` fits the immediate.
  Tracking an effective offset through an `add rT,rB,#big` is enough; the compiler chooses.
- **Repeated global -> one pool word.** If the same global is referenced several times, CW
  loads it once. Emitting distinct extern names per use inflates the pool and breaks the size.
  Dedup globals by reloc-target identity.
- **Return-register discipline.** A real return loads into `r0` then `bx lr`. A tail-call
  veneer is `... ; bx ip` (a thunk) - `is_thunk()` filters these; they are not C-expressible.
- **`-char signed`.** Plain `char` is signed. Use `unsigned char` explicitly for byte flags
  and indices, which is almost always what the game means.

## 4. Call / reloc patterns

- **Wrapper:** save arg, call, return arg -> `X(a); return a;`.
- **ctor+vtable:** install vtable into `*this`, call `X(this)`, return this.
- **chain dtor:** a chain of single-pointer calls on `this(+off)`, returning this.
- **guard call:** `r = C1(this); if (!r) return r; return C2(this);` - the `beq` after the
  first call splits guarded-vs-after calls. Parse the branch target offset: calls whose `bl`
  offset is below the `beq` target are inside the guard (often just the first one).
- **frame call with pooled args:** a `stmdb` frame calling several functions whose args are
  pool-loaded globals. Reloc'd pool slot -> extern global; non-reloc slot -> literal const.
  Dedup globals by reloc identity (CW merges them).

## 5. C++ patterns - compile as C++, not C

The single biggest unlock. A source whose first line is a literal `//cpp` compiles with
`-lang c++` (and `extern "C"` keeps the symbol unmangled so the oracle finds it). Undefined
virtual methods are fine - we only `-c` compile, never link; only the vtable layout is read.

- **Virtual dispatch produces the pre-indexed writeback `ldr rV,[r0,#OFF]!`** that *no* C and
  no compiler flag will emit. Real C++ virtual dispatch through a pointer emits it exactly:
  ```cpp
  struct Base { virtual void v0(); ... virtual void m(); };  // VOFF/4 dummies before m
  Base* b = &this->base; b->m(ARG); return RET;
  ```
  CW also has a split form `add r0,r0,#OFF; ldr rV,[r0]` - it picks per offset; both come from
  the same C++.
- **Pointer-to-member-function (PMF) call** has a fixed ARM ABI prologue:
  `ldr r3,[r0,#OFF]; ldr r1,[r3,#4]; add r0,r0,r1,asr#1; ands r1,r1,#1; ldrne...; blx`.
  Source: `PMF* p = c->pp [+ N/8]; (c->**p)();` with `typedef void (C::*PMF)();`. The
  `add r3,rA,#N` selects the (N/8)th PMF. Guarded/result-returning variants exist (null-check
  -> return a parameterized const; or return the call's int result).
- **PMF-table dispatch:** `(c->*TABLE[c->idx].pmf[k])()` - the global TABLE is reloc-wildcarded
  so it stays a leaf; element size comes from the `lsl#SH`.
- **Deleting destructor:** vtable install (compiler **hoists** the vtable pool-load above
  `mov r4,r0`, so don't pin it to a fixed position), then `D1(this)`, then a 2-arg
  `Deallocate(this, HEAP)` (HEAP is a global loaded via `ldr;ldr`), return this.
- **`new T()`:** `p = NEW(sz); if (p) { CTOR(p+off)...; p[voff]=&VT... } return p;`. Size too
  big for `mov` comes from a pool `ldr` (read the literal from the bytes; bail if that slot is
  a reloc).

## 6. Idiom families worth knowing (high-count in the game)

- **Matrix/transform setup:** `Matrix4x3_FromRotationY(m, ang); ...ApplyInPlaceToRotationX(m,
  ang); MulVec3Mat4x3(in, m, out);` then add a base position and `ApproachLinear` toward it.
  Extremely common in actor `_Main` state handlers.
- **Fixed-point scale:** `(int)(((long long)a * b + 0x800) >> 12)` is the Fix12 multiply;
  `cstd::div`/`mod`/`fdiv` route through the DS hardware divider registers at `0x4000280+`.
- **Actor state machines** (`St_*_Init` / `St_*_Main`): set a run of `this+off` byte flags,
  `SetAnim(...)`, set velocity fields (`0x98`/`0xa8`...), call `ChangeState`/sound, return 1.
  These cluster hard - one cracked representative teaches the whole family.
- **Destructor chains** (`func_ovNN_...` returning this): a vtable install, several
  `SubObjectD1(this+off)` calls in reverse construction order, then `Deallocate`.

## 7. Workflow implications

- **Free tiers first, every cycle:** `clone.py` (byte-identical retarget) then `paramclone.py`
  (same skeleton, substituted immediates) - they harvest the families each new match unlocks
  for $0. Then `sweep.py` applies the templates above across all modules.
- **One representative -> a template.** When you hand-crack a function that clearly recurs,
  add a rule to `swarm.py` and `sweep.py --apply` clears the cluster for free. That is how the
  whole template tier was built and it's the cheapest way to lower difficulty in bulk.
- **The oracle stays.** Understanding shrinks the number of compile-and-check iterations; it
  never removes the check. "Matched" means the bytes are identical, full stop.

---

*Add to this file whenever you learn a new codegen rule. It is the project's accumulating
model of mwccarm - the cheaper, local alternative to disassembling the compiler itself.*
