#include "include_asm.h"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/RECTANGLE_DRAW.H"
#include "FRONTEND/TEXT_RENDER.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/WIDGETRECAT34.H"
#include "COMMON/TEXTURE.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_31.H"
#include "FRONTEND/8040B45C_35.H"
#include "MENU/GFX/80414430_19.H"
#include "MATH/802A2870.H"
#include "MATH/80299ECC_3.H"
#include "FRONTEND/8040B45C_36.H"

extern BatchRec D_8014D590[];
extern struct Shape_typemap_165 D_8014D580;
extern s32 Frontend_ComputeWidgetBounds(struct Shape_typemap_165 *, struct Shape_typemap_165 *, void *widget, DrawArgs *);
/* Flushes the queued text sprite batches: when any are queued it selects render mode 0x53333 if
   not already active, saves the clip rectangle and applies the queue's own, then walks the texture
   pages from the lowest first page to the highest last page among the batches, loading each page
   once through Frontend_GetBankTileTexture and func_804174F4_de (stopping the page when it cannot load) and drawing
   every batch's run of sprites on that page at depth 10 through func_80418DA0_de; finally it restores
   the clip rectangle and empties the queue. */







extern s32 D_8014D570;

extern s32 D_8014D584;

extern s32 D_8014D588;

extern s32 D_8014D58C;

extern s32 D_800E2AB8;

extern s32 D_8014D714;

extern void func_802A1898_de(s32 *left, s32 *right, s32 *top, s32 *bottom);

extern s32 Frontend_GetBankTileTexture(s32 page, s32 a, s32 b);

extern void func_804174F4_de(s32 texture);

static inline void func_8040CB30_restore(struct Shape_typemap_165 *clip) {
    func_802A1870_de(clip->field_0, clip->field_8, clip->field_4, clip->field_C);
}

extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


static inline s32 func_8040CDD0_overlaps(struct Shape_typemap_165 *area) {
    BatchRec *batch;
    s32 i;

    for (i = 0; i < D_8014D570; i++) {
        batch = &D_8014D590[i];
        if (area->field_4 < batch->area.field_0 || batch->area.field_4 < area->field_0 || area->field_C < batch->area.field_8 ||
            batch->area.field_C < area->field_8) {
            continue;
        }
        return 1;
    }
    return 0;
}

extern void func_80418DE0_de(f32 x, f32 y, f32 z, f32 width, f32 height, u32 c0, u32 c1, u32 c2, u32 c3);

static inline s32 func_8040D00C_overlaps(struct Shape_typemap_165 *area) {
    BatchRec *batch;
    s32 i;

    for (i = 0; i < D_8014D570; i++) {
        batch = &D_8014D590[i];
        if (area->field_4 < batch->area.field_0 || batch->area.field_4 < area->field_0 || area->field_C < batch->area.field_8 ||
            batch->area.field_C < area->field_8) {
            continue;
        }
        return 1;
    }
    return 0;
}

s32 func_802A0238_de(u8 *);

GlyphBuffer *func_8041200C_de(s32);

void func_8029FE38_de(char *, s32, s32, s32 (*)(char *, char *));

static inline void textBegin(u8 font, u8 style) {
    func_802A1898_de(&D_8014D580.field_0, &D_8014D580.field_8,
                   &D_8014D580.field_4, &D_8014D580.field_C);
    D_8014D710 = (s8)font;
    D_8014D714 = (s8)style;
    D_8014D560 = func_8041200C_de((s8)font);
    D_8014D564 = func_80411C60_de((s8)font);
    D_8014D568 = func_80411CD0_de((s8)font);
    D_8014D56C = func_80411C98_de((s8)font);
}

static inline s32 textOverlaps(BatchRec *next) {
    s32 i;
    BatchRec *batch;
    for (i = 0; i < D_8014D570; i++) {
        batch = &D_8014D590[i];
        if (next->area.field_4 < batch->area.field_0 || batch->area.field_4 < next->area.field_0 ||
            batch->area.field_8 > next->area.field_C || batch->area.field_C < next->area.field_8) continue;
        return 1;
    }
    return 0;
}

