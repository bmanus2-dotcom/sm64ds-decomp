//cpp
extern "C" {
int _ZN13SharedFilePtr7ReleaseEv(void*);
extern int data_ov102_0214d70c[];
int func_ov102_0214d248(char* c){
  unsigned char i=*(unsigned char*)(c+0x3c4);
  _ZN13SharedFilePtr7ReleaseEv((void*)data_ov102_0214d70c[i]);
  return 1;
}
}
