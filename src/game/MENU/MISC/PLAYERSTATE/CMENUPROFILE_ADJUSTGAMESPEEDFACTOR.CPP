#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/PLAYERSETTINGS.H"
#include "TYPES.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "MENU/MISC/CMENUPROFILE_ADJUSTGAMESPEEDFACTOR.H"
#include "SYSTEM/DEFS.H"

/** Always returns 0. */
s32 CMenuProfile_GameSpeedReturnZero(void) {
    return 0;
}

/* Returns 1 if any of g_matchRoundCounters's unk1C, unk20 or unk28 fields is nonzero, otherwise 0. */




s32 CMenuProfile_HasDialogRoundProgress(void) {
    CGameStatus *s = &g_gameSettings.counters;
    s32 result;

    result = 0;
    if ((s->round != 0) || (s->elapsed != 0) || (s->state != 0)) {
        result = 1;
    }
    return result;
}

/* Clears arg1->unk1C's unk858 flag and its unk5D8's unk80, then forwards to Menu_OpenDialog. */

extern void Menu_OpenDialog(s32 parent, void *list, void *player, s32 controller, s32 dialogParameter);
extern s32 D_0044FB2C;







s32 CMenuProfile_OpenPrimaryPlayerDialog(void *unused0, Handle8043E788 *menuContext) {
    Obj1C *selectionPlayer;

    selectionPlayer = menuContext->unk1C;
    selectionPlayer->unk858 = 0;
    selectionPlayer->unk5D8->characterKind = 0;
    Menu_OpenDialog(selectionPlayer->unk5DC + 0x554, &D_0044FB2C, selectionPlayer, selectionPlayer->unk698, selectionPlayer->unk5D4);
    return 1;
}

/* Sets arg1->unk1C's unk858 flag and clears its unk5D8's unk80, then forwards to Menu_OpenDialog. */








s32 CMenuProfile_OpenAlternatePlayerDialog(void *unused0, Handle8043E788 *menuContext) {
    Obj1C *selectionPlayer;

    selectionPlayer = menuContext->unk1C;
    selectionPlayer->unk858 = 1;
    selectionPlayer->unk5D8->characterKind = 0;
    Menu_OpenDialog(selectionPlayer->unk5DC + 0x554, &D_0044FB2C, selectionPlayer, selectionPlayer->unk698, selectionPlayer->unk5D4);
    return 1;
}

/* Steps the selection g_profileGameSpeedSelection through Menu_AdjustValue (a second step when Control_IsRightPressed or
   func_8026437C_de reports the object's controller busy), then sets D_80142228 to the chosen entry of the
   float table D_00450854 plus the offset in g_profileGameSpeedPreview, clamped between g_profileGameSpeedWrapLimit and (2.0f). */








extern s32 Menu_AdjustValue(struct GameSpeedMenuValue *, s32, s32, s32, s32, s32);

extern s32 Control_IsAButtonPressed(s32);

s32 CMenuProfile_AdjustGameSpeedFactor(void *menuItem, struct GameSpeedMenuValue *obj)
{
    f32 scale;

    g_profileGameSpeedSelection = Menu_AdjustValue(obj, g_profileGameSpeedSelection, 1, 0, 15, 0);
    if (((s32 (*)(s32))Control_IsRightPressed)(obj->field_20) != 0 || Control_IsAButtonPressed(obj->field_20) != 0) {
        Menu_AdjustValue(obj, g_profileGameSpeedSelection, 1, 0, 15, 0);
    }
    scale = D_00450854[g_profileGameSpeedSelection] + g_profileGameSpeedPreview.scale;
    if (!(scale < g_profileGameSpeedWrapLimit)) {
        if (!(scale > (2.0f))) {
            if (scale < g_profileGameSpeedWrapLimit) {
                scale = g_profileGameSpeedWrapLimit;
            }
        } else {
            scale = (2.0f);
        }
    } else {
        scale = g_profileGameSpeedWrapLimit;
    }
    g_gameSettings.speedFactor = scale;
    return 0;
}

#include "COMMON/SHARED_DEBUGFIELD.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern f32 g_profileGameSpeedDefault;
extern char *g_profileGameSpeedScaledLabel[], *g_profileGameSpeedDefaultLabel[];
extern char g_profileGameSpeedFormat[];
extern s32 Menu_CountLineChars(void *);

s32 CMenuProfile_UpdateGameSpeedLabel(Shared_DebugWidget *widget) {
    char *text;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Shared_Game *game = &g_gameSettings;
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    if (game->speedFactor == g_profileGameSpeedDefault) {
#else
    if (g_gameSettings.speedFactor == g_profileGameSpeedDefault) {
#endif
        widget->text = g_profileGameSpeedDefaultLabel;
    } else {
        widget->text = g_profileGameSpeedScaledLabel;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        text = widget->text[game->language];
#else
        text = *widget->text;
#endif
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(widget) - 3), g_profileGameSpeedFormat, g_profileGameSpeedSelection - 5);
    }
    return 0;
}
