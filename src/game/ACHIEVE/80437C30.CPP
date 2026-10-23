#include "include_asm.h"
#include "ACHIEVE/80424E30_3.H"
#include "ACHIEVE/80424E30_2.H"

const unsigned int rodata_func_80438614_de_800E1F50[6] = {
    0x3E99999A, 0x3C1374BC, 0x40400000, 0xC0A00000, 0xC2C80000, 0xC1F00000,
};

#if defined(VERSION_US) || defined(VERSION_US_REV1)
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/ACTIVE.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/WORLD.H"
#include "ACHIEVE/MODELPREVIEWSCREEN.H"
extern Profile D_80102B00[];
extern Active *D_800E4680;
extern struct ResultsHeadingCharacter D_800DFA6C[];
extern s32 D_8015402C;
extern s32 D_8014DD98;
extern f32 D_800E1F40;
extern char *D_800D3578, *D_800D357C, *D_800D3580, *D_800D3588, *D_800D358C, *D_800D3590, *D_800D3594, *D_800D3598;
extern void func_8043C210_de(void *, s32, s32, s32, s32);
extern void func_8043C278_de(void *);
extern void func_80438A88_de();
extern void func_80425D14_de(s32);
extern s32 func_80265650_de(u8 *, s32);
extern void func_80265688_de(u8 *, s32, s32);
extern s32 func_80425014_de(s32);
extern void func_804259E0_de(s32);
extern void *func_802A001C_de(void *, int, u32);
extern s32 func_80425674_de(s32);
extern s32 func_8041F140_de(s32);
extern void func_802A0C08_de(char *, char *, ...);
extern void func_802A025C_de(char *, char *);
extern void func_8040E950_de(MenuWidget *, s32);
extern void func_8041B110_de(s32);
extern void func_8028D380_de(Shared_World *, s32, char *, s32);
extern char *func_802A0494_de(char *);
extern void func_802A2394_de(void);
extern void func_8043829C_de(void);
extern void func_80438614_de(void);
/* Opens the level results screen: allocates the preview state, records the finished level for the winning
   player, unlocks the level-end achievements and fills the level name and status lines. */
