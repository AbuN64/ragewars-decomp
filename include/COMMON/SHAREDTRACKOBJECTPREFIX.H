#ifndef COMMON_SHAREDTRACKOBJECTPREFIX_H
#define COMMON_SHAREDTRACKOBJECTPREFIX_H
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"


struct SharedTrackObject;




/* The copied prefix is exactly 0x50 bytes. */
typedef struct SharedTrackObjectPrefix {
    u32 unknown0[2];
    CVector3 position;
    u8 unknown14[0x3C];
} SharedTrackObjectPrefix;

typedef struct SharedTrackObject {
    SharedTrackObjectPrefix prefix;
    u8 unknown50[0x1C];
    f32 yaw;
} SharedTrackObject;

typedef struct SharedTrackCamera {
    u8 unknown0[0x28];
    f32 distance;
    f32 pitch;
    u8 unknown30[8];
    CVector3 position;
} SharedTrackCamera;

/* The two adjacent track constants are consumed at base and base+4. */
struct SharedTrackConstants { f32 amplitude; f32 unit; };
union SharedVectorBits { Triple words; CVector3 vector; };

#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/GROUP.H"


extern s32 D_800E28D0;
extern s32 D_800DE7E8;

extern s32 D_800E28D4;
void func_802A84F8_de(void);

void func_802A8F28_de(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7);
#endif
