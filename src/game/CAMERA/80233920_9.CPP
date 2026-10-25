#include "include_asm.h"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "abi.h"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/OBJECTSTATE18.H"
#include "gbi.h"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "COMMON/GFX.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "GFX/TEXT/802A8A94_5.H"

extern Gfx *D_80110634;
#include "COMMON/DISPLAY.H"
extern void Camera_UpdateScreenMessages(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool);
extern s32 D_800E28D0;
extern s32 D_800D297C;
extern f32 D_800D2988;
extern char D_800CBCC0;
extern char D_800CBCF0_de;
extern void Scene_MarkResourceInUse(s32, s32);
extern void Camera_SetupViewportAndFog(Racer *);
extern void func_802362E8_de(Racer *, s32);
extern void func_80239FD4_de(Racer *, s32);
extern void func_80233C88_de(Racer *);
extern void func_80238314_de(Race *, Racer *);
extern void func_804429D4_de(void *);
extern void func_802372D4_de(Racer *);
extern s32 Camera_IsSequenceActive(void);
extern s32 Camera_IsSequenceInWindow(void);
extern void func_8022A3F8_de(World_func_80236F1C_de *, Racer *);
/* Per-frame race update: clears three per-frame flags of the race's own racer, passes the race's first word to Scene_MarkResourceInUse, runs the 30-frame flash timer (restarted while D_80146894 is set or in mode 3) and while it runs clears the screen with a full-screen viewport, scissor and fill before func_8026D8F8_de, then updates every racer in the list until it ends or Camera_IsSequenceActive or Camera_IsSequenceInWindow reports, updates the race's own racer, hands the list to func_8022A3F8_de when the replay flag of D_80145040 is set, and passes the own racer's block at 0x554 to func_804429D4_de. */
void func_80236F1C_de(Race *race, s32 arg1)
{
    Racer *racer;
    race->self.hit = 0;
    race->self.boost = 0;
    race->self.spin = 0;
    if (race->header.music != 0) {
        Scene_MarkResourceInUse(0, race->header.music);
    }
    if (D_8011FAC0.clockPaused != 0 || race->header.views.count == 3) {
        D_800FF224_de = 30.0f;
    }
    if (D_800FF224_de != 0.0f) {
        D_800FF224_de -= D_800D2988;
    }
    if (D_800FF224_de < 0.0f) {
        D_800FF224_de = 0.0f;
    }
    if (D_800FF224_de != 0.0f) {
        racer = race->header.views.head;
        if (racer != 0) {
            gDPPipeSync(D_80110634++);
            gSPDisplayList(D_80110634++, ((&D_800CBCC0)));
            gSPDisplayList(D_80110634++, ((&D_800CBCF0_de)));
            racer->viewports[D_800D297C].vscale[0] = SCREEN_WD;
            racer->viewports[D_800D297C].vscale[1] = SCREEN_HT;
            racer->viewports[D_800D297C].vtrans[0] = SCREEN_WD;
            racer->viewports[D_800D297C].vtrans[1] = SCREEN_HT;
            gSPMoveMem(D_80110634++, G_MV_VIEWPORT, 0, 16, ((&racer->viewports[D_800D297C])));
            gDPSetScissor(D_80110634++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
            gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, (u32)((D_8011BDC0->colorImage)));
            gDPSetCycleType(D_80110634++, G_CYC_FILL);
            gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
            gDPSetRenderMode(D_80110634++, ((0)), 0);
            gDPSetFillColor(D_80110634++, ((0x10001)));
            gDPFillRectangle(D_80110634++, 0, 0, (SCREEN_WD), (SCREEN_HT));
            func_8026D8F8_de();
        }
    }
    for (racer = race->header.views.head; racer != 0;) {
        Camera_SetupViewportAndFog(racer);
        func_802362E8_de(racer, arg1);
        if (racer->effect != 0) {
            func_80239FD4_de(racer, racer->effectArg);
        }
        func_80233C88_de(racer);
        func_80238314_de(race, racer);
        func_804429D4_de(racer->sound);
        func_802372D4_de(racer);
        if (Camera_IsSequenceActive() != 0 || Camera_IsSequenceInWindow() != 0) {
            racer = 0;
        } else {
            racer = racer->next;
        }
    }
    Camera_SetupViewportAndFog(&race->self);
    if (race->header.views.count == 0) {
        func_80233C88_de(&race->self);
    }
    func_80238314_de(race, &race->self);
    if (D_80145040.replay != 0) {
        racer = race->header.views.head;
        if (racer != 0) {
            func_8022A3F8_de(&D_80145040, racer);
        }
    }
    func_804429D4_de(race->self.sound);
}


