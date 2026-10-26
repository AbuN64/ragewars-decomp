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

f32 XMath_SubtractAnglesCentered(f32 a, f32 b) { return centered(a - b); }

/** Clear a three-component floating-point vector. */
void Vector3Zero(float *vector) {
    vector[0] = vector[1] = vector[2] = 0.0f;
}

void Vector3Set(void *destination, float xValue, float yValue, float zValue) {
    CVector3 *vector = destination;
    vector->x = xValue;
    vector->y = yValue;
    vector->z = zValue;
}

/** Split a three-float vector into three destinations. */
void Vector3Unpack(float *source, float *xOut, float *yOut, float *zOut) {
    *xOut = source[0];
    *yOut = source[1];
    *zOut = source[2];
}

void Vector3Copy(Triple *destination, Triple *source) {
    *destination = *source;
}

void Vector3Add(void *destination, void *leftVector, void *rightVector) {
    (((struct CVector3_t *) ((s8 *) destination))->x) = (f32) ((((struct CVector3_t *) ((s8 *) leftVector))->x) + (((struct CVector3_t *) ((s8 *) rightVector))->x));
    (((struct CVector3_t *) ((s8 *) destination))->y) = (f32) ((((struct CVector3_t *) ((s8 *) leftVector))->y) + (((struct CVector3_t *) ((s8 *) rightVector))->y));
    (((struct CVector3_t *) ((s8 *) destination))->z) = (f32) ((((struct CVector3_t *) ((s8 *) leftVector))->z) + (((struct CVector3_t *) ((s8 *) rightVector))->z));
}

void Vector3Subtract(void *destination, void *leftVector, void *rightVector) {
    (((struct CVector3_t *) ((s8 *) destination))->x) = (f32) ((((struct CVector3_t *) ((s8 *) leftVector))->x) - (((struct CVector3_t *) ((s8 *) rightVector))->x));
    (((struct CVector3_t *) ((s8 *) destination))->y) = (f32) ((((struct CVector3_t *) ((s8 *) leftVector))->y) - (((struct CVector3_t *) ((s8 *) rightVector))->y));
    (((struct CVector3_t *) ((s8 *) destination))->z) = (f32) ((((struct CVector3_t *) ((s8 *) leftVector))->z) - (((struct CVector3_t *) ((s8 *) rightVector))->z));
}

/** Scale a 3-vector (arg1) by a scalar (arg2), store into arg0. */
void Vector3Scale(void *destination, void *source, f32 scaleFactor) {
    CVector3 *arg1_record = source;
    CVector3 *arg0_record = destination;
    arg0_record->x = arg1_record->x * scaleFactor;
    arg0_record->y = arg1_record->y * scaleFactor;
    arg0_record->z = arg1_record->z * scaleFactor;
}

