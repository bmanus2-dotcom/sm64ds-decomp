struct Pair { void *a; int b; };

extern int someGlobal;

void func_0205e088(struct Pair *dst, char *src)
{
    struct Pair v;
    v.a = &someGlobal;
    v.b = *(int*)(src + 0x18);
    *dst = v;
}
