//cpp
extern "C" {
extern void Copy32Bytes(void*, void*);

void _ZN3G3X11SetFogTableEPv(void* table) {
    Copy32Bytes(table, (void*)0x4000360);
}
}
