#include "span_1000/code_8027451C.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/func_802745D0_de_closed.h"
#include "span_16E000/code_8044ACCC.h"
#include "span_C76B0/data.h"
#include "TYPES.H"

extern f32 D_800D2988;

extern f32 D_800C4968_de[2];

extern f32 D_800C4970_de[2];

extern f32 func_802B72B0_de(f32);

extern char D_800C49A0_de;

extern f32 D_800C49A4_de;

/* Builds a look-at view matrix (ultralib guLookAtF) from an eye, a target and an up vector,
   substituting a fallback x component when the up vector is parallel to the view direction.
   Adapted from ultralib gu/lookat.c with single-precision const extern constants, the degenerate check and the 1.0 held in a temporary. */
extern const float D_800C49A8_de;

extern const float D_800C49B0_de;

extern void func_802B6C6C_de(float mf[4][4]);

extern float func_802B72B0_de(float);

/* Returns the normalised cross product of a path node's two edge vectors, cached in D_80115E00 for the last node seen, with a default up vector for a null node. Adapted from func_80275F28_de, which it inlines to compute the raw cross product, with the result normalised through func_8027207C_de and cached by a second last-node word; the inlined copy records its last node before copying its result. */


extern int D_80111D30;

extern int D_80115E00;

extern int D_800CD3E0;

extern int D_800CD3E4;

extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);

extern void func_8027207C_de(Vec3 *);

static inline Vec3 *cross_edges(Vec3 *out, Node75 *node) {
    Vec3 a;
    Vec3 b;
    char *p;
    char *q;

    if (node == 0) {
        ((Vec3 *)&D_80111D30)->x = 0;
        ((Vec3 *)&D_80111D30)->z = 0;
        ((Vec3 *)&D_80111D30)->y = D_800C49C4_de;
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
        func_80272018_de((Vec3 *)&D_80111D30, &b, &a);
    }
    D_800CD3E0 = (int)node;
    *out = *(Vec3 *)&D_80111D30;
    return out;
}

/** Perform the no-op callback at VRAM 0x8027451C. */
void func_802744AC_de(void) {
}

/** Store a fill pattern into two paired global words. */
void func_802744B4_de(void) {
    extern int D_80111D28;
    D_80111D24 = 0xE3F635E3;
    D_80111D28 = 0xE3F635E3;
}

s32 func_802744D4_de(void) {
    u32 temp_v1;

    temp_v1 = (D_80111D24 * 0xA84A5B53) + 0x58348C2D;
    D_80111D24 = temp_v1;
    return ((temp_v1 << 0x10) | (temp_v1 >> 0x10)) & 0x7FFFFFFF;
}

s32 func_8027451C_de(void) {
    extern u32 D_80111D28;
    u32 temp_v1;

    temp_v1 = (D_80111D28 * 0xA84A5B53) + 0x58348C2D;
    D_80111D28 = temp_v1;
    return ((temp_v1 << 0x10) | (temp_v1 >> 0x10)) & 0x7FFFFFFF;
}

/** LCG PRNG step scaled into [0, arg0 * D_800C9A38) as a float. */
f32 func_80274564_de(f32 arg0) {
    f64 var_f1;
    s32 temp_v0;
    u32 temp_v1;

    temp_v1 = (D_80111D24 * 0xA84A5B53) + 0x58348C2D;
    temp_v0 = (s32)((temp_v1 >> 0x10) & 0x7FFF);
    var_f1 = (f64)temp_v0;
    D_80111D24 = temp_v1;
    if (temp_v0 < 0) {
        var_f1 = var_f1 + D_800C4940_de;
    }
    return (f32)var_f1 * arg0 * D_800C9A38;
}

f32 func_802745D0_de(f32 arg0) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    s32 temp_f4;
    s32 var_v1;

    var_v1 = 1;
    if (arg0 < 0.0f) {
        temp_f1 = arg0 * D_800C494C_de;
    } else {
        temp_f1 = arg0 * D_800C4950_de;
        var_v1 = 0;
    }
    temp_f4 = (s32) temp_f1;
    if ((f32) temp_f4 < D_800C4954_de) {
        temp_f2_2 = D_800CC3DC[temp_f4];
        temp_f2 = temp_f2_2 + ((temp_f1 - (f32) temp_f4) * (D_800CC3E0[temp_f4] - temp_f2_2));
        if (var_v1 != 0) {
            return D_800C4958_de - temp_f2;
        }
        return temp_f2;
    }
    if (var_v1 != 0) {
        temp_f1 = D_800CD3D8;
        return D_800C495C_de - temp_f1;
    }
    return D_800CD3D8;
}

f32 func_802746A0_de(f32 arg0, f32 arg1, f32 arg2) {
    extern f32 D_800C4960_de;
    if (arg1 < 0.0f) {
        if (arg0 <= -arg2) {
            return arg0;
        }
    }
    if (0.0f < arg1) {
        if (arg2 <= arg0) {
            return arg0;
        }
    }
    if ((arg0 < 0.0f && 0.0f < arg1) ||
        (0.0f < arg0 && arg1 < 0.0f)) {
        arg1 *= D_800C4960_de;
    }
    arg0 += arg1 * D_800D2988;
    if (arg1 < 0.0f) {
        if (arg0 < -arg2) {
            arg0 = -arg2;
        }
    } else if (arg2 < arg0) {
        arg0 = arg2;
    }
    return arg0;
}

