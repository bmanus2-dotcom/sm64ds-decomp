// NONMATCHING: register allocation (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_0201267c(int a, void *b);
extern void _Z14ApproachLinearRiii(int *p, int target, int step);
extern void _ZN5Actor9UpdatePosEP12CylinderClsn(void *thiz, void *clsn);

void func_ov020_02111aa8(char *c)
{
    *(unsigned char *)(c + 0x108) = 0;
    *(unsigned short *)(c + 0x100) += 1;
    if (*(unsigned short *)(c + 0x100) >= 3) {
        *(int *)(c + 0x424) = 3;
        *(int *)(c + 0x98) = 0x32000;
        {
            int *bf = (int *)(c + 0x234);
            *bf &= ~1;
        }
        func_0201267c(0x166, c + 0x74);
    }
    _Z14ApproachLinearRiii((int *)(c + 0x98), 0x32000, 0x1000);
    _ZN5Actor9UpdatePosEP12CylinderClsn(c, 0);
}
