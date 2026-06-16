int func_ov004_020ae0a4(char *c) {
    char *p = *(char**)(c+4);
    if (p != 0) {
        void (*fn)(char*) = *(void(**)(char*))( (char*)(*(void**)p) + 0x58 );
        fn(p);
    }
    return 1;
}
