#include "COMMON/RESIDENTSTATE.H"
#include "RENDER/802944E8_10.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "TEXTURE/TEXTLOAD_RESETARTSENDTEXTURESTATE.H"
#include "RESMGR/X_PLUS.H"
#include "ENGINE/TENGINE.H"
#include "TEXTURE/80294C64_10.H"
#include "TEXTURE/TEXTLOAD_CLOSEARTSENDTEXTUREPREVIEW.H"
#include "TEXTURE/TEXTLOAD_ISARTSENDTEXTUREPREVIEWENABLED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTURE_REQUEST.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "SCENE/802508E0_9.H"
#include "TEXTURE/80294C64_11.H"

/* 80294C64_5.CPP */
#if defined(VERSION_US_REV1)

extern ResidentSlot D_8014AEC8;
extern ResidentEntry D_8014AECC;

void TextLoad_ResetArtsendTextureState(void) {
    s32 *base = &D_8014AEB8;

    D_8014AEB0.alternateTitle = 0;
    D_8014AEB1 = 0;
    D_8014AEBC = 0;
    D_8014AEC0 = 0;
    *base = 1;
    D_8014AEB4 = 0;
    D_8014AEC4 = 0;
    *(s32 *)&D_8014AECC = 0;
    D_8014AED4 = 0;
    D_8014AED8 = 0;
    D_8014AED0 = 0;
    D_8014CFDC = 0;
    D_8014CFE0 = 0;
    D_8014CFE4 = 0;
    D_8014D068 = 0;

    XPlus_FillMemory((s32) ((char *) base + 0x24), 0, 0x2000);
    XPlus_FillMemory((s32) ((char *) base + 0x2024), 0xFF, 0x100);

    *base = *D_8011FED8;
}
#endif

/* 80294C64_6.CPP */
#if defined(VERSION_US_REV1)
void TextLoad_CloseArtsendTexturePreview(void) { TextLoad_ReleaseArtsendTextureResource(); }
#endif

/* 80294C64_7.CPP */
#if defined(VERSION_US_REV1)
/** Report the global count only while its enable byte is set. */
int TextLoad_IsArtsendTexturePreviewEnabled(void) {
    int result = 0;
    if (D_8014AEB0.alternateTitle != 0) {
        result = D_800D2AE0 != 0;
    }
    return result;
}
#endif

/* 80294C64_8.CPP */
#if defined(VERSION_US_REV1)


void TextLoad_ApplyArtsendTextureOverride(s32 resource, s32 **texture) {
    s32 enabled;
    s32 choose;

    if ((D_800D2AE0 != 0) && (*texture != 0) && (*(s32 *)&D_8014AEC8 == 0)) {
        enabled = 0;
        if (D_8014AEB0.alternateTitle != 0) {
            enabled = (u32)D_800D2AE0 > 0U;
        }
        if (enabled != 0) {
            choose = (*(s32 *)((char *)&D_8014AEC8 + 0x21A0) % 10) < 3;
        } else {
            choose = 1;
        }
        if (resource == *(s32 *)&D_8014AECC) {
            if (choose != 0) {
                *texture = &((SelectionTextLoadApplyArtsendTextureOverride *)&D_8014AECC)->alternative;
                return;
            }
            *texture = D_8014AEB0.textureOverride;
        }
    }
}
#endif

/* 80294C64_9.CPP */
#if defined(VERSION_US_REV1)

void TextLoad_ApplyArtsendPaletteOverride(s32 resource, s32 **palette) {
    s32 var_v1;
    s32 var_v1_2;

    if ((D_800D2AE0 != 0) && (*palette != 0)) {
        if (*(s32 *)&D_8014AEC8 != 0) {
            return;
        }
        var_v1 = 0;
        if (D_8014AEB0.alternateTitle != 0) {
            var_v1 = (u32)D_800D2AE0 > 0U;
        }
        if (var_v1 != 0) {
            var_v1_2 = (*(s32 *)((char *)&D_8014AEC8 + 0x21A0) % 10) < 3;
        } else {
            var_v1_2 = 1;
        }
        if (resource == *(s32 *)&D_8014AECC) {
            if (var_v1_2 != 0) {
                *palette = &D_8014AECC.unk2010;
                return;
            }
            *palette = D_8014AEB0.paletteOverride;
        }
    }
}

