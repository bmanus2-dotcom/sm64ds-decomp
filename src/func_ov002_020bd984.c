/* func_ov002_020bd984 at 0x020bd984
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern void _ZN5Sound8EndMusicEjj(unsigned int, unsigned int);
extern void _ZN5Sound8SetMusicEjj(unsigned int, unsigned int);

struct Obj {
    char pad[0x678];
    unsigned int f678;
    unsigned int f67c;
    unsigned int f680;
    char pad2[0x6d8 - 0x684];
    unsigned char f6d8;
};

void func_ov002_020bd984(struct Obj *self, unsigned int arg)
{
    unsigned int v = self->f67c;
    if (v == 0) {
        _ZN5Sound8EndMusicEjj(self->f6d8, arg);
        self->f680 = 0;
    } else if (self->f680 == arg && v != arg) {
        _ZN5Sound8EndMusicEjj(self->f6d8, arg);
        _ZN5Sound8SetMusicEjj(self->f6d8, self->f67c);
        self->f680 = self->f67c;
    }
    self->f678 = 0;
}
