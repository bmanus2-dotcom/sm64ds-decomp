//cpp
/* operator delete(void*) at 0x0203cbf0 -- deallocates from the default heap
 * via Heap::_Deallocate. Defined extern "C" under its mangled name to avoid
 * the compiler's implicit throw() exception-spec on operator delete. */

class Heap
{
public:
    void _Deallocate(void* ptr);
};

namespace Memory
{
    extern Heap* defaultHeapPtr;
}

extern "C" void _ZdlPv(void* ptr)
{
    Memory::defaultHeapPtr->_Deallocate(ptr);
}
