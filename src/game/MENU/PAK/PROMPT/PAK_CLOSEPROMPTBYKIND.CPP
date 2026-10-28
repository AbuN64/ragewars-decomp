#include "include_asm.h"
#include "COMMON/LONE/D_0044E4B0.H"
#include "COMMON/MENURECAT24.H"
#include "MENU/80405DC0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/WORLD.H"
#include "COMMON/RECORDRECAT1C.H"
#include "TYPES.H"
#include "MENU/PAK/80405DC0.H"
#include "MENU/PAK/8043F69C_6.H"

/* Confirms the selected pak menu entry: marks the menu busy and returns when Snapshot_CheckStatusPrompt takes
   over the selected channel; with a profile loaded (D_80153730) it creates the player through
   func_8022A5C0_de, copies the loaded profile (flags, four words and eight name bytes) into the
   player's profile, applies the loaded team through func_8044A0C4_de and shows the player's message
   through Pak_AllocateMenu; otherwise it deletes the chosen note through Note_DeleteNote and shows the
   D_44F7C0 or D_44F82C result prompt. Returns 1. */









extern s32 D_8015375C;

extern s32 D_80153730;

extern u8 D_8014D4B0_de;

extern struct { u16 value; } D_80153738;

extern struct { u16 value; } D_8014D4AA;

extern struct { u16 value; } D_8014D4AC_de;

extern struct { u16 value; } D_8014D4AE;

extern u8 D_8014D4B4[];

extern s8 D_8014D490;

extern char D_80145040;

extern char D_0044FA6C[];

extern char D_8014561C[];

extern SharedPlayer *Playerai_FindPlayerByController(char *pool, PakMenuSlot *slot);

extern void Player_StartPlayerAnimation(SharedPlayer *player, s32 team);

extern void Pak_AllocateMenu(char *text, MenuPakConfirmProfileOrDeleteNote *menu, char *format);

extern s32 Note_DeleteNote(s32 ch, s32 index);

/* Closes the current pak menu prompt by its kind D_80153788: kind 8 is refused (returns 0); kinds
   9 and 5 release the slot's controller through func_80264248_de and func_802647E8_de; kind 9 then either
   hands the channel back through func_80264788_de and reopens the player's menu 0x5EC (load menu
   without a pending save) or returns to the main menu D_8011FAC0; kind 5 hands the channel back and
   reopens menu D_8013B2C8; kind 6 in the pak manager sets D_8014ADA0; kinds 4 and 3 recheck the pak
   and show D_44F100 or D_450BD0, or D_44F124, and any other kind shows the menu's pending prompt
   (clearing the placeholder 1) in the player's message box. Returns 1. */









extern s32 D_80153788;

extern s32 D_80153758;

extern s32 D_8014ADA0;


#include "COMMON/GAME_SESSION.H"

extern char D_0044E48C[];


extern char D_0044E4D4[];

extern char D_0044FFA4[];


extern void Control_SetProfileMode(PakMenuSlot *slot, s32 mode);

extern void Control_DisableControllerPak(s32 ch);

extern void OvlScene_SetSelection(char *, s32, s32);

struct GameSession;
extern void Match_ResetGameClockAndSelectSpawn(struct GameSession *);

extern void Pak_ProbeStatus(s32 ch);

extern s32 Note_GetStatus(s32 ch);

extern s32 Control_TakePakChange(s32 ch);

extern s32 D_80153778;

extern s32 D_8014D4C4;

extern char D_0044EB94[];

extern char D_0044ED20[];

extern s32 Note_RepairIdIfNeeded(s32 ch);

extern s32 Snapshot_SaveSnapshotAndClose(void *owner, MenuRecAt24 *menu, void *arg);

s32 Pak_ConfirmProfileOrDeleteNote(void *unused, MenuPakConfirmProfileOrDeleteNote *menu) {

    s32 ch;
    SharedPlayer *player;
    ProfileRecAt84 *profile;
    s32 i;

    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->slot->unk4;
    }
    if (Snapshot_CheckStatusPrompt(menu, ch, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_80153730 != 0) {
        player = Playerai_FindPlayerByController(&D_80145040, menu->slot);
        menu->player = player;
        profile = player->views5D8.view5D8_6.profile;
        profile->flags = D_8014D4B0_de;
        profile->words[0] = D_80153738.value;
        profile->words[1] = D_8014D4AA.value;
        profile->words[2] = D_8014D4AC_de.value;
        profile->words[3] = D_8014D4AE.value;
        for (i = 0; i < 8; i++) {
            profile->name[i] = D_8014D4B4[i];
        }
        Player_StartPlayerAnimation(player, D_8014D490);
        Pak_AllocateMenu(player->views5DC.view5DC_7.messages + 0x554, menu, D_0044FA6C);
        return 1;
    }
    if (Note_DeleteNote(ch, D_8014D4FC) == 0) {
        Menu_OpenDialog(D_8014561C, D_0044EB70, menu->player, menu->slot, menu->prompt);
    } else {
        Menu_OpenDialog(D_8014561C, D_0044EBDC, menu->player, menu->slot, menu->prompt);
    }
    return 1;
}

