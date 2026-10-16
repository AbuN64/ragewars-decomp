#include "TYPES.H"

typedef struct DamageDefinition { s32 kind; } DamageDefinition;
typedef struct DamageActor {
    u8 category; char pad01[3]; u16 kind; char pad06[0x12];
    DamageDefinition *definition;
    char pad1C[0xC8]; u16 team; char padE6[0x1A]; u32 flags;
    char pad104[0x14]; u32 *properties;
    char pad11C[0x10]; struct DamageActor *owner;
} DamageActor;
extern u8 D_801462E5;
extern s32 D_8013B290;
extern s32 func_8024D160_de(void *);

s32 func_802661DC_de(DamageActor *source, DamageActor *target) {
    DamageActor *owner;
    s32 allowed, kind;
    if (source == target) return 0;
    if ((source->flags & 0x300000) && !func_8024D160_de(source)) return 0;
    if (target->category == 1) {
        allowed = 1;
        if (!D_801462E5) {
            allowed = 0;
            if (target->team != source->team && (source->flags & 0x310000) &&
                (!D_8013B290 || (target->flags & 0x300000) || (source->flags & 0x300000))) {
                kind = source->definition->kind;
                if (kind == 4 || kind == 1 || kind == 7 || kind == 11) allowed = 1;
            }
        }
        return allowed;
    }
    if (target->category != 2) return 1;
    owner = target->owner;
    if (owner) {
        if (owner->category == 1) {
            allowed = 1;
            if (!D_801462E5) {
                allowed = 0;
                if (owner->team != source->team && (source->flags & 0x310000) &&
                    (!D_8013B290 || (owner->flags & 0x300000) || (source->flags & 0x300000))) {
                    kind = source->definition->kind;
                    if (kind == 4 || kind == 1 || kind == 7 || kind == 11) allowed = 1;
                }
            }
            if (!allowed) return 0;
        }
        if (source == target->owner && (*target->properties & 0x40)) return 0;
    }
    if (target->kind != 0x14) return 1;
    if (source->definition->kind == 1 && source->team == 0xCA) return 0;
    return 1;
}
