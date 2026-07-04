//cpp
// NONMATCHING: base materialization / addressing (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Actor;
extern "C" Actor* _ZN5Actor15FindWithActorIDEjPS_(unsigned int id, Actor* after);

extern "C" void func_ov080_02123fcc(char* thiz)
{
    char* c = thiz;
    {
        int* p150 = (int*)(c + 0x150);
        int* pb0 = (int*)(c + 0xb0);
        *p150 = *p150 | 1;
        *pb0 = *pb0 & ~0x10000000;
    }
    if (*(unsigned char*)(c + 0x180) == 0) {
        *(int*)(c + 0x17c) = 1;
        return;
    }
    {
        Actor* a = 0;
        do {
            a = _ZN5Actor15FindWithActorIDEjPS_(0x136, a);
            if (a == 0) break;
            if (a == (Actor*)c) continue;
            if (*(unsigned char*)(c + 0x182) != *(unsigned char*)((char*)a + 0x182)) continue;
            *(int*)(c + *(unsigned char*)(c + 0x183) * 4 + 0x16c) = *(int*)((char*)a + 4);
            (*(unsigned char*)(c + 0x183))++;
        } while (*(unsigned char*)(c + 0x183) != 4);
    }
    *(int*)(c + 0x17c) = 1;
}
