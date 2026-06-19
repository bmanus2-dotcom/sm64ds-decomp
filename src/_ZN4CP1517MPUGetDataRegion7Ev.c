unsigned int _ZN4CP1517MPUGetDataRegion7Ev(void){
    unsigned int v;
    asm { mrc p15,0,v,c6,c7,0 }
    return v;
}
