//cpp
// NONMATCHING: register allocation (div=30). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
void func_ov007_020bc02c(void* a, void* b);
void func_ov007_020be9ac(void* a, void* b, void* c);
void func_ov007_020bbff0(void* c);
}
extern char* data_ov007_0210342c;
extern "C" void func_ov007_020b2370(void){
  char* gp = *(char**)&data_ov007_0210342c;
  char* arr = gp + 0x100;
  void* f4 = *(void**)(gp + 0xf4);
  func_ov007_020bc02c(f4, *(char**)(gp + 0x30) + 0x44);
  {
    char* g2 = *(char**)&data_ov007_0210342c;
    func_ov007_020be9ac(*(void**)arr, *(void**)(g2 + 0xf4), *(char**)(g2 + 0x30) + 0x44);
  }
  {
    char* g2 = *(char**)&data_ov007_0210342c;
    func_ov007_020be9ac(*(void**)(arr + 4), *(void**)(g2 + 0xf4), *(char**)(g2 + 0x30) + 0x44);
  }
  {
    char* g2 = *(char**)&data_ov007_0210342c;
    int lr = *(int*)(g2 + 0xf8);
    long long v = ((long long)(0x1000 - lr) << 8) + ((long long)lr << 12);
    int res = (int)(v >> 12);
    *(int*)((char*)f4 + 0x48) = res;
    *(int*)((char*)f4 + 0x44) = *(int*)((char*)f4 + 0x48);
    *(int*)((char*)f4 + 0x40) = *(int*)((char*)f4 + 0x44);
  }
  func_ov007_020bbff0(f4);
  func_ov007_020bbff0(*(void**)((char*)*(void**)arr + 4));
  func_ov007_020bbff0(*(void**)((char*)*(void**)(arr + 4) + 4));
}
