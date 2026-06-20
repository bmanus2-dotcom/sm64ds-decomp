/* func_ov006_020fa9a0 at 0x020fa9a0
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_020fa9a0(char *p) {
    int i = 0;
    do {
        *(unsigned char *)(p + 0x4000 + 0xe6c) = 0;
        i++;
        *(unsigned char *)(p + 0x4000 + 0xe6d) = 0;
        p += 0x18;
    } while (i < 3);
}
