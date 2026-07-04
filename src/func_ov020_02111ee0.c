//cpp
// NONMATCHING: different op / idiom (div=29). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
int func_ov020_02111418(char *c);
int _Z14ApproachLinearRsss(void*, int, int);
int _ZN9ModelBase7SetFileEP8BMD_Fileii(void*,int,int,int);
int _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(void*,int,int,int,unsigned);
int _ZN5Actor9UpdatePosEP12CylinderClsn(void*,int);
extern int data_ov020_02114aa0[];
extern int data_ov020_02114aa8[];
int func_ov020_02111ee0(char* c){
  int r = func_ov020_02111418(c);
  if(r) return r;
  if(_Z14ApproachLinearRsss(c+0x8c, -0x2000, 0x200) == 0) return 0;
  *(int*)(c+0x98) = 0;
  if(_ZN9ModelBase7SetFileEP8BMD_Fileii(c+0x110, data_ov020_02114aa0[1], 1, -1) == 0) return 0;
  *(int*)(c+0x424) = 2;
  _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c+0x110, data_ov020_02114aa8[1], 0x40000000, 0x1000, 0);
  *(unsigned char*)(c+0x450) = 1;
  *(short*)(c+0x100) = 0;
  int* p60 = (int*)(c+0x60);
  *p60 = *p60 + 0x32000;
  *(int*)(c+0x43c) = -0x19000;
  return _ZN5Actor9UpdatePosEP12CylinderClsn(c, 0);
}
}
