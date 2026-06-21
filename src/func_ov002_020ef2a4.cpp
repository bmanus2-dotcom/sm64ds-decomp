//cpp
extern "C" {
extern int _ZNK12WithMeshClsn10IsOnGroundEv(void* self);
extern void* _ZNK12WithMeshClsn14GetFloorResultEv(void* self);
extern int _ZNK10ClsnResult9GetClsnIDEv(void* self);
extern void* _ZN5Actor10FindWithIDEj(unsigned int id);
int func_ov002_020ef2a4(void* self, void* arg){
  void* fr;
  void* actor;
  if(_ZNK12WithMeshClsn10IsOnGroundEv(self)){
    fr=_ZNK12WithMeshClsn14GetFloorResultEv(self);
    if(_ZNK10ClsnResult9GetClsnIDEv(fr)!=-1){
      actor=_ZN5Actor10FindWithIDEj(_ZNK10ClsnResult9GetClsnIDEv(fr));
      if(actor){
        (*(void(***)(void*,void*))actor)[0x54/4](actor,arg);
        return 1;
      }
    }
  }
  return 0;
}
}
