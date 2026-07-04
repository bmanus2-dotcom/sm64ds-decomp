// NONMATCHING: push-set / frame (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020f6830(char *o)
{
    int i;
    char *e;
    int count;
    if (*(unsigned short *)(o + 0x53ec) != 0) {
        *(unsigned short *)(o + 0x53ec) -= 1;
        return;
    }
    e = o;
    for (i = 0; i < 0x14; i++) {
        if (*(unsigned char *)(e + 0x51bb) != 0) {
            if (*(unsigned char *)(e + 0x51bc) == 4)
                *(unsigned char *)(e + 0x51bc) = 5;
        }
        e += 0x18;
    }
    count = 0;
    e = o;
    for (i = 0; i < 0x14; i++) {
        if (*(unsigned char *)(e + 0x51bb) != 0) {
            unsigned char st = *(unsigned char *)(e + 0x51bc);
            if (st != 1 && st != 5) {
                count++;
                break;
            }
        }
        e += 0x18;
    }
    if (count == 0)
        *(int *)(o + 0x53d8) = 7;
}
