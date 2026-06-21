/* func_ov002_020e9630 at 0x020e9630
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern int SublevelToLevel(int i);
extern signed char data_0209f2f8;

int func_ov002_020e9630(void) {
    int level = SublevelToLevel(data_0209f2f8);
    if (level == 0xf || level == 0x10 || level == 0x11 || level == 0x12 ||
        level == 0x13 || level == 0x14 || level == 0x1d) {
        return 1;
    }
    return 0;
}
