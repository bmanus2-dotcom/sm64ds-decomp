/* func_ov006_020e7940 at 0x020e7940
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_020e7940(char *p, short v) {
    *(short *)(p + 0x17c) = v;
}
