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

extern BatchRec g_textBatches[];
extern struct Shape_typemap_165 D_8014D580;
extern s32 Frontend_ComputeWidgetBounds(struct Shape_typemap_165 *, struct Shape_typemap_165 *, WidgetLayout *widget, sm_dldc *);
/* Flushes the queued text sprite batches: when any are queued it selects render mode 0x53333 if
   not already active, saves the clip rectangle and applies the queue's own, then walks the texture
   pages from the lowest first page to the highest last page among the batches, loading each page
   once through Frontend_GetBankTileTexture and Gfx_BindImageTexture (stopping the page when it cannot load) and drawing
   every batch's run of sprites on that page at depth 10 through Gfx_DrawRect; finally it restores
   the clip rectangle and empties the queue. */














extern s32 Frontend_GetBankTileTexture(s32 page, s32 a, s32 b);

extern void Gfx_BindImageTexture(s32 texture);

static inline void func_8040CB30_restore(struct Shape_typemap_165 *clip) {
    N64Eng_SetClipBounds(clip->field_0, clip->field_8, clip->field_4, clip->field_C);
}

extern s32 Frontend_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


static inline s32 func_8040CDD0_overlaps(struct Shape_typemap_165 *area) {
    BatchRec *batch;
    s32 i;

    for (i = 0; i < g_textBatchCount; i++) {
        batch = &g_textBatches[i];
        if (area->field_4 < batch->area.field_0 || batch->area.field_4 < area->field_0 || area->field_C < batch->area.field_8 ||
            batch->area.field_C < area->field_8) {
            continue;
        }
        return 1;
    }
    return 0;
}

extern void Gfx_DrawGradientRectangle(f32 x, f32 y, f32 z, f32 width, f32 height, u32 c0, u32 c1, u32 c2, u32 c3);

static inline s32 func_8040D00C_overlaps(struct Shape_typemap_165 *area) {
    BatchRec *batch;
    s32 i;

    for (i = 0; i < g_textBatchCount; i++) {
        batch = &g_textBatches[i];
        if (area->field_4 < batch->area.field_0 || batch->area.field_4 < area->field_0 || area->field_C < batch->area.field_8 ||
            batch->area.field_C < area->field_8) {
            continue;
        }
        return 1;
    }
    return 0;
}

s32 XPlus_StringLength(u8 *);

GlyphBuffer *Frontend_GetGlyphBuffer(s32);

void XPlus_SortArray(char *, s32, s32, s32 (*)(char *, char *));

static inline void textBegin(u8 font, u8 style) {
    N64Eng_GetClipBounds(&D_8014D580.field_0, &D_8014D580.field_8,
                   &D_8014D580.field_4, &D_8014D580.field_C);
    g_textBatchFontId = (s8)font;
    g_textBatchStyle = (s8)style;
    g_textGlyphBuffer = Frontend_GetGlyphBuffer((s8)font);
    g_textGlyphSpacing = Frontend_GetFontLetterSpacing((s8)font);
    g_textLineHeight = Frontend_GetFontMetricAtC((s8)font);
    g_textVerticalOffset = Frontend_GetFontMetricAtA((s8)font);
}

static inline s32 textOverlaps(BatchRec *next) {
    s32 i;
    BatchRec *batch;
    for (i = 0; i < g_textBatchCount; i++) {
        batch = &g_textBatches[i];
        if (next->area.field_4 < batch->area.field_0 || batch->area.field_4 < next->area.field_0 ||
            batch->area.field_8 > next->area.field_C || batch->area.field_C < next->area.field_8) continue;
        return 1;
    }
    return 0;
}

static inline s32 textClipChanged(struct Shape_typemap_165 *current) {
    if (current->field_0 != D_8014D580.field_0) return 1;
    if (current->field_8 != g_textClipTop) return 1;
    if (current->field_4 != g_textClipRight) return 1;
    return current->field_C != g_textClipBottom;
}

