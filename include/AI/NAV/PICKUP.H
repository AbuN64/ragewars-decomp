#ifndef AI_NAV_PICKUP_H
#define AI_NAV_PICKUP_H
#include "COMMON/ACTORREC.H"
extern s32 Nav_AdvancePickupRouteSelection(Selection *sel);
extern s32 Nav_AppendDirectionalRouteStage(SelectionNavAppendDirectionalRouteStage *sel);
extern s32 Nav_InsertPickupRouteNode(SelectionNavAppendDirectionalRouteStage *sel);
#endif
