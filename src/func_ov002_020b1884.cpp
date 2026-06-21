//cpp
struct Vector3 { int x, y, z; };

extern "C" void GiveCoins(unsigned int, int);

struct Sound {
    static void PlayBank3(unsigned int, const Vector3 &);
};

struct Player {
    char pad[0x6d8];
    unsigned char f6d8;       /* +0x6d8 */
    char pad2[0x706 - 0x6d9];
    unsigned char f706;       /* +0x706 */
    void Heal(int);
};

struct Actor {
    char pad[0x74];
    Vector3 pos;             /* +0x74 */
    char pad2[0x3a8 - 0x80];
    short f3a8;              /* +0x3a8 */
    void KillAndTrackInDeathTable();
};

extern "C" void func_ov002_020b1884(Actor *self, Player *player) {
    self->f3a8 = 0;
    self->KillAndTrackInDeathTable();
    if (player->f706 != 0)
        Sound::PlayBank3(0x12, self->pos);
    else
        Sound::PlayBank3(0x11, self->pos);
    GiveCoins(player->f6d8, 1);
    player->Heal(0x100);
}
