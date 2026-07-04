// NONMATCHING: register allocation (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
void func_02018c00(void* dst, int a, int id);
int func_0203d7b8(void);
struct Pair;
void func_0205e088(struct Pair* dst, char* src);
void Crash(void);
void FS_LoadOverlay(int a, int id);

struct Region { u32 valid; u32 start; u32 size; };
extern struct Region data_0209d3c4[12];

struct Pair { int a, b; };

void LoadOverlay(int id)
{
    struct Pair pair;
    char buf[0x24];
    u32 start, total, end;
    struct Region* slot;
    u32 i;

    func_02018c00(buf, 0, id);
    if (func_0203d7b8() != 0) return;
    func_0205e088(&pair, buf);

    slot = 0;
    total = *(u32*)(buf + 8) + *(u32*)(buf + 0xc);
    start = *(u32*)(buf + 4);
    end = start + total;
    for (i = 0; i < 12; i++) {
        if (data_0209d3c4[i].valid == 0xffffffff) {
            if (slot == 0) slot = &data_0209d3c4[i];
        } else if (data_0209d3c4[i].start + data_0209d3c4[i].size > start &&
                   end > data_0209d3c4[i].start) {
            Crash();
        }
    }
    if (slot != 0) {
        slot->valid = id;
        slot->start = start;
        slot->size = total;
    }
    FS_LoadOverlay(0, id);
    func_0203d7b8();
}
