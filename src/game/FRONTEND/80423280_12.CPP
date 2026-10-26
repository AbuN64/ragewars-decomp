#include "include_asm.h"
#include "COMMON/LEVEL_GOAL.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/RECRECAT4.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/WORLD.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/ACTIVE.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "ACHIEVE/80424E30_3.H"
#include "SCENE/802508E0_13.H"

extern MatchScoreScreen *D_800E53C0;
extern Shared_Rec3 g_playerSettings[8];
extern MenuWidget *Frontend_FindWidgetByResourceId(void *, s32);
extern void Frontend_SetWidgetFlag08(void *, s32);

/* Calls InitFrontendMenus and Tsmos_DeactivateControllerState, then SmXlate_SwitchScreen with 0x11. */
#if defined(VERSION_EU)
extern void Tsmos_InitializeEuropeanFrontend();
#elif defined(VERSION_EU_X)
extern void func_802A2374_eu_x();
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
extern void InitFrontendMenus();
#else
extern void func_802A2224_de();
#endif

extern void Tsmos_DeactivateControllerState();

extern void SmXlate_SwitchScreen(s32);

/* Clears the words at offsets 0x78 and 0x54 of D_801468A0, then calls SmXlate_SwitchScreen with 0x14
   unless func_8042AF28_de and ScenarioSetup_StartRandomCupStage both report something, in which case it calls
   Frontend_StartConfiguredMatch. */




extern s32 ScenarioSetup_StartRandomCupStage();

extern void Frontend_StartConfiguredMatch();

/* Reports why a match ended: time running out on a timed match, the score limit (Player_CheckScoreLimit),
   the rule set's own target (func_802282EC_de for rule set 0, the Frag Tag limit func_802281F0_de for
   rule set 1), or otherwise whether the last-player-standing check reached its end. */

extern Game_func_8042D060_de D_8014561C;



extern s32 Player_CheckScoreLimit(World *world);

extern s32 Player_CheckTotalScoreWin(World *world);

extern s32 Player_CheckTeamPointWin(World *world);

/* For each of the 8 occupied slots without the pending-remove flag, runs its two release callbacks. */









extern void Frontend_AwardMatchAchievements(s32 player, s32 *awarded);


/* Refreshes each of 8 configured participants: for each slot, reads the participant id at offset
   0xF0 + slot*4 of D_800E53C0; when it is not -1 and the id's 150-byte record in D_80146398 has
   its byte at 0x91 clear, stores Achieve_AwardMilestoneCompletion(id) at offset 0x32C of D_800E53C0, calls
   Achieve_AwardAllMilestoneAchievement(id, &D_800E53C0[0x110 + id*8]), and calls Achieve_UpdateUnlockTiers(id). */





/* When the object D_800E53C0 points to has a target at 0x32C and its word at 0x328 set, runs
   func_804399D0 on offset 0x20 of it with D_800D15E0 set and D_800D15F0 raised to D_800DDB08_de[1],
   then clears D_800D15E0 and sets D_800D15F0 to D_800DDB10. */







extern void func_804399D0(void *);

/* Draws player p's badge on the screen D_800E53C0: looks up the group item the third argument
   names in the screen window, picks its child 0x26C, 0x26B or 0x26A for kinds 1 to 3 and 0x26D
   otherwise, shows it with alpha 0x96, and sets its frame at 0x2C from the rank byte at 0x92 of
   the player's 150-byte record in D_80146398, the cartridge's jump table jtbl_800E1B48 sending
   ranks 0 to 4 to frame 0x63, 0x62, 0x61 or 0x5F or to hiding it again with frame 0x60, which any
   higher rank also gets. */


/* Hides the four child items of a selected menu panel. */



                            /* extern */


#if defined(VERSION_DE)
enum { ITEM0 = 616, ITEM1 = 615, ITEM2 = 614, ITEM3 = 613 };
#elif defined(VERSION_EU_X)
enum { ITEM0 = 625, ITEM1 = 624, ITEM2 = 623, ITEM3 = 622 };
#else
enum { ITEM0 = 621, ITEM1 = 620, ITEM2 = 619, ITEM3 = 618 };
#endif

