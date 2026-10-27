#ifndef OVLGAME_8044BD30_H
#define OVLGAME_8044BD30_H
#include "TYPES.H"
#include "COMMON/OBJB.H"
/* The dynamic-light pool: the active list, the free list holding all eight records, and the records. */
struct CGameDynamicLight_t {
    IntrusiveList m_ActiveList;
    IntrusiveList m_FreeList;
    struct CDLight_t m_DLights[8];
};
extern void Ovlgame_InitializeDynamicLightPool(struct CGameDynamicLight_t*arg0);
#endif
