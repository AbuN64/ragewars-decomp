#include "include_asm.h"
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RECORDRECAT1C.H"
#include "COMMON/MENURECAT24.H"
#include "TYPES.H"

/* Enters pak menu mode 2: sets the mode flags, shows the D_0044FFA4 prompt when a message is pending (D_800E28C0), and otherwise clears the owner's 0x01000000 flag, probes the Controller Pak on the selected channel, falls back to func_80405F48_de when func_80404F04_de reports none, and shows the D_0044EA2C, D_0044ED44 or D_0044E9C0 prompt according to func_80404F3C_de and func_80405598_de. */











extern s32 D_8015375C;
extern s32 D_800E28C0;
extern char D_8014561C[];
extern char D_0044FFA4[];
extern unsigned char D_0044E4B0[];
extern char D_0044EA2C[];
extern char D_0044ED44[];
extern char D_0044E9C0[];
extern void func_80404E28_de(s32 ch);
extern s32 func_80404F04_de(s32 ch);
extern s32 func_80404F3C_de(s32 ch);
extern s32 func_80405598_de(s32 ch);
extern void func_80442574_de(char *, char *, ObjRecAt5DC *, PakMenuSlot *, char *);
void func_804070F4_de(Shared_PakMenu *menu)
{
  Shared_PakMenu *new_var3;
  int new_var;
  char *new_var2;
  s32 ch;
  new_var = 1;
  D_800DE874 = 2;
  D_8014D4C0_de = 0;
  D_8014D4DC = 0;
  D_80153760 = new_var;
  D_8014D4EC_de = 0;
  D_80153784 = 0;
  D_8015375C = 0;
  ch = menu->slot->unk4;
  if (D_800E28C0 != 0)
  {
    D_80153784 = 1;
    func_80442574_de(D_8014561C, D_0044FFA4, menu->player, menu->slot, 0);
    return;
  }
  menu->items[20].flags &= ~0x01000000;
  func_80404E28_de(menu->slot->unk4);
  new_var = 0;
  if (func_80404F04_de(ch) == new_var)
  {
    func_80405F48_de(menu);
    return;
  }
  D_80153784 = 1;
  if (func_80404F3C_de(ch) != new_var)
  {
    new_var2 = D_0044EA2C;
    func_80442574_de(D_8014561C, new_var2, menu->player, menu->slot, (char *) 1);
  }
  else
  {
    new_var3 = menu;
    if (func_80405598_de(ch) != 0)
    {
      func_80442574_de(D_8014561C, D_0044ED44, new_var3->player, menu->slot, D_0044E4B0);
    }
    else
    {
      func_80442574_de(D_8014561C, D_0044E9C0, new_var3->player, new_var3->slot, D_0044FFA4);
    }
  }
}

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAK_SAVE_TEXT.H"
extern s32 D_8015375C, D_800E28C8, D_8014D4C0_de;
extern void *D_800DE860_de;
extern struct Shape_typemap_165 *D_800DE864_de;
extern s32 D_800DE868, D_800E28BC;
extern char D_80153738[], D_8014561C[];
extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
extern s32 func_804057EC_de(s32);
extern s32 func_80405160_de(s32, s32 *);
extern s32 func_804050CC_de(s32, s32 *);
extern s32 func_80405454_de(s32, char *);
extern s32 func_80404958_de(s32, s32, void *, char *, char *, char *);
extern void func_80442574_de(void *, void *, void *, void *, void *);
extern void func_80253908_de(s32);
extern void func_80253838_de(s32, void *);
/* Save the small controller-pak record when capacity allows, release the
 * pending resources, and show the channel-specific success/error dialog. */
s32 func_80407290_de(s32 unused, struct Shared_PakMenu *menu)
{
    struct SharedPlayer *player;
    char extension[8];
    char *label;
    char *dialog;
    s32 channel, freeBytes, slots, required, status = 0;
    s32 insufficient = 1;
    s32 attempted = 0;
    if (D_8015375C == 0) {
        player = menu->player;
        channel = menu->owner->unk4;
    } else {
        player = 0;
        channel = D_800E28C8;
    }
    if (D_8014D4C0_de != 0) {
        required = func_804057EC_de(0x18);
        status = func_80405160_de(channel, &freeBytes);
        if (status == 0) {
            if (required <= freeBytes) {
                status = func_804050CC_de(channel, &slots);
                if (status == 0 && slots != 0) {
                    insufficient = 0;
                    status = func_80405454_de(channel, extension);
                    if (status == 0) {
                        attempted = 1;
                        status = func_80404958_de(channel, 0x18, D_80153738,
                                                 rw_pak_save_name(), extension, rw_pak_save_code());
                    }
                }
            }
            if (insufficient != 0) {
                func_80442574_de(D_8014561C, rw_pak_no_space_dialog(), player,
                                player->views5E8.view698_34.unk698, menu->dialogData);
                return 0;
            }
        }
    }
    if (D_800DE860_de != 0 || D_800DE864_de != 0) func_80253908_de(0);
    if (D_800DE860_de != 0) func_80253838_de(0, D_800DE860_de);
    if (D_800DE864_de != 0) func_80253838_de(0, D_800DE864_de);
    D_800DE860_de = 0;
    D_800DE864_de = 0;
    D_800DE868 = 0;
    D_800E28BC = 0;
    if (!attempted) return 1;
    switch (channel) {
    case 1: label = D_00450C14_de; break;
    case 2: label = D_00450C38_de; break;
    case 3: label = D_00450C5C_de; break;
    default: label = D_00450BF0_de; break;
    }
    dialog = status != 0 ? rw_pak_save_error_dialog() : rw_pak_save_success_dialog();
    func_80442574_de(D_8014561C, dialog, player,
                    player->views5E8.view698_34.unk698, label);
    return 1;
}
#else
INCLUDE_ASM("ovl_80400000", func_80407290_de);
#endif

INCLUDE_ASM("ovl_80400000", func_80407578_de);
