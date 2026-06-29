extern void *_ZTV12CylinderClsn;
extern void *func_02014fa4(void *self);
extern void _ZN6Memory16operator_delete2EPv(void *ptr);

struct CylinderClsn {
    void *vtable;
};

void *_ZN12CylinderClsnD0Ev(struct CylinderClsn *self)
{
    self->vtable = &_ZTV12CylinderClsn;
    func_02014fa4(self);
    _ZN6Memory16operator_delete2EPv(self);
    return self;
}
