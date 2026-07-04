//cpp
// NONMATCHING: push-set / frame (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
void func_02051244(int* thiz);
void func_02050fb0(void);
void func_02050fd4(void* p);
}
struct HeapAllocator {
    int f0, f4, f8;
    void (*fc)(void*, int, int, int);   /* 0xc */
    int f10, f14, f18, f1c;             /* 0x10,0x14,0x18,0x1c */
    int f20;                            /* 0x20 */
};
struct NestedHeapIterator { HeapAllocator* Previous(HeapAllocator*); void Remove(HeapAllocator*); };
struct SolidHeapAllocator { void LoadState(unsigned int); void SaveState(unsigned int); };
struct Mgr {
    SolidHeapAllocator* alloc;
    NestedHeapIterator iter;
};

extern "C" void func_020510a4(Mgr* m, int n)
{
    HeapAllocator* a;
    NestedHeapIterator* it;
    if (n == 0) { func_02051244((int*)m); return; }
    a = 0;
    while (n < *(unsigned short*)((char*)m + 0xc)) {
        HeapAllocator* prev;
        it = &m->iter;
        prev = it->Previous(a);
        a = it->Previous(a);
        while (a != 0) {
            if (a->fc != 0)
                a->fc(&a->f20, a->f8, a->f10, a->f14);
            a = it->Previous(a);
        }
        it->Remove(prev);
    }
    m->alloc->LoadState(n);
    func_02050fb0();
    m->alloc->SaveState(*(unsigned short*)((char*)m + 0xc));
    func_02050fd4(m);
}
