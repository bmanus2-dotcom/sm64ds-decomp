// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
int func_ov004_020adbe0(void);
void func_ov004_020b0a54(void* c);

void func_ov006_020e61c4(char *thiz)
{
    int i;
    char *p;
    unsigned short *q = (unsigned short*)(thiz + 0x5500);
    if (q[0x5b] != 0) {
        --*(volatile unsigned short*)(thiz + 0x55b6);
        if (((short*)q)[0x5b] <= 0)
            ((short*)q)[0x5b] = 0;
        return;
    }
    if (func_ov004_020adbe0() != 0) {
        *(unsigned char*)((thiz + 0x5000) + 0x5bc) = 0;
        *(int*)((thiz + 0x5000) + 0x580) = 4;
        func_ov004_020b0a54((void*)0x10);
    } else {
        *(int*)((thiz + 0x5000) + 0x580) = 4;
        func_ov004_020b0a54((void*)0x10);
    }
    *(unsigned char*)(thiz + 0xc3) = 0;
    *(unsigned char*)((thiz + 0x5000) + 0x5b9) = 0;
    p = thiz;
    for (i = 0; i < 0xb; i++) {
        *(unsigned char*)((p + 0x4000) + 0x68a) = 0;
        p += 0x30;
    }
    *(unsigned char*)((thiz + 0x5000) + 0x5c3) = 0;
}
