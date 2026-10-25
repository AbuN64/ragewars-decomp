#include "COMMON/VIEWFLAGS.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
extern void Particle_SubtractVectors(CVector3 *out, CVector3 *a, CVector3 *b);

/* Spawns an emitter record: takes the head of the free list at 0x11D8 into the active list at 0x11EC (or reuses the record at 0x11F0 when none is free) and fills its position, scale, shared value and three rates converted by D_800C8630. */



extern f32 D_800C8630[];


static inline void set_emitter(CShake *node, f32 a, f32 b, f32 c, f32 scale, s32 value, CVector3 pos)
{
    node->m_vPos = pos;
    node->m_Radius = scale;
    node->x.mode = value;
    node->x.value = a;
    node->y.mode = value;
    node->y.value = b;
    node->z.mode = value;
    node->z.value = c;
}

extern s32 func_8027254C_de(f32 *arg0, f32 arg1);

extern f32 Math_Sqrtf(f32);

/* Posts a text as on-screen messages, one per line: the text (or D_800D7028 when given D_800D7034) is split
 * at newlines and for each non-empty line the oldest message node of the owner's list at 0xF24 is recycled
 * (cleared through func_80239CE0_de, unlinked, and pushed onto the free list at 0xE40 of the pool) and set up
 * as a kind 2 message centred horizontally 80 pixels above the bottom of the screen, scaled by the given
 * size. Returns the last message node. */




extern func_80237E70_G1 D_800D7028;

extern func_80237E70_G1 D_800D7034;

extern s32 D_800E28D0;

extern void func_80239CE0_de(void *arg0);

static inline CCameraText *recycle(void *owner, void *pool) {
    CCameraText *oldest;

    oldest = ((struct ScreenMessageOwner *)owner)->activeMessages.head;
    if (oldest != 0) {
        func_80239CE0_de(oldest);
        func_80255ED8_de(&((struct ScreenMessageOwner *)owner)->activeMessages, oldest);
        func_80255D14_de(&((struct ScreenMessagePool *)pool)->freeMessages, oldest);
    }
    return oldest;
}

static inline CCameraText *post_lines(void *owner, void *pool, u8 *text, s32 kind, f32 size, s32 target) {
    CCameraText *message;
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
                    s32 half = D_800E28D0 / 2;
                    message->kind = kind;
                    message->text = line;
                    message->m_nAlpha = 0;
                    message->alpha = 1.0f;
                    message->target = target;
                    message->pad20 = 0;
                    message->m_ModeTime = 0;
                    message->pad2C = 0;
                    message->m_XScale = 1.0f;
                    message->m_YScale = 1.0f;
                    height = D_800E28D4;
                    message->x = half;
                    message->y = height - 80;
                    message->m_DisplayTime = size * 15.0f;
                }
                line = p + 1;
            }
        }
    }
    return message;
}

void func_802394BC_de(char *obj, f32 a, f32 b, f32 c, f32 scale, s32 value, CVector3 pos)
{
    RaceViewportState *state = (void *)obj;
    CShake *node = state->freeEffects.head;
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

void *func_802395A4_de(MenuMatchGlobals *menuMatchGlobals, CVector3 *zero) {
    CVector3 position;
    GameplayCamera *node;
    void *bestNode;
    f32 bestDist;
    f32 distSq;

    func_8027254C_de(&zero->x, 20000.0f);
    if (menuMatchGlobals->useFallbackCamera != 0) {
        return &menuMatchGlobals->fallbackCamera;
    }
    node = menuMatchGlobals->cameras;
    bestDist = D_800C3548_de;
    bestNode = 0;
    if (node != 0) {
        do {
            Particle_SubtractVectors(&position, zero, &node->position);
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
        return &menuMatchGlobals->fallbackCamera;
    }
    return bestNode;
}

f32 func_80239678_de(Race *arg0, void *arg1) {
    CVector3 position;
    f32 sum;
    Racer *node;
    f64 divisor;
    s32 count;

    if (arg0->header.views.count == 0) {
        return 0.0f;
    }
    node = arg0->header.views.head;
    sum = 0.0f;
    if (node != 0) {
        do {
            Particle_SubtractVectors(&position, &((GameplayCamera *)node)->position, arg1);
            sum += Math_Sqrtf(
                (position.x * position.x) +
                (position.y * position.y) +
                (position.z * position.z));
            node = node->next;
        } while (node != 0);
    }
    count = arg0->header.views.count;
    divisor = (f64)count;
    if (count < 0) {
        divisor += D_800C3550_de;
    }
    return sum / (f32)divisor;
}

void *func_80239740_de(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool, u8 *text) {
    struct CCameraText_t *message = Camera_PostScreenMessage(owner, pool, text);
    if (message != 0) {
        message->pad20 = 1;
    }
    return message;
}

CCameraText *Camera_PostScaledScreenMessage(void *owner, void *pool, u8 *text, f32 size) {
    return post_lines(owner, pool, text, 2, size, -1);
}
