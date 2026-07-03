extern int func_ov007_020c9214();

void func_ov007_020bc3dc(void *c, int i, int a2)
{
    unsigned short **arr;
    unsigned short *p;
    int flag;

    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) {
        return;
    }
    flag = (*(unsigned char *)((char *)p + 4) != 0) ? 1 : 0;
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}