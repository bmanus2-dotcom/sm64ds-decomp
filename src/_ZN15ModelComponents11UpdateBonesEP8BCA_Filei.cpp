//cpp
struct BCA_File;
struct Inner15 { char pad[8]; void *f8; };
struct ModelComponents { struct Inner15 *inner; };
extern "C" void func_020453c0(struct ModelComponents *thiz, void *a, struct BCA_File *file, int i);
extern "C" void _ZN15ModelComponents11UpdateBonesEP8BCA_Filei(struct ModelComponents *thiz, struct BCA_File *file, int i);
extern "C" void _ZN15ModelComponents11UpdateBonesEP8BCA_Filei(struct ModelComponents *thiz, struct BCA_File *file, int i) {
    func_020453c0(thiz, thiz->inner->f8, file, i);
}
