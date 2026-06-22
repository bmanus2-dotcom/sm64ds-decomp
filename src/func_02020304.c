int func_0203da9c(void);
int func_0203db4c(int handle, int i);
void func_0203db3c(int i, unsigned char v);

void func_02020304(void)
{
    int v = func_0203db4c(func_0203da9c(), 0);
    func_0203db3c(0, (unsigned char)(v & ~8));
}
