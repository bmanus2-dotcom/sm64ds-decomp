/* _ZN21ExtendingMeshColliderC1Ev at 0x02014878
 * CylinderClsnWithPos C1 (complete object) constructor:
 *   call base CylinderClsn::CylinderClsn() (C2), then set own vtable.
 */
struct Obj { void *vtable; };
extern void *_ZTV19CylinderClsnWithPos[];
extern void func_0203a4b8(struct Obj *thiz); /* 0x020150cc */

struct Obj *_ZN21ExtendingMeshColliderC1Ev(struct Obj *thiz)
{
    func_0203a4b8(thiz);
    thiz->vtable = (void *)_ZTV19CylinderClsnWithPos;
    return thiz;
}
