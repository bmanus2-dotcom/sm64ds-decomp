//cpp
struct OamAttr;
struct Matrix2x2;
extern "C" {
extern int data_ov002_0210b998[];
extern void _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(int a, OamAttr* attr, int x, int y, int p4, int p5, Matrix2x2* m);
void func_ov002_020f3978(char* self){
  int i;
  char* p=self;
  for(i=0;i<4;i++,p+=0x4c){
    if(*(unsigned char*)(p+0x45)){
      _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(1,(OamAttr*)data_ov002_0210b998[i],
        *(int*)p>>12,*(int*)(p+4)>>12,-1,1,0);
    }
  }
}
}
