typedef unsigned int u32;

extern void func_0201473c(void *arg0, u32 fmtAddr, u32 val);

void func_02057d00(void *arg0, u32 fmt, ...)
{
    u32 ap = (((u32)&fmt) & ~3u) + 4;
    func_0201473c(arg0, fmt, ap);
}
