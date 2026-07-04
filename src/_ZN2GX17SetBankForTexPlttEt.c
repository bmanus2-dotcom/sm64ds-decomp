// NONMATCHING: constant / value (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;
struct VramReg { u16 w0; u16 pad[4]; u16 fa; };
extern struct VramReg gVramReg;
extern void Vram__Map(u16 bits);
void _ZN2GX17SetBankForTexPlttEt(u16 x){
    int s = (int)x;
    u16 old = gVramReg.fa;
    gVramReg.fa = x;
    gVramReg.w0 = ~x & (gVramReg.w0 | old);
    if (s <= 0x30) {
        if (s >= 0x30) {
            goto L_b4;
        } else if (s <= 0x10) {
            if (s >= 0x10) {
                goto L_c0;
            } else if (s == 0) {
                goto done;
            }
        } else {
            if (s == 0x20) goto L_98;
        }
    } else {
        if (s <= 0x60) {
            if (s >= 0x60) {
                goto L_8c;
            } else if (s == 0x40) {
                *(volatile unsigned char*)0x4000246 = 0x83;
            }
        } else {
            if (s == 0x70) goto L_a8;
        }
    }
    goto done;
L_8c:
    *(volatile unsigned char*)0x4000246 = 0x8b;
L_98:
    *(volatile unsigned char*)0x4000245 = 0x83;
    goto done;
L_a8:
    *(volatile unsigned char*)0x4000246 = 0x9b;
L_b4:
    *(volatile unsigned char*)0x4000245 = 0x93;
L_c0:
    *(volatile unsigned char*)0x4000244 = 0x83;
done:
    Vram__Map(gVramReg.w0);
}
