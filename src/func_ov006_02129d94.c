//cpp
// NONMATCHING: different op / idiom (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C; typedef void (C::*PMF)(int);
struct Entry { PMF pmf; };
extern Entry data_ov006_02143070[];
extern Entry data_ov006_02143020[];
struct C { char pad[1]; };
extern "C" void func_ov006_02129d94(C* c, int i) {
  int idx0 = *(unsigned char*)((char*)c + i * 0x24 + 0xbeb0);
  (c->*data_ov006_02143070[idx0].pmf)(i);
  int idx1 = *(unsigned char*)((char*)c + i * 0x24 + 0xbeb1);
  (c->*data_ov006_02143020[idx1].pmf)(i);
}
