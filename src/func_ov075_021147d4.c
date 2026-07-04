//cpp
// NONMATCHING: base materialization / addressing (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern short Vec3_HorzAngle(void* a, void* b);
extern int _Z14ApproachLinearRsss(short* a, short b, short c);
extern int func_ov075_02114a6c(char* c);
void func_ov075_021147d4(char* c){
  if (*(int*)(c+0x118) != *(int*)(c+0x124)) {
    short ang = Vec3_HorzAngle(c+0x118, c+0x124);
    if (_Z14ApproachLinearRsss((short*)(c+0x150), ang, 0x800) == 0) return;
    *(int*)(c+0x118) = *(int*)(c+0x118) + *(int*)(c+0x13c);
    if (*(int*)(c+0x13c) >= 0) {
      if (*(int*)(c+0x118) > *(int*)(c+0x124)) *(int*)(c+0x118) = *(int*)(c+0x124);
      return;
    }
    if (*(int*)(c+0x118) < *(int*)(c+0x124)) *(int*)(c+0x118) = *(int*)(c+0x124);
    return;
  }
  if (_Z14ApproachLinearRsss((short*)(c+0x150), 0, 0x800) == 0) return;
  func_ov075_02114a6c(c);
}
}
