// NONMATCHING: div=2; 6v load-order/color weld; pure C replaces HAND-ASM
extern void func_ov007_020c6d20(void *c);
extern void func_ov007_020c28ac(void *p);

/* BEST_DIV=2 (regperm load-order floor)
 * All of function matches except the two ldrs for the first (c+8)/(c+0xc) compare:
 *   ROM:  ldr r1,[c+#8]; ldr r2,[c+#0xc]; cmp r1,r2; blt
 *   this: ldr r2,[c+#0xc]; ldr r1,[c+#8]; cmp r1,r2; blt
 * Volatile on the right-hand load selects r1/r2 correctly (statement-level pair
 * selector) but schedules that load ASAP, swapping order. Non-vol restores order
 * but flips the pair back (div=3). ~80 pure-C variants; documented wall in
 * notes/mwccarm-codegen.md §6v for this symbol.
 */
int func_ov007_020c6550(char *c)
{
    int status = 1;
    void *obj = *(void **)(c + 0x20);
    int right;
    if (*(unsigned short *)((char *)obj + 8) == 0 ||
        *(int *)(c + 8) >= (right = *(volatile int *)(c + 0xc))) {
        status = 0;
    } else {
        func_ov007_020c6d20(c);
        {
            int *p = (int *)(((unsigned int)c + 8) & 0xFFFFFFFFFFFFFFFFULL);
            *p = *p + 1;
        }
        if (*(int *)(c + 8) >= *(int *)(c + 0xc))
            status = 2;
        func_ov007_020c28ac(obj);
    }
    return status;
}
