/* func_ov006_020ed81c at 0x020ed81c
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

struct Pair { int a; int b; };
extern struct Pair data_ov006_0213c9cc;

void func_ov006_020ed81c(char *p) {
    *(int *)(p + 0x466c) = 0x4b0;
    *(struct Pair *)(p + 0x4660) = data_ov006_0213c9cc;
}
