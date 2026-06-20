/* func_ov006_020deac8 at 0x020deac8
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov006).
 */

int func_ov006_020deac8(char *p) {
    int i = 0;
    do {
        if (*(unsigned char *)(p + 0x15) == 0)
            break;
        i++;
        p += 0x18;
    } while (i < 0x20);
    return i;
}
