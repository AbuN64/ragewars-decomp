#ifndef MENU_PAK_8043F69C_6_H
#define MENU_PAK_8043F69C_6_H
#include "COMMON/TEXTLAYERMETRICS.H"
#include "MENU/8043F69C.H"
#include "COMMON/ITEMRECAT20V1.H"
extern void *Menu_OpenDialog(void *owner, struct Dialog *list, s32 b, s32 c, s32 d);
extern s32 Menu_GetInnerMenuLock(struct Outer *outer);
extern float Menu_GetGlyphAdvance(int c, unsigned char next, float sx, float sy);
extern char *Menu_GetObjectDetailData(struct ObjRecAt20V2 *object);
#endif
