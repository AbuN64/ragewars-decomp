#include "include_asm.h"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/MENU_SCREEN_SETUP.H"
#include "COMMON/RECRECAT4.H"
#include "COMMON/CONTROL.H"
#include "COMMON/MENULISTSCREEN.H"
#include "FRONTEND/80423280_50.H"
#include "RENDER_2/8025DE50_5.H"

#if defined(VERSION_DE)
s32 ScenarioSetup_UpdateSetupTransitionDe(void *root, s32 unused, s32 delta) {
    MenuWidget *item;
    f32 alpha;
    s32 fade;
    s32 count, previous, level;
    SetupScreen *countdown;
    if (D_80154020.ready == 1) {
        D_80154020.ready = 0;
        if (D_80154020.value != -1) {
            D_800E4F60->unk44C->alpha = 0x5A;
            MarkMenuEventHandled();
            func_80298368_de(D_80154020.value);
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
            func_80298368_de(8);
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
        countdown = D_800E4F60;
        previous = countdown->unk3E0;
        count = previous - 1;
        /* fakematch: preserve the target's comparison-based decrement,
         * which a normal saturating countdown would simplify to max(previous - 1, 0). */
        if (count >= 0) count = previous - (previous >= count);
        else count = 0;
        countdown->unk3E0 = count;
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
        level = Frontend_FindWidgetByResourceId(root, 0x312)->alpha;
        fade = level >> 1;
        ScenarioSetup_SetCatalogueAlpha(fade);
        if (fade < 10) {
            D_800E4F60->unk3DC = 3;
            func_8042E988_de(11);
            return 0;
        }
        break;
    case 9:
        fade = Frontend_FindWidgetByResourceId(root, 0x312)->alpha;
        fade = (fade + 1) * 2;
        if (fade > 65) { fade = 65; D_800E4F60->unk3DC = 3; }
        ScenarioSetup_SetCatalogueAlpha(fade);
        if (D_800E4F60->selection == 0) Frontend_SetWidgetFlag08(D_800E4F60->unk448, 1);
        break;
    }
    if (D_800E4F60->unk3DC == 3) {
        D_800E4F60->unk45C += delta;
        if (D_80154020.value == -1) {
            if (D_800E4F60->selection == 0) {
                alpha = Math_Cosf((f32)D_800E4F60->unk45C * 0.0033333334f) * 100.0f + 150.0f;
                item = D_800E4F60->unk448;
                item->alpha = (u32)alpha;
            } else {
                alpha = Math_Cosf((f32)D_800E4F60->unk45C * 0.0033333334f) * 100.0f + 150.0f;
                item = D_800E4F60->item;
                item->alpha = (u32)alpha;
            }
        }
    }
    return 0;
}
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DDAE4[3] = {
    0x25642525, 0x00000000, 0x3E99999A,
};
#endif
