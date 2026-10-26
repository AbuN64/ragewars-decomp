#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "MENU/8043F69C.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/MENU_UI_PROVIDERS.H"
#include "TYPES.H"
#include "GFX/TEXT/802A8A94_5.H"

/* Chooses a text style, updates its colours and scale, then draws the text. */
/* The values func_8043FE3C_de loads by address:
 * 0x800E2490 = 1.25 (float, D_800E2490 in this cartridge's tables)
 * 0x800E2494 = 0.9 (float, unnamed in this cartridge's tables)
 * 0x800E2498 = 0.25 (float, D_800E2498 in this cartridge's tables)
 * 0x800E28D0 = 4.48e-43 (float, D_800E28D0 in this cartridge's tables; not a literal: a variable, its value in the image, since D_800E28D0: `sw` at %lo(D_800E28D0) in func_8040BBB0_de.s)
 * 0x800E28D4 = 3.36e-43 (float, D_800E28D4 in this cartridge's tables)
 * 0x800E249C = 0.0035211267 (float, D_800E249C in this cartridge's tables)
 * 0x800E24A0 = 0.0045045046 (float, D_800E24A0 in this cartridge's tables)
 * 0x800E24A4 = 255.0 (float, D_800E24A4 in this cartridge's tables)
 * 0x800E24A8 = 1.0 (float, D_800E24A8 in this cartridge's tables)
 */
u32 Defs_GetMemorySize(void);

int func_802934F8_de(void);

void Pak_DrawMenuPanel(func_8043FFAC_S2 *menu, TextBoundsText *text, s32 relative);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif



                          /* unable to generate initializer: unknown type */

                          



extern CMenuFontInfo D_800E1E24_de[];

void OnScreen_SetupSpriteMode(s32);

void OnScreen_SetupFillMode(void);

/* unable to generate initializer: unknown type */

