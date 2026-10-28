#include "include_asm.h"
#include "COMMON/LONE/D_800E28D4.H"
#include "RENDER/8026AC38.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/LABEL.H"
#include "TYPES.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "FRONTEND/MENU_DISPATCHSELECTIONMENUEVENT.H"

/* Enables mode 1 through Tsmos_SetModeOneFlag, places the menu model at (17, -10, -50) with uniform scale 0.14, zero rotation and a (0, 5, 0) offset, then issues request 0xE78 through SoundElement_PlayFlatSound; returns zero. */





/* The hub spells D_800E3590 as the padded menu block; this unit reaches the model name at +0x08
 * through its own view, so each use casts back to it. */
extern void Frontend_InitModelPreviewTransform(char *model, s32 arg1, CVector3 scale, CVector3 position);
extern void Frontend_SetPreviewRotation(char *model, CVector3 rotation);
extern void Frontend_SetPreviewRotationSpeed(char *model, CVector3 offset);

s32 Menu_PositionSelectionMenuModel(void) {
    CVector3 scale;
    CVector3 position;
    CVector3 rotation;
    CVector3 offset;

    Tsmos_SetModeOneFlag(1);
    scale.x = 0.14f;
    scale.y = 0.14f;
    scale.z = 0.14f;
    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = 0.0f;
    offset.x = 0.0f;
    offset.y = 5.0f;
    offset.z = 0.0f;
    position.x = 17.0f;
    position.y = -10.0f;
    position.z = -50.0f;
    Frontend_InitModelPreviewTransform(((MenuRecAt8 *) D_800E3590)->model, 0, scale, position);
    Frontend_SetPreviewRotation(((MenuRecAt8 *) D_800E3590)->model, rotation);
    Frontend_SetPreviewRotationSpeed(((MenuRecAt8 *) D_800E3590)->model, offset);
    SoundElement_PlayFlatSound(0xE78);
    return 0;
}

#include "gbi.h"
#include "COMMON/VIDEO_DIMENSIONS.H"
extern s32 Model_GetModelRecordCount(struct RecordFrontendSetPreviewModel *record);
extern void func_804399D0(struct RecordFrontendSetPreviewModel *record);
extern Gfx *g_displayListCursor;
extern s32 D_800E28D0;
/* Draw callback of the menu block: on draw event 1 in state 3 it clears the fill mode D_800D15E0, sets the fill
 * colour D_800D15E4 to opaque white, scissors the display list to the full screen and, when the block record at
 * +0x08 holds a model, draws it once in fill mode 1 at alpha 210, then restores the fill state. Returns zero. */
s32 Menu_DrawMenuBlockModel(void *window, void *item, s32 event) {
    if (event == 1 && D_800E3590->unk216 == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
        if (Model_GetModelRecordCount(&D_800E3590->record) != 0) {
            D_800D15E0 = 1;
            D_800D15E4[3] = 210.0f;
            func_804399D0(&D_800E3590->record);
            D_800D15E0 = 0;
            D_800D15E4[3] = 255.0f;
        }
    }
    return 0;
}

/* On event 3 with value 0, calls MarkMenuEventHandled, hands func_8041DB30_de the cursor word the hub
   names unk268 at +0x10C of the menu block D_800E3590 points to, calls Focus_ShowUnlockedEntries with 0x6E,
   Focus_RefreshProfileStatistics and Focus_RefreshUnlockedFocusLabel, and clears the hub's focus word at +0x0EC. Returns zero. */

extern void MarkMenuEventHandled();


s32 Menu_HandleNextProfileEvent(void *first, void *second, u32 event, s32 value) {
    if ((event >> 16) == 3 && value == 0) {
        MarkMenuEventHandled();
        Focus_AdvanceActiveSlot(&D_800E3590->unk268);
        Focus_ShowUnlockedEntries(0x6E);
        Focus_RefreshProfileStatistics();
        Focus_RefreshUnlockedFocusLabel();
        D_800E3590->focus = 0;
    }
    return 0;
}

s32 Menu_BeginSelectionMenuExit(void) {
    MarkMenuEventHandled();
    D_800E3590->unk216 = 5;
    D_800E3590->unk220 = 4;
    return 0;
}

/* Calls MarkMenuEventHandled with the arguments it was given and returns zero. */

s32 Menu_ConsumeSelectionMenuEvent(void) {
    MarkMenuEventHandled();
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3724, an actor kind at D_800E3728 and a handler at D_800E372C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */



extern s32 D_800E3724;
extern s32 D_800E3728;
extern Handler802A2B50 D_800E372C;

s32 Menu_DispatchSelectionMenuEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E372C != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E372C;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3724)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3728)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int func_8041DFB4_us_padding_181FB4[3] = {
    0x65717568, 0x10000094, 0x10000B00,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_8041E394_eu_x_padding_10E394[3] = {
    0xAFB00010, 0x0C0A6623, 0x241000FF,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8041E394_eu_padding_194394[3] = {
    0xAFA20014, 0x8FA2005C, 0x4600A306,
};
#endif
