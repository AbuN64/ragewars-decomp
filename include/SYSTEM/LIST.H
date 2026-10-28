#ifndef SYSTEM_LIST_H
#define SYSTEM_LIST_H
#include "TYPES.H"
#include "COMMON/S1.H"

void func_80255CB8_de(void *list, void *node);
extern IntrusiveList D_801010F8;

extern void func_80255E24_de(void *list, s32 anchorNode, s32 insertedNode);
extern void func_80255F94_de(IntrusiveList *list);
extern void func_80256214_de(IntrusiveList *list);
extern void func_802560A4_de(void *list, s32 nodeToMove);
extern void func_80255ED8_de(void *list, void *node);
#endif
