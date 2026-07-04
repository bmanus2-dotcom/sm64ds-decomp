//cpp
// NONMATCHING: base materialization / addressing (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct ModelAnim { void SetAnim(void* bca, int b, int c, unsigned int d); };
extern "C" {
void func_ov006_020e6df0(int a0, char* a1, void* a2);
void func_ov006_020cb5c4(char* c);
extern int data_020a0ebc[];
extern int *data_ov006_021405c0;
struct W2 { int a, b; };
extern struct W2 data_ov006_0213b224;
void func_ov006_020cb690(char* c);
}
void func_ov006_020cb690(char* c)
{
    *(int*)(c+0x34) = data_020a0ebc[0];
    *(int*)(c+0x38) = data_020a0ebc[1];
    *(int*)(c+0x3c) = data_020a0ebc[2];
    ((ModelAnim*)(c+0x6c))->SetAnim((void*)data_ov006_021405c0, 0x40000000, 0x800, 0);
    func_ov006_020e6df0(0, (char*)0x17, *(void**)(c+0x1c));
    *(struct W2*)(c+0x64) = data_ov006_0213b224;
    *(int*)(c+0x20) = *(int*)(c+0x20) + 0x20000;
    func_ov006_020cb5c4(c);
}
