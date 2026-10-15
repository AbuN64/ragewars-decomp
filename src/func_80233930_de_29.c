#include "span_1000/code_80233920.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_camera.h"
#include "shared/menu_match_globals.h"
#include "span_1000/code_802393F4.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

/* Spawns an emitter record: takes the head of the free list at 0x11D8 into the active list at 0x11EC (or reuses the record at 0x11F0 when none is free) and fills its position, scale, shared value and three rates converted by D_800C8630. */



extern f32 D_800C8630[];

extern void func_80255CB8_de(void *list, void *node);

static inline void set_emitter(Effect33920 *node, f32 a, f32 b, f32 c, f32 scale, s32 value, Vec3 pos)
{
    node->origin = pos;
    node->radius = scale;
    node->x.mode = value;
    node->x.value = a;
    node->y.mode = value;
    node->y.value = b;
    node->z.mode = value;
    node->z.value = c;
}

extern s32 func_8027254C_de(f32 *arg0, f32 arg1);

extern f32 func_802B72B0_de(f32);

/* Posts a text as on-screen messages, one per line: the text (or D_800D7028 when given D_800D7034) is split
 * at newlines and for each non-empty line the oldest message node of the owner's list at 0xF24 is recycled
 * (cleared through func_80239CE0_de, unlinked, and pushed onto the free list at 0xE40 of the pool) and set up
 * as a kind 2 message centred horizontally 80 pixels above the bottom of the screen, scaled by the given
 * size. Returns the last message node. */




extern func_80237E70_G1 D_800D7028;

extern func_80237E70_G1 D_800D7034;

extern s32 D_800E28D0;

extern void func_80239CE0_de(void *arg0);

static inline Message *recycle(void *owner, void *pool) {
    extern void func_80255ED8_de(void *, Message *);
    Message *oldest;

    oldest = ((struct ScreenMessageOwner *)owner)->activeMessages.head;
    if (oldest != 0) {
        func_80239CE0_de(oldest);
        func_80255ED8_de(&((struct ScreenMessageOwner *)owner)->activeMessages, oldest);
        func_80255D14_de(&((struct ScreenMessagePool *)pool)->freeMessages, oldest);
    }
    return oldest;
}

static inline Message *post_lines(void *owner, void *pool, u8 *text, s32 kind, f32 size, s32 target) {
    Message *message;
    s32 height;
    u8 *line;
    u8 *p;

    message = 0;
    if (pool == 0) {
        return message;
    }
    if (text == D_800D7034.unk0) {
        text = D_800D7028.unk0;
    }
    p = text;
    line = p;
    while (*p != 0) {
        p++;
        if (*p == '\n' || *p == 0) {
            if (line != p) {
                message = recycle(owner, pool);
                if (message != 0) {
                    s32 half = D_800E28D0; /* FAKEMATCH */
                    message->kind = kind;
                    message->text = line;
                    message->timer = 0;
                    message->alpha = 1.0f;
                    message->target = target;
                    message->pad20 = 0;
                    message->pad28 = 0;
                    message->pad2C = 0;
                    message->scaleX = 1.0f;
                    message->scaleY = 1.0f;
                    height = (&D_800E28D0)[1]; /* FAKEMATCH */
                    message->x = half / 2;
                    message->y = height - 80;
                    message->size = size * 15.0f;
                }
                line = p + 1;
            }
        }
    }
    return message;
}

void func_802394BC_de(char *obj, f32 a, f32 b, f32 c, f32 scale, s32 value, Vec3 pos)
{
    extern void func_80255ED8_de(void *list, void *node);
    RaceViewportState *state = (void *)obj;
    Effect33920 *node = state->freeEffects.head;
    f32 k;

    if (node != 0) {
        func_80255ED8_de(&state->freeEffects, node);
        func_80255CB8_de(&state->activeEffects, node);
    } else {
        node = state->activeEffects.tail;
    }
    k = D_800C8630[1];
    set_emitter(node, a * k, b * k, c * k, scale, value, pos);
}

void *func_802395A4_de(void *arg0, Vec3 *arg1) {
    extern void func_80271F68_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2);
    Vec3 position;
    GameplayCamera *node;
    void *bestNode;
    f32 bestDist;
    f32 distSq;

    func_8027254C_de(&arg1->x, 20000.0f);
    if (((MenuMatchGlobals *)arg0)->useFallbackCamera != 0) {
        return &((MenuMatchGlobals *)arg0)->fallbackCamera;
    }
    node = ((MenuMatchGlobals *)arg0)->cameras;
    bestDist = D_800C3548_de;
    bestNode = 0;
    if (node != 0) {
        do {
            func_80271F68_de(&position, arg1, &node->position);
            distSq = (position.x * position.x) +
                     (position.y * position.y) +
                     (position.z * position.z);
            if (distSq < bestDist) {
                bestNode = node;
                bestDist = distSq;
            }
            node = node->next;
        } while (node != 0);
    }
    if (bestNode == 0) {
        return &((MenuMatchGlobals *)arg0)->fallbackCamera;
    }
    return bestNode;
}

f32 func_80239678_de(void *arg0, void *arg1) {
    extern void func_80271F68_de(Vec3 *out, void *arg1, void *arg2);
    Vec3 position;
    f32 sum;
    Racer *node;
    f64 divisor;
    s32 count;

    if (((Race *)arg0)->header.views.count == 0) {
        return 0.0f;
    }
    node = ((Race *)arg0)->header.views.head;
    sum = 0.0f;
    if (node != 0) {
        do {
            func_80271F68_de(&position, &((GameplayCamera *)node)->position, arg1);
            sum += func_802B72B0_de(
                (position.x * position.x) +
                (position.y * position.y) +
                (position.z * position.z));
            node = node->next;
        } while (node != 0);
    }
    count = ((Race *)arg0)->header.views.count;
    divisor = (f64)count;
    if (count < 0) {
        divisor += D_800C3550_de;
    }
    return sum / (f32)divisor;
}

void *func_80239740_de(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool, u8 *text) {
    struct Message *temp_v0 = func_80237E80_de(owner, pool, text);
    if (temp_v0 != 0) {
        temp_v0->pad20 = 1;
    }
    return temp_v0;
}

Message *func_80239770_de(void *owner, void *pool, u8 *text, f32 size) {
    return post_lines(owner, pool, text, 2, size, -1);
}
