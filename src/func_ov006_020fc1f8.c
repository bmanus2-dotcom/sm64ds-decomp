// NONMATCHING: different op / idiom (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 data_ov006_0212eb3c[];
extern u8 data_ov006_0212eb34[];

int func_ov006_020fc1f8(char* self, int idx)
{
  u16* counter = (u16*)(self + 0x4eb0 + idx*0x1c);
  u8* p6 = (u8*)(self + 0x4eb6 + idx*0x1c);
  u16 c = *counter;
  *counter = c + 1;
  u8 f6 = *p6;
  if (*counter >= data_ov006_0212eb3c[f6]) {
    *counter = 0;
    *p6 = *p6 + 1;
    if (*p6 >= 8) {
      *p6 = 0;
      *(u8*)(self + 0x4eba + idx*0x1c) = *(u8*)(self + 0x4eba + idx*0x1c) + 1;
    }
    *(u8*)(self + idx*0x1c + 0x4000 + 0xeb5) = data_ov006_0212eb34[*p6];
  }
  {
    u8* base = (u8*)(self + idx*0x1c + 0x4000);
    if (base[0xeb4] != 0) {
      base[0xeba] = 0;
      return 0;
    }
    if (*(u8*)(self + 0x4eba + idx*0x1c) >= 2) {
      base[0xeb3] = 0;
    }
  }
  return 0;
}
