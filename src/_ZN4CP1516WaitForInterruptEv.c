void _ZN4CP1516WaitForInterruptEv(void){
    unsigned int v = 0;
    asm { mcr p15,0,v,c7,c0,4 }
}
