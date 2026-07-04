// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov004_020b0a54(int c);

struct VT { void (*m[20])(void*, int); };
struct Obj { struct VT* vt; };

void func_ov006_020df1c0(char* c)
{
    *(int*)(c + 0x541c) -= 1;
    if (*(int*)(c + 0x541c) > 0) return;
    if (*(unsigned char*)(c + 0x5469) != 0) {
        if (*(int*)(c + 0xb4) < 0x270f) *(int*)(c + 0xb4) += 1;
        if (*(int*)(c + 0xb4) > *(int*)(c + 0xb8)) *(int*)(c + 0xb8) = *(int*)(c + 0xb4);
        func_ov004_020b0a54(0);
        *(int*)(c + 0x5418) = 7;
    } else {
        if (*(int*)(c + 0xa8) > 0) {
            ((struct Obj*)c)->vt->m[18]((struct Obj*)c, -1);
        } else {
            func_ov004_020b0a54(0x12);
            *(int*)(c + 0x5418) = 7;
        }
    }
}
