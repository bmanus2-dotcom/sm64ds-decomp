// NONMATCHING: different op / idiom (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020da420(char *c);
void func_ov006_020da420(char *c){
    int i;
    char *p;
    short arr[6];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
    arr[4] = 0;
    arr[5] = 0;
    p = c;
    for (i = 0; i < 5; i++) {
        arr[*(unsigned char*)(p + 0x2a)]++;
        p += 0x30;
    }
    for (i = 0; i < 5; i++) {
        if (arr[*(unsigned char*)(c + 0x2a)] == 1)
            *(unsigned char*)(c + 0x2b) = 4;
        c += 0x30;
    }
}
