#include "TYPES.H"
typedef struct InteractionDescriptor { s32 kind; char pad4[0x10]; s32 flags; } InteractionDescriptor;
typedef struct InteractionLink { char pad0[0x1C]; s32 flags; char pad20[0x83C]; s32 linked; } InteractionLink;
typedef struct InteractionActor {
    u8 kind; char pad1[0x17]; InteractionDescriptor *descriptor;
    char pad1C[0xE4]; s32 flags; char pad104[0x9C]; InteractionLink *attached;
    char pad1A4[0x34]; InteractionLink *player;
} InteractionActor;
extern u8 D_801462E5;
s32 func_8024D160_de(InteractionActor *actor) {
    s32 flags;
    InteractionLink *link;
    s32 bit;
    switch (actor->descriptor->kind) {
    case 11:
        if (actor->kind == 1 && (actor->flags & 0x300000) != 0) {
            link = actor->player;
            if (D_801462E5 != 0 && link->linked != 0) return 0;
        }
    case 8: return 1;
    case 0: return actor->descriptor->flags & 2;
    case 2:
        if (actor->kind != 1) return 0;
        return actor->flags & 0x10000;
    case 1:
        if (actor->kind != 1 || (actor->flags & 0x2000) == 0) return 0;
        link = actor->attached;
        if (link == 0) return 0;
        bit = link->flags & 0x10000;
        return !bit;
    case 4: case 5: case 7: case 10:
        if (actor->kind == 1) {
            flags = actor->flags;
            if (flags & 0x2000) return flags & 0x10000;
        }
        return 0;
    case 12: return actor->descriptor->flags & 1;
    }
    return 0;
}
