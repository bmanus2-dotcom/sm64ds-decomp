//cpp
// NONMATCHING: register allocation (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct SEnt { short a, b; };
extern "C" {
extern void _ZN8Platform21UpdateModelPosAndRotYEv(void *);
extern int _ZN8Platform13IsClsnInRangeE5Fix12IiES1_(void *, int, int);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(void *);
}
extern SEnt data_02082214[];
extern "C" int func_ov022_02112238(char *c)
{
    short idx = data_02082214[(*(unsigned short *)(c + 0x324) >> 4)].a;
    *(int *)(c + 0x60) = idx * (short)0x1e + *(int *)(c + 0x320);
    *(short *)(c + 0x324) = *(short *)(c + 0x324) + 0x400;
    _ZN8Platform21UpdateModelPosAndRotYEv(c);
    if (_ZN8Platform13IsClsnInRangeE5Fix12IiES1_(c, 0, 0))
        _ZN8Platform19UpdateClsnPosAndRotEv(c);
    return 1;
}
