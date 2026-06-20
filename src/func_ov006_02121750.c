/* func_ov006_02121750 at 0x02121750
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

extern short data_ov006_02140538;

void func_ov006_02121750(char *p, short v) {
    data_ov006_02140538 = v;
    *(short *)(p + 0x5dba) = v;
}
