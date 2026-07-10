/* func_02053fbc @ 0x02053fbc -- clear OBJ ext-palette enable bit in main-engine
 * DISPCNT, then disable the VRAM bank assignment via func_0205402c. */
typedef unsigned short u16;
typedef volatile unsigned long vu32;

extern u16 func_0205402c(u16 *bankBitsPtr);
extern u16 data_020a6098;

u16 func_02053fbc(void) {
    *(vu32 *)0x04000000 &= ~0x80000000;
    return func_0205402c(&data_020a6098);
}
