// NONMATCHING: different op / idiom (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020e4b00(void*);
extern void func_ov006_020e5ffc(void*);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int);
struct S628 { char pad[0xb6]; unsigned short f; };
#define SB(c) (((struct S628*)((char*)(c) + 0x5500))->f)
void func_ov006_020e628c(char *c){
  int i;
  func_ov006_020e4b00(c);
  if (SB(c) != 0){
    *(unsigned short*)(c + 0x55b6) = *(unsigned short*)(c + 0x55b6) - 1;
    if ((short)SB(c) <= 0) SB(c) = 0;
    return;
  }
  *(int*)(c + 0x5580) = 1;
  if (*(unsigned char*)(c + 0x55ba) >= 5){
    *(int*)(c + 0x5580) = 3;
    SB(c) = 0x40;
    *(unsigned char*)(c + 0x55bc) = 1;
    _ZN5Sound12PlayBank2_2DEj(0x1d8);
  }
  for (i = 0; i < 5; i++){
    *(int*)(c + i*16 + 0x4870) = 0;
    *(int*)(c + i*16 + 0x4874) = 0;
    *(short*)(c + i*16 + 0x4878) = 0;
    *(short*)(c + i*16 + 0x487a) = 0;
    *(unsigned char*)(c + i*16 + 0x487d) = 0;
    *(unsigned char*)(c + i*16 + 0x487c) = 0;
  }
  func_ov006_020e5ffc(c);
}
