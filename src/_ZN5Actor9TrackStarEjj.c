struct Actor;
extern int SublevelToLevel(int i);
extern int IsStarCollectedInCurLevel(int i);
extern void SetStarMarker(int i, int v1, int v2);
extern unsigned char data_0209f220[];
extern signed char data_0209f2f8[];
extern int data_0209f40c[];

int _ZN5Actor9TrackStarEjj(struct Actor *self, unsigned int a, unsigned int b)
{
    int v = b;
    if (b == 2) {
        if (a != data_0209f220[0]) {
            if (SublevelToLevel(data_0209f2f8[0]) <= 0xe)
                return -1;
        }
        if (IsStarCollectedInCurLevel(a)) v = 3;
    }
    signed char i;
    for (i = 0; i < 0xc; i++) {
        if (data_0209f40c[i] == 0) {
            SetStarMarker(i, (int)self, v);
            return i;
        }
    }
    return -1;
}
