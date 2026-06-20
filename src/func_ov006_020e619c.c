/* func_ov006_020e619c at 0x020e619c
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_020e619c(char *p) {
    int i = 0;
    do {
        i++;
        *(unsigned char *)(p + 0x4000 + 0x68c) = 0;
        p += 0x30;
    } while (i < 0xb);
}
