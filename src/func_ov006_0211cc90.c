/* func_ov006_0211cc90 at 0x0211cc90
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_0211cc90(char *p) {
    p += 0x4000;
    if (*(unsigned char *)(p + 0xbe0) != 0) {
        *(unsigned char *)(p + 0xbe5) = 1;
    }
}
