/* func_ov006_020f8ed8 at 0x020f8ed8
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

extern int data_ov006_0213d5ac;

struct S {
    void *vtbl;
    int a;
    int b;
};

void func_ov006_020f8ed8(struct S *p) {
    p->vtbl = &data_ov006_0213d5ac;
    p->a = 0;
    p->b = 0;
}
