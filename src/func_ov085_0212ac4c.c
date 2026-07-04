// NONMATCHING: different op / idiom (div=39). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern char *_ZN5Actor13ClosestPlayerEv(void *self);
extern char *_ZN5Actor10FindWithIDEj(unsigned int id);
extern int _ZN6Player9StartTalkER9ActorBaseb(void *self, void *other, int b);
extern int func_ov085_0212bc78(void *c, void *p);
extern int data_ov085_021306dc;

int func_ov085_0212ac4c(char *c)
{
    char *obj;
    char *cp;
    char *o;
    int a;
    int b;

    obj = *(char **)(c + 0x45c);
    if (obj != 0) {
        a = (*(int *)(c + 0xb0) & 0x400) != 0;
        if (a || (*(int *)(c + 0xb0) & 0x2000) != 0) {
            if (a) {
                if (obj != 0)
                    *(short *)(c + 0x94) = *(short *)(obj + 0x8e);
            }
            *(int *)(c + 0x128) &= ~2;
            *(char **)(c + 0x45c) = 0;
        }
    }

    b = (*(int *)(c + 0xb0) & 0x100) != 0;
    if (!b)
        *(char **)(c + 0x45c) = 0;
    if (*(char **)(c + 0x45c) != 0) {
        if (*(unsigned char *)(*(char **)(c + 0x45c) + 0x706) != 0)
            *(char **)(c + 0x45c) = 0;
    }

    cp = _ZN5Actor13ClosestPlayerEv(c);
    if (cp != 0) {
        if (*(unsigned short *)(cp + 0x6ce) & 0x800)
            return 1;
    }

    if (*(int *)(c + 0x130) & 0x8000000) {
        o = _ZN5Actor10FindWithIDEj(*(unsigned int *)(c + 0x134));
        if (o != 0) {
            if (*(unsigned short *)(o + 0xc) == 0xbf) {
                *(char **)(c + 0x460) = o;
                if (_ZN6Player9StartTalkER9ActorBaseb(*(char **)(c + 0x460), c, 0)) {
                    func_ov085_0212bc78(c, &data_ov085_021306dc);
                }
            }
        }
    }

    return 1;
}
