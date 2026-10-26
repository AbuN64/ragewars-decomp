#ifndef FRONTEND_8040B45C_35_H
#define FRONTEND_8040B45C_35_H
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/SLOTRECATCV1.H"
extern void Frontend_SwapWidgetTreePositions(WidgetRecAtE *a, WidgetRecAtE *b);
extern void Frontend_SetObjectWordAt2C(void *object, int value);
extern void Frontend_AssignObjectWordAt2C(void *object, int value);
extern int Frontend_CompareRecordShortValues(struct Field_u16_14 *a, struct Field_u16_14 *b);
extern void Frontend_NoOperation();
extern s32 Frontend_MeasureTextPrefix(s32 font, u8 *text, s32 length);
extern void Frontend_SetRecordBytePair(struct Pair2C *record, u8 first, u8 second);
extern void Frontend_SetDisplayClipBounds(s32 width, s32 height);
extern void Frontend_SetRecordValueQuad(struct QuadRecAt2C *record, s32 first, s32 second, s32 third, s32 fourth);
struct Tree;
extern void Frontend_WrapNodeInParent(struct Tree *node, struct Tree *added);
#endif
