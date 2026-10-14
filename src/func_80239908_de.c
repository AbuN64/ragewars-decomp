#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802393F4.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
/* Posts a text as on-screen messages for a target: the target's messages still in the pool's list at 0xE40
 * are unlinked and returned to the owner's list at 0xF24, then the text (or D_800D7028 when given D_800D7034)
 * is split at newlines and for each non-empty line the oldest message node of the owner's list is recycled
 * and set up as a kind 2 message for the target, centred horizontally 80 pixels above the bottom of the
 * screen and scaled by the given size. Returns the last message node. */




extern func_80237E70_G1 D_800D7028;

extern func_80237E70_G1 D_800D7034;
extern s32 D_800E28D0;
extern void func_80239CE0_de(void *arg0);
extern void func_80255ED8_de(void *, Message *);
extern void func_80255CB8_de(void *, Message *);












static inline Message *recycle(void *owner, void *pool) {
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
                    message->x = D_800E28D0 / 2;
                    message->y = height - 80;
                    message->size = size * 15.0f;
                }
                line = p + 1;
            }
        }
    }
    return message;
}

Message *func_80239908_de(void *owner, void *pool, u8 *text, s32 target, f32 size) {
    Message *pending;
    Message *next;

    if (pool == 0) {
        return 0;
    }
    for (pending = ((struct ScreenMessagePool *)pool)->freeMessages.head; pending != 0; pending = next) {
        next = pending->next;
        if (pending->target == target) {
            func_80255ED8_de(&((struct ScreenMessagePool *)pool)->freeMessages, pending);
            func_80255CB8_de(&((struct ScreenMessageOwner *)owner)->activeMessages, pending);
        }
    }
    pending = post_lines(owner, pool, text, 2, size, target);
    return pending;
}
