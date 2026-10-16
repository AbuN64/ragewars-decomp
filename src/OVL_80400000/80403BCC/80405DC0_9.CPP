#include "shared/pak_menu.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80405454.h"
#include "span_16E000/code_80405DC0.h"
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
