// NONMATCHING: different op / idiom (div=7). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned int RENDER_DMA_CHANNEL;

extern void DMASyncWordTransfer(unsigned int channel, const void *src, void *dst, unsigned int count);
extern void MultiCopy_Int(const void *src, void *dst, unsigned int count);

void _ZN2GX7LoadOBJEPKvjj(const void *src, unsigned int offset, unsigned int count)
{
    unsigned int channel = RENDER_DMA_CHANNEL;
    if (channel != (unsigned int)-1) {
        DMASyncWordTransfer(channel, src, (void *)(0x6400000 + offset), count);
    } else {
        MultiCopy_Int(src, (void *)(0x6400000 + offset), count);
    }
}
