void* _ZNK8Particle10SysTracker8Contents8FindDataEj(char* table, int id){
  if(id==0) return 0;
  int idx = id & 0xf;
  char* base = table + (idx<<2);
  char* node = *(char**)(base + 0x708);
  while(node){
    if(id == *(int*)node) return node;
    node = *(char**)(node+0x18);
  }
  return 0;
}
