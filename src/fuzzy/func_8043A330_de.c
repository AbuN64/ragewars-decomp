#include "types.h"

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
extern void func_8040E928_de(ResultWidget *, s32);
extern void func_8043BA5C_de(s32, s32);
extern void func_8025DF34_de(s32);

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
