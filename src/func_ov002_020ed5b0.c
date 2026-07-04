// NONMATCHING: different op / idiom (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov002_020ed5b0(char* c)
{
    char* src;
    int* sp;
    short* m;
    src = *(char**)(c + 0x38c);
    sp = (int*)(src + 0x5c);
    *(int*)(c + 0x5c) = sp[0];
    *(int*)(c + 0x60) = sp[1];
    *(int*)(c + 0x64) = sp[2];
    src = *(char**)(c + 0x38c);
    *(short*)(c + 0x8e) = *(short*)(src + 0x8e);
    *(int*)(c + 0x3d8) = *(int*)(c + 0x5c);
    *(int*)(c + 0x3dc) = *(int*)(c + 0x60);
    *(int*)(c + 0x3e0) = *(int*)(c + 0x64);
    src = *(char**)(c + 0x38c);
    m = (short*)(src + 0x8c);
    *(short*)(c + 0x3e4) = m[0];
    *(short*)(c + 0x3e6) = m[1];
    *(short*)(c + 0x3e8) = m[2];
    src = *(char**)(c + 0x38c);
    m = (short*)(src + 0x8c);
    *(short*)(c + 0x3ea) = m[0];
    *(short*)(c + 0x3ec) = m[1];
    *(short*)(c + 0x3ee) = m[2];
}
