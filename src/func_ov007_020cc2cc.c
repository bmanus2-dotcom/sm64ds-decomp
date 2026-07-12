typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short DecIfAbove0_Short(unsigned short* p);
extern void _ZN5Sound22LoadAndSetMusic_Layer1Ei(int a);
extern int func_0203da9c(void);
extern u16* func_0203dabc(void);
extern int func_0203dae4(void);
extern int func_ov007_020b7090(u16 a0, u16 a1, u16 a2, u16 a3, int arg4);
extern int func_02013c84(int charID, void* dest, int fileIndex, void* src);
extern void StartFile(s8 levelID, u8 entranceID);
extern int func_0201a458(void);
extern int _ZN4Heap10SetDefaultEv(int heap);
extern int LoadArchive(int idx);
extern void LoadTextNarcs(void);
extern void _ZN4Heap6RescueEv(int heap);
extern void LoadOverlay(int id);
extern void _ZN5Scene14StartSceneFadeEjjt(unsigned int a, unsigned int b, u16 c);
extern void StartMinigameMenu(u8 returnToRecRoom);
extern void _ZN5Scene9SetFadersEP15FaderBrightness(void* p);

extern int data_ov007_02103260;
extern unsigned short data_ov007_02104c28;
extern char* data_0209b33c;
extern char data_0209caa0;
extern int data_0209d524;
extern int overlay_64;
extern int overlay_66;

int func_ov007_020cc2cc(char* c)
{
    int result;

    if (data_ov007_02103260 >= 0 && DecIfAbove0_Short(&data_ov007_02104c28) == 0) {
        _ZN5Sound22LoadAndSetMusic_Layer1Ei(data_ov007_02103260);
        data_ov007_02103260 = -1;
    }

    func_0203da9c();
    {
        u16* p = func_0203dabc();
        int arg4;
        func_0203da9c();
        arg4 = func_0203dae4();
        result = func_ov007_020b7090(p[0], p[1], p[2], p[3], arg4);
    }

    if ((unsigned int)(result - 3) <= 2) {
        int idx = 0;
        if (result == 4) {
            idx = 1;
        } else if (result == 5) {
            idx = 2;
        }
        func_02013c84(idx, data_0209b33c + idx * 0x44, -1, &data_0209caa0);
        StartFile(1, 0);
    } else if (result == 6) {
        if (data_0209d524 == 0) {
            int h1 = func_0201a458();
            int h2 = _ZN4Heap10SetDefaultEv(h1);
            LoadArchive(1);
            LoadTextNarcs();
            _ZN4Heap6RescueEv(h1);
            _ZN4Heap10SetDefaultEv(h2);
            LoadOverlay((int)&overlay_64);
            LoadOverlay((int)&overlay_66);
        }
        _ZN5Scene14StartSceneFadeEjjt(6, 0, 0x7fff);
    } else if (result == 7) {
        StartMinigameMenu(0);
    } else if (result == 2) {
        _ZN5Scene14StartSceneFadeEjjt(1, 0, 0x7fff);
    }

    _ZN5Scene9SetFadersEP15FaderBrightness(c + 0x54);
    return 1;
}
