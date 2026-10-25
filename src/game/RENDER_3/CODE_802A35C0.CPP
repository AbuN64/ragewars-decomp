#include "include_asm.h"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "RENDER_3/CODE_802A35C0.H"
#include "RENDER_3/802A35C0.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/OBJRECAT18V6.H"
#include "FX_2/80271B18.H"
#include "gbi.h"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/RESIDENTSTATE.H"
#include "RENDER_3/RIBBON_DRAW.H"

extern void *func_802A5734_de(void *arg0, s32 arg1);

extern void func_802732D0_de(char *object, f32 *output);

extern void func_802732EC_de(void *arg0, f32 *arg1);

extern void func_80271F68_de(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);

extern f32 func_802B72B0_de(f32);

/* Interpolates morph vertex positions and shades between two key frames. */




















/* Rebuilds one morphing mesh's vertices from its two key frames. The blend weight eases in and out
   of the clock's position in the actor's track, and again of the actor's own position in it while
   that is still inside the track; every vertex is then the first frame's position carried that far
   toward the second's, its two texture coordinates are the mesh's own scales times the caller's
   scale and times a fade that steps once a vertex, and its shade is the blend of the vertex's two
   shades. While func_8026E340_de holds, the shade is instead greyed: red and green are cleared and
   blue carries the blended sum of the three channels over three, as an unsigned divide. Written
   from the assembly: the second frame's key is taken before the first frame's sample is read so
   that it lives across that call, and the first shade is reached through its own pointer, which is
   what keeps the blend cursor itself in a register rather than the whole record being addressed
   four bytes on. */




















extern void func_802A5780_de(s32, State_func_802A2FA4_de *, Nodes *);

extern void func_802A5FF0_de(State_func_802A2FA4_de *);

extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);


extern void func_80272B38_de(void *, void *, void *);

extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);

extern void func_802727D8_de(void *);

extern void func_80272CB0_de(void *, f32, f32, f32);

extern void func_802A31E8_de(Node438C *, Node438C *, struct GameplayCamera *, void *);
extern void func_80271F9C_de(void *, void *, f32);
extern void func_8027027C_de(void *, f32 *);

void *func_802A25D0_de(void *arg0, void *arg1, void *local) {
    CVector3 sp10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f1;
    void *temp_s1;
    char *var_s0;
    char *temp_s2;

    temp_s2 = func_802A5734_de(arg0, (s32)arg1);
    var_s0 = temp_s2;
    if (temp_s2 != 0) {
        ((ObjectLinks54 *)(arg1))->unk_50 = 0;
        ((ObjectLinksB4 *)(var_s0))->unk_8 = ((struct ObjectState20 *) ((ObjectLinks54 *) arg1)->unk_8)->unk_8;
        ((ObjectLinksB4 *)(var_s0))->unk_B0 = 0;
        func_802732D0_de(local, &((ObjectLinksB4 *)(var_s0))->unk_10.v0);
        if (((ObjectLinks54 *)(arg1))->unk_3C & 4) {
            func_802732EC_de(local, &((ObjectLinksB4 *)(var_s0))->unk_1C);
        } else {
            func_8027027C_de(local, &((ObjectLinksB4 *)(var_s0))->unk_28);
            func_8027027C_de(local, &((ObjectLinksB4 *)(var_s0))->unk_68);
        }
        temp_s1 = *(void **)var_s0;
        ((ObjectLinksB4 *)(var_s0))->unk_AC.v0 = 0;
        ((ObjectLinksB4 *)(var_s0))->unk_A8 = 0.0f;
        if (temp_s1 != 0) {
            func_80271F68_de(&sp10, &((ObjectLinksB4 *)(var_s0))->unk_10.v1, &((ObjectStateB0 *)(temp_s1))->unk_10);
            temp_f0 = func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
            ((ObjectStateB0 *)(temp_s1))->unk_AC = temp_f0;
            ((ObjectLinks54 *)(arg1))->unk_4C += temp_f0;
        }
        if (((struct ObjectState20 *) ((ObjectLinks54 *) arg1)->unk_8)->unk_1C == 0) {
            if (((ObjectLinks54 *)(arg1))->unk_4C > 0.0f) {
                var_f1 = 0.0f;
                var_s0 = ((ObjectLinks54 *)(arg1))->unk_40;
                if (var_s0 != 0) {
                    do {
                        ((ObjectLinksB4 *)(var_s0))->unk_A8 = var_f1 / ((ObjectLinks54 *)(arg1))->unk_4C;
                        temp_f0_2 = ((ObjectLinksB4 *)(var_s0))->unk_AC.v1;
                        var_s0 = ((ObjectLinksB4 *)(var_s0))->unk_4;
                        var_f1 += temp_f0_2;
                    } while (var_s0 != 0);
                }
            }
        } else {
            if (temp_s1 != 0) {
                ((ObjectLinks54 *)(arg1))->unk_28 += ((ObjectStateB0 *)(temp_s1))->unk_AC * D_800C5DC0_de;
            }
            ((ObjectLinksB4 *)(var_s0))->unk_A8 = ((ObjectLinks54 *)(arg1))->unk_28;
        }
    }
    return temp_s2;
}

