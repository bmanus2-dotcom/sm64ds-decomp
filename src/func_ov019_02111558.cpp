//cpp
// NONMATCHING: different op / idiom (div=55). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" int Vec3_Dist(void *a, void *b);
extern "C" int Player_StartTalk(void *actor, void *self, int b);
extern "C" short Vec3_HorzAngle(void *a, void *b);
extern "C" int ApproachLinear(short *p, int target, int step);
extern "C" void TextureSequence_SetFile(void *self, void *btp, int a, int fix, unsigned int b);
extern "C" int Player_ShowMessage(void *actor, void *ab, unsigned int id, void *pos, unsigned int a, unsigned int b);
extern "C" int Player_GetTalkState(void *actor);
extern "C" void Actor_UntrackAndSpawnStar(void *self, signed char *a, unsigned int b, void *pos, unsigned int d);
extern "C" int Player_HasFinishedTalking(void *actor);
extern "C" int func_0201267c(int a, void *pos);

extern void **data_ov019_021134a8;
extern void **data_ov019_02113468;

extern "C" int func_ov019_02111558(void *thiz)
{
    unsigned char *c = (unsigned char *)thiz;

    switch (*(unsigned char *)(c + 0x38f)) {
    case 0: {
        int r5 = *(int *)(c + 0x178);
        int d = Vec3_Dist(c + 0x5c, (char *)*(void **)(c + 0x378) + 0x5c);
        if (d < r5 + 0x78000) {
            if (Player_StartTalk(*(void **)(c + 0x378), c, 1) != 0) {
                unsigned char *p = c + 0x38f;
                *p = *p + 1;
            }
        }
        break;
    }
    case 1: {
        short ang = Vec3_HorzAngle(c + 0x5c, (char *)*(void **)(c + 0x378) + 0x5c);
        if (ApproachLinear((short *)(c + 0x8e), ang, 0x514) != 0) {
            unsigned int id;
            int v[3];
            v[0] = *(int *)(c + 0x5c);
            v[1] = *(int *)(c + 0x60) + 0x190000;
            v[2] = *(int *)(c + 0x64);
            if (*(unsigned char *)(c + 0x394) != 0) {
                TextureSequence_SetFile(c + 0x138, (&data_ov019_021134a8)[1], 0, 0x1000, 0);
                id = 0xa9;
                *(unsigned char *)(c + 0x395) = 1;
            } else {
                if (*(unsigned char *)(c + 0x395) != 0)
                    id = 0xaa;
                else
                    id = 0xa8;
            }
            if (Player_ShowMessage(*(void **)(c + 0x378), c, id, v, 1, 2) != 0) {
                func_0201267c(0xdf, c + 0x74);
                {
                    unsigned char *p = c + 0x38f;
                    *p = *p + 1;
                }
            }
        }
        break;
    }
    case 2:
        if (Player_GetTalkState(*(void **)(c + 0x378)) == 2) {
            if (*(unsigned char *)(c + 0x395) == 0) {
                Actor_UntrackAndSpawnStar(c, (signed char *)(c + 0x396),
                                          (*(unsigned int *)(c + 8) >> 8) & 0xf,
                                          c + 0x5c, 4);
                Player_HasFinishedTalking(*(void **)(c + 0x378));
            }
            TextureSequence_SetFile(c + 0x138, (&data_ov019_02113468)[1], 0, 0x1000, 0);
            {
                unsigned char *p = c + 0x38f;
                *p = *p + 1;
            }
        }
        break;
    }
    return 1;
}
