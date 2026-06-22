//cpp
struct C; typedef void (C::*PMF)();
struct C { char pad[0x5004]; PMF m; };
extern "C" int func_ov006_020ee27c(C* c) { (c->*c->m)(); return 1; }