/* Releases the object D_800E53C0 holds through Cache_FreeMemory, clears D_800E53C0 and returns zero. */



/* Handles event 1 on the screen D_800E53C0: unless func_8043C308_de reports its menu in state 1 it
   calls Frontend_DrawResultSelectionPreview; otherwise it advances the menu with Frontend_DrawMenuImage and func_8043C2A4_de and,
   once func_8043C308_de reports 2, acts on the choice at 0x1C: choice 0 hides the window argument,
   calls MarkMenuEventHandled, clears D_80146918 and D_801468F4 and leaves for screen 0xF when option
   D_801462D5 is set, otherwise through Frontend_StartConfiguredMatch when func_8042AF28_de and ScenarioSetup_StartRandomCupStage both
   agree or for screen 0x14; choice 1 calls func_8040C428_de(0), shows the window, stops the objects
   at D_80145088 and 0x48 before it, releases D_8011FE88 through Scene_LoadLevelResources and sets the word at
   0x17F0 of D_80145088 to 8. Returns zero. */








extern s32 func_8043C308_de(void *);

extern void Frontend_DrawMenuImage(void *);

extern void func_8043C2A4_de(void *);



extern void Items_ResetActorPools(void *, s32);

extern void func_804499B0_de(void *, s32, s32);

extern void Scene_LoadLevelResources(void *, s32, s32);

extern void MarkMenuEventHandled();

/* Runs one frame of the screen D_800E53C0's confirmation prompt while D_800E28E0 is not positive:
   on the first frame it marks the prompt open at 0x320 and asks Smos_SetFocusedElement for message 0x238,
   or 0x237 when func_8040EBD0_de rejects the object loaded for 0x238, then calls Tsmos_ActivateControllerState. Once
   the choice word D_80154020[1] reads one it clears it and either enables the prompt's object at
   0xE4 and records the choice at 0x328, when the pending action D_80154020[0] is -1, or disables
   the object, clears 0x328 and hands the pending action to SmXlate_SwitchScreen through MarkMenuEventHandled.
   Returns zero. On eu-x both message ids are renumbered 5 higher. */






extern s32 D_80154020[];

extern s32 Frontend_ListHasFlag100(void *);

extern void Smos_SetFocusedElement(s32);

extern void Tsmos_ActivateControllerState();

#if defined(VERSION_DE)
enum { CONFIRM_MESSAGE = 0x234, FALLBACK_MESSAGE = 0x233 };
#elif defined(VERSION_EU_X)
enum { CONFIRM_MESSAGE = 0x23D, FALLBACK_MESSAGE = 0x23C };
#else
enum { CONFIRM_MESSAGE = 0x238, FALLBACK_MESSAGE = 0x237 };
#endif

void Frontend_InitMatchResultsMenu(void) {
    
#if defined(VERSION_EU)
Tsmos_InitializeEuropeanFrontend
#elif defined(VERSION_EU_X)
func_802A2374_eu_x
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
InitFrontendMenus
#else
func_802A2224_de
#endif
();
    Tsmos_DeactivateControllerState();
    SmXlate_SwitchScreen(0x11);
}

void Frontend_ContinueCupOrOpenResults(void) {
    CGameStatus *state = &D_801462C8.counters;

    state->m_bCTFOn = 0;
    state->m_bFragTagOn = 0;
    if (ScenarioSetup_IsCupSelected() == 0 || ScenarioSetup_StartRandomCupStage() == 0) {
        SmXlate_SwitchScreen(0x14);
    } else {
        Frontend_StartConfiguredMatch();
    }
}

void Frontend_OpenControllerModeResults(void) {
    CGameStatus *state = &D_801462C8.counters;

    state->m_bCTFOn = 0;
    state->m_bFragTagOn = 0;
    SmXlate_SwitchScreen(0xF);
}

