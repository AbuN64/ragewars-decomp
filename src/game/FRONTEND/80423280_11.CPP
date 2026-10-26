#include "include_asm.h"
#include "COMMON/RECRECAT4.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SCREEN.H"
#include "FRONTEND/MENUTRANSITIONSIGNAL.H"
#include "COMMON/CONTROL.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "FRONTEND/80423280_50.H"
#include "RENDER_2/8025DE50_5.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
/* Advances the menu transition state and updates its visual effects. */










/* The values ScenarioSetup_UpdateSetupTransition loads by address:
 * 0x800E1AF4 = 0.0033333334 (float, D_800EE144 in this cartridge's tables)
 * 0x800E1AF8 = 100.0 (float, D_800EE148 in this cartridge's tables)
 * 0x800E1AFC = 150.0 (float, unnamed in this cartridge's tables)
 * 0x800E1B00 = 2147483600.0 (float, D_800EE150 in this cartridge's tables)
 * 0x800E1B04 = 0.0033333334 (float, D_800EE154 in this cartridge's tables)
 * 0x800E1B08 = 100.0 (float, D_800EE158 in this cartridge's tables)
 * 0x800E1B0C = 150.0 (float, unnamed in this cartridge's tables)
 * 0x800E1B10 = 2147483600.0 (float, D_800EE160 in this cartridge's tables)
 */

void Tsmos_ActivateControllerState(void);

void SmpFlicker_RestoreFlickerValue(void *);

s32 SmpFlicker_IsFlickerIdle(void *);

void SmpFlicker_StartFlicker(void *, int);

void func_80298368_de(s32);

extern MenuTransitionSignal D_80154020;

extern ListScreenScreen *D_800E4F60;

