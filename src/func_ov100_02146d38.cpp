//cpp
extern "C" {
extern void *_ZN9ActorBasenwEj(unsigned int);
extern void _ZN5ActorC2Ev(void *);
extern void _ZN9ModelAnimC1Ev(void *);
extern void func_0203b9b4(int *p, int v);
extern void *data_ov100_021484bc;
void *func_ov100_02146d38(void)
{
    char *p = (char *)_ZN9ActorBasenwEj(0x160);
    if (p)
    {
        _ZN5ActorC2Ev(p);
        *(void **)p = &data_ov100_021484bc;
        _ZN9ModelAnimC1Ev(p + 0xd4);
        func_0203b9b4((int *)(p + 0x138), 1);
    }
    return p;
}
}