s32 Frontend_GetMatchEndReason(void) {
    SettingsRecAt24 *settings;
    settings = &D_8014561C.settings;
    if (settings->timeSetting > 0 && D_8014561C.rules.timeLeft == 0.0f) {
        return MATCH_END_TIME_UP;
    }
    if (Player_CheckScoreLimit((World *)&D_80145040) != 0) {
        return MATCH_END_SCORE_LIMIT;
    }
    switch (D_8014DD98.kind) {
    case 0:
        if (Player_CheckTeamPointWin((World *)&D_80145040) != 0) {
            return MATCH_END_POINT_TARGET;
        }
        break;
    case 1:
        if (Player_CheckTotalScoreWin((World *)&D_80145040) != 0) {
            return MATCH_END_TAG_LIMIT;
        }
        break;
    }
    return D_8014561C.rules.lastStanding == 1;
}

void Frontend_AwardResultAchievements(void)
{
  s32 i;
  MatchScoreScreen *obj;
  int temp_1;
  Shared_Rec3 *recs;
  for (i = 0; i < 8; i++)
  {
    s32 val;
    temp_1 = -1;
    obj = D_800E53C0;
    recs = g_playerSettings;
    val = obj->players[i];
    if (val == temp_1)
    {
      continue;
    }
    if ((recs + val)->flag != 0)
    {
      continue;
    }
    Frontend_AwardMatchAchievements(val, obj->icons[val]);
    recs = g_playerSettings;
    Achieve_UpdateUnlockTiers(val);
  }

}

void Frontend_AwardResultMilestones(void) {
    s32 id;
    s32 i;
    Shared_Rec3 *record;

    for (i = 0; i < 8; i += 1) {
        id = D_800E53C0->players[i];
        if (id == -1) {
            continue;
        }
        record = &g_playerSettings[id];
        if (record->flag != 0) {
            continue;
        }
        D_800E53C0->selection = Achieve_AwardMilestoneCompletion(id);
        Achieve_AwardAllMilestoneAchievement(id, D_800E53C0->icons[id]);
        Achieve_UpdateUnlockTiers(id);
    }
}

void Frontend_DrawResultSelectionPreview(void) {
    MatchScoreScreen *state = D_800E53C0;
    f32 *level;

    if (state->selection != -1 && state->dirty != 0) {
        level = &D_800D15E4[3];
        D_800D15E0 = 1;
        *level = D_800DDB08_de[1];
#if defined(VERSION_DE)
        func_804397F0_auto((char *)&state->pad20);
#else
        func_804399D0((char *)&state->pad20);
#endif
        D_800D15E0 = 0;
        *level = D_800DDB10;
    }
}

void Frontend_ShowResultRankBadge(s32 player, s32 kind, unsigned short group) {
    MenuWidget *item;
    MenuWidget *parent;
    Shared_Rec3 *record;
    u32 rank;
    s32 id;
    s32 frame;
    record = &g_playerSettings[player];
    parent = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, group);
    switch (kind) {
    case 0:
    default:
#if defined(VERSION_DE)
        id = 0x268;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x26D;
#elif defined(VERSION_EU_X)
        id = 0x271;
#endif
        break;
    case 1:
#if defined(VERSION_DE)
        id = 0x267;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x26C;
#elif defined(VERSION_EU_X)
        id = 0x270;
#endif
        break;
    case 2:
#if defined(VERSION_DE)
        id = 0x266;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x26B;
#elif defined(VERSION_EU_X)
        id = 0x26F;
#endif
        break;
    case 3:
#if defined(VERSION_DE)
        id = 0x265;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x26A;
#elif defined(VERSION_EU_X)
        id = 0x26E;
#endif
        break;
    }
    item = Frontend_FindWidgetByResourceId(parent, id);
    Frontend_SetWidgetFlag08(item, 1);
    item->alpha = 0x96;
    rank = record->rank;
    switch (rank) {
    case 0:
        frame = 0x63;
        break;
    case 1:
        frame = 0x62;
        break;
    case 2:
        frame = 0x61;
        break;
    case 3:
        frame = 0x5F;
        break;
    case 4:
        frame = 0x60;
        break;
    default:
        Frontend_SetWidgetFlag08(item, 0);
        frame = 0x60;
        break;
    }
    item->value = frame;
}

