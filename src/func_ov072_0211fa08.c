//cpp
// NONMATCHING: push-set / frame (div=29). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
int _ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj(int, void*, int, void*, int, int);
int _ZN6Player12GetTalkStateEv(void*);
unsigned short DecIfAbove0_Short(unsigned short* p);
int func_ov072_0211fcb0(void*, int);
void func_ov072_0211fa08(char* c){
  int v[3];
  v[0] = *(int*)(c+0x5c);
  int y = *(int*)(c+0x60);
  v[1] = y;
  v[2] = *(int*)(c+0x64);
  v[1] = y + 0x96000;
  switch(*(unsigned char*)(c+0x3a2)){
  case 0:
    if(_ZN6Player11ShowMessageER9ActorBasejPK7Vector3jj(*(int*)(c+0x390), c, 0xb0, v, 0, 0) == 0) break;
    (*(unsigned char*)(c+0x3a2))++;
    break;
  case 1:
    if(_ZN6Player12GetTalkStateEv((void*)*(int*)(c+0x390)) != -1) break;
    (*(unsigned char*)(c+0x3a2))++;
    break;
  case 2:
    if(DecIfAbove0_Short((unsigned short*)(c+0x3a0)) == 0){
      func_ov072_0211fcb0(c, 2);
    }
    break;
  }
}
}
