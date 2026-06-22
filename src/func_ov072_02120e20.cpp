//cpp
struct Player { int IsDiving(); };
struct Actor { Player* ClosestPlayer(); };
extern "C" void func_ov072_02121d50(void *c, int v);

extern "C" void func_ov072_02120e20(Actor *c)
{
    Player *p = c->ClosestPlayer();
    if (p->IsDiving()) func_ov072_02121d50(c, 1);
}
