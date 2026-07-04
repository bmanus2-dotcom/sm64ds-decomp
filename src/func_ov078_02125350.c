// NONMATCHING: different op / idiom (div=27). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void _ZN14BlendModelAnim7SetAnimER8BCA_Fileii5Fix12IiEt(
    int self, int bca, int a, int b, int fix, unsigned short t);
extern int _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
    unsigned int a, unsigned int b, int pos, int rot, int e, int f);

extern int data_ov078_02126ef0[];

int func_ov078_02125350(int sl)
{
    int i;
    int r;

    *(int*)(sl + 0x4fc) = 1;
    *(int*)(sl + 0x9c) = -0x2000;
    _ZN14BlendModelAnim7SetAnimER8BCA_Fileii5Fix12IiEt(
        sl + 0x2cc, data_ov078_02126ef0[1], 0, 0x40000000, 0x1000, 0);

    *(int*)(sl + 0x98) = 0;

    for (i = 0; i < *(int*)(sl + 0x4a0); i++) {
        if (*(int*)(sl + i * 4 + 0x424) == 0) {
            r = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
                0xce, 2, sl + 0x4ec, 0, *(signed char*)(sl + 0xcc), -1);
            if (r != 0) {
                *(int*)(sl + i * 4 + 0x424) = *(int*)(r + 4);
                *(int*)(sl + 0x49c) = i;
                return 1;
            }
        }
    }

    *(signed char*)(sl + 0x499) = 0;
    return 1;
}