static inline s32 textClipChanged(struct Shape_typemap_165 *current) {
    if (current->field_0 != D_8014D580.field_0) return 1;
    if (current->field_8 != D_8014D588) return 1;
    if (current->field_4 != D_8014D584) return 1;
    return current->field_C != D_8014D58C;
}

void func_8040CAB0_de(void) {
    u16 first;
    u16 last;
    u16 page;
    s32 i;
    s32 current;
    s32 loaded;
    s32 texture;
    struct Shape_typemap_165 clip;
    BatchRec *batch;
    TextSprite *sprite;

    if (D_8014D570 == 0) {
        return;
    }
    first = 0x60;
    last = 0;
    if (D_800DEA6C != 0x53333 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53333;
        func_80417138_de(0x53333);
        D_800E2AB8 = 1;
    }
    func_802A1898_de(&clip.field_0, &clip.field_8, &clip.field_4, &clip.field_C);
    func_802A1870_de(D_8014D580.field_0, D_8014D588, D_8014D584, D_8014D58C);
    for (current = 0; current < D_8014D570; current++) {
        sprite = D_8014D590[current].cursor;
        page = sprite->glyph;
        if (first < page) {
            page = first;
        }
        first = page;
        page = sprite[D_8014D590[current].count - 1].glyph;
        if (page < last) {
            page = last;
        }
        last = page;
    }
    for (current = first; current <= last; current++) {
        loaded = 0;
        for (i = 0; i < D_8014D570; i++) {
            batch = &D_8014D590[i];
            while (current == batch->cursor->glyph && batch->count > 0) {
                sprite = batch->cursor;
                if (!loaded) {
                    texture = Frontend_GetBankTileTexture(current & 0xFF, D_8014D710, D_8014D714);
                    if (texture == 0) {
                        i = D_8014D570;
                        break;
                    }
                    func_804174F4_de(texture);
                    loaded = 1;
                }
                func_80418DA0_de(sprite->x, sprite->y, 10.0f, sprite->width, sprite->height, sprite->color);
                batch->cursor++;
                batch->count--;
            }
        }
    }
    func_8040CB30_restore(&clip);
    D_8014D570 = 0;
}

void func_8040CD50_de(Widget_func_8040CD50_de *widget, DrawArgs args) {
    struct Shape_typemap_165 box;
    struct Shape_typemap_165 area;
    struct Shape_typemap_165 saved;
    struct Shape_typemap_165 clip;
    s32 clipped;
    s32 texture;
    s32 color;

    clipped = 0;
    if (Frontend_ComputeWidgetBounds(&area, &box, widget, &args) == 0) {
        return;
    }
    if (widget->flags & 0x200) {
        func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
        clip = saved;
        if (func_8040F488_de(&clip, &box) == 0) {
            return;
        }
        clipped = 1;
        func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
    }
    if (func_8040CDD0_overlaps(&area)) {
        func_8040CAB0_de();
    }
    texture = func_80410674_de(widget->image, 1);
    color = (args.alpha << 24) | 0xFFFFFF;
    if (D_800DEA6C != 0x53333 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53333;
        func_80417138_de(0x53333);
        D_800E2AB8 = 1;
    }
    func_804174F4_de(texture);
    func_80418DA0_de(area.field_0, area.field_8, 0.0f, area.field_4 - area.field_0 + 1, area.field_C - area.field_8 + 1, color);
    if (clipped) {
        func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
    }
}

void func_8040CF8C_de(WidgetLayout *widget, DrawArgs args) {
    struct Shape_typemap_165 box;
    struct Shape_typemap_165 area;
    struct Shape_typemap_165 saved;
    struct Shape_typemap_165 clip;
    s32 clipped;

    clipped = 0;
    if (Frontend_ComputeWidgetBounds(&area, &box, widget, &args) == 0) {
        return;
    }
    if (((u8)(widget->colors[0] >> 24) | (u8)(widget->colors[1] >> 24) | (u8)(widget->colors[2] >> 24) |
         (u8)(widget->colors[3] >> 24)) == 0) {
        return;
    }
    if (widget->flags & 0x200) {
        func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
        clip = saved;
        if (func_8040F488_de(&clip, &box) == 0) {
            return;
        }
        clipped = 1;
        func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
    }
    if (func_8040D00C_overlaps(&area)) {
        func_8040CAB0_de();
    }
    if (D_800DEA6C != 0x53533 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53533;
        func_80417138_de(0x53533);
        D_800E2AB8 = 1;
    }
    func_804174F4_de(0);
    func_80418DE0_de(area.field_0, area.field_8, 0.0f, area.field_4 - area.field_0 + 1, area.field_C - area.field_8 + 1,
                  (widget->colors[0] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[0] >> 24) / 255) << 24),
                  (widget->colors[1] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[1] >> 24) / 255) << 24),
                  (widget->colors[2] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[2] >> 24) / 255) << 24),
                  (widget->colors[3] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[3] >> 24) / 255) << 24));
    if (clipped) {
        func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
    }
}

