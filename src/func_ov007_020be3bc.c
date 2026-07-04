//cpp
// NONMATCHING: different op / idiom (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" int func_ov007_020b7690(int i);
extern int* data_ov007_0210342c;
extern int* data_ov007_02104bc0;
extern "C" void func_ov007_020be3bc(void){
  char* r4 = (char*)((int*)(data_ov007_0210342c[0x74/4]))[0x14/4];
  if (func_ov007_020b7690(0) == 0) return;
  if (func_ov007_020b7690(1) == 0) return;
  int count = 0;
  int soff = 0;
  int doff = 0;
  do {
    short* d = (short*)(r4 + (doff << 3));
    char* s = (char*)data_ov007_02104bc0[0] + 8 + soff;
    d[3] = (short)(*(int*)(s) >> 4);
    count++;
    d[7] = (short)(*(int*)(s+4) >> 4);
    d[0xb] = (short)(*(int*)(s+8) >> 4);
    soff += 0x10;
    d[0xf] = (short)(*(int*)(s+0xc) >> 4);
    doff += 4;
  } while (count < 0x10);
}
