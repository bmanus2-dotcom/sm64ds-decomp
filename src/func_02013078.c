typedef unsigned char u8;
typedef signed char s8;

extern u8 data_0209f250;
extern void *data_0209f394[];
extern s8 data_0209f2f8;
extern int data_0208e434;
extern int data_0208e438;
extern s8 data_02092120;
extern int data_0209b48c;

extern int func_020124c4(int a, int b, int c, int d);

int func_02013078(void)
{
    register s8 mode;
    register void *obj;
    u8 idx;
    u8 flag706;
    int has706;
    register int result;
    int tmp;

    idx = data_0209f250;
    obj = data_0209f394[idx];
    if (obj == 0)
        return -1;

    {
        register s8 *modeRef;
        modeRef = (s8 *)&data_0209f2f8;
        flag706 = *(u8 *)((char *)obj + 0x706);
        mode = *modeRef;
    }
    if (flag706 != 0)
        has706 = 1;
    else
        has706 = 0;
    result = -1;

    if (mode == 8) {
        if (data_0208e434 < 0) {
            if (has706 != 0)
                result = 0;
            else
                result = 1;
        }
    } else if (mode == 9) {
        if (has706 != 0)
            result = 1;
        else
            result = 2;
    } else if (mode == 0x12) {
        if (data_02092120 == 0) {
            result = 1;
        } else {
            if (has706 != 0)
                result = 0;
            else
                result = 2;
        }
    } else if (mode == 0xc) {
        if (data_02092120 == 0) {
            tmp = data_0209b48c;
            data_0209b48c = func_020124c4(tmp, 3, 0x18d, 0);
        }
        if (data_02092120 == 0)
            result = 4;
        else
            result = 3;
    } else if (mode == 0xd) {
        tmp = *(int *)((char *)obj + 0x60);
        if (tmp < (int)0xffe3e000)
            result = 5;
        else
            result = 6;
    } else if (mode == 0x15) {
        tmp = *(int *)((char *)obj + 0x60);
        if (tmp < 0)
            result = 5;
        else
            result = 6;
    }

    if (result >= 0 && result != data_0208e438) {
        data_0208e438 = result;
        return result;
    }
    return -1;
}