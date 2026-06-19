void _ZN4CP1514MPUDataRegion1Ej(unsigned int x){
    asm { mcr p15,0,x,c6,c1,0 }
}
