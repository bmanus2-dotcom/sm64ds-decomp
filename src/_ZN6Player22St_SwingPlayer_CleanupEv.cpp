//cpp
extern "C" {
int _ZN6Player22St_SwingPlayer_CleanupEv(char* c){
  char* p = *(char**)(c + 0x358);
  if (p) {
    *(unsigned int*)(((long long)(int)(p + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL) &= ~0x800;
  }
  *(short*)(c + 0x94) = *(short*)(c + 0x8e);
  return 1;
}
}
