#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029EB74.h"
#include "types.h"


extern f32 func_802B72B0_de(f32);
void func_8029E4DC_de(Vec3 *arg0)
{
  f32 sum;
  sum = ((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (arg0->z * arg0->z);
  if (!((((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (arg0->z * arg0->z)) <= 0.0f))
  {
    sum = arg0->z;
    func_802B72B0_de(((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (sum * sum));
  }
}
