//cpp
extern "C" {
void func_0203ae58(int* value, int target, int step);
}

extern "C" void _ZN5Fader13AdvanceInterpEv(char* self)
{
    int speed = *(int*)(self + 8);
    int target = speed >= 0 ? 0x1000 : 0;
    if (speed < 0)
        speed = -speed;
    func_0203ae58((int*)(self + 4), target, speed);
}
