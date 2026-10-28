#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"
#include "include_asm.h"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "FRONTEND/MENUIMAGE.H"

#if defined(VERSION_US_REV1) || defined(VERSION_EU) || defined(VERSION_DE) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
#define Frontend_CreatePakProfileScreen Frontend_CreatePakProfileScreenEu
#elif defined(VERSION_DE)
#define Frontend_CreatePakProfileScreen Frontend_CreatePakProfileScreenDe
#elif defined(VERSION_EU_X)
#define Frontend_CreatePakProfileScreen Frontend_CreatePakProfileScreenEux
#endif
/* Sprite ids of the setup screen: the first column is the id in the US rev 1 and EU builds. */
#if defined(VERSION_DE)
#define SPRITE_285 0x281
#elif defined(VERSION_EU_X)
#define SPRITE_285 0x28A
#else
#define SPRITE_285 0x285
#endif
#if defined(VERSION_DE)
#define SPRITE_2FB 0x29E
#elif defined(VERSION_EU_X)
#define SPRITE_2FB 0x300
#else
#define SPRITE_2FB 0x2FB
#endif
#if defined(VERSION_DE)
#define SPRITE_2A2 0x2F7
#elif defined(VERSION_EU_X)
#define SPRITE_2A2 0x2A7
#else
#define SPRITE_2A2 0x2A2
#endif
#if defined(VERSION_DE)
#define SPRITE_286 0x282
#elif defined(VERSION_EU_X)
#define SPRITE_286 0x28B
#else
#define SPRITE_286 0x286
#endif
#if defined(VERSION_DE)
#define SPRITE_287 0x283
#elif defined(VERSION_EU_X)
#define SPRITE_287 0x28C
#else
#define SPRITE_287 0x287
#endif
#if defined(VERSION_DE)
#define SPRITE_2FC 0x29F
#elif defined(VERSION_EU_X)
#define SPRITE_2FC 0x301
#else
#define SPRITE_2FC 0x2FC
#endif
#if defined(VERSION_DE)
#define SPRITE_2A3 0x2F8
#elif defined(VERSION_EU_X)
#define SPRITE_2A3 0x2A8
#else
#define SPRITE_2A3 0x2A3
#endif
#if defined(VERSION_DE)
#define SPRITE_2FD 0x2F6
#elif defined(VERSION_EU_X)
#define SPRITE_2FD 0x302
#else
#define SPRITE_2FD 0x2FD
#endif
#if defined(VERSION_DE)
#define SPRITE_2FA 0x2F9
#elif defined(VERSION_EU_X)
#define SPRITE_2FA 0x2FF
#else
#define SPRITE_2FA 0x2FA
#endif
#if defined(VERSION_DE)
#define SPRITE_293 0x289
#elif defined(VERSION_EU_X)
#define SPRITE_293 0x28D
#else
#define SPRITE_293 0x293
#endif
#if defined(VERSION_DE)
#define SPRITE_296 0x287
#elif defined(VERSION_EU_X)
#define SPRITE_296 0x290
#else
#define SPRITE_296 0x296
#endif
#if defined(VERSION_DE)
#define SPRITE_288 0x284
#elif defined(VERSION_EU_X)
#define SPRITE_288 0x28E
#else
#define SPRITE_288 0x288
#endif
#if defined(VERSION_DE)
#define SPRITE_2A1 0x288
#elif defined(VERSION_EU_X)
#define SPRITE_2A1 0x28F
#else
#define SPRITE_2A1 0x2A1
#endif
#if defined(VERSION_DE)
#define SPRITE_295 0x285
#elif defined(VERSION_EU_X)
#define SPRITE_295 0x291
#else
#define SPRITE_295 0x295
#endif
#if defined(VERSION_DE)
#define SPRITE_289 0x28A
#elif defined(VERSION_EU_X)
#define SPRITE_289 0x292
#else
#define SPRITE_289 0x289
#endif
#if defined(VERSION_DE)
#define SPRITE_297 0x294
#elif defined(VERSION_EU_X)
#define SPRITE_297 0x29D
#else
#define SPRITE_297 0x297
#endif
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_GAMESLOT.H"

