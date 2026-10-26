#ifndef MENU_ITEMS_80442BC8_H
#define MENU_ITEMS_80442BC8_H
#include "MENU/OBJECT1C8.H"
extern void Pak_EnableMenuItemExtra(s16 *record, struct ObjectRecAt478 *object);
extern void Pak_InitMenuItemFromDescriptor(CMenuItem *w, WidgetDescriptor *d, char **arena, int id, int arg);
extern void Pak_StepSpriteFrame(struct Object1C8 *object);
extern void Pak_DrawAnimatedMenuSprite(MenuSpriteElement *e);
extern s32 Pak_GetMirroredMenuFrame(struct ObjectRecAt1C8 *object);
extern s32 Pak_GetMenuItemExtraSize(s16 *record);
#endif
