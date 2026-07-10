/* func_0203cc0c at 0x0203cc0c -- allocates from the default heap via
 * Heap::Allocate(unsigned) (mangled names referenced directly from C). */

extern void* _ZN6Memory14defaultHeapPtrE;
extern void* _ZN4Heap8AllocateEj(void* heap, unsigned int size);

void* func_0203cc0c(unsigned int size)
{
    return _ZN4Heap8AllocateEj(_ZN6Memory14defaultHeapPtrE, size);
}
