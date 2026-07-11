//cpp
extern "C" {
extern void *_ZN9ActorBasenwEj(unsigned int);
extern void _ZN9ActorBaseC1Ev(void *);
extern void *data_0208e4b8[];
extern void *_ZTV5Stage[];
extern void *data_ov003_020b1650[];

void *func_ov003_020adc10(void) {
    char *p = (char *)_ZN9ActorBasenwEj(0x54);
    if (p) {
        _ZN9ActorBaseC1Ev(p);
        *(void ***)p = (void **)data_0208e4b8;
        *(void ***)p = (void **)_ZTV5Stage;
        unsigned char *fl = (unsigned char *)(((int)p + 0x13) & 0xFFFFFFFFFFFFFFFF);
        *fl |= 1;
        *fl |= 4;
        *(void ***)p = (void **)data_ov003_020b1650;
    }
    return p;
}
}
