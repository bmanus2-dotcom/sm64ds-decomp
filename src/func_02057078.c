// NONMATCHING: predicated add/sub vs ldrge/ldrlt base select (div=11). Logic verified.
typedef unsigned int u32;

void func_02057078(int idx)
{
    u32 *p;
    u32 mask;

    if (idx >= 0x60) {
        p = (u32 *)0x27fffb4;
        idx -= 0x60;
    } else {
        p = (u32 *)0x27fffb0;
        idx -= 0x40;
    }
    mask = 0x80000000u >> idx;
    *p |= mask;
}