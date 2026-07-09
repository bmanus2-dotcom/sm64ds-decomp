//cpp
// NONMATCHING: timer intro/camera path (div~999, size 0x198 vs 0x188 — closest in
// batch). smull div-by-5 idiom + func_0203d6d0/630 call order wall.
extern "C" void func_0203d6d0(int *out, int *a, int *b);
extern "C" void func_0203d630(int *p, int mode);

extern int data_ov006_0213d6f4;
extern int data_ov006_02142578;
extern int data_ov006_0214255c;

extern "C" void func_ov006_020f9db8(char *obj, int timer)
{
    int tmp[2];
    int x;
    int y;
    int q;
    int r;

    if (timer >= 0x14)
        return;
    if (*(short *)(obj + 0x2a) >= 0x14) {
        *(int *)(obj + 0xc) = (0x70 - ((*(short *)&data_ov006_0213d6f4 >> 2) << 1)) << 12;
        *(int *)(obj + 0x10) = -0x30000;
        data_ov006_02142578 = (int)obj;
        obj[0x2d] = 1;
    } else if (obj[0x2d] == 0) {
        *(int *)(obj + 0xc) = (0x70 - ((*(short *)&data_ov006_0213d6f4 >> 2) << 1)) << 12;
        *(int *)(obj + 0x10) = -0x30000;
        obj[0x2d] = 4;
        *(short *)&data_ov006_0214255c = (short)(*(short *)&data_ov006_0214255c + 1);
    } else {
        obj[0x2d] = 4;
        *(short *)&data_ov006_0214255c = (short)(*(short *)&data_ov006_0214255c + 1);
        q = (int)(((long long)0x66666667 * (long long)timer) >> 32);
        q = (q >> 1) + (timer >> 31);
        r = timer - q * 5;
        x = ((r << 5) + 0x30) << 12;
        y = ((q + (timer >> 31)) * 0x30) << 12;
        *(int *)(obj + 0x14) = x;
        *(int *)(obj + 0x18) = y;
        *(short *)(obj + 0x2a) = (short)timer;
        func_0203d6d0(tmp, (int *)(obj + 0x14), (int *)(obj + 0xc));
        *(int *)(obj + 0x1c) = tmp[0];
        *(int *)(obj + 0x20) = tmp[1];
        func_0203d630((int *)(obj + 0x1c), 0x124);
        if (*(int *)(obj + 0x1c) < 0)
            *(int *)(obj + 0x1c) = -*(int *)(obj + 0x1c);
        if (*(int *)(obj + 0x20) < 0)
            *(int *)(obj + 0x20) = -*(int *)(obj + 0x20);
    }
}