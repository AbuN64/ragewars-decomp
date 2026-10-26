#include "COMMON/PACKED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "AI/EXTERNS.H"
#include "COMMON/OBJB.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"
#include "sdk/lib_802BB630/802BBC50.H"
extern u32 D_80111D28;
extern f32 D_800C4960_de[2];

extern f32 D_800D2988;






/* Builds a look-at view matrix (ultralib guLookAtF) from an eye, a target and an up vector,
   substituting a fallback x component when the up vector is parallel to the view direction.
   Adapted from ultralib gu/lookat.c with single-precision const extern constants, the degenerate check and the 1.0 held in a temporary. */



extern float Math_Sqrtf(float);

/* Returns the normalised cross product of a path node's two edge vectors, cached in D_80115E00 for the last node seen, with a default up vector for a null node. Adapted from Region_GetCachedCeilingNormal, which it inlines to compute the raw cross product, with the result normalised through func_8027207C_de and cached by a second last-node word; the inlined copy records its last node before copying its result. */






extern void GraphU64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);


static inline CVector3 *cross_edges(CVector3 *out, Node75 *node) {
    CVector3 a;
    CVector3 b;
    char *p;
    char *q;

    if (node == 0) {
        D_80111D30.x = 0;
        D_80111D30.z = 0;
        D_80111D30.y = D_800C49C4_de;
    } else if ((int)node != D_800CD3E0) {
        p = node->cur;
        q = node->prev;
        a.x = ((CollisionBuildVertex *)p)->x - ((CollisionBuildVertex *)q)->x;
        p = node->cur;
        q = node->prev;
        a.y = ((CollisionBuildVertex *)p)->ceiling - ((CollisionBuildVertex *)q)->ceiling;
        p = node->cur;
        q = node->prev;
        a.z = ((CollisionBuildVertex *)p)->z - ((CollisionBuildVertex *)q)->z;
        p = node->next;
        q = node->cur;
        b.x = ((CollisionBuildVertex *)p)->x - ((CollisionBuildVertex *)q)->x;
        p = node->next;
        q = node->cur;
        b.y = ((CollisionBuildVertex *)p)->ceiling - ((CollisionBuildVertex *)q)->ceiling;
        p = node->next;
        q = node->cur;
        b.z = ((CollisionBuildVertex *)p)->z - ((CollisionBuildVertex *)q)->z;
        GraphU64_CrossVectors(&D_80111D30, &b, &a);
    }
    D_800CD3E0 = (int)node;
    *out = D_80111D30;
    return out;
}

/** Perform the no-op callback at VRAM 0x8027451C. */
void GraphU64_ReturnWithoutWork(void) {
}

/** Store a fill pattern into two paired global words. */
void GraphU64_ResetRandomSeeds(void) {
    D_80111D24 = 0xE3F635E3;
    D_80111D28 = 0xE3F635E3;
}

s32 GraphU64_NextRandom(void) {
    u32 seed;

    seed = (D_80111D24 * 0xA84A5B53) + 0x58348C2D;
    D_80111D24 = seed;
    return ((seed << 0x10) | (seed >> 0x10)) & 0x7FFFFFFF;
}

s32 GraphU64_NextRandomValue(void) {
    u32 seed;

    seed = (D_80111D28 * 0xA84A5B53) + 0x58348C2D;
    D_80111D28 = seed;
    return ((seed << 0x10) | (seed >> 0x10)) & 0x7FFFFFFF;
}

/** LCG PRNG step scaled into [0, arg0 * D_800C9A38) as a float. */
f32 GraphU64_RandomFloat(f32 range) {
    f64 value;
    s32 randomBits;
    u32 seed;

    seed = (D_80111D24 * 0xA84A5B53) + 0x58348C2D;
    randomBits = (s32)((seed >> 0x10) & 0x7FFF);
    value = (f64)randomBits;
    D_80111D24 = seed;
    if (randomBits < 0) {
        value = value + D_800C4940_de;
    }
    return (f32)value * range * D_800C9A38;
}

