// NONMATCHING: base materialization / addressing (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020def80(char* c, int i)
{
    if (*(unsigned char*)(c + i + 0x5465) == 0) {
        if (*(unsigned char*)(c + i + 0x5462) != 0) {
            *(int*)(c + i * 4 + 0x5434) = 4;
        } else {
            *(int*)(c + i * 4 + 0x5434) = 1;
        }
        goto done;
    }
    if (*(unsigned char*)(c + i + 0x5462) != 0) {
        *(int*)(c + i * 4 + 0x5434) = 5;
        if (*(unsigned char*)(c + 0x546d) == 0xff) {
            if (*(unsigned char*)(c + 0x5469) != 1) {
                *(unsigned char*)(c + 0x546d) = (unsigned char)i;
            }
        }
        goto done;
    }
    *(int*)(c + i * 4 + 0x5434) = 2;
    *(int*)(c + i * 4 + 0x5440) = 0;
    *(int*)(c + i * 4 + 0x544c) = 0;
done:
    ;
}
