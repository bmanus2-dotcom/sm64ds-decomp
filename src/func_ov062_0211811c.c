// NONMATCHING: push-set / frame (div=19). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZNK9Animation13GetFrameCountEv(void *self);
extern int _ZNK9Animation12WillHitFrameEi(void *self, int frame);
extern void func_ov062_02117994(char *c, int idx);
void func_ov062_0211811c(char *c) {
    {
        char *b = c + 0x300;
        if (*(unsigned short*)(b + 0xc6) == 0) {
            *(unsigned short*)(b + 0xc6) = (unsigned short)(*(unsigned short*)(b + 0xc6) - 1);
            return;
        }
    }
    if (_ZNK9Animation12WillHitFrameEi(c + 0x350, (unsigned short)(_ZNK9Animation13GetFrameCountEv(c + 0x350) - 1)) == 0)
        return;
    *(unsigned short*)(c + 0x3c4) = (unsigned short)(*(unsigned short*)(c + 0x3c4) + 1);
    func_ov062_02117994(c, 2);
}
