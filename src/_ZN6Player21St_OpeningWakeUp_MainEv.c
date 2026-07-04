// NONMATCHING: constant / value (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern int _ZN6Player12FinishedAnimEv(void* thiz);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(void* thiz, int a, int b, int c, u32 d);
extern void func_ov002_020bedd4(void* thiz);

int _ZN6Player21St_OpeningWakeUp_MainEv(char* thiz)
{
    switch (*(u8*)(thiz + 0x6e3)) {
    case 0:
        if (_ZN6Player12FinishedAnimEv(thiz)) {
            _ZN6Player7SetAnimEji5Fix12IiEj(thiz, 0xb4, 0, 0x1000, 0);
            (*(u8*)(thiz + 0x6e3))++;
        }
        break;
    case 1:
        break;
    case 2:
        if (_ZN6Player12FinishedAnimEv(thiz)) {
            _ZN6Player7SetAnimEji5Fix12IiEj(thiz, 0xb5, 0, 0x1000, 0);
            (*(u8*)(thiz + 0x6e3))++;
        }
        break;
    case 3:
        break;
    }

    func_ov002_020bedd4(thiz);
    return 1;
}
