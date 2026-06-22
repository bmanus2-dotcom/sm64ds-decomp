extern void _ZN13SharedFilePtr7ReleaseEv(void*);
extern int func_ov002_020ec628(void*);
extern void UnloadBlueCoinModel(void*);
extern char data_ov002_0210e6b0;
extern char data_ov002_0210eb78;
int func_ov002_020edf54(void* a){
  _ZN13SharedFilePtr7ReleaseEv(&data_ov002_0210e6b0);
  _ZN13SharedFilePtr7ReleaseEv(&data_ov002_0210eb78);
  if (func_ov002_020ec628(a) != 0)
    UnloadBlueCoinModel(a);
  return 1;
}
