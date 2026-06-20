/* func_ov006_020ed32c at 0x020ed32c
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

extern char data_ov006_0213ca64[];

struct S8 { int a; int b; };

void func_ov006_020ed32c(char *p) {
    *(struct S8 *)(p + 0x4000 + 0x660) = *(struct S8 *)data_ov006_0213ca64;
}
