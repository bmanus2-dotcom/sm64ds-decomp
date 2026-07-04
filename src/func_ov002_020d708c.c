//cpp
// NONMATCHING: register allocation (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Actor { static Actor* Next(const Actor*); };
extern "C" int Vec3_Dist(const void* a, const void* b);
extern "C" short Vec3_HorzAngle(const void* a, const void* b);
extern "C" short Vec3_VertAngle(const void* a, const void* b);

extern "C" Actor* func_ov002_020d708c(char* self);
Actor* func_ov002_020d708c(char* self) {
    Actor* best = 0;
    int bestAng = 0x238e;
    Actor* a = Actor::Next(0);
    if (a) {
        int thresh = bestAng;
        do {
            if (a != (Actor*)self) {
                int (*vfn)(void*) = (int(*)(void*))(*(void***)a)[0x12];
                if (vfn((void*)a)) {
                    if (Vec3_Dist(self + 0x5c, (char*)a + 0x5c) < 0x15e000) {
                        int diff = (short)(*(short*)(self + 0x8e) - Vec3_HorzAngle(self + 0x5c, (char*)a + 0x5c));
                        int ad = diff < 0 ? -diff : diff;
                        if (ad <= thresh) {
                            int ad2 = diff < 0 ? (short)(-diff) : diff;
                            if (ad2 < bestAng) {
                                bestAng = diff;
                                best = a;
                            }
                        }
                    }
                }
            }
            a = Actor::Next(a);
        } while (a);
    }
    if (best) {
        short v = Vec3_VertAngle(self + 0x5c, (char*)best + 0x5c);
        char* o = self + 0x700;
        *(short*)(o + 0x62) = 0;
        *(short*)(o + 0x64) = (short)bestAng;
        *(short*)(o + 0x66) = v;
        *(unsigned char*)(self + 0x742) = 1;
    }
    return best;
}
