//cpp
struct CylinderClsn { void Clear(); void Update(); };
extern "C" void func_ov072_02120560(void *c);
extern "C" void func_ov072_0211ffd8(void *c);

extern "C" int func_ov072_0212066c(char *c)
{
    func_ov072_02120560(c);
    ((CylinderClsn*)(c + 0x138))->Clear();
    ((CylinderClsn*)(c + 0x138))->Update();
    func_ov072_0211ffd8(c);
    return 1;
}
