//cpp
extern "C" void _ZN5Model17UpdateFileOffsetsER8BMD_File(char *c) {
  unsigned int i;
  int k;
  if (*(int *)(c + 8)) *(int *)(c + 8) += (int)c;
  for (i = 0; i < *(unsigned int *)(c + 4); i++) {
    char *b = *(char **)(c + 8) + i * 0x40;
    if (*(int *)(b + 4)) *(int *)(b + 4) += (int)c;
    if (*(int *)(b + 0x34)) *(int *)(b + 0x34) += (int)c;
    if (*(int *)(b + 0x38)) *(int *)(b + 0x38) += (int)c;
  }
  if (*(int *)(c + 0x10)) *(int *)(c + 0x10) += (int)c;
  for (i = 0; i < *(unsigned int *)(c + 0xc); i++) {
    char *m = *(char **)(c + 0x10) + i * 8;
    if (*(int *)(m + 4)) *(int *)(m + 4) += (int)c;
    for (k = 0; k < *(int *)m; k++) {
      char *t = *(char **)(m + 4) + k * 0x10;
      if (*(int *)(t + 4)) *(int *)(t + 4) += (int)c;
      if (*(int *)(t + 0xc)) *(int *)(t + 0xc) += (int)c;
    }
  }
  if (*(int *)(c + 0x18)) *(int *)(c + 0x18) += (int)c;
  for (i = 0; i < *(unsigned int *)(c + 0x14); i++) {
    char *e = *(char **)(c + 0x18) + i * 0x14;
    if (*(int *)e) *(int *)e += (int)c;
    if (*(int *)(e + 4)) *(int *)(e + 4) += (int)c;
  }
  if (*(int *)(c + 0x20)) *(int *)(c + 0x20) += (int)c;
  for (i = 0; i < *(unsigned int *)(c + 0x1c); i++) {
    char *e = *(char **)(c + 0x20) + i * 0x10;
    if (*(int *)e) *(int *)e += (int)c;
    if (*(int *)(e + 4)) *(int *)(e + 4) += (int)c;
  }
  if (*(int *)(c + 0x28)) *(int *)(c + 0x28) += (int)c;
  for (i = 0; i < *(unsigned int *)(c + 0x24); i++) {
    char *e = *(char **)(c + 0x28) + i * 0x30;
    if (*(int *)e) *(int *)e += (int)c;
  }
  if (*(int *)(c + 0x2c)) *(int *)(c + 0x2c) += (int)c;
  if (*(int *)(c + 0x30) == 0) return;
  if (*(int *)(c + 0x34)) *(int *)(c + 0x34) += (int)c;
  {
    char *e = *(char **)(c + 0x34);
    if (*(int *)e) *(int *)e += (int)c;
    if (*(int *)(e + 4)) *(int *)(e + 4) += (int)c;
    if (*(int *)(e + 8)) *(int *)(e + 8) += (int)c;
    if (*(int *)(e + 0xc)) *(int *)(e + 0xc) += (int)c;
  }
}
