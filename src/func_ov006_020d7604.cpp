//cpp
// NONMATCHING: 0x70-row coin-layout loop (div~999, size 0x114 vs 0x174). Triple-
// nested counter rotation (sl/sb/r8) wall; draft logic from disasm.
extern "C" void func_ov006_020d5e3c(void *);

extern "C" void func_ov006_020d7604(char *base)
{
    int i;
    int count;
    int row;
    int col;
    int val;
    char *rowBase;

    count = 0;
    row = 0;
    col = 0;
    i = 0;
    for (;;) {
        rowBase = base + (i << 6);
        if (*(unsigned char *)(rowBase + 0x4698) != 0) {
            if (*(unsigned char *)(base + 0x62f8) == 1) {
                if (*(unsigned char *)(rowBase + 0x4696) != 0) {
                    *(unsigned char *)(rowBase + 0x469b) = 3;
                    *(unsigned short *)(rowBase + 0x4690) = (unsigned short)(count << 3);
                    if (row < 5) {
                        val = col * 10 + (row - 5);
                    } else {
                        val = col * 10 + row;
                    }
                    *(unsigned char *)(rowBase + 0x469c) = (unsigned char)val;
                    row++;
                    count++;
                }
            } else if (*(unsigned char *)(base + 0x62f5) == *(unsigned char *)(rowBase + 0x4696)
                       && *(unsigned char *)(rowBase + 0x4697) == 6) {
                *(unsigned char *)(rowBase + 0x469c) = (unsigned char)count;
                *(unsigned short *)(rowBase + 0x4690) = (unsigned short)(count << 3);
                *(unsigned char *)(rowBase + 0x469b) = 3;
                count++;
            } else if (col != 0) {
                *(unsigned char *)(rowBase + 0x469c) = (unsigned char)count;
                *(unsigned short *)(rowBase + 0x4690) = (unsigned short)(count << 3);
                *(unsigned char *)(rowBase + 0x469b) = 3;
                count++;
            }
        }
        i++;
        if (i >= 0x70)
            break;
        if (count >= 5) {
            row -= 5;
            col++;
        }
    }
    func_ov006_020d5e3c(base);
}