#include "span_16E000/code_804264F0.h"
#include "types.h"

/* Calls func_8029973C_de and func_804273D4_de, passes the two words after the identifier in the
   28-byte entry D_800E4690's selection at 0xA44 picks from D_800E4694 to func_8042E9A0_de, then
   calls func_8042E988_de with 0x19. Returns zero. */




extern struct State_func_80428E10_de *D_800E4690;
extern struct EntryRecAt8V3 D_800E4694[];
extern void func_8029973C_de();

extern void func_8042E9A0_de(s32, s32);
extern void func_8042E988_de(s32);

s32 func_80428E10_de(void) {
    s32 selection;

    func_8029973C_de();
    func_804273D4_de();
    selection = D_800E4690->selection;
    func_8042E9A0_de(D_800E4694[selection].first, D_800E4694[selection].second);
    func_8042E988_de(0x19);
    return 0;
}
