//cpp
// NONMATCHING: base materialization / addressing (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Player;
extern "C" void func_ov002_020c9e40(Player*);
extern "C" void func_02035860(void*, void*);
extern "C" void func_0200cf40(int);
extern unsigned char data_0209f250;
extern int data_0209f318;

struct Player {
    int dummy;
    unsigned int SetAnim(unsigned int, int, int, unsigned int);
};

extern "C" int _ZN6Player15St_Respawn_InitEv(Player* thiz);
int _ZN6Player15St_Respawn_InitEv(Player* thiz) {
    char* self = (char*)thiz;
    func_ov002_020c9e40(thiz);
    *(int*)(self + 0x5c) = *(int*)(self + 0x53c);
    *(int*)(self + 0x60) = *(int*)(self + 0x540);
    *(int*)(self + 0x64) = *(int*)(self + 0x544);
    *(int*)(self + 0x60) += 0x3e8000;
    func_02035860(self + 0x380, self + 0x5c);
    *(int*)(self + 0x68) = *(int*)(self + 0x5c);
    *(int*)(self + 0x6c) = *(int*)(self + 0x60);
    *(int*)(self + 0x70) = *(int*)(self + 0x64);
    *(short*)(self + 0x94) = *(short*)(self + 0x698);
    *(short*)(self + 0x8e) = *(short*)(self + 0x94);
    *(unsigned char*)(self + 0x713) = 1;
    *(unsigned char*)(self + 0x716) = 0;
    if (*(unsigned char*)(self + 0x6d8) == data_0209f250) {
        func_0200cf40(data_0209f318);
    }
    thiz->SetAnim(0x54, 0x40000000, 0x1000, 0);
    *(unsigned char*)(self + 0x6e3) = 0;
    *(int*)(self + 0x684) = *(int*)(self + 0x60);
    *(int*)(self + 0x98) = 0;
    *(int*)(self + 0xa8) = *(int*)(self + 0x98);
    *(int*)(self + 0x9c) = 0;
    *(short*)(self + 0x6a4) = 0xa;
    return 1;
}
