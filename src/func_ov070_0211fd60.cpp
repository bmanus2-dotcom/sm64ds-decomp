//cpp
// NONMATCHING: register allocation (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
class BCA_File {};
class ModelAnim {
public:
    void SetAnim(BCA_File *file, int a, int fix12, unsigned int b);
};

extern int data_ov070_02123520;

extern "C" int func_ov070_0211fd60(char *p) {
    BCA_File *file = (BCA_File *)(((int *)&data_ov070_02123520)[1]);
    ((ModelAnim *)(p + 0x300))->SetAnim(file, 0x1000, 0, 0);
    return 1;
}
