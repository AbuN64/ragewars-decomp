#ifndef MENU_80409A88_H
#define MENU_80409A88_H
#include "TYPES.H"
struct RecordRecAt20V1 {
    char pad[0x20];
    struct ObjRecAtB0 *inner;
};
struct RecordRecAtCV1 {
    char pad[0xC];
    struct Target_func_8040A77C_de *target;
};
struct RecordRecAt20V2 {
    char pad[0x1C];
    s32 result;
    struct PakMenuSlot *inner;
};
/* The pak preview block D_800E28BC: a position, a packed value and the colour depth. */
struct PakPreview {
    char pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    char pad18[0x1C - 0x18];
    s32 value; /* shown shifted down eight bits */
    char pad20[0x24 - 0x20];
    s32 handle;
    char pad28[0x90 - 0x28];
    unsigned int depth;
};
struct RecordRecAt24 {
    char pad[0x1C];
    s32 first;
    s32 second;
    void *resource;
};
#endif
