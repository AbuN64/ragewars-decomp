#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "COMMON/MENU_SCREEN_SETUP.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "RENDER_2/8025DE50_5.H"
extern void ScenarioSetup_SetCatalogueAlpha(s32);
extern void Frontend_SetMenuChoiceResult(s32);
extern void ScenarioSetup_ResetSelectionIndicators(void);

s32 func_8042AFB0_eu_x(void *root, s32 unused, s32 delta) {
    MenuWidget *item;
    f32 alpha;
    u32 fade;
    s32 count;
    if (D_80154020.ready == 1) {
        D_80154020.ready = 0;
        if (D_80154020.value != -1) {
            D_800E4F60->unk44C->alpha = 0x5A;
            MarkMenuEventHandled();
            SmXlate_SwitchScreen(D_80154020.value);
            return 0;
        }
        D_800E4F60->unk44C->alpha = 0xFF;
        D_800E4F60->unk3DC = 9;
        if (D_800E4F60->selection == 0) {
            Frontend_SetWidgetFlag08(D_800E4F60->unk440, 1);
            item = D_800E4F60->unk448;
        } else item = D_800E4F60->unk444;
        Frontend_SetWidgetFlag08(item, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->label, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->unk3F0, 1);
    }
    switch (D_800E4F60->unk3DC) {
    case 1:
        D_800E4F60->left->x += (u16)D_800E4F60->leftCount;
        D_800E4F60->right->x -= (u16)D_800E4F60->rightCount;
        if (--D_800E4F60->unk3E0 <= 0) {
            SoundElement_PlayFlatSound(0xE79);
            Frontend_SetWidgetFlag08(D_800E4F60->unk3E8, 1);
            SmpFlicker_StartFlicker(D_800E4F60->text3E4, 4);
            D_800E4F60->unk3DC = 4;
            D_800E4F60->unk3E0 = 4;
        }
        break;
    case 2:
        D_800E4F60->left->x -= (u16)D_800E4F60->leftCount;
        D_800E4F60->right->x += (u16)D_800E4F60->rightCount;
        if (--D_800E4F60->unk3E0 <= 0) {
            D_800E4F60->unk3DC = 3;
            MarkMenuEventHandled();
            SmXlate_SwitchScreen(8);
            return 0;
        }
        break;
    case 3:
        if (D_800E4F60->unk460 == 0) {
            Tsmos_ActivateControllerState();
            D_800E4F60->unk460 = 1;
            Frontend_SetWidgetFlag08(D_800E4F60->unk458, 0);
        }
        break;
    case 4:
        count = D_800E4F60->unk3E0 - 1;
        D_800E4F60->unk3E0 = count < 0 ? 0 : count;
        if (D_800E4F60->unk3E0 <= 0 && SmpFlicker_IsFlickerIdle(D_800E4F60->text3E4)) {
            SmpFlicker_RestoreFlickerValue(D_800E4F60->text3E4);
            ScenarioSetup_SetCatalogueAlpha(10);
            D_800E4F60->unk3DC = 9;
        }
        break;
    case 5:
        Frontend_SetWidgetFlag08(D_800E4F60->unk458, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->unk3E8, 0);
        ScenarioSetup_ResetSelectionIndicators();
        ScenarioSetup_SetCatalogueAlpha(0);
        D_800E4F60->unk3DC = 2;
        D_800E4F60->unk3E0 = 4;
        Frontend_SetWidgetFlag08(D_800E4F60->unk448, 0);
        SoundElement_PlayFlatSound(0xE78);
        break;
    case 6: case 7: break;
    case 8:
        fade = Frontend_FindWidgetByResourceId(root, 0x31A)->alpha >> 1;
        ScenarioSetup_SetCatalogueAlpha(fade);
        if (fade < 10) {
            D_800E4F60->unk3DC = 3;
            Frontend_SetMenuChoiceResult(11);
            return 0;
        }
        break;
    case 9:
        fade = (Frontend_FindWidgetByResourceId(root, 0x31A)->alpha + 1) * 2;
        if (fade > 65) { fade = 65; D_800E4F60->unk3DC = 3; }
        ScenarioSetup_SetCatalogueAlpha(fade);
        if (D_800E4F60->selection == 0) Frontend_SetWidgetFlag08(D_800E4F60->unk448, 1);
        break;
    }
    if (D_800E4F60->unk3DC == 3) {
        D_800E4F60->unk45C += delta;
        if (D_80154020.value == -1) {
            if (D_800E4F60->selection == 0) {
                alpha = Math_Cosf((f32)D_800E4F60->unk45C * D_800EE144) * 100.0f + 150.0f;
                item = D_800E4F60->unk448;
            } else {
                alpha = Math_Cosf((f32)D_800E4F60->unk45C * D_800EE154) * 100.0f + 150.0f;
                item = D_800E4F60->item;
            }
            item->alpha = (u32)alpha;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8042AFB0_eu_x);
#endif
#endif
