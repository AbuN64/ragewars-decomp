#include "shared/world.h"
#include "span_16E000/code_804264F0.h"
#include "types.h"

/* Formats the name of entry D_800E4690's word at 0xA44 into a local 0x40-byte buffer through
   func_8028D380_de from D_8011FE88, passes the length func_802A0494_de measures to func_802A025C_de for the
   text object at offset 0xA04, and points word 0x38 of the object at 0x998 to that text object. */




extern struct State_func_804280BC_de *D_800E4690;

extern void func_8028D380_de(void *, s32, char *, s32);
extern s32 func_802A0494_de(char *);
extern void func_802A025C_de(void *, s32);

void func_804280BC_de(void) {
    char buffer[0x40];

    func_8028D380_de(&D_8011FE88, D_800E4690->name, buffer, 0x3F);
    func_802A025C_de(D_800E4690->text, func_802A0494_de(buffer));
    D_800E4690->owner->unk38 = D_800E4690->text;
}
