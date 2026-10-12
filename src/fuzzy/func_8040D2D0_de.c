#include "types.h"
typedef struct TextRect { s32 x0, x1, y0, y1; } TextRect;
typedef struct TextArgs {
    s32 x, y, flags; f32 scaleX, scaleY; u8 alpha; u8 pad[3]; s32 extra[4];
} TextArgs;
typedef struct TextWidget {
    char pad0[0x12]; u16 flags; char pad14[0x18];
    u8 font, style, fontAlt, styleAlt, fontSelected, styleSelected;
    u16 align; s32 stringId; u8 *text;
} TextWidget;
typedef struct TextGlyph {
    char pad0[4]; s8 width, height; char pad6; s8 offsetY;
} TextGlyph;
typedef struct TextFont { char pad0[4]; TextGlyph glyphs[1]; } TextFont;
typedef struct TextSprite {
    s32 color; f32 x, y, width, height; u16 glyph; u16 pad16;
} TextSprite;
typedef struct TextBatch { TextRect area; TextSprite *cursor; s32 count; } TextBatch;
extern s32 D_8014D570, D_8014D710, D_8014D714;
extern s32 D_8014D564, D_8014D568, D_8014D56C, D_800DEA60;
extern s32 D_8014D584, D_8014D588, D_8014D58C;
extern TextRect D_8014D580;
extern TextFont *D_8014D560;
extern TextBatch D_8014D590[];
extern TextSprite *D_8014D5A0[];
extern s32 D_8014D5A4[];
u8 *func_80411D78_de(s32);
s32 func_8040E0D4_de(TextRect *, TextRect *, TextWidget *, TextArgs *);
s32 func_8040F488_de(TextRect *, TextRect *);
void func_802A1898_de(s32 *, s32 *, s32 *, s32 *);
void func_802A1870_de(s32, s32, s32, s32);
void func_8040CAB0_de(void);
s32 func_802A0238_de(u8 *);
TextFont *func_8041200C_de(s32);
s16 func_80411C60_de(s32);
s16 func_80411CD0_de(s32);
s16 func_80411C98_de(s32);
s32 func_8040F160_de(s32, u8 *, s32);
void *func_802A15E4_de(s32);
void func_8029FE38_de(char *, s32, s32, s32 (*)(char *, char *));
s32 D_0040F570(char *, char *);
static inline void textBegin(u8 font, u8 style) {
    func_802A1898_de(&D_8014D580.x0, &D_8014D580.y0,
                   &D_8014D580.x1, &D_8014D580.y1);
    D_8014D710 = (s8)font;
    D_8014D714 = (s8)style;
    D_8014D560 = func_8041200C_de((s8)font);
    D_8014D564 = func_80411C60_de((s8)font);
    D_8014D568 = func_80411CD0_de((s8)font);
    D_8014D56C = func_80411C98_de((s8)font);
}
static inline s32 textOverlaps(TextBatch *next) {
    s32 i;
    TextBatch *batch;
    for (i = 0; i < D_8014D570; i++) {
        batch = &D_8014D590[i];
        if (next->area.x1 < batch->area.x0 || batch->area.x1 < next->area.x0 ||
            next->area.y1 < batch->area.y0 || batch->area.y1 < next->area.y0) continue;
        return 1;
    }
    return 0;
}
void func_8040D2D0_de(TextWidget *widget, TextArgs args) {
    TextRect box, saved, clip, area, current;
    s32 clipped, length, width, mismatch, count, i, tempX, tempY;
    u8 font, style;
    u8 *text;
    f32 x, y, sub; u8 *resolved;
    TextBatch *batch;
    TextSprite *sprites, *sprite;
    TextGlyph *glyph;
    u32 color; s16 glyphId;
    resolved = widget->text;
    clipped = 0;
    if (!resolved) {
        if (widget->stringId == -1) return;
        resolved = func_80411D78_de(widget->stringId);
    }
    text=resolved;
    if (!func_8040E0D4_de(&area, &box, widget, &args)) return;
    if (widget->flags & 0x200) {
        func_802A1898_de(&saved.x0, &saved.y0, &saved.x1, &saved.y1);
        clip = saved;
        if (!func_8040F488_de(&clip, &box)) return;
        clipped = 1;
        func_802A1870_de(clip.x0, clip.y0, clip.x1, clip.y1);
    }
    length = func_802A0238_de(text);
    if (args.flags & 0x100) { font=widget->fontSelected; style=widget->styleSelected; }
    else if (args.flags & 0x40) { font=widget->fontAlt; style=widget->styleAlt; }
    else { font=widget->font; style=widget->style; }
    if ((s8)font == -1) font=widget->font;
    if ((s8)style == -1) style=widget->style;
    if (D_8014D570) {
        func_802A1898_de(&current.x0, &current.y0, &current.x1, &current.y1);
        mismatch = 1;
        if (current.x0 == D_8014D580.x0) {
            mismatch=1;
            if (current.y0 == D_8014D588) {
                mismatch=1;
                if (current.x1 == D_8014D584) mismatch=current.y1 != D_8014D58C;
            }
        }
        if (mismatch || D_8014D710 != (s8)font || D_8014D714 != (s8)style) {
            if (D_8014D570) func_8040CAB0_de();
            textBegin(font, style);
        }
    } else textBegin(font, style);
    width = func_8040F160_de((s8)font, text, length) * args.scaleX;
    x = 0.0f;
    switch (widget->align & 3) {
        case 0: x=area.x0; break;
        case 1: x=(area.x0+area.x1)/2-width/2; break;
        case 2: x=area.x1+1-width; break;
    }
    y = 0.0f;
    switch (widget->align & 12) {
        case 0: y=area.y0; y-=D_8014D56C*args.scaleY; break;
        case 4:
            y=(area.y0+area.y1)/2;
            y-=D_8014D56C*args.scaleY;
            sub=(D_8014D568/2)*args.scaleY;
            y-=sub; break;
        case 8:
            sub=(D_8014D568+D_8014D56C)*args.scaleY;
            y=area.y1; y-=sub; break;
    }
    batch=&D_8014D590[D_8014D570];
    tempX=x; batch->area.x0=tempX; batch->area.x1=tempX+width;
    tempY=(s32)y+(s32)(D_8014D56C*args.scaleY);
    batch->area.y0=tempY; batch->area.y1=tempY+(s32)(D_8014D568*args.scaleY);
    if (batch->area.x0 >= batch->area.x1) batch->area.x1=batch->area.x0+1;
    if (batch->area.y0 >= batch->area.y1) batch->area.y1=batch->area.y0+1;
    if (textOverlaps(batch)) { func_8040CAB0_de(); textBegin(font, style); }
    sprites=func_802A15E4_de(length*sizeof(TextSprite));
    D_8014D590[D_8014D570].cursor=sprites;
    color=((u32)args.alpha<<24)|0xFFFFFF;
    count=0;
    sprite=sprites;
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
        if (x<D_800DEA60 && x+sprite->width>0.0f) { sprite++; count++; }
        x=x+glyph->width*args.scaleX+D_8014D564*args.scaleX;
    }
    if (clipped) func_802A1870_de(saved.x0, saved.y0, saved.x1, saved.y1);
    if (count>0) {
        D_8014D590[D_8014D570].count=count;
        func_8029FE38_de((char *)D_8014D590[D_8014D570].cursor, count, sizeof(TextSprite), D_0040F570);
        D_8014D570++;
        if (D_8014D570>=16) func_8040CAB0_de();
    }
}
