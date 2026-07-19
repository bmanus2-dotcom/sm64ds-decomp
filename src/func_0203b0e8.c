int AngleDiff(int a, int b) {
    return ((a - b) << 16 >> 16) < 0 ? -((a - b) << 16 >> 16) : ((a - b) << 16 >> 16);
}
