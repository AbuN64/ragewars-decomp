#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "shared/pak_load.h"
extern struct Shape_typemap_165 *D_800DE864_de;
extern void *D_800DE860_de;
extern u8 *D_800E28BC;
extern char D_0044E468[], D_0044E4B0[], D_800DCD60[], D_8014561C[];
extern s32 D_8011FECC, D_8015375C, D_80153784, D_800E28C8, D_8014D4DC, D_80153760, D_8014D4EC_de, D_8014D4FC, D_8014D4C4, D_800DE868;
s32 func_8040458C_de(s32, s32, s32 *, u8 *, u8 *, s32 *, u8 *, u8 *);
void func_80405F48_de(void *);
s32 func_802A0238_de(u8 *);
s32 func_802A037C_de(const void *, const void *);
s32 func_80404F58_de(s32, s32, void *, s32);
u32 func_804057F8_de(void *, u32, u32);
void func_80253908_de(s32);
void func_80253838_de(void *, void *);
s32 func_804057BC_de(u8 *, s32);
u8 *func_802A025C_de(u8 *, void *);
void *func_80442574_de(void *, void *, void *, void *, char *);
s32 func_80406178_de(void *, s32, s32);
struct Shape_typemap_165 *func_8025343C_de(s32, s32, u32, void *);
void *func_802A001C_de(void *, s32, u32);
static __inline__ s32 valid_note(u8 *sp28, u8 *sp30) { if ((func_802A0238_de(sp30) == 4) && (func_802A0238_de(sp28) == 2) && (func_802A037C_de(sp30, rw_pak_game_code()) == 0) && (func_802A037C_de(sp28, rw_pak_company()) == 0)) return 1; return 0; }
s32 func_80407748_de(s32 *arg0, Menu_func_804066BC_de *arg1) {
    u8 sp20[8];
    u8 sp28[8];
    u8 sp30[8];
    u8 sp38[16];
    s32 sp48;
    s32 sp4C;
    s32 temp_a1_2;
    s32 temp_s5;
    s32 temp_s7;
    s32 temp_v0;
    s32 var_a1_2;
    s32 current;
    s32 var_s0_2;
    s32 var_s0_4;
    u8 *var_s1;
    char *messageExtra;
    s32 var_s2;
    s32 var_s0;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    char *var_a1;
    struct Shape_typemap_165 *temp_v0_2;
    struct Shape_typemap_165 *temp_v0_3;
    u8 *temp_a0;
    u8 *temp_a0_2;
    u8 *var_s1_2;

    var_s2 = 0;
    temp_s5 = *arg0 - 3;
    temp_s7 = D_8011FECC + 0x610;
    if (D_8015375C != 0) {
        var_s4 = D_800E28C8;
    } else {
        var_s4 = arg1->slot->unk4;
    }
    if (func_80406178_de(arg1, var_s4, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_8014D4DC != 0) {
        temp_v0 = func_8040458C_de(var_s4, temp_s5, &sp48, sp38, sp20, &sp4C, sp28, sp30);
        if ((temp_v0 == 0) && (sp48 == 0)) {
            arg1->state = 0x14;
            func_80405F48_de(arg1);
            return 0;
        }
        var_v1 = valid_note(sp28,sp30);
        if (var_v1 != 0) {
            var_s3 = func_802A037C_de(sp38, rw_pak_profile_name()) == 0;
            var_s0 = func_802A037C_de(sp38, rw_pak_block_name()) == 0;
        } else {
            var_s3 = 0;
            var_s0 = 0;
        }
        if ((temp_v0 == 0) && (sp48 != 0)) {
            if (var_s3 != 0) {
if (func_80404F58_de(var_s4,temp_s5,&D_80153738,0x18)==0 && func_804057F8_de(&D_80153738,0x14,4)==D_80153738.checksum) {
                    *rw_pak_loaded_profile() =D_80153738;
                    D_8014D4FC=temp_s5;
                    func_80442574_de(&D_8014561C,rw_pak_selected_profile_dialog(),arg1->player,arg1->slot,arg1->dialogData);
                    return 1;
}
var_s3=0;var_s2=1;
}
block_24:
            if ((var_s0 != 0) && (var_s2 == 0)) {
                var_s0 = sp4C;
                if (D_800DE864_de != 0) {
                    func_80253908_de(0);
                    func_80253838_de(0, D_800DE864_de);
                }
                if (var_s0 != 0) var_s0 <<= 8;
                else {
                    var_s0 = D_8011FECC + 0x610;
                }
                temp_v0_2 = func_8025343C_de(0, var_s0, 0x33U, D_800DCD60);
                temp_a0 = temp_v0_2->data;
                D_800DE864_de = temp_v0_2;
                D_800E28BC = temp_a0;
                func_802A001C_de(temp_a0, 0, (u32) var_s0);
                if (func_80404F58_de(var_s4,temp_s5,D_800E28BC,sp4C << 8)==0 &&
                    (temp_v0=*(s32 *)D_800E28BC)==temp_s7 &&
                    func_804057F8_de(D_800E28BC,temp_v0-4,11)==*(s32 *)(*(s32 *)D_800E28BC+D_800E28BC-4) &&
                    D_8011FECC==((s32 *)D_800E28BC)[1]) {
                    D_8014D4FC=temp_s5;
                    func_80442574_de(&D_8014561C,rw_pak_selected_block_dialog(),arg1->player,arg1->slot,arg1->dialogData);
                    return 1;
                }
                var_s0=0;
                var_s2=1;
            }
block_40:
            if (var_s3 == 0) {
                if (var_s0 == 0) {
                    current = 0;
                    var_s1 = rw_pak_note_text();
                    D_8014D4FC = temp_s5;
                    if (func_804057BC_de(sp38, 0x10) != 0) {
                        func_802A025C_de(sp38, rw_pak_invalid_name());
                    }
                    var_a1_2 = 1;
                    var_v1_2 = 0;
                    do {
                        if (var_a1_2 != 0) {
                            current = (sp38)[var_v1_2];
                        }
                        if (current == 0) {
                            var_a1_2 = 0;
                            current = 0x20;
                        }
                        *var_s1 = current;
                        var_v1_2 += 1;
                        var_s1 += 1;
                    } while (var_v1_2 < 0x10);
                    var_a1_2 = 1;
                    var_s1 += 1;
                    var_v1_2 = 0;
                    do {
                        if (var_a1_2 != 0) {
                            current = (sp20)[var_v1_2];
                        }
                        if (current == 0) {
                            var_a1_2 = 0;
                            current = 0x20;
                        }
                        *var_s1 = current;
                        var_v1_2 += 1;
                        var_s1 += 1;
                    } while (var_v1_2 < 4);
                    func_80442574_de(&D_8014561C, rw_pak_other_note_dialog(), arg1->player, arg1->slot, arg1->dialogData);
                        return 1;
                }
            }
            goto block_89;
        }
        goto block_89;

    }
    if (D_80153760 != 0) {
        if ((D_8014D4EC_de != 0) && (var_s2 == 0)) {
            if ((func_8040458C_de(var_s4, temp_s5, &sp48, sp38, sp20, &sp4C, sp28, sp30) == 0) && (sp48 != 0) && (func_802A037C_de(sp38, rw_pak_profile_name()) == 0)) {
                if (func_80404F58_de(var_s4,temp_s5,&D_80153738,0x18)==0 &&
                    func_804057F8_de(&D_80153738,0x14,4)==D_80153738.checksum) {
                    *rw_pak_loaded_profile() =D_80153738;
                    func_80442574_de(&D_8014561C,rw_pak_loaded_profile_dialog(),arg1->player,arg1->slot,0);
                    return 1;
                }
                var_s2=1;
            }
            goto block_89;
        }
        if ((D_80153760 != 0) && (D_8014D4EC_de == 0)) {
            if (var_s2 != 0) goto block_91;
            {
                if ((func_8040458C_de(var_s4, temp_s5, &sp48, sp38, sp20, &sp4C, sp28, sp30) == 0) && (sp48 != 0) && (func_802A037C_de(sp38, rw_pak_block_name()) == 0)) {
                    var_s0_4 = sp4C;
                    if (D_800DE864_de != 0) {
                        func_80253908_de(0);
                        func_80253838_de(0, D_800DE864_de);
                    }
                    if (var_s0_4 != 0) var_s0_4 <<= 8;
                    else {
                        var_s0_4 = D_8011FECC + 0x610;
                    }
                    temp_v0_3 = func_8025343C_de(0, var_s0_4, 0x33U, D_800DCD60);
                    temp_a0_2 = temp_v0_3->data;
                    D_800DE864_de = temp_v0_3;
                    D_800E28BC = temp_a0_2;
                    func_802A001C_de(temp_a0_2, 0, (u32) var_s0_4);
                    if (func_80404F58_de(var_s4, temp_s5, D_800E28BC, sp4C << 8) == 0) {
                        temp_a1_2 = *(s32 *)D_800E28BC;
                        if ((temp_a1_2 == temp_s7) && (func_804057F8_de(D_800E28BC, temp_a1_2 - 4, 0xBU) == *(s32 *)(D_800E28BC + *(s32 *)D_800E28BC - 4)) && (D_8011FECC == ((s32 *)D_800E28BC)[1])) {
                            func_80442574_de(&D_8014561C, rw_pak_loaded_block_dialog(), arg1->player, arg1->slot, 0);
                        return 1;
                        }
                    }
                    var_s2 = 1;
                    if ((D_800DE860_de != 0) || (D_800DE864_de != 0)) {
                        func_80253908_de(0);
                    }
                    if (D_800DE860_de != 0) {
                        func_80253838_de(0, D_800DE860_de);
                    }
                    if (D_800DE864_de != 0) {
                        func_80253838_de(0, D_800DE864_de);
                    }
                    D_800DE860_de = 0;
                    D_800DE864_de = 0;
                    D_800DE868 = 0;
                    D_800E28BC = 0;
                    goto block_89;
                }
                goto block_89;
            }
            goto block_91;
        }
        goto block_89;
    }
block_89:
    var_v0 = 0;
    if (var_s2 != 0) {
block_91:
        if (D_8014D4EC_de != 0) messageExtra = D_0044E468;
        else messageExtra = D_0044E4B0;
        var_a1 = rw_pak_load_error_dialog();
        D_8014D4C4 = temp_s5;
block_94:
        func_80442574_de(&D_8014561C, var_a1, arg1->player, arg1->slot, messageExtra);
        var_v0 = 1;
    }
    return var_v0;
}