s32 func_80437C30_us_rev1(MenuWidget *menu) {
    char levelName[0x40];
    MenuWidget *item;
    Active *preset;
    func_8041F2A0_Config *config;
    Shared_Game *game;
    RenderCounters *counters;
    s32 achievement;
    s32 time;
    s32 slot;
    s32 character;
    s32 *level;
    s32 i;

    D_800E5830 = (ModelPreviewScreen *)func_8025305C_de(sizeof(ModelPreviewScreen));
    D_800E5830->window = menu;
    func_8040E8D8_de(menu, 0);
    func_8043C210_de(D_800E5830, 0x67, 0, 0, 0);
    func_8043C278_de(D_800E5830);
    D_800E5830->cursor = 1;
    func_8040EC30_de(menu, 0x26B + PREVIEW_ID_SHIFT)->alpha = 0x6E;
    func_8040EC30_de(menu, 0x270 + PREVIEW_ID_SHIFT)->alpha = 0x14;
    func_8040EC30_de(menu, 0x26D + PREVIEW_ID_SHIFT)->alpha = 0x14;
    func_8040EC30_de(menu, 0x280 + PREVIEW_ID_SHIFT)->alpha = 0x19;
    config = D_80146398;
    D_800E5830->player = 0;
    for (i = 0; i < 4; i++) {
        if (config[i].active == 1) {
            D_800E5830->player = i;
            break;
        }
    }
    func_80438A88_de();
    D_800E5830->badge = -1;
    game = &D_801462C8;
    switch (game->controllerMode) {
    case 1:
        if (game->humanWon == 1) {
            func_80425D14_de(D_800E5830->player);
            D_800E5830->rows[0].unk0 = -1;
            if (D_800E4680->recorded != 0) {
                slot = D_80102B00[D_800E5830->player].slot;
                if (func_80265650_de(D_80102B00[D_800E5830->player].slotLevels[slot], D_8015402C) == 1) {
                    item = func_8040EC30_de(D_800E5830->window, 0x27E + PREVIEW_ID_SHIFT);
                    func_8040E8D8_de(item, 1);
                    item->alpha = 0xAF;
                    item->text = D_800D3580;
                    goto done;
                }
            }
            D_800E5830->rows[0].unk0 = func_80425014_de(D_800E5830->player);
            D_800E5830->rows[0].unk10 = func_804253C8_de(D_800E5830->rows[0].unk0);
done:
            D_800E5830->badge = -1;
            switch (D_8015402C) {
            case 4:
                achievement = 0x2D;
                break;
            case 9:
                achievement = 0x2E;
                break;
            case 0x16:
                achievement = 0x2F;
                break;
            case 0x23:
                achievement = 0x30;
                break;
            default:
                achievement = -1;
                break;
            }
            if (achievement != -1 && func_80265650_de(D_80102B00[D_800E5830->player].achievementFlags, achievement) == 0) {
                func_80265688_de(D_80102B00[D_800E5830->player].achievementFlags, achievement, 1);
                D_800E5830->badge = achievement;
                func_804259E0_de(D_800E5830->player);
            }
            if (D_80102B00[D_800E5830->player].count >= 18) {
                func_80265688_de(&D_80102B00[D_800E5830->player].groupFlags, 1, 1);
            }
            if (D_80102B00[D_800E5830->player].count >= 36) {
                func_80265688_de(&D_80102B00[D_800E5830->player].groupFlags, 2, 1);
            }
            if (D_8015402C >= 0x23) {
                func_80265688_de(D_80102B00[D_800E5830->player].kindFlags, D_80146398[D_800E5830->player].kind, 1);
                func_802A001C_de(D_80102B00[D_800E5830->player].levelFlags[0], 0, 5);
                character = func_80425674_de(D_800E5830->player);
                if (character >= 0) {
                    func_802A0C08_de(D_800E5830->resultText, D_800D3578, *D_800DFA6C[func_8041F140_de(character)].name);
                    item = func_8040EC30_de(D_800E5830->window, 0x27F + PREVIEW_ID_SHIFT);
                    item->alpha = 0xAF;
                    func_8040E8D8_de(item, 1);
                    item->text = D_800E5830->resultText;
                }
            }
        } else {
            func_802A025C_de(D_800E5830->resultText, D_800D357C);
            item = func_8040EC30_de(D_800E5830->window, 0x27F + PREVIEW_ID_SHIFT);
            item->alpha = 0xAF;
            func_8040E8D8_de(item, 1);
            item->text = D_800E5830->resultText;
        }
        break;
    case 3:
        counters = &game->counters;
        if (counters->humanWon == 1) {
            func_80425D14_de(D_800E5830->player);
            level = &D_8015402C;
            preset = func_80425C70_de(*level, 3, 0);
            time = counters->timeLimit * D_800E1F40;
            if (D_80102B00[D_800E5830->player].times[*level] == 0) {
                D_80102B00[D_800E5830->player].times[*level] = preset->time - time;
            } else if (preset->time - time < D_80102B00[D_800E5830->player].times[*level]) {
                D_80102B00[D_800E5830->player].times[*level] = preset->time - time;
            }
            if (D_8015402C == 0x23) {
                item = func_8040EC30_de(D_800E5830->window, 0x27F + PREVIEW_ID_SHIFT);
                item->alpha = 0xAF;
                func_8040E8D8_de(item, 1);
                item->text = D_800D3598;
            }
        } else {
            func_802A025C_de(D_800E5830->resultText, D_800D357C);
            item = func_8040EC30_de(D_800E5830->window, 0x27F + PREVIEW_ID_SHIFT);
            item->alpha = 0xAF;
            func_8040E8D8_de(item, 1);
            item->text = D_800E5830->resultText;
        }
        break;
    case 4:
        if (game->humanWon == 1) {
            func_80425D14_de(D_800E5830->player);
            if (D_8015402C == 0x23) {
                item = func_8040EC30_de(D_800E5830->window, 0x27F + PREVIEW_ID_SHIFT);
                item->alpha = 0xAF;
                func_8040E8D8_de(item, 1);
                item->text = D_800D3594;
            }
        } else {
            func_802A025C_de(D_800E5830->resultText, D_800D357C);
            item = func_8040EC30_de(D_800E5830->window, 0x27F + PREVIEW_ID_SHIFT);
            item->alpha = 0xAF;
            func_8040E8D8_de(item, 1);
            item->text = D_800E5830->resultText;
        }
        break;
    }
    func_8043829C_de();
    func_80438614_de();
    func_8041B110_de(0x26E + PREVIEW_ID_SHIFT);
    func_8041B110_de(0x26F + PREVIEW_ID_SHIFT);
    func_8041B110_de(0x273 + PREVIEW_ID_SHIFT);
    func_8040E950_de(func_8040EC30_de(menu, 0x26F + PREVIEW_ID_SHIFT), 1);
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].player >= 0 && D_80102B00[i].fresh == 0) {
            func_8040E950_de(func_8040EC30_de(menu, 0x26F + PREVIEW_ID_SHIFT), 0);
            break;
        }
    }
    func_8040EC30_de(D_800E5830->window, 0x271 + PREVIEW_ID_SHIFT)->text = D_800D3588;
    item = func_8040EC30_de(D_800E5830->window, 0x272 + PREVIEW_ID_SHIFT);
    if (D_8014DD98 == 0) {
        item->text = D_800D3590;
    } else {
        item->text = D_800D358C;
    }
    item = func_8040EC30_de(menu, 0x26C + PREVIEW_ID_SHIFT);
    func_8028D380_de(&D_8011FE88, D_8015402C, levelName, 0x3F);
    func_802A025C_de(D_800E5830->nameText, func_802A0494_de(levelName));
    item->text = D_800E5830->nameText;
    D_800E5830->item24 = func_8040EC30_de(menu, 0x274 + PREVIEW_ID_SHIFT);
    D_800E5830->ready = 1;
    D_80146894 = 1;
    D_800E5830->started = 0;
    func_802A2394_de();
    return 0;
}
#endif

