typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

int func_0206e28c(const u8* a, const u8* b, u32 n) {
    while (n != 0) {
        u8 ca = *a++;
        u8 cb = *b++;
        if (ca != cb) {
            if (a[-1] < b[-1]) return -1;
            return 1;
        }
        n--;
    }
    return 0;
}
