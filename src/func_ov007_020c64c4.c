struct Vec3 { int x, y, z; };
extern void func_ov007_020c6314(void* c, int i, int b);
extern void SubVec3(struct Vec3 *a, struct Vec3 *b, struct Vec3 *c);
extern int LenVec3(struct Vec3 *a);

void func_ov007_020c64c4(char* c, int b) {
    char* r4;
    int i;
    for (i = 0; i < *(int*)(c + 8); i++) {
        func_ov007_020c6314(c, i, b);
    }
    if (*(int*)(c + 4) != 2) return;
    *(struct Vec3*)(c + 0x98) = *(struct Vec3*)(c + 0x70);
    r4 = *(char**)(c + 0xa4);
    SubVec3(*(struct Vec3**)*(char**)r4, *(struct Vec3**)*(char**)(r4 + 4), (struct Vec3*)(r4 + 0xc));
    *(int*)(r4 + 8) = LenVec3((struct Vec3*)(r4 + 0xc));
}
