/* func_ov006_02107b70 at 0x02107b70
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

extern void *data_ov006_02142aa4[];

void func_ov006_02107b70(int p) {
    int i;
    for (i = 0; i < 4; i++) {
        data_ov006_02142aa4[i] = (void *)p;
        p += 0x18;
    }
}
