#include "include_asm.h"
#include "GAMECORE/EXTERNS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"

extern s32 D_800D2978;



f32 func_80278890_de(void *arg0)
{
  ObjectRecAtBC *volume = arg0;
  u32 temp_a0;
  s32 idx;
  temp_a0 = volume->animationSeed;
  idx = D_800D2978 + ((((temp_a0 % 7) & 0xFF) + 1) * 0x10);
  idx = idx % 90;
  return (f32) D_800CD604[idx];
}

extern s32 D_800D2978;






void func_8027892C_de(ObjectRecAt8 *object, u8 *colors) {
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

/* Saves each vertex's base colour for the colour pulse (func_8027892C_de): copies the r, g, b of every
   vertex of the object into colors (4 bytes per vertex), clamped to 30..225. */
void func_80278A08_de(ObjectRecAt8 *object, u8 *colors) {
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
