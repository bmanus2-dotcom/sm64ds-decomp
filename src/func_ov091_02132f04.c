//cpp
// NONMATCHING: base materialization / addressing (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
struct V3 { int x, y, z; };
int _ZN5Actor15HugeLandingDustEb(void*, int);
int _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(int, struct V3);
int _ZN5Actor10EarthquakeERK7Vector35Fix12IiE(void*, struct V3*, int);
int func_0201267c(int, void*);
void func_ov091_02132f04(char* c){
  int* pa8 = (int*)(c+0xa8);
  int* p60 = (int*)(c+0x60);
  *pa8 = *pa8 - 0x4000;
  *p60 = *p60 + *(int*)(c+0xa8);
  if(*(int*)(c+0x60) > *(int*)(c+0x394)) return;
  *(int*)(c+0x60) = *(int*)(c+0x394);
  *(int*)(c+0xa8) = 0;
  *(int*)(c+0x398) = 3;
  *(unsigned char*)(c+0x39e) = 0xa;
  int flag = 0;
  if(*(unsigned short*)(c+0xc) == 0xa1) flag = 1;
  if(flag != 0){
    _ZN5Actor15HugeLandingDustEb(c, 1);
  } else {
    struct V3 v;
    v.x = *(int*)(c+0x5c);
    v.y = *(int*)(c+0x60);
    v.z = *(int*)(c+0x64);
    v.y = *(int*)(c+0x60) + 0x3c000;
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x2e, v);
  }
  struct V3 w;
  w.x = *(int*)(c+0x5c);
  w.y = *(int*)(c+0x60);
  w.z = *(int*)(c+0x64);
  _ZN5Actor10EarthquakeERK7Vector35Fix12IiE(c, &w, 0x7d0000);
  func_0201267c(0xc7, c+0x74);
}
}
