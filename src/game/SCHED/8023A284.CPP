#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "SCHED/8023A284.H"
#include "SYSTEM/80255C40_7.H"



f32 func_8023A294_de(s32 unused0, f32 value, f32 target, f32 step) {
    if (Control_IsSnapshotActive() != 0) {
        value = target;
    }
    if (value < target) {
        value += step;
        D_800FF224_de = D_800C359C_de;
        if (target < value) {
            value = target;
        }
    } else if (target < value) {
        value -= step;
        D_800FF224_de = D_800C35A0_de;
        if (value < target) {
            value = target;
        }
    }
    return value;
}

/* Posts a text as on-screen messages, one per line, with the given kind, target and size: the text (or
 * D_800D7028 when given D_800D7034) is split at newlines and for each non-empty line the oldest message node
 * of the owner's list at 0xF24 is recycled (cleared through func_80239CE0_de, unlinked, and pushed onto the free
 * list at 0xE40 of the pool) and set up as a message centred horizontally 80 pixels above the bottom of the
 * screen, scaled by the given size. Returns the last message node. */




extern u8 *D_800D7028;

extern u8 *D_800D7034;










static inline CCameraText *recycle(void *owner, void *pool) {
    struct ScreenMessageOwner *messageOwner = owner;
    struct ScreenMessagePool *messagePool = pool;
    CCameraText *oldest;

    oldest = messageOwner->activeMessages.head;
    if (oldest != 0) {
        func_80239CE0_de(oldest);
        func_80255ED8_de(&messageOwner->activeMessages, oldest);
        func_80255D14_de(&messagePool->freeMessages, oldest);
    }
    return oldest;
}

CCameraText *Sky_PostScreenMessage(void *owner, void *pool, u8 *text, s32 kind, f32 size, s32 target) {
    CCameraText *message;
    u8 *line;
    u8 *p;
    s32 height;

    message = 0;
    if (pool == 0) {
        return message;
    }
    if (text == D_800D7034) {
        text = D_800D7028;
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
                    message->m_nAlpha = 0;
                    message->alpha = 1.0f;
                    message->target = target;
                    message->pad20 = 0;
                    message->m_ModeTime = 0;
                    message->pad2C = 0;
                    message->m_XScale = 1.0f;
                    message->m_YScale = 1.0f;
                    height = D_800E28D4;
                    message->x = D_800E28D0 / 2;
                    message->y = height - 80;
                    message->m_DisplayTime = size * 15.0f;
                }
                line = p + 1;
            }
        }
    }
    return message;
}
