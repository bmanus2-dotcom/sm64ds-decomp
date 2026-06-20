/* func_ov006_020ee598 at 0x020ee598
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

struct Pair { int a, b; };
extern struct Pair data_ov006_0213cb84;

void func_ov006_020ee598(char *p) {
    *(struct Pair *)(p + 0x5000 + 4) = data_ov006_0213cb84;
}
