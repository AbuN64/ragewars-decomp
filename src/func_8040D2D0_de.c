#include "shared/text_render.h"
#include "audio_callbacks.h"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/rectangle_draw.h"
#include "span_16E000/code_8040C780.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_80411B68.h"
#include "types.h"
extern struct Shape_typemap_165 D_8014D580;
extern BatchRec D_8014D590[];
s32 func_8040E0D4_de(struct Shape_typemap_165 *, struct Shape_typemap_165 *, TextWidget *, DrawArgs *);
s32 func_8040F488_de(struct Shape_typemap_165 *, struct Shape_typemap_165 *);
void func_802A1870_de(unsigned int, unsigned int, unsigned int, unsigned int);
s32 func_802A0238_de(u8 *);
Element_func_8041200C_de *func_8041200C_de(s32);
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
    if (!func_8040E0D4_de(&area, &box, widget, &args)) return;
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
