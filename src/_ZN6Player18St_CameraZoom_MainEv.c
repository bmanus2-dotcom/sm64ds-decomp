//cpp
// NONMATCHING: different op / idiom (div=26). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct State;
struct Player {
    void ChangeState(State&);
    unsigned int GetBodyModelID(unsigned int, bool) const;
};
extern "C" void func_ov002_020cae10(char* c);
extern "C" int func_ov002_020cac60(char* c);
extern "C" void func_ov002_020bedd4(char* c);
extern signed char data_02092110;
extern State data_ov002_0211013c;
extern unsigned char data_020a0e40;
extern short data_0209f49e;

extern "C" int _ZN6Player18St_CameraZoom_MainEv(Player* thiz);
int _ZN6Player18St_CameraZoom_MainEv(Player* thiz) {
    char* self = (char*)thiz;
    if (data_02092110 < 0) {
        if ((unsigned short)(*(unsigned short*)(self + 0x6ce) & 4) == 0) {
            thiz->ChangeState(data_ov002_0211013c);
            unsigned int id = thiz->GetBodyModelID(*(int*)(self + 8) & 0xff, 0);
            *(int*)(*(int*)(self + id * 4 + 0xdc) + 0x50 + 8) = 0;
            *(short*)(self + 0x94) = *(short*)(self + 0x8e);
            return 1;
        }
        if (*(unsigned char*)(self + 0x6de)) {
            *(unsigned short*)(self + 0x6ce) &= ~4;
        }
        func_ov002_020cae10(self);
        if (*(short*)((char*)&data_0209f49e + data_020a0e40 * 0x18) & 0x8f03) {
            *(unsigned short*)(self + 0x6ce) &= ~4;
        }
        func_ov002_020cac60(self);
    }
    func_ov002_020bedd4(self);
    return 1;
}
