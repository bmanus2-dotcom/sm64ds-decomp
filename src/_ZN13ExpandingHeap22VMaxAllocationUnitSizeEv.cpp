//cpp
extern "C" {
extern unsigned int _ZN22ExpandingHeapAllocator18MaxAllocatableSizeEi(void*, int);

unsigned int _ZN13ExpandingHeap22VMaxAllocationUnitSizeEv(char* self) {
    return _ZN22ExpandingHeapAllocator18MaxAllocatableSizeEi(*(void**)(self + 0x14), 4);
}
}
