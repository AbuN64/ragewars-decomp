#ifndef FRONTEND_SMP_OVERLAY_H
#define FRONTEND_SMP_OVERLAY_H
#include "COMMON/MENURECAT24.H"
#include "COMMON/LABEL.H"
extern s32 SmpOverlay_HandlePakDialogChoice(void);
extern s32 SmpOverlay_DispatchPakDialogEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 SmpOverlay_FinishPakDialog(void);
extern void SmpOverlay_ProbePakDialogPorts(void);
#endif
