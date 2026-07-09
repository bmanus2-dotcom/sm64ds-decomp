extern int func_ov002_020ec654(unsigned char *p);
extern void func_ov002_020edca4(char *c);
extern void *func_02010ecc(const void *prev);
extern int func_0203cfdc(const void *a, const void *b);

void *func_ov002_020edb3c(char *c, int a, int maxDist)
{
    char *cur;
    char *best;
    int bestDist;
    int i;
    int match;
    int flags;
    unsigned char count;

    (void)a;
    count = *(unsigned char *)(c + 0x41c);
    if (count >= 5) {
        if (func_ov002_020ec654((unsigned char *)c) == 0) {
            func_ov002_020edca4(c);
        }
        return 0;
    }

    best = 0;
    bestDist = maxDist;
    cur = (char *)func_02010ecc(0);
    while (cur != 0) {
        if (cur != c && cur != *(char **)(c + 0x38c)) {
            flags = *(int *)(cur + 0xb0);
            if ((flags & 0x10000000) != 0 && (flags & 8) == 0) {
                match = 0;
                for (i = 0; i < 5; i++) {
                    if (*(int *)(c + 0x3fc + i * 4) == *(int *)(cur + 4)) {
                        match = 1;
                    }
                }
                if (match == 0) {
                    if (func_ov002_020ec654((unsigned char *)c) != 0) {
                        if ((*(int (**)(void *))(*(int *)cur + 0x50))(cur) == 0) {
                            goto next_actor;
                        }
                    }
                    i = func_0203cfdc(c + 0x5c, cur + 0x5c);
                    if (i < bestDist) {
                        bestDist = i;
                        best = cur;
                    }
                }
            }
        }
    next_actor:
        cur = (char *)func_02010ecc(cur);
    }

    if (best == 0) {
        return 0;
    }

    count = *(unsigned char *)(c + 0x41c);
    *(int *)(c + 0x3fc + count * 4) = *(int *)(best + 4);
    *(int *)(c + 0x410) = *(int *)(best + 4);
    {
        char *p = c + 0x41c;
        count = *(unsigned char *)p;
        *(unsigned char *)p = count + 1;
    }
    return best;
}