/* Creates the match setup block D_800E54A4 for screen arg0: allocates and clears it, loads its sprites and centres the two banner rows, links every player slot, shows the header for the game mode, resets each player's menu state, records and name entries, then starts each player in the state the mode needs (team handoff for mode 5, memory-card check for mode 6, the host for mode 7) and starts the menu music. Returns zero. */



typedef struct PakSetupProfile {
    char pad0[0xD];
    s8 owner;
    s8 dropped;
    char padF[0x190 - 0xF];
} PakSetupProfile;


extern s32 D_800DF4C0;
extern s32 D_800DF4C4;
extern PakSetupProfile D_80102B00[];

extern void *Cache_AllocateMemory(s32);
extern void Frontend_InitMenuImage(void *, s32, s32, s32, s32);
extern void *SmpOverlay_CreateOverlayNode(void *, s32);
extern void SmpOverlay_ShowSlotById(void *, s32, s32);
extern void Widget_SetWidgetFlag08(MenuWidget *, s32);
extern void *SmpFlicker_CreateFlickerWidget(s32, s32);
extern void PAKInterface_RelabelSlotRows(s32);
extern void PAKInterface_RefreshPlayerPanel(s32);
extern void Control_EnableControllerPak(s32);
extern void Player_InitializeProfile(Profile *);
extern void Note_ProbeStatus(s32);
extern s32 Note_GetStatus(s32);
extern void Frontend_RequestScreenMode(s32);
extern void Tsmos_DeactivateControllerState(void);
extern void Tsmos_SetTimerState(s32);

