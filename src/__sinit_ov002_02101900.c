/* __sinit_ov002_02101900 at 0x02101900
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern char data_ov002_0210e104;
extern char data_ov002_0210e10c;
extern char data_ov002_0210e0fc;
extern char data_ov002_0210e118;
extern void func_02017ab4(void);
extern void func_02017984(void);

extern void func_02017acc(void *p, int x);
extern void func_020731dc(void *a, void (*b)(void), void *c);
extern void _ZN13SharedFilePtr9ConstructEj(void *t, unsigned int x);

void __sinit_ov002_02101900(void) {
    func_02017acc(&data_ov002_0210e104, 0x470);
    func_020731dc(&data_ov002_0210e104, func_02017ab4, &data_ov002_0210e10c);
    _ZN13SharedFilePtr9ConstructEj(&data_ov002_0210e0fc, 0x471);
    func_020731dc(&data_ov002_0210e0fc, func_02017984, &data_ov002_0210e118);
}
