//cpp
// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern unsigned int data_020a4be8;
extern unsigned int data_020a4bc8;
extern unsigned int data_020a4be4;
extern unsigned int data_020a4be0;
void Crash();
void _ZN2GX12BeginLoadTexEv();
void _ZN2GX7LoadTexEPKvjj(const void*, unsigned int, unsigned int);
void _ZN2GX10EndLoadTexEv();

void _ZN5Model27LoadCompressedTextureToVramEPcjPc(char* src, unsigned int size, char* dst){
  if ((data_020a4be8 - data_020a4bc8) < size) Crash();
  _ZN2GX12BeginLoadTexEv();
  _ZN2GX7LoadTexEPKvjj(src, data_020a4bc8, size);
  data_020a4be4 += size;
  _ZN2GX7LoadTexEPKvjj(dst, data_020a4be0, size >> 1);
  data_020a4be4 += size >> 1;
  _ZN2GX10EndLoadTexEv();
  data_020a4bc8 += size;
  data_020a4be0 += size >> 1;
}
}
