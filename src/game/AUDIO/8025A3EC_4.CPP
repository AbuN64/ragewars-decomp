#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON.H"
#include "AUDIO/EXTERNS.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "AUDIO/8025A3EC_4.H"
#include "AUDIO/80259280_11.H"

/* Releases occupied nonlocal slots unless their value equals the exclusion. */





extern void func_802B2F00_de(void *sound, s16 sample);

extern s32 func_802B2620_de(void *sound);

extern void alSndpStop(void *sound);

extern void func_802B2F00_de(void *arg0, s16 arg1);

extern s32 func_802B2620_de(void *arg0);

/* Stops the selected sound slot and sets its release flag; split unsigned offset-to-pointer casts and a one-pass statement group preserve the separate table and offset schedule. */


extern void func_802B2D80_de(void *);

extern void alSndpStop(void *arg0);

extern void func_80259C5C_de(void *arg0, void *arg1, s32 arg2);

extern void *func_80258BF4_de(ContextRecAt2BC0 *arg0, s32 arg1);

extern s32 func_80258D2C_de(void *arg0);

extern s16 func_80259B10_de(void *arg0, GameplayCamera *arg1);

extern void func_8025AE1C_de(void *arg0);

/* Returns how strongly a listener at 0x128 hears a source at 0x34: one minus the squared distance over the squared range D_800D0D10 (zero beyond it), shaped by the source's curve at 0x44 as the eighth power, the square or the plain value. */






extern void func_802B2F10_de(void *arg0, s16 arg1);

extern void alSndpSetPitch(void *arg0, f32 arg1);

void func_8025B5F0_de(RecordRecAt4V6 *record, s32 value)
{
  s32 i;
  s32 active;
  s32 absent;
  SlotRecAtB0 *slot = record->slots;
  i = 0;
  absent = -1;
  active = 1;
  for (; i < 16; slot++, i++)
  {
    if (((slot->used != absent) && (record->header->local != i)) && ((value == absent) || (slot->value != value)))
    {
      OwnerCode8025A3EC8025B5F0 *owner = slot->owner;
      void *sound;
      slot->active = active;
      slot->flag = 0;
      if (slot->key != owner->key)
      {
        sound = owner->sound;
        func_802B2F00_de(sound, owner->samples[slot->index]);
        if (func_802B2620_de(sound) != 0)
        {
          if (active)
          {
            alSndpStop(sound);
          }
          else
          {
            alSndpStop(sound);
          }
        }
        slot->state = absent;
      }
    }
  }

}

/* Initialises an object: sets the words at 0x8, 0xC, 0x40 and 0xB4 and the halfword at 0x3A to -1,
   stores the two arguments at 0xB0 and 0x0, clears the halfword at 0x38 and the words at 0x14, 0x58,
   0x5C, 0xA4, 0xAC, 0xBC and 0xC0, sets the word at 0xC4 to 1 and writes D_800C9068 into the floats
   at 0x2C, 0x34 and 0xB8. */



void func_8025B6F8_de(void *arg0, int arg1, int arg2) {
    RecordCode8025A3EC *slot = arg0;
    float k = D_800C9068;

    slot->f0C = -1;
    slot->f08 = -1;
    slot->f3A = -1;
    slot->f40 = -1;
    slot->fB4 = -1;
    slot->owner = arg1;
    slot->index = arg2;
    slot->f38 = 0;
    slot->f14 = 0;
    slot->f58 = 0;
    slot->f5C = 0;
    slot->fA4 = 0;
    slot->fAC = 0;
    slot->fBC = 0;
    slot->fC0 = 0;
    slot->fC4 = 1;
    slot->f2C = k;
    slot->f34 = k;
    slot->fB8 = k;
}

