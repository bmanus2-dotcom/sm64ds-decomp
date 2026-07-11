//cpp
extern "C" {
extern void _ZN18SolidHeapAllocator5ResetEj(void*, unsigned int);

void _ZN9SolidHeap14VDeallocateAllEv(char* self) {
    _ZN18SolidHeapAllocator5ResetEj(*(void**)(self + 0x14), 3);
}
}
