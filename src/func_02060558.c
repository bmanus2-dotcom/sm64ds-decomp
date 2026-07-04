//cpp
// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
extern "C" {
extern char data_020a8180[];
extern int data_020a6134[];
void func_020580f0(void* p);
void func_02060228(void* fn);
int func_0206071c(void* g);
}
namespace IRQ { unsigned int Disable(); void Restore(unsigned int); }

extern "C" int func_02060558(int a, int b, int c, int d, int e, int f)
{
    char* g = data_020a8180;
    unsigned int irq = IRQ::Disable();
    if (*(u32*)(g + 0x34) & 4) {
        char* p = g + 0xd4;
        do {
            func_020580f0(p);
        } while (*(u32*)(g + 0x34) & 4);
    }
    *(u32*)(g + 0x34) |= 4;
    IRQ::Restore(irq);
    *(int*)(g + 0x18) = a;
    *(int*)(g + 0x1c) = b;
    *(int*)(g + 0x20) = c;
    *(int*)(g + 0x28) = d;
    *(int*)(g + 0x2c) = e;
    if (f != 0) {
        func_02060228((void*)func_0206071c);
        return 1;
    }
    *(int*)(data_020a8180 + 0xd0) = data_020a6134[2];
    func_0206071c(g);
    return (*(int**)g)[0] == 0;
}
