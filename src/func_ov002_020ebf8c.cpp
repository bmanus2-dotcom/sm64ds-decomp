//cpp
extern "C" {
extern int func_0207328c(void*, int, int, void*);
extern void _ZN5ActorD1Ev(void*);
extern void *data_ov002_0210ac00;
extern int _ZN5ModelD1Ev();
int func_ov002_020ebf8c(char* c){
    *(void**)c = (void*)&data_ov002_0210ac00;
    func_0207328c((char*)c+0xd4, 5, 0x50, (void*)&_ZN5ModelD1Ev);
    _ZN5ActorD1Ev(c);
    return (int)c;
}
}
