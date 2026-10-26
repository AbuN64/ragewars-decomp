#ifndef AUDIO_2_802591C0_H
#define AUDIO_2_802591C0_H
#include "COMMON/STATERECAT34.H"
struct ObjectLinks2B50 {
    unsigned char padding_0[11084];
    void *unk_2B4C;
};
extern s32 Audio_GetVoiceMixValue(struct ContextRecAt2BC0 *arg0);
extern void Audio_SetVoiceMixValue(struct ContextRecAt2BC0 *arg0, s32 arg1);
extern s32 Audio_CountSoundVoices(char *obj, s32 owner);
extern void * Audio_GetSoundPlayer(void *arg0);
extern s32 Audio_PlayDialogGroup(struct ContextRecAt2BC0 *arg0, s32 arg1);
extern void func_80258F50_de(s32 arg0);
extern void func_80258800_de(struct ContextRecAt2BC0 *arg0, s32 arg1);
extern void func_802588D4_de(struct ContextRecAt2BC0 *arg0, s32 arg1);
extern void Audio_StopAudioByMask(struct ContextRecAt2BC0 *arg0, s32 arg1);
extern void func_80258C0C_de(void *arg0, s32 arg1);
#endif
