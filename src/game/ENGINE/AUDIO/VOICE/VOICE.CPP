#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AUDIO/8025A3EC.H"
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
#include "include_asm.h"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "VOICE/VOICE.H"
#include "COMMON/S1.H"
#include "COMMON/STATERECAT34.H"
#include "RENDER/8025DE50_6.H"
#include "SYSTEM/80255C40_3.H"

/* 8025A3EC_4.CPP */
/* Releases occupied nonlocal slots unless their value equals the exclusion. */

/* Stops the selected sound slot and sets its release flag; split unsigned offset-to-pointer casts and a one-pass statement group preserve the separate table and offset schedule. */

extern void alSndpPlay(void *);

extern void Channel_InitializeVoicePitchMotion(void *arg0, void *arg1, s32 arg2);

extern void *Audio_GetMetadataSectionFiveEntry(ContextRecAt2BC0 *arg0, s32 arg1);

extern s32 Audio_GetSpatialPanMode(void *arg0);

extern s16 Channel_ComputeListenerRelativePan(void *arg0, GameplayCamera *arg1);

extern void Channel_UpdateVoicePlayback(void *arg0);

/* Returns how strongly a listener at 0x128 hears a source at 0x34: one minus the squared distance over the squared range D_800D0D10 (zero beyond it), shaped by the source's curve at 0x44 as the eighth power, the square or the plain value. */

extern void alSndpSetVol(void *arg0, s16 arg1);

extern void alSndpSetPitch(void *arg0, f32 arg1);

void Audio_StopVoicesExceptKey(RecordRecAt4V6 *record, s32 value)
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

