/* func_02069918 at 0x02069918 (arm9), size 0x7c
 * Compiler mwccarm 1.2/sp2p3, flags:
 * -O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc */
/* Note: cannot match byte-for-byte. The target uses ldm{cond}/bx{cond} for early returns,
 * but mwccarm's asm assembler rejects those mnemonics. Functionally equivalent ldr/mov
 * substitutes assemble to different ARM encodings. */
struct S {
    unsigned char pad0[2];
    unsigned short f2;
    unsigned short f4;
};

extern void *data_020a9db4;

asm void func_02069918(struct S *self)
{
    stmdb sp!, {lr}
    sub sp, sp, #4
    mov r1, r0
    ldrh r0, [r1, #2]
    cmp r0, #0
    addne sp, sp, #4
    ldrne r12, [sp], #4
    movne pc, r12
    ldrh r0, [r1, #4]
    cmp r0, #7
    addeq sp, sp, #4
    ldreq r12, [sp], #4
    moveq pc, r12
    cmp r0, #9
    addeq sp, sp, #4
    ldreq r12, [sp], #4
    moveq pc, r12
    cmp r0, #0x15
    addne sp, sp, #4
    ldrne r12, [sp], #4
    movne pc, r12
    ldr r2, =data_020a9db4
    mov r0, #9
    ldr r2, [r2]
    add r2, r2, #0x1000
    ldr r2, [r2, #0xe1c]
    blx r2
    add sp, sp, #4
    ldmia sp!, {lr}
    bx lr
}
