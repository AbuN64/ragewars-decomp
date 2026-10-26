#include "MENU/HOLDERRECAT1CV2.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "MENU/ITEMS/80444030_6.H"
#include "RENDER/80291054_9.H"

/* Clears the word held in D_80154100. */
extern s32 D_80154100;

/* Returns the name the object at offset 0x5D8 of an actor's owner holds, falling back to
   D_80146302 when the actor has no owner or the owner has no such object. */






/* Updates the selected menu option in response to the current input state. */
s32 Control_IsAButtonPressed(char *);

 /* extern */
 /* extern */
 /* extern */
extern char D_8010B0E0;





/* Replaces the signed byte at offset 0x7B of the second argument's owner settings (or the defaults D_80146302) with what Pak_AdjustValue returns for the second argument, that byte, 1, 0, 1 and 1, returning zero. Adapted from func_80444610_de with the settings byte made the signed byte at 0x7B. */









extern s32 Pak_AdjustValue(void *, s32, s32, s32, s32, s32);

/* Points an option field at the text D_800D75E0 when the signed byte at offset 0x7B of the second argument's owner settings (or the defaults D_80146302) is zero and at D_800D75E4 when it is one, returning zero. Adapted from func_80444674_de with the settings byte made the signed byte at 0x7B and the texts changed. */













/* Replaces the byte at offset 0x7C of the second argument's owner settings (or the defaults D_80146302) with what Pak_AdjustValue returns for the second argument, that byte, 1, 0, 1 and 1, and returns zero. */









/* Points a field's text at D_800D75F0 when the byte at offset 0x7C of the settings the second argument's owner holds (or of the defaults D_80146302 without an owner or settings) is zero, at D_800D75EC when it is one, and leaves it otherwise, returning zero. Adapted from func_80444BE8_de with the settings pointer checked for null, the byte offset 0x7C, and a nested test over the texts D_800D75F0 and D_800D75EC changed. */












/* Replaces the byte at offset 0x7D of the second argument's owner settings (or the defaults D_80146302) with what Pak_AdjustValue returns for the second argument, that byte, 1, 0, 1 and 1, and returns zero. Adapted from func_80444488_de with the settings byte 0x7D changed. */









/* Points an option field at the text D_800D75F8 when the byte at offset 0x7D of the second argument's owner settings (or the defaults D_80146302) is zero and at D_800D75F4 when it is one, returning zero. */













/* Replaces the byte at offset 0x7E of the second argument's owner settings (or the defaults D_80146302) with what Pak_AdjustValue returns for the second argument, that byte, 1, 0, 1 and 1, and returns zero. Adapted from func_80444488_de with the settings byte 0x7E changed. */









/* Points an option field at the text D_800D7600 when the byte at offset 0x7E of the second argument's owner settings (or the defaults D_80146302) is zero and at D_800D75FC when it is one, returning zero. Adapted from func_804445AC_de with the settings byte 0x7E and the texts D_800D7600 and D_800D75FC changed. */













/* Replaces the option byte D_801462E3 with what Pak_AdjustValue returns for the second argument, that
   byte, 1, 0, 2 and 1, and returns zero. */




/* Replaces the option byte D_801462E7 with what Pak_AdjustValue returns for the second argument, that
   byte, 1, 0, 1 and 1, and returns zero. */

/* Updates the menu item visibility and text for the current configuration. */


                                /* extern */


void func_804441E4_de(void) {
    D_80154100 = 0;
}

char *func_804441F4_de(struct ActorRecAt1C *actor) {
    char *name = D_80146302.text;

    if (actor->owner != 0 && actor->owner->settings != 0) {
        name = actor->owner->settings->text;
    }
    return name;
}

s32 func_8044421C_de(void) {
 if(((s32 (*)(char *))Control_IsLeftPressed)(&D_8010B0E0)) {
 switch(D_801462C8.sceneMask) {
 case 8: D_801462C8.sceneMask=32; break;
 case 16: D_801462C8.sceneMask=8; break;
 case 32: D_801462C8.sceneMask=16; break;
 }
 }
 if(((s32 (*)(char *))Control_IsRightPressed)(&D_8010B0E0) || Control_IsAButtonPressed(&D_8010B0E0)) {
 switch(D_801462C8.sceneMask) {
 case 8: D_801462C8.sceneMask=16; break;
 case 16: D_801462C8.sceneMask=32; break;
 case 32: D_801462C8.sceneMask=8; break;
 }
 }
 return 0;
}

