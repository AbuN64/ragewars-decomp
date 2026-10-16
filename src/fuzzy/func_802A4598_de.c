#include "TYPES.H"

typedef struct EffectResource {
    f32 value; char pad04[0xC]; s16 attachment; char pad12[0xD]; u8 first, second;
} EffectResource;
typedef struct EffectActor {
    char pad00[4]; u16 kind; char pad06[0x112]; u32 *flags;
    char pad11C[0x10]; void *owner; char pad130[0xA9]; u8 references;
} EffectActor;
typedef struct EffectList { void *head, *tail; s32 count; } EffectList;
typedef struct EffectNode {
    struct EffectNode *previous, *next; EffectResource *resource;
    void *first, *second; f32 coordinates[2]; void *owner; s32 kind;
    f32 value; s32 field28, field2C, field30, attachment, handle, flags;
    EffectList children; s32 field4C, field50;
} EffectNode;
typedef struct EffectPool { EffectList free, used; } EffectPool;
typedef struct EffectWorld { char pad00[0x751C]; EffectPool pool; } EffectWorld;
typedef struct EffectInstance { char pad00[0xB0]; EffectActor *actor; } EffectInstance;
extern char D_8011FE88;
extern void *D_800CDBD0[];
extern EffectNode *func_8027963C_de(void *);
extern EffectResource *func_8028AFEC_de(void *, s32);
extern void func_802794B0_de(void *);
extern void func_80295E84_de(void *, s32);
extern void func_80283064_de(void *, void *);
extern void func_802727D8_de(void *);
extern EffectInstance *func_802A25D0_de(void *, void *, void *);

void func_802A4598_de(EffectWorld *world, EffectActor *actor, s32 resourceId) {
    EffectNode *node;
    EffectResource *resource;
    void *first, *second;
    f32 matrix[4][4];
    EffectInstance *instance;
    node = 0;
    if (*actor->flags & 0x10000) {
        for (node = world->pool.used.head; node; node = node->next) {
            if (node->owner == actor->owner && node->kind == actor->kind) break;
        }
    }
    if (!node) {
        node = func_8027963C_de(&world->pool);
        if (!node) return;
        resource = func_8028AFEC_de(&D_8011FE88, resourceId);
        first = D_800CDBD0[resource->first];
        second = D_800CDBD0[resource->second];
        func_802794B0_de(&node->children);
        node->flags = 2;
        if (*actor->flags & 0x10000) {
            node->flags = 10;
            node->owner = actor->owner;
            node->kind = actor->kind;
        } else {
            node->owner = actor;
            node->kind = -1;
        }
        node->resource = resource;
        node->first = first;
        node->second = second;
        node->field28 = 0;
        node->value = resource->value;
        node->field4C = 0;
        node->field50 = 0;
        node->field2C = 0;
        node->field30 = 0;
        node->attachment = resource->attachment;
        node->handle = -1;
        if (node->attachment != -1) {
            func_80295E84_de(node->coordinates, node->attachment);
            if (actor) func_80283064_de(actor, node->coordinates);
        }
    }
    ++actor->references;
    if (*actor->flags & 0x10000) {
        func_802727D8_de(matrix);
        instance = func_802A25D0_de(world, node, matrix);
        if (instance) instance->actor = actor;
    }
}
