#include "include_asm.h"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "TYPES.H"
#include "SOUND/CODE_8025C544.H"
struct ALSndPlayer;
extern void func_802B2D80_de(struct ALSndPlayer *player);
extern void alSndpSetPan(struct ObjRecAt40V2 *player, u8 pan);
extern s32 func_802B2620_de(void *arg0);
extern void func_802B2F00_de(void *arg0, s16 arg1);

void func_8025C524_de(SlotRecAtB4V2 *arg0, s32 arg1)
{
  s32 *new_var;
  int new_var2;
  s32 temp_s0;
  void *temp_s0_2;
  temp_s0 = (s32)arg0->owner;
  temp_s0_2 = temp_s0 + 0x84;
  new_var2 = 2;
  new_var = &arg0->index;
  func_802B2F00_de(temp_s0_2, ((OwnerCode8025A3EC8025B5F0 *)temp_s0)->samples[*new_var]);
  alSndpSetPan(temp_s0_2, arg1 & 0xFF);
}

void func_8025C578_de(SlotRecAtB4V2 *arg0)
{
  s16 *new_var;
  s32 temp_v1;
  void *temp_s0;
  temp_v1 = (s32)arg0->owner;
  temp_s0 = temp_v1 + 0x84;
  func_802B2F00_de(temp_s0, ((OwnerCode8025A3EC8025B5F0 *)temp_v1)->samples[arg0->index]);
  func_802B2620_de(temp_s0);
}

void func_8025C5BC_de(SlotRecAtB4V2 *arg0) {
    func_802B2D80_de(arg0->owner->sound);
}

extern void func_802B2F00_de(void *arg0, s16 arg1);
extern s32 func_802B2620_de(void *arg0);
extern void alSndpStop(void *arg0);

void func_8025C5DC_de(SlotRecAtB4V2 *arg0) {
    s32 a0;
    void *s1;

    a0 = arg0->owner;
    arg0->active = 1;
    arg0->flag = 0;
    s1 = (void *)(a0 + 0x84);
    if (arg0->key != ((OwnerCode8025A3EC8025B5F0 *)a0)->key) {
        s32 idx = arg0->index;
        s32 addr = a0 + idx * 2;
        func_802B2F00_de(s1, ((OwnerCode8025A3EC8025B5F0 *)a0)->samples[idx]);
        if (func_802B2620_de(s1) != 0) {
            alSndpStop(s1);
        }
        arg0->state = -1;
    }
}

void func_802B25D0_de(void *a, short b);

void func_8025C65C_de(SlotRecAtB4V2 *arg0) {
    void *base;
    Slots *arrayBase;
    short *slot;
    base = arg0->owner;
    arrayBase = &((ContextCode8025A3EC *)base)->slots;
    func_802B25D0_de(((OwnerCode8025A3EC8025B5F0 *)base)->sound, arrayBase->ids[arg0->index]);
    arrayBase->ids[arg0->index] = -1;
    arg0->priority = 0;
    arg0->fieldC = -1;
    arg0->used = -1;
    arg0->value = -1;
    arg0->channel = -1;
    arg0->fieldB4 = -1;
}


typedef struct {
    u16 key;
    u16 start;
    u16 end;
    s16 duration;
    u16 reserved[2];
} Block12;

struct ContextRecAt2BC0;
extern void *Audio_GetMetadataSectionFiveEntry(struct ContextRecAt2BC0 *arg0, s32 arg1);
extern s32 Audio_GetSpatialPanMode(void *arg0);
struct GameplayCamera;
extern s16 func_80259B10_de(void *arg0, struct GameplayCamera *arg1);
extern f32 func_802B2350(s32 arg0);

typedef struct func_8025C6F4_S1 func_8025C6F4_S1;
typedef struct func_8025C6F4_S2 func_8025C6F4_S2;
typedef struct func_8025C6F4_S3 func_8025C6F4_S3;
typedef struct func_8025C6F4_S4 func_8025C6F4_S4;
struct func_8025C6F4_S1 {
    char pad0[0x28];
    s16 unk28;
    char pad28[0x44 - 0x28 - sizeof(s16)];
    char unk44;
    char pad44[0x88 - 0x44 - sizeof(char)];
    s32 unk88;
    char pad88[0x8C - 0x88 - sizeof(s32)];
    Block12 unk8C;
    char pad8C[0x98 - 0x8C - sizeof(Block12)];
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
struct func_8025C6F4_S3 {
    char pad0[0x8E];
    u16 unk8E;
    char pad8E[0x90 - 0x8E - sizeof(u16)];
    u16 unk90;
    char pad90[0x92 - 0x90 - sizeof(u16)];
    s16 unk92;
};
struct func_8025C6F4_S4 {
    char pad0[0x2B94];
    s8 unk2B94;
    char pad2B94[0x2B98 - 0x2B94 - sizeof(s8)];
    s32 unk2B98;
};

void Sound_InitVoiceVolume(func_8025C6F4_S1 *arg0, func_8025C6F4_S2 *arg1) {
    f32 first;
    s16 index;
    s16 value;
    Block12 *record;

    arg0->unk28 = 0x40;
    index = arg1->unkC;
    if (index != -1) {
        record = Audio_GetMetadataSectionFiveEntry(arg0->unkB0, index);
        arg0->unk8C = *record;
        first = func_802B2350(arg0->unk8C.start);
        arg0->unk9C =
            (first - func_802B2350(arg0->unk8C.end)) /
            arg0->unk8C.duration;
        arg0->unk98 =
            func_802B2350(arg0->unk8C.start);
        arg0->unk28 =
            (s16)(s32)func_802B2350(arg0->unk8C.start);
        arg0->unk88 = 1;
        return;
    }

    arg0->unk88 = 0;
    if (arg0->unkA8 < 0x100) {
        if (arg0->unkC0 == 0 &&
            Audio_GetSpatialPanMode(arg0->unkB0) != 0) {
            value = arg0->unkB0->unk2B94;
            goto store_value;
        }
    } else if (arg0->unkC0 == 0 &&
               Audio_GetSpatialPanMode(arg0->unkB0) != 0) {
        value = func_80259B10_de(&arg0->unk44,
            arg0->unkB0->unk2B98);
store_value:
        arg0->unk28 = value;
    }
}
