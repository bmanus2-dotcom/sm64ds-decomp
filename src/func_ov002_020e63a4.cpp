//cpp
struct Vector3 { int x, y, z; };
struct Actor;
struct MovingCylinderClsnWithPos {
    void Init(Actor *a, const Vector3 &pos, int r, int s, unsigned int t, unsigned int u);
};

extern const Vector3 data_ov002_0210f92c;

extern "C" void func_ov002_020e63a4(Actor *self) {
    Vector3 v;
    v.x = data_ov002_0210f92c.x;
    v.y = data_ov002_0210f92c.y;
    v.z = data_ov002_0210f92c.z;
    ((MovingCylinderClsnWithPos *)((char *)self + 0x2d4))->Init(
        self, v, 0x28000, 0x96000, 0x400008, 0x4f3ffe0);
}
