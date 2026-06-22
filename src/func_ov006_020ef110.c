extern void _ZN13SharedFilePtr7ReleaseEv(void *p);
extern void func_ov004_020ad90c(void);
extern void *data_ov006_021421b8;

int func_ov006_020ef110(void) {
    _ZN13SharedFilePtr7ReleaseEv(data_ov006_021421b8);
    data_ov006_021421b8 = 0;
    func_ov004_020ad90c();
    return 1;
}
