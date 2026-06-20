/* func_ov034_02112330 at 0x02112330
 *
 * Caches the closest player actor into the +0x8c8 field.
 */

extern void *_ZN5Actor13ClosestPlayerEv(void *actor);

void func_ov034_02112330(char *c)
{
    *(void **)(c + 0x8c8) = _ZN5Actor13ClosestPlayerEv(c);
}
