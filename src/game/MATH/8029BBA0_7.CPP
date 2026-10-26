#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "MATH/DOUBLEBITS.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/TRIPLE.H"
#include "MATH/math_double.H"
#include "MATH/8029BBA0_7.H"

/* Normalizes an offset angle, using double remainder for large magnitudes and repeated single-precision adjustments otherwise. */







inline static f32 wrap(f32 arg0)
{
  f32 new_var3;
  f32 value;
  f32 *new_var;
  f32 new_var2;
  value = arg0;
  new_var2 = value;
  if (1)
  {
    if (((long long) (D_800C5C88_de < new_var2)) || (new_var2 < D_800C5C8C))
    {
      value = (f32) FloatModulo((f64) value, D_800C5C90_de);
    }
    else
    {
      if (D_800C5C98_de[0] < value)
      {
        new_var3 = D_800C5C98_de[0];
        do
        {
          value -= new_var3;
          if (1)
          {
          }
        }
        while (new_var3 < value);
      }
      if (value < 0.0f)
      {
        do
        {
          new_var = D_800C5C98_de;
          value += new_var[1];
        }
        while (value < (new_var3 = 0.0f));
      }
    }
  }
  return value;
}


static inline f32 centered(f32 x)
{
  f32 new_var;
  float new_var3;
  f32 new_var2;
  new_var = D_800C5C84;
  new_var2 = x + new_var;
  {
    new_var3 = new_var2;
  }
  new_var2 = wrap(new_var3);
  return new_var2 - D_800CAE30;
}



static inline f32 safe_sqrt(f32 x) {
    if (x <= 0.0f) {
        return 0.0f;
    }
    return Math_Sqrtf(x);
}

f32 func_8029E1D4_de(f32 a, f32 b) { return centered(a - b); }

/** Clear a three-component floating-point vector. */
void Vector3Zero(float *vector) {
    vector[0] = vector[1] = vector[2] = 0.0f;
}

void Vector3Set(void *arg0, float arg1, float arg2, float arg3) {
    CVector3 *vector = arg0;
    vector->x = arg1;
    vector->y = arg2;
    vector->z = arg3;
}

/** Split a three-float vector into three destinations. */
void Vector3Unpack(float *arg0, float *arg1, float *arg2, float *arg3) {
    *arg1 = arg0[0];
    *arg2 = arg0[1];
    *arg3 = arg0[2];
}

void Vector3Copy(Triple *arg0, Triple *arg1) {
    *arg0 = *arg1;
}

void Vector3Add(void *arg0, void *arg1, void *arg2) {
    (((struct CVector3_t *) ((s8 *) arg0))->x) = (f32) ((((struct CVector3_t *) ((s8 *) arg1))->x) + (((struct CVector3_t *) ((s8 *) arg2))->x));
    (((struct CVector3_t *) ((s8 *) arg0))->y) = (f32) ((((struct CVector3_t *) ((s8 *) arg1))->y) + (((struct CVector3_t *) ((s8 *) arg2))->y));
    (((struct CVector3_t *) ((s8 *) arg0))->z) = (f32) ((((struct CVector3_t *) ((s8 *) arg1))->z) + (((struct CVector3_t *) ((s8 *) arg2))->z));
}

void Vector3Subtract(void *arg0, void *arg1, void *arg2) {
    (((struct CVector3_t *) ((s8 *) arg0))->x) = (f32) ((((struct CVector3_t *) ((s8 *) arg1))->x) - (((struct CVector3_t *) ((s8 *) arg2))->x));
    (((struct CVector3_t *) ((s8 *) arg0))->y) = (f32) ((((struct CVector3_t *) ((s8 *) arg1))->y) - (((struct CVector3_t *) ((s8 *) arg2))->y));
    (((struct CVector3_t *) ((s8 *) arg0))->z) = (f32) ((((struct CVector3_t *) ((s8 *) arg1))->z) - (((struct CVector3_t *) ((s8 *) arg2))->z));
}

/** Scale a 3-vector (arg1) by a scalar (arg2), store into arg0. */
void Vector3Scale(void *arg0, void *arg1, f32 arg2) {
    CVector3 *arg1_record = arg1;
    CVector3 *arg0_record = arg0;
    arg0_record->x = arg1_record->x * arg2;
    arg0_record->y = arg1_record->y * arg2;
    arg0_record->z = arg1_record->z * arg2;
}

void Vector3Negate(void *arg0, void *arg1) {
    (((struct CVector3_t *) ((s8 *) arg0))->x) = (f32) -(((struct CVector3_t *) ((s8 *) arg1))->x);
    (((struct CVector3_t *) ((s8 *) arg0))->y) = (f32) -(((struct CVector3_t *) ((s8 *) arg1))->y);
    (((struct CVector3_t *) ((s8 *) arg0))->z) = (f32) -(((struct CVector3_t *) ((s8 *) arg1))->z);
}

void Vector3Distance(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    f32 sum;

    sum = ((dx * dx) + (dy * dy)) + (dz * dz);
    if (!(((dx * dx) + (dy * dy)) + (dz * dz) <= 0.0f)) {
        sum = dz;
        Math_Sqrtf(((dx * dx) + (dy * dy)) + (sum * sum));
    }
}

