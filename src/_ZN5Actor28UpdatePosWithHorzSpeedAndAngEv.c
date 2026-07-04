// NONMATCHING: different op / idiom (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
typedef int s32;
typedef long long s64;
extern s16 data_02082214[];
void _ZN5Actor28UpdatePosWithHorzSpeedAndAngEv(void *c){
    s32 v98 = *(s32*)((char*)c+0x98);
    if (v98 == 0) {
        s32 a8 = *(s32*)((char*)c+0xa8);
        s32 v9c = *(s32*)((char*)c+0x9c);
        s32 a0 = *(s32*)((char*)c+0xa0);
        s32 nx = a8 + v9c;
        if (nx >= a0) a0 = nx;
        *(s32*)((char*)c+0xa4) = 0;
        *(s32*)((char*)c+0xa8) = a0;
        *(s32*)((char*)c+0xac) = 0;
        return;
    } else {
        s32 ang = *(unsigned short*)((char*)c+0x94);
        s32 j = (ang >> 4) << 1;
        s16 sinv = data_02082214[j + 1];
        s32 a8 = *(s32*)((char*)c+0xa8);
        s32 v9c = *(s32*)((char*)c+0x9c);
        s32 a0 = *(s32*)((char*)c+0xa0);
        s64 px = ((s64)v98 * sinv + 0x800) >> 12;
        s32 nx = a8 + v9c;
        if (nx >= a0) a0 = nx;
        s16 cosv = data_02082214[j];
        s64 pz = ((s64)v98 * cosv + 0x800) >> 12;
        *(s32*)((char*)c+0xa4) = (s32)pz;
        *(s32*)((char*)c+0xa8) = a0;
        *(s32*)((char*)c+0xac) = (s32)px;
        return;
    }
}
