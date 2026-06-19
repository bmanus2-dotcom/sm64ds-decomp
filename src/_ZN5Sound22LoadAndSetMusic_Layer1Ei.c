extern int data_0208e438;
extern int data_0208e434;
extern int data_0209b48c;
extern int data_0208e430;
extern int data_0209b4ac;
extern int data_0208e43c;
extern int data_0209b4a0[];
extern int data_0209b4b0[];
extern void func_0204fa2c(int* g, int z);
extern void func_02011dcc(int* g, int x);
extern void func_02013524(int* g, int a, int b);
extern void func_02011b7c(void);
void _ZN5Sound22LoadAndSetMusic_Layer1Ei(int j){
  data_0208e438=-1;
  data_0208e434=-1;
  data_0209b48c=0;
  if(j<0){
    func_0204fa2c(data_0209b4a0, 0);
  } else {
    if(!(data_0208e430>=0 && data_0209b4ac>=0 && data_0208e43c==j))
      func_02011dcc(data_0209b4a0, j);
    func_02013524(data_0209b4a0, 0x7f, 0);
    func_0204fa2c(data_0209b4b0, 0);
  }
  data_0209b4ac=j;
  data_0208e43c=j;
  func_02011b7c();
}
