/* func_ov006_0210d898 at 0x0210d898
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

int func_ov006_0210d898(char *p) {
    if (*(int *)(p + 0x40) == 0) {
        return 1;
    }
    return *(short *)(p + 0x32) == 0x3000;
}
