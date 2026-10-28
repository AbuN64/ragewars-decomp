#ifndef COMMON_OBJECTLINKS1458_H
#define COMMON_OBJECTLINKS1458_H
#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
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
#include "COMMON/MEASURED_STORAGE.H"
#include "COMMON/OBJECTLINKS14.H"




extern float D_800C1EE4_de;

struct ObjectLinks1458;
struct ObjectLinks1458 {
    char pad0[0x1454];
    char * unk_1454;
};


struct ObjectLinks1458;
typedef struct ObjectLinks1458 ObjectLinks1458;



struct Actor1DC;
typedef struct Actor1DC Actor1DC;




struct ObjectLinks40;
typedef struct ObjectLinks40 ObjectLinks40;




struct Actor1DC;
struct Actor1DC {
    char pad0[0x1D8];
    char **info;
};





struct Func8020ED50Arg;
struct Func8020ED50Arg {
    char pad0[4];
    s32 field4;
    char pad8[4];
    s32 fieldC;
    s32 field10;
    s32 links[4]; /* 0x14 */
    char pad24[4];
    s32 committed; /* 0x28 */
    char pad2C[0x1BC - 0x2C];
    s32 linkState;
    s32 selection;
    char pad1C4[0x2F4 - 0x1C4];
    s32 releaseFlags[3];
};



struct Func8020ED50Arg;
typedef struct Func8020ED50Arg Func8020ED50Arg;







extern float D_800C1EE0_de;







extern float D_800C1EDC_de;

struct ObjectLinks40;
struct ObjectLinks40 {
    unsigned char padding_0[60];
    Actor1DC *unk_3C;
};




extern s32 Weapon_PickRandomArmedWeapon(void *player);
#endif
