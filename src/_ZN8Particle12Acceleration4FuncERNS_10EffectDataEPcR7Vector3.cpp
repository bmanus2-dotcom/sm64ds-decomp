//cpp
extern "C" {
void _ZN8Particle12Acceleration4FuncERNS_10EffectDataEPcR7Vector3(char* ed, char* p, int* vec){
  vec[0] += (int)*(short*)(ed+0);
  *(int*)(((long long)(int)(vec+1)) & 0xFFFFFFFFFFFFFFFFLL) += (int)*(short*)(ed+2);
  *(int*)(((long long)(int)(vec+2)) & 0xFFFFFFFFFFFFFFFFLL) += (int)*(short*)(ed+4);
}
}
