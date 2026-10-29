#ifndef COMMON_RESOURCELOCKSTATE_H
#define COMMON_RESOURCELOCKSTATE_H
#include "TYPES.H"
/* The resource API retains an unused arena selector. */
void Cache_DrainAndCompactResources(s32 unusedHeap);
#include "COMMON/ITEMRECAT20V1.H"
extern int Cache_QueryResourceEntryCount(void);


extern int Cache_ReadResourceEntryCount(void);


extern int Cache_GetPendingRequestCount(void);




extern int g_resourceEntryCount;

struct NodePair80253E04;
typedef struct NodePair80253E04 NodePair80253E04;

extern int g_resourcePendingRequestCount;

struct NodePair80253E04;

extern int Cache_GetResourceEntryCount(void);



#endif