void func_802A274C_de(RibbonActor *actor, ObjRecAt28V1 *clock, Vtx *out, Morph *morph) {
    f32 a[3];
    f32 b[3];
    f32 weight;
    f32 t;
    Blend *blend;
    Shade *from;
    Key *key;
    s32 count;
    u32 grey;
    s32 red;
    s32 green;
    s32 blue;

    weight = 0.5f - func_802B6560_de(clock->unk8 / actor->track->total * 3.1415927f) * 0.5f;
    if (actor->time <= actor->track->span) {
        weight = weight * (0.5f - func_802B6560_de(actor->time / actor->track->span * 3.1415927f) * 0.5f);
    }
    count = morph->count;
    blend = morph->blends;
    t = 1.0f - weight;
    while (--count != -1) {
        key = &morph->second[blend->second];
        func_80271F9C_de(a, &morph->first[blend->first], morph->firstFrame);
        func_80271F9C_de(b, key, morph->secondFrame);
        out->x = (s16) (a[0] + t * (b[0] - a[0]));
        out->y = (s16) (a[1] + t * (b[1] - a[1]));
        out->z = (s16) (a[2] + t * (b[2] - a[2]));
        from = &blend->from;
        if (func_8026E340_de() != 0) {
            blue = blend->from.b;
            green = blend->from.g;
            red = blend->from.r;
            grey = (f32) (blue + green + red)
                 + t * (f32) ((blend->to.b - blue) + (blend->to.g - green) + (blend->to.r - red));
            out->r = 0;
            out->g = 0;
            out->b = grey / 3;
            out->a = (u32) ((f32) from->a + t * (f32) (blend->to.a - from->a));
        } else {
            out->r = (u32) ((f32) blend->from.r + t * (f32) (blend->to.r - blend->from.r));
            out->g = (u32) ((f32) blend->from.g + t * (f32) (blend->to.g - blend->from.g));
            out->b = (u32) ((f32) blend->from.b + t * (f32) (blend->to.b - blend->from.b));
            out->a = (u32) ((f32) from->a + t * (f32) (blend->to.a - from->a));
        }
        blend++;
        out++;
    }
}

