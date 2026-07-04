// NONMATCHING: base materialization / addressing (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
int func_ov004_020ad674(void);
void func_ov004_020afa20(int a0, int a1, int a2, int a3, int a4);
extern int* data_ov004_020bbfa8[];

void func_ov004_020b0de0(char* c){
    if (*(unsigned char*)(c+0xc3) == 0) return;
    if (*(unsigned char*)(c+0xc4) < 4) {
        unsigned short* p = (unsigned short*)(c+0xc0);
        *p = *p + 1;
        if (*(unsigned short*)(c+0xc0) >= 0x30) {
            unsigned char* q = (unsigned char*)(c+0xc4);
            *(unsigned short*)(c+0xc0) = 0;
            *q = *q + 1;
        }
    }
    if (*(unsigned short*)(c+0xc0) >= 0x18) return;
    {
        int i = func_ov004_020ad674();
        func_ov004_020afa20(*(int*)((char*)data_ov004_020bbfa8[i] + 0x28), 0xc0, 0xb0, -1, -1);
    }
}
