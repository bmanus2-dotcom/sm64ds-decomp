/* func_ov006_020e3b9c at 0x020e3b9c
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_020e3b9c(char *p) {
    int i = 0;
    do {
        *(p + 0x4000 + 0xff4) = 0;
        *(p + 0x4000 + 0xff5) = 0;
        i++;
        p += 0x18;
    } while (i < 0x3c);
}
