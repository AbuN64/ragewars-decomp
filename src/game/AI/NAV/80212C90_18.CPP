#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "AI/SOURCE.H"
#include "AI/ACTOR_SETUP_VERSIONS.H"
#include "TYPES.H"
extern void *func_802A001C_de(void *arg0, int arg1, u32 arg2);

/* Sets up a sound voice from its definition: clears the voice's handle at 0xC and state at 0x100 and
   0x102, takes the definition's three bytes at 0x12, 0xE and 0x10 for the output parameters, and the
   pitch from its word at 0x18 read unsigned for kinds 1 and 4 (with the two level bytes at 0x41 and 0x40
   for kind 1, D_800C2100_de otherwise) or signed short for kind 7; for kinds 1 and 4 the audio mode
   D_801462D0 8 scales the pitch by D_800C2118_de with a floor of (&D_800C2118_de)[1] and no second level,
   and mode 0x20 scales it by D_800C2120_de with second level D_800C2124_de; the pitch is stored shifted up 8
   bits at 0x4 and 0x8 and the levels at 0x10 and 0xCC. */








extern s32 D_801462D0;







void func_802138F0_de(Dest *voice, void *def, ResourceManagerState unused, s32 arg4, u8 *out) {
    s32 send;
    s32 first;
    s32 second;
    f32 pitch;
    f32 level;
    f32 level2;
    f64 wide;
    f32 scaled;
    s32 raw;

    send = 0;
    level = D_800C2100_de;
    level2 = (&D_800C2100_de)[1];
    first = 0;
    second = 0;
    voice->handle = -1;
    voice->pending = 0;
    voice->channel = -1;
    pitch = level;
    if (def != 0) {
        send = ((ActorDefinitionHeader *)def)->send;
        first = ((ActorDefinitionHeader *)def)->first;
        second = ((ActorDefinitionHeader *)def)->second;
        switch (((ActorDefinitionHeader *)def)->kind) {
        case 1:
            raw = ((ActorHealthDefinition *)def)->health;
            wide = raw;
            if (raw < 0) {
                wide += D_800C2108_de;
            }
            level = ((MovementDescriptor *)def)->level;
            level2 = ((MovementDescriptor *)def)->secondaryLevel;
            pitch = wide;
            break;
        case 4:
            raw = ((ActorHealthDefinition *)def)->health;
            wide = raw;
            if (raw < 0) {
                wide += D_800C2110_de;
            }
            pitch = wide;
            break;
        case 7:
            pitch = ((PickupHealthDefinition *)def)->health;
            break;
        }
        if (((ActorDefinitionHeader *)def)->kind == 1 || ((ActorDefinitionHeader *)def)->kind == 4) {
            switch (D_801462D0) {
            case 8:
                scaled = pitch * D_800C2118_de;
                level2 = 0.0f;
                if (scaled < (&D_800C2118_de)[1]) {
                    scaled = (&D_800C2118_de)[1];
                }
                pitch = scaled;
                break;
            case 0x20:
                level2 = D_800C2124_de;
                pitch *= D_800C2120_de;
                break;
            }
        }
    }
    out[3] = send;
    out[1] = first;
    out[2] = second;
    voice->health = pitch;
    voice->level = (s32) level;
    voice->secondaryLevel = (s32) level2;
    voice->health <<= 8;
    voice->maxHealth = voice->health;
}

#ifdef NON_MATCHING
/* Builds an actor record from its source object: clears the 0x170-byte record (keeping the field at
 * 0x68), calls the shared initialiser, installs the two behaviour tables for this version, seeds the
 * position and scale copies, the sentinel indices and the default colour factors, runs the optional first
 * callback, and flags the record when the source asks for it (bit 27 of its word at 0x100). */
