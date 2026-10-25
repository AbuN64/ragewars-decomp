#ifndef FRONTEND_8040B45C_32_H
#define FRONTEND_8040B45C_32_H
#include "COMMON/WIDGETRECAT1A.H"
extern s32 func_8040EBAC_de(struct WidgetNode *node);
extern s32 func_8040EB48_de(struct WidgetNode *node);
extern void func_8040E900_de(struct Widget *record, int enable);
extern s32 func_8040EB68_de(struct WidgetNode *node);
extern void func_8040EBF4_de(struct NodeRecAt16 *node, s32 *x, s32 *y);
extern s32 func_8040EB8C_de(struct WidgetNode *node);
extern void func_8040E978_de(struct Pair14 *record, s16 first, s16 second);
extern void func_8040E984_de(WidgetRecAt1A **hit, WidgetRecAt1A *node, DrawArgs_func_8040E67C_de args, s32 px, s32 py);
extern void func_8040E894_de();
extern void Frontend_SetWidgetFlag40(void *object, int enabled);
#endif
