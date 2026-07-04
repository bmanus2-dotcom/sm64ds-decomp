//cpp
// NONMATCHING: register allocation (div=41). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" void DMASyncWordTransfer(unsigned char channel, unsigned int src, unsigned int dest, unsigned int len);
extern "C" void func_02059fd0(int ch, int src, int dst, unsigned int size, void (*cb)(int), int cbarg);
extern "C" void MultiCopy_Int(int *src, int *dst, int len);

extern unsigned int data_020a60bc;
extern unsigned int data_020a60ac;
extern unsigned int data_020a60c0;
extern int data_02099fd0;

namespace GX {
void LoadTex(void const *src, unsigned int offset, unsigned int size) {
    unsigned int dst;
    unsigned int base = data_020a60bc;
    if (base == 0) {
        dst = data_020a60ac + offset;
    } else {
        unsigned int top = data_020a60c0;
        if (offset + size < top) {
            dst = data_020a60ac + offset;
        } else if (offset >= top) {
            dst = base + offset - top;
        } else {
            int len = top - offset;
            unsigned int d0 = data_020a60ac + offset;
            int ch = data_02099fd0;
            if (ch != -1) {
                DMASyncWordTransfer(ch, (unsigned int)src, d0, len);
                func_02059fd0(data_02099fd0, (int)((char*)src + len), base, size - len, 0, 0);
                return;
            }
            MultiCopy_Int((int*)src, (int*)d0, len);
            MultiCopy_Int((int*)((char*)src + len), (int*)base, size - len);
            return;
        }
    }
    if (data_02099fd0 == -1) {
        MultiCopy_Int((int*)src, (int*)dst, size);
        return;
    }
    func_02059fd0(data_02099fd0, (int)src, dst, size, 0, 0);
}
}
