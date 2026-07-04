// NONMATCHING: extra logic (you do more) (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_02017acc();
extern void func_020731dc();
extern void _ZN13SharedFilePtr9ConstructEj();
extern void func_02017ab4();
extern void func_02017984();
extern void func_020072c0();

typedef struct { int a, b; } S8;

extern S8 g_cb4, g_c9c, g_cbc, g_c94, g_cac, g_ca4;
extern S8 g_d00, g_d0c, g_d18, g_d24, g_d30, g_cc4;

typedef struct { S8 a, b; } S16;
extern S16 g_d6c[6];
extern S8 g_9fc, g_a14, g_a4c, g_a0c, g_a44, g_a3c, g_a34, g_a2c, g_a04, g_a1c, g_9f4, g_a24;

typedef struct { int base, unk4, top; } S12;
extern S12 g_d3c, g_d48, g_d54, g_d60;
extern S8 g_cd0, g_cdc, g_ce8, g_cf4;

void __sinit_ov072_02122414(void)
{
    func_02017acc(&g_cb4, 0x3ff);
    func_020731dc(&g_cb4, func_02017ab4, &g_d00);

    _ZN13SharedFilePtr9ConstructEj(&g_c9c, 0x406);
    func_020731dc(&g_c9c, func_02017984, &g_d0c);

    _ZN13SharedFilePtr9ConstructEj(&g_cbc, 0x408);
    func_020731dc(&g_cbc, func_02017984, &g_d18);

    _ZN13SharedFilePtr9ConstructEj(&g_c94, 0x400);
    func_020731dc(&g_c94, func_02017984, &g_d24);

    _ZN13SharedFilePtr9ConstructEj(&g_cac, 0x403);
    func_020731dc(&g_cac, func_02017984, &g_d30);

    _ZN13SharedFilePtr9ConstructEj(&g_ca4, 0x405);
    func_020731dc(&g_ca4, func_02017984, &g_cc4);

    g_d6c[0].a = g_9fc; g_d6c[0].b = g_a14;
    g_d6c[1].a = g_a4c; g_d6c[1].b = g_a0c;
    g_d6c[2].a = g_a44; g_d6c[2].b = g_a3c;
    g_d6c[3].a = g_a34; g_d6c[3].b = g_a2c;
    g_d6c[4].a = g_a04; g_d6c[4].b = g_a1c;
    g_d6c[5].a = g_9f4; g_d6c[5].b = g_a24;

    g_d3c.base = 0x1c000;
    g_d3c.unk4 = 0;
    g_d3c.top  = 0x1e000;
    func_020731dc(&g_d3c, func_020072c0, &g_cd0);

    g_d48.base = 0x1c000;
    g_d48.unk4 = 0;
    g_d48.top  = 0x1e000;
    func_020731dc(&g_d48, func_020072c0, &g_cdc);

    g_d54.base = 0x2b000;
    g_d54.unk4 = 0;
    g_d54.top  = 0x1e000;
    func_020731dc(&g_d54, func_020072c0, &g_ce8);

    g_d60.base = 0x30000;
    g_d60.unk4 = 0;
    g_d60.top  = 0x32000;
    func_020731dc(&g_d60, func_020072c0, &g_cf4);
}
