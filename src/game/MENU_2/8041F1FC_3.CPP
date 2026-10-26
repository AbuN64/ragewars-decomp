#include "include_asm.h"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_32.H"
#include "FRONTEND/8041BEA8_6.H"



extern struct Shape_typemap_165 D_800E41C0[];

extern s32 D_800E28D0;


extern Gfx *g_displayListCursor;

extern void Frontend_DrawModelPreview(void *);
extern u8 D_800FEB57[][0x190];
extern HudStatusShared_Settings D_801462C8[];

/* Enables character choices unlocked by active players and highlights the selected profile's unlocked characters. */
#if defined(VERSION_DE)
enum { UNLOCK_MARK = 129 };
#elif defined(VERSION_EU_X)
enum { UNLOCK_MARK = 135 };
#else
enum { UNLOCK_MARK = 131 };
#endif

extern char D_80102B00[][0x190];

extern signed char D_80102B0D[];

extern u8 D_800FEB54[];

extern s32 D_800E3A54[][28];


extern s32 Player_TestAchievementFlag7(void *profile, s32 character);

extern s32 Defs_TestBit(u8 *bits, s32 index);

extern void Defs_SetBitValue(u8 *bits, s32 index, s32 value);

extern void Frontend_SetWidgetFlag100(MenuWidget *record, int enable);

/* Cycles player p's choice on the screen D_800E42D0: dims the item for the current choice at 0x18
   of p's 0x4C8-byte entry (from p's 36-byte layout row D_800E42D4, cells from 0xC) to alpha 0x50
   through func_8040E928_de(0), advances the choice modulo the count byte (at least one) found at
   0x57 plus the index func_8041F1D8_de gives for the entry's word at 0x10 in p's 400-byte record of
   D_80102B00, highlights the new choice's item with alpha 0x96 and stores it. Written from the
   assembly with the entries as an array member of the screen. */














/* Activates player p's panel on the screen D_800E42D0: passes p and the frame item id from p's
   36-byte layout row D_800E42D4 to func_8041B6E8_de, takes the row's cursor item into the word at 0x8
   of p's 0x4C8-byte entry, places it two units up and left of the frame item, shows it, sets the
   entry's state at 0x14 to one, redraws through Menu_RefreshPlayerCharacterVariants and hides the row's prompt item. */












extern void Menu_RefreshPlayerCharacterVariants(s32);

/* Resets player p's choice on the screen D_800E42D0: calls func_8040E8D8_de(1) on the three items in
   option cells from 0x18 of p's 36-byte layout row D_800E42D4, dims the item of the current choice at 0x18 of
   p's 0x4C8-byte entry to alpha 0x50 through func_8040E928_de(0) and resets the choice to 0; unless
   the entry's kind at 0x10 is -1 it then calls func_8040E8D8_de(0) on as many of those cells as the
   count byte (at least one) at 0x57 plus the index func_8041F1D8_de gives for the kind in p's
   400-byte record of D_80102B00, and highlights the item of the choice with alpha 0x96. Adapted
   from Menu_CyclePlayerCharacterVariant. */













/* Confirms a player's character choice and, once no player is still choosing, fills the match roster and starts the game; scheduler lever: the block-scoped match pointer inside the roster loop places the hoisted match address after the loop constants, as the cartridge does. */










extern CharacterScreenCell D_800E029E[][9];

extern unsigned char D_800FEB0F[];

extern void SmpOverlay_SetSlotValue(void *, int, int);

extern void Frontend_SetPreviewTransformUpdate(void *, int);

extern void func_80298368_de(int);

/* Chooses a different enabled random character, updates its preview and selects an available costume. */











extern s_CharacterData D_800E3A50[];

extern s32 GraphU64_NextRandom(void);

extern s32 Frontend_ListHasFlag100(void *widget);


/* Counts how many of the four 0x4C8-byte entries D_800E42D0 points to are in state 1 or 2. */




