#include "COMMON/RESIDENTSTATE.H"
#include "RENDER/802944E8_10.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "TEXTURE/80294C64_11.H"

#if defined(VERSION_US_REV1)
/** Return the texture override pointer of the menu state. */


/* Handles one held press of the menu "next page" key: D_auto_800D2AF8 counts the held presses, and on the
 * fourth one the selection index D_8014AEB0.selectionIndex is stepped up by five modulo the menu item count; the
 * pre-modulo index store is retained as the original emitted it, and the change flag word at +8 from
 * the index is set. Ported verbatim from the legacy branch source (byte-exact in that build). */


void TextLoad_SelectNextArtsendPage(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    s32 *p;
    s32 old;

    old = D_auto_800D2AF8++;
    if (old >= 3) {
        p = &D_8014AEB0.selectionIndex;
        temp_a0 = p[0] + 5;
        temp_v0 = p[-1];
        var_v1 = temp_a0 % temp_v0;
        D_auto_800D2AF8 = 0;
        p[2] = 1;
        *(volatile s32 *)&p[0] = temp_a0;
        p[0] = var_v1;
    }
}

int TextLoad_GetArtsendTextureOverride(void) {
    return (int)D_8014AEB0.textureOverride;
}

int TextLoad_GetArtsendPaletteOverride(void) {
    return (int)D_8014AEB0.paletteOverride;
}

/** Compute a bit mask from the byte at offset 2 of the global record. */
int TextLoad_GetArtsendPrimaryButtonMask(void) {
    return 1 << D_8014AEB0.selector->primaryButton;
}

int TextLoad_GetArtsendSecondaryButtonMask(void) {
    unsigned char shift = D_8014AEB0.selector->secondaryButton;
    return 1 << shift;
}

/** Return the mode mask selected by the global record's leading byte. */
int TextLoad_GetArtsendModeMask(void) {
    {
        int sw_mode_value = D_8014AEB0.selector->mode;
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
#endif
