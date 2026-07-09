typedef struct { int x, y, z; } Vec3;

extern int data_ov006_0214081c;
extern Vec3 data_ov006_021408a8;
extern void func_020072c0(void);
extern void* data_ov006_0214089c;
extern int data_02092768[4];
extern int data_020a0ebc[3];

extern void func_020731dc(int a, int b, void** node);
extern void func_0203cc28(int* p, int angle);
extern void Quaternion_FromVector3(int* q, Vec3* axis, Vec3* v);
extern void func_ov006_020ce0ac(char* c);

void func_ov006_020ceabc(char* self, int a0, int a1, int a2, int a3)
{
    int* r6;
    int r5;
    int r2;
    int* r3;
    int r0;
    int* r1;

    if ((data_ov006_0214081c & 1) == 0) {
        data_ov006_021408a8.x = 0;
        data_ov006_021408a8.y = 0x1000;
        data_ov006_021408a8.z = 0;
        func_020731dc((int)&data_ov006_021408a8, (int)&func_020072c0, (void**)&data_ov006_0214089c);
        data_ov006_0214081c |= 1;
    }

    r6 = (int*)a0;
    *(int*)(self + 0x8) = r6[0];
    *(int*)(self + 0xc) = r6[1];
    *(int*)(self + 0x10) = r6[2];
    r3 = (int*)a1;
    *(int*)(self + 0x38) = r3[0];
    *(int*)(self + 0x3c) = r3[1];
    *(int*)(self + 0x40) = r3[2];
    *(int*)(self + 0x44) = r3[0];
    *(int*)(self + 0x48) = r3[1];
    *(int*)(self + 0x4c) = r3[2];
    func_0203cc28((int*)(self + 0x44), -0x4000);

    r6 = (int*)(self + 0x14);
    *(int*)(self + 0x14) = *(int*)(self + 0x8);
    *(int*)(self + 0x18) = *(int*)(self + 0xc);
    *(int*)(self + 0x1c) = *(int*)(self + 0x10);
    r2 = r6[0];
    *(int*)(self + 0x20) = r2;
    r5 = r6[1];
    *(int*)(self + 0x24) = r5;
    r5 = r6[2];
    *(int*)(self + 0x28) = r5;
    r5 = *(int*)(self + 0x38);
    *(int*)(self + 0x50) = r5;
    r5 = *(int*)(self + 0x3c);
    *(int*)(self + 0x54) = r5;
    r5 = *(int*)(self + 0x40);
    *(int*)(self + 0x58) = r5;
    r5 = *(int*)(self + 0x44);
    *(int*)(self + 0x5c) = r5;
    r5 = *(int*)(self + 0x48);
    *(int*)(self + 0x60) = r5;
    r5 = *(int*)(self + 0x4c);
    *(int*)(self + 0x64) = r5;
    r1 = data_02092768;
    r5 = r1[0];
    *(int*)(self + 0x74) = r5;
    r5 = r1[1];
    *(int*)(self + 0x78) = r5;
    r5 = r1[2];
    *(int*)(self + 0x7c) = r5;
    r5 = r1[3];
    *(int*)(self + 0x80) = r5;
    Quaternion_FromVector3((int*)(self + 0x74), &data_ov006_021408a8, (Vec3*)(self + 0x38));

    *(short*)(self + 0x96) = (short)a2;
    *(short*)(self + 0x98) = (short)a3;
    *(int*)(self + 0x84) = 1;

    r0 = *(short*)(self + 0x96);
    if (r0 == 0)
        *(int*)(self + 0x190) = (int)(self + 0xa0);
    else if (r0 == 1)
        *(int*)(self + 0x190) = (int)(self + 0xf0);
    else
        *(int*)(self + 0x190) = (int)(self + 0x140);

    r1 = data_020a0ebc;
    r2 = r1[0];
    r0 = (int)self;
    *(int*)(self + 0x68) = r2;
    r2 = r1[1];
    *(int*)(self + 0x6c) = r2;
    r2 = r1[2];
    *(int*)(self + 0x70) = r2;
    *(int*)(self + 0x88) = 0;
    *(short*)(self + 0x92) = 0x5a;
    func_ov006_020ce0ac((char*)r0);
}