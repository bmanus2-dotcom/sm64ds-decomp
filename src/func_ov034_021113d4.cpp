//cpp
// NONMATCHING: different op / idiom (div=41). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct S { int _pad; void *f; };
extern struct S *data_ov034_02113888[];
extern struct S *data_ov034_02113874[];

extern "C" void _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(void *thiz, void *file, int a, int b, unsigned int c);
extern "C" int _ZN9Animation8FinishedEv(void *thiz);
extern "C" void func_ov034_021125b8(void *c, int i);

extern "C" void func_ov034_021113d4(char *thiz){
  int i;
  int flag;
  int k;
  char *anim = (thiz + 0x110) + 0xc8;
  for(i=2,k=6;i<5;i++,k+=3){
    if((unsigned char)thiz[0x8da] == (k - 3)){
      _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(anim, data_ov034_02113888[i]->f, 0x40000000, 0x1000, 0);
    }
    anim += 0x64;
  }
  {
    char *fin = thiz + 0x160;
    char *anm = thiz + 0x110;
    for(i=0;i<5;i++){
      if(_ZN9Animation8FinishedEv(fin)){
        _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(anm, data_ov034_02113874[i]->f, 0, 0x1000, 0);
      }
      fin += 0x64;
      anm += 0x64;
    }
  }
  {
    char *p = thiz;
    flag = 1;
    for(i=0;i<5;i++){
      if(*(int*)(p+0x170) != (int)data_ov034_02113874[i]->f) flag = 0;
      p += 0x64;
    }
  }
  if(flag == 1){
    func_ov034_021125b8(thiz, 4);
  }
  (*(unsigned char*)(thiz+0x8da))++;
  if((unsigned char)thiz[0x8da] > 0xc) thiz[0x8da] = 0xd;
}
