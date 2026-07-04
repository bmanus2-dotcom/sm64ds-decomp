//cpp
// NONMATCHING: predicate vs branch (div=31). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern int _ZNK9Animation12WillHitFrameEi(void *o, int f);
extern void _ZN14BlendModelAnim7SetAnimER8BCA_Fileii5Fix12IiEt(void *o, void *bca, int a, int b, int fx, unsigned short t);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned a);
extern void func_ov006_020c1764(void *c);
extern int _ZN9Animation8FinishedEv(void *o);
}

extern "C" void func_ov006_020c0f9c(void *cc)
{
    char *c = (char*)cc;

    if (*(int*)(c + 0x7c) != *(int*)(c + 0x21c))
        goto other;

    if (_ZNK9Animation12WillHitFrameEi(c + 0x6c, 0)) {
        short t = *(short*)((char*)(c + 0x100) + 0xde);
        *(short*)(c + 0x1de) = *(short*)(c + 0x1de) - 1;
        if (t <= 0) {
            int a;
            *(int*)(c + 0x1d4) = 0;
            a = *(short*)(c + 0x1a);
            if (a == 0) {
                _ZN14BlendModelAnim7SetAnimER8BCA_Fileii5Fix12IiEt(c + 0x1c, *(void**)(c + 0x224), 0, 0x40000000, 0x800, 0);
                if (*(int*)(c + 0x26c) != 0)
                    return;
                _ZN5Sound12PlayBank2_2DEj(0x13a);
                *(int*)(c + 0x26c) = 1;
                return;
            } else if (a == 2) {
                _ZN14BlendModelAnim7SetAnimER8BCA_Fileii5Fix12IiEt(c + 0x1c, *(void**)(c + 0x22c), 0, 0x40000000, 0x800, 0);
                if (*(int*)(c + 0x26c) != 0)
                    return;
                _ZN5Sound12PlayBank2_2DEj(0x13a);
                *(int*)(c + 0x26c) = 1;
                return;
            } else {
                func_ov006_020c1764(c);
                return;
            }
        }
    }

    if (*(int*)(c + 0x1d4) == 0)
        return;
    if (!_ZNK9Animation12WillHitFrameEi(c + 0x6c, 5))
        return;
    _ZN5Sound12PlayBank2_2DEj(0x142);
    *(short*)*(char**)(c + 0x1d4) += 1;
    return;

other:
    if (*(int*)(c + 0x7c) == *(int*)(c + 0x224) || *(int*)(c + 0x7c) == *(int*)(c + 0x22c)) {
        if (_ZN9Animation8FinishedEv(c + 0x6c))
            func_ov006_020c1764(c);
    }
}