#ifndef NON_MATCHING
INCLUDE_ASM("ovl_80400000", func_8043829C_de);
#endif

#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "ACHIEVE/MODELPREVIEWSCREEN.H"
#include "COMMON/OBJECTRECAT28.H"
/* This function's literal pool (retained rodata): 0.3, 0.009, 3.0, -5.0, -100.0, -30.0. */
extern f32 D_800E1F54;
extern f32 D_800DDF30_de;
/* Shows the selected preview row's model: sets its image widget, scales the model (0.3 for the listed models,
   0.009 otherwise; 0.3 with a lower camera for 0x1390/0x1392), places it and resets the row's fade. */
void func_80438614_de(void) {
 SetupModelVector scale,offset,angle,position;
 s32 index, displacement, model;
 MenuWidget *item;
 ModelPreviewScreen *slot;
 index=D_800E5830->selected;
 displacement=index*20;
 model=D_800E5830->rows[index].unk0;
 if(model>=0) {
  /* the hub's Item view shares the MenuWidget prefix; this unit writes alpha and image through its own view */
  item=(MenuWidget *)func_8040EC30_de(D_800E5830->window,MENU_804387F4_642);
  func_8040E8D8_de(item,1);
  item->alpha=0xAF;
  item->image=D_800E5830->rows[index].unk10;
  if ((u32)(model-0x1389)<2U || model==0x139F || model==0x13A0 || model==0x13C1 || model==0x1398 || model==0x13BD) {
   scale.value.x=D_800DDF20_de; scale.value.y=D_800DDF20_de; scale.value.z=D_800DDF20_de;
  } else { scale.value.x=D_800E1F54; scale.value.y=D_800E1F54; scale.value.z=D_800E1F54; }
  angle.value.x=0;angle.value.y=0;angle.value.z=0;
  position.value.x=0;position.value.y=D_800DDF28_de;position.value.z=0;
  offset.value.x=0;offset.value.y=(&D_800DDF28_de)[1];offset.value.z=D_800DDF30_de;
  if (model==0x1390 || model==0x1392) {
   offset.value.x=0;offset.value.y=(&D_800DDF30_de)[1];offset.value.z=D_800DDF30_de;
   scale.value.x=D_800DDF38_de;scale.value.y=D_800DDF38_de;scale.value.z=D_800DDF38_de;
  }
  func_80439B5C_de(&D_800E5830->modelWorkspace,0,scale.words,offset.words);
  func_80439BE0_de(&D_800E5830->modelWorkspace,angle.words);
  func_80439C30_de(&D_800E5830->modelWorkspace,position.words);
  func_80439C80_de(&D_800E5830->modelWorkspace,model);
  D_800E5830->rows[index].unk4=0;
  D_800E5830->rows[index].unk8=10;
 }
}

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "ACHIEVE/MODELPREVIEWSCREEN.H"
#include "COMMON/OBJECTRECAT28.H"
#include "TYPES.H"
void func_804399D0(MenuModelItem *item);
void func_80438614_de(void);
extern s32 D_800D15E0;
extern f32 D_800D15F0;
extern f32 D_800DDF3C_de;

