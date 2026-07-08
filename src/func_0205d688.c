extern int func_0205cdf4(void *self, int a);
extern int func_0205d3f4(void *self);

int func_0205d688(char *self, int a1, int a2, int a3) {
    int n;
    int oldpos;
    oldpos = *(int *)(self + 0x28);
    n = a2;
    {
        int avail = *(int *)(self + 0x24) - oldpos;
        if (n > avail) n = avail;
    }
    *(int *)(self + 0x2c) = a1;
    if (n < 0) n = 0;
    *(int *)(self + 0x30) = a2;
    *(int *)(self + 0x34) = n;
    if (a3 == 0)
        *(int *)(((long long)(int)(self + 0xc)) & 0xFFFFFFFFFFFFFFFFLL) |= 4;
    func_0205cdf4(self, 0);
    if (a3 == 0) {
        if (func_0205d3f4(self))
            n = *(int *)(self + 0x28) - oldpos;
        else
            n = -1;
    }
    return n;
}
