//cpp
// NONMATCHING: push-set / frame (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C; typedef void (C::*PMF)(int);
struct Entry { PMF pmf; };
extern Entry data_ov006_021426f4[];
struct C { char pad[1]; };
extern "C" void func_ov006_02102e8c(C *c);
void func_ov006_02102e8c(C *c) {
    int i;
    for (i = 0; i < 0x30; i++) {
        if (*(unsigned char *)((char *)c + i * 0x40 + 0x4698) != 0) {
            unsigned char k = *(unsigned char *)((char *)c + i * 0x40 + 0x4699);
            (c->*data_ov006_021426f4[k].pmf)(i);
        }
    }
}
