// NONMATCHING: register allocation (div=19). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void* _ZN5Model27LoadCompressedTextureToVramEPcjPc(char* a, unsigned int b, char* c);
void* func_02045ad8(void* p);
void* func_02045a50(void* p);

int func_ov075_0211aa94(char* c, char* b){
    char* r6 = *(char**)(b+0x18);
    char* r7 = *(char**)(b+0x28);
    char* r5 = *(char**)(b+0x20);
    {
        unsigned int sz = *(unsigned int*)(r6+8);
        char* src = *(char**)(r6+4);
        *(void**)(c+0x88) = _ZN5Model27LoadCompressedTextureToVramEPcjPc(src, sz, src + sz);
    }
    if (*(int*)(r5+8) <= 8)
        *(void**)(c+0x8c) = func_02045ad8(*(void**)(r5+4));
    else
        *(void**)(c+0x8c) = func_02045a50(*(void**)(r5+4));
    *(int*)(c+0x90) = *(int*)(r7+0x28);
    *(int*)(c+0x94) = *(int*)(r7+0x2c);
    *(int*)(c+0x98) = *(int*)(r6+0x10);
    if (*(int*)(c+0x88) == 0) return 0;
    if (*(int*)(c+0x8c) != 0) return 1;
    return 0;
}
