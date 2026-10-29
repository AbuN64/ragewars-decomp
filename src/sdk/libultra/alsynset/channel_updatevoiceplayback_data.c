#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "TYPES.H"

s32 alSndpGetState(void *soundPlayer) {
    return (((struct ObjRecAt28V2 *) ((s8 *) ((((struct SoundPlayerStateTableView *) ((s8 *) soundPlayer))->selectedSoundIndex * 0x30) + ((struct SoundPlayerStateTableView *) ((s8 *) soundPlayer))->soundStates)))->state);
}

#if defined(VERSION_US)
char s_ChannelUpdatevoiceplaybackDataRyTEosTText[12] =
    "ry_t\004.eosT\000\000";
#endif
