#ifndef AI_SOURCE_H
#define AI_SOURCE_H
#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ACTOR_DEFINITION.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARGB_COLOR.H"
#include "COMMON/GFX.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/MANAGER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/MTX.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/RESULTS.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/ALDELAY28.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/CTX.H"
#include "COMMON/AUDIO_LOADDECODEDSAMPLES.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/LABEL.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/MENU_INITIALIZEOPTIONSSCENE.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/SHAREDPLAYER.H"
extern float D_800C2100_de;

extern double D_800C2108_de;

extern double D_800C2110_de;

extern float D_800C20F0_de;

extern float D_800C2124_de;

struct AiTarget;




struct Source;
struct Source {
    u8 pad0;
    s8 first; /* +0x1..0x3: copied from the definition by Actor_ApplyActorDefinition */
    s8 second;
    s8 send;
    u8 pad4[4];
    CVector3 position;
    void *surface; /* +0x14: Actor_InitSpawnedActor ground query */
    ActorDefinitionHeader *definition;
    CVector3 velocity;
    u8 pad28[0x10];
    s32 flags38;
    u8 pad3c[0x30];
    f32 height;
    u8 reserved070[0x90];
    u32 flags; /* +0x100; probe 20261019T012702233005Z */
};

extern int D_8013B368;

extern float D_800C2120_de;

struct IntegerState23C;
struct IntegerState23C {
    unsigned char padding_0[104];
    s32 unk_68;
    unsigned char padding_6C[436];
    s32 unk_220;
    unsigned char padding_224[20];
    s32 unk_238;
};

extern float D_800C2118_de;



struct IntegerState23C;
typedef struct IntegerState23C IntegerState23C;



struct Source;
typedef struct Source Source;



extern f32 InstHdr_GetActorTargetHeight(u8 *player);
#endif
