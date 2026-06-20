/* func_ov006_02106bac at 0x02106bac
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_02106bac(char *p, int off) {
    *(unsigned char *)(p + off + 0x4000 + 0xf8a) = 0;
}
