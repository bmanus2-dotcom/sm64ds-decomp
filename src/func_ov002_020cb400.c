/* func_ov002_020cb400 at 0x020cb400
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

struct Vector3 { int x, y, z; };

extern void* func_02012194(void* a, int b, int c, int d, int e, void* f, int g);

void* func_ov002_020cb400(char* self)
{
    int v = *(short*)(self + 0x69c);
    int n = v / 16;
    if (n >= 0x100)
        n = 0x100;
    int id = 0x107;
    if (*(int*)(*(int*)(self + 0x37c) + 0x18) & 0x1000000)
        id = 0x105;
    void* r = func_02012194(
        *(void**)(self + 0x620), 0, id, 3, n, (struct Vector3*)(self + 0x74), 0);
    *(void**)(self + 0x620) = r;
    return r;
}
