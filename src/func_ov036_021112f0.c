extern int func_ov036_0211123c(char *t);
extern int _ZN8Platform13IsClsnInRangeE5Fix12IiES1_(char *c, int a, int b);
extern int _ZN8Platform19UpdateClsnPosAndRotEv(char *c);

int func_ov036_021112f0(char *c)
{
    if (*(short *)(c + 0x90) < 0) {
        short *p = (short *)(((int)c + 0x31e) & 0xFFFFFFFFFFFFFFFF);
        *p = *p + 4;
    } else {
        short *p = (short *)(((int)c + 0x31e) & 0xFFFFFFFFFFFFFFFF);
        *p = *p - 4;
    }
    {
        short *q = (short *)(((int)c + 0x90) & 0xFFFFFFFFFFFFFFFF);
        *q = *q + ((short *)(c + 0x300))[15];
    }
    func_ov036_0211123c(c);
    if (_ZN8Platform13IsClsnInRangeE5Fix12IiES1_(c, 0, 0))
        _ZN8Platform19UpdateClsnPosAndRotEv(c);
    return 1;
}
