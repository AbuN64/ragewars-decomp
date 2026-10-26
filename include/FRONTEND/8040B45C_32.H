#ifndef FRONTEND_8040B45C_32_H
#define FRONTEND_8040B45C_32_H
#include "COMMON/WIDGETRECAT1A.H"
extern s32 Frontend_AnySiblingFlag40(struct WidgetNode *node);
extern s32 Frontend_CollectSiblingFlags(struct WidgetNode *node);
extern void Frontend_SetWidgetFlag01(struct Widget *record, int enable);
extern s32 Frontend_AnyVisibleSibling(struct WidgetNode *node);
extern void Frontend_SumNodeOffsets(struct NodeRecAt16 *node, s32 *x, s32 *y);
extern s32 Frontend_AnySiblingFlag01(struct WidgetNode *node);
extern void Frontend_SetPairValues(struct Pair14 *record, s16 first, s16 second);
extern void Frontend_FindWidgetAtPoint(WidgetRecAt1A **hit, WidgetRecAt1A *node, DrawArgsFrontendDrawVisibleWidgetClipped args, s32 px, s32 py);
extern void Frontend_ResetTextClipBounds();
extern void Frontend_SetWidgetFlag40(void *object, int enabled);
#endif
