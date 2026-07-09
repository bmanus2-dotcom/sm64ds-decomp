//cpp
struct BMD_TexEntry {
    int field0;
    int tex;
    int palBase;
    int fieldC;
    int flags;
};

struct BMD_PalEntry {
    int field0;
    int src;
    int size;
    int allocOff;
};

struct BMD_File {
    char pad0[0x14];
    unsigned int texCount;
    BMD_TexEntry* texArr;
    unsigned int palCount;
    BMD_PalEntry* palArr;
};

extern "C" {
extern int func_02045b58(int tex, int pal);
extern int func_02045c10(int tex);
extern void func_02056998(void);
extern void func_02019740(void);
extern void func_02056924(int dst, int srcOff, int size);
extern void func_020568cc(void);
extern unsigned int data_020a4bd8;
extern unsigned int data_020a4bcc;
}

extern "C" void _ZN5Model13LoadTexAndPalER8BMD_File(BMD_File& sl)
{
    unsigned int r6;
    unsigned int r4;
    int r0;
    int r7;
    unsigned int r8;
    BMD_TexEntry* r5;
    int r1;
    int r2;
    unsigned int* r4p;
    unsigned int* r5p;
    unsigned int fp;
    unsigned int r8p;
    BMD_PalEntry* sb;
    unsigned int r7p;
    unsigned int r6p;

    r6 = 0;
    r0 = (int)sl.texCount;
    if ((unsigned int)r0 == 0)
        goto done_tex;

    r0 = 0x10000;
    r8 = 0xffff;
    r4 = 0;
    r7 = -r0;
    do {
        r0 = (int)sl.texArr;
        r5 = (BMD_TexEntry*)(r0 + r4);
        r0 = r5->flags;
        r1 = r5->palBase;
        r0 = (unsigned int)r0 >> 26;
        r0 &= 7;
        if (r0 == 5) {
            r0 = r5->tex;
            r2 = r0 + r1;
            r0 = func_02045b58(r0, r2);
        } else {
            r0 = r5->tex;
            r0 = func_02045c10(r0);
        }
        r1 = r5->flags;
        r0 = (int)((unsigned int)r8 & ((unsigned int)r0 >> 3));
        r1 &= r7;
        r0 |= r1;
        r5->flags = r0;
        r0 = (int)sl.texCount;
        r6++;
        r4 += 0x14;
    } while (r6 < (unsigned int)r0);

done_tex:
    func_02056998();

    r7p = 0;
    r0 = (int)sl.palCount;
    if ((unsigned int)r0 == 0)
        goto done_pal;

    r4p = &data_020a4bd8;
    r5p = &data_020a4bcc;
    fp = 0xfff8;
    r8p = 0;
    do {
        r0 = (int)sl.palArr;
        sb = (BMD_PalEntry*)(r0 + r8p);
        r6p = sb->size;
        r1 = (int)*r5p;
        r0 = (int)*r4p;
        r1 += (int)r6p;
        if ((unsigned int)r1 > (unsigned int)r0)
            func_02019740();
        if (r6p > 8) {
            r0 = 0xfff0;
            r1 = (int)r6p + 0xf;
            r2 = (int)*r4p;
            r0 &= r1;
            r1 = r2 - r0;
            *r4p = (unsigned int)r1;
            r0 = sb->src;
            r2 = (int)r6p;
            func_02056924(r0, r1, r2);
            r0 = (int)*r4p;
            sb->allocOff = r0;
        } else {
            r0 = sb->src;
            r1 = (int)*r5p;
            r2 = (int)r6p;
            func_02056924(r0, r1, r2);
            r1 = (int)*r5p;
            r0 = (int)r6p + 7;
            sb->allocOff = r1;
            r1 = (int)*r5p;
            r0 &= (int)fp;
            r0 = r1 + r0;
            *r5p = (unsigned int)r0;
        }
        r0 = (int)sl.palCount;
        r7p++;
        r8p += 0x10;
    } while (r7p < (unsigned int)r0);

done_pal:
    func_020568cc();
}