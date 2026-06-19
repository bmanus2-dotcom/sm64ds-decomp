void _ZN4CP1514MPUDataRegion7Ej(unsigned int x){
    asm { mcr p15,0,x,c6,c7,0 }
}
