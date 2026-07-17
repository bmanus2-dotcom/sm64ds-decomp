//cpp
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern "C" u32 data_020a4d30;
extern "C" void _ZN8Particle6Jitter4FuncERNS_10EffectDataEPcR7Vector3(char* e, char* p, int* v)
{
    u32 s;
    int r;
    int amp;
    if ((int)*(u16*)(p + 0x2e) % (int)*(u16*)(e + 6) != 0)
        return;
    s = data_020a4d30 * 0x5eedf715u + 0x1b0cb173u;
    data_020a4d30 = s;
    amp = *(s16*)(e + 0);
    r = s >> 23;
    v[0] += (amp * r - (amp << 8)) >> 8;
    s = data_020a4d30 * 0x5eedf715u + 0x1b0cb173u;
    data_020a4d30 = s;
    amp = *(s16*)(e + 2);
    r = s >> 23;
    *(int*)(((long long)(int)(v + 1)) & 0xFFFFFFFFFFFFFFFFLL) += (amp * r - (amp << 8)) >> 8;
    s = data_020a4d30 * 0x5eedf715u + 0x1b0cb173u;
    data_020a4d30 = s;
    amp = *(s16*)(e + 4);
    r = s >> 23;
    *(int*)(((long long)(int)(v + 2)) & 0xFFFFFFFFFFFFFFFFLL) += (amp * r - (amp << 8)) >> 8;
}
