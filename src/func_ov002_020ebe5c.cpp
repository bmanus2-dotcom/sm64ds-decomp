//cpp
extern "C" void *_ZN9ActorBasenwEj(unsigned int sz);
extern "C" void *_ZN5ActorC1Ev(void *thiz);

extern "C" void *func_ov002_020ebe5c(void)
{
    void *p = _ZN9ActorBasenwEj(0xd4);
    if (p == 0) return p;
    return _ZN5ActorC1Ev(p);
}
