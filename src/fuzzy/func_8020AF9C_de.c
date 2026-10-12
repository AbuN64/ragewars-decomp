#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef struct Shared_ActorRoomState {
    s32 reserved0;
    s32 current;
    s32 previous;
    s32 fallback;
    s32 reserved10;
    s32 pending;
} Shared_ActorRoomState;
typedef struct Shared_Func80243A80Actor Shared_Func80243A80Actor;
struct Shared_Func80243A80Actor {
    u8 type; /* +0x0: src/func_80243A80.c */
    u8 pad1[7]; /* +0x1: src/func_80243A80.c */
    f32 x; /* +0x8: src/func_80243A80.c */
    f32 y; /* +0xC: src/func_80243A80.c */
    f32 z; /* +0x10: src/func_80243A80.c */
    u16 * collision; /* +0x14: src/func_80243A80.c */
    u8 pad18[4]; /* +0x18: src/func_80243A80.c */
    s32 room; /* +0x1C: src/func_80243A80.c */
    f32 velY; /* +0x20: src/func_80243A80.c */
    s32 room2; /* +0x24: src/func_80243A80.c */
    u8 pad28[12]; /* +0x28: src/func_80243A80.c */
    void * attached; /* +0x34: src/func_80243A80.c */
    u32 flags; /* +0x38: src/func_80243A80.c */
    u8 pad3C[4]; /* +0x3C: src/func_80243A80.c */
    f32 groundY; /* +0x40: src/func_80243A80.c */
    f32 contactX; /* +0x44: src/func_80243A80.c */
    f32 contactBits; /* +0x48: src/func_80243A80.c */
    f32 contactZ; /* +0x4C: src/func_80243A80.c */
    u8 pad50[28]; /* +0x50: src/func_80243A80.c */
    f32 angle; /* +0x6C: src/func_80243A80.c */
    u8 pad70[144]; /* +0x70: src/func_80243A80.c */
    u32 status; /* +0x100: src/func_80243A80.c */
    u8 pad104[0x650 - 0x104];
    s16 pose;
    u8 pad652[0x6D0 - 0x652];
    s32 active;
    u8 pad6D4[0x1450 - 0x6D4];
    s32 roomLock;
    Shared_ActorRoomState *roomState;
};



typedef Shared_Func80243A80Actor Func80243A80Actor;
typedef struct Shared_Func80243A80State Shared_Func80243A80State;
struct Shared_Func80243A80State {
    u32 flags; /* +0x0: src/func_80243A80.c */
    s32 w1; /* +0x4: src/func_80243A80.c */
    s32 w2; /* +0x8: src/func_80243A80.c */
    s32 w3; /* +0xC: src/func_80243A80.c */
    s32 w4; /* +0x10: src/func_80243A80.c */
    s32 w5; /* +0x14: src/func_80243A80.c */
    s32 w6; /* +0x18: src/func_80243A80.c */
};



typedef Shared_Func80243A80State Func80243A80State;

extern f32 D_800C1D54_de;
extern f32 D_800C1D58_de;
extern f32 D_800C1D5C_de;
extern f32 D_800C1D60_de;
extern f32 D_800C1D64_de;

typedef struct RoomBuffer {
    s32 stride;
    s32 reserved;
    u8 records[1];
} RoomBuffer;
typedef struct RoomMap {
    RoomBuffer *rooms;
    s32 roomCount;
    RoomBuffer *portals;
    s32 portalCount;
} RoomMap;
typedef struct RoomRecord {
    Vec3 center;
    u32 flags;
} RoomRecord;
typedef struct RoomPortal {
    u16 first;
    u16 second;
    u8 kind;
} RoomPortal;

s32 func_8024E62C_de(void *);
s32 func_8024DEE0_de(void *);
s32 func_8024DF5C_de(void *);
s32 func_8024DFA0_de(void *);
s32 func_80243A90_de(Func80243A80Actor *, Vec3, u32 *);
extern char D_80103FF0;
extern char D_80104050;
extern char D_80104070;
extern char D_801040D0;

static void copyRoomBytes(void *destination, const void *source, s32 count) {
    u8 *out = destination;
    const u8 *in = source;
    while (count-- > 0) *out++ = *in++;
}

