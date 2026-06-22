//cpp
extern "C" {
extern unsigned char data_0209caa0[];
extern unsigned char data_0209f2d8[];
int _ZN8SaveData16CanPlayerHaveCapEv(void){
  if (data_0209caa0[0x41] != 3) {
    int b = (int)(data_0209f2d8[0] == 1);
    if (b == 0) return 1;
  }
  return 0;
}
}
