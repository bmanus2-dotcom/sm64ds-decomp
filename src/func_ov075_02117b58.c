//cpp
// NONMATCHING: base materialization / addressing (div=7). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
void _ZN5Scene14StartSceneFadeEjjt(unsigned int a, unsigned int b, unsigned short c);
void _ZN5Sound22StopLoadedMusic_Layer1Ej(unsigned int a);
}
extern int data_0208ee44;
extern unsigned char data_02092778;

extern "C" void func_ov075_02117b58(char* c)
{
    int* p = (int*)(c + 0x264);
    *p = *p - data_0208ee44;
    if (*(int*)(c + 0x264) > 0) return;
    _ZN5Scene14StartSceneFadeEjjt(1, 0, 0);
    _ZN5Sound22StopLoadedMusic_Layer1Ej(0x3c);
    data_02092778 = 1;
}
