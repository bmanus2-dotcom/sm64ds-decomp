// NONMATCHING: register allocation (div=29). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned char u8;
void func_ov006_0211d018(char *base, int idx)
{
    int off = idx * 0x1c;
    char *r = base + off + 0x4000;
    if (*(u8 *)(r + 0xbe5) != 0) {
        *(u8 *)(r + 0xbe1) = 6;
        return;
    }
    if (*(u16 *)(base + 0x4bde + off) != 0) {
        *(u16 *)(base + 0x4bde + off) = *(u16 *)(base + 0x4bde + off) - 1;
        return;
    }
    *(u8 *)(r + 0xbe2) = 1;
    if ((*(s32 *)(base + 0x4bcc + off) >> 0xc) < 0) {
        *(u8 *)(r + 0xbe4) = 1;
        *(s32 *)(base + 0x4bcc + off) = -0x80000;
        *(s32 *)(r + 0xbd4) = -0x4800;
        *(u8 *)(r + 0xbe1) = 3;
        return;
    }
    *(u8 *)(r + 0xbe4) = 0;
    *(s32 *)(base + 0x4bcc + off) = 0x180000;
    *(s32 *)(r + 0xbd4) = -0x4800;
    *(u8 *)(r + 0xbe1) = 2;
}
