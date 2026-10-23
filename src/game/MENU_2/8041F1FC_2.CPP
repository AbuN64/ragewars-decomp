#include "MENU_2/CHARACTER_SELECTION_IDS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SCREEN.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "RENDER_2/8025DE50_5.H"
#include "FRONTEND/8041BEA8_6.H"

extern s32 func_8040EBD0_de(struct WidgetNode *);
extern struct WidgetNode *func_8041B7FC_de(struct SlotsCode804196C0 *, s32);

/* Advances the selection panels, cursor highlight and character previews. */
s32 func_8041F6C8_de(s32 arg0,s32 arg1,s32 arg2) {
    CVector3 scale;
    f32 temp_f0;
    s16 resource;
    s32 temp_s0;
    s32 phase;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 i;
    s32 empty_slot;
    MenuWidget *highlight;
    MenuWidget *temp_a0_3;
    MenuWidget *temp_a0_5;
    MenuWidget *temp_a0_6;
    MenuWidget *pulse;
    MenuWidget *header;
    MenuWidget *footer;
    struct WidgetNode *widgetNode;

    phase = D_800E42D0->phase;
    switch (phase) {
    case 1:
        header = D_800E42D0->header;
        header->x = (u16) (header->x + (u16)D_800E42D0->headerStep);
        footer = D_800E42D0->footer;
        footer->x = (u16) (footer->x - (u16)D_800E42D0->footerStep);
        temp_v0_2 = D_800E42D0->timer - 1;
        D_800E42D0->timer = temp_v0_2;
        if (temp_v0_2 <= 0) {
            func_8025DF34_de(0xE79);
            func_8040E8D8_de(D_800E42D0->promptItem, 1);
            func_80419F58_de(D_800E42D0->prompt, 4);
            D_800E42D0->phase = 4;
            D_800E42D0->timer = 4;
        }
        break;
    case 2:
        temp_a0_5 = D_800E42D0->header;
        temp_a0_5->x = (u16) (temp_a0_5->x - (u16)D_800E42D0->headerStep);
        temp_a0_6 = D_800E42D0->footer;
        temp_a0_6->x = (u16) (temp_a0_6->x + (u16)D_800E42D0->footerStep);
        temp_v0_4 = D_800E42D0->timer - 1;
        D_800E42D0->timer = temp_v0_4;
        if (temp_v0_4 <= 0) {
            D_800E42D0->phase = 3;
            func_8029973C_de();
            func_80298368_de(D_800E42D0->result);
            return 0;
        }
        break;
    case 3:
        func_802A2360_de();
        break;
    case 4:
        D_800E42D0->timer = D_800E42D0->timer - 1 < 0 ? 0 :
            D_800E42D0->timer - 1 > D_800E42D0->timer ? D_800E42D0->timer : D_800E42D0->timer - 1;
        if ((D_800E42D0->timer <= 0) && (func_80419F38_de(D_800E42D0->prompt) != 0)) {
            func_80419F24_de(D_800E42D0->prompt);
            D_800E42D0->phase = 6;
            D_800E42D0->timer = 4;
            func_8040E8D8_de(D_800E42D0->pulse, 1);
        }
        break;
    case 5:
        func_8025DF34_de(0xE78);
        D_800E42D0->phase = 2;
        D_800E42D0->timer = 4;
        func_8040E8D8_de(D_800E42D0->promptItem, 0);
        func_8040E8D8_de(D_800E42D0->pulse, 0);
        break;
    case 7: break;
    case 6:
        pulse = D_800E42D0->pulse;
        pulse->alpha = (u8) (pulse->alpha + (u8)D_800E42D0->pulseStep);
        temp_v0_6 = D_800E42D0->timer - 1;
        D_800E42D0->timer = temp_v0_6;
        if (temp_v0_6 <= 0) {
            D_800E42D0->pulse->alpha = 0xC8;
            D_800E42D0->phase = 3;
        }
        break;
    }
        if (D_800E42D0->phase == 3) {
            i = 0;
            empty_slot = CHARACTER_EMPTY_SLOT;
            D_800E42D0->clock = (s32) (D_800E42D0->clock + arg2);
            do {
                if (D_800E42D0->players[i].unkC == 1) {
                    if (D_800E42D0->players[i].highlight != 0) {
                        temp_f0 = (func_802B6560_de((f32) i + ((f32) D_800E42D0->clock * 0.0033333334f)) * 70.0f) + 170.0f;
                        highlight = D_800E42D0->players[i].highlight;
                        highlight->alpha=(unsigned int)temp_f0;
                    }
                    widgetNode = func_8041B7FC_de(D_800E42D0->unk4, i);
                    temp_a0_3 = D_800E42D0->players[i].highlight;
                    if ((temp_a0_3->x != (widgetNode->x - 2)) || (temp_a0_3->y != (widgetNode->y - 2))) {
                        func_8025DF34_de(0xE7F);
                        if (func_8040EBD0_de(widgetNode) == 0) {
                            resource = widgetNode->resource;
                            if (resource != empty_slot) {
                                D_800E42D0->players[i].kind = (s32) resource;
                                temp_s0 = func_8041F1D8_de(resource);
                                temp_v1 = func_8041F18C_de(D_800E42D0->players[i].kind);
                                scale.x = D_800E3A58[temp_v1].scale[i];
                                scale.y = D_800E3A58[temp_v1].scale[i];
                                scale.z = D_800E3A58[temp_v1].scale[i];
                                func_8041CAD8_de(D_800E42D0->players[i].model, 9, temp_s0 + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[temp_v1].position[i], D_800E3A58[temp_v1].distance[i], D_800E3A58[temp_v1].light[i]);
                            } else {
                                func_80420850_de(i);
                            }
                        } else {
                            D_800E42D0->players[i].kind = -1;
                        }
                        func_80420438_de(i);
                    } else if (widgetNode->resource == empty_slot) {
                        func_80420850_de(i);
                    }
                    D_800E42D0->players[i].highlight->x = (s16) ((u16) widgetNode->x - 2);
                    D_800E42D0->players[i].highlight->y = (s16) ((u16) widgetNode->y - 2);
                }
                i += 1;
            } while (i < 4);
        }
        return 0;
}
