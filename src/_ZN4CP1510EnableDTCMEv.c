unsigned int _ZN4CP1510EnableDTCMEv(void){
    unsigned int v;
    asm { mrc p15,0,v,c1,c0,0 }
    v |= 0x10000;
    asm { mcr p15,0,v,c1,c0,0 }
    return v;
}
