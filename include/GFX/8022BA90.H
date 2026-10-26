#ifndef GFX_8022BA90_H
#define GFX_8022BA90_H
#include "TYPES.H"
#include "COMMON/MTX.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
struct Player1680 {
    char pad0[0x5DC];
    func_8023945C_S1 *mount;
    char pad5E0[0x1640 - 0x5E0];
    Mtx views[1];
};
#endif
