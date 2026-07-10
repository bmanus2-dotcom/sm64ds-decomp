typedef struct Vector3 Vector3;
extern void func_0201267c(unsigned int id, const Vector3 *v);

void func_ov025_021119f4(char *c)
{
    *(unsigned char *)(int)(((long long)(int)(c + 0x39e)) & 0xFFFFFFFFFFFFFFFFLL) -= 1;
    if (*(unsigned char *)(c + 0x39e) != 0)
        return;
    if (*(unsigned char *)(c + 0x39f) != 4) {
        *(int *)(c + 0x398) = 5;
        *(int *)(c + 0xa8) = 0x3c000;
        func_0201267c(0xf4, (const Vector3 *)(c + 0x74));
    } else {
        *(int *)(c + 0x398) = 7;
        *(short *)(c + 0x39c) = (short)(*(short *)(c + 0x8e) + 0x8000);
    }
}