s32 ScenarioSetup_UpdateSetupTransition(void *root, s32 arg1, s32 arg2) {
    ListScreenScreen *countdown;
    f32 var_f0;
    s32 temp_a2;
    s32 temp_s0; 
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a1;
    s32 var_v0;
    ListScreenItem *closeLeft;
    ListScreenItem *closeRight;
    ListScreenItem *openLeft;
    ListScreenItem *openRight;
    void *var_a0;
    ListScreenItem *var_a0_2;
    void *var_a0_3;

    if (D_80154020.trigger == 1) {
        D_80154020.trigger = 0;
        if (D_80154020.selection != -1) {
            D_800E4F60->unk_44C->alpha = 0x5A;
            MarkMenuEventHandled();
            func_80298368_de(D_80154020.selection);
            return 0;
        }
        D_800E4F60->unk_44C->alpha = 0xFF;
        D_800E4F60->unk_3DC = 9;
        if (D_800E4F60->selection == 0) {
            Frontend_SetWidgetFlag08(D_800E4F60->unk_440, 1);
            var_a0 = D_800E4F60->unk_448;
        } else {
            var_a0 = D_800E4F60->unk_444;
        }
        Frontend_SetWidgetFlag08(var_a0, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->label, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->unk_3F0, 1);
        goto block_7;
    }
block_7:
    temp_v0 = D_800E4F60->unk_3DC;
    switch (temp_v0) {
    case 1:
        openLeft = D_800E4F60->left;
        openLeft->x = (u16) (openLeft->x + (u16)D_800E4F60->leftCount);
        openRight = D_800E4F60->right;
        openRight->x = (u16) (openRight->x - (u16)D_800E4F60->rightCount);
        temp_v0_2 = D_800E4F60->unk_3E0 - 1;
        D_800E4F60->unk_3E0 = temp_v0_2;
        if (temp_v0_2 <= 0) {
            SoundElement_PlayFlatSound(0xE79);
            Frontend_SetWidgetFlag08(D_800E4F60->unk_3E8, 1);
            SmpFlicker_StartFlicker(D_800E4F60->text3E4, 4);
            D_800E4F60->unk_3DC = 4;
            D_800E4F60->unk_3E0 = 4;
        }
        break;
    case 2:
        closeLeft = D_800E4F60->left;
        closeLeft->x = (u16) (closeLeft->x - (u16)D_800E4F60->leftCount);
        closeRight = D_800E4F60->right;
        closeRight->x = (u16) (closeRight->x + (u16)D_800E4F60->rightCount);
        temp_v0_3 = D_800E4F60->unk_3E0 - 1;
        D_800E4F60->unk_3E0 = temp_v0_3;
        if (temp_v0_3 <= 0) {
            D_800E4F60->unk_3DC = 3;
            MarkMenuEventHandled();
            func_80298368_de(8);
            return 0;
        }
        break;
    case 3:
        if (D_800E4F60->unk_460 == 0) {
            Tsmos_ActivateControllerState();
            var_a1 = 0;
            var_a0_3 = D_800E4F60->unk_458;
            D_800E4F60->unk_460 = 1;
            Frontend_SetWidgetFlag08(var_a0_3, var_a1);
        }
        break;
    case 4:
        countdown = D_800E4F60;
        temp_v1 = countdown->unk_3E0;
        temp_v0_4 = temp_v1 - 1;
        if (temp_v0_4 >= 0) {
            var_v0 = temp_v1 - (temp_v1 >= temp_v0_4);
        } else {
            var_v0 = 0;
        }
        countdown->unk_3E0 = var_v0;
        
        if ((((ListScreenScreen *) D_800E4F60)->unk_3E0 <= 0) && (SmpFlicker_IsFlickerIdle(D_800E4F60->text3E4) != 0)) {
            SmpFlicker_RestoreFlickerValue(D_800E4F60->text3E4);
            ScenarioSetup_SetCatalogueAlpha(0xA);
            D_800E4F60->unk_3DC = 9;
        }
        break;
    case 5:
        Frontend_SetWidgetFlag08(D_800E4F60->unk_458, 1);
        Frontend_SetWidgetFlag08(D_800E4F60->unk_3E8, 0);
        ScenarioSetup_ResetSelectionIndicators();
        ScenarioSetup_SetCatalogueAlpha(0);
        D_800E4F60->unk_3DC = 2;
        D_800E4F60->unk_3E0 = 4;
        Frontend_SetWidgetFlag08(D_800E4F60->unk_448, 0);
        SoundElement_PlayFlatSound(0xE78);
        break;
    case 8:
        temp_v0 = ((ListScreenItem *)Frontend_FindWidgetByResourceId(root, 0x316U))->alpha;
        temp_s0 = temp_v0 >> 1;
        ScenarioSetup_SetCatalogueAlpha(temp_s0);
        if (temp_s0 < 0xA) {
            D_800E4F60->unk_3DC = 3;
            func_8042E988_de(0xB);
            return 0;
        }
        break;
    case 9:
        temp_s0 = ((ListScreenItem *)Frontend_FindWidgetByResourceId(root, 0x316U))->alpha;
        temp_s0 = (temp_s0 + 1) * 2;
        if (temp_s0 >= 0x42) {
            temp_s0 = 0x41;
            D_800E4F60->unk_3DC = 3;
        }
        ScenarioSetup_SetCatalogueAlpha(temp_s0);
        var_a1 = 1;
        if (D_800E4F60->selection == 0) {
            var_a0_3 = D_800E4F60->unk_448;
            Frontend_SetWidgetFlag08(var_a0_3, var_a1);
        }
        break;
    default:
        break;
    }
    if (D_800E4F60->unk_3DC == 3) {
            temp_a2 = D_800E4F60->unk_45C + arg2;
            D_800E4F60->unk_45C = temp_a2;
            if (D_80154020.selection == -1) {
                if (D_800E4F60->selection == 0) {
                    var_f0 = (Math_Cosf((f32) temp_a2 * 0.0033333334f) * 100.0f) + 150.0f;
                    var_a0_2 = D_800E4F60->unk_448;
                    var_a0_2->alpha = (u8) (u32) var_f0;
                } else {
                    var_f0 = (Math_Cosf((f32) temp_a2 * 0.0033333334f) * 100.0f) + 150.0f;
                    var_a0_2 = D_800E4F60->item;
                    var_a0_2->alpha = (u8) (u32) var_f0;
                }
            }
        }
        return 0;
}
#endif

#if defined(VERSION_US)
char rodata_unresolved_800DC794[12] =
    "\000\000\000\000\023RAX_INT";
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE164[3] = {
    0x00BA00C9, 0x00BB00C2, 0x00BC00BF,
};
#endif
