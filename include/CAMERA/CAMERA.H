#ifndef CAMERA_CAMERA_H
#define CAMERA_CAMERA_H
#include "CAMERA/80233920.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/VIEWFLAGS.H"
extern void Camera_DrawAndAdvanceMessages(Race*race, RacerViewport*racer);
extern void Camera_DrawViewportBorder(RacerViewport*racer);
extern void Camera_UpdateScreenMessages(struct ScreenMessageOwner*owner, struct ScreenMessagePool*pool);
extern ViewFlags D_80103220;
extern void func_80289084_de(char*, char*);
#endif