void Frontend_FlushTextBatches(void) {
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

    if (g_textBatchCount == 0) {
        return;
    }
    first = 0x60;
    last = 0;
    if (D_800DEA6C != 0x53333 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53333;
        Gfx_ConfigurePrimitiveRenderFlags(0x53333);
        D_800E2AB8 = 1;
    }
    N64Eng_GetClipBounds(&clip.field_0, &clip.field_8, &clip.field_4, &clip.field_C);
    N64Eng_SetClipBounds(D_8014D580.field_0, g_textClipTop, g_textClipRight, g_textClipBottom);
    for (current = 0; current < g_textBatchCount; current++) {
        sprite = g_textBatches[current].cursor;
        page = sprite->glyph;
        if (first < page) {
            page = first;
        }
        first = page;
        page = sprite[g_textBatches[current].count - 1].glyph;
        if (page < last) {
            page = last;
        }
        last = page;
    }
    for (current = first; current <= last; current++) {
        loaded = 0;
        for (i = 0; i < g_textBatchCount; i++) {
            batch = &g_textBatches[i];
            while (current == batch->cursor->glyph && batch->count > 0) {
                sprite = batch->cursor;
                if (!loaded) {
                    texture = Frontend_GetBankTileTexture(current & 0xFF, g_textBatchFontId, g_textBatchStyle);
                    if (texture == 0) {
                        i = g_textBatchCount;
                        break;
                    }
                    Gfx_BindImageTexture(texture);
                    loaded = 1;
                }
                Gfx_DrawRect(sprite->x, sprite->y, 10.0f, sprite->width, sprite->height, sprite->color);
                batch->cursor++;
                batch->count--;
            }
        }
    }
    func_8040CB30_restore(&clip);
    g_textBatchCount = 0;
}

void Frontend_DrawImageWidget(WidgetFrontendDrawImageWidget *widget, sm_dldc args) {
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
        N64Eng_GetClipBounds(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
        clip = saved;
        if (Frontend_ClampRectToClip(&clip, &box) == 0) {
            return;
        }
        clipped = 1;
        N64Eng_SetClipBounds(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
    }
    if (func_8040CDD0_overlaps(&area)) {
        Frontend_FlushTextBatches();
    }
    texture = Frontend_GetImageTexture(widget->image, 1);
    color = (args.alpha << 24) | 0xFFFFFF;
    if (D_800DEA6C != 0x53333 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53333;
        Gfx_ConfigurePrimitiveRenderFlags(0x53333);
        D_800E2AB8 = 1;
    }
    Gfx_BindImageTexture(texture);
    Gfx_DrawRect(area.field_0, area.field_8, 0.0f, area.field_4 - area.field_0 + 1, area.field_C - area.field_8 + 1, color);
    if (clipped) {
        N64Eng_SetClipBounds(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
    }
}

void Frontend_DrawGradientWidget(WidgetLayout *widget, sm_dldc args) {
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
        N64Eng_GetClipBounds(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
        clip = saved;
        if (Frontend_ClampRectToClip(&clip, &box) == 0) {
            return;
        }
        clipped = 1;
        N64Eng_SetClipBounds(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
    }
    if (func_8040D00C_overlaps(&area)) {
        Frontend_FlushTextBatches();
    }
    if (D_800DEA6C != 0x53533 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53533;
        Gfx_ConfigurePrimitiveRenderFlags(0x53533);
        D_800E2AB8 = 1;
    }
    Gfx_BindImageTexture(0);
    Gfx_DrawGradientRectangle(area.field_0, area.field_8, 0.0f, area.field_4 - area.field_0 + 1, area.field_C - area.field_8 + 1,
                  (widget->colors[0] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[0] >> 24) / 255) << 24),
                  (widget->colors[1] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[1] >> 24) / 255) << 24),
                  (widget->colors[2] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[2] >> 24) / 255) << 24),
                  (widget->colors[3] & 0xFFFFFF) | ((args.alpha * (u8)(widget->colors[3] >> 24) / 255) << 24));
    if (clipped) {
        N64Eng_SetClipBounds(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
    }
}

