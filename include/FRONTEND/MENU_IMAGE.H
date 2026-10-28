#ifndef FRONTEND_MENU_IMAGE_H
#define FRONTEND_MENU_IMAGE_H
#include "FRONTEND/ENTRYRECAT4D4.H"

extern void Frontend_ResetEquipmentFromCharacter();
extern s32 Frontend_CountActiveEquipmentPanels();
extern s32 Frontend_DispatchEquipmentEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void Frontend_SelectEquipmentColumn(s32, s32);
#endif
