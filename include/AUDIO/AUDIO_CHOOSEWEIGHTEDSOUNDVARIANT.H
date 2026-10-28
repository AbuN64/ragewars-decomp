#ifndef AUDIO_AUDIO_CHOOSEWEIGHTEDSOUNDVARIANT_H
#define AUDIO_AUDIO_CHOOSEWEIGHTEDSOUNDVARIANT_H
#include "COMMON/STATERECAT34.H"
struct ObjectLinks2B50 {
    unsigned char padding_0[11084];
    void *unk_2B4C;
};
extern s32 Audio_GetVoiceMixValue(struct ContextRecAt2BC0 *context);
extern void Audio_SetVoiceMixValue(struct ContextRecAt2BC0 *context, s32 arg1);
extern s32 Audio_CountSoundVoices(char *obj, s32 owner);
extern void * Audio_GetSoundPlayer(void *arg0);
extern s32 Audio_PlayDialogGroup(struct ContextRecAt2BC0 *arg0, s32 group);
extern void Audio_StopContextDialog(s32 contextAddress);
extern void Audio_StopAudioByKey(struct ContextRecAt2BC0 *context, s32 matchValue);
extern void Audio_StopAudioBySecondaryValue(struct ContextRecAt2BC0 *context, s32 matchValue);
extern void Audio_StopAudioByMask(struct ContextRecAt2BC0 *context, s32 matchMask);
extern void Audio_StopAudioExceptKey(void *context, s32 matchValue);
#endif
