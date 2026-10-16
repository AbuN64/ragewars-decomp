#include "span_1000/code_80294C64.h"
#include "common/unused.h"
#include "TYPES.H"

/** Return the global word at D_8014AED4. */
extern int D_8014AED4;


/* Handles one held press of the menu "next page" key: D_auto_800D2AF8 counts the held presses, and on the
 * fourth one the selection index D_8014AEBC is stepped up by five modulo the menu item count; the
 * pre-modulo index store is retained as the original emitted it, and the change flag word at +8 from
 * the index is set. Ported verbatim from the legacy branch source (byte-exact in that build). */


void func_80295A60_us_rev1(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    s32 *p;
    s32 old;

    old = D_auto_800D2AF8++;
    if (old >= 3) {
        p = &D_8014AEBC;
        temp_a0 = p[0] + 5;
        temp_v0 = p[-1];
        var_v1 = temp_a0 % temp_v0;
        D_auto_800D2AF8 = 0;
        p[2] = 1;
        *(volatile s32 *)&p[0] = temp_a0;
        p[0] = var_v1;
    }
}

int func_80295AE0_us_rev1(void) {
    return D_8014AED4;
}

int func_80295AF0_us_rev1(void) {
    return D_8014AED8;
}

/** Compute a bit mask from the byte at offset 2 of the global record. */
int func_80295B00_us_rev1(void) {
    extern func_80295B00_S1 *D_8014AED0;
    return 1 << D_8014AED0->unk2;
}

int func_80295B18_us_rev1(void) {
    extern func_80295B18_S1 *D_8014AED0;
    unsigned char shift = D_8014AED0->unk3;
    return 1 << shift;
}

/** Return the mode mask selected by the global record's leading byte. */
int func_80295B30_us_rev1(void) {
    extern void *D_8014AED0;
    {
        int sw_mode_value = *(unsigned char *)D_8014AED0;
        if ((unsigned int)sw_mode_value > 5) {
            goto sw_mode_default;
        }
        switch (sw_mode_value) {
        case 0: goto sw_mode_0;
        case 1: goto sw_mode_1;
        case 2: goto sw_mode_2;
        case 3: goto sw_mode_1;
        case 4: goto sw_mode_4;
        case 5: goto sw_mode_1;
        }
    }
    do {
    sw_mode_0:
        return 8;
    sw_mode_1:
    sw_mode_3:
    sw_mode_5:
        return 4;
    sw_mode_2:
        return 0x20;
    sw_mode_4:
        return 0x10;
    sw_mode_default:
        return 0;
    
    } while (0);
}
