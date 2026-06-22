int func_0203da9c(void);
int func_0203db4c(int handle, int i);
void func_0203db3c(int i, unsigned char v);

void func_02020078(unsigned int flags)
{
    if (func_0203da9c() != 0) return;
    int v = func_0203db4c(0, 3);
    func_0203db3c(3, (unsigned char)(flags | (v & ~3)));
}
