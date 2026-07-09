typedef unsigned short u16;

void func_0206ca7c(u16 *st, u16 color)
{
    u16 r5;
    u16 r3;
    u16 lr;
    u16 ip;
    u16 r1;
    char *r4;
    char *r2;
    u16 odd;

    r5 = st[0];
    r3 = (r5 + 1) & 0x3fff;
    if (r3 == st[2])
        return;
    r4 = (char *)(*(int *)((char *)0x027fff60 + 0x1c) + 0x8000);
    lr = r5 & ~1u;
    ip = *(u16 *)(r4 + lr);
    odd = r5 & 1;
    r1 = (ip & (0xff00 >> (odd * 8))) | ((color << (odd * 8)) | (color & (0xff >> (odd * 8))));
    r2 = r4 + lr;
    *(u16 *)r2 = r1;
    st[0] = r3;
}