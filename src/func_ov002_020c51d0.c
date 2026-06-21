/* func_ov002_020c51d0 at 0x020c51d0
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern int _ZN6Player7IsStateERNS_5StateE(void *self, void *state);
extern char data_ov002_0211046c[];

int func_ov002_020c51d0(char *self, int *arg)
{
    if (!_ZN6Player7IsStateERNS_5StateE(self, data_ov002_0211046c))
        return 0;
    if (*(unsigned char *)(self + 0x6e3))
        return 0;
    *(int *)(self + 0x744) = arg[0];
    *(int *)(self + 0x748) = arg[1];
    *(int *)(self + 0x74c) = arg[2];
    *(unsigned char *)(self + 0x6e5) = 1;
    return 1;
}
