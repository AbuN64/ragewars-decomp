#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80294C64.h"
#include "types.h"

extern s32 D_8014AECC;
void func_80295890_us_rev1(void) {
    if (((ResidentState *)&D_8014AECC)->unk0 != 0) {
        func_80253754_de(0, ((ResidentState *)&D_8014AECC)->unk0);
    }
    ((ResidentState *)&D_8014AECC)->unk0 = 0;
    ((ResidentState *)&D_8014AECC)->unk8 = 0;
    ((ResidentState *)&D_8014AECC)->unkC = 0;
    ((ResidentState *)&D_8014AECC)->unk4 = 0;
}

extern char D_8014AEB0;




/** Reset the record's fields, marking slot 1 active. */
void func_802958D8_us_rev1(void) {
    char *object = &D_8014AEB0;

    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->alternateTitle = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->state = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->selectionIndex = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->selectionValue = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->active = 1;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->field4 = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->titleWasShown = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->field1C = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->field24 = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->field28 = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->field20 = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->field212C = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->field2130 = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->field2134 = 0;
    ((struct MenuGlobal_func_80294F1C_us_rev1 *)object)->frameCount = 0;
}

extern s32 D_800D2AEC;
extern ResourceManagerState D_8014AEC0;

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

extern s32 D_800D2AF0;
extern ResourceManagerState D_8014AEC0;

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
