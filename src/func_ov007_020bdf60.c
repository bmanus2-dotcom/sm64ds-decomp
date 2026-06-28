extern void func_0204fa2c(char* p, int v);
extern void func_0204f934(char* p);
extern void _ZN6Player17St_EndingFly_MainEv(char* p);
extern char* data_ov007_02104bbc;
extern char* data_ov007_02104bb8;

void func_ov007_020bdf60(void){
  int i = 0;
  int off = 0;
  for (; i < 0x39; i++, off += 4) {
    if (((int*)data_ov007_02104bbc)[i] != 0) {
      func_0204fa2c(data_ov007_02104bbc + off, 5);
    }
    func_0204f934(data_ov007_02104bbc + off);
  }
  if (data_ov007_02104bb8 != 0) {
    _ZN6Player17St_EndingFly_MainEv(data_ov007_02104bb8);
    data_ov007_02104bb8 = 0;
  }
  if (data_ov007_02104bbc != 0) {
    _ZN6Player17St_EndingFly_MainEv(data_ov007_02104bbc);
    data_ov007_02104bbc = 0;
  }
}
