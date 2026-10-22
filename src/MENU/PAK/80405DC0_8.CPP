#include "include_asm.h"
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RECORDRECAT1C.H"
#include "COMMON/MENURECAT24.H"
#include "TYPES.H"
#include "stddef.h"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
#if defined(VERSION_EU)
#define func_804069F4_de func_80406A90_eu
#endif
#if defined(VERSION_EU_X)
#define func_804069F4_de func_80406A90_eu_x
#endif
/* Selects a usable Controller Pak, checks its notes and free space, and opens the appropriate prompt. */
s32 func_8026464C_de(void);
void func_80293268_de(s32);
void func_80404E28_de(s32);
s32 func_80404F04_de(s32);
s32 func_804050CC_de(s32, s32 *);
int func_80405160_de(int, int *);
s32 func_80405338_de(s32, s32, char **);
s32 func_80405598_de(s32);
void func_80405648_de(u8 *, u8 *, s32);
u32 func_804057EC_de(u32);
s32 func_80406858_de(void *, s32, s32 *, s32 *);
void * func_80442574_de(void *, void *, s32, s32, s32);
s32 func_802A037C_de(); /* extern */
extern s32 D_0044E4F8;
#if defined(VERSION_DE)
extern s32 D_0044EA74;
extern s32 D_0044EABC;
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)


#elif defined(VERSION_US)
extern s32 D_0044EBE4;
extern s32 D_0044EC2C;
#endif
extern s32 D_0044ED44;
#if defined(VERSION_DE)
extern s32 D_0044EEAC;
extern s32 D_0044EED0;
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)