void func_802A2B58_de(RibbonActor *actor, ObjRecAt28V1 *clock, Vtx *out, f32 scale, Morph *morph) {
    f32 a[3];
    f32 b[3];
    f32 weight;
    f32 t;
    f32 fade;
    Blend *blend;
    Shade *from;
    Key *key;
    s32 count;
    u32 grey;
    s32 red;
    s32 green;
    s32 blue;

    weight = 0.5f - func_802B6560_de(clock->unk8 / actor->track->total * 3.1415927f) * 0.5f;
    if (actor->time <= actor->track->span) {
        weight = weight * (0.5f - func_802B6560_de(actor->time / actor->track->span * 3.1415927f) * 0.5f);
    }
    fade = 0.0f;
    count = morph->count;
    blend = morph->blends;
    t = 1.0f - weight;
    while (--count != -1) {
        key = &morph->second[blend->second];
        func_80271F9C_de(a, &morph->first[blend->first], morph->firstFrame);
        func_80271F9C_de(b, key, morph->secondFrame);
        out->x = (s16) (a[0] + t * (b[0] - a[0]));
        out->y = (s16) (a[1] + t * (b[1] - a[1]));
        out->z = (s16) (a[2] + t * (b[2] - a[2]));
        out->s = (s16) (morph->textureScaleS * scale);
        out->t = (s16) (morph->textureScaleT * fade);
        from = &blend->from;
        if (func_8026E340_de() != 0) {
            blue = blend->from.b;
            green = blend->from.g;
            red = blend->from.r;
            grey = (f32) (blue + green + red)
                 + t * (f32) ((blend->to.b - blue) + (blend->to.g - green) + (blend->to.r - red));
            out->r = 0;
            out->g = 0;
            out->b = grey / 3;
            out->a = (u32) ((f32) from->a + t * (f32) (blend->to.a - from->a));
        } else {
            out->r = (u32) ((f32) blend->from.r + t * (f32) (blend->to.r - blend->from.r));
            out->g = (u32) ((f32) blend->from.g + t * (f32) (blend->to.g - blend->from.g));
            out->b = (u32) ((f32) blend->from.b + t * (f32) (blend->to.b - blend->from.b));
            out->a = (u32) ((f32) from->a + t * (f32) (blend->to.a - from->a));
        }
        blend++;
        out++;
        fade = fade + morph->step;
    }
}

