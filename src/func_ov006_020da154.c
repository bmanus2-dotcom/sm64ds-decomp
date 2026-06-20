/* func_ov006_020da154 at 0x020da154
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_020da154(char *p) {
    int i = 0;
    do {
        i++;
        *(unsigned char *)(p + 0x2b) = 9;
        p += 0x30;
    } while (i < 5);
}
