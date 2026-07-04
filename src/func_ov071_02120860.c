//cpp
// NONMATCHING: constant / value (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj(void*, void*, int, int, unsigned int);
extern void _ZN9Animation8SetFlagsEi(void*, int);
extern int _ZN9Animation8FinishedEv(void*);
extern void _ZN9Animation7AdvanceEv(void*);
struct SFP { void* a; void* b; };
extern struct SFP data_ov071_02123038;
extern struct SFP data_ov071_02123040;
int func_ov071_02120860(char* c){
  unsigned char* p;
  switch (*(unsigned char*)(c + 0x214)) {
  case 0:
    return 0;
  case 1:
  case 4:
    _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj(c + 0x138, data_ov071_02123038.b, 0, 0x1000, 0);
    _ZN9Animation8SetFlagsEi(c + 0x138, 0x40000000);
    *(int*)(c + 0x144) = 0x1000;
    *(int*)(c + 0x140) = 0;
    p = (unsigned char*)(c + 0x214);
    *p = *p + 1;
  case 2:
  case 5:
    if (_ZN9Animation8FinishedEv(c + 0x138)) {
      _ZN15TextureSequence7SetFileER8BTP_Filei5Fix12IiEj(c + 0x138, data_ov071_02123040.b, 0, 0x1000, 0);
      _ZN9Animation8SetFlagsEi(c + 0x138, 0x40000000);
      *(int*)(c + 0x144) = 0x1000;
      *(int*)(c + 0x140) = 0;
      p = (unsigned char*)(c + 0x214);
      (*p)++;
    }
    _ZN9Animation7AdvanceEv(c + 0x138);
    return 0;
  case 3:
  case 6:
    if (_ZN9Animation8FinishedEv(c + 0x138)) {
      p = (unsigned char*)(c + 0x214);
      (*p)++;
    }
    _ZN9Animation7AdvanceEv(c + 0x138);
    return 0;
  case 7:
    *(unsigned char*)(c + 0x214) = 0;
    return 1;
  }
  return 0;
}
}
