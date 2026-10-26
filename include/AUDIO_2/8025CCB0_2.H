#ifndef AUDIO_2_8025CCB0_2_H
#define AUDIO_2_8025CCB0_2_H
#include "COMMON/SOUNDVOICEPOOL.H"
#include "AUDIO_2/8025CCB0.H"
#include "TYPES.H"

extern void Audio_StopDialogPlayer(void *arg0);
extern s32 Audio_ChooseSequenceVariant(void **arg0, s16 id, s16 avoid);
extern void Audio_LoadDialogMetadata(void *arg0, s32 arg1);
extern void Audio_StopDialogPlayerUnlocked(void *arg0);
extern s32 Audio_StartDialogGroup(PlayerRecAt1E *player, s32 group, f32 scale, int arg3);
#endif
