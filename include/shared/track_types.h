#ifndef RW_TRACK_TYPES_H
#define RW_TRACK_TYPES_H
#include "TYPES.H"

struct KeyRecAt1C;
typedef struct KeyRecAt1C KeyRecAt1C;

struct KeyRecAt1C;
struct KeyRecAt1C {
    char pad0[0x1C];
    f32 time;
    char pad20[4];
};

struct PositionKey;
typedef struct PositionKey PositionKey;

struct PositionKey;
struct PositionKey {
    f32 x;
    f32 y;
    f32 z;
    f32 pad;
    f32 time;
};

struct EntryRecAt48;
typedef struct EntryRecAt48 EntryRecAt48;

struct EntryRecAt48;
struct EntryRecAt48 {
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
