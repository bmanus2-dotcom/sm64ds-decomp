// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_02110e28(char* c);

void START_INTRO_MINIMAP_ZOOM(char* c){
  *(int*)(c+0x10) = *(int*)(c+8);
  *(int*)(c+0x14) = *(int*)(c+0xc);
  if (*(unsigned char*)(*(char**)(c+4) + 0x595d) != 0)
    return;
  if (*(short*)(c+0x36) < *(short*)(c+0x34)) {
    short* p = (short*)(c+0x36);
    *p = *p + 8;
    if (*(short*)(c+0x36) > *(short*)(c+0x34))
      *(short*)(c+0x36) = *(short*)(c+0x34);
  } else {
    short* p = (short*)(c+0x36);
    *p = *p - 8;
    if (*(short*)(c+0x36) < *(short*)(c+0x34))
      *(short*)(c+0x36) = *(short*)(c+0x34);
  }
  {
    short* q = (short*)(c+0x32);
    *q = *q + *(short*)(c+0x36);
  }
  func_ov006_02110e28(c);
}