void Vector3Negate(void *destination, void *source) {
    (((struct CVector3_t *) ((s8 *) destination))->x) = (f32) -(((struct CVector3_t *) ((s8 *) source))->x);
    (((struct CVector3_t *) ((s8 *) destination))->y) = (f32) -(((struct CVector3_t *) ((s8 *) source))->y);
    (((struct CVector3_t *) ((s8 *) destination))->z) = (f32) -(((struct CVector3_t *) ((s8 *) source))->z);
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

void XMath_EvaluateVectorLength(CVector3 *arg0)
{
  f32 sum;
  sum = ((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (arg0->z * arg0->z);
  if (!((((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (arg0->z * arg0->z)) <= 0.0f))
  {
    sum = arg0->z;
    Math_Sqrtf(((arg0->x * arg0->x) + (arg0->y * arg0->y)) + (sum * sum));
  }
}

void Vector3Normalize(f32 *vector) {
    f32 mag;
    f32 scale;

    mag = safe_sqrt((vector[0] * vector[0]) + (vector[1] * vector[1]) + (vector[2] * vector[2]));
    scale = D_800C5CA4_de / mag;
    vector[0] = vector[0] * scale;
    vector[1] = vector[1] * scale;
    vector[2] = vector[2] * scale;
}

void Vector3RotatePitch(CVector3 *destination, CVector3 *source, f32 arg2) {
    CVector3 tmp;
    f32 sp20;
    f32 sp24;

    XMath_EvaluateSineCosine(arg2, &sp20, &sp24);
    tmp.x = source->x;
    tmp.y = (sp24 * source->y) - (sp20 * source->z);
    tmp.z = (sp24 * source->z) + (sp20 * source->y);
    *destination = tmp;
}

void Vector3RotateYaw(CVector3 *destination, CVector3 *source, f32 arg2) {
    CVector3 tmp;
    f32 sp20;
    f32 sp24;

    XMath_EvaluateSineCosine(arg2, &sp20, &sp24);
    tmp.x = (sp24 * source->x) + (sp20 * source->z);
    tmp.y = source->y;
    tmp.z = (sp24 * source->z) - (sp20 * source->x);
    *destination = tmp;
}

void Vector3RotateRoll(CVector3 *destination, CVector3 *source, f32 arg2) {
    CVector3 tmp;
    f32 sp20;
    f32 sp24;

    XMath_EvaluateSineCosine(arg2, &sp20, &sp24);
    tmp.x = (sp24 * source->x) - (sp20 * source->y);
    tmp.y = (sp24 * source->y) + (sp20 * source->x);
    tmp.z = source->z;
    *destination = tmp;
}

void Vector3Angles(f32 *vector, f32 *pitchOut, f32 *yawOut) {
    f32 magnitude_squared;
    f32 magnitude;
    f32 x;
    f32 z;

    x = vector[0];
    z = vector[2];
    x *= x;
    z *= z;
    x += z;
    magnitude_squared = x;
    if (magnitude_squared <= 0.0f) {
        magnitude = 0.0f;
    } else {
        magnitude = Math_Sqrtf(magnitude_squared);
    }
    *yawOut = XMath_EvaluateArcTangentTwo(vector[0], vector[2]);
    *pitchOut = -XMath_EvaluateArcTangentTwo(vector[1], magnitude);
}

void Vector3AnglesInverse(f32 *vector, f32 *pitchOut, f32 *yawOut) {
    f32 magnitude_squared;
    f32 magnitude;
    f32 x;
    f32 z;

    x = vector[0];
    z = vector[2];
    x *= x;
    z *= z;
    x += z;
    magnitude_squared = x;
    if (magnitude_squared <= 0.0f) {
        magnitude = 0.0f;
    } else {
        magnitude = Math_Sqrtf(magnitude_squared);
    }
    *yawOut = XMath_EvaluateArcTangentTwo(vector[0], vector[2]);
    *pitchOut = XMath_EvaluateArcTangentTwo(vector[1], magnitude);
    *yawOut = -*yawOut;
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

void Vector3IntersectPlane(CVector3 *intersectionOut, CVector3 *lineStart, CVector3 *lineEnd, f32 normalX, f32 normalY, f32 normalZ, f32 planeOffset) {
    CVector3 delta;
    f32 numerator;
    f32 denominator;
    f32 fraction;

    delta.x = lineEnd->x - lineStart->x;
    delta.y = lineEnd->y - lineStart->y;
    delta.z = lineEnd->z - lineStart->z;
    numerator = -((normalX * lineStart->x) + (normalY * lineStart->y) + (normalZ * lineStart->z) + planeOffset);
    denominator = (normalX * delta.x) + (normalY * delta.y) + (normalZ * delta.z);
    if (!(denominator < D_800C5CAC_de) || (fraction = D_800C5CB4_de, !(D_800C5CB0_de < denominator))) {
        fraction = numerator / denominator;
    }
    intersectionOut->x = lineStart->x + (fraction * delta.x);
    intersectionOut->y = lineStart->y + (fraction * delta.y);
    intersectionOut->z = lineStart->z + (fraction * delta.z);
}

void XMath_CopyMatrix(void *arg0, void *arg1) {
    char *dst = (char *)arg0;
    char *src = (char *)arg1;
    char *end = src + 0x40;
    do {
        *(struct Shape_typemap_165 *)dst = *(struct Shape_typemap_165 *)src;
        src += 0x10;
        dst += 0x10;
    } while (src != end);
}
