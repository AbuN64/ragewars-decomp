#include "SCENE/802508E0_9.H"
#include "COMMON/RESIDENTSTATE.H"
#include "RENDER/802944E8_10.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "TEXTURE/80294C64_10.H"
struct Node80253610;

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
