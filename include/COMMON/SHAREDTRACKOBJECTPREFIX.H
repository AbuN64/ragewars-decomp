#ifndef COMMON_SHAREDTRACKOBJECTPREFIX_H
#define COMMON_SHAREDTRACKOBJECTPREFIX_H
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"


struct SharedTrackObject;




/* The copied prefix is exactly 0x50 bytes. */
#include "MENU/TRACK_TYPES.H"





/* The two adjacent track constants are consumed at base and base+4. */



#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/GROUP.H"


extern s32 D_800E28D0;
extern s32 D_800DE7E8;

void OnScreen_SetupTextRendering(void);

void func_802A8F28_de(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7);
#endif
