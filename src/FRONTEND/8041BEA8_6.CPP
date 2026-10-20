#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LABEL.H"
#include "TYPES.H"
#include "FRONTEND/8041BEA8_6.H"

#if defined(VERSION_DE)
INCLUDE_ASM("ovl_80400000", func_8041C614);
#endif
#if !(defined(VERSION_DE))
INCLUDE_ASM("ovl_80400000", func_8041C610_de);
#endif

INCLUDE_ASM("ovl_80400000", func_8041C7F4_de);

INCLUDE_ASM("ovl_80400000", func_8041CAD8_de);

/* Copies the three-word vector passed by value into the object's vector at 0x480. */





void func_8041CDB0_de(ObjRecAt480 *arg0, CVector3 v) {
    arg0->unk480 = v;
}

/* Copies the three-word vector passed by value into the object's vector at 0x48C. */





void func_8041CDDC_de(ObjRecAt48C *arg0, CVector3 v) {
    arg0->unk48C = v;
}

/* Stores arg1 into the word at 0x498 of the object arg0. */



void func_8041CE08_de(ObjRecAt498 *arg0, s32 arg1) {
    arg0->unk498 = arg1;
}

/* Stores a value into the word at offset 0x49C of an object; func_80420618_de and func_8043AB40_de call
   it with zero, func_8041CAD8_de writes the same word directly and func_8041C7F4_de reads it. */


void func_8041CE10_de(struct Object49C *object, s32 value) {
    object->value = value;
}

/* Sets field 0x274 of arg0 to 0xFFFF and then calls func_8041C610_de on it. */
void func_8041CE18_de(Unk8041CE88 *arg0) {
    arg0->unk274 = 0xFFFF;
    func_8041C610_de(arg0);
}

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_8041CEA8_us_padding_180EA8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("ovl_80400000", func_8041D278_eu_x_padding_10D278);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("ovl_80400000", func_8041D278_eu_padding_193278);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("ovl_80400000", func_8041CE38_de_padding_182E38);
#endif