void func_80438828_de(void) {
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;

    temp_s1 = D_800E5830->selected;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    if ((D_800E5830->rows[temp_s1].unk0 >= 0) && (*((s32 *) ((u8 *) (D_800E5830) + 448)) != 0)) {
        D_800D15E0 = 1;
        D_800D15F0 = (f32) D_800E5830->rows[temp_s1].unk8;
        func_804399D0((void *)&D_800E5830->modelWorkspace);
        D_800D15F0 = D_800DDF3C_de;
        temp_v1 = D_800E5830->rows[temp_s1].unk4;
        D_800D15E0 = 0;
        switch (temp_v1) {                          /* irregular */
        case 0:
            temp_v0 = D_800E5830->rows[temp_s1].unk8 + 2;
            D_800E5830->rows[temp_s1].unk8 = temp_v0;
            if (temp_v0 >= 0x97) {
                D_800E5830->rows[temp_s1].unk8 = 0x96;
                D_800E5830->rows[temp_s1].unk4 = 2;
                if (temp_s1 <= 0) {
                    var_v0 = temp_s1 * 4;
                    if (D_800E5830->rows[temp_s1 + 1].unk0 > 0) {
                        D_800E5830->rows[temp_s1].unkC = 0x96;
                        return;
                    }
                    goto block_15;
                }
                var_v0 = temp_s1 * 4;
block_15:
                D_800E5830->rows[temp_s1].unkC = 0x38F;
                return;
            }
            break;
        case 2:
            temp_v1_2 = D_800E5830->rows[temp_s1].unkC;
            temp_v0_2 = temp_v1_2 - 1;
            if (temp_v1_2 != 0x38F) {
                D_800E5830->rows[temp_s1].unkC = temp_v0_2;
                if (temp_v0_2 <= 0) {
                    D_800E5830->rows[temp_s1].unk4 = 1;
                    return;
                }
            }
            break;
        case 1:
            temp_v0_3 = D_800E5830->rows[temp_s1].unk8 - 2;
            D_800E5830->rows[temp_s1].unk8 = temp_v0_3;
            if (temp_v0_3 < 0xA) {
                D_800E5830->rows[temp_s1].unk8 = 0xA;
                D_800E5830->selected += 1;
                func_80438614_de();
            }
            break;
        }
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_80438828_de);
#endif

#ifdef NON_MATCHING
extern Profile D_80102B00[];
extern char D_800E1F48[];

#if !defined(VERSION_US) && !defined(VERSION_US_REV1)
extern s32 func_802A0C08_de(void *, s32, ...);
#endif

/* Fill the selected player's preview statistics and optional rank badge. */
void func_8043829C_de(void) {
    MenuWidget *item, *lastItem;
    func_8041F2A0_Config *record;
    s32 denominator;
    s32 player;
    s32 statIndex;
    s32 percent;

    player = D_800E5830->player;
    statIndex = player;
    record = &D_80146398[player];
    item = func_8040EC30_de(D_800E5830->window, (0x279 + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0x96;
    item->value = D_800E3A58[func_8041F140_de((s32) record->kind)].portrait;
    item = func_8040EC30_de(D_800E5830->window, (0x27a + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    item->text = D_80102B00[player].name;
    item = func_8040EC30_de(D_800E5830->window, (0x27b + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0x73;
    item->text = func_80424DE8_de(player);
    item = func_8040EC30_de(D_800E5830->window, (0x27c + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    func_802A0C08_de(D_800E5830->killsText, (s32)previewNumberFormat(), record->kills);
    item->text = D_800E5830->killsText;
    item = func_8040EC30_de(D_800E5830->window, (0x27d + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    func_802A0C08_de(D_800E5830->scoreText, (s32)previewNumberFormat(), record->score + record->total);
    item->text = D_800E5830->scoreText;
    item = func_8040EC30_de(D_800E5830->window, (0x27e + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    denominator = D_800FF140_de[statIndex];
    percent = 0;
    if (denominator > 0) {
        percent = (s32) (D_800FEAE0[statIndex] * 0x64) / denominator;
    }
    func_802A0C08_de(D_800E5830->ratioText, (s32)D_800E1F48, percent);
    item->text = D_800E5830->ratioText;
    item = func_8040EC30_de(D_800E5830->window, (0x27f + PREVIEW_ID_SHIFT));
    func_8040E8D8_de(item, 1);
    item->alpha = 0xAF;
    lastItem=item;
    switch (D_8014DD98) {
    case 0: func_802A0C08_de(D_800E5830->otherText, (s32)previewNumberFormat(), record->other); break;
    case 1: func_802A0C08_de(D_800E5830->otherText, (s32)previewNumberFormat(), record->selected); break;
    default: func_802A0C08_de(D_800E5830->otherText, (s32)previewNumberFormat(), 0); break;
    }
    lastItem->text = D_800E5830->otherText;
    if (D_800E5830->badge != -1) {
        item = func_8040EC30_de(D_800E5830->window, (0x280 + PREVIEW_ID_SHIFT));
        item->alpha = 0x96;
        func_8040E8D8_de(item, 1);
        item->value = D_800E01B0_de[D_800E5830->badge];
    }
}

#endif
