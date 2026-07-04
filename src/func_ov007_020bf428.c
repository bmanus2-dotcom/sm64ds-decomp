// NONMATCHING: different op / idiom (div=51). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;

extern int func_ov007_020c3df4(int a, int b);
extern int func_ov007_020cbbb0(int a, int b, int c);
extern void* func_ov007_020cbf8c(void* src);
extern void* func_ov007_020ca2a8(void* arg);
extern void* func_ov007_020ca010(void* arg);
extern void func_ov007_020bf57c(char* arg0, int idx);
extern void* func_ov007_020b42d8(int i);
extern void func_ov007_020beeb0(void);

extern int* data_ov007_02104bd4;
extern int data_ov007_020d7cb0;
extern char data_ov007_020d7cf8[];
extern u8 data_ov007_020d7c98[];
extern int* data_ov007_0210342c;
extern char data_ov007_020d7c9c;
extern char data_ov007_020d7cc8;

void func_ov007_020bf428(void)
{
    int i;

    if (data_ov007_02104bd4 != 0) return;

    data_ov007_02104bd4 = (int*)func_ov007_020c3df4(0, 0x30);
    *data_ov007_02104bd4 = (int)func_ov007_020cbbb0(0xf, 0xe, 0x6000);

    for (i = 0; i < 2; i++) {
        data_ov007_02104bd4[i + 1] = (int)func_ov007_020cbf8c(&data_ov007_020d7cf8[i * 0x34]);
        *(int*)data_ov007_02104bd4[i + 1] = *(int*)((char*)data_ov007_0210342c[data_ov007_020d7c98[i]] + 0x78);
    }

    data_ov007_02104bd4[3] = (int)func_ov007_020ca2a8(&data_ov007_020d7c9c);
    for (i = 0; i < 8; i++) {
        data_ov007_02104bd4[i + 4] = (int)func_ov007_020ca010(&data_ov007_020d7cc8);
        func_ov007_020bf57c(*(char**)(data_ov007_0210342c + 0xc), i);
    }

    for (i = 0; i <= 2; i++) {
        *(int*)((char*)data_ov007_0210342c[i] + 0x174) = (int)func_ov007_020b42d8(i);
    }

    for (i = 0; i < 0x14; i++) {
        func_ov007_020beeb0();
    }
}
