extern int data_0209b4ac;
extern int data_0208e43c;
extern int data_0208e440;
extern int data_0209b4a0[];
extern void func_02011dcc(int* g, int x);
void _ZN5Sound22LoadAndSetMusic_Layer2Ej(int j){
  int a=data_0209b4ac;
  int b=data_0208e43c;
  data_0208e440=j;
  if(a!=b) return;
  func_02011dcc(data_0209b4a0, j);
}
