// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
asm void _ZN4CP1516DrainWriteBufferEv(void){
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}
