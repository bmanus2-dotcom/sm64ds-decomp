asm void _ZN4CP1516DrainWriteBufferEv(void){
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}
