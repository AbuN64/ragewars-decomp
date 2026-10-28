#include "include_asm.h"
#include "GAMECORE/EXTERNS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "GAMECORE/CODE.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/WORLD.H"
#include "COMMON/SHAREDPLAYER.H"
#include "GAMECORE/80278900.H"
#include "GAMECORE/80278900_2.H"
#include "RENDER/8028FD2C_6.H"

extern s32 D_800D2978;



f32 Link_GetLightAnimationOffset(void *arg0)
{
  ObjectRecAtBC *volume = arg0;
  u32 temp_a0;
  s32 idx;
  temp_a0 = volume->animationSeed;
  idx = D_800D2978 + ((((temp_a0 % 7) & 0xFF) + 1) * 0x10);
  idx = idx % 90;
  return (f32) D_800CD604[idx];
}







void Link_AnimateVertexColors(ObjectRecAt8 *object, u8 *colors) {
    s32 state;
    s32 i;
    Vtx *record;
    Vtx *end;

    state = D_800D2978;
    i = 0;
    if (!(state & 1)) {
        record = (void *)object->records;
        end = record + object->count;
        if (record != end) {
            do {
                u16 flags = (u16)record->flag;
                s32 amount;
                s32 value;
                u8 *color;

                if (flags & 0x70) {
                    amount = D_800CD604[(state + ((flags & 0x70) >> 2)) & 0x3F];
                    amount >>= (flags & 0xC) >> 2;
                    color = colors + i * 4;

                    value = amount + color[0];
                    if (value >= 0x100) value = 0xFF;
                    if (value < 0) value = 0;
                    record->r = value;

                    value = amount + color[1];
                    if (value >= 0x100) value = 0xFF;
                    if (value < 0) value = 0;
                    record->g = value;

                    value = amount + color[2];
                    if (value >= 0x100) value = 0xFF;
                    if (value < 0) value = 0;
                    record->b = value;
                }
                record++;
                i++;
            } while (record != end);
        }
    }
}

/* Saves each vertex's base colour for the colour pulse (Link_AnimateVertexColors): copies the r, g, b of every
   vertex of the object into colors (4 bytes per vertex), clamped to 30..225. */
void Link_CaptureVertexColors(ObjectRecAt8 *object, u8 *colors) {
    s32 i, count;
    Vtx *records;
    Vtx *record;
    u8 *color;
    u8 t;

    i = 0;
    count = object->count;
    records = (void *)object->records;
    if (count > 0) {
        do {
            record = &records[i];
            color = colors;
            colors += 4;
            t = RW_MAX_GT(RW_MIN_LT(record->r, 225), 30);
            color[0] = t;
            t = RW_MAX_GT(RW_MIN_LT(record->g, 225), 30);
            color[1] = t;
            t = RW_MAX_GT(RW_MIN_LT(record->b, 225), 30);
            color[2] = t;
            i++;
        } while (i < count);
    }
}

/* Sums the size field of the record SetN64_GetPackSection returns for each entry of the D_8011FE88 table and returns the total.
   Adapted from alEvtqNew with the loop over the global entry table and the accumulated return changed. */






/* Adds packed per-axis byte offsets to each entry of a vertex list. */







s32 Link_SumWorldSectionCounts(void) {
    s32 total = 0;
    s32 i;
    char *base = (char *)&g_world;

    for (i = 0; i < ((IntegerState1504 *)(base))->unk_1500; i++) {
        total += ((struct Shape_typemap_13 *)SetN64_GetPackSection(*((struct ObjectLinks150C *) (base + (i * 0xC)))->unk_1508, 2))->field_4;
    }
    return total;
}

void Link_ApplyPackedVertexDeltas(s32 arg0, s32 count, CVector3 *vtx) {
    Table *t;
    s32 zero;
    s32 i;
    char *base = (char *)&g_world;
    s32 *d;
    s32 w;
    s32 dx;
    s32 dy;
    s32 dz;

    t = SetN64_GetPackSection(arg0, 1);
    if (t->unk4 != 0) {
        zero = 0;
        i = zero;
        d = t->deltas;
        if (count > zero) {
            do {
                w = d[i];
                dx = ((w & 0xFF0000) << 8) >> 23;
                dy = ((w << 16) >> 24) * 2;
                dz = (w << 24) >> 23;
                vtx[i].x += (f32)dx;
                vtx[i].y += (f32)dy;
                vtx[i].z += (f32)dz;
                i++;
            } while (i < count);
        }
    }
}
