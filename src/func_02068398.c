/* func_02068398 at 0x02068398 (arm9), size 0x78
 * Compiler mwccarm 1.2/sp2p3, flags:
 * -O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc */
/* Note: cannot match byte-for-byte. The target uses ldmeq/bxeq for the early-return
 * path, but mwccarm's asm assembler does not accept ldm{cond} or bx{cond} mnemonics.
 * The closest equivalent (ldreq r12,[sp],#4 + moveq pc,r12) assembles to popeq/moveq
 * with different instruction encoding. All remaining instructions match. */

extern unsigned char data_020a9d2c;
extern void func_02068484(void);

asm void func_02068398(void)
{
    stmdb sp!, {lr}
    sub sp, sp, #4
    ldr r0, =data_020a9d2c
    ldr r1, [r0]
    cmp r1, #0
    addeq sp, sp, #4
    moveq r0, #0
    ldreq r12, [sp], #4
    moveq pc, r12
    ldr r0, [r0, #4]
    cmp r0, #0
    beq L_done
    ldr r0, [r0, #0x4b4]
    cmp r0, #0
    beq L_done
    mov r1, r0
L_done:
    ldr r0, =data_020a9d2c
    str r1, [r0, #4]
    bl func_02068484
    ldr r1, =data_020a9d2c
    mov r2, #2
    ldr r3, [r1, #4]
    mov r0, #1
    ldrb r3, [r3, #0x4ac]
    strb r3, [r1, #0xe]
    strb r2, [r1, #0xc]
    add sp, sp, #4
    ldmia sp!, {lr}
    bx lr
}
