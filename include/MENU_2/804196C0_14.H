#ifndef MENU_2_804196C0_14_H
#define MENU_2_804196C0_14_H
#include "COMMON/ANIMATION.H"
extern s32 SmpFrameAnim_GetFrameCount(struct FrameSequence *sequence);
extern s32 SmpFrameAnim_DispatchEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void SmpFrameAnim_IgnoreEvent(s32 arg0, struct Triple arg1);
extern s32 SmpFrameAnim_GetLoopCount(struct FrameSequence *sequence);
extern s32 SmpFrameAnim_GetSequenceFrame(struct FrameSequence *sequence);
#endif
