extern void func_02035514(void* c);
extern int* func_0203819c(void* t);
extern unsigned int data_02099264[];
extern unsigned int data_02099274[];

void* _ZN13RaycastGroundC1Ev(char* c){
    func_02035514(c);
    func_0203819c(c + 0x10);
    *(unsigned int**)c = data_02099264;
    *(unsigned int**)(c + 0x10) = data_02099274;
    *(int*)(c + 0x4c) = 0x1f4000;
    return c;
}
