#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/LONE/D_800CA8C4_de.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PROPGEOMETRY.H"
#include "FX_2/80246E34_10.H"
#include "particle/8024BA6C_6.H"
#include "RENDER_4/8028FD2C_6.H"

extern char D_8011D8D0;

extern f32 Particle_GetActorHeight(Actor_func_8024A1D0_de *actor);

#include "particle/8027A0F4_8.H"

extern EffectRecAt154 *func_802830B8_de(void *system);

extern f32 Particle_GetActorRadius(Actor_func_8024A1D0_de *actor);

extern void Fx_DispatchAttachmentEffects(void *arg0, s32 arg1, s32 arg2, void *arg3, void *arg4);


extern void *D_800CB440_de[];


/* Applies a blast from a source to a body when an owner is given: the strength comes from the falloff table
 * D_800D06C0 indexed by the source's remaining charges, times 0.5 and 0.3 and the kind (-2 for kind 5);
 * the body's reversed velocity is placed in its offset transform, an impulse at the source position is
 * built by func_80272D00_de and applied through Rsp_MultiplyAffineMatrices, the velocity is restored onto the body, and
 * the source spends a charge when its owner matches. */








extern void func_8027302C(f32 *, Body_func_8024C6E8_de *);

extern void Particle_ScaleVector(CVector3 *, CVector3 *, f32);

extern void func_80273448_de(void *, f32, f32, f32);

extern void func_80272D00_de(f32 *, f32, f32, f32, f32);

extern void Rsp_MultiplyAffineMatrices(Body_func_8024C6E8_de *, f32 *, f32 *);

extern void func_80270AAC_de(void *arg0, s32 arg1, void *arg2, void *arg3);

void func_8024C454_de(Actor_func_8024A1D0_de *actor, LookupRecAtC *lookup) {
    CVector3 position;
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (func_8026E340_de() != 0) {
        node = Render_GetPackSection(*lookup->value, 2);
        if ((*node != 0) &&
            (*((s32 *)Render_GetPackSection(Render_GetPackSection(node, 0), 0)) & 0x8000)) {
            position = actor->position0;
            position.y += Particle_GetActorHeight(actor) * D_800C3B60_de;
            func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                          actor->position1, actor->rotation, position, 0, -1, 0);
            effect = func_802830B8_de(&D_8011D8D0);
            if (effect != 0) {
                scale = *(&D_800C3B60_de + 1);
                effect->field150 = Particle_GetActorRadius(actor) * scale;
                effect->field154 = Particle_GetActorHeight(actor) * scale;
            }
        }
    }
}

void func_8024C5D4_de(void *arg0, void *arg1, s32 arg2, s32 arg3)
{
    ObjRecAt17C *object = arg0;
  func_8024C5C4_S2 *temp_v0;
  s32 temp_s1;
  s32 mask = 1 << arg2;
  char *new_var;
  if ((object->unk17C) & mask)
  {
    temp_v0 = Render_GetPackSection(arg1, 3);
    temp_s1 = temp_v0->unk4;
    if (temp_s1 != 0)
    {
      new_var = &temp_v0->unk8;
      Fx_DispatchAttachmentEffects(new_var, temp_s1, arg3, arg0, Render_GetPackSection(arg1, 5));
    }
  }
}

void *func_8024C664_de(char *arg0)
{
    s32 type;
    s32 i;
    s32 count;
    s32 limit;
    char *object;
    ObjectList *list;

    ObjRecAt18V2 *actor = (void *)arg0;

    type = *actor->unk18;
    if ((unsigned int)type >= 15) {
        return 0;
    }
    if (type == 11) {
        list = (ObjectList *)&D_80145040;
        count = list->count;
        i = 0;
        if (count > 0) {
            limit = count;
            object = list->objects;
            do {
                if (object == arg0) {
                    return 0;
                }
                if (object + 0x2E8 == arg0) {
                    return D_800CA8C4_de;
                }
                i++;
                object += 0x16E8;
            } while (i < limit);
        }
    }
    return D_800CB440_de[type];
}