/* Draw callback of the four-player screen D_800E42D0: on draw event 1 in state 3 it clips the display list to each joined or ready player's viewport in D_800E41C0 and draws that panel through Frontend_DrawModelPreview, in the flash fill (mode 3) while the panel's flash counter runs down and in opaque white otherwise, then restores the full-screen clip and the white fill; returns zero. */
s32 Menu_RenderPlayerCharacterPreviews(void *arg0, void *arg1, s32 event)
{
    s32 i;
    if (event == 1 && D_800E42D0->phase == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        for (i = 0; i < 4; i++) {
            if (D_800E42D0->players[i].unkC == 1 || D_800E42D0->players[i].unkC == 3) {
                if (D_800E42D0->players[i].kind != -1) {
                    gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, D_800E41C0[i].field_0, D_800E41C0[i].field_4, D_800E41C0[i].field_8, D_800E41C0[i].field_C);
                    if (D_800E42D0->players[i].unk4C0 > 0) {
                        D_800D15E4[0] = 150.0f;
                        D_800D15E4[1] = 0.0f;
                        D_800D15E4[2] = 0.0f;
                        D_800D15E4[3] = 100.0f;
                        D_800D15E4[4] = 100.0f;
                        D_800D15E0 = 3;
                        D_800E42D0->players[i].unk4C0--;
                    } else {
                        D_800D15E0 = 0;
                        D_800D15E4[0] = 255.0f;
                        D_800D15E4[1] = 255.0f;
                        D_800D15E4[2] = 255.0f;
                        D_800D15E4[3] = 255.0f;
                    }
                    Frontend_DrawModelPreview(D_800E42D0->players[i].model);
                }
            }
        }
        D_800D15E0 = 0;
        gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
    }
    return 0;
}

void Menu_RefreshCharacterUnlocks(void) {
    u8 bits[4];
    s32 i;
    s32 j;
    s32 found;
    MenuWidget *widget;
    MenuWidget *mark;

    for (i = 0; i < 17; i++) {
        found = 0;
        for (j = 0; j < 4 && !found; j++) {
            if (D_80102B0D[j * 0x190] >= 0) {
                found = found || Player_TestAchievementFlag7(D_80102B00[j], D_800E3A54[i][0]);
            }
        }
        if (D_801462C8->trialKind == 0 || D_801462C8->trialKind == 2) {
            if (D_801462C8->flags & 0x8000000) {
                found = 1;
            }
        }
        Defs_SetBitValue(bits, i, found);
    }
    if (D_801462C8->trialKind == 1) {
        Defs_SetBitValue(bits, 11, 0);
        Defs_SetBitValue(bits, 12, 0);
        Defs_SetBitValue(bits, 13, 0);
        Defs_SetBitValue(bits, 14, 0);
    }
    if (D_801462C8->trialKind == 0 || D_801462C8->trialKind == 2) {
        Defs_SetBitValue(bits, 1, 1);
    }
    for (i = 0; i < 17; i++) {
        widget = Frontend_FindWidgetByResourceId(D_800E42D0->screen, (u16)D_800E3A50[i].id);
        Frontend_SetWidgetFlag100(widget, 0);
        if (!Defs_TestBit(bits, i)) {
            if (widget) {
                Frontend_SetWidgetFlag100(widget, 1);
                Frontend_SetWidgetFlag08(widget, 0);
            }
        } else if (D_801462C8->trialKind == 1 && Defs_TestBit(D_800FEB54, D_800E3A54[i][0]) == 1) {
            mark = Frontend_FindWidgetByResourceId(widget, UNLOCK_MARK);
            Frontend_SetWidgetFlag08(mark, 1);
            mark->alpha = 50;
        }
    }
}

void Menu_CyclePlayerCharacterVariant(s32 player) {
    MenuWidget *item;
    s32 choice;
    s32 count;

    choice = D_800E42D0->players[player].choice;
    item = Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[player].cells[choice].id);
    Frontend_SetWidgetFlag40(item, 0);
    item->alpha = 0x50;
    count = D_800FEB57[player][func_8041F1D8_de(D_800E42D0->players[player].kind)];
    if (count <= 0) {
        count = 1;
    }
    choice = (choice + 1) % count;
    item = Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[player].cells[choice].id);
    Frontend_SetWidgetFlag40(item, 1);
    item->alpha = 0x96;
    D_800E42D0->players[player].choice = choice;
}

void Menu_ShowPlayerCharacterSelection(s32 player) {
    MenuWidget *frame;

    SmpOverlay_ShowSlotById(D_800E42D0->screen, player, (s16)D_800E42D4[player].kind);
    D_800E42D0->players[player].highlight = Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[player].cursor);
    frame = Frontend_FindWidgetByResourceId(D_800E42D0->screen, (u16)D_800E42D4[player].kind);
    D_800E42D0->players[player].highlight->x = frame->x - 2;
    D_800E42D0->players[player].highlight->y = frame->y - 2;
    Frontend_SetWidgetFlag08(D_800E42D0->players[player].highlight, 1);
    D_800E42D0->players[player].unkC = 1;
    Menu_RefreshPlayerCharacterVariants(player);
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[player].title), 0);
}

