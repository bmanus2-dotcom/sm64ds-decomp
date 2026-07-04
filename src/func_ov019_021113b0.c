// NONMATCHING: base materialization / addressing (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
extern void _ZNK7PathPtr7GetNodeER7Vector3j(void *self, struct Vector3 *out, unsigned int idx);
extern int Vec3_Dist(const struct Vector3 *a, const struct Vector3 *b);
extern short Vec3_HorzAngle(const struct Vector3 *v0, const struct Vector3 *v1);
void func_ov019_021113b0(char *c)
{
    struct Vector3 v;
    int *cnt = (int *)(c + 0x36c);
    *cnt = *cnt + 1;
    _ZNK7PathPtr7GetNodeER7Vector3j(c + 0x364, &v, *(int *)(c + 0x36c));
    *(int *)(c + 0x380) = Vec3_Dist((struct Vector3 *)(c + 0x5c), &v);
    *(short *)(c + 0x38c) = Vec3_HorzAngle((struct Vector3 *)(c + 0x5c), &v);
}
