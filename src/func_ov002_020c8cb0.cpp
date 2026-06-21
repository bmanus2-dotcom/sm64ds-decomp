//cpp
extern "C" {
struct Player;
int _ZN6Player12FinishedAnimEv(Player *self);
void func_ov002_020ca108(char *r0);
void _ZN6Player7SetAnimEji5Fix12IiEj(Player *self, unsigned int a, int b, int c, unsigned int d);
}
extern signed char data_02092110;

extern "C" int func_ov002_020c8cb0(Player *self) {
    char *p = (char *)self;
    if (_ZN6Player12FinishedAnimEv(self)) {
        if (data_02092110 >= 0) {
            *(unsigned char *)(p + 0x70b) = 1;
        }
        func_ov002_020ca108(p);
        *(unsigned char *)(p + 0x743) = 0;
        _ZN6Player7SetAnimEji5Fix12IiEj(self, 0x47, 0, 0x1000, 0);
    }
    return 0;
}
