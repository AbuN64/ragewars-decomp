#ifndef RW_TRACK_TYPES_H
#define RW_TRACK_TYPES_H
#include "types.h"

struct Key_func_80401214_de;
typedef struct Key_func_80401214_de Key_func_80401214_de;

struct Key_func_80401214_de;
struct Key_func_80401214_de {
    char pad0[0x1C];
    f32 time;
    char pad20[4];
};

struct Key_func_80401564_de;
typedef struct Key_func_80401564_de Key_func_80401564_de;

struct Key_func_80401564_de;
struct Key_func_80401564_de {
    f32 x;
    f32 y;
    f32 z;
    f32 pad;
    f32 time;
};

struct Entry_func_804030E0_de;
typedef struct Entry_func_804030E0_de Entry_func_804030E0_de;

struct Entry_func_804030E0_de;
struct Entry_func_804030E0_de {
    s32 id0;
    s32 id4;
    s32 id8;
    s32 flags;
    char pad10[0x28];
    f32 scaleA0; /* record + 0x38, context + 0xA0 */
    f32 aspectRatio; /* record + 0x3C, context + 0xA4 */
    u32 settings[2]; /* context + 0xA8, + 0xAC */
    u32 unknown48;
};

#endif
