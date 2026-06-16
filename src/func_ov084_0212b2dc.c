extern void func_ov084_0212af74(void *);
extern void func_ov084_0212abd4(void *);
void func_ov084_0212b2dc(char *c)
{
    short r;
    if (*(int *)(c + 0x460) == 3)
        func_ov084_0212af74(c);
    else
        func_ov084_0212abd4(c);
    r = *(short *)(c + 0x94);
    *(short *)(c + 0x8e) = r;
}
