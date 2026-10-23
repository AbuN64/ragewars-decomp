#ifndef MENU_80414430_H
#define MENU_80414430_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
struct Image_func_80419490_de {
    char pad0[8];
    s16 width;
    s16 height;
    char padC[0xC];
    s32 *pixels;
};
struct Command {
    unsigned words[2];
};
union Vtx10 {
    Vtx_t v;
    Vtx_tn n;
    s64 force_structure_alignment;
};
#endif