void func_8020AF9C_de(void *mapData, Func80243A80Actor *actor) {
    RoomMap *map = mapData;
    s32 rooms[64], portals[64];
    RoomRecord room;
    RoomPortal portal;
    Vec3 delta, position;
    Func80243A80State query;
    u8 saved[0x50];
    const void *settings;
    f32 distance, best, initialY, absY;
    s32 count = 0, i, chosen, candidate, mode, verticalSeen = 0;
    s32 flags2000 = actor->flags & 0x2000;
    s32 flags1000 = actor->flags & 0x1000;
    for (i = 0; i < 64; i++) rooms[i] = portals[i] = -1;
    chosen = actor->roomState->current;
    copyRoomBytes(&room, map->rooms->records + chosen * map->rooms->stride, sizeof(room));
    delta.x = room.center.x - actor->x;
    delta.y = room.center.y - actor->y;
    delta.z = room.center.z - actor->z;
    best = delta.x * delta.x + delta.z * delta.z;
    if (flags2000 || flags1000) best = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
    initialY = delta.y;
    if (initialY < 0.0f) initialY = -initialY;
    if (actor->roomLock && actor->roomState->pending != -1) {
        mode = func_8024E62C_de(actor);
        if (mode && actor->active == 0) actor->roomState->pending = -1;
        else if (mode || actor->pose == 15 || flags2000) {
            candidate = actor->roomState->pending;
            if (candidate == -1) candidate = actor->roomState->fallback;
            copyRoomBytes(&room, map->rooms->records + candidate * map->rooms->stride, sizeof(room));
            delta.x = room.center.x - actor->x;
            delta.y = room.center.y - actor->y;
            delta.z = room.center.z - actor->z;
            distance = delta.x * delta.x + delta.z * delta.z;
            if (flags2000 || flags1000 || (room.flags & 0x02000000))
                distance = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
            if (distance < best && ((delta.y < 0.0f && -delta.y < D_800C1D54_de) ||
                (delta.y >= 0.0f && delta.y < D_800C1D58_de))) {
                actor->roomState->previous = actor->roomState->current;
                actor->roomState->current = candidate;
            }
            return;
        }
    }
    for (i = 0; i < map->portalCount; i++) {
        copyRoomBytes(&portal, map->portals->records + i * map->portals->stride, sizeof(portal));
        if (portal.first == actor->roomState->current) { rooms[count] = portal.second; portals[count++] = i; }
        if (portal.second == actor->roomState->current) { rooms[count] = portal.first; portals[count++] = i; }
    }
    for (i = 0; i < count; i++) {
        candidate = rooms[i];
        copyRoomBytes(&room, map->rooms->records + candidate * map->rooms->stride, sizeof(room));
        copyRoomBytes(&portal, map->portals->records + portals[i] * map->portals->stride, sizeof(portal));
        if ((room.flags & 0x300000) && !flags1000 && !flags2000) continue;
        delta.x = room.center.x - actor->x;
        delta.y = room.center.y - actor->y;
        delta.z = room.center.z - actor->z;
        distance = delta.x * delta.x + delta.z * delta.z;
        if (flags2000 || flags1000) distance = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
        absY = delta.y;
        if (absY < 0.0f) absY = -absY;
        if (portal.kind == 3 || portal.kind == 10 || portal.kind == 5 || (!flags1000 && (room.flags & 0x20))) {
            if (!(absY < initialY)) continue;
            if (!verticalSeen) { best = D_800C1D60_de; verticalSeen = 1; }
            if (!(distance < best) && best != D_800C1D64_de) continue;
        } else if (!(distance < best)) continue;
        position = room.center;
        position.y += D_800C1D5C_de;
        if (actor->type == 1 && (actor->status & 0x300000)) settings = &D_801040D0;
        else {
            mode = func_8024DEE0_de(actor);
            if (!func_8024DF5C_de(actor)) settings = mode ? &D_80104050 : &D_801040D0;
            else if (!func_8024DFA0_de(actor)) settings = &D_80104070;
            else settings = &D_80103FF0;
        }
        copyRoomBytes(&query, settings, sizeof(query));
        query.flags = 0x4000;
        copyRoomBytes(saved, actor, sizeof(saved));
        mode = func_80243A90_de(actor, position, &query.flags);
        copyRoomBytes(actor, saved, sizeof(saved));
        if (!mode) { best = distance; chosen = candidate; }
    }
    if (actor->roomState->current != chosen) actor->roomState->previous = actor->roomState->current;
    actor->roomState->current = chosen;
}
