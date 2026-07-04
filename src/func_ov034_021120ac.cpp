//cpp
// NONMATCHING: different op / idiom (div=45). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void _Z14ApproachLinearRiii(int *p, int t, int s);
extern void _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(void *o, void *f, int a, int fx, unsigned j);
extern int _ZN9Animation8FinishedEv(void *o);
extern int _ZN6Player12GetTalkStateEv(void);
extern void _ZN5Sound22LoadAndSetMusic_Layer3Ej(unsigned a);
extern void _ZN7Message7EndTalkEv(void);
extern void func_ov034_021125b8(void *c, int i);
extern char *data_ov034_0211389c[];
extern char *data_ov034_02113860[];
}

extern "C" void func_ov034_021120ac(void *cc)
{
    char *c = (char*)cc;
    int i, j, k;
    int match;

    _Z14ApproachLinearRiii((int*)(c + 0x98), 0, 0x1000);

    if (*(unsigned char*)(c + 0x8da) == 0) {
        _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c + 0x110, *(void**)(data_ov034_0211389c[0] + 4), 0x40000000, 0x1000, 0);
        _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c + 0x174, *(void**)(data_ov034_0211389c[1] + 4), 0x40000000, 0x1000, 0);
    }

    {
        char *r7 = c + 0x110 + 0xc8;
        int r8 = 6;
        for (i = 2; i < 5; i++) {
            if (*(unsigned char*)(c + 0x8da) == r8 - 3) {
                _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(r7, *(void**)(data_ov034_0211389c[i] + 4), 0x40000000, 0x1000, 0);
            }
            r8 += 3;
            r7 += 0x64;
        }
    }

    if (_ZN9Animation8FinishedEv(c + 0x2f0)) {
        char *r7 = c + 0x110;
        for (j = 0; j < 5; j++) {
            _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(r7, *(void**)(data_ov034_02113860[j] + 4), 0, 0x1000, 0);
            r7 += 0x64;
        }
    }

    {
        char *r5 = c;
        match = 1;
        for (k = 0; k < 5; k++) {
            if (*(int*)(r5 + 0x170) != *(int*)(data_ov034_02113860[k] + 4))
                match = 0;
            r5 += 0x64;
        }
    }

    if (match == 1 && _ZN6Player12GetTalkStateEv() == 2) {
        _ZN5Sound22LoadAndSetMusic_Layer3Ej(0x2d);
        _ZN7Message7EndTalkEv();
        func_ov034_021125b8(c, 3);
    }

    *(unsigned char*)(c + 0x8da) += 1;
    if (*(unsigned char*)(c + 0x8da) > 0xc)
        *(unsigned char*)(c + 0x8da) = 0xd;
}
