/* func_02053ee0 @ 0x02053ee0 -- clear OBJ ext-palette enable bit in sub-engine
 * DISPCNT, then disable the VRAM bank assignment via func_0205402c. */
typedef unsigned short u16;
typedef volatile unsigned long vu32;

extern u16 func_0205402c(u16 *bankBitsPtr);
extern u16 data_020a60a0;

u16 func_02053ee0(void) {
    *(vu32 *)0x04001000 &= ~0x80000000;
    return func_0205402c(&data_020a60a0);
}
