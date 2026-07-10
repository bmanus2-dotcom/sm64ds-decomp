//cpp
extern "C" {
void func_02046e28(void* model, void* file, int frame);
}

extern "C" void _ZN15MaterialChanger6UpdateER15ModelComponents(char* self, void* model)
{
    func_02046e28(model, *(void**)(self + 0x10), (unsigned short)(*(unsigned int*)(self + 8) >> 12));
}
