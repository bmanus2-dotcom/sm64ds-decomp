// NONMATCHING: size 0x68 vs 0x5c; PTMF below-sp wall under 1.2/sp2p3; pure C replaces HAND-ASM
typedef struct { int a; int b; } PMF;
extern int _ZN9ActorBase7ProcessEMS_FivEMS_FbvEMS_FvjE(void *self, PMF a, PMF b, PMF c);
extern PMF data_02099e9c;
extern PMF data_02099e74;
extern PMF data_02099ecc;

int func_0204322c(void *self)
{
    return _ZN9ActorBase7ProcessEMS_FivEMS_FbvEMS_FvjE(
        self, data_02099ecc, data_02099e74, data_02099e9c);
}