s32 Frontend_CreatePakProfileScreen(void *screen) {
    PakMenuController *block;
    Shared_Game *globals;
    MenuWidget *sprite;
    MenuWidget *row;
    s32 rest;
    s32 i;
    s32 j;

    block = Cache_AllocateMemory(sizeof(PakMenuController));
    D_800E54A4 = block;
    block->window = screen;
    Frontend_InitMenuImage(block->menu, 0x67, 0, 0, 0);
    D_800E54A4->list = SmpOverlay_CreateOverlayNode(screen, 4);
    SmpOverlay_ShowSlotById(screen, 0, SPRITE_285);
    SmpOverlay_ShowSlotById(screen, 1, SPRITE_285);
    SmpOverlay_ShowSlotById(screen, 2, SPRITE_285);
    SmpOverlay_ShowSlotById(screen, 3, SPRITE_285);
    for (i = 0; i < 4; i++) {
        D_800E54A4->selected[i] = 0;
    }
    D_800E54A4->ready = 1;
    D_800E54A4->timer = 4;
    D_800E54A4->top = Node_FindWidgetByResourceId(screen, SPRITE_2FB);
    D_800E54A4->top->x -= D_800E54A4->top->w;
    D_800E54A4->topStep = D_800E54A4->top->w / 4;
    rest = D_800E54A4->top->w - D_800E54A4->topStep * 4;
    D_800E54A4->top->x += rest;
    D_800E54A4->bottom = Node_FindWidgetByResourceId(screen, SPRITE_2A2);
    D_800E54A4->bottom->x += D_800E54A4->bottom->w;
    D_800E54A4->bottomStep = D_800E54A4->bottom->w / 4;
    rest = D_800E54A4->bottom->w - D_800E54A4->bottomStep * 4;
    D_800E54A4->bottom->x -= rest;
    Node_FindWidgetByResourceId(screen, SPRITE_286)->alpha = 0x6E;
    D_800E54A4->music = SmpFlicker_CreateFlickerWidget(SPRITE_287, 0xFF);
    D_800E54A4->title = Node_FindWidgetByResourceId(screen, SPRITE_287);
    Widget_SetWidgetFlag08(D_800E54A4->title, 0);
    D_800E54A4->players[0].sprite = Node_FindWidgetByResourceId(screen, SPRITE_2FC);
    D_800E54A4->players[1].sprite = Node_FindWidgetByResourceId(screen, SPRITE_2A3);
    D_800E54A4->players[2].sprite = Node_FindWidgetByResourceId(screen, SPRITE_2FD);
    D_800E54A4->players[3].sprite = Node_FindWidgetByResourceId(screen, SPRITE_2FA);
    D_800E54A4->phase = D_800E54A0;
    for (i = 0; i < 4; i++) {
        D_800E54A4->links[i].player = -1;
        D_800E54A4->links[i].entry = 0;
        D_800E54A4->links[i].state = 2;
    }
    switch (D_800E54A4->phase) {
    case 5:
        sprite = Node_FindWidgetByResourceId(screen, SPRITE_293);
        Widget_SetWidgetFlag08(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 6:
        sprite = Node_FindWidgetByResourceId(screen, SPRITE_296);
        Widget_SetWidgetFlag08(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 4:
        sprite = Node_FindWidgetByResourceId(screen, SPRITE_288);
        Widget_SetWidgetFlag08(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 0:
        sprite = Node_FindWidgetByResourceId(screen, SPRITE_2A1);
        Widget_SetWidgetFlag08(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 3:
        sprite = Node_FindWidgetByResourceId(screen, SPRITE_295);
        Widget_SetWidgetFlag08(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 1:
        sprite = Node_FindWidgetByResourceId(screen, SPRITE_289);
        Widget_SetWidgetFlag08(sprite, 1);
        sprite->alpha = 0xFF;
        for (i = 0; i < 4; i++) {
            if (D_80102B00[i].owner >= 0) {
                if (D_80102B00[i].dropped == 1) {
                    D_80102B00[i].owner = -1;
                    D_80102B00[i].dropped = 0;
                }
                if (D_80102B00[i].owner >= 0) {
                    D_800E54A4->links[i].player = 0;
                    D_800E54A4->links[i].entry = i;
                    D_800E54A4->links[i].state = 1;
                }
            }
        }
        PAKInterface_RelabelSlotRows(-1);
        break;
    case 7:
        break;
    case 2:
        sprite = Node_FindWidgetByResourceId(screen, SPRITE_297);
        Widget_SetWidgetFlag08(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    }
    for (i = 0; i < 4; i++) {
        D_800E54A4->players[i].state = 0;
        D_800E54A4->players[i].menu = 0;
        D_800E54A4->players[i].back = -1;
        PAKInterface_RefreshPlayerPanel(i);
        Control_EnableControllerPak(i);
        for (j = 0; j < 4; j++) {
            Player_InitializeProfile(&D_800E54A4->players[i].records[j]);
        }
        for (j = 0; j < 16; j++) {
            XPlus_FillMemory(D_800E54A4->players[i].noteTexts[j].name, 0, 0x14);
            XPlus_FillMemory(D_800E54A4->players[i].noteTexts[j].size, 0, 0xA);
        }
        XPlus_FillMemory(D_800E54A4->players[i].codes[2], 0, 0xA);
        XPlus_FillMemory(D_800E54A4->players[i].codes[1], 0, 0xA);
        XPlus_FillMemory(D_800E54A4->players[i].codes[0], 0, 0xA);
        D_800E54A4->players[i].slot = 0;
        D_800E54A4->players[i].choice = 0;
        for (j = 0; j < 4; j++) {
            D_800E54A4->players[i].used[j] = 2;
            D_800E54A4->players[i].notes[j] = 0;
        }
        D_800E54A4->players[i].record = 0;
        D_800E54A4->players[i].host = 0;
        D_800E54A4->players[i].profile = 0;
        D_800E54A4->players[i].sub = 0;
        D_800E54A4->players[i].next = -1;
        D_800E54A4->players[i].port = -1;
    }
    D_800E54A4->focus = -1;
    switch (D_800E54A4->phase) {
    case 5:
        for (i = 0; i < 4; i++) {
            D_800E54A4->players[i].state = 0xE;
        }
        for (i = 0; i < 4; i++) {
            globals = &D_801462C8;
            if (D_80102B00[i].dropped == 0 && D_80102B00[i].owner >= 0 && globals->playerSettings[i].enabled == 1 &&
                globals->playerSettings[i].locked == 0) {
                D_800E54A4->players[D_80102B00[i].owner].back = 2;
                D_800E54A4->players[D_80102B00[i].owner].state = 2;
                D_800E54A4->players[D_80102B00[i].owner].next = 6;
            }
        }
        for (i = 0; i < 4; i++) {
            PAKInterface_RefreshPlayerPanel(i);
        }
        break;
    case 6:
        if (D_800DF4C4 == 0) {
            for (i = 0; i < 4; i++) {
                Note_ProbeStatus(i);
                switch (Note_GetStatus(i)) {
                case -4:
                case -3:
                case -1:
                case 0:
                    D_800E54A4->players[i].back = 2;
                    D_800E54A4->players[i].state = 2;
                    D_800E54A4->players[i].next = 4;
                    PAKInterface_RefreshPlayerPanel(i);
                    break;
                }
            }
        } else {
            Note_ProbeStatus(D_800DF4C0);
            switch (Note_GetStatus(D_800DF4C0)) {
            case -4:
            case -3:
            case -1:
            case 0:
                D_800E54A4->players[D_800DF4C0].back = 2;
                D_800E54A4->players[D_800DF4C0].state = 2;
                D_800E54A4->players[D_800DF4C0].next = 4;
                PAKInterface_RefreshPlayerPanel(D_800DF4C0);
                break;
            }
        }
        break;
    case 7:
        D_800E54A4->players[0].back = 2;
        D_800E54A4->players[0].state = 2;
        D_800E54A4->players[0].next = 0xD;
        D_800E54A4->players[0].sub = 6;
        PAKInterface_RefreshPlayerPanel(0);
        break;
    }
    Frontend_RequestScreenMode(0);
    Tsmos_DeactivateControllerState();
    Tsmos_SetTimerState(0);
    SoundElement_PlayFlatSound(0xE78);
    return 0;
}
#endif

/* Runs the block D_800E54A4 points to on event 1: in phase 3 at 0x4C it counts each player's timer
   at 0x14 of its 2920-byte record at 0x58 down and, when one expires, marks it -1 and resets that
   player through Note_ProbeStatus and PAKInterface_ResolvePlayerPakState between Tsmos_DeactivateControllerState and Tsmos_ActivateControllerState; then it
   advances the menu at 0x8 with Frontend_DrawMenuImage and Frontend_AdvanceMenuImageTransition while Frontend_GetMenuImageState reports 1, and
   once it reports 2 in phase 5 at 0x54 calls MarkMenuEventHandled and moves on through Frontend_ContinueCupOrOpenResults,
   Frontend_OpenControllerModeResults or Achieve_SelectPostResultScreen as the cartridge's jump table jtbl_800E1BB0 chooses for option
   byte D_801462D5 up to 4. Returns zero. */





extern void Tsmos_DeactivateControllerState(void);
extern void Tsmos_ActivateControllerState(void);
extern void Note_ProbeStatus(s32);
extern void PAKInterface_ResolvePlayerPakState(s32);
extern s32 Frontend_GetMenuImageState(void *);
extern void Frontend_DrawMenuImage(void *);
extern void MarkMenuEventHandled();
extern void Frontend_ContinueCupOrOpenResults(void);
extern void Frontend_OpenControllerModeResults(void);
extern void Achieve_SelectPostResultScreen(void);

s32 Frontend_UpdatePakScreenExit(void *unused0, void *unused1, s32 event) {
    s32 i;
    u32 option;

    if (event != 1) {
        return 0;
    }
    if (D_800E54A4->ready == 3) {
        for (i = 0; i < 4; i++) {
            if (D_800E54A4->players[i].back > 0 && --D_800E54A4->players[i].back == 0) {
                D_800E54A4->players[i].back = -1;
                Tsmos_DeactivateControllerState();
                Note_ProbeStatus(i);
                PAKInterface_ResolvePlayerPakState(i);
                Tsmos_ActivateControllerState();
            }
        }
    }
    if (Frontend_GetMenuImageState(D_800E54A4->menu) != 1) {
        return 0;
    }
    Frontend_DrawMenuImage(D_800E54A4->menu);
    Frontend_AdvanceMenuImageTransition(D_800E54A4->menu);
    if (Frontend_GetMenuImageState(D_800E54A4->menu) != 2) {
        return 0;
    }
    if (D_800E54A4->phase != 5) {
        return 0;
    }
    MarkMenuEventHandled();
    option = D_801462C8.controllerMode;
    if (option >= 5) {
        goto done;
    }
    switch (option) {
        case 0: goto option_a;
        case 1: goto option_c;
        case 2: goto option_b;
        case 3: goto option_c;
        case 4: goto option_c;
        }
option_a:
    Frontend_ContinueCupOrOpenResults();
    return 0;
option_b:
    Frontend_OpenControllerModeResults();
    return 0;
option_c:
    Achieve_SelectPostResultScreen();
done:
    return 0;
}
