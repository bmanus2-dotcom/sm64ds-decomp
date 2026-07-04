//cpp
// NONMATCHING: base materialization / addressing (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
extern "C" unsigned short DecIfAbove0_Short(unsigned short* p);
struct Actor {
    void UntrackAndSpawnStar(signed char &a, unsigned int b, const Vector3 &c, unsigned int d);
};

extern "C" void func_ov064_0211a2c4(char *thiz)
{
    Vector3 v;
    if (*(unsigned char*)(thiz + 0x173) == 0) return;
    if (*(unsigned short*)(thiz + 0x170) == 0) return;
    if (DecIfAbove0_Short((unsigned short*)(thiz + 0x170)) != 0) return;
    if (*(unsigned char*)(thiz + 0x174) != 0xff) {
        v.x = *(int*)(thiz + 0x5c);
        v.y = *(int*)(thiz + 0x60);
        v.z = *(int*)(thiz + 0x64);
        v.y += 0xc8000;
        ((Actor*)thiz)->UntrackAndSpawnStar(
            *(signed char*)(thiz + 0x175),
            *(unsigned char*)(thiz + 0x174),
            v, 4);
    }
    *(int*)(thiz + 0xb0) |= 1;
}
