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
    func_802B2D80_de(voiceRecord->owner->sound);
}

extern void func_802B2F00_de(void *arg0, s16 arg1);
extern s32 func_802B2620_de(void *arg0);
extern void alSndpStop(void *arg0);

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

void func_802B25D0_de(void *a, short b);

void func_8025C65C_de(SlotRecAtB4V2 *voiceRecord) {
    void *base;
    Slots *arrayBase;
    short *slot;
    base = voiceRecord->owner;
    arrayBase = &((ContextCode8025A3EC *)base)->slots;
    func_802B25D0_de(((OwnerCode8025A3EC8025B5F0 *)base)->sound, arrayBase->ids[voiceRecord->index]);
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
} Block12;

struct ContextRecAt2BC0;
extern void *Audio_GetMetadataSectionFiveEntry(struct ContextRecAt2BC0 *arg0, s32 arg1);
extern s32 Audio_GetSpatialPanMode(void *arg0);
struct GameplayCamera;
extern s16 func_80259B10_de(void *arg0, struct GameplayCamera *arg1);
extern f32 Menu_ExpandFloatHighWord(s32 arg0);

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
    Block12 *record;

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
        value = func_80259B10_de(&voiceRecord->unk44,
            voiceRecord->unkB0->unk2B98);
store_value:
        voiceRecord->unk28 = value;
    }
}
