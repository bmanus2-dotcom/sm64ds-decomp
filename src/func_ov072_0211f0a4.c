extern int Vec3_Dist(const void* a, const void* b);
extern short Vec3_HorzAngle(const void* v0, const void* v1);
extern int data_ov072_02122b58[];
int func_ov072_0211f0a4(char* c){
    int d0 = Vec3_Dist(data_ov072_02122b58, (char*)c+0x5c);
    int d1 = Vec3_Dist(data_ov072_02122b58, (char*)(*(int*)((char*)c+0x390))+0x5c);
    int a0 = Vec3_HorzAngle(data_ov072_02122b58, (char*)c+0x5c);
    int a1 = Vec3_HorzAngle(data_ov072_02122b58, (char*)(*(int*)((char*)c+0x390))+0x5c);
    int sub = a0 - a1;
    if(d1 < d0){
        short diff = (short)sub;
        if(diff < 0) diff = -diff;
        if(diff < 0x700) goto ret1;
    }
    if(Vec3_Dist(data_ov072_02122b58, (char*)(*(int*)((char*)c+0x390))+0x5c) >= 0x300000) goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}
