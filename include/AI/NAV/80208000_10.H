#ifndef AI_NAV_80208000_10_H
#define AI_NAV_80208000_10_H
#include "COMMON/OBJECTLINKS14.H"
extern int Nav_OpenSearchNode(void *arg0);
extern void Nav_CloseSearchNode(void *object);
extern void Nav_ClearSearchNodeStatus(void *arg0);
extern int Nav_IsSearchNodeClosed(void *arg0);
extern int Nav_IsSearchNodeOpen(void *arg0);
extern void *Nav_TakeLowestCostOpenNode(void *arg0);
#endif
