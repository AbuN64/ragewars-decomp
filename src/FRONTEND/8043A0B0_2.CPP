#include "include_asm.h"
#include "FRONTEND/8040B45C_32.H"
#include "RENDER_2/8025DE50_5.H"

INCLUDE_RODATA("data_800C", rodata_func_8043A890_de_800E1FFC);

INCLUDE_ASM("ovl_80400000", func_80439EC4_de);

#ifdef NON_MATCHING
#include "TYPES.H"

typedef struct { f32 x, y, z; } ResultVector;
typedef struct { char bytes[0xC0]; } ResultBadge;
typedef struct { char pad0[0x4AC]; s32 selection; char pad4B0[0x1C]; s32 mode; } ResultPanel;
typedef struct { void *window; s32 unk4; ResultPanel panels[4]; char pad1348[0x28]; ResultBadge badges[4]; } ResultScreen;
typedef struct { char pad0[0x78]; u8 active; char pad79[0x1D]; } ResultPlayer;
typedef struct { u16 resource; char pad2[0x4A]; } ResultResource;
typedef struct { char pad0[0x10]; u8 color; } ResultWidget;
extern ResultScreen *D_800E59E0;
extern ResultPlayer D_80146398[];
extern ResultResource D_800E19DE[];
extern f32 D_800E1FC4, D_800DDF98_de, D_800DDF9C, D_800E1FD0, D_800E1FD4, D_800DDFA8, D_800DDFAC_de;
extern s32 func_802744D4_de(void);
extern s32 func_80439B5C_de(ResultBadge *, s32, ResultVector, ResultVector);
extern void func_80439BE0_de(ResultBadge *, ResultVector);
extern void func_80439C30_de(ResultBadge *, ResultVector);
extern ResultWidget *func_8040EC30_de(void *, s32);
extern void func_8043BA5C_de(s32, s32);

s32 func_8043A330_de(void) {
    ResultVector scale, position, rotation, offset;
    ResultWidget *widget;
    s32 i, angle = 0, mode;
    func_802A23C4_de(1);
    scale.x = D_800E1FC4; scale.y = D_800E1FC4; scale.z = D_800E1FC4;
    offset.x = 0.0f; offset.y = D_800DDF98_de; offset.z = 0.0f;
    position.x = 0.0f; position.y = 0.0f; position.z = D_800DDF9C;
    rotation.x = 0.0f; rotation.y = 0.0f; rotation.z = 0.0f;
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0: position.y = D_800E1FD0; break;
        case 1: position.y = D_800E1FD4; break;
        case 2: position.y = D_800DDFA8; break;
        case 3: position.y = D_800DDFAC_de; break;
        }
        rotation.y = (f32)(angle + func_802744D4_de() % 10);
        angle += 45;
        func_80439B5C_de(&D_800E59E0->badges[i], 0, scale, position);
        func_80439BE0_de(&D_800E59E0->badges[i], rotation);
        func_80439C30_de(&D_800E59E0->badges[i], offset);
    }
    for (i = 0; i < 4; i++) {
        if (D_80146398[i].active == 1) {
            widget = func_8040EC30_de(D_800E59E0->window, D_800E19DE[i].resource);
            func_8040E928_de(widget, 0);
            widget->color = 35;
            mode = D_800E59E0->panels[i].mode;
            if (mode == 1) {
                D_800E59E0->panels[i].selection = 0;
                func_8043BA5C_de(i, 0);
            } else if (mode == 0) {
                D_800E59E0->panels[i].selection = 5;
                func_8043BA5C_de(i, 5);
            } else if (mode == 2) {
                D_800E59E0->panels[i].selection = 0;
                func_8043BA5C_de(i, 0);
            }
        }
    }
    func_8025DF34_de(0xE78);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8043A330_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct DraftWidget3A5F8 { u8 pad[0x14]; u16 x; } DraftWidget3A5F8;
