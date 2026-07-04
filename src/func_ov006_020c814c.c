//cpp
// NONMATCHING: different op / idiom (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern int data_ov006_0214041c;
extern int data_ov006_02140434;
int _ZNK9Animation12WillHitFrameEi(void *thiz, int frame);
void func_ov006_020e6e3c(int a, int b);
void func_ov006_020c8658(void *c);
void func_ov006_020c814c(char *c)
{
    int hit;
    if (*(int *)(c + 0xac) != data_ov006_0214041c)
        return;
    hit = _ZNK9Animation12WillHitFrameEi(c + 0x9c, 0xc);
    if (!hit)
        hit = _ZNK9Animation12WillHitFrameEi(c + 0x9c, 0x18);
    if (!hit)
        return;
    func_ov006_020e6e3c(0x1b5, *(int *)(c + 0x14));
    if (*(int *)(c + 0x18) <= 0x180000)
        return;
    *(int *)(c + 0x24) = 0;
    data_ov006_02140434++;
    func_ov006_020c8658(c);
}
}
