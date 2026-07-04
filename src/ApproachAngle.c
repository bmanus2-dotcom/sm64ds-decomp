//cpp
// NONMATCHING: register allocation (div=31). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" int __aeabi_idiv(int a, int b);

extern "C" int ApproachAngle(short &cur, short target, int divisor, int band, int maxStep) {
    short diff = (short)(target - cur);
    if (cur != target) {
        int step = (short)(__aeabi_idiv(diff, divisor));
        if (step > maxStep || step < -maxStep) {
            if (step > band) step = band;
            else if (step < -band) step = (short)-band;
            cur = (short)(cur + step);
        } else if (diff >= 0) {
            cur = (short)(cur + maxStep);
            if ((short)(target - cur) <= 0) cur = target;
        } else {
            cur = (short)(cur - maxStep);
            if ((short)(target - cur) >= 0) cur = target;
        }
    }
    return target - cur;
}
