void _ZN9Animation17UpdateFileOffsets_ZN9AnimationER8BCA_File(char* o, void* f){
  *(char**)(o+8) = o + *(int*)(o+8);
  *(char**)(o+0xc) = o + *(int*)(o+0xc);
  *(char**)(o+0x10) = o + *(int*)(o+0x10);
  *(char**)(o+0x14) = o + *(int*)(o+0x14);
}
