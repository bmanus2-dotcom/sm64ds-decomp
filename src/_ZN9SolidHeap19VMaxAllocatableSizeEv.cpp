//cpp
extern "C" {
extern unsigned int _ZN18SolidHeapAllocator10MemoryLeftEi(void*, int);

unsigned int _ZN9SolidHeap19VMaxAllocatableSizeEv(char* self) {
    return _ZN18SolidHeapAllocator10MemoryLeftEi(*(void**)(self + 0x14), 4);
}
}
