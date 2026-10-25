#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SHARED_MENUREPLY.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#define Frontend_CreateResultsOptionsScreen func_80426FA0_eu_x
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/80423280_38.H"
#include "FRONTEND/80423280_39.H"
#include "FRONTEND/80423280_42.H"
#include "FRONTEND/CODE_80426EC4.H"
#include "FRONTEND/8041BEA8_6.H"
#define D_800E4690 fz_D_800E4690
#define D_80146398 fz_D_80146398
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/S1_5.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
extern struct Screen_func_80426788_de *D_800E4690;
extern struct Status D_80146398[];
extern MenuWidget *func_8040EC30_de(void *, s32);
void func_80265688_de(u8 *arg0, s32 arg1, s32 arg2);
void func_80427F10_de(void);
void func_8043C210_de(s32 *record, s32 first, s32 second, s32 third, s32 fourth);




s32 Frontend_CreateResultsOptionsScreen(MenuWidget *owner) {
    MenuWidget *temp_a2;
    MenuWidget *temp_a2_2;
    MenuWidget *temp_v0_2;
    MenuWidget *temp_v0_3;
    MenuWidget *temp_v0_4;
    MenuWidget *temp_v0_5;
    ResultsOptionsScreen *screen;
    u8 *var_a0;
    u8 *var_v1_3;
    s16 var_v1;
    s16 var_v1_2;
    s32 temp_a1;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s32 i;
    s32 j;
    s32 k;
    u8 temp_v1_3;

    screen = Scene_AllocateMemory(0xA80);
    (*(ResultsOptionsScreen **)&D_800E4690) = screen;
    screen->root = owner;
    i = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((void * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2420))) = func_8041B610_de(owner, 4);
    func_8041B6E8_de(owner, 0, 0x13E);
    func_8041B6E8_de(owner, 1, 0x13E);
    func_8041B6E8_de(owner, 2, 0x13E);
    func_8041B6E8_de(owner, 3, 0x13E);
    var_a1 = 0;
    do {
        func_80265688_de((*(ResultsOptionsScreen **)&D_800E4690)->owned, var_a1, 0);
        temp_a1 = i;
        i += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        func_80265688_de(&(*((u8 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2681))), temp_a1, 0);
        var_a1 = i;
    } while (i < 0x24);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2440))) = 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2444))) = 4;
    temp_v0_2 = func_8040EC30_de(owner, 0x145);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2424))) = temp_v0_2;
    temp_v0_2->x = (u16) temp_v0_2->x - (u16) temp_v0_2->width;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    var_v1 = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2424)))->width;
    if (var_v1 < 0) {
        var_v1 += 3;
    }
    temp_v1 = var_v1 >> 2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2428))) = temp_v1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_a2 = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2424)));
    temp_a2->x = (u16) temp_a2->x + (temp_a2->width - (temp_v1 * 4));
    temp_v0_3 = func_8040EC30_de(owner, 0x144);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432))) = temp_v0_3;
    temp_v0_3->x = (u16) temp_v0_3->x + (u16) temp_v0_3->width;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    var_v1_2 = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432)))->width;
    if (var_v1_2 < 0) {
        var_v1_2 += 3;
    }
    j = 0;
    temp_v1_2 = var_v1_2 >> 2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2436))) = temp_v1_2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_a2_2 = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432)));
    temp_a2_2->x = (u16) temp_a2_2->x - (temp_a2_2->width - (temp_v1_2 * 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((void * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2448))) = func_80419E54_de(0x141, 0x6E);
    temp_v0_4 = func_8040EC30_de(owner, 0x13F);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2452))) = temp_v0_4;
    func_8040E8D8_de(temp_v0_4, 0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2456))) = func_8040EC30_de(owner, 0x154);
    var_a0 = D_80146398;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2460))) = func_8040EC30_de(owner, 0x155);
    (*(ResultsOptionsScreen **)&D_800E4690)->player = 0;
loop_7:
    if (var_a0[0x78] != 1) {
        j += 1;
        var_a0 += 0x96;
        if (j < 4) {
            goto loop_7;
        }
    } else {
        (*(ResultsOptionsScreen **)&D_800E4690)->player = j;
    }
    k = 0;
    var_v1_3 = D_80146398;
    do {
        k += 1;
        if (var_v1_3[0x91] == 1) {
            var_v1_3[0x78] = 0;
            var_v1_3[0x91] = 0;
        }
        var_v1_3 += 0x96;
    } while (k < 8);
    func_80427008_de();
    func_80427F10_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2632))) = func_8040EC30_de(owner, (s32) *(D_800E0646_de + ((*(ResultsOptionsScreen **)&D_800E4690)->selection * 0x1C)));
    func_804280BC_de();
    D_80154020.ready = 0;
    D_80154020.value = -1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    func_8043C210_de(&(*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 0))), 0x67, 0, 0, 0);
    temp_v0_5 = func_8040EC30_de(owner, 0x151);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2640))) = temp_v0_5;
    temp_v0_5->alpha = 0xFF;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2636))) = 0;
    if (((s32) D_801462C8.controllerMode < 5) && ((s32) D_801462C8.controllerMode >= 3)) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2636))) = 1;
        func_804279B8_de((*(ResultsOptionsScreen **)&D_800E4690));
    }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2664))) = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2668))) = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2672))) = -1;
    temp_v1_3 = D_801462C8.controllerMode;
    switch (temp_v1_3) {                            /* switch 1; irregular */
    default:                                        /* switch 1 */
    case 1:                                         /* switch 1 */
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2656))) = func_8040EC30_de(owner, 0x13D);
        func_80422170_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2660))) = func_8040EC30_de(owner, 0x147);
        func_8040EC30_de(owner, 0x148)->alpha = 0x6E;
        /* fallthrough */
    case 2:                                         /* switch 1 */
        break;
    }
    switch (temp_v1_3) {                            /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        func_80428300_de();
        break;
    case 3:                                         /* switch 2 */
        func_8042840C_de();
        break;
    case 2:                                         /* switch 2 */
        func_80428214_de();
        break;
    }
    if (D_801462C8.controllerMode != 2) {
        func_80427B08_de();
    }
    func_8025DF34_de(0xE78);
    return 0;
}
#undef D_800E4690
#undef D_80146398
#else
INCLUDE_ASM("ovl_80400000", func_80426FA0_eu_x);
#endif
#endif
