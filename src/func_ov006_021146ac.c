/* func_ov006_021146ac at 0x021146ac
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

int func_ov006_021146ac(int *p) {
    int x = p[0xa];
    return (int)(((long long)x * x + 0x800) >> 12);
}
