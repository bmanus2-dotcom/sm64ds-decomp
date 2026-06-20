/* func_ov006_020fadfc at 0x020fadfc
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

extern unsigned char data_0209d45c;

void func_ov006_020fadfc(char *p) {
    data_0209d45c &= ~4;
    *(unsigned char *)(p + 0x5000 + 0xc0e) = 0;
}
