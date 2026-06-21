/* func_ov002_020d5f98 at 0x020d5f98
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern int _ZN6Player7IsStateERNS_5StateE(void *self, void *state);
extern int RandomIntInternal(void *r);
extern char data_ov002_02110064[];
extern char data_ov002_0210e160[];

int func_ov002_020d5f98(char *self, unsigned char *out0, unsigned char *out1)
{
    if (_ZN6Player7IsStateERNS_5StateE(self, data_ov002_02110064)
        && *(unsigned char *)(self + 0x6e3) == 3
        && *(unsigned char *)(self + 0x6e5) != 0) {
        *out0 = ((unsigned int)RandomIntInternal(data_ov002_0210e160) >> 4) & 3;
        *out1 = *(unsigned char *)(self + 0x6e5);
        return 1;
    }
    return 0;
}
