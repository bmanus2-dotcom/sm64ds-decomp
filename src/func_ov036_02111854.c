// NONMATCHING: different op / idiom (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
extern void* _ZN5Model8LoadFileER13SharedFilePtr(void*);
extern int _ZN9ModelBase7SetFileEP8BMD_Fileii(void*, void*, int, int);
extern char data_ov036_02114070[];

int func_ov036_02111854(char* c) {
  void* mdl = _ZN5Model8LoadFileER13SharedFilePtr(data_ov036_02114070);
  _ZN9ModelBase7SetFileEP8BMD_Fileii(c+0xd4, mdl, 1, -1);
  *(unsigned char*)(c+0x118) = *(unsigned int*)(c+8) & 1;
  *(unsigned char*)(c+0x119) = (*(unsigned int*)(c+8) >> 8) & 1;
  if (*(unsigned char*)(c+0x118) != 0) {
    s16* a = (s16*)(c+0x8c);
    s16* b = (s16*)(c+0x8e);
    s16* d = (s16*)(c+0x90);
    s16* e = (s16*)(c+0x100);
    *a += 0x2400;
    *b += 0x8000;
    *d += 0x8000;
    e[8] = *a;
    e[9] = *b;
    e[10] = *d;
    e[11] = 0;
  }
  return 1;
}
