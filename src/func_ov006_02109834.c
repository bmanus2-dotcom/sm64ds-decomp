/* func_ov006_02109834 @ 0x02109834 (ov006, size 0x26c)
 * Race minigame frame update: updates the racers back-to-front, plays the
 * countdown beep (volume ramps over the last 3 seconds), shows the winner
 * banner with per-rank colors, and refreshes the board.
 */
typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;

typedef struct Racer {
    char b[0x34];
} Racer;

typedef struct Obj9 {
    char _p0[0x51a8];
    Racer racers[3]; /* 0x51a8 */
} Obj9;

extern int data_020a0db0;
extern int data_ov006_02138c18;
extern char data_ov006_02142ab4[];
extern char data_ov006_02142ab8[];
extern char data_ov006_0213e2e0[];
extern char data_ov006_0213e34c[];
extern char data_ov006_0213e350[];
extern char data_ov006_0213e354[];
extern char data_ov006_0213e370[];
extern char data_ov006_0213e374[];
extern char data_ov006_0213e378[];

extern void func_ov004_020b1bc8(char *, int, int, int);
extern void func_ov004_020b6430(void);
extern void func_ov006_02108cc0(char *);
extern void func_ov006_02109aa0(char *);
extern void func_ov004_020af68c(int, int, int, int, int);
extern int func_02053200(int);
extern void func_ov004_020b2220(int, int, int, int, int, int, int);
extern void func_ov006_020c0134(char *);
extern void func_ov006_020c0aa8(char *);
extern void func_ov006_02107d80(char *);
extern void func_ov006_020c1804(char *);

int func_ov006_02109834(char *c)
{
    func_ov004_020b1bc8(c, 0xc, 0xc, 0);
    func_ov004_020b6430();

    {
        int i = *(int *)(c + 0x53fc) - 1;
        for (; i >= 0; i--)
            func_ov006_02108cc0(((Obj9 *)c)->racers[i].b);
    }

    func_ov006_02109aa0(c);

    {
        int idle = (int)(((long long)(*(int *)(c + 0x53c4) == 0)) & 0xFFFFFFFFFFFFFFFFLL);
        if (idle != 0) {
            if (*(s16 *)(c + 0x53e6) < 8) {
                if (data_020a0db0 & 8) {
                    s16 idx = *(s16 *)(c + 0x53d6);
                    func_ov004_020af68c(data_ov006_02138c18,
                                        *(int *)(data_ov006_02142ab4 + idx * 8) >> 12,
                                        *(int *)(data_ov006_02142ab8 + idx * 8) >> 12,
                                        -1, 1);
                }
            }
        }
    }

    if (*(s16 *)(c + 0x53e6) == 2) {
        int t = *(s16 *)(c + 0x53e8);
        if (t <= 0xb4) {
            int u = t + 0x3b;
            s16 rem = u % 60;
            int q = u / 60;
            int vol = rem * 0x88 + 0x1000;
            if (vol > 0x2000)
                vol = 0x2000;
            func_ov004_020b2220(0x80, 0x60, q, 1, -1, func_02053200(vol), 0);
        }
    }

    {
        s16 k = *(s16 *)(c + 0x53e4);
        if (k != 0) {
            int off = k * 0xc;
            s16 hval = *(s16 *)(data_ov006_0213e2e0 + k * 2);
            {
                int d1 = *(int *)(data_ov006_0213e354 + off);
                int b1 = *(int *)(data_ov006_0213e350 + off);
                int a1 = *(int *)(data_ov006_0213e34c + off);
                *(int *)(c + 0x470c) = a1;
                *(int *)(c + 0x4710) = b1;
                *(int *)(c + 0x4714) = d1;
            }
            {
                int f2 = *(int *)(data_ov006_0213e378 + off);
                int e2 = *(int *)(data_ov006_0213e374 + off);
                int d2 = *(int *)(data_ov006_0213e370 + off);
                *(int *)(c + 0x4700) = d2;
                *(int *)(c + 0x4704) = e2;
                *(int *)(c + 0x4708) = f2;
            }
            *(s16 *)(c + 0x4718) = hval;
            func_ov006_020c0134(c + 0x4660);
        } else {
            func_ov006_020c0aa8(c + 0x4660);
        }
        if (k != 0)
            func_ov006_02107d80(c + 0x530c);
        else
            func_ov006_020c1804(c + 0x4f38);
    }

    return 1;
}
