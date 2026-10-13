#include "shared/character_selection_ids.h"
#include "types.h"
/* Animates selection panels, tracks each player's focused character and updates the preview and pulsing highlight. */
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct SelectionSprite { char pad0[12]; s16 unkC; char padE[2]; u8 unk10; char pad11[3]; s16 unk14, unk16; } SelectionSprite;
typedef struct SelectionSlot {
    s32 unk0, unk4; SelectionSprite *unk8; s32 unkC, unk10, unk14;
    char pad18[8]; char preview[0x4A8];
} SelectionSlot;
typedef struct CharacterSelectionScreen {
    SelectionSlot slots[4]; char pad1320[8];
    SelectionSprite *unk1328; u16 unk132C, unk132E;
    SelectionSprite *unk1330; u16 unk1334, unk1336;
    s32 unk1338, unk133C, unk1340;
    SelectionSprite *unk1344, *unk1348;
    char pad134C[3]; u8 unk134F; s32 unk1350, unk1354;
} CharacterSelectionScreen;
typedef struct CharacterPreviewRow { s32 pad; f32 scale[4], distance[4]; Vec3 position[4]; s32 light[4]; char tail[12]; } CharacterPreviewRow;

extern CharacterSelectionScreen *D_800E42D0;
extern CharacterPreviewRow D_800E3A58[];
extern float D_800DD568[];
extern s32 func_8025DF34_de(s32);
extern void func_80298368_de(int),func_8029973C_de(void),func_802A2360_de(void),func_8040E8D8_de(SelectionSprite *,int),func_80419F24_de(int),func_80419F58_de(int,int),func_80420438_de(int),func_80420850_de(int);
extern int func_8040EBD0_de(SelectionSprite *),func_80419F38_de(int),func_8041F18C_de(int),func_8041F1D8_de(short);
extern SelectionSprite *func_8041B7FC_de(int,int);
extern void func_8041CAD8_de(void *,int,int,int,int,Vec3,Vec3,float,int);
s32 func_8041F6C8_de(s32 arg0,s32 arg1,s32 arg2) {
    Vec3 scale;
    f32 temp_f0_2;
    f32 temp_f0;
    s16 temp_a0_4;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 empty_slot;
    s32 var_v0;
    SelectionSlot *temp_a0;
    SelectionSprite *temp_a0_2;
    SelectionSprite *temp_a0_3;
    SelectionSprite *temp_a0_5;
    SelectionSprite *temp_a0_6;
    SelectionSprite *temp_a0_7;
    SelectionSprite *temp_a1;
    SelectionSprite *temp_a1_2;
    SelectionSprite *temp_v0_3;
    SelectionSlot *temp_v1_3;

    temp_v0 = D_800E42D0->unk1338;
    switch (temp_v0) {
    case 1:
        temp_a1 = D_800E42D0->unk1328;
        temp_a1->unk14 = (u16) (temp_a1->unk14 + D_800E42D0->unk132E);
        temp_a1_2 = D_800E42D0->unk1330;
        temp_a1_2->unk14 = (u16) (temp_a1_2->unk14 - D_800E42D0->unk1336);
        temp_v0_2 = D_800E42D0->unk133C - 1;
        D_800E42D0->unk133C = temp_v0_2;
        if (temp_v0_2 <= 0) {
            func_8025DF34_de(0xE79);
            func_8040E8D8_de(D_800E42D0->unk1344, 1);
            func_80419F58_de(D_800E42D0->unk1340, 4);
            D_800E42D0->unk1338 = 4;
            D_800E42D0->unk133C = 4;
        }
        break;
    case 2:
        temp_a0_5 = D_800E42D0->unk1328;
        temp_a0_5->unk14 = (u16) (temp_a0_5->unk14 - D_800E42D0->unk132E);
        temp_a0_6 = D_800E42D0->unk1330;
        temp_a0_6->unk14 = (u16) (temp_a0_6->unk14 + D_800E42D0->unk1336);
        temp_v0_4 = D_800E42D0->unk133C - 1;
        D_800E42D0->unk133C = temp_v0_4;
        if (temp_v0_4 <= 0) {
            D_800E42D0->unk1338 = 3;
            func_8029973C_de();
            func_80298368_de(D_800E42D0->unk1354);
            return 0;
        }
        break;
    case 3:
        func_802A2360_de();
        break;
    case 4:
        if (D_800E42D0->unk133C > 0) D_800E42D0->unk133C--;
        else D_800E42D0->unk133C = 0;
        if ((D_800E42D0->unk133C <= 0) && (func_80419F38_de(D_800E42D0->unk1340) != 0)) {
            func_80419F24_de(D_800E42D0->unk1340);
            D_800E42D0->unk1338 = 6;
            D_800E42D0->unk133C = 4;
            func_8040E8D8_de(D_800E42D0->unk1348, 1);
        }
        break;
    case 5:
        func_8025DF34_de(0xE78);
        D_800E42D0->unk1338 = 2;
        D_800E42D0->unk133C = 4;
        func_8040E8D8_de(D_800E42D0->unk1344, 0);
        func_8040E8D8_de(D_800E42D0->unk1348, 0);
        break;
    case 7: break;
    case 6:
        temp_a0_7 = D_800E42D0->unk1348;
        temp_a0_7->unk10 = (u8) (temp_a0_7->unk10 + D_800E42D0->unk134F);
        temp_v0_6 = D_800E42D0->unk133C - 1;
        D_800E42D0->unk133C = temp_v0_6;
        if (temp_v0_6 <= 0) {
            D_800E42D0->unk1348->unk10 = 0xC8;
            D_800E42D0->unk1338 = 3;
        }
        break;
    }
        if (D_800E42D0->unk1338 == 3) {
            var_s3 = 0;
            empty_slot = CHARACTER_EMPTY_SLOT;
            var_s2 = 0;
            var_s4 = 0;
            D_800E42D0->unk1350 = (s32) (D_800E42D0->unk1350 + arg2);
            do {
                temp_a0 = &D_800E42D0->slots[var_s3];
                if (temp_a0->unk14 == 1) {
                    if (temp_a0->unk8 != 0) {
                        temp_f0 = (func_802B6560_de((f32) var_s3 + ((f32) D_800E42D0->unk1350 * 0.0033333334f)) * 70.0f) + 170.0f;
                        temp_a0_2 = (&D_800E42D0->slots[var_s3])->unk8;
                        temp_a0_2->unk10=(unsigned int)temp_f0;
                    }
                    temp_v0_3 = func_8041B7FC_de(D_800E42D0->slots[0].unk4, var_s3);
                    temp_a0_3 = (&D_800E42D0->slots[var_s3])->unk8;
                    if ((temp_a0_3->unk14 != (temp_v0_3->unk14 - 2)) || (temp_a0_3->unk16 != (temp_v0_3->unk16 - 2))) {
                        func_8025DF34_de(0xE7F);
                        if (func_8040EBD0_de(temp_v0_3) == 0) {
                            temp_a0_4 = temp_v0_3->unkC;
                            if (temp_a0_4 != empty_slot) {
                                (&D_800E42D0->slots[var_s3])->unk10 = (s32) temp_a0_4;
                                temp_s0 = func_8041F1D8_de(temp_a0_4);
                                temp_v1 = func_8041F18C_de((&D_800E42D0->slots[var_s3])->unk10);
                                temp_a2 = (var_s3 * 4) + temp_v1;
                                temp_v1_2 = var_s4 + temp_v1;
                                scale.x = D_800E3A58[temp_v1].scale[var_s3];
                                scale.y = D_800E3A58[temp_v1].scale[var_s3];
                                scale.z = D_800E3A58[temp_v1].scale[var_s3];
                                func_8041CAD8_de(D_800E42D0->slots[var_s3].preview, 9, temp_s0 + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[temp_v1].position[var_s3], D_800E3A58[temp_v1].distance[var_s3], D_800E3A58[temp_v1].light[var_s3]);
                            } else {
                                func_80420850_de(var_s3);
                            }
                        } else {
                            (&D_800E42D0->slots[var_s3])->unk10 = -1;
                        }
                        func_80420438_de(var_s3);
                    } else if (temp_v0_3->unkC == empty_slot) {
                        func_80420850_de(var_s3);
                    }
                    temp_v1_3 = &D_800E42D0->slots[var_s3];
                    temp_v1_3->unk8->unk14 = (s16) ((u16) temp_v0_3->unk14 - 2);
                    temp_v1_3->unk8->unk16 = (s16) ((u16) temp_v0_3->unk16 - 2);
                }
                var_s2 += 0x4C8;
                var_s3 += 1;
                var_s4 += 0xC;
            } while (var_s3 < 4);
        }
        return 0;
}
