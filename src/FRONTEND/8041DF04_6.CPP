#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_ASM("ovl_80400000", func_8041E408_de);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
extern void *D_800E39C0;
extern struct RequestRecAt10 D_80153F80[];
extern struct TextEntry D_800E381C[][17];
extern u8 *func_802A025C_de(u8 *, u8 *);
enum { DRAW_ICON=909, DRAW_NAME=911, DRAW_VARIANT=910, DRAW_FIRST=912, DRAW_SECOND=913 };
void func_8041E408_de(s32 index) {
    void *window;
    RequestDrawScreen *screen;
    MenuWidget *widget;
    s32 model;
    char *name;
    void *widgetObject;
    void *variantObject;
    char ***variantSlot;
    screen = D_800E39C0;
    window = screen->roots[index];
    if (screen->count < index || D_80153F80[index].id < 0) {
        func_8040E8D8_de(window, 0);
    } else {
        widgetObject = func_8040EC30_de(window, DRAW_ICON);
        widget = widgetObject;
        widget->alpha = 125;
        model = func_8041F140_de(D_80153F80[index].id);
        widget->value = D_800E3A58[model].portrait;
        widgetObject = func_8040EC30_de(window, DRAW_NAME);
        widget = widgetObject;
        widget->alpha = 125;
        model = func_8041EC44_de(D_80153F80[index].variant, D_80153F80[index].id);
    name = D_80153F80[index].name;
        func_802A025C_de((u8 *)name,
          (u8 *)*D_800E381C[D_80153F80[index].variant][model].text
        );
        widget->text = name;
        widgetObject = func_8040EC30_de(window, DRAW_VARIANT);
        widget = widgetObject;
        widget->alpha = 125;
        variantObject = &D_800DF964[D_80153F80[index].variant];
        variantSlot = variantObject;
        widget->text = **variantSlot;
        widgetObject = func_8040EC30_de(window, DRAW_FIRST);
        widget = widgetObject;
        widget->alpha = 125;
        widget->value = D_800DF740[D_80153F80[index].word8].first;
        widgetObject = func_8040EC30_de(window, DRAW_SECOND);
        widget = widgetObject;
        widget->alpha = 125;
        widget->value = D_800DF740[D_80153F80[index].word8].second;
    }
}
#endif

#ifdef NON_MATCHING
#include "TYPES.H"

typedef struct {
    u8 pad0[0x78];
    u8 enabled;
    u8 pad79[6];
    u8 slot;
    u8 character;
    u8 variant;
    u8 pad82[2];
    char name[13];
    u8 bot;
    u8 mode;
    u8 shown;
    u8 pad94[2];
} Player_u1;
typedef struct { u8 pad0[0xD0]; Player_u1 players[8]; } Game_u1;
typedef union { s32 word; u8 bytes[4]; } Word_u1;
typedef struct { Word_u1 id, tier, mode, shown; char name[12]; } Request_u1;
extern Game_u1 D_801462C8;
extern Request_u1 D_80153F80[];
extern void func_802A025C_de(char *, char *);

void func_8041E5F8_de(void)
{
    Player_u1 *player;
    Player_u1 *probe;
    s32 slot = 7;
    s32 i = 0;
    player = &D_801462C8.players[7];
    do {
        if (slot <= 0) return;
        if (D_80153F80[i].id.word >= 0) {
            probe = &D_801462C8.players[slot];
            while (probe->enabled == 1) {
                probe--;
                slot--;
                player--;
                if (slot <= 0) break;
            }
            if (slot >= 0) {
                player->bot = 1;
                player->enabled = 1;
                player->slot = slot;
                slot--;
                player->character = D_80153F80[i].id.bytes[3];
                player->shown = D_80153F80[i].tier.bytes[3];
                player->mode = D_80153F80[i].mode.bytes[3];
                player->variant = D_80153F80[i].shown.bytes[3];
                func_802A025C_de(player->name, D_80153F80[i].name);
                player--;
            }
        }
        i++;
    } while (i < 3);
}
#else
INCLUDE_ASM("ovl_80400000", func_8041E5F8_de);
#endif