void func_8025B758_de(s32 *arg0, s32 arg1) {
    s32 i;
    s32 idx;
    f32 t;
    f32 p;
    s32 off;
    RecordCode8025A3EC *rec;
    f32 k1;
    f32 k2;
    f32 k3;
    s32 negone;
    s32 one;

    i = 0;
    k1 = D_800C3F7C_de;
    k2 = D_800C3F80_de;
    *arg0 = arg1;
    do {
        t = (f32)i * k1;
        p = t * t * t * t * t * k2;
        idx = 0x5A - i;
        i += 1;
        D_80107FA0[idx] = (s16)(s32)p;
    } while (i < 0x5B);

    negone = -1;
    i = 0;
    k3 = D_800C3F84_de;
    one = 1;
    off = i;
    do {
        rec = (RecordCode8025A3EC *)((u32)off + (u32)arg0);
        rec = &((ObjRecAt4V6 *)(rec))->unk4;
        rec->index = i;
        i += 1;
        rec->owner = arg1;
        rec->f0C = negone;
        rec->f08 = negone;
        rec->f3A = (s16)negone;
        rec->f38 = 0;
        rec->f40 = negone;
        rec->f14 = 0;
        rec->f2C = k3;
        rec->f58 = 0;
        rec->f5C = 0;
        rec->f34 = k3;
        rec->fA4 = 0;
        rec->fAC = 0;
        rec->fB4 = negone;
        rec->fB8 = k3;
        rec->fBC = 0;
        rec->fC0 = 0;
        rec->fC4 = one;
        off += 0xCC;
    } while (i < 0x11);
}

s32 func_8025B854_de(SlotRecAtB8 *arg0, s16 arg1)
{
  s32 temp_v0;
  s32 temp_v1;
  void *temp_s0;
  RecordCode8025A3EC *slot;
  OwnerCode8025A3EC8025B5F0 *owner;
  temp_v0 = (arg1 * 0xCC) + (s32)arg0;
  temp_v0 = temp_v0 + 4;
  slot = (RecordCode8025A3EC *)temp_v0;
  temp_v1 = slot->owner;
  owner = (OwnerCode8025A3EC8025B5F0 *)temp_v1;
  temp_s0 = owner->sound;
  func_802B2F00_de(temp_s0, owner->samples[slot->index]);
  return func_802B2620_de(temp_s0);
}

void func_8025B8BC_de(SlotRecAtB8 *base, s16 index)
{
  unsigned int offset = index * (sizeof(SlotRecAtB8));
  char *entry = (char *) offset;
  SlotRecAtB8 *slots;
  SlotRecAtB8 *selected;
  entry += (unsigned int) base;
  slots = base;
 do { func_802B2D80_de(0x84 + ((SlotRecAtB8 *) entry)->owner); entry = (char *) slots; entry += offset; selected = (SlotRecAtB8 *) entry; } while (0);
  selected->flags |= 8;
}

s32 func_8025B920_de(RecordD90 *record, s16 value, s16 id) {
    s32 i;
    SlotCC *cur = record->slots;

    for (i = 0; i < 16; cur++, i++) {
        if (cur->used != -1 && record->header->local != i && cur->value == value && (cur->mode & 0x40) &&
            cur->id == id) {
            release(&record->slots[(s16)i]);
            return (s16)i;
        }
    }
    return -1;
}

/* Returns whether any of the sixteen occupied slots of a record, other than the one its header marks as local, holds the given value at slot offset 0xA8. */

s32 func_8025BA4C_de(RecordRecAt4V3 *record, s32 value) {
    s32 i;
    SlotRecAtA8 *slot = record->slots;

    for (i = 0; i < 16; i++, slot++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            return 1;
        }
    }
    return 0;
}

