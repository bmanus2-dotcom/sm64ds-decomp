extern int _ZN4cstd5atan2E5Fix12IiES1_(int y, int x);
extern void func_ov006_020fbbe8(void* self);
extern void func_ov006_020fbd38(void* self);

void func_ov006_020fe750(char* self, int i)
{
    int off = i * 0x38;
    int oldS;
    int qi;
    int pi;

    *(int*)(self + 0x4ed8 + off) += *(int*)(self + 0x4ee0 + off);
    *(int*)(self + 0x4edc + off) += *(int*)(self + 0x4ee4 + off);
    *(int*)(self + 0x4efc + off) += 0x10;
    oldS = *(int*)(self + 0x4ee4 + off);
    *(int*)(self + 0x4ee4 + off) = oldS + *(int*)(self + 0x4efc + off);
    if (*(int*)(self + 0x4ee4 + off) >= 0x8000)
        *(int*)(self + 0x4ee4 + off) = 0x8000;
    *(unsigned short*)(self + off + 0x4f08) =
        _ZN4cstd5atan2E5Fix12IiES1_(*(int*)(self + 0x4ee4 + off) >> 0xc,
                                    *(int*)(self + 0x4ee0 + off) >> 0xc);
    if (oldS < 0) {
        if (*(int*)(self + 0x4ee4 + off) >= 0)
            *(unsigned short*)(self + off + 0x4f0a) = 0x40;
    }
    if (*(unsigned short*)(self + off + 0x4f0a) != 0) {
        (*(unsigned short*)(self + 0x4f0a + off))--;
        if ((short)*(unsigned short*)(self + 0x4f0a + off) <= 0)
            *(unsigned char*)(self + off + 0x4f0d) = 4;
    }
    qi = *(int*)(self + 0x4edc + off) >> 0xc;
    if (qi <= -0x120) *(unsigned char*)(self + off + 0x4f0d) = 4;
    if (qi >= 0xd0) *(unsigned char*)(self + off + 0x4f0d) = 4;
    pi = *(int*)(self + 0x4ed8 + off) >> 0xc;
    if (pi >= 0x140 || pi <= -0x40) *(unsigned char*)(self + off + 0x4f0d) = 4;
    func_ov006_020fbbe8(self);
    if (*(unsigned char*)(self + 0x5c2f) == 0) return;
    func_ov006_020fbd38(self);
}