void func_8024C6E8_de(s32 unused, SourceRecAt18 *source, Body_func_8024C6E8_de *body, s32 owner, s32 kind) {
    CVector3 velocity;
    CVector3 position;
    f32 impulse[16];
    f32 transform[16];
    f32 strength;
    f32 reverse;
    f32 multiplier;

    if (owner == 0) {
        return;
    }
    velocity.x = body->velocity.x;
    velocity.y = body->velocity.y;
    velocity.z = body->velocity.z;
    position = source->position;
    strength = D_800D06C0[25 - source->charges] * 0.5f;
    strength *= 0.3f;
    if (kind == 5) {
        strength *= -2.0f;
    } else {
        strength *= kind;
    }
    func_8027302C(transform, body);
    reverse = -1.0f;
    Particle_ScaleVector(&velocity, &velocity, reverse);
    func_80273448_de(transform, velocity.x, velocity.y, velocity.z);
    func_80272D00_de(impulse, strength, position.x, position.y, position.z);
    Rsp_MultiplyAffineMatrices(body, transform, impulse);
    Particle_ScaleVector(&velocity, &velocity, reverse);
    func_80273448_de(body, velocity.x, velocity.y, velocity.z);
    if (source->owner == owner) {
        source->charges--;
    }
}

/** Lerp a 3-component vector: out = a + t * (b - a). */
void func_8024C874_de(void *arg0, f32 t, void *a, void *b) {
    CVector3 *out = arg0;
    CVector3 *start = a;
    CVector3 *end = b;
    out->x = start->x + (t * (end->x - start->x));
    out->y = start->y + (t * (end->y - start->y));
    out->z = start->z + (t * (end->z - start->z));
}

/** Lerp a 4-component vector: out = a + t * (b - a). */
void func_8024C8C4_de(void *cQuatern, f32 t, void *a, void *b) {
    CQuatern *out = cQuatern;
    CQuatern *left = a;
    CQuatern *right = b;

    out->x = left->x + (t * (right->x - left->x));
    out->y = left->y + (t * (right->y - left->y));
    out->z = left->z + (t * (right->z - left->z));
    out->w = left->w + (t * (right->w - left->w));
}

void func_8024C92C_de(void *arg0, s32 arg1, void *arg2) {
    ObjectLinks24 *o = arg0;
    CVector3 *out = arg2;
    ObjRecAt2V1 *indices = (void *)o->unk_0;
    s16 idx;
    CROMInitialOrientation_t *recs;
    f32 *base;
    f32 *a;
    f32 scale;

    idx = indices[arg1].translation;
    if (idx == -1) {
        recs = (void *)o->unk_4;
        *out = recs[arg1].position;
        return;
    }
    base = Render_GetPackSection(o->translationFrames, (s32) idx);
    a = base + o->translationFirst;
    base = base + o->translationNext;

    scale = o->unk_20;

    out->x = a[0] + scale * (base[0] - a[0]);
    out->y = a[1] + scale * (base[1] - a[1]);
    out->z = a[2] + scale * (base[2] - a[2]);
}

void func_8024CA10_de(void *arg0, s32 arg1, CQuatern *arg2) {
    char *o = (char *)arg0;
    s16 idx;
    char *rec;
    void *base;
    char *a;

    idx = ((struct ObjRecAt2V1 *) (((ObjectLinks24 *) o)->unk_0 + (arg1 * 4)))->unk2;
    if (idx == -1) {
        f32 scale;
        rec = ((ObjectLinks24 *)(o))->unk_4 + arg1 * 0x14;
        scale = (3.0518509447574615e-05f);
        arg2->x = (f32)(((CROMInitialOrientation_t *)(rec))->unk_C) * scale;
        arg2->y = (f32)(((CROMInitialOrientation_t *)(rec))->m_RotY) * scale;
        arg2->z = (f32)(((CROMInitialOrientation_t *)(rec))->unk_10) * scale;
        arg2->w = (f32)(((CROMInitialOrientation_t *)(rec))->unk_12) * scale;
        return;
    }
    base = Render_GetPackSection(((ObjectLinks24 *)(o))->unk_C, (s32)idx);
    a = (char *)base + (((ObjectLinks24 *)(o))->unk_10) * 4;
    base = (char *)base + (((ObjectLinks24 *)(o))->unk_14) * 4;
    {
        f32 scale;
        scale = ((ObjectLinks24 *)(o))->unk_20;
        arg2->x = ((CQuatern *)(a))->x + scale * (((CQuatern *)(base))->x - ((CQuatern *)(a))->x);
        arg2->y = ((CQuatern *)(a))->y + scale * (((CQuatern *)(base))->y - ((CQuatern *)(a))->y);
        arg2->z = ((CQuatern *)(a))->z + scale * (((CQuatern *)(base))->z - ((CQuatern *)(a))->z);
        arg2->w = ((CQuatern *)(a))->w + scale * (((CQuatern *)(base))->w - ((CQuatern *)(a))->w);
    }
}

