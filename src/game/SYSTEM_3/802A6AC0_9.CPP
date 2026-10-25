#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "TYPES.H"
#include "GFX/TEXT/802A8A94_5.H"
extern void Text_SetupSpriteMode(s32 color);

/* Draws one of the two gauges of the head-up panel, the first at hud->bars[0] and the second at
   hud->bars[1]: steps the gauge's scripted mover, walks its shown amount toward the gauge's target
   count by eight a frame up or four a frame down without passing it, fills the bar from x+80 to the
   right margin in the gauge's own colour at the options fade D_801462DE times 180/255, and draws the
   gauge's label at the bar's left edge. The first gauge also draws its two end caps, at the screen
   edges, unit width and one and a half times the panel scale. */







extern s32 D_800E28D0;

extern s32 Camera_IsSequenceInWindow(void);
extern s32 func_802934F8_de(void);
extern s32 func_8040C474_de(void);

extern void func_802A7AA4_de(void *mover);
extern void func_802AAA54_de(s32 x0, s32 y0, s32 x1, s32 y1, s32 red, s32 green, s32 blue, u8 alpha);




void func_802A7660_de(Hud *hud, s32 which) {
    Bar *bar;
    f32 scale;
    f32 wide;
    f32 target;
    f32 shift;
    s32 red;
    s32 green;
    s32 blue;
    s32 offset;
    s32 x;
    s32 y;
    s32 left;
    s32 right;
    s32 inset;
    u8 *fade;
    s32 value;

    if (Camera_IsSequenceInWindow() != 0) {
        return;
    }
    if (func_802934F8_de() == 0) {
        return;
    }
    wide = func_8040C474_de() == 0 ? 0.75f : 1.0f;
    scale = D_80140FE8_de.object->b / (f32) D_800E28D4;
    scale = scale * wide;
    switch (which) {
    case 1:
        bar = &hud->bars[0];
        target = (f32) hud->bars[0].target;
        red = 0x1D;
        green = 0x53;
        blue = 0xE2;
        offset = 0x1F;
        break;
    case 2:
        bar = &hud->bars[1];
        target = (f32) hud->bars[1].target;
        red = 0x8B;
        green = 0xB9;
        blue = 0x46;
        offset = 0x30;
        break;
    default:
        return;
    }
    x = (s32) bar->x;
    y = (s32) (bar->y + (f32) offset * scale);
    Text_SetupFillMode();
    func_802A7AA4_de(bar);
    if (bar->state == 1) {
        value = bar->fill;
        if ((f32) value < target) {
            value += 8;
            bar->fill = value;
            if (target < (f32) value) {
                bar->fill = (s32) target;
            }
        } else if (target < (f32) value) {
            value -= 4;
            bar->fill = value;
            if ((f32) value < target) {
                bar->fill = (s32) target;
            }
        }
    }
    left = x + 0x50;
    inset = x - 0x70;
    right = inset + D_800E28D0;
    fade = &D_801462C8.hudFade;
    func_802AAA54_de(left, (s32) ((f32) y + scale * 9.0f),
                  left + ((right - left) * bar->fill) / 100,
                  (s32) ((f32) y + scale * 15.0f), red, green, blue,
                  (u8) (*fade * 180 / 255));
    Text_SetupSpriteMode(*fade);
    if (which == 1) {
        shift = scale * 27.0f;
        func_802AAC28_de(0x202, 0, (s16) (x + 0x46), (s16) (s32) (bar->y + shift), 1.0f, scale * 1.5f, which);
        func_802AAC28_de(0x203, 0, (s16) (D_800E28D0 + x - 0x6D), (s16) (s32) (bar->y + shift), 1.0f, scale * 1.5f, which);
        func_802A84F8_de();
        func_802AAB68_de(0.4f, scale * 0.4f);
        func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
        func_802A8F28_de(hud->bars[0].label, left, y - 2, *fade, 0, 0, 1.0f, 1.0f);
    } else {
        func_802A84F8_de();
        func_802AAB68_de(0.4f, scale * 0.4f);
        func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
        func_802A8F28_de(hud->bars[1].label, left, y - 2, *fade, 0, 0, 1.0f, 1.0f);
    }
}
