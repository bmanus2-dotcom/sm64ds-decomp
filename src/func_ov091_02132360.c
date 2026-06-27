void func_ov091_02132360(char *a, char *b) {
    int cond = *(unsigned short*)(b + 0xc);
    cond = (cond == 0xbf);
    if (cond) {
        *(a + 0x356) = 1;
    }
}