void func_8040D2D0_de(TextWidget *widget, DrawArgs args) {
    struct Shape_typemap_165 box, saved, clip, area, current;
    s32 clipped, length, width, mismatch, count, i, tempX, tempY;
    u8 font, style;
    u8 *text;
    f32 x, y, sub; u8 *resolved;
    BatchRec *batch;
    TextSprite *sprites, *sprite;
    TextGlyph *glyph;
    u32 color; s16 glyphId;
    resolved = widget->text;
    clipped = 0;
    if (!resolved) {
        if (widget->stringId == -1) return;
        resolved = (u8 *)func_80411D78_de(widget->stringId);
    }
    text=resolved;
    if (!Frontend_ComputeWidgetBounds(&area, &box, widget, &args)) return;
    if (widget->flags & 0x200) {
        func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
        clip = saved;
        if (!func_8040F488_de(&clip, &box)) return;
        clipped = 1;
        func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
    }
    length = func_802A0238_de(text);
    if (args.flags & 0x100) { font=widget->fontSelected; style=widget->styleSelected; }
    else if (args.flags & 0x40) { font=widget->fontAlt; style=widget->styleAlt; }
    else { font=widget->font; style=widget->style; }
    if ((s8)font == -1) font=widget->font;
    if ((s8)style == -1) style=widget->style;
    if (D_8014D570) {
        func_802A1898_de(&current.field_0, &current.field_8, &current.field_4, &current.field_C);
        mismatch = textClipChanged(&current);
        if (mismatch || D_8014D710 != (s8)font || D_8014D714 != (s8)style) {
            if (D_8014D570) func_8040CAB0_de();
            textBegin(font, style);
        }
    } else textBegin(font, style);
    width = func_8040F160_de((s8)font, text, length) * args.scaleX;
    x = 0.0f;
    switch (widget->align & 3) {
        case 0: x=area.field_0; break;
        case 1: x=(area.field_0+area.field_4)/2-width/2; break;
        case 2: {s32 edge=area.field_4; ++edge; x=edge-width;} break;
    }
    y = 0.0f;
    switch (widget->align & 12) {
        case 0: y=area.field_8; y-=D_8014D56C*args.scaleY; break;
        case 4:
            y=(area.field_8+area.field_C)/2; y-=D_8014D56C*args.scaleY; y-=(D_8014D568/2)*args.scaleY; break;
        case 8:
            sub=(D_8014D568+D_8014D56C)*args.scaleY;
            y=area.field_C; y-=sub; break;
    }
    batch=&D_8014D590[D_8014D570];
    tempX=x; batch->area.field_0=tempX; batch->area.field_4=tempX+width;
    tempY=(s32)y+(s32)(D_8014D56C*args.scaleY);
    batch->area.field_8=tempY; batch->area.field_C=tempY+(s32)(D_8014D568*args.scaleY);
    if (batch->area.field_0 >= batch->area.field_4) batch->area.field_4=batch->area.field_0+1;
    if (batch->area.field_C <= batch->area.field_8) batch->area.field_C=batch->area.field_8+1;
    if (textOverlaps(batch)) { func_8040CAB0_de(); textBegin(font, style); }
    sprite=func_802A15E4_de(length*sizeof(TextSprite));
    sprites=sprite;
    D_8014D590[D_8014D570].cursor=sprites;
    color=((u32)args.alpha<<24)|0xFFFFFF;
    count=0;

    for (i=0; i<length; i++) {
        glyphId=*text-0x20;
        sprite->glyph=glyphId;
        glyph=&D_8014D560->glyphs[glyphId];
        sprite->color=color;
        sprite->x=x;
        sprite->y=y+glyph->offsetY*args.scaleY;
        sprite->width=glyph->width*args.scaleX;
        sprite->height=glyph->height*args.scaleY;
        text++;
        if (sprite->x<D_800DEA60 && sprite->x+sprite->width>0.0f) { sprite++; count++; }
        x+=glyph->width*args.scaleX; x+=D_8014D564*args.scaleX;
    }
    if (clipped) func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
    if (count>0) {
        D_8014D590[D_8014D570].count=count;
        func_8029FE38_de((char *)D_8014D590[D_8014D570].cursor, count, sizeof(TextSprite), D_0040F570);
        D_8014D570++;
        if (D_8014D570>=16) func_8040CAB0_de();
    }
}