typedef struct SetupVec {
    f32 x, y, z;
} SetupVec;
typedef struct SetupDesc {
    u32 pad00;
    u32 flags;
} SetupDesc;
typedef struct SetupSource {
    u8 pad00[8];
    SetupVec pos;
    void *model;
    SetupDesc *desc;
    u8 pad1C[0x50];
    f32 scale;
    u8 pad70[0x90];
    u32 flags;
} SetupSource;
typedef struct SetupActor {
    u32 flags;
    u8 pad04[0xE];
    u8 field12;
    u8 field13;
    s8 sentinel14[4];
    f32 field18;
    s32 words1C[4];
    u8 pad2C[4];
    s32 field30;
    s8 field34;
    s8 field35;
    u8 pad36[0xE];
    s32 field44;
    SetupVec pos48;
    SetupVec pos54;
    f32 field60;
    s32 field64;
    s32 field68;
    s32 words6C[3];
    s32 words78[5];
    f32 field8C;
    f32 field90;
    u8 field94;
    u8 field95;
    s16 field96;
    u8 pad98[4];
    f32 field9C;
    SetupVec posA0;
    s32 fieldAC;
    SetupVec posB0;
    void *modelBC;
    f32 fieldC0;
    f32 fieldC4;
    s16 fieldC8;
    s8 fieldCA;
    u8 fieldCB;
    u8 padCC[4];
    s32 fieldD0;
    s32 fieldD4;
    u8 padD8[0x24];
    s32 fieldFC;
    u8 field100;
    u8 pad101;
    s16 field102;
    u8 pad104[8];
    void *table10C;
    u8 pad110[0xC];
    void *table11C;
    u8 pad120[0x50];
} SetupActor;
typedef struct SetupCallbacks {
    void (*first)(SetupSource *, SetupActor *);
} SetupCallbacks;
typedef char SetupActor_size_check[(sizeof(SetupActor) == 0x170) ? 1 : -1];
typedef char SetupActor_model_check[(((u32)&((SetupActor *)0)->modelBC) == 0xBC) ? 1 : -1];
typedef char SetupActor_field9C_check[(((u32)&((SetupActor *)0)->field9C) == 0x9C) ? 1 : -1];
typedef char SetupActor_fieldFC_check[(((u32)&((SetupActor *)0)->fieldFC) == 0xFC) ? 1 : -1];
typedef char SetupSource_flags_check[(((u32)&((SetupSource *)0)->flags) == 0x100) ? 1 : -1];
extern char ACTOR_TABLE_A;
extern char ACTOR_TABLE_B;
extern f32 D_800C7218;
/* the shared initialiser is declared with five parameters above; this caller also passes the source on the stack */
typedef void (*SetupInitFn)(SetupActor *, SetupDesc *, SetupVec, SetupSource *);
extern f32 func_80275DD4_de(void *, f32, f32);
/* 134/147 words; remaining: target loads actor->flags before the -1 store group (v0 flags, v1 -1), ours loads it after */
void Nav_InitSpawnedActor(SetupSource *source, SetupActor *actor, SetupCallbacks *callbacks) {
    s32 saved;
    void *model;
    f32 default_;

    saved = actor->field68;
    func_802A001C_de(actor, 0, 0x170);
    actor->flags = 0x40;
    actor->field68 = saved;
    ((SetupInitFn)func_802138F0_de)(actor, source->desc, source->pos, source);
    actor->table11C = &ACTOR_TABLE_A;
    actor->table10C = &ACTOR_TABLE_B;
    actor->field34 = -1;
    actor->field35 = -1;
    actor->field30 = 0;
    actor->pos48 = source->pos;
    actor->pos54 = source->pos;
    actor->words6C[0] = 0;
    actor->words6C[1] = 0;
    actor->words6C[2] = 0;
    actor->field60 = source->scale;
    actor->field64 = 0;
    actor->words78[0] = 0;
    actor->words78[1] = 0;
    actor->words78[2] = 0;
    actor->words78[3] = 0;
    actor->words78[4] = 0;
    actor->field8C = source->scale;
    actor->field90 = source->pos.y;
    actor->field9C = source->scale;
    actor->posA0 = source->pos;
    actor->fieldAC = (s32)source->model;
    actor->posB0 = source->pos;
    model = source->model;
    actor->modelBC = model;
    if ((source->desc->flags & 4) && model != 0) {
        actor->posB0.y = func_80275DD4_de(model, actor->posB0.x, actor->posB0.z);
    }
    default_ = D_800C7218;
    actor->fieldCA = -1;
    actor->sentinel14[3] = -1;
    actor->sentinel14[2] = -1;
    actor->flags &= ~1;
    actor->field13 = 0x14;
    actor->fieldC8 = -1;
    actor->field96 = -1;
    actor->field102 = -1;
    actor->sentinel14[0] = -1;
    actor->field95 = 0xFF;
    actor->sentinel14[1] = -1;
    actor->field35 = -1;
    actor->fieldCB = 0;
    actor->fieldD0 = 0;
    actor->fieldD4 = 0;
    actor->field44 = 0;
    actor->field12 = 0;
    actor->words1C[0] = 0;
    actor->words1C[1] = 0;
    actor->words1C[2] = 0;
    actor->words1C[3] = 0;
    actor->field100 = 0;
    actor->field94 = 0;
    actor->fieldFC = 0;
    actor->fieldC0 = default_;
    actor->fieldC4 = default_;
    actor->field18 = default_;
    if (callbacks != 0 && callbacks->first != 0) {
        callbacks->first(source, actor);
    }
    if (source->flags & 0x8000000) {
        actor->fieldCB = 1;
    }
}
#else
INCLUDE_ASM("span_1000", Nav_InitSpawnedActor);
#endif
