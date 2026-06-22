void _ZN12MeshCollider17UpdateFileOffsetsER8KCL_File(char* o, void* f){
  *(char**)(o) = o + *(int*)(o);
  *(char**)(o+4) = o + *(int*)(o+4);
  *(char**)(o+8) = o + *(int*)(o+8);
  *(char**)(o+0xc) = o + *(int*)(o+0xc);
}
