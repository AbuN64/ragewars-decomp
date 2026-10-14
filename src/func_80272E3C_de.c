#include "span_1000/code_80271B18.h"
#include "types.h"




void func_80272E3C_de(f32 *m, f32 x, f32 y, f32 z)
{
  f32 zero;
  f32 ax = func_802B7130_de(x);
  f32 bx = func_802B6560_de(x);
  f32 ay = func_802B7130_de(y);
  f32 by = func_802B6560_de(y);
  int new_var;
  f32 az = func_802B7130_de(z);
  f32 bz = func_802B6560_de(z);
  new_var = 0;
  m[new_var] = by * bz;
  m[1] = by * az;
  m[2] = -ay;
  zero = 0.0f;
  m[14] = zero;
  m[13] = zero;
  m[12] = zero;
  m[11] = zero;
  m[7] = zero;
  m[3] = zero;
  m[4] = ((ax * ay) * bz) - (bx * az);
  m[5] = ((ax * ay) * az) + (bx * bz);
  m[6] = ax * by;
  m[8] = ((bx * ay) * bz) + (ax * az);
  m[9] = ((bx * ay) * az) - (ax * bz);
  m[10] = bx * by;
  m[15] = D_800C48DC_de;
}