void func_8024CB4C_de(ObjectLinks24_2 *arg0, s32 arg1, CQuatern *arg2) {
    ObjectLinks24_2 *o = arg0;
    ObjRecAt2V1 *indices;
    s16 idx;
    CROMInitialOrientation_t *rec;
    void *base;
    f32 scale;

    indices = (void *)o->unk_0;
    idx = indices[arg1].unk2;
    if (idx == -1) {
        rec = (void *)(o->unk_4 + arg1 * 0x14);
        scale = D_800C3B7C;
        arg2->x = (f32)rec->unk_C * scale;
        arg2->y = (f32)rec->m_RotY * scale;
        arg2->z = (f32)rec->unk_10 * scale;
        arg2->w = (f32)rec->unk_12 * scale;
        return;
    }
    base = Render_GetPackSection(o->unk_C, (s32)idx);
    func_80270AAC_de(arg2, o->unk_20,
                    (char *)base + o->unk_10 * 4,
                    (char *)base + o->unk_14 * 4);
}

/* Converts the twelve used entries of a 4x4 float matrix to unsigned integers, splitting each pair into the high and low halfword arrays of a packed matrix and setting the final high word's low bit. Adapted from func_8027027C_de with the per-entry scale multiplies removed, the converted value scoped to each conversion block, and the D_800C8C70 thresholds changed. */
void func_8024CC30_de(f32 *src, PackedMatrixWords *dst) {
    u32 *upper = dst->upper;
    u32 *lower = dst->lower;
    s32 a;
    s32 b;
    { f32 value = (src[0]); if (!((D_800C8C70) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (D_800C8C70)); (a) |= 0x80000000; } };
    { f32 value = (src[1]); if (!((*(&D_800C8C70 + 1)) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - (*(&D_800C8C70 + 1))); (b) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;
    { f32 value = (src[2]); if (!((D_800C3B88) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (D_800C3B88)); (a) |= 0x80000000; } };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;
    { f32 value = (src[4]); if (!((*(&D_800C3B88 + 1)) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (*(&D_800C3B88 + 1))); (a) |= 0x80000000; } };
    { f32 value = (src[5]); if (!((D_800C3B90) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - (D_800C3B90)); (b) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;
    { f32 value = (src[6]); if (!((*(&D_800C3B90 + 1)) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (*(&D_800C3B90 + 1))); (a) |= 0x80000000; } };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;
    { f32 value = (src[8]); if (!((D_800C3B98) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (D_800C3B98)); (a) |= 0x80000000; } };
    { f32 value = (src[9]); if (!((*(&D_800C3B98 + 1)) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - (*(&D_800C3B98 + 1))); (b) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;
    { f32 value = (src[10]); if (!((D_800C3BA0_de) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (D_800C3BA0_de)); (a) |= 0x80000000; } };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;
    { f32 value = (src[12]); if (!((*(&D_800C3BA0_de + 1)) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (*(&D_800C3BA0_de + 1))); (a) |= 0x80000000; } };
    { f32 value = (src[13]); if (!((D_800C3BA8) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - (D_800C3BA8)); (b) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;
    { f32 value = (src[14]); if (!((*(&D_800C3BA8 + 1)) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (*(&D_800C3BA8 + 1))); (a) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | 1;
    *lower = a << 16;
}
