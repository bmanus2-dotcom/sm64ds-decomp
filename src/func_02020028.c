extern int func_0203db4c(int i, int n);
extern void func_0203db3c(int i, int v);

void func_02020028(int a, int b)
{
    int x = func_0203db4c(a, 4);
    x = b | (x & ~3);
    func_0203db3c(4, x & 0xff);
}
