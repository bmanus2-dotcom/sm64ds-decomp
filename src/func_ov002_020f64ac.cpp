//cpp
extern "C" {
void _ZN9Animation7AdvanceEv(void *anim);
int _ZN9Animation8FinishedEv(void *anim);
void func_ov002_020f6514(void *self, void *r1, unsigned int r2);
}

extern "C" void func_ov002_020f64ac(char *self, char *r1) {
    _ZN9Animation7AdvanceEv(self + 0x50);
    if (_ZN9Animation8FinishedEv(self + 0x50) == 0) {
        return;
    }
    unsigned int idx = *(unsigned char *)(self + 0x82);
    signed char v = *(signed char *)(r1 + (idx << 2) + 3);
    if (v < 0) {
        return;
    }
    func_ov002_020f6514(self, r1, (unsigned char)v);
}
