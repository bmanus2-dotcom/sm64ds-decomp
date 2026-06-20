/* func_ov006_0210c218 at 0x0210c218
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

void func_ov006_0210c218(void *p, short a, short b) {
    *(short *)((char *)p + 0) = a;
    *(short *)((char *)p + 2) = b;
    *(int *)((char *)p + 4) = 0x48;
    *(unsigned char *)((char *)p + 8) = 1;
}
