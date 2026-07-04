//cpp
// NONMATCHING: register allocation (div=29). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct S2 { int a, b; };
extern "C" {
extern struct S2 data_ov002_0210c040;
extern struct S2 data_ov002_0210c010;
extern struct S2 data_ov002_0210c020;
extern struct S2 data_ov002_0210c038;
extern struct S2 data_ov002_0210c030;
extern struct S2 data_ov002_0210c018;
extern struct S2 data_ov002_0210c028;
extern struct S2 data_ov002_0211110c[7];
void __sinit_ov002_02107f88(void) {
    data_ov002_0211110c[0] = data_ov002_0210c040;
    data_ov002_0211110c[1] = data_ov002_0210c010;
    data_ov002_0211110c[2] = data_ov002_0210c020;
    data_ov002_0211110c[3] = data_ov002_0210c038;
    data_ov002_0211110c[4] = data_ov002_0210c030;
    data_ov002_0211110c[5] = data_ov002_0210c018;
    data_ov002_0211110c[6] = data_ov002_0210c028;
}
}
