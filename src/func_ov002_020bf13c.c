// HAND-ASM: pure regperm + dead sub sp,#0x10 frame under mwccarm 1.2/sp2p3 C.
// C tip matches schedule/shape (sin/cos smlabb before vel clamp, flag pack);
// only coloring (dst r1/vel r2/sin lr vs r2/r1/r4) and an unused 0x10 frame
// differ. Exhausted reordered C, struct-copy, u64-launder, //cpp, decl-order.
extern short data_02082214[];

asm void func_ov002_020bf13c(void)
{
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x10
    ldr r1, [r0, #8]
    cmp r1, #3
    addne sp, sp, #0x10
    ldmneia sp!, {r4, r5, r6, lr}
    bxne lr
    ldr r1, [r0, #0x578]
    cmp r1, #0
    addeq sp, sp, #0x10
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    ldrsh r3, [r0, #0x8e]
    ldr r2, [r0, #0x98]
    ldr ip, [pc, #0xa4]
    add r3, r3, #0x8000
    mov r3, r3, lsl #0x10
    mov r3, r3, asr #0x10
    mov r3, r3, lsl #0x10
    mov r3, r3, lsr #0x10
    mov r3, r3, asr #4
    mov lr, r3, lsl #1
    add r3, lr, #1
    mov lr, lr, lsl #1
    mov r3, r3, lsl #1
    ldrsh lr, [ip, lr]
    ldrsh ip, [ip, r3]
    ldr r5, [r0, #0x5c]
    mov r3, #0x78
    ldr r4, [r0, #0x64]
    smlabb lr, lr, r3, r5
    smlabb r4, ip, r3, r4
    mov r6, r2, asr #5
    cmp r6, #0x1000
    movgt r6, #0x1000
    cmp r6, #0
    movlt r6, #0
    ldrb r3, [r0, #0x6de]
    add ip, r6, #0x1000
    ldr r5, [r0, #0x60]
    mov ip, ip, asr #8
    cmp r3, #0
    and r3, ip, #0xff
    orrne r3, r3, #0x80
    andne r3, r3, #0xff
    cmp r2, #0
    orrne r2, r3, #0x40
    andne r3, r2, #0xff
    str lr, [r1]
    add r2, r5, #0xc000
    str r2, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r0, #0x57c]
    strb r3, [r0]
    add sp, sp, #0x10
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
    dcd data_02082214
}
