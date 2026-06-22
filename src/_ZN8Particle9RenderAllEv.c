extern void func_02049ee8(void* a, void* b);
extern char* data_0209ee74;
extern int data_0209b3ec;

void _ZN8Particle9RenderAllEv(void)
{
    char* p = data_0209ee74;
    if (p == 0) return;
    func_02049ee8(*(void**)(p + 4), &data_0209b3ec);
}