#if defined(NON_MATCHING) || defined(VERSION_US_REV1)
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "TYPES.H"

typedef struct DraftWidget {
    struct DraftWidget *parent;
    struct DraftWidget *next;
    struct DraftWidget *child;
    s16 id;
    u16 type;
    u16 unk10;
    u16 flags;
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    char pad1C[0x10];
    struct DraftWidget *normal;
    struct DraftWidget *selected;
    struct DraftWidget *disabled;
} DraftWidget;

extern s32 D_800E2AB8;
extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);
extern void func_802A1898_de(s32 *, s32 *, s32 *, s32 *);
extern void func_8040E7FC_de(void *, DrawArgs);
extern s32 func_80299838_de(s32);
extern void func_802A18FC_de(void);
extern void func_802A18F4_de(void);

void Frontend_DrawWidget(DraftWidget *, DrawArgs);
static inline void drawWidgetChoice(DraftWidget *widget, DrawArgs args) {
        struct Shape_typemap_165 area;
        struct Shape_typemap_165 box;
        DraftWidget *child;
        if (Frontend_ComputeWidgetBounds(&area, &box, widget, &args)) {
            if (args.flags & 0x100) child = widget->disabled;
            else if (args.flags & 0x40) child = widget->selected;
            else child = widget->normal;
            if (child) {
                args.x -= (s32)(child->x * args.scaleX);
                args.y -= (s32)(child->y * args.scaleY);
                Frontend_DrawWidget(child, args);
            }
        }
}

