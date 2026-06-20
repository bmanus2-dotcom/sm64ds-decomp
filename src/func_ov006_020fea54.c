/* func_ov006_020fea54 at 0x020fea54
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

struct E {
    char pad[0x38];
};

void func_ov006_020fea54(struct E *base, int i) {
    char *p = (char *)&base[i];
    *(unsigned char *)(p + 0x4000 + 0xf0c) = 0;
    *(unsigned char *)(p + 0x4000 + 0xf0e) = 0;
}