s32 func_802A2FA4_de(s32 owner, State_func_802A2FA4_de *state) {
    LevelActor *object;
    Nodes *node;
    Nodes *next;
    f32 saved_step;
    f32 zero;
    f32 decay;
    f32 cutoff;
    f32 value;
    f32 updated;

    saved_step = D_800D2988;
    if (state->flags & 2) {
        D_800D2988 = saved_step * D_800CD740_de;
    }
    if (state->flags & 1) {
        D_800D2988 *= (&D_800D2988)[1];
    }
    if (state->flags & 8) {
        state->retries++;
        if (state->retries >= 3) {
            state->object = 0;
        }
    }

    if (state->count_up >= 0.0f) {
        state->total += D_800D2988;
    }
    state->timer -= D_800D2988;
    if (state->timer < 0.0f) {
        state->timer = 0.0f;
    }

    node = state->nodes;
    if (node != 0) {
        zero = 0.0f;
        decay = D_800C5DE0_de[1];
        cutoff = D_800C5DE8_de[0];
        do {
            next = node->next;
            if (state->timer <= zero && node->value > zero) {
                node->value = zero;
            }
            value = node->value;
            if (value <= zero) {
                updated = value - decay;
                node->value = updated;
                if (updated < cutoff) {
                    func_802A5780_de(owner, state, node);
                }
            } else {
                updated = value - D_800D2988;
                node->value = updated;
                if (updated < zero) {
                    node->value = zero;
                }
            }
            node = next;
        } while (node != 0);
    }

    object = state->object;
    if (state->object != 0 && (state->flags & 1) &&
        !(object->flags & 0x200)) {
        func_802A5FF0_de(state);
    }
    D_800D2988 = saved_step;

    if (state->active == 0) {
        if (state->timer != 0.0f) {
            if (state->object == 0) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

void func_802A31E8_de(Node438C *arg0, Node438C *arg1, GameplayCamera *camera, void *matrix) {
    f32 setup[4];
    CVector3 first;
    CVector3 basis;
    CVector3 cross;
    CVector3 result;
    f32 neg_y;
    f32 neg_z;

    func_80271F68_de(&first, &arg0->position,
                  &arg1->position);
    func_8027207C_de(&first);
    setup[0] = 0;
    setup[1] = 0;
    setup[2] = D_800C5DE8_de[1];
    func_80272B38_de(&camera->unk1A0, setup, &basis);
    neg_y = -basis.y;
    neg_z = -basis.z;
    basis.y = neg_y;
    basis.z = neg_z;
    func_80271F9C_de(&cross, &basis,
                  basis.x * first.x + neg_y * first.y + neg_z * first.z);
    func_80271F68_de(&cross, &first, &cross);
    func_8027207C_de(&cross);
    func_80272018_de(&result, &basis, &cross);
    func_8027207C_de(&result);
    func_80271F9C_de(&result, &result, arg0->a);
    func_80271F9C_de(&cross, &cross, arg0->b);
    func_80271F9C_de(&basis, &basis, arg0->c);
    func_802727D8_de(matrix);
    ((Matrix *)matrix)->m[0] = result.x;
    ((Matrix *)matrix)->m[1] = result.y;
    ((Matrix *)matrix)->m[2] = result.z;
    ((Matrix *)matrix)->m[4] = cross.x;
    ((Matrix *)matrix)->m[5] = cross.y;
    ((Matrix *)matrix)->m[6] = cross.z;
    ((Matrix *)matrix)->m[8] = basis.x;
    ((Matrix *)matrix)->m[9] = basis.y;
    ((Matrix *)matrix)->m[10] = basis.z;
    ((Matrix *)matrix)->m[12] = arg0->position.x;
    ((Matrix *)matrix)->m[13] = arg0->position.y;
    ((Matrix *)matrix)->m[14] = arg0->position.z;
}

struct GameplayCamera;

void func_802A339C_de(void *arg0, void *camera) {
    f32 matrix[16];
    Node438C *first;
    Node438C *next;
    State802A6DF8 *state = arg0;

    if (state->vertexCount < 2) {
        return;
    }

    first = state->vertices;
    next = first->next;
    if (first != 0) {
        func_80272CB0_de(matrix, first->a, first->b, first->c);
    } else {
        func_802727D8_de(matrix);
    }

    while (first != 0) {
        Node438C *a;
        Node438C *b;

        if (next == 0) {
            break;
        }
        a = first;
        b = next;
        if (first == 0) {
            goto no_pair;
        }
        if (first->position.x != next->position.x || first->position.y != next->position.y) {
            goto boundary;
        }
z_test:
        if (a->position.z != b->position.z) {
            goto boundary;
        }
        a = b;
        b = b->next;
        if (a == 0) {
            goto no_pair;
        }
        if (b == 0 || a->position.x != b->position.x || a->position.y != b->position.y) {
            goto boundary;
        }
        goto z_test;
boundary:
        if (a != 0 && b != 0) {
            func_802A31E8_de(a, b, camera, matrix);
            goto apply;
        }
no_pair:
        {
            matrix[12] = first->position.x;
            matrix[13] = first->position.y;
            matrix[14] = first->position.z;
        }
apply:
        func_8027027C_de(matrix, first->matrices[D_800D297C]);
        first = next;
        next = first->next;
    }

    matrix[12] = first->position.x;
    matrix[13] = first->position.y;
    matrix[14] = first->position.z;
    func_8027027C_de(matrix, first->matrices[D_800D297C]);
}

extern f32 D_800C5DF0_de, D_800C5DF4_de;
extern void func_80270910_de(void *, void *);
extern void func_8027347C_de(void *, f32, f32, f32);
extern void func_80272828_de(void *);
typedef struct LinkNode802A {
    struct LinkNode802A *parent; /* 0x00 */
    struct LinkNode802A *next;   /* 0x04 */
    f32 value;                   /* 0x08 */
    char padC[4];
    CVector3 pos;                /* 0x10 */
    char pad1C[0x0C];
    Matrix matrices[2];         /* 0x28, double buffered */
    char pad_A8[4];
    f32 length;                  /* 0xAC */
    void *source;                /* 0xB0: -1 = copy the other buffer, else the node to follow */
} LinkNode802A;
typedef struct LinkOwner802A {
    char pad0[8];
    f32 *range;      /* 0x08 */
    char pad0C[0x30];
    u32 flags;        /* 0x3C */
    LinkNode802A *head; /* 0x40 */
    char pad44[8];
    f32 totalLength;  /* 0x4C */
} LinkOwner802A;
/* Updates a chain of linked nodes: nodes following a source take its matrix (scaled by a size flag) or copy the
 * other matrix buffer, then each node's distance to its parent is measured and summed into the owner's total. */
static inline void Render_UpdateLinkedSource(LinkOwner802A *owner, LinkNode802A *node, void *source) {
    f32 matrix[16];
    f32 scale;
    func_80270910_de(matrix, (char *)source + (D_800D297C * 64 + 0x60));
    scale = D_800C5DF0_de;
    if (*(s32 *)(*(char **)((char *)source + 0x118) + 0x14) != 0) {
        scale = D_800C5DF4_de;
    }
    func_8027347C_de(matrix, scale, scale, scale);
    func_80272828_de(matrix);
    func_802732D0_de((char *)matrix, &node->pos.x);
    if (owner->flags & 4) {
        func_802732EC_de(matrix, (f32 *)((char *)node + 0x1C));
    } else {
        func_8027027C_de(matrix, node->matrices[D_800D297C].m);
    }
}
void Render_UpdateLinkedNodeTransforms(LinkOwner802A *owner) {
    LinkNode802A *node;
    LinkNode802A *parent;
    void *source;
    s32 changed = 0;
    f32 delta[3];
    owner->totalLength = 0.0f;
    for (node = owner->head; node != 0; node = node->next) {
        source = node->source;
        if (source != 0) {
            if (source == (void *)-1) {
                node->matrices[D_800D297C] = node->matrices[D_800D297C ^ 1];
                node->source = 0;
            } else {
                Render_UpdateLinkedSource(owner, node, source);
            }
            changed = 1;
            node->value = owner->range[2];
        }
        parent = node->parent;
        if (parent != 0) {
            f32 length;
            func_80271F68_de((CVector3 *)delta, &node->pos, &parent->pos);
            length = func_802B72B0_de(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
            parent->length = length;
            owner->totalLength += length;
        }
    }
    if (changed) {
        *(f32 *)((char *)owner + 0x24) = owner->range[0];
    }
}

extern float D_800C5DF8_de, D_800C5DFC, D_800C5E00_de, D_800C5E04_de;
struct Shared_AnimFrame {
    u8 kind;
    u8 unknown1;
    u8 shiftS;
    u8 shiftT;
};
void *func_80295F14_de(s32 *, s32);
void func_80295F78_de(void *, struct Shared_AnimInfo *);
#if defined(VERSION_US_REV1)
void func_80295FB4_us_rev1(s32 *, void *, s32, s32, s32, s32, s32, s32, s32);
#else
void func_802950B4_de(s32 *, void *, s32, s32, s32, s32, s32, s32, s32);
#endif
void func_80253754_de(s32, void *);
s32 func_802A4134_de(AnimationFrameState *state, AnimationFrameDefinition *definition, s32 *frame_count);
/* Draws a textured ribbon: spaces the texture along the tail by length, picks the animation frame, sets the
 * combiner and colours (greyscale on a monochrome camera), then emits two vertex rows per clock node and the
 * triangle strip between them. */
void func_802A3718_de(VertexArena *pool, RibbonActor *actor, GameplayCamera *camera) {
    struct Shared_AnimInfo info;
    Morph storage;
    struct Shared_AnimInfo *anim;
    void *model;
    struct CROMSwoosh_t *track;
    ObjRecAt28V1 *clock, *next, *node;
    Vtx *vertices;
    f32 offset;
    f32 period;
    u32 grey;
    s32 count, edges, i, used, frame;

    track = actor->track;
    used = 0;
    if (track->kind == 2 && 0.0f < actor->length) {
        offset = 0.0f;
        for (node = actor->tail; node != 0; node = node->prev) {
            node->offset = offset / actor->length;
            offset += node->length;
        }
    }
    model = func_80295F14_de(&actor->model, -1);
    if (model == 0) return;
    func_80295F78_de(model, &info);
    anim = &info;
    storage.blends = actor->track->blends;
    storage.count = actor->track->count;
    if (actor->flags & 2) { storage.first = actor->first; storage.second = actor->second; }
    else { storage.first = actor->first; storage.second = actor->first; }
    storage.scaleS = actor->track->scaleS * D_800C5DF8_de;
    storage.scaleT = actor->track->scaleT * D_800C5DF8_de;
    if (anim != 0) {
        storage.textureScaleS = 1 << (anim->frame->shiftS + 5);
        storage.textureScaleS = storage.textureScaleS * actor->track->textureScale - D_800C5DFC;
        storage.textureScaleT = 1 << (anim->frame->shiftT + 5);
        storage.step = D_800C5E00_de / (storage.count - D_800C5E00_de);
    }
    period = D_800C5E04_de;
    while (actor->phase >= period) actor->phase -= period;
    gDPPipeSync(D_80110634++);
    switch (info.frame->kind) {
    case 3:
        func_80268CE0_de(0x29);
        if (camera->monochrome) {
            grey = track->env[0] + track->env[1] + track->env[2];
            gDPSetEnvColor(D_80110634++, 0, 0, grey / 3, 255);
            grey = track->prim[0] + track->prim[1] + track->prim[2];
            gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, grey / 3, 255);
        } else {
            gDPSetEnvColor(D_80110634++, track->env[0], track->env[1], track->env[2], 255);
            gDPSetPrimColor(D_80110634++, 0, 0, track->prim[0], track->prim[1], track->prim[2], 255);
        }
        break;
    case 0:
    case 1:
        func_80268CE0_de(0x28);
        break;
    }
    Render_SetModePreset(0xD);
    clock = actor->clock;
    count = track->count;
    next = clock->next;
    frame = func_802A4134_de((AnimationFrameState *)actor, (AnimationFrameDefinition *)track, &info.count);
#if defined(VERSION_US_REV1)
    func_80295FB4_us_rev1(&actor->model, model, frame, 0, 0xFFFF, 0xFFFF, 0, 0, 0);
#else
    func_802950B4_de(&actor->model, model, frame, 0, 0xFFFF, 0xFFFF, 0, 0, 0);
#endif
    edges = count - 1;
    gSPMatrix(D_80110634++, &clock->matrix[D_800D297C], G_MTX_LOAD);
    while (clock != 0 && next != 0 && 0.0f < clock->unk8 && 0.0f < next->unk8 && used + count * 2 < 32) {
        f32 scale;
        vertices = func_802A56C4_de(pool, count);
        if (vertices == 0) break;
        func_802A2B58_de(actor, clock, vertices, clock->offset, &storage);
        used += count;
        gSPVertex(D_80110634++, vertices, count, 0);
        gSPMatrix(D_80110634++, &next->matrix[D_800D297C], G_MTX_LOAD);
        vertices = func_802A56C4_de(pool, count);
        if (vertices == 0) break;
        scale = next->offset;
        while (clock->offset < scale) scale -= period;
        func_802A2B58_de(actor, next, vertices, scale, &storage);
        used += count;
        gSPVertex(D_80110634++, vertices, count, count);
        for (i = 0; i < edges; i++) {
            Gfx *cmd = D_80110634++;
            cmd->words.w0 = (((i * 2 & 255) << 16) | (((count + i) * 2 & 255) << 8) | ((count + i + 1) * 2 & 255)) | (G_TRI2 << 24);
            cmd->words.w1 = ((i * 2 & 255) << 16) | (((count + i + 1) * 2 & 255) << 8) | ((i + 1) * 2 & 255);
        }
        if (actor->track->closed) {
            Gfx *cmd = D_80110634++;
            cmd->words.w0 = (((i * 2 & 255) << 16) | (((count + i) * 2 & 255) << 8) | (count * 2 & 255)) | (G_TRI2 << 24);
            cmd->words.w1 = ((i * 2 & 255) << 16) | ((count * 2 & 255) << 8);
        }
        clock = next;
        next = clock->next;
    }
    func_80253754_de(0, model);
}
