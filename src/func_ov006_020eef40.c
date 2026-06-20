/* func_ov006_020eef40 at 0x020eef40
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

extern void *data_ov006_021421c0;

void func_ov006_020eef40(void **p) {
    *p = data_ov006_021421c0;
    data_ov006_021421c0 = p;
}
