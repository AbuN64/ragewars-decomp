#ifndef CAMERA_CAMERA_H
#define CAMERA_CAMERA_H
#include "CAMERA/80233920.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
extern void Camera_DrawAndAdvanceMessages(Race*race, RacerViewport*racer);
extern void Camera_DrawViewportBorder(RacerViewport*racer);
extern void Camera_UpdateScreenMessages(struct ScreenMessageOwner*owner, struct ScreenMessagePool*pool);
extern ViewFlags D_80103220;
extern void func_80289084_de(char*, char*);
extern void Camera_AccumulateDistanceScaledShake(CShake *shake, CVector3 position, CVector3 *out);
extern void Camera_AdvanceOverlayFade(Overlay *overlay);
extern void Camera_DrawViewportOverlays(View *entity);
extern void Camera_AnimateViewColorsAndLight(View *actor);
extern void Camera_BlendEnvironmentColors(View *self);
extern void Camera_BuildShakenViewTransform(void *cameraTransform);
extern void Camera_UpdateFrustumBounds(GameplayCamera *camera);
extern void Camera_SetupViewportAndFog(RacerViewport *view);
extern void Camera_DrawWorldViewLayers(char *view, char *world);
extern const unsigned char D_d0_f6a5694fb306509f[13];
extern void Camera_EaseViewportRectangle(GameplayCamera *camera, f32 a, f32 b, f32 c, f32 d);
extern void Camera_DrawActiveViews(Race *race, s32 world);
#endif
