#ifndef T2SOUNDELEMENT_T2SOUNDELEMENT_H
#define T2SOUNDELEMENT_T2SOUNDELEMENT_H
#include "COMMON/STATERECAT34.H"
extern void func_8025DE30_de(void);
extern s32 func_8025DEC0_de(s32 trackId, CVector3 soundPosition, s32 spatialMode, s32 ownerId, f32 playbackScale);
extern s32 SoundElement_PlayFlatSound(s32 track);
extern s32 func_8025DFE8_de(s32 index, CVector3 position, s32 voiceParameter);
extern int func_8025E04C_de(int index);
extern s32 func_8025E0F4_de(s32 owner);
extern void func_8025E11C_de(s32 callback);
extern void func_8025E150_de(void);
extern void func_8025E174_de(s32 soundId);
extern void func_8025E19C_de(s32 matchingKey);
extern void func_8025E1C4_de(s32 matchingValue);
extern void func_8025E1EC_de(s32 matchingFlags);
extern void func_8025E214_de(s32 retainedKey);
extern void func_8025E23C_de(void);
#endif