f32 func_802747A0_de(f32 arg0, f32 arg1) {
    f32 zero;

    zero = 0.0f;
    if (zero < arg0) {
        arg0 -= arg1 * D_800D2988;
        if (arg0 < zero) {
            arg0 = zero;
        }
    } else if (arg0 < zero) {
        arg0 += arg1 * D_800D2988;
        if (zero < arg0) {
            arg0 = zero;
        }
    }
    return arg0;
}

f32 func_80274808_de(f32 arg0, f32 arg1, f32 arg2) {
    f32 value;
    value = arg0;
    if (value < arg1) {
        value += arg2 * D_800D2988;
        if (arg1 < value) {
            value = arg1;
        }
    }
    else if (arg1 < value) {
        value -= arg2 * D_800D2988;
        if (value < arg1) {
            value = arg1;
        }
    }
    return value;
}

void func_80274870_de(f32 *value, f32 target, f32 rate) {
    extern f32 D_800C4960_de[2];
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

s32 func_802748F4_de(s32 arg0, s32 arg1, s32 arg2)
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

f32 func_80274944_de(f32 arg0)
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

f32 func_802749B4_de(f32 arg0, f32 arg1) {
    f32 var_f0;
    f32 var_f14;

    var_f14 = arg1;
    if (var_f14 < D_800C4978_de) {
        do {
            var_f14 += *(&D_800C4978_de + 1);
        } while (var_f14 < D_800C4978_de);
    }
    if (D_800C4980_de < var_f14) {
        do {
            var_f14 -= *(&D_800C4980_de + 1);
        } while (D_800C4980_de < var_f14);
    }
    var_f0 = arg0 - var_f14;
    if (var_f0 < D_800C4988_de) {
        do {
            var_f0 += *(&D_800C4988_de + 1);
        } while (var_f0 < D_800C4988_de);
    }
    if (D_800C4990_de < var_f0) {
        do {
            var_f0 -= *(&D_800C4990_de + 1);
        } while (D_800C4990_de < var_f0);
    }
    return -var_f0;
}

f32 func_80274A90_de(f32 arg0, f32 arg1) {
    f32 temp_f1;
    u32 temp_a1;
    s32 rotated;

    temp_a1 = (D_80111D24 * 0xA84A5B53) + 0x58348C2D;
    rotated = ((temp_a1 << 0x10) | (temp_a1 >> 0x10)) & 0x7FFFFFFF;
    rotated = rotated % 10000;
    temp_f1 = (f32)rotated * D_800C4998_de;
    D_80111D24 = temp_a1;
    return (temp_f1 * arg0) + ((D_800C499C_de - temp_f1) * arg1);
}

s32 func_80274B44_de(f32 *arg0)
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
void func_80274B7C_de(void *arg0, void *arg1, void *arg2) {
    GeometryEdge *dst = arg0;
    Vec3 *a = arg1;
    Vec3 *b = arg2;
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

void func_80274BF4_de(void *arg0)
{
    ObjRecAt2CV1 *o = arg0;
    f32 magSq;
    f32 mag;
    f32 zOut;

    magSq = (o->unk18 * o->unk18) +
            (o->unk20 * o->unk20);
    zOut = 0.0f;
    if (magSq != 0.0f) {
        mag = func_802B72B0_de(magSq);
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

void func_80274C7C_de(void *arg0)
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
        mag = func_802B72B0_de(magSq);
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

s32 func_80274D10_de(f32 *arg0, f32 *arg1, f32 *arg2) {
    Vec3 delta;
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
s32 func_80274D8C_de(void *arg0, void *arg1) {
    GeometryEdge *edge = arg0;
    Vec3 *point = arg1;
    Vec3 normal;
    Vec3 delta;
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

void func_80274DFC_de(float mf[4][4], float xEye, float yEye, float zEye,
                   float xAt, float yAt, float zAt,
                   float xUp, float yUp, float zUp)
{
    float one, len, xLook, yLook, zLook, xRight, yRight, zRight;

    func_802B6C6C_de(mf);

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    len = D_800C49A8_de / func_802B72B0_de(xLook * xLook + yLook * yLook + zLook * zLook);
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
    len = one / func_802B72B0_de(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = one / func_802B72B0_de(xUp * xUp + yUp * yUp + zUp * zUp);
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

Vec3 *func_802750B0_de(Vec3 *out, Node75 *node) {
    if (node == 0) {
        ((Vec3 *)&D_80115E00)->x = 0;
        ((Vec3 *)&D_80115E00)->z = 0;
        ((Vec3 *)&D_80115E00)->y = D_800C49C0_de;
    } else if ((int)node != D_800CD3E4) {
        cross_edges((Vec3 *)&D_80115E00, node);
        func_8027207C_de((Vec3 *)&D_80115E00);
    }
    *out = *(Vec3 *)&D_80115E00;
    D_800CD3E4 = (int)node;
    return out;
}

f32 func_8027525C_de(Node75 *node, f32 x, f32 z) {
    Vec3 normal;
    Vec3 point;
    Vec3 a;
    Vec3 b;
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
        func_80272018_de((Vec3 *)&D_80111D30, &b, &a);
    }
    normal = *(Vec3 *)&D_80111D30;
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
