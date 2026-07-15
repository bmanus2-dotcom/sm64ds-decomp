// NONMATCHING: schedule wall: mov r4,#0xc0 before arg pool loads (div=5, mwccarm 1.2/sp2p3).
typedef short s16;
extern int data_ov004_020bf3f0; extern int data_ov004_020bf3fc; extern int func_0203d47c;
extern int data_ov004_020bf404; extern int data_0209e650;
extern void func_020731dc(void* a, void* b, void* node);
extern void func_0203d704(int* o, int* a, int* b);
extern void func_0203d388(int* p, int angle);
extern int RandomIntInternal(int* seed);
extern void func_ov004_020adfc4(void* c, short a1, int* outa, int* outb, int* list);
void func_ov004_020b484c(char* c) {
int m[12]; int sl, r, g, t2000, t1800, t4000, z, zero, y, x;

    z=0; *(int*)(c+0x24)=z;
    *(int*)(c+0x28)=(((*(s16*)(c+0x2c)+1)<<2)+0x1e)<<0xc;
    t2000=0x2000; t1800=0x1800; t4000=0x4000;
    m[0]=z; g=data_ov004_020bf3f0; m[1]=0-t2000; m[2]=z; m[3]=0-t1800; m[4]=z; m[5]=0-t4000;
    y=*(s16*)(c+0x12); x=*(s16*)(c+0x10); r=g&1;
    { int py=y<<0xc; int px=x<<0xc; m[6]=px; m[7]=py; }

    if(r==0){
        int c0 = 0xc0;
        int *p = &data_ov004_020bf3fc;
        void *cb = (void *)&func_0203d47c;
        void *nd = &data_ov004_020bf404;
        p[0] = z;
        p[1] = c0;
        func_020731dc(p, cb, nd);
        data_ov004_020bf3f0|=1;
    }

    zero=0;
    for(sl=0;sl<0x20;sl++){
        func_0203d704(&m[8],&m[6],&m[4]);
        func_0203d388(&m[0],0x800);
        func_0203d388(&m[4],0x800);
        func_0203d704(&m[10],&m[2],&m[0]);
{ int rr=RandomIntInternal(&data_0209e650); unsigned u=((unsigned)rr&0x7fffffffu)>>0x13; int k=0x3c; r=(((int)u)*k)>>0xc; r=r+0x5a; }
        func_ov004_020adfc4((void*)zero,(short)r,&m[8],&m[10],&data_ov004_020bf3fc);
    }
}
