// NONMATCHING: different op / idiom (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void* data_ov001_020ad634[];
extern unsigned char data_ov001_020ad630[];
extern unsigned char data_ov001_020ad628[];
extern void func_ov001_020aa6cc(int r0);

void func_ov001_020ab228(char* c, char* a1, int idx, int a3, unsigned char a5){
    *(unsigned char*)(c+0x18) = (unsigned char)idx;
    *(int*)(c+4) = (int)a1;
    *(int*)(c+8) = *(int*)(a1+4);
    *(unsigned char*)(c+0x19) = (unsigned char)a3;
    *(int*)(c+0x10) = (int)data_ov001_020ad634[idx];
    char* prev = (char*)data_ov001_020ad634[idx];
    if(prev) *(int*)(prev+0xc) = (int)c;
    data_ov001_020ad634[idx] = c;
    data_ov001_020ad630[idx]++;
    if(a3==3) data_ov001_020ad628[idx] |= 8;
    *(unsigned char*)(c+0x1a) = 0;
    *(unsigned char*)(c+0x1b) = 0;
    *(unsigned char*)(c+0x1b) = (*(unsigned char*)(c+0x1b) & ~1) | (a5 & 1);
    if(a5!=0) return;
    if(a3!=3) return;
    func_ov001_020aa6cc(idx);
    *(int*)(c+0x14) = -1;
}
