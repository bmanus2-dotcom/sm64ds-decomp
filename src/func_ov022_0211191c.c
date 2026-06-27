void func_ov022_0211191c(char *a, char *b) {
    int cond = *(unsigned short*)(b + 0xc);
    cond = (cond == 0xbf);
    if (cond) {
        *(a + 0x324) = 1;
    }
}
