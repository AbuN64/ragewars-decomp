#ifndef AUDIO_RAXPLAYER_H
#define AUDIO_RAXPLAYER_H
#include "COMMON/SOUNDVOICEPOOL.H"
#include "AUDIO/SONG_PLAYER_VIEWS.H"
#include "TYPES.H"

extern void Audio_StopDialogPlayer(void *arg0);
extern s32 Audio_ChooseSequenceVariant(void **arg0, s16 id, s16 avoid);
extern void Audio_LoadDialogMetadata(void *arg0, s32 songIndex);
extern void Audio_StopDialogPlayerUnlocked(void *arg0);
extern s32 Audio_StartDialogGroup(PlayerRecAt1E *player, s32 group, f32 scale, int unused3);
#endif
