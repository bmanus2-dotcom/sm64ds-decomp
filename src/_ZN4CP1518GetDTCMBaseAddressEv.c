unsigned int _ZN4CP1518GetDTCMBaseAddressEv(void){ asm { mrc p15,0,r0,c9,c1,0; ldr r1,=0xfffff000; and r0,r0,r1 } }
