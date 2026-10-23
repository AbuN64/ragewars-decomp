#include "COMMON/RESIDENTSTATE.H"
#include "TEXTURE/80294C64.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "TEXTURE/80294C64_10.H"
struct Node80253610;
extern void func_80253754_de(void *heap, struct Node80253610 *resource);

#if defined(VERSION_US_REV1)
extern s32 D_8014AECC;

extern char D_8014AEB0;


extern ResourceManagerState D_8014AEC0;


void func_802957EC_us_rev1(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    s32 *p;
    s32 old;

    old = D_auto_800D2AE4++;
    if (old >= 3) {
        p = &D_8014AEBC;
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

void func_80295890_us_rev1(void) {
    if (((ResidentState *)&D_8014AECC)->unk0 != 0) {
        func_80253754_de(0, ((ResidentState *)&D_8014AECC)->unk0);
    }
    ((ResidentState *)&D_8014AECC)->unk0 = 0;
    ((ResidentState *)&D_8014AECC)->unk8 = 0;
    ((ResidentState *)&D_8014AECC)->unkC = 0;
    ((ResidentState *)&D_8014AECC)->unk4 = 0;
}

/** Reset the record's fields, marking slot 1 active. */
void func_802958D8_us_rev1(void) {
    char *object = &D_8014AEB0;

    ((struct MenuGlobalRecAt21B8 *)object)->alternateTitle = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->state = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->selectionIndex = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->selectionValue = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->active = 1;
    ((struct MenuGlobalRecAt21B8 *)object)->field4 = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->titleWasShown = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->field1C = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->field24 = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->field28 = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->field20 = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->field212C = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->field2130 = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->field2134 = 0;
    ((struct MenuGlobalRecAt21B8 *)object)->frameCount = 0;
}

void func_80295924_us_rev1(void) {
    s32 *ptr;
    s32 old;
    s32 count;

    ptr = &D_800D2AEC;
    old = (*ptr)++;
    if (old >= 3) {
        count = D_8014AEC0.active;
        D_8014AEC0.count = 1;
        D_800D2AEC = 0;
        D_8014AEC0.active = count - 1;
    }
}

void func_80295970_us_rev1(void) {
    s32 *ptr;
    s32 old;
    s32 count;

    ptr = &D_800D2AF0;
    old = (*ptr)++;
    if (old >= 3) {
        count = D_8014AEC0.active;
        D_8014AEC0.count = 1;
        D_800D2AF0 = 0;
        D_8014AEC0.active = count + 1;
    }
}

void func_802959BC_us_rev1(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    s32 *p;
    s32 old;

    old = D_auto_800D2AF4++;
    if (old >= 3) {
        p = &D_8014AEBC;
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
