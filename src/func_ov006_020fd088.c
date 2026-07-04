// NONMATCHING: register allocation (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;
extern void func_ov006_020fdaf0(char*, int);
extern void func_ov006_020fca1c(char*, int);
extern void func_ov006_020fc9b0(char*, int);

void func_ov006_020fd088(char* self, int idx)
{
  *(int*)(self + 0x4660 + idx*0x38) = *(int*)(self + 0x4660 + idx*0x38) + *(int*)(self + idx*0x38 + 0x4668);
  *(int*)(self + 0x4664 + idx*0x38) = *(int*)(self + 0x4664 + idx*0x38) + *(int*)(self + idx*0x38 + 0x466c);
  {
    int raw = *(u16*)(self + idx*0x38 + 0x4686);
    u16 ip = (u16)(raw - 0x4000);
    short tgt = (short)ip;
    short* cur = (short*)(self + 0x4684 + idx*0x38);
    if (*cur > tgt) {
      *cur = *cur - 0x100;
      if (*cur <= tgt) *cur = ip;
    } else if (*cur < tgt) {
      *cur = *cur + 0x100;
      if (*cur >= tgt) *cur = ip;
    }
  }
  func_ov006_020fdaf0(self, idx);
  func_ov006_020fca1c(self, idx);
  func_ov006_020fc9b0(self, idx);
}
