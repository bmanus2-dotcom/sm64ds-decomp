extern void _ZN13SharedFilePtr7ReleaseEv(void *p);
extern void func_ov004_020ad90c(void);
extern void *data_ov006_02142184;

int func_ov006_020edffc(void) {
    _ZN13SharedFilePtr7ReleaseEv(data_ov006_02142184);
    data_ov006_02142184 = 0;
    func_ov004_020ad90c();
    return 1;
}