void func_802372D4_de(Racer *racer) {
    View *entity = (View *)racer;
    f32 x;
    f32 y;
    f32 width;
    f32 height;

    func_8026D8F8_de();
    x = entity->viewport[2];
    y = entity->viewport[3];
    width = entity->viewport[0];
    height = entity->viewport[1];
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE,
                     0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_80110634++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, 0, 0);
    gDPFillRectangle(D_80110634++, x, y, (x + width) - 1.0f, y + 2.0f);
    gDPFillRectangle(D_80110634++, x, (y + height) - 2.0f,
                    (x + width) - 1.0f, (y + height) - 1.0f);
    gDPFillRectangle(D_80110634++, x, y, x + 2.0f, (y + height) - 1.0f);
    gDPFillRectangle(D_80110634++, (x + width) - 2.0f, y,
                    (x + width) - 1.0f, (y + height) - 1.0f);
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_FILL);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE,
                     0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(D_80110634++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(D_80110634++, (1 << 16) | 1);
    gDPFillRectangle(D_80110634++, x, y, (x + width) - 1.0f, y);
    gDPFillRectangle(D_80110634++, x, (y + height) - 1.0f,
                    (x + width) - 1.0f, (y + height) - 1.0f);
    gDPFillRectangle(D_80110634++, x, y, x, (y + height) - 1.0f);
    gDPFillRectangle(D_80110634++, (x + width) - 1.0f, y,
                    x + width, (y + height) - 1.0f);
}

/* Posts a text as on-screen messages, one per line: when Camera_IsSequenceActive reports it, the messages already in
 * the pool's list at 0xE40 are flagged kind 4 and the new ones get kind 1, otherwise kind 2; the text (or
 * D_800D7028 when given D_800D7034) is split at newlines and for each non-empty line the oldest message node
 * of the owner's list at 0xF24 is recycled and set up centred horizontally 80 pixels above the bottom of the
 * screen at unit size. Returns the last message node. */




extern func_80237E70_G1 D_800D7028;

extern func_80237E70_G1 D_800D7034;

extern s32 D_800E28D0;
extern void func_80239CE0_de(void *arg0);
extern s32 Camera_IsSequenceActive(void);












static inline CCameraText *recycle(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool) {
    CCameraText *oldest;

    oldest = owner->activeMessages.head;
    if (oldest != 0) {
        func_80239CE0_de(oldest);
        func_80255ED8_de(&owner->activeMessages, oldest);
        func_80255D14_de(&pool->freeMessages, oldest);
    }
    return oldest;
}

static inline CCameraText *post_lines(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool, u8 *text, s32 kind, f32 size, s32 target) {
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
                    message->kind = kind;
                    message->text = line;
                    message->m_nAlpha = 0;
                    message->alpha = 1.0f;
                    message->m_DisplayTime = size * 15.0f;
                    message->target = target;
                    message->pad20 = 0;
                    message->m_ModeTime = 0;
                    message->pad2C = 0;
                    message->m_XScale = 1.0f;
                    message->m_YScale = 1.0f;
                    height = D_800E28D4;
                    message->x = D_800E28D0 / 2;
                    message->y = height - 80;
                }
                line = p + 1;
            }
        }
    }
    return message;
}

CCameraText *Camera_PostScreenMessage(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool, u8 *text) {
    CCameraText *pending;
    s32 kind;

    kind = 2;
    if (pool == 0) {
        return 0;
    }
    if (Camera_IsSequenceActive() != 0) {
        pending = pool->freeMessages.head;
        if (pending != 0) {
            kind = 1;
            do {
                pending->kind = 4;
                pending = pending->next;
            } while (pending != 0);
        }
    }
    return post_lines(owner, pool, text, kind, 1.0f, -1);
}

extern void func_802A84F8_de(void);
extern void func_802A8800_de(void);
extern void func_802A8F28_de(void *text, s32 x, s32 y, s32 alpha, s32 arg4, s32 arg5, f32 scaleX, f32 scaleY);
void Camera_UpdateScreenMessages(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool) {
    f32 spacing;
    f32 fade;
    CCameraText *node;
    CCameraText *msg;
    CCameraText *waiting;

    spacing = 9.0f;
    if (pool != 0) {
        func_802A84F8_de();
        func_802A8800_de();
        node = pool->freeMessages.head;
        if (node != 0) {
            node->y = (f32)D_800E28D4 * 0.81f;
            for (msg = node->next; msg != 0; msg = msg->next) {
                msg->y = node->y + spacing;
                node = msg;
            }
        }
        for (msg = pool->freeMessages.tail; msg != 0; msg = msg->prev) {
            func_802A8F28_de(msg->text, (s32)msg->x, (s32)msg->y, msg->m_nAlpha, 1, 1, 1.0f, 1.0f);
        }
        for (msg = pool->freeMessages.tail; msg != 0; msg = msg->prev) {
            fade = D_800D2988 * 0.06666667f;
            node = msg;
            switch (msg->kind) {
            case 2:
                msg->m_nAlpha = (s32)(Math_Sinf(msg->m_ModeTime * 1.5707964f) * 255.0f);
                msg->m_ModeTime += fade;
                if (msg->m_ModeTime > 1.0f) {
                    msg->kind = 3;
                    msg->m_ModeTime = 0.0f;
                }
                break;
            case 1:
                msg->m_nAlpha = 0;
                break;
            case 3:
                msg->m_nAlpha = 255;
                break;
            case 4:
                msg->m_nAlpha = (s32)(Math_Cosf(msg->m_ModeTime * 1.5707964f) * 255.0f);
                msg->m_ModeTime += fade;
                if (msg->m_ModeTime > 1.0f) {
                    for (waiting = pool->freeMessages.head; waiting != 0; waiting = waiting->next) {
                        if (waiting->kind == 1) {
                            waiting->kind = 2;
                            waiting->m_ModeTime = 0.0f;
                        }
                    }
                    node->kind = 0;
                    node->m_ModeTime = 0.0f;
                }
                break;
            default:
                node->m_nAlpha = 0;
                node->kind = 0;
                break;
            }
        }
        for (msg = pool->freeMessages.tail; msg != 0; msg = node) {
            node = msg->prev;
            if (msg->kind == 0) {
                func_80255ED8_de(&pool->freeMessages, msg);
                func_80255CB8_de(&owner->activeMessages, msg);
            }
        }
    }
}

