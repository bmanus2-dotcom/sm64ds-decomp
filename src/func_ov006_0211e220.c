// NONMATCHING: register allocation (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct E29 { unsigned char b[0x10]; };
void func_ov006_0211e220(unsigned char* c,int param){
  struct E29* a=(struct E29*)c;
  int i;
  for(i=0;i<16;i++){
    unsigned char* s=(unsigned char*)&a[i];
    if(*(unsigned char*)(s+0x496d)==0){
      unsigned char* src=c+param*0x24+0x4000;
      *(int*)(s+0x4960)=*(int*)(src+0x660);
      *(int*)(s+0x4964)=*(int*)(src+0x664);
      *(short*)(s+0x4968)=0;
      *(unsigned char*)(s+0x496c)=0;
      *(unsigned char*)(s+0x496d)=1;
      *(unsigned char*)(s+0x496e)=1;
      return;
    }
  }
}