#elif defined(VERSION_US)
extern s32 D_0044F01C;
extern s32 D_0044F040;
#endif
extern s32 D_8011FECC;
#include "COMMON/GAME_SESSION.H"
extern s32 D_8014561C;
extern s32 D_8015375C;
void func_804069F4_de(Shared_PakMenu *arg0) {
    u8 sp18[16];
    s32 sp28;
    s32 sp2C;
    s8 *sp30;
    s8 *sp34;
    s32 sp38;
    s32 sp3C;
    s32 *var_a1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4; /* FAKEMATCH: reuse the dead second note cursor for the Pak error status. */
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2; /* FAKEMATCH: reuse the completed retry count for the second note name. */
    s32 regpart_var_s2; /* FAKEMATCH: split the second note flag from the dead retry counter. */
    s32 var_s3;
    s32 var_s3_2;
    /* FAKEMATCH: keep the absent-channel sentinel live across the retry scan. */
    s32 var_s5;
    s32 var_s6;
    u32 temp_a0_3;
    u32 temp_s1_3;
    D_8014D4C0_de = 0;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 0;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 1;
    if (func_8026464C_de() == 0) {
        D_80153784 = 1;
        D_8014AD9C = 0;
#if defined(VERSION_DE)
        func_80442574_de(&D_8014561C, &D_0044EABC, (s32)arg0->player, (s32) arg0->slot, 0);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
        func_80442574_de(&D_8014561C, &D_0044F70C, (s32)arg0->player, (s32) arg0->slot, 0);
#elif defined(VERSION_US)
        func_80442574_de(&D_8014561C, &D_0044EC2C, (s32)arg0->player, (s32) arg0->slot, 0);
#endif
        D_800E28CC = 1;
        D_8014AD94 = 0;
        return;
    }
    var_s0 = 0;
    if (D_800E28C8 == -1) {
        var_s1 = 0;
        do {
        func_80404E28_de(var_s0);
        if (func_80404F04_de(var_s0) == -2) {
            var_s0 += 1;
            if (var_s0 >= 4) {
                var_s0 = 0;
            }
            var_s1 += 1;
        } else {
            break;
        }
        } while (var_s1 < 4);
        if (var_s1 == 4) {
            var_s0 = -1;
        }
        D_800E28C8 = var_s0;
        if (var_s0 != -1) {
            goto block_11;
        }
        goto block_35;
    }
block_11:
    if (func_80405598_de(D_800E28C8) == 0) {
        func_80293268_de((s32) &D_8011FAC0);
        if ((arg0->slot->unkB0 & 0x1000) && (D_800E28CC == 0)) {
            D_80146D60 = 1;
            D_800E28CC = 1;
        }
        var_s0 = 1;
        D_800E28CC = var_s0;
        if ((D_80142CAC != 0) || (var_s3 = 0, (D_80146D60 != 0))) {
            func_80404E28_de(D_800E28C8);
            if (func_80404F04_de(D_800E28C8) == -2) {
                D_80153784 = 1;
                D_8014AD9C = 0;
#if defined(VERSION_DE)
                func_80442574_de(&D_8014561C, &D_0044EA74, (s32)arg0->player, (s32) arg0->slot, 0);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
                func_80442574_de(&D_8014561C, &D_0044F6C4, (s32)arg0->player, (s32) arg0->slot, 0);
#elif defined(VERSION_US)
                func_80442574_de(&D_8014561C, &D_0044EBE4, (s32)arg0->player, (s32) arg0->slot, 0);
#endif
                D_8014AD94 = 0;
                D_800E28CC = 1;
                return;
            }
            goto block_60;
        }
        /* FAKEMATCH: preserve the status-to-counter copy across a compiler loop boundary. */
        do {} while (0);
        /* FAKEMATCH: redundant copies preserve the status-to-counter register move. */
        temp_s1_2 = var_s3;
        var_s3 = temp_s1_2;
        var_s2 = var_s3;
        sp2C = -1;
        var_s5 = -1;
        sp28 = D_800E28C8;
        var_s6 = -2;
loop_20:
        if ((D_800E28C8 == var_s5) || (var_s3 = func_80406858_de(arg0, D_800E28C8, &sp28, &sp2C), var_s0_2 = 0, (var_s3 == 0))) {
            var_s0_3 = 0;
            if (D_800E28C8 != var_s5) {
                var_s0_3 = D_800E28C8 + 1;
                if (var_s0_3 >= 4) {
                    var_s0_3 = 0;
                }
            }
            var_s1_2 = 0;
loop_26:
            func_80404E28_de(var_s0_3);
            if (func_80404F04_de(var_s0_3) == var_s6) {
                var_s0_3 += 1;
                if (var_s0_3 >= 4) {
                    var_s0_3 = 0;
                }
                var_s1_2 += 1;
                if (var_s1_2 < 4) {
                    goto loop_26;
                }
            }
            if (var_s1_2 == 4) {
                var_s0_3 = -1;
            }
            D_800E28C8 = var_s0_3;
            var_s2 += 1;
            if (var_s2 >= 4) {
                var_s0_2 = 0;
                if (var_s3 == 0) {
                    D_800E28C8 = sp28;
                    func_80404E28_de(sp28);
                    if (func_80404F04_de(D_800E28C8) == -2) {
block_35:
block_36:
                        D_80153784 = 1;
                        D_8014AD9C = 0;
#if defined(VERSION_DE)
                        func_80442574_de(&D_8014561C, &D_0044EA74, (s32)arg0->player, (s32) arg0->slot, 0);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
                        func_80442574_de(&D_8014561C, &D_0044F6C4, (s32)arg0->player, (s32) arg0->slot, 0);
#elif defined(VERSION_US)
                        func_80442574_de(&D_8014561C, &D_0044EBE4, (s32)arg0->player, (s32) arg0->slot, 0);
#endif
                        D_8014AD94 = 0;
                        D_800E28CC = 1;
                        return;
                    }
                }
                goto block_39;
            }
            goto loop_20;
        }
        goto block_39;
/* FAKEMATCH: place found-note exits before the loops to preserve branch layout. */
first_note_found:
        var_s3_2 = 1;
        goto second_note_search;
second_note_found:
        regpart_var_s2 = 1;
        goto notes_checked;
block_39:
        temp_s2 = D_800D36D4;
        temp_s1 = D_800E28C8;
        temp_a0 = temp_s1;
loop_40:
        func_80405338_de(temp_a0, var_s0_2, &sp30);
        func_80405648_de((u8 *) sp30, sp18, 0x10);
        if (func_802A037C_de(sp18, temp_s2) == 0) {
            goto first_note_found;
        }
        var_s0_2 += 1;
        if (var_s0_2 < 0x10) {
            goto loop_40;
        }
        var_s3_2 = 0;
second_note_search:
        var_s0_4 = 0;
        var_s2 = D_800D36D8;
        temp_s1_2 = D_800E28C8;
        temp_a0_2 = temp_s1_2;
loop_44:
        func_80405338_de(temp_a0_2, var_s0_4, &sp34);
        func_80405648_de((u8 *) sp34, sp18, 0x10);
        if (func_802A037C_de(sp18, var_s2) == 0) {
            goto second_note_found;
        }
        var_s0_4 += 1;
        if (var_s0_4 < 0x10) {
            goto loop_44;
        }
        regpart_var_s2 = 0;
notes_checked:
        if ((var_s3_2 == 0) && (regpart_var_s2 == 0)) {
            if ((func_80405160_de(D_800E28C8, &sp38) == 0) && (var_s0_4 = func_804050CC_de(D_800E28C8, &sp3C), (var_s0_4 == 0))) {
                temp_s1_3 = func_804057EC_de(D_8011FECC + 0x610);
                temp_a0_3 = func_804057EC_de(0x18U);
                if ((sp3C != 0) && (sp38 >= (s32) temp_a0_3)) {
                    if (sp38 < (s32) temp_s1_3) {
                        D_80153784 = 1;
                        D_80146D60 = 1;
#if defined(VERSION_DE)
                        func_80442574_de(&D_8014561C, &D_0044EED0, (s32)arg0->player, (s32) arg0->slot, (s32) &D_0044E4F8);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
                        func_80442574_de(&D_8014561C, &D_0044FB20, (s32)arg0->player, (s32) arg0->slot, (s32) &D_0044E4F8);
#elif defined(VERSION_US)
                        func_80442574_de(&D_8014561C, &D_0044F040, (s32)arg0->player, (s32) arg0->slot, (s32) &D_0044E4F8);
#endif
                        goto prompt_checked;
                    }
                    /* FAKEMATCH: retain the repeated minimum-size test and its target branch. */
                    if (sp38 < (s32) temp_a0_3) {
                        goto block_56;
                    }
                } else {
block_56:
                    D_80153784 = 1;
                    D_80146D60 = 1;
#if defined(VERSION_DE)
                    func_80442574_de(&D_8014561C, &D_0044EEAC, (s32)arg0->player, (s32) arg0->slot, (s32) &D_0044E4F8);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
                    func_80442574_de(&D_8014561C, &D_0044FAFC, (s32)arg0->player, (s32) arg0->slot, (s32) &D_0044E4F8);
#elif defined(VERSION_US)
                    func_80442574_de(&D_8014561C, &D_0044F01C, (s32)arg0->player, (s32) arg0->slot, (s32) &D_0044E4F8);
#endif
                }
prompt_checked:
                if (var_s0_4 != 0) {
                    goto block_59;
                }
            } else {
                goto block_59;
            }
        }
        goto block_60;
    }
block_59:
    D_80153784 = 1;
    D_80146D60 = 1;
    func_80442574_de(&D_8014561C, &D_0044ED44, (s32)arg0->player, (s32) arg0->slot, (s32) &D_0044E4F8);
block_60:
    if (D_80153784 == 0) {
        func_80405F48_de(arg0);
    }
    D_8014AD94 = 0;
    D_800E28CC = 1;
}
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct SaveOwner { u8 pad0[0x554]; u32 list; } SaveOwner;
typedef struct SavePlayer { u8 pad0[0x5dc]; SaveOwner *owner; u8 pad5e0[0xb8]; s32 value; } SavePlayer;
typedef struct SaveInfo { u8 pad0[4]; s8 id; } SaveInfo;
typedef struct SaveRequest { u8 pad0[0x1c]; SavePlayer *player; SaveInfo *info; } SaveRequest;
typedef struct SaveBuffer { u8 pad0[0x60c]; u32 checksums[0]; } SaveBuffer;
extern s32 D_8014D4C0_de,D_8014D4DC,D_80153760,D_8014D4EC_de,D_800DE874,D_80153784,D_8015375C,D_800E28C0,D_800DE868;
extern u8 D_0044EA08[];
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern SaveBuffer *D_8011FECC;
extern u32 D_8014561C;
extern s32 D_0044ED44;
#endif
extern void func_80404E28_de(s32);
extern s32 func_80404F04_de(s32),func_80404F3C_de(s32),func_80405598_de(s32);
extern void func_80405DC0_de(SavePlayer *);
extern u32 func_804057F8_de(s32,void *,s32);
void func_80406F7C_de(SaveRequest *request) {
    s32 id;
    SavePlayer *player;
    u32 sum;
    D_8014D4C0_de = 1;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 0;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 0;
    id = request->info->id;
    player = request->player;
    if (D_800E28C0 != 0) { D_80153784 = 1; return; }
    func_80404E28_de(request->info->id);
    if (func_80404F04_de(id) == 0) {
        func_80405DC0_de(player);
        sum = func_804057F8_de(D_800DE868,(*(SaveBuffer * *)&D_8011FECC)->checksums,11);
        (*(SaveBuffer * *)&D_8011FECC)->checksums[D_800DE868 / 4] = sum;
        func_80405F48_de(request);
    } else {
        D_80153784 = 1;
        if (func_80404F3C_de(id) != 0) {
            func_80442574_de(&player->owner->list,D_0044EA08,player,player->value,1);
        } else {
            if (func_80405598_de(id) == 0) return;
            func_80442574_de(&(*(u32 *)&D_8014561C),&D_0044ED44,player,player->value,(u32)D_0044E4D4);
        }
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_80406F7C_de);
#endif
