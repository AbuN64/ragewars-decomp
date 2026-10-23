#ifndef OVLGAME_8044BD30_H
#define OVLGAME_8044BD30_H
#include "TYPES.H"
#include "COMMON/OBJB.H"
/* A list of the pool's eight records and a second, empty list. */
struct CGameDynamicLight_t {
    IntrusiveList empty;
    IntrusiveList records;
    struct PoolRecord entries[8];
};
#endif