void Frontend_HideResultBadgeGroup(s32 arg0) {
    MenuWidget *root;
    s32 var_a1;
    s32 var_s0;

    root = Frontend_FindWidgetByResourceId(D_800E53C0->unkE0, arg0 & 0xFFFF);
    var_s0 = 0;
    do {
        switch(var_s0) {
        case 0: var_a1=ITEM0; break;
        case 1: var_a1=ITEM1; break;
        case 2: var_a1=ITEM2; break;
        case 3: var_a1=ITEM3; break;
        default: var_a1=ITEM0; break;
        }
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(root, var_a1), 0);
        var_s0 += 1;
    } while (var_s0 < 4);
}

s32 Frontend_DestroyMatchResults(void) {
    Cache_FreeMemory(D_800E53C0);
    D_800E53C0 = 0;
    return 0;
}

s32 Frontend_UpdateMatchResultsTransition(void *window, void *unused1, s32 event) {
    s32 state;
    char *object;
    s32 next;

    if (event != 1) {
        return 0;
    }
    state = func_8043C308_de(D_800E53C0);
    if (state == event) {
        Frontend_DrawMenuImage(D_800E53C0);
        func_8043C2A4_de(D_800E53C0);
        if (func_8043C308_de(D_800E53C0) != 2) {
            return 0;
        }
        if (D_800E53C0->active != 0) {
            if (D_800E53C0->active != state) {
                return 0;
            }
            Frontend_RequestScreenMode(0);
            Frontend_SetWidgetFlag08(window, 1);
            object = &D_80145088;
            Items_ResetActorPools(object, 0);
            func_804499B0_de(object - 0x48, 0, 0);
            Scene_LoadLevelResources(&g_world, 0, 0);
            ((MatchMenuObjects *)(object))->transition = 8;
        } else {
            Frontend_SetWidgetFlag08(window, 0);
            MarkMenuEventHandled();
            if (D_801462C8.controllerMode == 0) {
                D_80146918 = 0;
                D_801468F4 = 0;
                if (ScenarioSetup_IsCupSelected() != 0 && ScenarioSetup_StartRandomCupStage() != 0) {
                    Frontend_StartConfiguredMatch();
                    return 0;
                }
                next = 0x14;
            } else {
                D_80146918 = 0;
                D_801468F4 = 0;
                next = 0xF;
            }
            SmXlate_SwitchScreen(next);
            return 0;
        }
    } else {
        Frontend_DrawResultSelectionPreview();
    }
    return 0;
}

s32 Frontend_HandleResultsConfirmation(s32 context) {
    s32 *choice;
    s32 taken;
    s32 message;

    if (D_800E28E0 <= 0) {
        if (D_800E53C0->phase == 0) {
            D_800E53C0->phase = 1;
            if (Frontend_ListHasFlag100(Frontend_FindWidgetByResourceId(context, CONFIRM_MESSAGE)) == 0) {
                message = CONFIRM_MESSAGE;
            } else {
                message = FALLBACK_MESSAGE;
            }
            Smos_SetFocusedElement(message);
            Tsmos_ActivateControllerState();
        }
        choice = &D_80154020[1];
        taken = choice[0];
        if (taken == 1) {
            choice[0] = 0;
            if (choice[-1] != -1) {
                Frontend_SetWidgetFlag08(D_800E53C0->buttonAddress, 0);
                D_800E53C0->dirty = 0;
                MarkMenuEventHandled();
                SmXlate_SwitchScreen(choice[-1]);
                return 0;
            }
            Frontend_SetWidgetFlag08(D_800E53C0->buttonAddress, 1);
            D_800E53C0->dirty = taken;
        }
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC7DC[1] = {
    0x10000B00,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E936C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE1AC[1] = {
    0x00CC00CD,
};
#endif

#if defined(VERSION_DE)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DDB2C[1] = {
    (unsigned int)&D_800CBB1C + 0x4,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E1B44 */
unsigned int D_blob_2b6f958a3aa45420c4fc[1] = {
    0x00000000,
};
#endif
