// NONMATCHING: register allocation (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct HeapAllocator;
extern void _ZN18NestedHeapIterator4InitEP13HeapAllocator(char* it, char* a);
void _ZN18NestedHeapIterator8AddFirstEP13HeapAllocator(char* it, char* a) {
    if (*(char**)it == 0) { _ZN18NestedHeapIterator4InitEP13HeapAllocator(it, a); return; }
    unsigned short* cnt = (unsigned short*)(it + 8);
    *(int*)(a + *(unsigned short*)(it + 0xa)) = 0;
    *(int*)(a + *(unsigned short*)(it + 0xa) + 4) = *(int*)it;
    *(int*)(*(char**)it + *(unsigned short*)(it + 0xa)) = (int)a;
    *(char**)it = a;
    *cnt = *cnt + 1;
}
