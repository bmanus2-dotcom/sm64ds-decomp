struct Actor;
struct Vector3 { int x, y, z; };
struct Vector3_16;
extern struct Actor *_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int id, unsigned int param, const struct Vector3 *pos, const struct Vector3_16 *r, int a, int b);
extern struct Actor *func_ov002_020f0918(struct Actor *a, void *ps);

struct Actor *_ZN5Actor11SpawnNumberERK7Vector3jbtPS_(struct Actor *self, const struct Vector3 *pos, unsigned int v, int b, unsigned short t, void *ps)
{
    struct Actor *r;
    if (b) {
        r = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0x14a, (v & 0xf) | 0x10, pos, 0, *(signed char*)((char*)self+0xcc), -1);
    } else {
        r = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0x14a, v, pos, 0, *(signed char*)((char*)self+0xcc), -1);
    }
    if (r == 0) return r;
    *(unsigned short*)((char*)r+0x14c) = t;
    return func_ov002_020f0918(r, ps);
}