void func_8025BA9C_de(s32 arg0, s16 arg1) {
    s32 base;
    s32 a0;
    void *s1;

    base = (arg1 * 0xCC) + arg0;
    base = base + 4;
    a0 = ((struct IntegerStateB4 *) base)->unk_B0;
    ((struct IntegerStateB4 *) base)->unk_AC = 1;
    ((struct IntegerStateB4 *) base)->unk_50 = 0;
    s1 = (void *)(a0 + 0x84);
    if (((struct IntegerStateB4 *) base)->unk_10 != ((struct func_80245A10_S1 *) a0)->unk104) {
        s32 idx = ((struct IntegerStateB4 *) base)->unk_0;
        s32 addr = a0 + idx * 2;
        func_802B2F00_de(s1, ((struct ObjRecAtDC *) addr)->unkDC);
        if (func_802B2620_de(s1) != 0) {
            alSndpStop(s1);
        }
        ((struct IntegerStateB4 *) base)->unk_4 = -1;
    }
}

void func_8025BB3C_de(s32 a) {
    s32 var_v0;
    void *var_a0;
    var_a0 = a + 4;
    var_v0 = 0x10;
    do {
        ((SlotCC *)var_a0)->flag = 0;
        var_v0 -= 1;
        var_a0 += 0xCC;
    } while (var_v0 >= 0);
}

void func_8025BB5C_de(void *arg0, void *arg1, int arg2) {
    ((struct View_func_8025AE1C_de *)(arg0))->position = *(Triple *)arg1;
    ((struct View_func_8025AE1C_de *)(arg0))->tracked = (Triple *)arg2;
}

void func_8025BB7C_de(void *arg0, int arg1) {
    ((struct View_func_8025AE1C_de *)(arg0))->trackId = arg1;
}

void func_8025BB84_de(void *arg0, void *arg1, s32 arg2) {
    f32 first;
    s16 index;
    s16 value;
    void *record;

    func_80259C5C_de(arg0, arg1, arg2);
    func_80259F68_de(arg0, arg1, arg2);
    ((struct View_func_8025AE1C_de *)(arg0))->priority = 0x40;
    index = ((struct Shared_Body *)(arg1))->kind;
    if (index != -1) {
        record = func_80258BF4_de(((struct View_func_8025AE1C_de *)(arg0))->context, index);
        ((struct View_func_8025AE1C_de *)(arg0))->envelope = *(SoundEnvelope *)record;
        first = RW_BITS_TO_FLOAT(((struct View_func_8025AE1C_de *)(arg0))->envelope.initial);
        ((struct View_func_8025AE1C_de *)(arg0))->step =
            (first - RW_BITS_TO_FLOAT(((struct View_func_8025AE1C_de *)(arg0))->envelope.target)) /
            ((struct View_func_8025AE1C_de *)(arg0))->envelope.frames;
        ((struct View_func_8025AE1C_de *)(arg0))->value =
            RW_BITS_TO_FLOAT(((struct View_func_8025AE1C_de *)(arg0))->envelope.initial);
        ((struct View_func_8025AE1C_de *)(arg0))->priority =
            (s16)(s32)RW_BITS_TO_FLOAT(((struct View_func_8025AE1C_de *)(arg0))->envelope.initial);
        ((struct View_func_8025AE1C_de *)(arg0))->sweeping = 1;
        return;
    }

    ((struct View_func_8025AE1C_de *)(arg0))->sweeping = 0;
    if (((struct View_func_8025AE1C_de *)(arg0))->trackId < 0x100) {
        if (((struct View_func_8025AE1C_de *)(arg0))->fixed == 0 &&
            func_80258D2C_de(((struct View_func_8025AE1C_de *)(arg0))->context) != 0) {
            value = (s8)((ContextRecAt2BC0 *)((struct View_func_8025AE1C_de *)arg0)->context)->field2B94;
            goto store_value;
        }
    } else if (((struct View_func_8025AE1C_de *)(arg0))->fixed == 0 &&
               func_80258D2C_de(((struct View_func_8025AE1C_de *)(arg0))->context) != 0) {
        value = func_80259B10_de(&((struct View_func_8025AE1C_de *)(arg0))->position,
            ((struct View_func_8025AE1C_de *)arg0)->context->result);
store_value:
        ((struct View_func_8025AE1C_de *)(arg0))->priority = value;
    }
}

