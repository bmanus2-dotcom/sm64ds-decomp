// NONMATCHING: different op / idiom (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Pair { int a, b; };
extern void* data_ov006_0214041c;
extern struct Pair data_ov006_0213b068;
extern struct Pair data_ov006_0213b078;
extern void _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(void* self, void* bca, int b, int f, unsigned int g);
extern void func_02012718(void* a, int b);
extern void func_ov006_020e6df0(int a0, char* a1, void* a2);

void func_ov006_020c8270(char* c)
{
    struct Pair* p;
    _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj((void*)(c + 0x4c), data_ov006_0214041c, 0x40000000, 0x800, 0);
    *(int*)(c + 0xa4) = 0;
    p = (struct Pair*)(c + 0x3c);
    if (p->a == data_ov006_0213b068.a &&
        (p->b == data_ov006_0213b068.b || *(int*)(c + 0x3c) == 0)) {
        func_02012718((void*)0x110, *(short*)(c + 0x36) << 12);
    } else {
        func_ov006_020e6df0(0, (char*)4, *(void**)(c + 0x14));
    }
    func_02012718((void*)0x1b5, *(short*)(c + 0x36) << 12);
    *(int*)(c + 0x3c) = data_ov006_0213b078.a;
    *(int*)(c + 0x40) = data_ov006_0213b078.b;
}
