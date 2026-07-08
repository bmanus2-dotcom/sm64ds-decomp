//cpp
extern "C" {

typedef unsigned int u32;

extern void _ZN18NestedHeapIteratorC1Ej(void* self, u32 off);
extern void* _ZN18NestedHeapIterator10FindNestedEPv(void* ptr);
extern void _ZN18NestedHeapIterator7AddLastEP13HeapAllocator(void* iter, void* node);

extern int _ZN6Memory25isRootHeapIterInitializedE;
extern char _ZN6Memory16rootHeapIteratorE;

void _ZN13HeapAllocatorC1EjPvPvj(char* self, u32 magic, void* a, void* b, unsigned short size) {
    *(u32*)self = magic;
    *(void**)(self + 0x18) = a;
    *(void**)(self + 0x1c) = b;
    *(u32*)(self + 0x20) = 0;
    {
        u32* p = (u32*)(((long long)(int)(self + 0x20)) & 0xFFFFFFFFFFFFFFFFLL);
        *p &= ~0xffu;
        *p |= (size & 0xffu);
    }
    _ZN18NestedHeapIteratorC1Ej(self + 0xc, 4);
    if (_ZN6Memory25isRootHeapIterInitializedE == 0) {
        _ZN18NestedHeapIteratorC1Ej(&_ZN6Memory16rootHeapIteratorE, 4);
        _ZN6Memory25isRootHeapIterInitializedE = 1;
    }
    {
        void* it = _ZN18NestedHeapIterator10FindNestedEPv(self);
        _ZN18NestedHeapIterator7AddLastEP13HeapAllocator(it, self);
    }
}

}
