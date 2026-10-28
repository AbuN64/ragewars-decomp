#ifndef SYSTEM_LIST_H
#define SYSTEM_LIST_H
#include "TYPES.H"
#include "COMMON/S1.H"

void func_80255CB8_de(void *list, void *node);
extern IntrusiveList D_801010F8;

extern void func_80255E24_de(void *arg0, s32 arg1, s32 arg2);
extern void func_80255F94_de(IntrusiveList *arg0);
extern void func_80256214_de(IntrusiveList *arg0);
extern void func_802560A4_de(void *arg0, s32 arg1);
extern void func_80255ED8_de(void *list, void *node);
#endif