void Audio_InitializeVoiceRecord(void *arg0, int owner, int arg2) {
    RecordCode8025A3EC *slot = arg0;
    float k = D_800C9068;

    slot->f0C = -1;
    slot->f08 = -1;
    slot->f3A = -1;
    slot->f40 = -1;
    slot->fB4 = -1;
    slot->owner = owner;
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

void Audio_InitializeVoicePool(s32 *arg0, s32 arg1) {
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

s32 Audio_GetVoiceSoundState(SlotRecAtB8 *voicePool, s16 slotIndex)
{
  s32 voiceAddress;
  s32 ownerAddress;
  void *soundPlayer;
  RecordCode8025A3EC *slot;
  OwnerCode8025A3EC8025B5F0 *owner;
  voiceAddress = (slotIndex * 0xCC) + (s32)voicePool;
  voiceAddress = voiceAddress + 4;
  slot = (RecordCode8025A3EC *)voiceAddress;
  ownerAddress = slot->owner;
  owner = (OwnerCode8025A3EC8025B5F0 *)ownerAddress;
  soundPlayer = owner->sound;
  func_802B2F00_de(soundPlayer, owner->samples[slot->index]);
  return func_802B2620_de(soundPlayer);
}

void Audio_PlayVoiceSound(SlotRecAtB8 *base, s16 index)
{
  unsigned int offset = index * (sizeof(SlotRecAtB8));
  unsigned int entry = offset;
  SlotRecAtB8 *slots;
  SlotRecAtB8 *selected;
  entry += (unsigned int) base;
  slots = base;
 do { alSndpPlay(0x84 + ((SlotRecAtB8 *) entry)->owner); entry = (unsigned int) slots; entry += offset; selected = (SlotRecAtB8 *) entry; } while (0);
  selected->flags |= 8;
}

s32 Audio_ReleaseMatchingExclusiveVoice(RecordD90 *record, s16 value, s16 id) {
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

s32 Audio_HasVoiceWithKey(RecordRecAt4V3 *record, s32 value) {
    s32 i;
    SlotRecAtA8 *slot = record->slots;

    for (i = 0; i < 16; i++, slot++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            return 1;
        }
    }
    return 0;
}

void Audio_StopVoiceSlot(s32 arg0, s16 arg1) {
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

void Audio_ClearVoiceFlags(s32 a) {
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

void Audio_SetVoicePositionTracking(void *arg0, void *arg1, int arg2) {
    ((struct ViewChannelUpdateVoicePlayback *)(arg0))->position = *(Triple *)arg1;
    ((struct ViewChannelUpdateVoicePlayback *)(arg0))->tracked = (Triple *)arg2;
}

void Audio_SetVoiceTrackId(void *arg0, int newTrackId) {
    ((struct ViewChannelUpdateVoicePlayback *)(arg0))->trackId = newTrackId;
}

void Audio_InitializeVoiceParameters(void *arg0, void *desc, s32 extra) {
    f32 first;
    s16 index;
    s16 value;
    void *record;

    Channel_InitializeVoicePitchMotion(arg0, desc, extra);
    Channel_InitializeVoiceMix(arg0, desc, extra);
    ((struct ViewChannelUpdateVoicePlayback *)(arg0))->priority = 0x40;
    index = ((struct Shared_Body *)(desc))->kind;
    if (index != -1) {
        record = Audio_GetMetadataSectionFiveEntry(((struct ViewChannelUpdateVoicePlayback *)(arg0))->context, index);
        ((struct ViewChannelUpdateVoicePlayback *)(arg0))->envelope = *(SoundEnvelope *)record;
        first = RW_BITS_TO_FLOAT(((struct ViewChannelUpdateVoicePlayback *)(arg0))->envelope.initial);
        ((struct ViewChannelUpdateVoicePlayback *)(arg0))->step =
            (first - RW_BITS_TO_FLOAT(((struct ViewChannelUpdateVoicePlayback *)(arg0))->envelope.target)) /
            ((struct ViewChannelUpdateVoicePlayback *)(arg0))->envelope.frames;
        ((struct ViewChannelUpdateVoicePlayback *)(arg0))->value =
            RW_BITS_TO_FLOAT(((struct ViewChannelUpdateVoicePlayback *)(arg0))->envelope.initial);
        ((struct ViewChannelUpdateVoicePlayback *)(arg0))->priority =
            (s16)(s32)RW_BITS_TO_FLOAT(((struct ViewChannelUpdateVoicePlayback *)(arg0))->envelope.initial);
        ((struct ViewChannelUpdateVoicePlayback *)(arg0))->sweeping = 1;
        return;
    }

    ((struct ViewChannelUpdateVoicePlayback *)(arg0))->sweeping = 0;
    if (((struct ViewChannelUpdateVoicePlayback *)(arg0))->trackId < 0x100) {
        if (((struct ViewChannelUpdateVoicePlayback *)(arg0))->fixed == 0 &&
            Audio_GetSpatialPanMode(((struct ViewChannelUpdateVoicePlayback *)(arg0))->context) != 0) {
            value = (s8)((ContextRecAt2BC0 *)((struct ViewChannelUpdateVoicePlayback *)arg0)->context)->randomPan;
            goto store_value;
        }
    } else if (((struct ViewChannelUpdateVoicePlayback *)(arg0))->fixed == 0 &&
               Audio_GetSpatialPanMode(((struct ViewChannelUpdateVoicePlayback *)(arg0))->context) != 0) {
        value = Channel_ComputeListenerRelativePan(&((struct ViewChannelUpdateVoicePlayback *)(arg0))->position,
            ((struct ViewChannelUpdateVoicePlayback *)arg0)->context->result);
store_value:
        ((struct ViewChannelUpdateVoicePlayback *)(arg0))->priority = value;
    }
}

void Audio_UpdateVoicePool(void **arg0) {
    s32 i;
    s32 var_s2;
    char *view;

    var_s2 = 0;
    view = (char *)((RecordD90 *)arg0)->slots;
    i = 0;
    do {
        if (((SlotCC *)view)->used != -1 && ((HeaderRecAt102 *)(*arg0))->local != i) {
            Channel_UpdateVoicePlayback(view);
            var_s2 += 1;
        }
        i += 1;
        view += 0xCC;
    } while (i < 0x10);
    D_800CBAFC = var_s2;
    if (D_800CBB00 < var_s2) {
        D_800CBB00 = var_s2;
    }
}

/* Returns the index of the first of sixteen 0xCC-byte slots at 0xC that is in use, is not the
   owner's own slot and whose two keys at 0xA0 and 0xAC equal the arguments, or -1 when none does; indexing from the second key reproduces the reference induction base. */

int Audio_FindVoiceByKeyPair(ObjRecAtCV4 *obj, int keyA, int keyB) {
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

void Audio_StopVoicesByKey(RecordRecAt4V6 *record, s32 value) {
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

void Audio_StopVoicesBySecondaryValue(RecordRecAt4V5 *record, s32 value) {
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

void Audio_StopVoicesByFlags(RecordRecAt4V4 *record, s32 value) {
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

f32 Audio_ComputeDistanceAttenuation(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    f32 distSq = (dx * dx) + (dy * dy) + (dz * dz);
    if (D_800D0D10 <= distSq) {
        return 0.0f;
    }
    return D_800C3F88_de - (distSq / D_800D0D10);
}

/* Returns whether any of the seventeen occupied slots of a record, other than the one its header marks as local, holds the given value at slot offset 0xA8. Adapted from Audio_HasVoiceWithKey with the slot count changed from 16 to 17. */

s32 Audio_HasVoiceOrReservedSlotWithKey(RecordRecAt4V3 *record, s32 value) {
    s32 i;
    SlotRecAtA8 *slot = record->slots;

    for (i = 0; i < 17; i++, slot++) {
        if (slot->used != -1 && record->header->local != i && slot->value == value) {
            return 1;
        }
    }
    return 0;
}

f32 Audio_InterpolatePitchTable(f32 arg0)
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

s16 Audio_RandomizeSignedRange(s16 arg0, s16 arg1) {
    f32 temp_f20;
    f32 temp_f21;
    temp_f21 = (f32)arg1;
    temp_f20 = (f32)arg0;
    return (s16)(s32)(GraphU64_RandomBetween(temp_f21, temp_f20) < 0.0f
                          ? temp_f20 - GraphU64_RandomBetween(temp_f21, temp_f20)
                          : temp_f20 + GraphU64_RandomBetween(temp_f21, temp_f20));
}

f32 Audio_RandomizeScaledByteRange(u8 arg0, u8 arg1) {
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
    return first + GraphU64_RandomFloat(second - first);
}

f32 Audio_ComputeSpatialAttenuationCurve(char *source, char *listener)
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

void Audio_SetScaledVoiceVolume(void *arg0, s32 arg1) {
    RecordCode8025A3EC *slot = arg0;
    OwnerCode8025A3EC8025B5F0 *owner;
    s32 temp_s0;
    void *sound;

    temp_s0 = slot->owner;
    owner = (OwnerCode8025A3EC8025B5F0 *)temp_s0;
    sound = owner->sound;
    func_802B2F00_de(sound, owner->samples[slot->index]);
    alSndpSetVol(sound, (s16)(s32)((f32) arg1 * (slot->fC8)));
}

void Audio_SetScaledVoicePitch(void *arg0, f32 arg1) {
    RecordCode8025A3EC *slot = arg0;
    OwnerCode8025A3EC8025B5F0 *owner;
    s32 temp_s0;
    void *sound;
    f32 scaled;

    temp_s0 = slot->owner;
    owner = (OwnerCode8025A3EC8025B5F0 *)temp_s0;
    sound = owner->sound;
    func_802B2F00_de(sound, owner->samples[slot->index]);
    scaled = arg1 * (slot->f34);
    scaled = scaled * (slot->fB8);
    alSndpSetPitch(sound, scaled);
}

/* CODE_8025C544.CPP */
struct ALSndPlayer;

extern void alSndpSetPan(struct ObjRecAt40V2 *player, u8 pan);

void func_8025C524_de(SlotRecAtB4V2 *voiceRecord, s32 panValue)
{
  s32 *new_var;
  int new_var2;
  s32 ownerAddress;
  void *soundPlayer;
  ownerAddress = (s32)voiceRecord->owner;
  soundPlayer = ownerAddress + 0x84;
  new_var2 = 2;
  new_var = &voiceRecord->index;
  func_802B2F00_de(soundPlayer, ((OwnerCode8025A3EC8025B5F0 *)ownerAddress)->samples[*new_var]);
  alSndpSetPan(soundPlayer, panValue & 0xFF);
}

void func_8025C578_de(SlotRecAtB4V2 *voiceRecord)
{
  s16 *new_var;
  s32 ownerAddress;
  void *soundPlayer;
  ownerAddress = (s32)voiceRecord->owner;
  soundPlayer = ownerAddress + 0x84;
  func_802B2F00_de(soundPlayer, ((OwnerCode8025A3EC8025B5F0 *)ownerAddress)->samples[voiceRecord->index]);
  func_802B2620_de(soundPlayer);
}

void func_8025C5BC_de(SlotRecAtB4V2 *voiceRecord) {
    alSndpPlay(voiceRecord->owner->sound);
}

void func_8025C5DC_de(SlotRecAtB4V2 *voiceRecord) {
    s32 a0;
    void *s1;

    a0 = voiceRecord->owner;
    voiceRecord->active = 1;
    voiceRecord->flag = 0;
    s1 = (void *)(a0 + 0x84);
    if (voiceRecord->key != ((OwnerCode8025A3EC8025B5F0 *)a0)->key) {
        s32 idx = voiceRecord->index;
        s32 addr = a0 + idx * 2;
        func_802B2F00_de(s1, ((OwnerCode8025A3EC8025B5F0 *)a0)->samples[idx]);
        if (func_802B2620_de(s1) != 0) {
            alSndpStop(s1);
        }
        voiceRecord->state = -1;
    }
}

void alSndpDeallocate(void *a, short b);

void func_8025C65C_de(SlotRecAtB4V2 *voiceRecord) {
    void *base;
    Slots *arrayBase;
    short *slot;
    base = voiceRecord->owner;
    arrayBase = &((ContextCode8025A3EC *)base)->slots;
    alSndpDeallocate(((OwnerCode8025A3EC8025B5F0 *)base)->sound, arrayBase->ids[voiceRecord->index]);
    arrayBase->ids[voiceRecord->index] = -1;
    voiceRecord->priority = 0;
    voiceRecord->fieldC = -1;
    voiceRecord->used = -1;
    voiceRecord->value = -1;
    voiceRecord->channel = -1;
    voiceRecord->fieldB4 = -1;
}

typedef struct {
    u16 key;
    u16 start;
    u16 end;
    s16 duration;
    u16 reserved[2];
} VoiceEnvelopeBlock;

struct ContextRecAt2BC0;
struct GameplayCamera;

typedef struct func_8025C6F4_S1 func_8025C6F4_S1;
typedef struct func_8025C6F4_S2 func_8025C6F4_S2;
typedef struct func_8025C6F4_S4 func_8025C6F4_S4;
struct func_8025C6F4_S1 {
    char pad0[0x28];
    s16 unk28;
    char pad28[0x44 - 0x28 - sizeof(s16)];
    char unk44;
    char pad44[0x88 - 0x44 - sizeof(char)];
    s32 unk88;
    char pad88[0x8C - 0x88 - sizeof(s32)];
    VoiceEnvelopeBlock unk8C;
    char pad8C[0x98 - 0x8C - sizeof(VoiceEnvelopeBlock)];
    f32 unk98;
    char pad98[0x9C - 0x98 - sizeof(f32)];
    f32 unk9C;
    char pad9C[0xA8 - 0x9C - sizeof(f32)];
    s32 unkA8;
    char padA8[0xB0 - 0xA8 - sizeof(s32)];
    func_8025C6F4_S4 *unkB0;
    char padB0[0xC0 - 0xB0 - sizeof(void*)];
    s32 unkC0;
};
struct func_8025C6F4_S2 {
    char pad0[0xC];
    s16 unkC;
};
struct func_8025C6F4_S4 {
    char pad0[0x2B94];
    s8 unk2B94;
    char pad2B94[0x2B98 - 0x2B94 - sizeof(s8)];
    s32 unk2B98;
};

void Audio_InitVoiceVolume(func_8025C6F4_S1 *voiceRecord, func_8025C6F4_S2 *soundDescriptor) {
    f32 first;
    s16 index;
    s16 value;
    VoiceEnvelopeBlock *record;

    voiceRecord->unk28 = 0x40;
    index = soundDescriptor->unkC;
    if (index != -1) {
        record = Audio_GetMetadataSectionFiveEntry(voiceRecord->unkB0, index);
        voiceRecord->unk8C = *record;
        first = Menu_ExpandFloatHighWord(voiceRecord->unk8C.start);
        voiceRecord->unk9C =
            (first - Menu_ExpandFloatHighWord(voiceRecord->unk8C.end)) /
            voiceRecord->unk8C.duration;
        voiceRecord->unk98 =
            Menu_ExpandFloatHighWord(voiceRecord->unk8C.start);
        voiceRecord->unk28 =
            (s16)(s32)Menu_ExpandFloatHighWord(voiceRecord->unk8C.start);
        voiceRecord->unk88 = 1;
        return;
    }

    voiceRecord->unk88 = 0;
    if (voiceRecord->unkA8 < 0x100) {
        if (voiceRecord->unkC0 == 0 &&
            Audio_GetSpatialPanMode(voiceRecord->unkB0) != 0) {
            value = voiceRecord->unkB0->unk2B94;
            goto store_value;
        }
    } else if (voiceRecord->unkC0 == 0 &&
               Audio_GetSpatialPanMode(voiceRecord->unkB0) != 0) {
        value = Channel_ComputeListenerRelativePan(&voiceRecord->unk44,
            voiceRecord->unkB0->unk2B98);
store_value:
        voiceRecord->unk28 = value;
    }
}

/* 8025C544_2.CPP */
static inline short slot_id(Slots *slots, int index) {
    return slots->ids[index];
}

extern s32 SoundElement_PlaySoundAtPosition(s16 arg0, CVector3 position, s32 arg4, s32 arg5);

int func_8025C824_de(RecordRecAt4V4 *pool, short index) {
    SlotRecAtB4V2 *entry;
    ContextCode8025A3EC *context;
    Slots *slots;
    void *owner;

    entry = &pool->slots[index + 1];
    entry--;
    owner = entry->owner;
    context = owner;
    slots = &context->slots;
    alSndpDeallocate(entry->owner->sound, slot_id(slots, entry->index));
    slots->ids[entry->index] = -1;
    entry->priority = 0;
    entry->fieldC = -1;
    entry->used = -1;
    entry->value = -1;
    entry->channel = -1;
    entry->fieldB4 = -1;
    return 0;
}

/** Initialize the two object words at offsets 8 and 12 to negative one. */
void func_8025C8C0_de(void *cLoopingSoundData) {
    CLoopingSoundData *voice = cLoopingSoundData;
    voice->state = -1;
    voice->value = -1;
}

void func_8025C8D0_de(void) {
}

void func_8025C8D8_de(void *soundVoicePool, CLoopingSoundData *availableNodes, s32 nodeCount) {
    s32 i;

    func_80255CA0_de(soundVoicePool, 0, 4);
    func_80255CA0_de(&((SoundVoicePool *)soundVoicePool)->playing, 0, 4);
    i = 0;
    if (nodeCount > 0) {
        do {
            func_80255D14_de(soundVoicePool, availableNodes);
            i += 1;
            availableNodes = availableNodes + 1;
        } while (i < nodeCount);
    }
    ((SoundVoicePool *)soundVoicePool)->state = 0;
}

void *func_8025C95C_de(void *voicePool, s32 soundId, CVector3 *soundPosition, void *position, s32 fallback) {
    CLoopingSoundData *node;
    s32 result;

    node = ((SoundVoicePool *)voicePool)->available.head;
    if (node != 0) {
        func_80255ED8_de(voicePool, node);
        func_80255D14_de(&((SoundVoicePool *)voicePool)->playing, node);
        node->state = -1;
        node->value = -1;
        result = SoundElement_PlaySoundAtPosition((s16)soundId, *soundPosition,
                                (s32)position, fallback);
        node->value = result;
        D_800CBB10 = result;
        node->state = soundId;
        node->m_vSoundPos = *soundPosition;
        node->m_vSoundPosPtr = position;
    }
    return node;
}

s32 func_8025CA24_de(void *work, void *wantedNode) {
    void *playingNode;

    if (wantedNode == 0) {
        return 0;
    }

    playingNode = ((SoundVoicePool *)work)->playing.head;
    if (playingNode != 0) {
        do {
            if (playingNode == wantedNode) {
                func_8025E174_de(((CLoopingSoundData *)playingNode)->value);
                D_800CBB14 = ((CLoopingSoundData *)playingNode)->value;
                func_80255ED8_de(&((SoundVoicePool *)work)->playing, playingNode);
                func_80255D14_de(work, playingNode);
                return 1;
            }
            playingNode = ((CLoopingSoundData *)playingNode)->next;
        } while (playingNode != 0);
    }
    return 0;
}

void func_8025CAB0_de(void *voicePool) {
    s32 value;
    SoundVoicePool *pool = voicePool;
    CLoopingSoundData *playingNode;

    playingNode = pool->playing.head;
    if (playingNode != 0) {
        do {
            func_8025E174_de(playingNode->value);
            value = playingNode->value;
            playingNode = playingNode->next;
            D_800CBB18 = value;
        } while (playingNode != 0);
    }
    pool->state = 1;
}

void func_8025CB0C_de(SoundVoicePool *soundVoicePool) {
    s32 playbackHandle;
    CLoopingSoundData *playingNode;

    playingNode = soundVoicePool->playing.head;
    if (playingNode != 0) {
        do {
            playbackHandle = SoundElement_PlaySoundAtPosition((s16)playingNode->state,
                                     playingNode->m_vSoundPos,
                                     (s32)playingNode->m_vSoundPosPtr,
                                     -1);
            playingNode->value = playbackHandle;
            playingNode = playingNode->next;
            D_800CBB1C = playbackHandle;
        } while (playingNode != 0);
    }
    soundVoicePool->state = 0;
}

void func_8025CB88_de(void *soundVoicePool) {
    SoundVoicePool *pool = soundVoicePool;
    CLoopingSoundData *playingNode;

    if (pool->state == 0) {
        playingNode = pool->playing.head;
        if (playingNode != 0) {
            do {
                if (func_8025E0F4_de(playingNode->value) == 0) {
                    playingNode->state = -1;
                    playingNode->value = -1;
                }
                playingNode = playingNode->next;
            } while (playingNode != 0);
        }
    }
}

void func_8025CBEC_de(void *soundVoicePool) {
    CLoopingSoundData *cur;
    CLoopingSoundData *next;
    s32 value;
    SoundVoicePool *pool = soundVoicePool;

    cur = pool->playing.head;
    if (cur != 0) {
        do {
            value = cur->value;
            next = cur->next;
            func_8025E174_de(value);
            cur->state = -1;
            cur->value = -1;
            func_80255ED8_de(&pool->playing, cur);
            func_80255D14_de(&pool->available, cur);
            cur = next;
        } while (cur != 0);
    }
}

/* 8025C544_6.CPP */
/** Return the address of the global state word at D_8011F260. */
s32 *func_8025CC6C_de(void) {
    return &D_8011F260;
}

/** Deliberately perform no work. */
void func_8025CC7C_de(void) {
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8025CC24[3] = {
    0x72000000, 0x00940A00, 0x08001400,
};
#endif

/* 800C9068.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_8025B6F8_C9C68[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025B6F8_C9C68_us_rev1.c */
const unsigned int D_blob_c47a1224be0864d16b8f[1] = {
    0x3F800000,
};
#endif

/* 800C906C.CPP */
/* ROM-grounded data: src/rw_pool_8025B758_C9C6C_us_rev1.c */
const unsigned int D_blob_2f4433e4bee06427c8ee[3] = {
    0x3C360B61, 0x46FA0000, 0x3F800000,
};

/* 800C9078.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_8025C10C_C9C78[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025C10C_C9C78_us_rev1.c */
const unsigned int D_blob_d58ac873383264ce9118[1] = {
    0x3F800000,
};
#endif

/* 800C907C.CPP */
/* ROM-grounded data: src/rw_pool_8025C1CC_C9C7C_us_rev1.c */
const unsigned int D_blob_fe75a13ded2f86ba8f91[2] = {
    0x45BB8000, 0x3C888889,
};

/* 800C9084.CPP */
/* ROM-grounded data: src/rw_pool_8025C2EC_C9C84_us_rev1.c */
const unsigned int D_blob_e7465b1d1ef08856aedf[2] = {
    0x3C23D70A, 0x3F800000,
};

/* 800C908C.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_8025C368_C9C8C[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025C368_C9C8C_us_rev1.c */
const unsigned int D_blob_5ddf429d49c9c14c2026[1] = {
    0x3F800000,
};
#endif
