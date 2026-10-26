#include "COMMON/CALLBACK.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "RESMGR/8029AA48_12.H"
#include "SCENE/802508E0_13.H"
#include "RESMGR/resmgr_string_memory.H"

/** Store a word through the global pointer at D_8014D0B0. */


void *Cache_AllocateMemory(s32);



void Smos_AllocateControllerContext(void) {
    Callback *callback;
    callback = Cache_AllocateMemory(0xC44);
    D_8014D0B0 = callback;
    XPlus_FillBytes(callback, 0, 0xC44);
}

void Smos_FreeControllerContext(void) {
    Cache_FreeMemory(D_8014D0B0);
    D_8014D0B0 = 0;
}
