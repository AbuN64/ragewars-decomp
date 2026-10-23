#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "RENDER_3/802A35C0.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "RENDER_3/RIBBON_DRAW.H"
#include "COMMON/SELF.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/TRIPLE.H"
#include "RENDER_3/802A35C0_3.H"
#include "LISTS/80279520.H"

/* Detaches an entity from linked effects while preserving their transforms and lifetimes; the unsigned offset-to-pointer cast preserves matrix-address scheduling and addition operand order. */
extern void func_8027027C_de(void *,void *),func_80270910_de(void *,void *),func_80272828_de(void *),func_802732D0_de(void *,void *),func_802732EC_de(void *,void *),func_8027347C_de(void *,f32,f32,f32),func_802A25D0_de(void *,Node44 *,void *);

void func_802A3DD4_de(VertexArena *pool, RibbonActor *actor) {
    Morph storage;
    Morph *morph = &storage;
    ObjRecAt28V1 *clock, *next;
    Vtx *vertices;
    u32 count, i;
    s32 edges;
    morph->blends = actor->track->blends;
    morph->count = actor->track->count;
    if (actor->flags & 2) { morph->first = actor->first; morph->second = actor->second; }
    else { morph->first = actor->first; morph->second = actor->first; }
    morph->scaleS = actor->track->scaleS * D_800C5E08_de;
    morph->scaleT = actor->track->scaleT * D_800C5E08_de;
    clock = actor->clock;
    next = clock->next;
    count = actor->track->count;
    edges = count - 1;
    gSPMatrix(D_80110634++, &clock->matrix[D_800D297C], G_MTX_LOAD);
    while (clock != 0 && next != 0 && 0.0f < clock->unk8 && 0.0f < next->unk8) {
        vertices = func_802A56C4_de(pool, count);
        if (vertices == 0) break;
        func_802A274C_de(actor, clock, vertices, &storage);
        gSPVertex(D_80110634++, vertices, count, 0);
        gSPMatrix(D_80110634++, &next->matrix[D_800D297C], G_MTX_LOAD);
        vertices = func_802A56C4_de(pool, count);
        if (vertices == 0) return;
        func_802A274C_de(actor, next, vertices, &storage);
        gSPVertex(D_80110634++, vertices, count, count);
        i = 0;
        while ((s32)i < edges) {
            { Gfx *cmd = D_80110634++;
              cmd->words.w0 = (((i * 2 & 255) << 16) | (((count + i) * 2 & 255) << 8) | ((count + i + 1) * 2 & 255)) | (G_TRI2 << 24);
              cmd->words.w1 = ((i * 2 & 255) << 16) | (((count + i + 1) * 2 & 255) << 8) | ((i + 1) * 2 & 255);
            }
            i++;
        }
        if (actor->track->closed) {
            { Gfx *cmd = D_80110634++;
              cmd->words.w0 = (((i * 2 & 255) << 16) | (((count + i) * 2 & 255) << 8) | (count * 2 & 255)) | (G_TRI2 << 24);
              cmd->words.w1 = ((i * 2 & 255) << 16) | ((count * 2 & 255) << 8);
            }
        }
        clock = next;
        next = clock->next;

    }
}

/* Partial storage views: the named fields are the ones this routine accesses.
   The prefix and intervening bytes retain the observed node and descriptor layout. */





/* Selects a frame using clamping, looping, ping-pong or random playback. */
s32 func_802A4134_de(AnimationFrameState *state,
                     AnimationFrameDefinition *definition, s32 *frame_count) {
    s32 frame = (s32)state->frame;
    s32 *selected = &frame;
    s32 value;

    switch (definition->mode) {
    case 0:
        value = *frame_count - 1;
        if (*selected >= value) {
            *selected = value;
            state->endpoint = (f32)*frame_count;
        }
        break;
    case 1:
        if (*selected >= *frame_count) {
            *selected = *frame_count - 1;
        }
        break;
    case 2:
        *selected %= *frame_count;
        break;
    case 3:
        value = *frame_count * 2 - 2;
        if (value > 0) {
            value = *selected % value;
        } else {
            value = 0;
        }
        *selected = value;
        if (value >= *frame_count) {
            s32 reflected = *frame_count * 2;
            s32 adjusted = value + 2;
            *selected = reflected - adjusted;
        }
        break;
    case 4:
        *selected = func_802744D4_de() % *frame_count;
        break;
    case 5:
        if (state->cached_frame == -1) {
            state->cached_frame = func_802744D4_de() % *frame_count;
        }
        *selected = state->cached_frame;
        break;
    }
    return frame;
}

