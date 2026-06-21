//cpp
struct Vector3 {};
struct Player {
    void SetAnim(unsigned int a, int b, int c, unsigned int d);
};
namespace Sound {
    void PlayCharVoice(unsigned int a, unsigned int b, const Vector3 &v);
}

extern "C" void func_ov002_020c9840(char *self) {
    *(unsigned char *)(self + 0x71a) = 0;
    *(unsigned char *)(self + 0x6e3) = 0x18;
    ((Player *)self)->SetAnim(0x47, 0, 0x1000, 0);
    *(unsigned short *)(self + 0x6a4) = 2;
    *(int *)(self + 0x98) = 0;
    *(int *)(self + 0xa8) = 0;
    *(unsigned char *)(self + 0x70c) = 0;
    Sound::PlayCharVoice(*(unsigned char *)(self + 0x6d9), 4, *(Vector3 *)(self + 0x74));
}
