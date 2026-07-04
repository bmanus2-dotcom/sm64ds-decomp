// NONMATCHING: register allocation (div=7). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
extern int LoadArchive(int idx);
extern void func_0201a458(void);
extern void *_ZN4Heap10SetDefaultEv(void);
extern void HeapUse(void *h);
extern void LoadTextNarcs(void);
extern void func_0201a5f8(int);
extern void LoadOverlay(int id);
extern void *func_0201a3e4(void);

extern u32 data_020a0c60;
extern void *data_020a0c5c;

void func_02034fbc(void)
{
    LoadArchive(0);
    func_0201a458();
    if (!(data_020a0c60 & 1)) {
        data_020a0c5c = _ZN4Heap10SetDefaultEv();
        data_020a0c60 |= 1;
    }
    LoadTextNarcs();
    LoadArchive(1);
    HeapUse(data_020a0c5c);
    func_0201a5f8(6);
    LoadOverlay(0x64);
    LoadOverlay(0x66);
    data_020a0c5c = func_0201a3e4();
    HeapUse(data_020a0c5c);
    LoadArchive(7);
    HeapUse(data_020a0c5c);
}
