/* func_ov006_0210c2c0 at 0x0210c2c0
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

struct S {
    char pad[0x1c];
    int a;   /* 0x1c */
    int b;   /* 0x20 */
};

void func_ov006_0210c2c0(struct S *p, int n) {
    p->b = (p->a * n) << 2;
}