void Frontend_DrawTextWidget(TextWidget *widget, sm_dldc args) {
    struct Shape_typemap_165 box, saved, clip, area, current;
    s32 clipped, length, width, mismatch, count, i, tempX, tempY;
    u8 font, style;
    u8 *text;
    f32 x, y, sub; u8 *resolved;
    BatchRec *batch;
    TextSprite *sprites, *sprite;
    sm_font_char *glyph;
    u32 color; s16 glyphId;
    resolved = widget->text;
    clipped = 0;
    if (!resolved) {
        if (widget->stringId == -1) return;
        resolved = (u8 *)Frontend_GetStringByIndex(widget->stringId);
    }
    text=resolved;
    if (!Frontend_ComputeWidgetBounds(&area, &box, widget, &args)) return;
    if (widget->flags & 0x200) {
        N64Eng_GetClipBounds(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
        clip = saved;
        if (!Frontend_ClampRectToClip(&clip, &box)) return;
        clipped = 1;
        N64Eng_SetClipBounds(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
    }
    length = XPlus_StringLength(text);
    if (args.flags & 0x100) { font=widget->fontSelected; style=widget->styleSelected; }
    else if (args.flags & 0x40) { font=widget->fontAlt; style=widget->styleAlt; }
    else { font=widget->font; style=widget->style; }
    if ((s8)font == -1) font=widget->font;
    if ((s8)style == -1) style=widget->style;
    if (g_textBatchCount) {
        N64Eng_GetClipBounds(&current.field_0, &current.field_8, &current.field_4, &current.field_C);
        mismatch = textClipChanged(&current);
        if (mismatch || g_textBatchFontId != (s8)font || g_textBatchStyle != (s8)style) {
            if (g_textBatchCount) Frontend_FlushTextBatches();
            textBegin(font, style);
        }
    } else textBegin(font, style);
    width = Frontend_MeasureTextPrefix((s8)font, text, length) * args.XScale;
    x = 0.0f;
    switch (widget->align & 3) {
        case 0: x=area.field_0; break;
        case 1: x=(area.field_0+area.field_4)/2-width/2; break;
        case 2: {s32 edge=area.field_4; ++edge; x=edge-width;} break;
    }
    y = 0.0f;
    switch (widget->align & 12) {
        case 0: y=area.field_8; y-=g_textVerticalOffset*args.YScale; break;
        case 4:
            y=(area.field_8+area.field_C)/2; y-=g_textVerticalOffset*args.YScale; y-=(g_textLineHeight/2)*args.YScale; break;
        case 8:
            sub=(g_textLineHeight+g_textVerticalOffset)*args.YScale;
            y=area.field_C; y-=sub; break;
    }
    batch=&g_textBatches[g_textBatchCount];
    tempX=x; batch->area.field_0=tempX; batch->area.field_4=tempX+width;
    tempY=(s32)y+(s32)(g_textVerticalOffset*args.YScale);
    batch->area.field_8=tempY; batch->area.field_C=tempY+(s32)(g_textLineHeight*args.YScale);
    if (batch->area.field_0 >= batch->area.field_4) batch->area.field_4=batch->area.field_0+1;
    if (batch->area.field_C <= batch->area.field_8) batch->area.field_C=batch->area.field_8+1;
    if (textOverlaps(batch)) { Frontend_FlushTextBatches(); textBegin(font, style); }
    sprite=ESmem_AllocateFrameHeapHigh(length*sizeof(TextSprite));
    sprites=sprite;
    g_textBatches[g_textBatchCount].cursor=sprites;
    color=((u32)args.alpha<<24)|0xFFFFFF;
    count=0;

    for (i=0; i<length; i++) {
        glyphId=*text-0x20;
        sprite->glyph=glyphId;
        glyph=&g_textGlyphBuffer->glyphs[glyphId];
        sprite->color=color;
        sprite->x=x;
        sprite->y=y+glyph->BaselineOffset*args.YScale;
        sprite->width=glyph->width*args.XScale;
        sprite->height=glyph->height*args.YScale;
        text++;
        if (sprite->x<D_800DEA60 && sprite->x+sprite->width>0.0f) { sprite++; count++; }
        x+=glyph->width*args.XScale; x+=g_textGlyphSpacing*args.XScale;
    }
    if (clipped) N64Eng_SetClipBounds(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
    if (count>0) {
        g_textBatches[g_textBatchCount].count=count;
        XPlus_SortArray((char *)g_textBatches[g_textBatchCount].cursor, count, sizeof(TextSprite), D_0040F570);
        g_textBatchCount++;
        if (g_textBatchCount>=16) Frontend_FlushTextBatches();
    }
}

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

extern s32 Frontend_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);
extern void Frontend_DrawVisibleSiblings(void *, sm_dldc);
extern s32 Smos_GetElementHandlerFlags(s32);
extern void N64Eng_ResetRenderState(void);
extern void N64Eng_RenderNoop(void);

void Frontend_DrawWidget(DraftWidget *, sm_dldc);
static inline void drawWidgetChoice(DraftWidget *widget, sm_dldc args) {
        struct Shape_typemap_165 area;
        struct Shape_typemap_165 box;
        DraftWidget *child;
        if (Frontend_ComputeWidgetBounds(&area, &box, widget, &args)) {
            if (args.flags & 0x100) child = widget->disabled;
            else if (args.flags & 0x40) child = widget->selected;
            else child = widget->normal;
            if (child) {
                args.x -= (s32)(child->x * args.XScale);
                args.y -= (s32)(child->y * args.YScale);
                Frontend_DrawWidget(child, args);
            }
        }
}

static inline void drawWidgetResetGroup(DraftWidget *widget, sm_dldc args) {
        struct Shape_typemap_165 box;
        struct Shape_typemap_165 saved;
        struct Shape_typemap_165 clip;
        struct Shape_typemap_165 area;
        s32 clipped;
        clipped = 0;
        D_800E2AB8 = 0;
        if (Frontend_ComputeWidgetBounds(&area, &box, widget, &args)) {
            if (widget->flags & 0x200) {
                N64Eng_GetClipBounds(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (!Frontend_ClampRectToClip(&clip, &box)) return;
                clipped = 1;
                N64Eng_SetClipBounds(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            Frontend_DrawVisibleSiblings(widget->child, args);
            if (clipped) N64Eng_SetClipBounds(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
        }
}

static inline void drawWidgetGroup(DraftWidget *widget, sm_dldc args) {
        struct Shape_typemap_165 box;
        struct Shape_typemap_165 area;
        struct Shape_typemap_165 saved;
        struct Shape_typemap_165 clip;
        s32 clipped;
        clipped = 0;
        if (Frontend_ComputeWidgetBounds(&area, &box, widget, &args)) {
            if (widget->flags & 0x200) {
                N64Eng_GetClipBounds(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (!Frontend_ClampRectToClip(&clip, &box)) return;
                clipped = 1;
                N64Eng_SetClipBounds(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            Frontend_DrawVisibleSiblings(widget->child, args);
            if (clipped) N64Eng_SetClipBounds(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
        }
}

void Frontend_DrawWidget(DraftWidget *widget, sm_dldc args) {
    switch (widget->type) {
    case 3:
        Frontend_DrawImageWidget((void *)widget, args);
        break;
    case 4:
        Frontend_DrawTextWidget((void *)widget, args);
        break;
    case 6:
        Frontend_DrawGradientWidget((void *)widget, args);
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
        flags = Smos_GetElementHandlerFlags(widget->type);
        if (!(flags & 1)) {
            N64Eng_ResetRenderState();
            D_800E2AB8 = 0;
        }
        if (Smos_InvokeWidgetCallback((void *)widget, args) && !(flags & 1)) {
            N64Eng_RenderNoop();
            D_800E2AB8 = 0;
        }
        break;
    }
    }
}

/* Applies a widget's flags, opacity and scale to the draw context, computes its draw rectangle
   (scaled about its centre when any scale is not 1) and its hit box, and clips the hit box to the
   screen. Returns 1 when the widget is visible, and then moves the context origin and clip to the
   draw rectangle. */
s32 Frontend_ComputeWidgetBounds(struct Shape_typemap_165 *draw, struct Shape_typemap_165 *hit, WidgetLayout *widget, sm_dldc *ctx) {
    u16 flags = widget->flags;
    s32 parentFlags = ctx->flags;
    f32 parentScaleX = ctx->XScale;
    f32 parentScaleY = ctx->YScale;
    s32 centred = flags & 0x800;
    s32 useDraw = flags & 0x400;
    s32 halfW = widget->width >> 1;
    s32 halfH = widget->height >> 1;
    s32 drawHalfW;
    s32 drawHalfH;
    s32 centreX;
    s32 centreY;

    if (!(parentFlags & 0x4000)) {
        ctx->flags = parentFlags | (flags & 0x140);
    }
    ctx->flags |= widget->flags & 0x609;
    if (widget->alpha < 0xFF) {
        ctx->alpha = ctx->alpha * widget->alpha / 255;
    }
    if (ctx->flags & 1) {
        ctx->alpha >>= 1;
    }
    if (ctx->alpha == 0) {
        return 0;
    }
    if (!(widget->flags & 8)) {
        return 0;
    }
    if (ctx->XScale != 1.0f || ctx->YScale != 1.0f || widget->scaleX != 1.0f || widget->scaleY != 1.0f) {
        centreX = (widget->x + widget->offsetX + widget->width * 0.5f) * ctx->XScale;
        centreY = (widget->y + widget->offsetY + widget->height * 0.5f) * ctx->YScale;
        ctx->XScale *= widget->scaleX;
        ctx->YScale *= widget->scaleY;
        drawHalfW = widget->width * ctx->XScale * 0.5f;
        drawHalfH = widget->height * ctx->YScale * 0.5f;
        draw->field_0 = centreX - drawHalfW + ctx->x;
        draw->field_4 = centreX + drawHalfW + ctx->x;
        draw->field_8 = centreY - drawHalfH + ctx->y;
        draw->field_C = centreY + drawHalfH + ctx->y;
    } else {
        draw->field_0 = ctx->x + widget->x + widget->offsetX;
        draw->field_8 = ctx->y + widget->y + widget->offsetY;
        draw->field_4 = draw->field_0 + widget->width - 1;
        draw->field_C = draw->field_8 + widget->height - 1;
        drawHalfW = widget->width >> 1;
        drawHalfH = widget->height >> 1;
    }
    centreX = (f32)(widget->x + widget->width / 2) * parentScaleX;
    centreY = (f32)(widget->y + widget->height / 2) * parentScaleY;
    if (centred && useDraw) {
        *hit = *draw;
    } else if (!centred && !useDraw) {
        if (parentScaleX != 1.0f) {
            hit->field_0 = (s32)(widget->x * parentScaleX) + ctx->x;
        } else {
            hit->field_0 = widget->x + ctx->x;
        }
        hit->field_4 = hit->field_0 + widget->width;
        if (parentScaleY != 1.0f) {
            hit->field_8 = (s32)(widget->y * parentScaleY) + ctx->y;
        } else {
            hit->field_8 = widget->y + ctx->y;
        }
        hit->field_C = hit->field_8 + widget->height;
    } else if (centred) {
        hit->field_0 = centreX - drawHalfW + ctx->x;
        hit->field_8 = centreY - drawHalfH + ctx->y;
        hit->field_4 = centreX + drawHalfW + ctx->x;
        hit->field_C = centreY + drawHalfH + ctx->y;
    } else {
        hit->field_0 = centreX - halfW + widget->offsetX + ctx->x;
        hit->field_8 = centreY - halfH + widget->offsetY + ctx->y;
        hit->field_4 = centreX + halfW + widget->offsetX + ctx->x;
        hit->field_C = centreY + halfH + widget->offsetY + ctx->y;
    }
    if (hit->field_0 < 0) {
        hit->field_0 = 0;
    } else if (hit->field_0 > D_800DEA60) {
        return 0;
    }
    if (hit->field_4 < 0) {
        return 0;
    }
    if (hit->field_4 > D_800DEA60) {
        hit->field_4 = D_800DEA60;
    }
    if (hit->field_8 < 0) {
        hit->field_8 = 0;
    } else if (hit->field_8 > D_800E2AB4_de) {
        return 0;
    }
    if (hit->field_C < 0) {
        return 0;
    }
    if (hit->field_C > D_800E2AB4_de) {
        hit->field_C = D_800E2AB4_de;
    }
    if (hit->field_4 <= hit->field_0) {
        hit->field_4 = hit->field_0 + 1;
    }
    if (hit->field_C <= hit->field_8) {
        hit->field_C = hit->field_8 + 1;
    }
    ctx->x = draw->field_0;
    ctx->y = draw->field_8;
    ctx->Rgn = *draw;
    return 1;
}
