extern void func_0203abd4(int* a, int* b, int c);
extern void func_020353b0(void* c, void* p);
extern void func_02037b5c(void* c);

void _ZN10SphereClsn15SetObjAndSphereERK7Vector35Fix12IiEP5Actor(char* c, int* vec, int fix, void* actor){
    func_0203abd4((int*)(c + 0x38), vec, fix);
    func_020353b0(c, actor);
    func_02037b5c(c);
    *(int*)(c + 0x108) = 0x1000;
}
