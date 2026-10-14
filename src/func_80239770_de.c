#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802393F4.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
/* Posts a text as on-screen messages, one per line: the text (or D_800D7028 when given D_800D7034) is split
 * at newlines and for each non-empty line the oldest message node of the owner's list at 0xF24 is recycled
 * (cleared through func_80239CE0_de, unlinked, and pushed onto the free list at 0xE40 of the pool) and set up
 * as a kind 2 message centred horizontally 80 pixels above the bottom of the screen, scaled by the given
 * size. Returns the last message node. */




extern func_80237E70_G1 D_800D7028;

extern func_80237E70_G1 D_800D7034;
extern s32 D_800E28D0;
extern void func_80239CE0_de(void *arg0);
extern void func_80255ED8_de(void *, Message *);









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

Message *func_80239770_de(void *owner, void *pool, u8 *text, f32 size) {
    return post_lines(owner, pool, text, 2, size, -1);
}
