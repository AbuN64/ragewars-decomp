#ifndef AI_NAV_SEARCH_NODE_STATE_H
#define AI_NAV_SEARCH_NODE_STATE_H
#include "COMMON/OBJECTLINKS14.H"
extern int Nav_OpenSearchNode(void *navigationSearchNode);
extern void Nav_CloseSearchNode(void *object);
extern void Nav_ClearSearchNodeStatus(void *arg0);
extern int Nav_IsSearchNodeClosed(void *navigationSearchNode);
extern int Nav_IsSearchNodeOpen(void *navigationSearchNode);
extern void *Nav_TakeLowestCostOpenNode(void *cNavData);
#endif
