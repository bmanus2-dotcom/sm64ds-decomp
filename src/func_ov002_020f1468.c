// NONMATCHING: different op / idiom (div=35). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12i;
typedef short s16;
struct SharedFilePtr;
extern void* _ZN5Model8LoadFileER13SharedFilePtr(void* fp);
extern void _ZN9ModelBase7SetFileEP8BMD_Fileii(void* m, void* f, int a, int b);
extern void _ZN8Platform21UpdateModelPosAndRotYEv(void* c);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(void* c);
extern void* _ZN12MeshCollider8LoadFileER13SharedFilePtr(void* fp);
extern void _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(void* mc, void* f, void* mtx, Fix12i fx, short s, void* clps);
extern void func_020393c4(void* p, void* v);
extern char data_ov002_02110acc;
extern char data_ov002_02110ac4;
extern char data_ov002_0210d6f4;
extern void func_ov002_020f15b8(void);
int func_ov002_020f1468(char* c){
  void* bmd = _ZN5Model8LoadFileER13SharedFilePtr(&data_ov002_02110acc);
  _ZN9ModelBase7SetFileEP8BMD_Fileii(c + 0xd4, bmd, 1, -1);
  *(unsigned char*)(c + 0x32d) = *(int*)(c + 8) & 0xf;
  _ZN8Platform21UpdateModelPosAndRotYEv(c);
  _ZN8Platform19UpdateClsnPosAndRotEv(c);
  {
    void* kcl = _ZN12MeshCollider8LoadFileER13SharedFilePtr(&data_ov002_02110ac4);
    _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(
      c + 0x124, kcl, c + 0x2ec, 0x199, *(s16*)(c + 0x8e), &data_ov002_0210d6f4);
  }
  func_020393c4(c + 0x124, (void*)&func_ov002_020f15b8);
  *(unsigned char*)(c + 0x32c) = 0;
  *(int*)(c + 0x320) = *(int*)(c + 0x60) - 0x64000;
  *(unsigned short*)(c + 0x32a) = (*(int*)(c + 8) >> 8) & 0xff;
  *(unsigned char*)(c + 0x32e) = *(signed char*)(c + 0xcc);
  if (*(unsigned short*)(c + 0x32a) == 0xff)
    *(unsigned short*)(c + 0x32a) = *(unsigned short*)(c + 0x32a) * 0xa;
  else if (*(unsigned short*)(c + 0x32a) == 0)
    *(unsigned short*)(c + 0x32a) = 0xfa;
  return 1;
}
