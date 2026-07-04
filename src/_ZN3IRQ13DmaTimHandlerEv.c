// NONMATCHING: register allocation (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
typedef unsigned short u16;

extern void _ZN3IRQ11DisableIRQsEj(u32 mask);

typedef struct {
    void (*fn)(void *);   /* +0 */
    u32   flag;           /* +4 */
    void *arg;            /* +8 */
} DmaEnt;

extern DmaEnt data_020a60c4[];
extern u16 data_02099fd4[];
extern volatile u32 reg[];

void _ZN3IRQ13DmaTimHandlerEv(u32 idx) {
    void (*fn)(void *) = data_020a60c4[idx].fn;
    u16 bit = data_02099fd4[idx];
    u32 mask = 1u << bit;
    data_020a60c4[idx].fn = 0;
    if (fn != 0)
        fn(data_020a60c4[idx].arg);
    reg[0x3ff8 / 4] |= mask;
    if (data_020a60c4[idx].flag != 0)
        return;
    _ZN3IRQ11DisableIRQsEj(mask);
}
