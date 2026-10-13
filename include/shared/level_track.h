#ifndef RW_LEVEL_TRACK_H
#define RW_LEVEL_TRACK_H
#include "common/types_8a8189af7b05.h"
typedef struct Object_func_8044D220_de Object_func_8044D220_de;
struct Object_func_8044D220_de {
    Vec3 pos;
    f32 angle;
    s16 kind;
    s16 pad12;
};
typedef struct Track_func_8044D220_de Track_func_8044D220_de;
struct Track_func_8044D220_de {
    char pad0[0x90];
    s32 resource;
    char pad94[0x138 - 0x94];
    void *unk138;
    s32 unk13C;
    s32 unk140;
    char pad144[0xF58 - 0x144];
    s32 unkF58;
    char padF5C[0x1B40C - 0xF5C];
    s32 unk1B40C;
    char pad1B410[0xC];
    s32 unk1B41C;
    char pad1B420[0x14];
    s32 unk1B434;
    char pad1B438[0x1B614 - 0x1B438];
    f32 unk1B614;
    f32 unk1B618;
    f32 unk1B61C;
};
#endif
