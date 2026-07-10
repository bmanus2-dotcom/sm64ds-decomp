extern void func_ov001_020aa6cc(int r0);

typedef struct SubT SubT;
struct SubT {
    int f00;
    char *f04;
    int f08;
    SubT *f0c;
    SubT *f10;
    int f14;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1a;
    unsigned char f1b;
};

extern SubT *data_ov001_020ad634[];
extern unsigned char data_ov001_020ad630[];
extern unsigned char data_ov001_020ad628[];

void func_ov001_020ab228(char *c, char *a1, int idx, int a3, unsigned char a5)
{
    SubT *t = (SubT *)c;
    SubT *prev;
    unsigned char *p;

    t->f18 = (unsigned char)idx;
    t->f04 = a1;
    t->f08 = *(int *)(a1 + 4);
    t->f19 = (unsigned char)a3;
    t->f10 = data_ov001_020ad634[idx];
    prev = *(SubT * volatile *)&data_ov001_020ad634[idx];
    if (prev) prev->f0c = t;
    data_ov001_020ad634[idx] = t;
    data_ov001_020ad630[idx] = (unsigned char)(data_ov001_020ad630[idx] + 1);
    if (a3 == 3) data_ov001_020ad628[idx] |= 8;
    t->f1a = 0;
    t->f1b = 0;
    p = (unsigned char *)(int)(((long long)(int)((char *)t + 0x1b)) & 0xFFFFFFFFFFFFFFFFLL);
    *p = (unsigned char)((*p & ~1) | (a5 & 1));
    if (a5 != 0 || a3 == 3) func_ov001_020aa6cc(idx);
    t->f14 = -1;
}
