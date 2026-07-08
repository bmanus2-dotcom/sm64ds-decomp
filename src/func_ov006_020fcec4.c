extern short data_02082214[];
extern int func_020124c4(int a, int b, int c, int d);

void func_ov006_020fcec4(char *base, int idx) {
    int off = idx * 0x38;
    int a;
    int t;
    int x, y;

    *(int *)(base + 0x4660 + off) += *(int *)(base + 0x4668 + off);
    *(int *)(base + 0x4664 + off) += *(int *)(base + 0x466c + off);
    *(unsigned short *)(base + 0x4684 + off) += 0x800;
    if (*(int *)(base + 0x4678 + off) <= 0x30000)
        *(int *)(base + 0x4678 + off) += 0x800;

    a = *(unsigned short *)(base + 0x4684 + off);
    a = a >> 4;
    *(int *)(base + 0x4670 + off) =
        (int)(((long long)data_02082214[2 * a + 1] * *(int *)(base + 0x4678 + off) + 0x800) >> 12);

    a = *(unsigned short *)(base + 0x4684 + off);
    a = a >> 4;
    *(int *)(base + 0x4674 + off) =
        (int)(((long long)data_02082214[2 * a] * *(int *)(base + 0x4678 + off) + 0x800) >> 12);

    x = (*(int *)(base + 0x4660 + off) + *(int *)(base + 0x4670 + off)) >> 12;
    y = (*(int *)(base + 0x4664 + off) + *(int *)(base + 0x4674 + off)) >> 12;

    *(int *)(base + 0x467c + off) = func_020124c4(*(int *)(base + 0x467c + off), 2, 0x187, 0);

    t = 0;
    if (x >= 0x130 || x <= -0x30) t++;
    if (y >= 0xf0 || y <= -0x110) t++;
    if (t != 0) {
        *(base + 0x468c + off) = 0;
        *(base + 0x468d + off) = 0;
    }
}