void func_802A42F4_de(Root752C *arg0, Entity1DC *arg1) {
    f32 sp10[16];
    f32 temp_f1;
    f32 scale;
    f32 var_f0_2;
    s32 temp_v1;
    u8 temp_v0;
    u8 temp_v0_2;
    char *temp_v1_2;
    Entity1DC *temp_v1_3;
    Entity1DC *temp_v1_4;
    struct Shape_typemap_6 *var_a0;
    ChildB4 *var_s0;
    Node44 *var_s1;
    struct Shape_typemap_6 *var_v0;
    var_s1 = arg0->unk_7528;
    if (var_s1 != 0) {
        do {
            temp_v1 = var_s1->unk_3C;
            if (temp_v1 & 8) {
                var_s0 = var_s1->unk_40;
                if (var_s0 != 0) {
loop_4:
                    if (var_s0->unk_B0 == arg1) {
                        if (arg1 != 0) {
                            if (arg1 == (void *)-1) {
                                ((struct ObjectState68 *) (((char *) var_s0) + (D_800D297C << 6)))->unk_28=((struct ObjectState68 *) (((char *) var_s0) + ((D_800D297C ^ 1) << 6)))->unk_28;
                                var_s0->unk_B0 = 0;
                            } else {
                                func_80270910_de(&sp10, (char *)arg1 + ((D_800D297C << 6) + 0x60));
                                scale = D_800C5E28_de;
                                if (arg1->unk_118->unk14 != 0) {
                                    scale = D_800C5E2C_de;
                                }
                                func_8027347C_de(&sp10, scale, scale, scale);
                                func_80272828_de(&sp10);
                                func_802732D0_de(&sp10, var_s0->pos);
                                if (var_s1->unk_3C & 4) {
                                    func_802732EC_de(&sp10, var_s0->rot);
                                } else {
                                    func_8027027C_de(&sp10, (char *)var_s0 + ((D_800D297C << 6) + 0x28));
                                }
                            }
                            var_s0->unk_8 = (f32) var_s1->unk_8->unk_8;
                        }
                        var_s0->unk_B0 = (Entity1DC *)-1;
                    }
                    var_s0 = var_s0->unk_4;
                    if (var_s0 != 0) {
                        goto loop_4;
                    }
                }
            } else if (var_s1->unk_1C == arg1) {
                if (temp_v1 & 2) {
                    unsigned int offset = D_800D297C << 6;
                    char *matrix = (char *)offset;
                    matrix += (unsigned int)arg1;
                    matrix += 0x60;
                    if (var_s1->unk_24 > 0.0f) {
                    func_80270910_de(&sp10, matrix);
                    var_f0_2 = D_800C5E30_de;
                    if (arg1->unk_118->unk14 != 0) {
                        var_f0_2 = D_800C5E34_de;
                    }
                    func_8027347C_de(&sp10, var_f0_2, var_f0_2, var_f0_2);
                    func_80272828_de(&sp10);
                    func_802A25D0_de(&D_801379C0, var_s1, &sp10);
                }
                }
                temp_v1_3 = var_s1->unk_1C;
                if (temp_v1_3 != 0) {
                    if (var_s1->unk_3C & 1) {
                        temp_v0 = temp_v1_3->unk_13B;
                        if (temp_v0 != 0) {
                            temp_v1_3->unk_13B = (u8) (temp_v0 - 1);
                        }
                    }
                    if (var_s1->unk_3C & 2) {
                        temp_v1_4 = var_s1->unk_1C;
                        temp_v0_2 = temp_v1_4->unk_1D9;
                        if (temp_v0_2 != 0) {
                            temp_v1_4->unk_1D9 = (u8) (temp_v0_2 - 1);
                        }
                    }
                }
                var_s1->unk_1C = 0;
                temp_f1 = var_s1->unk_8->unk_4;
                if (var_s1->unk_24 < temp_f1) {
                    var_s1->unk_24 = temp_f1;
                }
            }
            var_s1 = var_s1->unk_4;
        } while (var_s1 != 0);
    }
}

#if defined(VERSION_US_REV1) || defined(NON_MATCHING)
#include "TYPES.H"

typedef struct EffectResource {
    f32 value; char pad04[0xC]; s16 attachment; char pad12[0xD]; u8 first, second;
} EffectResource;
typedef struct FxActor {
    char pad00[4]; u16 kind; char pad06[0x112]; u32 *flags;
    char pad11C[0x10]; void *owner; char pad130[0xA9]; u8 references;
} FxActor;
typedef struct EffectList { void *head, *tail; s32 count; } EffectList;
typedef struct EffectNode {
    struct EffectNode *previous, *next; EffectResource *resource;
    void *first, *second; f32 coordinates[2]; void *owner; s32 kind;
    f32 value; s32 field28, field2C, field30, attachment, handle, flags;
    EffectList children; s32 field4C, field50;
} EffectNode;
typedef struct EffectPool { EffectList free, used; } EffectPool;
typedef struct EffectWorld { char pad00[0x751C]; EffectPool pool; } EffectWorld;
typedef struct EffectInstance { char pad00[0xB0]; FxActor *actor; } EffectInstance;
extern EffectResource *func_8028AFEC_de(void *, s32);
extern void Lists_ClearHeader(void *);
extern void func_80295E84_de(void *, s32);
extern void func_80283064_de(void *, void *);
extern void func_802727D8_de(void *);

