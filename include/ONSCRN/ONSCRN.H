#ifndef ONSCRN_ONSCRN_H
#define ONSCRN_ONSCRN_H
#include "COMMON/OBJRECAT18V6.H"
extern void OnScreen_DrawBevelBox(s32 x0, s32 y0, s32 x1, s32 y1, s32 border, s32 invert, s32 red, s32 green, s32 blue, s32 alpha);
extern void OnScreen_DrawSpriteNumber(s32 value, f32 x, f32 y, f32 size, f32 scaleY, s32, s32 rightAlign, s32 minDigits);
extern void OnScreen_SetupTextRendering(void);
extern void OnScreen_LoadTextTileModeOne(void);
extern void OnScreen_LoadTextTileModeTwo(void);
#endif
