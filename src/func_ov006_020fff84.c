//cpp
// NONMATCHING: push-set / frame (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C; typedef void (C::*PMF)(int);
struct Entry { PMF pmf; };
extern Entry data_ov006_021426cc[];
struct C { char pad[1]; };
extern "C" void func_ov006_020fff84(C *c);
void func_ov006_020fff84(C *c) {
    int i;
    for (i = 0; i < 2; i++) {
        if (*(unsigned char *)((char *)c + i * 0x20 + 0x5634) != 0) {
            unsigned char k = *(unsigned char *)((char *)c + i * 0x20 + 0x5635);
            (c->*data_ov006_021426cc[k].pmf)(i);
        }
    }
}
