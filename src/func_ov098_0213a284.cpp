//cpp
struct V {
  virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
  virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
  virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
  virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
  virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
  virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
  virtual void v28(); virtual void v29(); virtual void v30(); virtual void m31();
};
extern "C" {
void func_ov098_0213a284(char* c){
  if (*(unsigned char*)(c+0x33f) != 0) return;
  ((V*)c)->m31();
  *(unsigned char*)(c+0x33f) = 0xa;
  *(unsigned char*)(c+0x33c) = 3;
  *(short*)(c+0x33a) = 0x3c;
}
}
