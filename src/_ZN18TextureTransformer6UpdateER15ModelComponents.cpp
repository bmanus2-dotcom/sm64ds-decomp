//cpp
extern "C" {
void func_020469e8(void* model, void* file, int frame);
}

extern "C" void _ZN18TextureTransformer6UpdateER15ModelComponents(char* self, void* model)
{
    func_020469e8(model, *(void**)(self + 0x10), (unsigned short)(*(unsigned int*)(self + 8) >> 12));
}