void func_8025BD00_de(void **arg0) {
    s32 var_s0;
    s32 var_s2;
    char *var_s1;

    var_s2 = 0;
    var_s1 = (char *)((RecordD90 *)arg0)->slots;
    var_s0 = 0;
    do {
        if (((SlotCC *)var_s1)->used != -1 && ((HeaderRecAt102 *)(*arg0))->local != var_s0) {
            func_8025AE1C_de(var_s1);
            var_s2 += 1;
        }
        var_s0 += 1;
        var_s1 += 0xCC;
    } while (var_s0 < 0x10);
    D_800CBAFC = var_s2;
    if (D_800CBB00 < var_s2) {
        D_800CBB00 = var_s2;
    }
}

/* Returns the index of the first of sixteen 0xCC-byte slots at 0xC that is in use, is not the
   owner's own slot and whose two keys at 0xA0 and 0xAC equal the arguments, or -1 when none does; indexing from the second key reproduces the reference induction base. */






int func_8025BDAC_de(ObjRecAtCV4 *obj, int keyA, int keyB) {
    int i;
    int *keys = &obj->slots[0].keyB;

    for (i = 0; i < 16; i++) {
        if (keys[i * 0x33 - 43] != -1 && obj->owner->local != i && keys[i * 0x33 - 3] == keyA &&
            keys[i * 0x33] == keyB) {
            return i;
        }
    }
    return -1;
}

void func_8025BE08_de(RecordRecAt4V6 *record, s32 value) {
    s32 i;
    SlotRecAtB0 *slot = record->slots;

    for (i = 0; i < 17; slot++, i++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            OwnerCode8025A3EC8025B5F0 *owner = slot->owner;
            void *sound;

            slot->active = 1;
            slot->flag = 0;
            if (slot->key != owner->key) {
                sound = owner->sound;
                func_802B2F00_de(sound, owner->samples[slot->index]);
                if (func_802B2620_de(sound) != 0) {
                    alSndpStop(sound);
                }
                slot->state = -1;
            }
        }
    }
}

void func_8025BF08_de(RecordRecAt4V5 *record, s32 value) {
    s32 i;
    SlotRecAtB4V1 *slot = record->slots;

    for (i = 0; i < 17; slot++, i++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            OwnerCode8025A3EC8025B5F0 *owner = slot->owner;
            void *sound;

            slot->active = 1;
            slot->flag = 0;
            if (slot->key != owner->key) {
                sound = owner->sound;
                func_802B2F00_de(sound, owner->samples[slot->index]);
                if (func_802B2620_de(sound) != 0) {
                    alSndpStop(sound);
                }
                slot->state = -1;
            }
        }
    }
}

void func_8025C008_de(RecordRecAt4V4 *record, s32 value) {
    s32 i;
    SlotRecAtB4V2 *slot = record->slots;

    for (i = 0; i < 17; slot++, i++) {
        if (slot->used != -1 && record->header->local != i && (slot->mask & value) != 0) {
            OwnerCode8025A3EC8025B5F0 *owner = slot->owner;
            void *sound;

            slot->active = 1;
            slot->flag = 0;
            if (slot->key != owner->key) {
                sound = owner->sound;
                func_802B2F00_de(sound, owner->samples[slot->index]);
                if (func_802B2620_de(sound) != 0) {
                    alSndpStop(sound);
                }
                slot->state = -1;
            }
        }
    }
}

f32 func_8025C10C_de(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    f32 distSq = (dx * dx) + (dy * dy) + (dz * dz);
    if (D_800D0D10 <= distSq) {
        return 0.0f;
    }
    return D_800C3F88_de - (distSq / D_800D0D10);
}

/* Returns whether any of the seventeen occupied slots of a record, other than the one its header marks as local, holds the given value at slot offset 0xA8. Adapted from func_8025BA4C_de with the slot count changed from 16 to 17. */







s32 func_8025C17C_de(RecordRecAt4V3 *record, s32 value) {
    s32 i;
    SlotRecAtA8 *slot = record->slots;

    for (i = 0; i < 17; i++, slot++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            return 1;
        }
    }
    return 0;
}