f32 GraphU64_ArcCos(f32 cosineValue) {
    f32 tableCoordinate;
    f32 interpolatedAngle;
    f32 lowerSample;
    s32 sampleIndex;
    s32 negativeInput;

    negativeInput = 1;
    if (cosineValue < 0.0f) {
        tableCoordinate = cosineValue * D_800C494C_de;
    } else {
        tableCoordinate = cosineValue * D_800C4950_de;
        negativeInput = 0;
    }
    sampleIndex = (s32) tableCoordinate;
    if ((f32) sampleIndex < D_800C4954_de) {
        lowerSample = D_800CC3DC[sampleIndex];
        interpolatedAngle = lowerSample + ((tableCoordinate - (f32) sampleIndex) * (D_800CC3E0[sampleIndex] - lowerSample));
        if (negativeInput != 0) {
            return D_800C4958_de - interpolatedAngle;
        }
        return interpolatedAngle;
    }
    if (negativeInput != 0) {
        tableCoordinate = D_800CD3D8;
        return D_800C495C_de - tableCoordinate;
    }
    return D_800CD3D8;
}

f32 GraphU64_IntegrateBoundedValue(f32 value, f32 velocity, f32 limit) {
    if (velocity < 0.0f) {
        if (value <= -limit) {
            return value;
        }
    }
    if (0.0f < velocity) {
        if (limit <= value) {
            return value;
        }
    }
    if ((value < 0.0f && 0.0f < velocity) ||
        (0.0f < value && velocity < 0.0f)) {
        velocity *= D_800C4960_de[0];
    }
    value += velocity * D_800D2988;
    if (velocity < 0.0f) {
        if (value < -limit) {
            value = -limit;
        }
    } else if (limit < value) {
        value = limit;
    }
    return value;
}

f32 GraphU64_DecayToZero(f32 value, f32 rate) {
    f32 zero;

    zero = 0.0f;
    if (zero < value) {
        value -= rate * D_800D2988;
        if (value < zero) {
            value = zero;
        }
    } else if (value < zero) {
        value += rate * D_800D2988;
        if (zero < value) {
            value = zero;
        }
    }
    return value;
}

f32 GraphU64_ApproachValue(f32 current, f32 target, f32 rate) {
    f32 value;
    value = current;
    if (value < target) {
        value += rate * D_800D2988;
        if (target < value) {
            value = target;
        }
    }
    else if (target < value) {
        value -= rate * D_800D2988;
        if (value < target) {
            value = target;
        }
    }
    return value;
}

void GraphU64_EaseValueToward(f32 *value, f32 target, f32 rate) {
    f32 current;
    f32 next;

    current = *value;
    next = (target - current) * rate * D_800D2988;
    if (rate == D_800C4960_de[1]) {
        *value = target;
    } else if (current < target) {
        *value += next;
        if (target < *value) {
            *value = target;
        }
    } else if (target < current) {
        *value += next;
        if (*value < target) {
            *value = target;
        }
    }
}

s32 GraphU64_IntegrateBoundedInteger(s32 arg0, s32 arg1, s32 arg2)
{
  f32 temp_f1;
  s32 var_a0;
  s32 var_a2;
  s32 var_v0;
  var_a2 = arg2;
  temp_f1 = (f32) arg1;
  var_a0 = arg0 + ((s32) (temp_f1 * D_800D2988));
  if (temp_f1 < 0.0f)
  {
    var_a2 = -var_a2;
    var_v0 = var_a0 < var_a2;
  }
  else
  {
    var_v0 = var_a2 < var_a0;
  }
  if (var_v0 != 0)
  {
    var_a2 = var_a2;
    var_a0 = var_a2;
  }
  if (var_a2)
  {
    return var_a0;
  }
  else
  {
    return var_a0;
  }
}

f32 GraphU64_NegateWrappedValue(f32 arg0)
{
  unsigned char new_var;
  f32 val;
  val = arg0;
  new_var = 0;
  if (val < D_800C4968_de[new_var])
  {
    do
    {
      val += D_800C4968_de[1];
    }
    while (val < D_800C4968_de[new_var]);
  }
  if (D_800C4970_de[new_var] < val)
  {
    do
    {
      val -= D_800C4970_de[1];
    }
    while (D_800C4970_de[new_var] < val);
  }
  return -val;
}

