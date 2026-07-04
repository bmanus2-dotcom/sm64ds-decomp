//cpp
// NONMATCHING: register allocation (div=28). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
struct P { int a, b; };
extern P data_ov002_02108730;
extern P data_ov002_02108770;
extern P data_ov002_02108748;
extern P data_ov002_02108760;
extern P data_ov002_02108740;
extern P data_ov002_02108758;
extern P data_ov002_02108750;
extern P data_ov002_02108768;
extern P data_ov002_02108738;
extern P data_ov002_0210dc70[9];

void __sinit_ov002_02100c50(void){
  data_ov002_0210dc70[0] = data_ov002_02108730;
  data_ov002_0210dc70[1] = data_ov002_02108770;
  data_ov002_0210dc70[2] = data_ov002_02108748;
  data_ov002_0210dc70[3] = data_ov002_02108760;
  data_ov002_0210dc70[4] = data_ov002_02108740;
  data_ov002_0210dc70[5] = data_ov002_02108758;
  data_ov002_0210dc70[6] = data_ov002_02108750;
  data_ov002_0210dc70[7] = data_ov002_02108768;
  data_ov002_0210dc70[8] = data_ov002_02108738;
}
}