f32 func_8025C1CC_de(f32 arg0)
{
  f32 temp_f0;
  f32 temp_f1;
  f32 temp_f2;
  s32 temp_f3;
  s16 temp_s16;
  s32 temp_plus;
  temp_f0 = (arg0 + (&D_800C3F88_de)[1]) * D_800C3F90_de;
  temp_f3 = (s32) temp_f0;
  temp_s16 = (s16) temp_f3;
  temp_f1 = (f32) temp_s16;
  if (temp_f1 != temp_f0)
  {
    temp_plus = temp_f3 + 1;
    temp_f2 = (&D_800CB8E8)[1 + temp_s16];
    return temp_f2 + ((temp_f0 - temp_f1) * ((&D_800CB8E8)[1 + ((s16) temp_plus)] - temp_f2));
  }
  return (&D_800CB8E8)[1 + temp_s16];
}

s16 func_8025C25C_de(s16 arg0, s16 arg1) {
    f32 temp_f20;
    f32 temp_f21;
    temp_f21 = (f32)arg1;
    temp_f20 = (f32)arg0;
    return (s16)(s32)(func_80274A90_de(temp_f21, temp_f20) < 0.0f
                          ? temp_f20 - func_80274A90_de(temp_f21, temp_f20)
                          : temp_f20 + func_80274A90_de(temp_f21, temp_f20));
}

f32 func_8025C2EC_de(u8 arg0, u8 arg1) {
    f32 first;
    f32 second;

    first = arg0 * D_800C3F94_de;
    second = arg1 * D_800C3F94_de;
    if (first == D_800C3F98_de) {
        return D_800C3F98_de;
    }
    if (second == first) {
        return first;
    }
    return first + func_80274564_de(second - first);
}

f32 func_8025C368_de(char *source, char *listener)
{
    SoundSpatialSource *sound = (SoundSpatialSource *)source;
    GameplayCamera *camera = (GameplayCamera *)listener;
    CVector3 *a = &sound->position;
    CVector3 *b = &camera->position;
    f32 dx = a->x - b->x;
    f32 dy;
    f32 dz;
    f32 d;
    f32 t;

    dx *= dx;
    dy = a->y - b->y;
    dy *= dy;
    dz = a->z - b->z;
    dz *= dz;
    d = dx + dy + dz;
    if (d >= D_800D0D10) {
        t = 0.0f;
    } else {
        t = D_800C3F9C_de - d / D_800D0D10;
    }
    switch (sound->curve) {
    case 2:
        return t;
    case 0:
        t *= t;
        t *= t;
    case 1:
        return t * t;
    default:
        return 0.0f;
    }
}

void func_8025C438_de(void *arg0, s32 arg1) {
    RecordCode8025A3EC *slot = arg0;
    OwnerCode8025A3EC8025B5F0 *owner;
    s32 temp_s0;
    void *temp_s0_2;

    temp_s0 = slot->owner;
    owner = (OwnerCode8025A3EC8025B5F0 *)temp_s0;
    temp_s0_2 = owner->sound;
    func_802B2F00_de(temp_s0_2, owner->samples[slot->index]);
    func_802B2F10_de(temp_s0_2, (s16)(s32)((f32) arg1 * (slot->fC8)));
}

void func_8025C4B4_de(void *arg0, f32 arg1) {
    RecordCode8025A3EC *slot = arg0;
    OwnerCode8025A3EC8025B5F0 *owner;
    s32 temp_s0;
    void *temp_s0_2;
    f32 scaled;

    temp_s0 = slot->owner;
    owner = (OwnerCode8025A3EC8025B5F0 *)temp_s0;
    temp_s0_2 = owner->sound;
    func_802B2F00_de(temp_s0_2, owner->samples[slot->index]);
    scaled = arg1 * (slot->f34);
    scaled = scaled * (slot->fB8);
    alSndpSetPitch(temp_s0_2, scaled);
}
