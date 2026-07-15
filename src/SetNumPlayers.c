extern unsigned char data_0208a0e0;
extern void func_020308d0(void);

void SetNumPlayers(int a)
{
    data_0208a0e0 = (unsigned char)a;
    func_020308d0();
}
