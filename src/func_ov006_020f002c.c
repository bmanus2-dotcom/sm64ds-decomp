/* func_ov006_020f002c at 0x020f002c
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_020f002c(char *p, int i) {
    *(int *)(p + i * 0x14 + 0x4000 + 0x7f0) = 0x1000;
}
