/* func_ov006_020f1e40 at 0x020f1e40
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_020f1e40(int *base, int i) {
    char *p = (char *)&base[i];
    *(int *)(p + 0x4000 + 0xbb8) = 0;
    *(int *)(p + 0x4000 + 0xd98) = 0;
}