static inline void drawWidgetResetGroup(DraftWidget *widget, DrawArgs args) {
        struct Shape_typemap_165 box;
        struct Shape_typemap_165 saved;
        struct Shape_typemap_165 clip;
        struct Shape_typemap_165 area;
        s32 clipped;
        clipped = 0;
        D_800E2AB8 = 0;
        if (Frontend_ComputeWidgetBounds(&area, &box, widget, &args)) {
            if (widget->flags & 0x200) {
                func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (!func_8040F488_de(&clip, &box)) return;
                clipped = 1;
                func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            func_8040E7FC_de(widget->child, args);
            if (clipped) func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
        }
}

static inline void drawWidgetGroup(DraftWidget *widget, DrawArgs args) {
        struct Shape_typemap_165 box;
        struct Shape_typemap_165 area;
        struct Shape_typemap_165 saved;
        struct Shape_typemap_165 clip;
        s32 clipped;
        clipped = 0;
        if (Frontend_ComputeWidgetBounds(&area, &box, widget, &args)) {
            if (widget->flags & 0x200) {
                func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (!func_8040F488_de(&clip, &box)) return;
                clipped = 1;
                func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            func_8040E7FC_de(widget->child, args);
            if (clipped) func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
        }
}

void Frontend_DrawWidget(DraftWidget *widget, DrawArgs args) {
    switch (widget->type) {
    case 3:
        func_8040CD50_de((void *)widget, args);
        break;
    case 4:
        func_8040D2D0_de((void *)widget, args);
        break;
    case 6:
        func_8040CF8C_de((void *)widget, args);
        break;
    case 8:
        drawWidgetChoice(widget, args);
        break;
    case 2:
        drawWidgetResetGroup(widget, args);
        break;
    case 1:
        drawWidgetGroup(widget, args);
        break;
    default: {
        s32 flags;
        flags = func_80299838_de(widget->type);
        if (!(flags & 1)) {
            func_802A18FC_de();
            D_800E2AB8 = 0;
        }
        if (func_80299A80_de((void *)widget, args) && !(flags & 1)) {
            func_802A18F4_de();
            D_800E2AB8 = 0;
        }
        break;
    }
    }
}
#else
INCLUDE_ASM("ovl_80400000", Frontend_DrawWidget);
#endif

#ifdef NON_MATCHING
#include "COMMON/WIDGETRECAT1A.H"
extern s32 D_800DEA60, D_800E2AB4_de;

/* Propagate widget opacity and scale, compute its bounds, then clip the hit box. */
/* 168/362 aligned words; remaining: scaled bounds scheduling and register allocation. */
s32 Frontend_ComputeWidgetBounds(struct Shape_typemap_165 *draw, struct Shape_typemap_165 *hit, void *widget, DrawArgs *context) {
    WidgetLayout *layout = widget;
    f32 scaledCenterX,scaledCenterY,scaleX,scaleY,scaledHalfWidth,scaledHalfHeight;
    f32 parentScaleX;
    f32 parentScaleY;
    s16 widgetX;
    s32 centerX;
    s32 centerY;
    s32 hitCenterX;
    s32 hitCenterY;
    s32 parentFlags;
    s32 offsetHitBox;
    s32 centerFlag;
    s32 unscaledHalfWidth;
    s32 unscaledHalfHeight;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 halfWidth;
    s32 halfHeight;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    u16 widgetFlags;
    u16 widgetHeight;

    widgetFlags = layout->flags;
    parentFlags = context->flags;
    parentScaleX = context->scaleX;
    parentScaleY = context->scaleY;
    centerFlag = widgetFlags & 0x800 & 0xFFFF;
    offsetHitBox = widgetFlags & 0x400 & 0xFFFF;
    unscaledHalfWidth = (s32) (((u16)layout->width) << 0x10) >> 0x11;
    unscaledHalfHeight = (s32) (((u16)layout->height) << 0x10) >> 0x11;
    if (!(parentFlags & 0x4000)) {
        context->flags = (s32) (parentFlags | (widgetFlags & 0x140));
    }
    context->flags = (s32) (context->flags | (layout->flags & 0x609));
    if ((u8) layout->alpha < 0xFFU) {
        context->alpha = (u8) ((context->alpha * layout->alpha) / 255);
    }
    if (context->flags & 1) {
        context->alpha = (u8) ((u8) context->alpha >> 1);
    }
    var_v0 = 0;
    if (context->alpha != 0) {
        if (!(layout->flags & 8)) {
            return 0;
        }
        if ((context->scaleX != 1.0f) || (context->scaleY != 1.0f) || (layout->scaleX != 1.0f) || (layout->scaleY != 1.0f)) {
            scaledCenterX=(f32)(layout->x+layout->offsetX)+(f32)(s16)layout->width*0.5f;
            scaledCenterX*=context->scaleX;
            scaleX=context->scaleX*layout->scaleX;
            context->scaleX=scaleX;
            scaleY=context->scaleY*layout->scaleY;
            scaledCenterY=(f32)(layout->y+layout->offsetY)+(f32)(s16)layout->height*0.5f;
            scaledCenterY*=context->scaleY;
            context->scaleY=scaleY;
            scaledHalfWidth=(f32)(s16)layout->width*scaleX; scaledHalfWidth*=0.5f;
            scaledHalfHeight=(f32)(s16)layout->height*scaleY; scaledHalfHeight*=0.5f;
            centerX=(s32)scaledCenterX;
            centerY=(s32)scaledCenterY;
            halfWidth=(s32)scaledHalfWidth;
            halfHeight=(s32)scaledHalfHeight;
            draw->field_0=centerX-halfWidth+context->x;
            draw->field_4=centerX+halfWidth+context->x;
            draw->field_8=centerY-halfHeight+context->y;
            draw->field_C=centerY+halfHeight+context->y;
        } else {
            draw->field_0 = (s32) (context->x + layout->x + layout->offsetX);
            draw->field_8 = (s32) (context->y + layout->y + layout->offsetY);
            draw->field_4 = (s32) ((draw->field_0 + (s16) ((u16)layout->width)) - 1);
            draw->field_C = (s32) ((draw->field_8 + (s16) ((u16)layout->height)) - 1);
            halfWidth = (s32) (((u16)layout->width) << 0x10) >> 0x11;
            halfHeight = (s32) (((u16)layout->height) << 0x10) >> 0x11;
        }
        widgetX = layout->x;
        widgetHeight = ((u16)layout->height);
        hitCenterX = (s32) ((f32) (widgetX + ((s16) ((u16)layout->width) / 2)) * parentScaleX);
        hitCenterY = (s32) ((f32) (layout->y + ((s32) ((s16) widgetHeight + ((u32) (widgetHeight << 0x10) >> 0x1F)) >> 1)) * parentScaleY);
        if (centerFlag) {
            if (offsetHitBox != 0) {
                *hit = *draw;
            } else {
                hit->field_0 = (s32) ((hitCenterX - halfWidth) + context->x);
                hit->field_8 = (s32) ((hitCenterY - halfHeight) + context->y);
                hit->field_4 = (s32) (hitCenterX + halfWidth + context->x);
                var_v0_2 = hitCenterY + halfHeight + context->y;
                goto storeHitBottom;
            }
        } else {
            if (offsetHitBox == 0) {
                if (parentScaleX != 1.0f) {
                    var_v0_3 = (s32) ((f32) widgetX * parentScaleX) + context->x;
                } else {
                    var_v0_3 = widgetX + context->x;
                }
                hit->field_0 = var_v0_3;
                hit->field_4 = (s32) (hit->field_0 + (s16) ((u16)layout->width));
                if (parentScaleY != 1.0f) {
                    var_v0_4 = (s32) ((f32) layout->y * parentScaleY) + context->y;
                } else {
                    var_v0_4 = layout->y + context->y;
                }
                hit->field_8 = var_v0_4;
                var_v0_2 = hit->field_8 + (s16) ((u16)layout->height);
            } else {
                hit->field_0 = (s32) ((hitCenterX - unscaledHalfWidth) + layout->offsetX + context->x);
                hit->field_8 = (s32) ((hitCenterY - unscaledHalfHeight) + layout->offsetY + context->y);
                hit->field_4 = (s32) (hitCenterX + unscaledHalfWidth + layout->offsetX + context->x);
                var_v0_2 = hitCenterY + unscaledHalfHeight + layout->offsetY + context->y;
            }
storeHitBottom:
            hit->field_C = var_v0_2;
        }
        temp_v1 = hit->field_0;
        if (temp_v1 < 0) {
            hit->field_0 = 0;
            goto clipRight;
        }
        var_v0 = 0;
        if (D_800DEA60 >= temp_v1) {
clipRight:
            temp_v0_2 = hit->field_4;
            if (temp_v0_2 < 0) {
                return 0;
            }
            if (D_800DEA60 < temp_v0_2) {
                hit->field_4 = (s32) D_800DEA60;
            }
            temp_v1_2 = hit->field_8;
            if (temp_v1_2 < 0) {
                hit->field_8 = 0;
                goto clipBottom;
            }
            var_v0 = 0;
            if (D_800E2AB4_de >= temp_v1_2) {
clipBottom:
                temp_v0_3 = hit->field_C;
                if (temp_v0_3 < 0) {
                    return 0;
                }
                if (D_800E2AB4_de < temp_v0_3) {
                    hit->field_C = (s32) D_800E2AB4_de;
                }
                temp_v1_3 = hit->field_0;
                if (temp_v1_3 >= hit->field_4) {
                    hit->field_4 = (s32) (temp_v1_3 + 1);
                }
                temp_v1_4 = hit->field_8;
                if (temp_v1_4 >= hit->field_C) {
                    hit->field_C = (s32) (temp_v1_4 + 1);
                }
                context->x = (s32) draw->field_0;
                var_v0 = 1;
                context->y = (s32) draw->field_8;
                context->v[0] = (s32) draw->field_0;
                context->v[1] = (s32) draw->field_4;
                context->v[2] = (s32) draw->field_8;
                context->v[3] = (s32) draw->field_C;
                return var_v0;
            }
            return var_v0;
        }
        return var_v0;
    }
    return var_v0;
}
#else
INCLUDE_ASM("ovl_80400000", Frontend_ComputeWidgetBounds);
#endif
