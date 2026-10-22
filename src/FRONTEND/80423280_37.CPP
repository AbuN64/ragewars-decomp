#include "include_asm.h"
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

#if defined(VERSION_US) || defined(VERSION_US_REV1) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
#if defined(VERSION_EU)
#define func_804264F0_us_rev1 func_80426E50_eu
#endif
#if defined(VERSION_EU_X)
#define func_804264F0_us_rev1 func_80426FA0_eu_x
#endif
#ifdef NON_MATCHING
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




s32 func_804264F0_us_rev1(MenuWidget *arg0) {
    MenuWidget *temp_a2;
    MenuWidget *temp_a2_2;
    MenuWidget *temp_v0_2;
    MenuWidget *temp_v0_3;
    MenuWidget *temp_v0_4;
    MenuWidget *temp_v0_5;
    ResultsOptionsScreen *temp_v0;
    u8 *var_a0;
    u8 *var_v1_3;
    s16 var_v1;
    s16 var_v1_2;
    s32 temp_a1;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    u8 temp_v1_3;

    temp_v0 = func_8025305C_de(0xA80);
    (*(ResultsOptionsScreen **)&D_800E4690) = temp_v0;
    temp_v0->root = arg0;
    var_s0 = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((void * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2420))) = func_8041B610_de(arg0, 4);
    func_8041B6E8_de(arg0, 0, 0x13E);
    func_8041B6E8_de(arg0, 1, 0x13E);
    func_8041B6E8_de(arg0, 2, 0x13E);
    func_8041B6E8_de(arg0, 3, 0x13E);
    var_a1 = 0;
    do {
        func_80265688_de((*(ResultsOptionsScreen **)&D_800E4690)->owned, var_a1, 0);
        temp_a1 = var_s0;
        var_s0 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        func_80265688_de(&(*((u8 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2681))), temp_a1, 0);
        var_a1 = var_s0;
    } while (var_s0 < 0x24);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2440))) = 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2444))) = 4;
    temp_v0_2 = func_8040EC30_de(arg0, 0x145);
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
    temp_v0_3 = func_8040EC30_de(arg0, 0x144);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432))) = temp_v0_3;
    temp_v0_3->x = (u16) temp_v0_3->x + (u16) temp_v0_3->width;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    var_v1_2 = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432)))->width;
    if (var_v1_2 < 0) {
        var_v1_2 += 3;
    }
    var_s0_2 = 0;
    temp_v1_2 = var_v1_2 >> 2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2436))) = temp_v1_2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_a2_2 = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432)));
    temp_a2_2->x = (u16) temp_a2_2->x - (temp_a2_2->width - (temp_v1_2 * 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((void * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2448))) = func_80419E54_de(0x141, 0x6E);
    temp_v0_4 = func_8040EC30_de(arg0, 0x13F);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2452))) = temp_v0_4;
    func_8040E8D8_de(temp_v0_4, 0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2456))) = func_8040EC30_de(arg0, 0x154);
    var_a0 = D_80146398;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2460))) = func_8040EC30_de(arg0, 0x155);
    (*(ResultsOptionsScreen **)&D_800E4690)->player = 0;
loop_7:
    if (var_a0[0x78] != 1) {
        var_s0_2 += 1;
        var_a0 += 0x96;
        if (var_s0_2 < 4) {
            goto loop_7;
        }
    } else {
        (*(ResultsOptionsScreen **)&D_800E4690)->player = var_s0_2;
    }
    var_s0_3 = 0;
    var_v1_3 = D_80146398;
    do {
        var_s0_3 += 1;
        if (var_v1_3[0x91] == 1) {
            var_v1_3[0x78] = 0;
            var_v1_3[0x91] = 0;
        }
        var_v1_3 += 0x96;
    } while (var_s0_3 < 8);
    func_80427008_de();
    func_80427F10_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2632))) = func_8040EC30_de(arg0, (s32) *(D_800E0646_de + ((*(ResultsOptionsScreen **)&D_800E4690)->selection * 0x1C)));
    func_804280BC_de();
    D_80154024 = 0;
    D_80154020.value = -1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    func_8043C210_de(&(*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 0))), 0x67, 0, 0, 0);
    temp_v0_5 = func_8040EC30_de(arg0, 0x151);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2640))) = temp_v0_5;
    temp_v0_5->alpha = 0xFF;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2636))) = 0;
    if (((s32) D_801462D5 < 5) && ((s32) D_801462D5 >= 3)) {
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
    temp_v1_3 = D_801462D5;
    switch (temp_v1_3) {                            /* switch 1; irregular */
    default:                                        /* switch 1 */
    case 1:                                         /* switch 1 */
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2656))) = func_8040EC30_de(arg0, 0x13D);
        func_80422170_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2660))) = func_8040EC30_de(arg0, 0x147);
        func_8040EC30_de(arg0, 0x148)->alpha = 0x6E;
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
    if (D_801462D5 != 2) {
        func_80427B08_de();
    }
    func_8025DF34_de(0xE78);
    return 0;
}
#undef D_800E4690
#undef D_80146398
#else
INCLUDE_ASM("ovl_80400000", func_804264F0_us_rev1);
#endif
#endif

/* Places the models of the first two active players on the screen D_800E4690: calls
   func_802A23C4_de(1) and func_802A2394_de, clears the word at 0xA58, and for each player whose 150-byte
   status record in D_80146398 has byte 0x78 equal to one maps its kind byte at 0x80 to a 0x70-byte
   row of D_800E3A58 through func_8041F140_de and shows object 0x38F plus the kind through
   func_8041CAD8_de in the next 0x4A8-byte view from 0x20 of the screen, using layout 0 of the row
   (uniform scale, position, float and word) for the first model and layout 2 for the second.
   Returns zero. */









extern struct Screen_func_80426788_de *D_800E4690;
extern struct Status D_80146398[];

extern void func_802A2394_de();

s32 func_80426788_de(void) {
    s32 shown;
    s32 layout;
    s32 view;
    s32 row;
    s32 i;
    CVector3 scale;
    struct Status *status;
    s32 offset;

    func_802A23C4_de(1);
    func_802A2394_de();
    shown = 0;
    layout = 0;
    i = 0;
    offset = 0;
    view = 0x20;
    D_800E4690->wordA58 = 0;
next:
    status = (struct Status *)((char *)D_80146398 + offset);
    if (status->active == 1) {
        shown++;
        row = func_8041F140_de(status->kind);
        scale.x = D_800E3A58[row].scale[layout];
        scale.y = D_800E3A58[row].scale[layout];
        scale.z = D_800E3A58[row].scale[layout];
        func_8041CAD8_de((char *)D_800E4690 + view, 9, status->kind + 0x38F, 0x4B, 0x5DC0, scale,
                      D_800E3A58[row].position[layout], D_800E3A58[row].distance[layout],
                      D_800E3A58[row].light[layout]);
        view += 0x4A8;
        layout = 2;
        if (shown >= layout) {
            goto done;
        }
    }
    i++;
    offset += 150;
    if (i < 4) {
        goto next;
    }
done:
    return 0;
}
