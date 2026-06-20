/* func_ov006_02115040 at 0x02115040
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_02115040(char *p, int idx) {
    int *arr = (int *)(p + 0x5968);
    arr[idx - 1] = arr[idx - 1] + 1;
}