void Menu_RefreshPlayerCharacterVariants(s32 player) {
    MenuWidget *item;
    s32 count;
    s32 i;

    for (i = 0; i < 3; i++) {
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[player].options[i].id), 1);
    }
    item = Frontend_FindWidgetByResourceId(D_800E42D0->screen,
                         D_800E42D4[player].cells[D_800E42D0->players[player].choice].id);
    Frontend_SetWidgetFlag40(item, 0);
    item->alpha = 0x50;
    D_800E42D0->players[player].choice = 0;
    if (D_800E42D0->players[player].kind == -1) {
        return;
    }
    count = D_800FEB57[player][func_8041F1D8_de(D_800E42D0->players[player].kind)];
    if (count <= 0) {
        count = 1;
    }
    for (i = 0; i < count; i++) {
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[player].options[i].id), 0);
    }
    item = Frontend_FindWidgetByResourceId(D_800E42D0->screen,
                         D_800E42D4[player].cells[D_800E42D0->players[player].choice].id);
    Frontend_SetWidgetFlag40(item, 1);
    item->alpha = 0x96;
}

void Menu_ApplySlotValueGfx(int player, int choice) {
    int i;
    int j;
    int count;
    ListScreenRecord *slot;
    int kind;

    D_800E42D0->players[player].unkC = 3;
    SmpOverlay_SetSlotValue(D_800E42D0->unk4, player, 1);
    D_800E42D0->players[player].unk4C0 = 1;
    for (i = 0; i < 3; i++) {
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E029E[player][i].id), 1);
    }
    D_800E42D0->players[player].kind = choice;
    func_8041F18C_de(choice);
    Frontend_SetPreviewTransformUpdate(D_800E42D0->players[player].model, 0);

    count = 0;
    for (j = 0; j < 4; j++) {
        if (D_800E42D0->players[j].unkC == 1 || D_800E42D0->players[j].unkC == 2) {
            count++;
        }
    }
    if (count != 0) {
        return;
    }

    slot = D_801462C8->roster;
    for (i = 0; i < 8; i++) {
        slot[i].active = 0;
        if (D_800E42D0->players[i].unkC == 3) {
            slot[i].m_IsBot = 0;
            slot[i].active = 1;
            slot[i].m_nController = i;
            kind = func_8041F1D8_de(D_800E42D0->players[i].kind);
            slot[i].m_nCharacter = kind;
            if (D_801462C8->trialKind == 1) {
                D_800FEB0F[i * 0x190] = kind;
            }
            slot[i].variant = (u8)D_800E42D0->players[i].choice;
        }
    }
    func_80298368_de(D_801462C8->trialKind == 1 ? 10 : 8);
}

void Menu_RandomizeCharacterPreview(s32 player) {
    s32 tries;
    s32 done;
    s32 id;
    s32 kind;
    s32 index;
    s32 costumes;

    tries = 0;
    done = 0;
    do {
        id = D_800E3A50[GraphU64_NextRandom() % 17].id;
        if (Frontend_ListHasFlag100(Frontend_FindWidgetByResourceId(D_800E42D0->screen, (u16)id)) == 0 && D_800E42D0->players[player].kind != id) {
            done = 1;
        } else if (++tries > 5000) {
#if defined(VERSION_DE)
            id = 0x90;
#elif defined(VERSION_EU_X)
            id = 0x96;
#else
            id = 0x92;
#endif
            done = 1;
        }
    } while (!done);
    D_800E42D0->players[player].kind = id;
    kind = func_8041F1D8_de(id);
    index = func_8041F18C_de(D_800E42D0->players[player].kind);
    {
        CVector3 scale;
        scale.x = D_800E3A50[index].scale[player];
        scale.y = D_800E3A50[index].scale[player];
        scale.z = D_800E3A50[index].scale[player];
        Frontend_InitModelPreview(D_800E42D0->players[player].model, 9, kind + 0x38F, 75, 24000, scale,
                      D_800E3A50[index].m_vPos[player], D_800E3A50[index].m_fRotY[player],
                      D_800E3A50[index].flags[player]);
    }
    costumes = D_800FEB57[player][kind];
    if (costumes <= 0) {
        costumes = 1;
    }
    D_800E42D0->players[player].choice = GraphU64_NextRandom() % costumes;
}

s32 Menu_CountPendingCharacterSelections(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if ((u32) (D_800E42D0->players[i].unkC - 1) < 2) {
            count++;
        }
    }
    return count;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC23C[1] = {
    0x595F3165,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8DCC[1] = {
    0x0044333C,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EDC0C[1] = {
    0x01770178,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD58C[1] = {
    0x0042148C,
};
#endif