extern const f32 D_800C3414_de, D_800C3418_de, D_800C341C_de, D_800C3420_de;
extern const f32 D_800C3424_de, D_800C3428_de, D_800C342C_de, D_800C3430_de;
extern const f32 D_800C3434_de, D_800C3438_de, D_800C343C_de, D_800C3440_de;
extern const f32 D_800C3444_de, D_800C3448_de;
extern s32 D_800E28D8;
extern void func_802A84F8_de(void);
extern void func_802A8F28_de(void *, s32, s32, s32, s32, s32, f32, f32);
extern float Math_Sinf(float x);

/* Draws and advances the screen messages of one view, retiring finished ones. */
void func_80238314_de(Race *race, Racer *racer) {
    f32 scale;
    f32 width, height, x, y;
    f32 scaleY;
    f32 scaleX;
    f32 offsetY;
    s32 small;
    CCameraText *message;
    CCameraText *prev;
    f32 drop;
    f32 offsetXf;
    f32 left;
    s32 centered;

    if (Camera_IsSequenceInWindow() != 0) {
        Camera_UpdateScreenMessages((struct ScreenMessageOwner *)race, (struct ScreenMessagePool *)racer);
        return;
    }
    scale = D_800C3414_de;
    height = racer->viewportHeight;
    width = racer->viewportWidth;
    x = racer->viewportX;
    y = racer->viewportY;
    scaleY = height / (f32)D_800E28D4;
    scaleX = width / (f32)D_800E28D0;
    small = 1;
    if (!(scaleX < scale) && !(scaleY < scale)) {
        small = 0;
    }
    offsetXf = width * D_800C3418_de + x;
    drop = scaleY * D_800C341C_de;
    left = height * D_800C3420_de + y;
    offsetY = left - drop;
    message = racer->activeMessages.tail;
    for (; message != 0; message = prev) {
        prev = message->prev;
        if (message->kind != 0) {
            func_802A84F8_de();
            if (small || message->pad20 != 0) {
                scale = D_800C3424_de;
                if (D_800E28D8 == 0) {
                    scale = D_800C3428_de;
                }
                scaleY = D_800C342C_de;
                centered = 1;
            } else {
                scale = D_800C3430_de;
                centered = 1;
            }
            func_802A8F28_de(message->text, (s32)offsetXf, (s32)offsetY, message->m_nAlpha, centered, centered,
                             message->alpha * scaleX * scale, message->alpha * scaleY * scale);
            switch (message->kind) {
            case 2:
                message->m_nAlpha += 31;
                if (message->m_nAlpha >= 255) {
                    message->m_nAlpha = 255;
                    message->kind = 3;
                    message->m_Time = message->m_DisplayTime;
                }
                message->alpha = Math_Sinf((f32)message->m_nAlpha * D_800C3434_de);
                break;
            case 3:
                message->m_Time -= D_800D2988;
                left = message->m_Time;
                message->m_nAlpha = 255;
                message->alpha = D_800C3438_de;
                if (left < 0.0f) {
                    message->kind = 4;
                    message->m_nAlpha = 128;
                }
                break;
            case 4:
                message->alpha -= Math_Sinf(D_800C3440_de - (f32)message->m_nAlpha * D_800C343C_de) * D_800C3444_de;
                if (message->alpha < 0.0f) {
                    message->alpha = 0.0f;
                }
                message->m_nAlpha -= 12;
                if (message->m_nAlpha < 0) {
                    message->m_nAlpha = 0;
                    message->kind = 0;
                }
                break;
            }
        }
        if (message->kind == 0) {
            func_80255ED8_de(&racer->activeMessages, message);
            func_80255CB8_de(&race->freeMessages, message);
        }
        offsetY -= scaleY * D_800C3448_de / scale;
    }
}