s32 Pak_ClosePromptByKind(void *owner, MenuRecAt24 *menu) {

    s32 ch;
    s32 status;
    s32 connected;

    if (D_80153788 == 8) {
        return 0;
    }
    if (D_80153788 == 9 || D_80153788 == 5) {
        Control_ResetControllerPak(menu->slot);
        Control_SetProfileMode(menu->slot, 1);
    }
    if (D_80153788 == 9) {
        if (D_80153760 != 0 && D_8014D4EC_de == 0 && D_80153758 == 0) {
            if (D_8015375C != 0) {
                ch = D_800E28C8;
            } else {
                ch = menu->slot->unk4;
            }
            Control_DisableControllerPak(ch);
            OvlScene_SetSelection(&g_world, menu->player->menu, 2);
            return 1;
        }
        Match_ResetGameClockAndSelectSpawn(&D_8011FAC0);
        return 1;
    }
    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->slot->unk4;
    }
    if (D_80153788 == 5) {
        Control_DisableControllerPak(ch);
        OvlScene_SetSelection(&g_world, g_world.selectionValues[3], 2);
    }
    if (D_8015375C != 0 && D_80153788 == 6) {
        D_8014ADA0 = 1;
    }
    if (D_80153788 == 4 && D_80153760 != 0 && D_8014D4EC_de == 0) {
        Pak_ProbeStatus(ch);
        status = Note_GetStatus(ch);
        connected = Control_TakePakChange(ch);
        if ((status == 0 || connected != 0) && status != -2 && menu->prompt == (char *)1) {
            Menu_OpenDialog(D_8014561C, D_0044E4B0, menu->player, menu->slot, 0);
        } else {
            Menu_OpenDialog(D_8014561C, D_0044FFA4, menu->player, menu->slot, 0);
        }
    } else if (D_80153788 == 3 && g_pakAlternatePromptEnabled != 0) {
        Pak_ProbeStatus(ch);
        status = Note_GetStatus(ch);
        connected = Control_TakePakChange(ch);
        if ((status == 0 || connected != 0) && status != -2 && menu->prompt == (char *)1) {
            Menu_OpenDialog(D_8014561C, D_0044E4D4, menu->player, menu->slot, 0);
        }
    } else {
        if (menu->prompt == (char *)1) {
            menu->prompt = 0;
        }
        if (menu->prompt != 0) {
            Menu_OpenDialog(menu->prompt != D_0044E48C && menu->player != 0 ?
                              menu->player->messages->text : D_8014561C,
                          menu->prompt, menu->player, menu->slot, ch);
        }
    }
    return 1;
}

s32 Pak_ConfirmPendingOperation(void *owner, MenuRecAt24 *menu, void *arg) {

    s32 ch;

    switch (D_80153778) {
        case 4:
            if (D_8015375C != 0) {
                ch = D_800E28C8;
            } else {
                ch = menu->slot->unk4;
            }
            if (Snapshot_CheckStatusPrompt(menu, ch, 1) != 0) {
                D_80153784 = 1;
                Menu_OpenDialog(D_8014561C, menu->prompt, menu->player, menu->slot, 0);
                break;
            }
            Pak_ProbeStatus(ch);
            if (Note_DeleteNote(ch, D_8014D4C4) == 0) {
                Menu_OpenDialog(D_8014561C, D_0044EB70, menu->player, menu->slot, menu->prompt);
            } else {
                Menu_OpenDialog(D_8014561C, D_0044EBDC, menu->player, menu->slot, menu->prompt);
            }
            break;
        case 3:
            if (D_8015375C != 0) {
                ch = D_800E28C8;
            } else {
                ch = menu->slot->unk4;
            }
            if (Snapshot_CheckStatusPrompt(menu, ch, 1) != 0) {
                D_80153784 = 1;
                Menu_OpenDialog(D_8014561C, menu->prompt, menu->player, menu->slot, 0);
                break;
            }
            Pak_ProbeStatus(ch);
            if (Note_DeleteNote(ch, D_8014D4FC) == 0) {
                Snapshot_SaveSnapshotAndClose(owner, menu, arg);
                return 1;
            }
            Menu_OpenDialog(D_8014561C, D_0044EBDC, menu->player, menu->slot, menu->prompt);
            break;
        case 0:
            if (D_8015375C != 0) {
                ch = D_800E28C8;
            } else {
                ch = menu->slot->unk4;
            }
            if (Snapshot_CheckStatusPrompt(menu, ch, 1) != 0) {
                D_80153784 = 1;
                Menu_OpenDialog(D_8014561C, menu->prompt, menu->player, menu->slot, 0);
                break;
            }
            Pak_ProbeStatus(ch);
            if (Note_RepairIdIfNeeded(ch) == 0) {
                Menu_OpenDialog(D_8014561C, D_0044EB94, menu->player, menu->slot, menu->prompt);
            } else {
                Menu_OpenDialog(D_8014561C, D_0044ED20, menu->player, menu->slot, menu->prompt);
            }
            break;
        case 1:
        case 2:
            if (D_8015375C != 0) {
                D_80142CAC = 1;
            }
            Menu_OpenDialog(D_8014561C, menu->prompt, menu->player, menu->slot, 0);
            break;
    }
    return 1;
}
