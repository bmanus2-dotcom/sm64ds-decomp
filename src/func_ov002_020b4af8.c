/* func_ov002_020b4af8 at 0x020b4af8
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern void *data_ov002_02108d94;
extern void *data_ov002_0210ae38;
extern void _ZN18MovingMeshColliderD1Ev(void *t);
extern void _ZN5ModelD1Ev(void *t);
extern void _ZN5ActorD1Ev(void *t);
extern void func_0207328c(void *base, int count, int stride, void (*dtor)(void *));

void *func_ov002_020b4af8(char *self) {
    *(void **)self = &data_ov002_02108d94;
    func_0207328c(self + 0x4b0, 5, 0x1c8, _ZN18MovingMeshColliderD1Ev);
    func_0207328c(self + 0x320, 5, 0x50, _ZN5ModelD1Ev);
    *(void **)self = &data_ov002_0210ae38;
    _ZN18MovingMeshColliderD1Ev(self + 0x124);
    _ZN5ModelD1Ev(self + 0xd4);
    _ZN5ActorD1Ev(self);
    return self;
}
