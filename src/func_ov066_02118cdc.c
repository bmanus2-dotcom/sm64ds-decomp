//cpp
// NONMATCHING: base materialization / addressing (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Actor;
typedef int Fix12;
typedef struct { int x; } C;
typedef struct { int y; } PMF;
extern "C" {
extern int func_ov066_021168b0(char* c);
extern Fix12 func_ov066_02116a68(Actor *self);
extern void func_ov066_02119454(C *c, PMF *p);
extern unsigned char data_ov066_0211ae0c;
extern unsigned char data_ov066_0211ae04;
extern PMF data_ov066_0211b0cc;
extern unsigned char data_ov066_0211abe0;

int func_ov066_02118cdc(char* c) {
    if (func_ov066_021168b0(c) == 0)
        return 1;
    if (*(unsigned short*)(c + 0x4d0) == 0) {
        if (func_ov066_02116a68((Actor*)c) != (Fix12)0xff3ae000) {
            if (data_ov066_0211ae0c == 0) {
                data_ov066_0211ae04 = 3;
                *(unsigned short*)(c + 0x4d2) = 0x1e;
                func_ov066_02119454((C*)c, &data_ov066_0211b0cc);
            }
            return 1;
        }
    }
    if (data_ov066_0211ae0c == 0) {
        if (data_ov066_0211abe0 == 3) {
            if (*(int*)(c + 0x494) == 0)
                data_ov066_0211ae0c = 1;
            else
                data_ov066_0211ae0c = 2;
        } else {
            data_ov066_0211ae0c = data_ov066_0211abe0;
        }
    }
    *(int*)(c + 0x494) += 1;
    *(int*)(c + 0x494) &= 1;
    return 1;
}
}
