/* _ZN18MovingMeshColliderC1Ev at 0x02014878
 * CylinderClsnWithPos C1 (complete object) constructor:
 *   call base CylinderClsn::CylinderClsn() (C2), then set own vtable.
 */
struct Obj { void *vtable; };
extern void *_ZTV19CylinderClsnWithPos[];
extern void func_020398c8(struct Obj *thiz); /* 0x020150cc */

struct Obj *_ZN18MovingMeshColliderC1Ev(struct Obj *thiz)
{
    func_020398c8(thiz);
    thiz->vtable = (void *)_ZTV19CylinderClsnWithPos;
    return thiz;
}
