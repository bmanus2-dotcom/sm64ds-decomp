/* func_ov006_020ed300 at 0x020ed300
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

struct Pair { int a; int b; };
extern struct Pair data_ov006_0213ca5c;

void func_ov006_020ed300(char *p) {
    p += 0x4000;
    *(int *)(p + 0x66c) = 0xb4;
    *(struct Pair *)(p + 0x660) = data_ov006_0213ca5c;
}
