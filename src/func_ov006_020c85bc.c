//cpp
// NONMATCHING: base materialization / addressing (div=8). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
extern "C" int _Z15ApproachLinear2Rsss(s16 &dst, s16 a, s16 b);
extern "C" void func_ov006_020c8270(void *self);
extern "C" int data_ov006_0213b00c;

extern "C" void func_ov006_020c85bc(char *o)
{
    if (_Z15ApproachLinear2Rsss(*(s16 *)(o + 0x32), 0, 1) == 0) {
        *(int *)(o + 0x18) = 0;
        return;
    }
    *(unsigned char *)(o + 0x35) = 1;
    *(int *)(o + 0x18) = 0;
    {
        int *p = (int *)(o + 0x20);
        *p = *p << 1;
    }
    *(int *)(o + 0x24) = data_ov006_0213b00c;
    *(short *)(o + 0x10) = 0;
    func_ov006_020c8270(o);
}
