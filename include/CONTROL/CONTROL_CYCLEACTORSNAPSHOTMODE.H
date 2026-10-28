#ifndef CONTROL_CONTROL_CYCLEACTORSNAPSHOTMODE_H
#define CONTROL_CONTROL_CYCLEACTORSNAPSHOTMODE_H
#include "COMMON/LONE/D_8010EC90.H"
#include "COMMON/ACTORRECAT5E0.H"
extern void Control_ResetControllerProfiles(void);
extern void Control_SetControllerMode(s32 a);
extern void Control_SaveControllerSetup(void);
extern void Control_SetMenuControlFlag(void);
extern void Control_CycleActorSnapshotMode(void);
extern void Control_ResetActorSnapshot(void);
extern s32 Control_GetSnapshotActorId(void);
extern void Control_DeactivateActorSnapshot(void);
extern void Control_RestoreActorSnapshot(void);
extern void Control_TickSnapshotCountdown(void);
extern void Control_SaveActorSnapshot(void);
extern void Control_InitializeCurvePlayer(unsigned int *record, unsigned int value);
extern s32 Control_AdvanceEffectCurve(void *);
extern float Control_SampleEffectCurve(PlayerRecAt8 *p);
#endif
