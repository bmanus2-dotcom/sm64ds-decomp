/* func_ov006_020da974 at 0x020da974
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

extern int data_ov006_0213bd18[];

void func_ov006_020da974(int v) {
    int i;
    for (i = 0; i < 6; i++) {
        data_ov006_0213bd18[i] = v;
    }
}
