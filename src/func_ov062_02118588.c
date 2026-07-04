// NONMATCHING: different op / idiom (div=43). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void *_ZN5Actor10FindWithIDEj(unsigned int id);
extern void _ZN9ActorBase18MarkForDestructionEv(void *a);
extern void func_ov062_02118004(void *c, int a1);
extern void func_ov062_02117994(char *c, int idx);
extern int _ZNK9Animation12WillHitFrameEi(void *anim, int f);
extern void func_ov062_021175c0(void *c);
extern int _ZN9Animation8FinishedEv(void *anim);

void func_ov062_02118588(char *c)
{
    void *found = 0;
    int match = 0;

    if (*(int*)(c + 0x38c) == 2 && *(unsigned int*)(c + 0x134) != 0) {
        found = _ZN5Actor10FindWithIDEj(*(unsigned int*)(c + 0x134));
        if (found != 0) {
            if (*(unsigned short*)((char*)found + 0xc) == 0x11d)
                match = 1;
        }
    }

    if (match) {
        int *hp = (int*)(c + 0x98);
        *(int*)(c + 0x390) = 0;
        *(int*)(c + 0x38c) = 4;
        *hp = *hp / 2;
        _ZN9ActorBase18MarkForDestructionEv(found);
        return;
    }

    if (*(int*)(c + 0x98) != 0) {
        func_ov062_02118004(c, 0x800);
        return;
    }

    {
        char *p = c + 0x300;
        unsigned short *q = (unsigned short*)(c + 0x3c6);
        if (*(unsigned short*)(p + 0xc6) != 0) {
            (*q)--;
            if (*(unsigned short*)(p + 0xc6) != 0)
                return;
            func_ov062_02117994(c, 8);
            return;
        }
    }

    if (_ZNK9Animation12WillHitFrameEi(c + 0x350, 0x1e))
        func_ov062_021175c0(c);

    if (_ZN9Animation8FinishedEv(c + 0x350) == 0)
        return;

    if (*(int*)(c + 0x394) != 0) {
        *(int*)(c + 0x38c) = 5;
        func_ov062_02117994(c, 0);
        return;
    }

    *(int*)(c + 0x38c) = 1;
    func_ov062_02117994(c, 3);
}
