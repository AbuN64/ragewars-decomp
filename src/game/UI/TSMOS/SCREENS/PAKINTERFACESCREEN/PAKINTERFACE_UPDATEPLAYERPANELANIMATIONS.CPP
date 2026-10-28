#include "COMMON/ITEMRECAT20V1.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/NAME.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/PAKINTERFACE_UPDATEPLAYERPANELANIMATIONS.H"
#include "FRONTEND/PAKINTERFACE_PULSEIDLEPANELLABELS.H"

/* Steps each channel's fade timer and writes the level its curve currently reaches. */



extern ResourceSmpFlickerCreateFlickerWidget *SmpOverlay_GetSlotValue(s32, s32);
extern void PAKInterface_IncrementNameCharacter(s32);
extern void PAKInterface_DecrementNameCharacter(s32);


void PAKInterface_UpdatePlayerPanelAnimations(s32 arg0) {
    f32 bobValue;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_idx;
    ResourceSmpFlickerCreateFlickerWidget *temp_s0;
    s32 player;
    Blk *temp_a0;
    Blk *temp_a0_2;
    Blk *temp_v0_3;
    Blk *temp_v0_4;
    Blk *temp_v0_5;

    player = 0;
    do {
        temp_a0 = (Blk *)((char *)D_800E54A4 + (player * 0xB68));
        temp_v1 = temp_a0->unk58;
        switch (temp_v1) {
        case 0:
            PAKInterface_PulseIdlePanelLabels(player);
            break;
        case 0xC:
            temp_s0 = SmpOverlay_GetSlotValue(D_800E54A4->root, player);
            temp_v0_4 = (Blk *)((char *)D_800E54A4 + (player * 4));
            bobValue = (Math_Cosf((f32)player + ((f32)temp_v0_4->unk2C * 0.005f)) * 100.0f) + 150.0f;
            temp_s0->value = bobValue;
            temp_a0_2 = (Blk *)((char *)D_800E54A4 + (player * 0xB68));
            temp_v1_2 = temp_a0_2->unkBA0;
            switch (temp_v1_2) {
            case 0:
                temp_v0 = temp_a0_2->unkBA4 + 1;
                temp_a0_2->unkBA4 = temp_v0;
                if (temp_v0 >= 6) {
                    PAKInterface_DecrementNameCharacter(player);
                }
                break;
            case 1:
                temp_v0_2 = temp_a0_2->unkBA4 + 1;
                temp_a0_2->unkBA4 = temp_v0_2;
                if (temp_v0_2 >= 6) {
                    PAKInterface_IncrementNameCharacter(player);
                }
                break;
            case 2:
                break;
            }
            break;
        case 4:
            temp_idx = ((temp_a0->unkB30 - temp_a0->unkB34) * 4) + (player * 0xB68);
            temp_s0 = ((Blk *)((char *)D_800E54A4 + temp_idx))->unkB38;
            temp_v0_5 = (Blk *)((char *)D_800E54A4 + (player * 4));
            bobValue = (Math_Cosf((f32)player + ((f32)temp_v0_5->unk2C * 0.005f)) * 100.0f) + 150.0f;
            temp_s0->value = bobValue;
            break;
        }
        temp_v0_3 = (Blk *)((char *)D_800E54A4 + (player * 4));
        temp_v0_3->unk2C = temp_v0_3->unk2C + arg0;
        player += 1;
    } while (player < 4);
}
