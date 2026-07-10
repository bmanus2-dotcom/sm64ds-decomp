//cpp
extern "C" {
void func_02046bbc(void* model, void* file, int frame);
}

extern "C" void _ZN15TextureSequence6UpdateER15ModelComponents(char* self, void* model)
{
    func_02046bbc(model, *(void**)(self + 0x10), (unsigned short)(*(unsigned int*)(self + 8) >> 12));
}
