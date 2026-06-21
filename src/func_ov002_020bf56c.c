/* func_ov002_020bf56c at 0x020bf56c
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern int func_ov002_020c031c(void *c);

int func_ov002_020bf56c(void *unused, int x)
{
    int v;
    switch (func_ov002_020c031c(unused)) {
    case 4:
    case 5:
        v = 0x199;
        break;
    case 3:
        v = 0x599;
        break;
    default:
    case 0:
        v = 0x1000;
        break;
    case 1:
    case 2:
        v = 0x1000;
        break;
    }
    return (int)(((long long)x * v + 0x800) >> 12);
}