f32 Vector3Dot(f32 *a, f32 *b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

/** Cross product of two vectors, written through a local temp to allow aliasing with out. */
void Vector3Cross(CVector3 *out, CVector3 *a, CVector3 *b) {
    CVector3 tmp;

    tmp.x = (a->y * b->z) - (a->z * b->y);
    tmp.y = (a->z * b->x) - (a->x * b->z);
    tmp.z = (a->x * b->y) - (a->y * b->x);
    *out = tmp;
}

void func_8029E4DC_de(CVector3 *arg0)
{
  f32 sum;
  sum = ((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (arg0->z * arg0->z);
  if (!((((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (arg0->z * arg0->z)) <= 0.0f))
  {
    sum = arg0->z;
    Math_Sqrtf(((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (sum * sum));
  }
}

void Vector3Normalize(f32 *arg0) {
    f32 mag;
    f32 scale;

    mag = safe_sqrt((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]));
    scale = D_800C5CA4_de / mag;
    arg0[0] = arg0[0] * scale;
    arg0[1] = arg0[1] * scale;
    arg0[2] = arg0[2] * scale;
}

void Vector3RotatePitch(CVector3 *arg0, CVector3 *arg1, f32 arg2) {
    CVector3 tmp;
    f32 sp20;
    f32 sp24;

    XMath_EvaluateSineCosine(arg2, &sp20, &sp24);
    tmp.x = arg1->x;
    tmp.y = (sp24 * arg1->y) - (sp20 * arg1->z);
    tmp.z = (sp24 * arg1->z) + (sp20 * arg1->y);
    *arg0 = tmp;
}

void Vector3RotateYaw(CVector3 *arg0, CVector3 *arg1, f32 arg2) {
    CVector3 tmp;
    f32 sp20;
    f32 sp24;

    XMath_EvaluateSineCosine(arg2, &sp20, &sp24);
    tmp.x = (sp24 * arg1->x) + (sp20 * arg1->z);
    tmp.y = arg1->y;
    tmp.z = (sp24 * arg1->z) - (sp20 * arg1->x);
    *arg0 = tmp;
}

void Vector3RotateRoll(CVector3 *arg0, CVector3 *arg1, f32 arg2) {
    CVector3 tmp;
    f32 sp20;
    f32 sp24;

    XMath_EvaluateSineCosine(arg2, &sp20, &sp24);
    tmp.x = (sp24 * arg1->x) - (sp20 * arg1->y);
    tmp.y = (sp24 * arg1->y) + (sp20 * arg1->x);
    tmp.z = arg1->z;
    *arg0 = tmp;
}

void Vector3Angles(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 magnitude_squared;
    f32 magnitude;
    f32 x;
    f32 z;

    x = arg0[0];
    z = arg0[2];
    x *= x;
    z *= z;
    x += z;
    magnitude_squared = x;
    if (magnitude_squared <= 0.0f) {
        magnitude = 0.0f;
    } else {
        magnitude = Math_Sqrtf(magnitude_squared);
    }
    *arg2 = XMath_EvaluateArcTangentTwo(arg0[0], arg0[2]);
    *arg1 = -XMath_EvaluateArcTangentTwo(arg0[1], magnitude);
}

void Vector3AnglesInverse(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 magnitude_squared;
    f32 magnitude;
    f32 x;
    f32 z;

    x = arg0[0];
    z = arg0[2];
    x *= x;
    z *= z;
    x += z;
    magnitude_squared = x;
    if (magnitude_squared <= 0.0f) {
        magnitude = 0.0f;
    } else {
        magnitude = Math_Sqrtf(magnitude_squared);
    }
    *arg2 = XMath_EvaluateArcTangentTwo(arg0[0], arg0[2]);
    *arg1 = XMath_EvaluateArcTangentTwo(arg0[1], magnitude);
    *arg2 = -*arg2;
}

/* Projects n vectors onto the screen plane: each one with depth above 0.01 becomes (ox + sx * x / z, oy + sy * y / z, z), and any other becomes zero. */



void Vector3ProjectArray(CVector3 *out, CVector3 *in, s32 n, f32 ox, f32 sx, f32 oy, f32 sy) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (in[i].z > 0.01f) {
            out[i].x = ox + sx * (in[i].x / in[i].z);
            out[i].y = oy + sy * (in[i].y / in[i].z);
            out[i].z = in[i].z;
        } else {
            out[i].x = 0.0f;
            out[i].y = 0.0f;
            out[i].z = 0.0f;
        }
    }
}

void Vector3IntersectPlane(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    CVector3 delta;
    f32 numerator;
    f32 denominator;
    f32 fraction;

    delta.x = arg2->x - arg1->x;
    delta.y = arg2->y - arg1->y;
    delta.z = arg2->z - arg1->z;
    numerator = -((arg3 * arg1->x) + (arg4 * arg1->y) + (arg5 * arg1->z) + arg6);
    denominator = (arg3 * delta.x) + (arg4 * delta.y) + (arg5 * delta.z);
    if (!(denominator < D_800C5CAC_de) || (fraction = D_800C5CB4_de, !(D_800C5CB0_de < denominator))) {
        fraction = numerator / denominator;
    }
    arg0->x = arg1->x + (fraction * delta.x);
    arg0->y = arg1->y + (fraction * delta.y);
    arg0->z = arg1->z + (fraction * delta.z);
}

void func_8029EA44_de(void *arg0, void *arg1) {
    char *dst = (char *)arg0;
    char *src = (char *)arg1;
    char *end = src + 0x40;
    do {
        *(struct Shape_typemap_165 *)dst = *(struct Shape_typemap_165 *)src;
        src += 0x10;
        dst += 0x10;
    } while (src != end);
}
