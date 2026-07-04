//cpp
// NONMATCHING: extra logic (you do more) (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3; struct BCA_File;
struct Actor { Actor *ClosestPlayer(); };
struct ModelAnim { void SetAnim(BCA_File *f, int b, int c, unsigned int d); };
extern "C" int Vec3_HorzDist(const void *a, const void *b);
extern "C" short Vec3_HorzAngle(const void *a, const void *b);
extern "C" void func_0201267c(int a, void *b);
extern "C" void func_ov080_02124360(void *self);
extern "C" int data_ov080_021283d8[];

extern "C" void func_ov080_02123ecc(Actor *self)
{
    char *s = (char*)self;
    Actor *p = self->ClosestPlayer();
    int dist;
    if (p == 0) dist = 0x5dc000;
    else dist = Vec3_HorzDist(s + 0x5c, (char*)p + 0x5c);
    if (dist >= 0x5dc000) return;
    if (*(signed char*)(s + 0x181) != 1) return;
    if (dist >= 0xfa000) {
        *(int*)(s + 0x17c) = 2;
        ((ModelAnim*)(s + 0xd4))->SetAnim((BCA_File*)data_ov080_021283d8[1], 0x40000000, 0x1000, 0);
        Actor *p2 = self->ClosestPlayer();
        *(short*)(s + 0x8e) = Vec3_HorzAngle(s + 0x5c, (char*)p2 + 0x5c);
        int *a = (int*)(s + 0x150);
        int *b = (int*)(s + 0xb0);
        *(short*)(s + 0x94) = *(short*)(s + 0x8e);
        *a = *a & ~1;
        *b = *b | 0x10000000;
        func_0201267c(0x116, s + 0x74);
        return;
    }
    func_ov080_02124360(self);
}