void TextLoad_SelectNextArtsendTexture(void) {
    s32 temp_v1;

    if (D_auto_800D2AE8++ >= 3) {
        temp_v1 = D_8014AEB8.unk4 + 1;
        D_auto_800D2AE8 = 0;
        D_8014AEB8.unkC = 1;
        D_8014AEB8.unk4 = temp_v1;
        D_8014AEB8.unk4 = temp_v1 % D_8014AEB8.unk0;
    }
}
#endif

/* 80294C64_10.CPP */
#if defined(VERSION_US_REV1)

void TextLoad_SelectPreviousArtsendTexture(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    s32 *p;
    s32 old;

    old = D_auto_800D2AE4++;
    if (old >= 3) {
        p = &D_8014AEB0.selectionIndex;
        temp_a0 = p[0] - 1;
        temp_v0 = temp_a0 + p[-1];
        var_v1 = temp_v0 % p[-1];
        p[2] = 1;
        *(volatile s32 *)&p[0] = temp_a0;
        p[0] = var_v1;
        if ((f32) var_v1 < 0.0f) {
            var_v1 = -var_v1;
        }
        p[0] = var_v1;
        D_auto_800D2AE4 = 0;
    }
}

void TextLoad_ReleaseArtsendTextureResource(void) {
    if (D_8014AEB0.resource != 0) {
        Cache_UnlockResource(0, D_8014AEB0.resource);
    }
    D_8014AEB0.resource = 0;
    D_8014AEB0.textureOverride = 0;
    D_8014AEB0.paletteOverride = 0;
    D_8014AEB0.selector = 0;
}

/** Reset the record's fields, marking slot 1 active. */
void TextLoad_InitializeArtsendPreviewState(void) {
    struct MenuGlobalRecAt21B8 *object = &D_8014AEB0;

    object->alternateTitle = 0;
    object->state = 0;
    object->selectionIndex = 0;
    object->selectionValue = 0;
    object->active = 1;
    object->field4 = 0;
    object->titleWasShown = 0;
    object->resource = 0;
    object->textureOverride = 0;
    object->paletteOverride = 0;
    object->selector = 0;
    object->entryTable = 0;
    object->textureTable = 0;
    object->paletteTable = 0;
    object->frameCount = 0;
}

void TextLoad_DecreaseArtsendSelectionValue(void) {
    s32 *ptr;
    s32 old;
    s32 count;

    ptr = &D_800D2AEC;
    old = (*ptr)++;
    if (old >= 3) {
        count = D_8014AEB0.selectionValue;
        D_8014AEB0.titleWasShown = 1;
        D_800D2AEC = 0;
        D_8014AEB0.selectionValue = count - 1;
    }
}

void TextLoad_IncreaseArtsendSelectionValue(void) {
    s32 *ptr;
    s32 old;
    s32 count;

    ptr = &D_800D2AF0;
    old = (*ptr)++;
    if (old >= 3) {
        count = D_8014AEB0.selectionValue;
        D_8014AEB0.titleWasShown = 1;
        D_800D2AF0 = 0;
        D_8014AEB0.selectionValue = count + 1;
    }
}

void TextLoad_SelectPreviousArtsendPage(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    s32 *p;
    s32 old;

    old = D_auto_800D2AF4++;
    if (old >= 3) {
        p = &D_8014AEB0.selectionIndex;
        temp_a0 = p[0] - 5;
        temp_v0 = temp_a0 + p[-1];
        var_v1 = temp_v0 % p[-1];
        *(volatile s32 *)&p[0] = temp_a0;
        p[0] = var_v1;
        if ((f32) var_v1 < 0.0f) {
            var_v1 = -var_v1;
        }
        p[0] = var_v1;
        p[2] = 1;
        D_auto_800D2AF4 = 0;
    }
}
#endif

/* 80294C64_11.CPP */
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
