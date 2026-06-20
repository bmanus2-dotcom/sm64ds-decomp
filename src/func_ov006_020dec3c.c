/* func_ov006_020dec3c at 0x020dec3c
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_020dec3c(char *p) {
    int i;
    for (i = 0; i < 0x20; i++) {
        p[0x15] = 0;
        p += 0x18;
    }
}
