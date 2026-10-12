#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8027302C.h"
#include "types.h"



extern f32 D_800C48F8_de[];



void func_802736D4_de(void *arg0, f32 arg1)
{
  struct Mtx *m = (char *) arg0;
  f32 sin_v;
  f32 cos_v;
  f32 zero;
  f32 identity;
  zero = 0;
  sin_v = func_802B7130_de(arg1);
  identity = D_800C48F8_de[1];
  m->forward.x = sin_v;
  m->right.y = zero;
  m->right.z = -sin_v;
  m->up.x = zero;
  m->up.z = zero;
  m->forward.y = zero;
  m->m32 = zero;
  m->m31 = zero;
  m->m30 = zero;
  m->m23 = zero;
  m->m13 = zero;
  m->m03 = zero;
  m->m33 = identity;
  m->up.y = identity;
  cos_v = func_802B6560_de(arg1);
  m->forward.z = cos_v;
  m->right.x = cos_v;
}
