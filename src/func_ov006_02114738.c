/* func_ov006_02114738 at 0x02114738
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_02114738(char *p) {
    int b = *(int *)(p + 0x1c);
    int a = *(int *)(p + 0x18);
    *(int *)(p + 8) = a;
    *(int *)(p + 0xc) = b;
}