void func_8043FE3C_de(func_80254D70_S2 *arg0, func_8043FFAC_S5 *entry, s32 arg2, func_8043FFAC_S2 *arg3, void *arg4, s32 arg5) {
    f32 var_f1;
    s32 temp_f3;
    s32 temp_f3_2;
    s32 temp_f3_3;
    s32 temp_f3_4;
    s32 temp_f3_5;
    s32 temp_f3_6;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_s0;
    u32 temp_v1;
    u8 var_s5;
    CMenuFontInfo *temp_s1;

    var_s5 = 1;
    if ((func_802934F8_de() == 0) || !(arg0->unk8 & 0x40000000)) {
        if (D_80145088.settings.local != 0) {
            if (arg0->unk8 < 0) {
                if (Defs_GetMemorySize() == 0x400000) {
                    goto block_5;
                }
            }
        }
    } else {
block_5:
        arg3->unk38 = 0;
    }
    if (arg0->unk8 & 0x08000000) {
        if (arg3->unk3C != 0) {
            arg3->unk38 = 0;
        }
        Pak_DrawMenuPanel(arg3, (TextBoundsText *)arg0, 1);
        Pak_DrawMenuPanel(arg3, (TextBoundsText *)arg0, 0);
        var_s5 = 0;
    }
    if (arg3->unk38 == 0) {
        var_s5 = 0;
    }
    temp_v1 = arg0->unk8 & 0x3FE0;
    var_a0 = 0;
    switch (temp_v1) {
    case 0x20: var_a0 = 0; break;
    case 0x40: var_a0 = 1; break;
    case 0x80: var_a0 = 2; break;
    case 0x100: var_a0 = 3; break;
    case 0x200: var_a0 = 4; break;
    case 0x400: var_a0 = 5; break;
    case 0x800: var_a0 = 6; break;
    case 0x1000: var_a0 = 7; break;
    case 0x2000: var_a0 = 8; break;
    default: var_a0 = 0; break;
    }
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    var_a0 += g_languageIndex * 9;
#endif
    temp_s1 = &D_800E1E24_de[var_a0];
    var_s0 = temp_s1->unk0;
    if (arg5 != 0) {
        var_s0 = 6;
    }
    if (D_800E1E20 != var_s0) {
        switch (var_s0) {                           /* irregular */
        case 0:
            func_802A84F8_de();
            break;
        case 1:
            func_802A84F8_de();
            func_802A8710_de();
            break;
        case 2:
            func_802A84F8_de();
            func_802A8800_de();
            break;
        case 6:
            func_802A84F8_de();
            func_802A8710_de();
            D_80147150 = 1;
            break;
        }
        D_800E1E20 = var_s0;
    }
    if (entry->unk0 == arg3->unk0) {
        var_f1 = 1.25f;
    } else if (!(arg0->unk8 & 0x01000000)) {
        var_f1 = 0.25f;
    } else {
        var_f1 = 0.9f;
    }
    temp_f3 = (s32) ((f32) temp_s1->unk15 * var_f1);
    var_a0_2 = 0xFF;
    if (temp_f3 < 0x100) {
        var_a0_2 = temp_f3;
    }
    temp_f3_2 = (s32) ((f32) temp_s1->unk16 * var_f1);
    var_a1 = 0xFF;
    if (temp_f3_2 < 0x100) {
        var_a1 = temp_f3_2;
    }
    temp_f3_3 = (s32) ((f32) temp_s1->unk17 * var_f1);
    var_a2 = 0xFF;
    if (temp_f3_3 < 0x100) {
        var_a2 = temp_f3_3;
    }
    temp_f3_4 = (s32) ((f32) temp_s1->unk18 * var_f1);
    var_a3 = 0xFF;
    if (temp_f3_4 < 0x100) {
        var_a3 = temp_f3_4;
    }
    func_802AAB3C_de(var_a0_2, var_a1, var_a2, var_a3,
        (s32)((f32)temp_s1->unk19 * var_f1) > 0xFF ? 0xFF : (s32)((f32)temp_s1->unk19 * var_f1),
        (s32)((f32)temp_s1->unk1A * var_f1) > 0xFF ? 0xFF : (s32)((f32)temp_s1->unk1A * var_f1));
    D_801376F8.shadowX = (s32) temp_s1->unk14;
    D_801376F8.shadowY = (s32) temp_s1->unk14;
    func_802AAB68_de(temp_s1->unkC * (f32) (D_800E28D0) * 0.0035211267f, temp_s1->unk10 * (f32) (D_800E28D4) * 0.0045045046f);
    if (var_s5 != 0) {
        var_s5 = temp_s1->unk14;
    }
    func_802A8F28_de(arg4, entry->unk14, entry->unk1C, (s32) (arg3->alpha * (arg3->fade * 255.0f)), 0, (s32) var_s5, 1.0f, 1.0f);
}

void func_804402DC_de(MenuOption *arg0, MenuOptionBox *box, s32 dir, MenuOptionFade *arg3) {
    s32 var_v1;
    f32 right;
    f32 bottom;
    f32 width;
    f32 height;
    s32 *active;

    if (((func_802934F8_de() != 0) && (arg0->flags & 0x40000000)) || ((D_80145088.settings.local != 0) && (arg0->flags < 0) && (Defs_GetMemorySize() == 0x400000))) {
        arg3->highlighted = 1;
        if (D_800E1E20 != 3) {
            D_800E1E20 = 3;
        }
        OnScreen_SetupFillMode();
        width = (f32)box->width * box->scaleX;
        height = (f32)box->height * box->scaleY;
        bottom = (f32)box->top;
        right = (f32)box->left;
        right += width;
        bottom += height;
        active = &D_80145088.status[7];
        if (*active != 0) {
            if (D_80145088.settings.local == 0) {
                var_v1 = 0x80;
            } else if (arg0->flags < 0) {
                var_v1 = 0xFF;
            } else {
                var_v1 = 0xC0;
            }
        } else {
            var_v1 = 0x80;
        }
        OnScreen_DrawBevelBox(box->left, box->top, (s32)right, (s32)bottom, 1, 0, 0, 0, 0, var_v1);
        return;
    }
    if (D_800E1E20 != 3) {
        D_800E1E20 = 3;
        OnScreen_SetupSpriteMode((s32) (arg3->fade * (arg3->alpha * D_800DE47C_de)));
    }
    func_802AAC28_de(arg0->resource, 0, (s16)box->left, (s16)box->top, box->scaleX, box->scaleY, 1);
}