typedef struct DraftPanel3A5F8 { void *widget; u8 pad[0x4CC]; } DraftPanel3A5F8;
typedef struct DraftScreen3A5F8 {
    void *root; u8 pad4[0x4D0-4]; DraftPanel3A5F8 panels[3];
    void *fourth; u8 pad1344[4]; DraftWidget3A5F8 *left;
    u16 pad134C, leftStep; DraftWidget3A5F8 *right; u16 pad1354, rightStep;
    s32 state, timer; void *animation, *widget, *returnScreen;
} DraftScreen3A5F8;
typedef struct DraftRow3A5F8 { u16 id; u8 pad[2]; } DraftRow3A5F8;
typedef struct DraftIds3A5F8 { DraftRow3A5F8 rows[5]; u8 pad[0x38]; } DraftIds3A5F8;
extern DraftScreen3A5F8 *D_800E59E0;
extern DraftIds3A5F8 D_800E5A06[4];
extern void func_8040E8D8_de(void *, s32), func_80419F58_de(void *, s32);
extern void func_8029973C_de(void), func_80298368_de(void *), func_802A2360_de(void), func_80419F24_de(void *);
extern s32 func_80419F38_de(void *);
extern void *func_8040EC30_de(void *, s32);
s32 func_8043A5F8_de(void)
{
    DraftScreen3A5F8 *screen;
    s32 i, j, timer;
    screen = D_800E59E0;
    switch (screen->state) {
    case 1:
        screen->left->x += screen->leftStep;
        screen->right->x -= screen->rightStep;
        if (--screen->timer <= 0) {
            func_8025DF34_de(0xE79);
            func_8040E8D8_de(D_800E59E0->widget, 1);
            func_80419F58_de(D_800E59E0->animation, 4);
            D_800E59E0->state = 4;
            D_800E59E0->timer = 4;
        }
        break;
    case 2:
        screen->left->x -= screen->leftStep;
        screen->right->x += screen->rightStep;
        if (--screen->timer <= 0) {
            screen->state = 3;
            func_8029973C_de();
            func_80298368_de(D_800E59E0->returnScreen);
            return 0;
        }
        break;
    case 3: func_802A2360_de(); return 0;
    case 4:
        timer = screen->timer - 1;
        if (timer < 0) timer = 0;
        else timer = screen->timer - (screen->timer < timer ^ 1);
        screen->timer = timer;
        if (D_800E59E0->timer > 0) return 0;
        if (!func_80419F38_de(D_800E59E0->animation)) return 0;
        func_80419F24_de(D_800E59E0->animation);
        D_800E59E0->state = 3;
        break;
    case 5:
        func_8025DF34_de(0xE78);
        D_800E59E0->state = 2;
        D_800E59E0->timer = 4;
        func_8040E8D8_de(D_800E59E0->widget, 0);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5; j++) {
                func_8040E8D8_de(func_8040EC30_de(D_800E59E0->root, D_800E5A06[i].rows[j].id), 0);
            }
            if (i < 3) func_8040E8D8_de(D_800E59E0->panels[i].widget, 0);
            else func_8040E8D8_de(D_800E59E0->fourth, 0);
        }
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8043A5F8_de);
#endif

INCLUDE_ASM("ovl_80400000", func_8043A890_de);

#ifdef NON_MATCHING
/* Draw callback of the four-player results screen D_800E59E0: on draw event 1 in state 3 it resets the
   fill colour to opaque white, clips the display list to each active player's viewport in D_800E41C0 to
   draw that panel through func_8041C7F4_de, restores the full-screen clip, and then draws each ready
   player's badge that func_80439CC8_de accepts at alpha 150 through func_804399D0. Returns zero. */

extern struct FourPlayerResultsScreen *D_800E59E0;
extern s32 D_800D15E0;
extern f32 D_800D15E4[4];
extern struct Shape_typemap_165 D_800E41C0[];

extern void func_8041C7F4_de(struct ResultsPlayerPanel *);
extern s32 func_80439CC8_de(char *);
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_804399D0(char *);
#else
#endif
#if defined(VERSION_DE)
extern void func_804399D0(char *);
#else
extern void func_804397F0_auto(char *);
#endif

s32 func_8043A890_de(void *arg0, void *arg1, s32 event) {
    s32 i;

    if (event == 1 && D_800E59E0->state == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        for (i = 0; i < 4; i++) {
            if (D_800E59E0->panels[i].state == 1 || D_800E59E0->panels[i].state == 2) {
                gDPSetScissor(D_80110634++, G_SC_NON_INTERLACE, D_800E41C0[i].field_0, D_800E41C0[i].field_4,
                              D_800E41C0[i].field_8, D_800E41C0[i].field_C);
                func_8041C7F4_de(&D_800E59E0->panels[i]);
            }
        }
        gDPSetScissor(D_80110634++, G_SC_NON_INTERLACE, 0, 0, D_800E28D0 - 1, D_800E28D4 - 1);
        for (i = 0; i < 4; i++) {
            if (D_800E59E0->panels[i].state == 1 && func_80439CC8_de(D_800E59E0->badges[i]) != 0) {
                D_800D15E0 = 1;
                D_800D15E4[3] = 150.0f;
#if defined(VERSION_DE)
                
#if defined(VERSION_DE)
func_804399D0
#else
func_804397F0_auto
#endif
(D_800E59E0->badges[i]);
#else
                
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_804399D0
#else
func_804397E8_de
#endif
(D_800E59E0->badges[i]);
#endif
                D_800D15E0 = 0;
                D_800D15E4[3] = 255.0f;
            }
        }
    }
    return 0;
}
#endif
