#ifndef RAGEWARS_NAVIGATION_GRAPH_H
#define RAGEWARS_NAVIGATION_GRAPH_H
#include "types.h"
#include "common/types_8a8189af7b05.h"

struct Player;
struct NavigationPlatform;

typedef struct NavigationBuffer { s32 stride; s32 reserved; u8 data[1]; } NavigationBuffer;

typedef struct NavigationPoint { Vec3 position; u16 flags; u16 objectId; } NavigationPoint;

typedef struct NavigationPortal { u16 first, second; u8 kind; } NavigationPortal;

typedef struct NavigationSearchNode {
    s32 key; /* 0x0 */
    f32 value; /* 0x4 */
    s32 state; /* 0x8 */
    u8 padC[0x4];
    struct NavigationSearchNode * next; /* 0x10 */
    u8 pad14[0x4];
    f32 extra; /* 0x18 */
    f32 cost; /* 0x1C */
    f32 estimate; /* 0x20 */
    f32 total; /* 0x24 */
    s32 open; /* 0x28 */
    s32 goal; /* 0x2C */
    struct NavigationSearchNode * parent; /* 0x30 */
    struct Player * object; /* 0x34 */
    u8 pad38[0x8];
    struct NavigationPlatform * platform; /* 0x40 */
    Vec3 endpoint; /* 0x44 */
} NavigationSearchNode;

typedef struct NavigationGraph {
    NavigationBuffer * points; /* 0x0 */
    s32 pointCount; /* 0x4 */
    NavigationBuffer * portals; /* 0x8 */
    s32 portalCount; /* 0xC */
    NavigationBuffer * links; /* 0x10 */
    u8 pad14[0x4];
    s32 result; /* 0x18 */
    f32 value; /* 0x1C */
    s32 selected; /* 0x20 */
    NavigationSearchNode * nodes; /* 0x24 */
    u8 pad28[0x10];
    s32 goals[64]; /* 0x38 */
} NavigationGraph;

/* Resource tables store records with a runtime stride. */
static __inline__ void *navigationRecord(NavigationBuffer *table, s32 index) { return table->data + index * table->stride; }
#endif
