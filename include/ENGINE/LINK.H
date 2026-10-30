#ifndef ENGINE_LINK_H
#define ENGINE_LINK_H
#include "TYPES.H"
struct WorldSectionCountView {
    char pad0[0x1500];
    s32 sectorCount;
};
struct WorldSectionResourceView {
    unsigned char padding_0[5384];
    s32 *resource;
};
#endif
