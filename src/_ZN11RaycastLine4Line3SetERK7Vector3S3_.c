struct V3 { int x, y, z; };
void _ZN11RaycastLine4Line3SetERK7Vector3S3_(struct V3* o, const struct V3* a, const struct V3* b){
  o->x = a->x;
  o->y = a->y;
  o->z = a->z;
  *(int*)((char*)o+0xc) = b->x;
  *(int*)((char*)o+0x10) = b->y;
  *(int*)((char*)o+0x14) = b->z;
}
