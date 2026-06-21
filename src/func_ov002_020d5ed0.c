/* func_ov002_020d5ed0 at 0x020d5ed0
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

struct State;
extern struct State data_ov002_02110064;
extern struct State data_ov002_0211013c;

struct Player;
extern int _ZN6Player7IsStateERNS_5StateE(struct Player* self, struct State* s);
extern void _ZN6Player11ChangeStateERNS_5StateE(struct Player* self, struct State* s);

int func_ov002_020d5ed0(struct Player* self) {
    if (!_ZN6Player7IsStateERNS_5StateE(self, &data_ov002_02110064)) {
        *(int*)((char*)self + 0xd0) = 0;
        _ZN6Player11ChangeStateERNS_5StateE(self, &data_ov002_0211013c);
        return 0;
    }
    *(unsigned char*)((char*)self + 0x6e3) = 1;
    *(short*)((char*)self + 0x600 + 0xa4) = 0x5a;
    *(unsigned char*)((char*)self + 0x6f5) = 0;
    return 1;
}
