extern unsigned char data_0209f2a0[];
extern int data_0209d4c8[];
extern unsigned char data_0209d45c[];
extern unsigned char data_0209d454[];
extern unsigned char data_0209f280[];
extern unsigned short data_0209f300[];
extern unsigned char data_0209f2c4[];
extern int _ZN5Timer10StartTimerEv(void*);
extern int _ZN5Sound12UnpauseMusicEv(void);
extern int _ZN5Sound22StopLoadedMusic_Layer1Ej(unsigned int);
void _ZN5Stage10PS_CleanupEv(void){
  if(*data_0209f2a0){
    _ZN5Timer10StartTimerEv(data_0209d4c8);
    *data_0209f2a0=0;
  }
  *data_0209d45c &= ~0xe;
  *data_0209d454 &= ~3;
  if(*data_0209f280==0) _ZN5Sound12UnpauseMusicEv();
  else _ZN5Sound22StopLoadedMusic_Layer1Ej(0x3c);
  *data_0209f300=0xf;
  *(short*)0x4000050=0;
  *(short*)0x4001050=0;
  *data_0209f280=0;
  *data_0209f2c4=0;
}
