#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/PLAYERRECAT64E.H"
#include "MULTI/INITIAL.H"
#include "COMMON/MENU_UI_PROVIDERS.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/EXTERNS_6.H"
#include "GFX/TEXT/ONSCREEN_DRAWSCALEDMASKEDTILEGRID.H"
#include "MULTI/ITEM.H"

#if (!(defined(VERSION_US) || defined(VERSION_US_REV1) || defined(VERSION_EU))) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_80400000", Multi_DrawPlayerItemAvailability);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1) || defined(VERSION_EU) || defined(NON_MATCHING)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */

void Multi_DrawPlayerItemAvailability(struct ItemRecAt18V2 *item, MenuOptionBox *box, s32 unused, struct HolderMultiIsPlayerItemAvailable *context) {
    struct ItemDef *def = item->def;
    s32 type = def->type;
    s32 index = def->index;
    struct PlayerRecAt64E *player = context->player;
    s32 available = 0;
    switch (type) {
    case 0x10FE:
        if (index >= 0) {
            if (index < 3) goto low;
            if (index < 6) goto high;
            break;
        low:
            available = index < player->count64D;
            break;
        high:
            available = index - 3;
            available = available < player->count64E;
        }
        break;
    case 0x1194:
        available = player->flags[index] != 0;
        break;
    }
    if (D_800E1E20 != 5) {
        D_800E1E20 = 5;
        Onscrn_SetupSpriteMode((s32)(context->fade * (context->alpha * D_800E23A0[0])));
    }
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
    if (available) {
        gDPSetEnvColor(g_displayListCursor++, 255, 255, 255, (s32)(context->fade * (context->alpha * D_800E23A0[1])));
    } else {
        gDPSetEnvColor(g_displayListCursor++, 50, 50, 50, (s32)(context->fade * (context->alpha * D_800E23A8)));
    }
    OnScreen_DrawSpriteResource(item->resource, 0, box->left, box->top, box->scaleX, box->scaleY, 1);
}
#endif

/* Does nothing. Nothing in the cartridge image calls it or stores its address as a word. */
void func_8043F040_de(void) {
}

/* Reports whether an item is available to the player: for item type 0x10FE its index 0-2 must be below the player's count at 0x64D and 3-5 (less three) below the count at 0x64E, and for type 0x1194 the player's flag byte at 0x644 for the index must be set; any other type or index gives zero. */








/* Reports whether an item is available to the player: indices 0-2 and 3-5 of type 0x10FE are checked against the player's two counts, type 0x1194 against its flag table. */
s32 Multi_IsPlayerItemAvailable(struct ItemRecAt18V2 *item, struct HolderMultiIsPlayerItemAvailable *holder) {
    struct ItemDef *def = item->def;
    s32 type = def->type;
    s32 index = def->index;
    struct PlayerRecAt64E *player = holder->player;
    s32 result = 0;

    switch (type) {
    case 0x10FE:
        if (index >= 0) {
            if (index < 3) {
                goto low;
            }
            if (index < 6) {
                goto high;
            }
            break;
        low:
            result = index < player->count64D;
            break;
        high:
            result = index - 3;
            result = result < player->count64E;
        }
        break;
    case 0x1194:
        result = player->flags[index] != 0;
        break;
    }
    return result;
}

/* Calls SoundElement_DisableMusicGainOverride and then returns what Menu_TryCreateMenu gives for the same three arguments. */
extern void SoundElement_DisableMusicGainOverride(void);
extern s32 Menu_TryCreateMenu(void *, void *, void *);

s32 Multi_CreateMenuWithDefaultMusicGain(void *first, void *second, void *third) {
    SoundElement_DisableMusicGainOverride();
    return Menu_TryCreateMenu(first, second, third);
}
