#include "span_1000/code_80286050.h"
#pragma once
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028FC98.h"
struct Shared_Pickup;
struct Record14;
struct Actor_func_8028E284_de;
typedef struct Shared_World {
    s32 mode;
    u8 unknown4[0x18];
    s32 resourceBank; /* 0x1C */
    u8 unknown20[0x2C];
    s32 *resourceDirectory; /* 0x4C */
    u8 unknown50[0x1C];
    s32 *modelSections; /* 0x6C */
    s32 *objectSections; /* 0x70 */
    u8 unknown74[4];
    s32 *actorDefinitions; /* 0x78: count followed by record offsets */
    s32 *routeCount; /* +0x7C: PatrolRouteSet */
    void *bitSections; /* 0x80 */
    void *secondaryLevels; /* 0x84 */
    u8 unknown88[0xC];
    struct Table_func_8028B274_de *modelIds; /* 0x94 */
    u8 unknown98[8];
    Table_func_8028CE94_de *records; /* 0xA0 */
    u8 unknownA4[8];
    Table_func_8028CE94_de *actorRecords; /* 0xAC */
    u8 unknownB0[0x38];
    s32 resource;
    u8 unknownEC[0x34];
    s32 counter120;
    s32 counter124;
    u8 system128[0x10];
    struct Actor_func_8028E284_de *actors; /* 0x138 */
    s32 actorCapacity; /* 0x13C */
    s32 actorCount; /* 0x140 */
    u8 unknown144[0x800];
    s32 counter944; /* 0x944 */
    u8 unknown948[0x200];
    s32 counterB48; /* 0xB48 */
    u8 unknownB4C[0x100];
    s32 counterC4C; /* 0xC4C */
    u8 unknownC50[0x200];
    s32 counterE50; /* 0xE50 */
    u8 unknownE54[0x100];
    s32 counterF54; /* 0xF54 */
    u8 unknownF58[0x84];
    s32 counterFDC; /* 0xFDC */
    u8 unknownFE0[0x40];
    s32 counter1020; /* 0x1020 */
    u8 unknown1024[0x80];
    s32 counter10A4; /* 0x10A4 */
    u8 unknown10A8[0x10];
    s32 counter10B8; /* 0x10B8 */
    s32 counter10BC; /* 0x10BC */
    u8 unknown10C0[0x100];
    s32 recordCount; /* 0x11C0 */
    s32 alternateRecordCount; /* 0x11C4 */
    s32 * recordIndex; /* 0x11C8 */
    s32 * alternateRecordIndex; /* 0x11CC */
    struct Record14 * recordArray; /* 0x11D0 */
    struct Record14 * alternateRecordArray; /* 0x11D4 */
    u8 unknown11D8[0x32C];
    s32 counter1504; /* 0x1504 */
    u8 unknown1508[0x600];
    u8 system1B08[0x11778 - 0x1B08];
    World_func_80290238_de system11778;
    u8 unknown15384[0x1B308 - 0x15384];
    f32 elapsed;
    u8 unknown1B30C[0x100];
    s32 level; /* 0x1B40C */
    s32 selectionState; /* 0x1B410 */
    s32 frozen;
    f32 selectionTimer; /* 0x1B418 */
    s32 selectionFlags; /* 0x1B41C */
    u8 unknown1B420[0x14];
    s32 selectionValues[4]; /* 0x1B434 */
    s32 previewState; /* 0x1B444 */
    s32 previewTimer; /* 0x1B448 */
    s32 previewStart; /* 0x1B44C */
    u8 unknown1B450[0x1C4];
    Vec3 offset;
    struct Shared_Pickup *objects[16];
    s32 count;
    struct Actor_func_8028E284_de *specialActors[16]; /* 0x1B664 */
    s32 specialActorCount; /* 0x1B6A4 */
} Shared_World;
extern Shared_World D_8011FE88;