static inline EffectNode *FX_FIND_NODE(EffectWorld *world, FxActor *actor) {
    EffectNode *it;
    void *owner = actor->owner;
    s32 kind = actor->kind;
    for (it = world->pool.used.head; it; it = it->next) {
        if (it->owner == owner && it->kind == kind) return it;
    }
    return 0;
}
void func_802A4598_de(EffectWorld *world, FxActor *actor, s32 resourceId) {
    EffectNode *node;
    EffectResource *resource;
    void *first, *second;
    f32 matrix[4][4];
    EffectInstance *instance;
    if (*actor->flags & 0x10000) {
        node = FX_FIND_NODE(world, actor);
    } else {
        node = 0;
    }
    if (!node) {
        node = func_8027963C_de(&world->pool);
        if (node) {
        resource = func_8028AFEC_de(&D_8011FE88, resourceId);
        first = ((void **)D_800CDBD0)[resource->first];
        second = ((void **)D_800CDBD0)[resource->second];
        Lists_ClearHeader(&node->children);
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
        node->value = resource->value;
        node->field28 = 0;
        node->attachment = resource->attachment;
        node->field4C = 0;
        node->field50 = 0;
        node->field2C = 0;
        node->field30 = 0;
        node->handle = -1;
        if (node->attachment != -1) {
            func_80295E84_de(node->coordinates, node->attachment);
            if (actor) func_80283064_de(actor, node->coordinates);
        }
        }
    }
    if (node) {
    ++actor->references;
    if (*actor->flags & 0x10000) {
        func_802727D8_de(matrix);
        instance = ((EffectInstance *(*)(void *, void *, void *))func_802A25D0_de)(world, node, matrix);
        if (instance) instance->actor = actor;
    }
    }
}
#else
INCLUDE_ASM("span_1000", func_802A4598_de);
#endif

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
#ifndef PUSH_GFX
#define PUSH_GFX(w0, w1) do { u32 *cmd_ = (u32 *)D_80110634; cmd_[0] = (w0); cmd_[1] = (u32)(w1); D_80110634 = (void *)(cmd_ + 2); } while (0)
#endif
extern void func_8026D8F8_de(void);
extern void func_80295FF4_de(void);
extern void func_802A339C_de(void *, void *);
extern void func_802A3718_de(void *, void *, void *);
/* Builds a world's ribbon display list once and replays it afterwards: the first call opens a branch list
 * (patched at the end to jump over the body), sets the fixed render state, then updates and draws every ribbon
 * of the world's list at 0x7528 -- those with a negative layer at 0x34 first, positive layers second. */
void func_802A478C_de(void *world, void *camera) {
    void *node;
    s32 pass;
    u32 *start;
    func_8026D8F8_de();
    func_80295FF4_de();
    if (FIELD(void *, world, 0) != 0) {
        PUSH_GFX(0xDE000000, FIELD(void *, world, 0));
        return;
    }
    FIELD(void *, world, 0) = D_80110634;
    PUSH_GFX(0xDE010000, 0);
    PUSH_GFX(0xE7000000, 0);
    func_8026925C_de(0xE);
    func_80268CE0_de(0x1C);
    PUSH_GFX(0xD9F8FB7F, 0);
    PUSH_GFX(0xD9FFFFFF, 0x200004);
    PUSH_GFX(0xE3000A01, 0);
    PUSH_GFX(0xE3000C00, 0x80000);
    PUSH_GFX(0xD7000000, 0);
    for (pass = 0; pass < 2; pass++) {
        for (node = FIELD(void *, world, 0x7528); node != 0; node = FIELD(void *, node, 4)) {
            s32 layer = FIELD(s32, node, 0x34);
            if (pass == 0 ? layer < 0 : layer > 0) {
                if (FIELD(u32, node, 0x3C) & 8) {
                    func_802A354C_de(node);
                }
                if (FIELD(u32, node, 0x3C) & 4) {
                    func_802A339C_de(node, camera);
                }
                if (FIELD(s32, node, 0x48) >= 2) {
                    if (FIELD(s32, node, 0x34) >= 0) {
                        func_802A3718_de(world, node, camera);
                    } else {
                        ((void (*)(void *, void *, void *))func_802A3DD4_de)(world, node, camera);
                    }
                }
            }
        }
    }
    PUSH_GFX(0xDF000000, 0);
    start = FIELD(u32 *, world, 0);
    FIELD(u32 *, world, 0) = start + 2;
    start[0] = 0xDE010000;
    start[1] = (u32)D_80110634;
    PUSH_GFX(0xDE000000, FIELD(void *, world, 0));
}
#else
INCLUDE_ASM("span_1000", func_802A478C_de);
#endif
