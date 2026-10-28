#include "include_asm.h"
#include "COMMON/RESULTS.H"
#include "RENDER/SETN64_ONWORLDVIEWDRAW.H"

/** Perform the no-op callback at VRAM 0x802909D0. */
void SetN64_OnWorldViewDraw(void) {
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80290908[2] = {
    0x1C180134, 0x433A5C50,
};
#endif