/* Sets bit 24 of the item's flags when D_80146878 is 8 (clears it otherwise) and points the item at the text table for the configuration D_801462D0 (8, 0x10 or 0x20); returns 0. */
s32 func_80444314_de(MenuItemRecAt14 *item) {
    if (D_8011FAC0.mode == 8) {
        item->flags |= 0x01000000;
    } else {
        item->flags &= ~0x01000000;
    }
    switch (D_801462C8.sceneMask) {
    case 8:
        item->table = D_800D35A8;
        break;
    case 0x10:
        item->table = D_800D35AC;
        break;
    case 0x20:
        item->table = D_800D35B0;
        break;
    }
    return 0;
}

s32 func_804443C0_de(void *first, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->option7B = Pak_AdjustValue(holder, settings->option7B, 1, 0, 1, 1);
    return 0;
}

s32 func_80444424_de(struct Field *field, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    switch (settings->option7B) {
    case 0:
        field->text = &D_800D75E0;
        break;
    case 1:
        field->text = &D_800D75E4;
        break;
    }
    return 0;
}

s32 func_80444488_de(void *first, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->option7C = Pak_AdjustValue(holder, settings->option7C, 1, 0, 1, 1);
    return 0;
}

s32 func_804444EC_de(struct FieldRecAt14 *field, struct ActorRecAt1C *holder) {
    s32 result = 0;
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    if (settings->option7C != 0) {
        if (settings->option7C == 1) {
            field->text = D_800D75EC;
        }
    } else {
        field->text = D_800D75F0;
    }
    return result;
}

s32 func_80444548_de(void *first, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->option7D = Pak_AdjustValue(holder, settings->option7D, 1, 0, 1, 1);
    return 0;
}

s32 func_804445AC_de(struct Field *field, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    switch (settings->option7D) {
    case 0:
        field->text = &D_800D75F8;
        break;
    case 1:
        field->text = &D_800D75F4;
        break;
    }
    return 0;
}

s32 func_80444610_de(void *first, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->option7E = Pak_AdjustValue(holder, settings->option7E, 1, 0, 1, 1);
    return 0;
}

s32 func_80444674_de(struct Field *field, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    switch (settings->option7E) {
    case 0:
        field->text = &D_800D7600;
        break;
    case 1:
        field->text = &D_800D75FC;
        break;
    }
    return 0;
}

s32 func_804446D8_de(void *first, void *second) {
    u8 *option = &D_801462C8.firstListMode;

    *option = Pak_AdjustValue(second, *option, 1, 0, 2, 1);
    return 0;
}

s32 func_8044472C_de(struct FieldRecAt14 *field) {
    switch (D_801462C8.firstListMode) {
    case 0:
        field->text = D_800D7604;
        break;
    case 1:
        field->text = D_800D7608;
        break;
    case 2:
        field->text = D_800D760C;
        break;
    default:
        return 0;
    }
    return 0;
}

s32 func_804447A0_de(void *first, void *second) {
    u8 *option = &D_801462C8.unknown1F;

    *option = Pak_AdjustValue(second, *option, 1, 0, 1, 1);
    return 0;
}

s32 func_804447F0_de(StateRecAt14 *arg0) {
    s32 var_v0;

    if ((func_802934F8_de() != 0) && (D_801462C8.local == 0)) {
        arg0->unk8 = arg0->unk8 & 0xFEFFFFFF;
    } else {
        arg0->unk8 = arg0->unk8 | 0x01000000;
    }
    switch (D_801462C8.unknown1F) {                           /* irregular */
    case 0:
        arg0->unk14 = &D_800D35E4;
        break;
    case 1:
        arg0->unk14 = &D_800D35E8;
        break;
    }
    return 0;
}