f32 GraphU64_GetNegatedWrappedDifference(f32 angleA, f32 angleB) {
    f32 difference;
    f32 wrappedB;

    wrappedB = angleB;
    if (wrappedB < D_800C4978_de) {
        do {
            wrappedB += *(&D_800C4978_de + 1);
        } while (wrappedB < D_800C4978_de);
    }
    if (D_800C4980_de < wrappedB) {
        do {
            wrappedB -= *(&D_800C4980_de + 1);
        } while (D_800C4980_de < wrappedB);
    }
    difference = angleA - wrappedB;
    if (difference < D_800C4988_de) {
        do {
            difference += *(&D_800C4988_de + 1);
        } while (difference < D_800C4988_de);
    }
    if (D_800C4990_de < difference) {
        do {
            difference -= *(&D_800C4990_de + 1);
        } while (D_800C4990_de < difference);
    }
    return -difference;
}

f32 GraphU64_RandomBetween(f32 shakeMin, f32 shakeMax) {
    f32 blend;
    u32 seed;
    s32 randomValue;

    seed = (D_80111D24 * 0xA84A5B53) + 0x58348C2D;
    randomValue = ((seed << 0x10) | (seed >> 0x10)) & 0x7FFFFFFF;
    randomValue = randomValue % 10000;
    blend = (f32)randomValue * D_800C4998_de;
    D_80111D24 = seed;
    return (blend * shakeMin) + ((D_800C499C_de - blend) * shakeMax);
}

s32 GraphU64_UpdateCountdown(f32 *arg0)
{
  f32 *new_var2;
  float new_var3;
  f32 *new_var;
  f32 temp_f0;
  temp_f0 = (*arg0) - D_800D2988;
  *arg0 = temp_f0;
  new_var = arg0;
  new_var2 = new_var;
  new_var3 = 0.0f;
  if ((temp_f0 <= 0.0f) == 0)
  {
    if (D_800D2988)
    {
      temp_f0 = 0;
      return temp_f0;
    }
    else
    {
      temp_f0 = 0;
      return temp_f0;
    }
  }
  *new_var2 = new_var3;
  return 1;
}

/** Copy two 3-vectors, then derive an edge vector, its z-component twice, and a negated x. */
void GraphU64_InitializeEdge(void *geometryEdge, void *arg1, void *arg2) {
    GeometryEdge *dst = geometryEdge;
    CVector3 *a = arg1;
    CVector3 *b = arg2;
    f32 zdiff;

    dst->start = *a;
    dst->end = *b;
    dst->direction.x = b->x - a->x;
    dst->direction.y = b->y - a->y;
    zdiff = b->z - a->z;
    dst->normal.y = 0.0f;
    dst->normal.z = -dst->direction.x;
    dst->direction.z = zdiff;
    dst->normal.x = zdiff;
}

void GraphU64_NormalizeEdgeHorizontal(void *arg0)
{
    ObjRecAt2CV1 *o = arg0;
    f32 magSq;
    f32 mag;
    f32 zOut;

    magSq = (o->unk18 * o->unk18) +
            (o->unk20 * o->unk20);
    zOut = 0.0f;
    if (magSq != 0.0f) {
        mag = Math_Sqrtf(magSq);
        magSq = *(f32 *)&D_800C49A0_de / mag;
        o->unk24 = o->unk18 * magSq;
        o->unk28 = o->unk1C * magSq;
        zOut = o->unk20 * magSq;
    } else {
        o->unk24 = 0.0f;
        o->unk28 = 0.0f;
    }
    o->unk2C = zOut;
}

void GraphU64_NormalizeEdgeDirection(void *arg0)
{
    ObjRecAt2CV1 *o = arg0;
    f32 magSq;
    f32 mag;
    f32 zOut;

    magSq = (o->unk18 * o->unk18) +
            (o->unk1C * o->unk1C) +
            (o->unk20 * o->unk20);
    zOut = 0.0f;
    if (magSq != 0.0f) {
        mag = Math_Sqrtf(magSq);
        magSq = D_800C49A4_de / mag;
        o->unk24 = o->unk18 * magSq;
        o->unk28 = o->unk1C * magSq;
        zOut = o->unk20 * magSq;
    } else {
        o->unk24 = 0.0f;
        o->unk28 = 0.0f;
    }
    o->unk2C = zOut;
}

s32 GraphU64_GetHorizontalIntersectionParameter(f32 *arg0, f32 *arg1, f32 *arg2) {
    CVector3 delta;
    f32 temp_f3;
    s32 result;

    delta.x = arg1[0] - arg0[0];
    delta.z = arg1[2] - arg0[2];
    temp_f3 = (arg1[6] * arg0[12]) + (arg1[8] * arg0[14]);
    result = 0;
    if (temp_f3 != 0.0f) {
        result = 1;
        *arg2 = ((delta.x * arg0[12]) + (delta.z * arg0[14])) / -temp_f3;
    }
    return result;
}

