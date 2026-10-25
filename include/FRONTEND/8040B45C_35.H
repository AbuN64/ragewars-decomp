#ifndef FRONTEND_8040B45C_35_H
#define FRONTEND_8040B45C_35_H
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/SLOTRECATCV1.H"
extern void func_8040F044_de(WidgetRecAtE *a, WidgetRecAtE *b);
extern void func_8040F208_de(void *object, int value);
extern void func_8040F210_de(void *object, int value);
extern int func_8040F570_de(struct Field_u16_14 *a, struct Field_u16_14 *b);
extern void func_8040F568_de();
extern s32 func_8040F160_de(s32 font, u8 *text, s32 length);
extern void func_8040F1FC_de(struct Pair2C *record, u8 first, u8 second);
extern void func_8040F534_de(s32 width, s32 height);
extern void func_8040F218_de(struct QuadRecAt2C *record, s32 first, s32 second, s32 third, s32 fourth);
struct Tree;
extern void Frontend_WrapNodeInParent(struct Tree *node, struct Tree *added);
#endif
