#ifndef COMMON_ROUND_STATE_VARIANTS_H
#define COMMON_ROUND_STATE_VARIANTS_H
#include "TYPES.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
extern void TextLoad_ResetArtsendTextureState(void), Tengine_UpdateArtsendTexturePreview(void);
extern s32 D_800D2970;
extern f32 D_800CA5C4, D_800C54D8_de;
extern void InitFrontendMenus(void), Tsmos_InitializeEuropeanFrontend(void);
static inline void resetRoundExtra(void) {
#if defined(VERSION_US_REV1)
TextLoad_ResetArtsendTextureState();
#endif
}
static inline void clearRoundExtra(void) {
#if defined(VERSION_US_REV1)
D_800D2970 = 0;
#endif
}
static inline f32 roundTimerConstant(void) {
#if defined(VERSION_US_REV1)
return D_800CA5C4;
#else
return D_800C54D8_de;
#endif
}
/* Round transitions share the platform's player gate and localized messages. */
#if defined(VERSION_DE)
static inline void stopRoundPlatform(void) { InitFrontendMenus(); }
static inline s32 gameplayTransitionEnabled(u8 flag) { return flag; }
extern u8 *D_800D1D60, *D_800D31B8;
static inline u8 *gameplayResetMessage(u8 language) { return D_800D1D60; }
static inline u8 *gameplayReleaseMessage(u8 language) { return D_800D31B8; }
static inline void *gameplayMessageContext(s32 *context) { return &D_80145088; }
#elif defined(VERSION_EU)
static inline void stopRoundPlatform(void) { Tsmos_InitializeEuropeanFrontend(); }
static inline s32 gameplayTransitionEnabled(u8 flag) { return 1; }
extern u8 *D_auto_800E0D24[], *D_800D31B8[];
static inline u8 *gameplayResetMessage(u8 language) { return D_auto_800E0D24[language]; }
static inline u8 *gameplayReleaseMessage(u8 language) { return D_800D31B8[language]; }
static inline void *gameplayMessageContext(s32 *context) { return context; }
#elif defined(VERSION_EU_X)
static inline void stopRoundPlatform(void) { InitFrontendMenus(); }
static inline s32 gameplayTransitionEnabled(u8 flag) { return flag; }
extern u8 *D_800E0C80[], *D_800D31B8[];
static inline u8 *gameplayResetMessage(u8 language) { return D_800E0C80[language]; }
static inline u8 *gameplayReleaseMessage(u8 language) { return D_800D31B8[language]; }
static inline void *gameplayMessageContext(s32 *context) { return context; }
#else
static inline void stopRoundPlatform(void) { InitFrontendMenus(); }
static inline s32 gameplayTransitionEnabled(u8 flag) { return 1; }
extern u8 *D_800D1D60, *D_800D31B8;
static inline u8 *gameplayResetMessage(u8 language) { return D_800D1D60; }
static inline u8 *gameplayReleaseMessage(u8 language) { return D_800D31B8; }
static inline void *gameplayMessageContext(s32 *context) { return &D_80145088; }
#endif
#endif
