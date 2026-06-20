/* func_ov006_020ee4e0 at 0x020ee4e0
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

struct Pair {
    int a;
    int b;
};

extern struct Pair data_ov006_0213cb5c;

void func_ov006_020ee4e0(char *p) {
    p += 0x5000;
    *(short *)(p + 0x14) = 0x20;
    *(struct Pair *)(p + 4) = data_ov006_0213cb5c;
}
