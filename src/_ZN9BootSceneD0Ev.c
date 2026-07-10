/* _ZN9BootSceneD0Ev (deleting / D0) at 0x020235d4
 *
 * This is the BootScene flavor of the Scene deleting dtor; vtable chain
 * (from the literal pool) is BootScene -> Scene -> ActorDerived:
 *   0x02091528 = _ZTV9BootScene
 *   0x02092680 = _ZTV5Scene
 *   0x0208e4b8 = _ZTV12ActorDerived
 *   bl 0x02043d48 = ActorBase::~ActorBase
 *   bl 0x0203c1e8 = Memory::Deallocate(this, *gameHeapPtr)
 *   return this;
 */

struct Scene { void **vtable; /* 0x0 */ };
struct Heap;

extern void *_ZTV9BootScene[];
extern void *_ZTV5Scene[];
extern void *_ZTV12ActorDerived[];

extern void _ZN9ActorBaseD1Ev(struct Scene *self);              /* 0x02043d48 */
extern void _ZN6Memory10DeallocateEPvP4Heap(void *ptr, struct Heap *heap); /* 0x0203c1e8 */
extern struct Heap *_ZN6Memory11gameHeapPtrE;                   /* 0x020a0eac */

struct Scene *_ZN9BootSceneD0Ev(struct Scene *self)
{
    self->vtable = (void **)_ZTV9BootScene;
    self->vtable = (void **)_ZTV5Scene;
    self->vtable = (void **)_ZTV12ActorDerived;
    _ZN9ActorBaseD1Ev(self);
    _ZN6Memory10DeallocateEPvP4Heap(self, _ZN6Memory11gameHeapPtrE);
    return self;
}
