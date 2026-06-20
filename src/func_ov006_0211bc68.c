/* func_ov006_0211bc68 at 0x0211bc68
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_0211bc68(char *p, int i) {
    if (*(unsigned char *)(p + 0x5624) == 0) {
        *(unsigned char *)(p + i * 0x14 + 0x50f4) = 3;
    }
}
