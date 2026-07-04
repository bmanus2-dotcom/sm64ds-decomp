//cpp
// NONMATCHING: missing logic (ROM does more) (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Base {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
  virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
  virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18();
  virtual int m_4c(void* arg);   /* slot 19 -> 0x4c */
};
extern "C" void func_ov004_020ae20c(void);
extern "C" void func_ov004_020b0aa0(int arg);
extern "C" void func_ov004_020ae2c8(void);
extern "C" void func_ov004_020b29a0(Base* c, void* arg);
extern Base* data_ov004_020beb68;
extern void* data_ov004_020bc7d4;
extern void* data_ov004_020bfa24;
struct Pair { int a; int b; };
extern struct Pair data_ov004_020bc904;

extern "C" void func_ov004_020b7cd0(char* c){
  int state = *(int*)(c + 0x1c);
  if (state > 0x64)
    return;
  Base* p = data_ov004_020beb68;
  int a8 = (p != 0) ? *(int*)((char*)p + 0xa8) : 0;
  if (a8 == 0) {
    if (state != 0)
      return;
    Base* q = data_ov004_020beb68;
    if (q == 0)
      return;
    if (q->m_4c(*(void**)(c + 0x18)) == 0)
      return;
    data_ov004_020bc7d4 = 0;
    data_ov004_020bfa24 = 0;
    func_ov004_020ae20c();
    func_ov004_020b0aa0(0x1d);
    *(int*)(c + 0x1c) = 0xb4;
    *(struct Pair*)(c + 8) = data_ov004_020bc904;
  } else {
    if (state != 0)
      return;
    Base* r5 = data_ov004_020beb68;
    if (r5 == 0)
      return;
    if (r5->m_4c(*(void**)(c + 0x18)) == 0)
      return;
    func_ov004_020b0aa0(0x1d);
    func_ov004_020ae20c();
    func_ov004_020ae2c8();
    func_ov004_020b29a0(r5, *(void**)(c + 0x18));
    *(int*)(c + 0x1c) = 0;
    *(int*)(c + 0x18) = -1;
    *(int*)(c + 0x20) = 0;
    *(int*)(c + 0x24) = 0;
  }
}
