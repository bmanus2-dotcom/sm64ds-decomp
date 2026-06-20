/* func_ov006_020fa740 at 0x020fa740
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

extern char data_ov006_0213d728[];

struct S {
    void *a;
    int b;
    int c;
};

void func_ov006_020fa740(struct S *p) {
    p->a = data_ov006_0213d728;
    p->b = 0;
    p->c = 0;
}
