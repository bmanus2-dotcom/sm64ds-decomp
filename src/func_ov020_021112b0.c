// NONMATCHING: extra logic (you do more) (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

struct Vec3
{
  int x;
  int y;
  int z;
};
extern char *Actor_ClosestPlayer(void *);
extern void Vec3_Sub(struct Vec3 *d, struct Vec3 *a, struct Vec3 *b);
extern short cstd_atan2(int, int);
extern int Vec3_HorzLen(struct Vec3 *);
void func_ov020_021112b0(char *c)
{
  char *new_var;
  char *p = Actor_ClosestPlayer(c);
  new_var = p + 0x5c;
  if (!p)
  {
    return;
  }
  struct Vec3 *ps = (struct Vec3 *) new_var;
  struct Vec3 tmp;
  tmp.x = ps->x;
  tmp.y = ps->y;
  tmp.z = ps->z;
  struct Vec3 d;
  Vec3_Sub(&d, &tmp, (struct Vec3 *) (c + 0x5c));
  *((short *) (c + 0x446)) = cstd_atan2(d.x, d.z);
  *((short *) (c + 0x444)) = cstd_atan2(d.y, Vec3_HorzLen(&d));
  *((short *) (c + 0x448)) = 0x4000;
}