/** Half-plane test: is arg1 on the positive side of arg0's normal (at +0x30)? */
s32 GraphU64_IsPointOnPositiveEdgeSide(void *geometryEdge, void *arg1) {
    GeometryEdge *edge = geometryEdge;
    CVector3 *point = arg1;
    CVector3 normal;
    CVector3 delta;
    s32 result;

    normal = edge->normal;
    delta.x = point->x - edge->start.x;
    delta.z = point->z - edge->start.z;
    result = 0;
    if (!(((normal.x * delta.x) + (normal.z * delta.z)) <= 0.0f)) {
        result = 1;
    }
    return result;
}

void GraphU64_BuildLookAtMatrix(float mf[4][4], float xEye, float yEye, float zEye,
                   float xAt, float yAt, float zAt,
                   float xUp, float yUp, float zUp)
{
    float one, len, xLook, yLook, zLook, xRight, yRight, zRight;

    func_802B6C6C_de(mf);

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    len = D_800C49A8_de / Math_Sqrtf(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    if (xRight == 0.0f && yRight == 0.0f && zRight == 0.0f) {
        xRight = (&D_800C49A8_de)[1];
    }
    one = D_800C49B0_de;
    len = one / Math_Sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = one / Math_Sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = one;
}

CVector3 *GraphU64_GetCachedSurfaceNormal(CVector3 *out, Node75 *node) {
    if (node == 0) {
        ((CVector3 *)&D_80115E00)->x = 0;
        ((CVector3 *)&D_80115E00)->z = 0;
        ((CVector3 *)&D_80115E00)->y = D_800C49C0_de;
    } else if ((int)node != D_800CD3E4) {
        cross_edges((CVector3 *)&D_80115E00, node);
        GraphU64_NormalizeVec3((CVector3 *)&D_80115E00);
    }
    *out = *(CVector3 *)&D_80115E00;
    D_800CD3E4 = (int)node;
    return out;
}

f32 GraphU64_GetTrianglePlaneHeight(Node75 *node, f32 x, f32 z) {
    CVector3 normal;
    CVector3 point;
    CVector3 a;
    CVector3 b;
    char *p;
    char *q;

    if (node == 0) {
        return 0.0f;
    }
    if ((int)node != D_800CD3E0) {
        p = node->cur;
        q = node->prev;
        a.x = ((CollisionBuildVertex *)p)->x - ((CollisionBuildVertex *)q)->x;
        p = node->cur;
        q = node->prev;
        a.y = ((CollisionBuildVertex *)p)->ceiling - ((CollisionBuildVertex *)q)->ceiling;
        p = node->cur;
        q = node->prev;
        a.z = ((CollisionBuildVertex *)p)->z - ((CollisionBuildVertex *)q)->z;
        p = node->next;
        q = node->cur;
        b.x = ((CollisionBuildVertex *)p)->x - ((CollisionBuildVertex *)q)->x;
        p = node->next;
        q = node->cur;
        b.y = ((CollisionBuildVertex *)p)->ceiling - ((CollisionBuildVertex *)q)->ceiling;
        p = node->next;
        q = node->cur;
        b.z = ((CollisionBuildVertex *)p)->z - ((CollisionBuildVertex *)q)->z;
        GraphU64_CrossVectors(&D_80111D30, &b, &a);
    }
    normal = D_80111D30;
    D_800CD3E0 = (int)node;
    if (normal.y == 0.0f) {
        return (((CollisionBuildVertex *)node->prev)->ceiling +
                ((CollisionBuildVertex *)node->cur)->ceiling +
                ((CollisionBuildVertex *)node->next)->ceiling) * D_800C49C8_de;
    }
    p = node->prev;
    point.x = ((CollisionBuildVertex *)p)->x;
    p = node->prev;
    point.y = ((CollisionBuildVertex *)p)->ceiling;
    p = node->prev;
    point.z = ((CollisionBuildVertex *)p)->z;
    return (((point.z - z) * normal.z) +
            ((point.x - x) * normal.x) + (point.y * normal.y)) /
           normal.y;
}
