#include "COMMON/SCREEN.H"
#include "include_asm.h"

#if defined(VERSION_US)
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
extern struct CourseOptionsScreen *g_courseOptionsScreen;

s32 Join_CreateUsJoinOptionsMenu(void *root) {
    MenuWidget *item;
    s32 row;

    { void *memory = Cache_AllocateMemory(0x20); g_courseOptionsScreen = memory; }
    g_courseOptionsScreen->handle = root;
    g_courseOptionsScreen->mode = SmpOverlay_CreateOverlayNode((s32) root, 4);
    SmpOverlay_ShowSlotById((s32) root, 0, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 1, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 2, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 3, 0x389);

    item = Node_FindWidgetByResourceId(root, 0x38B);
    item->alpha = 0x8C;
    if (Menu_GetPreviousScreenOwner(0) == 22) {
        Widget_SetWidgetFlag08(item, 0);
    }

    g_courseOptionsScreen->timer = 0;
    g_courseOptionsScreen->selection = 0;
    item = Node_FindWidgetByResourceId(root, 0x38C);
    g_courseOptionsScreen->rows[0] = item;
    item = Node_FindWidgetByResourceId(root, 0x395);
    g_courseOptionsScreen->rows[1] = item;
    item = Node_FindWidgetByResourceId(root, 0x396);
    g_courseOptionsScreen->rows[2] = item;
    g_courseOptionsScreen->step = Join_CountUsedSlots();

    for (row = 0; row < 3; row++) {
        Join_UpdateJoinRequestDisplay(row);
        item = Node_FindWidgetByResourceId(g_courseOptionsScreen->rows[row], 0x392);
        Widget_SetWidgetFlag08(item, 0);
    }

    Tsmos_ActivateControllerState();

    item = Node_FindWidgetByResourceId(g_courseOptionsScreen->rows[g_courseOptionsScreen->selection], 0x392);
    Widget_SetWidgetFlag08(item, 1);
    return 0;
}
#endif

#if defined(VERSION_US)
#include "COMMON/ITEMRECAT20V1.H"
extern struct TextEntry g_rewardItemTiers[][17];
extern void XPlus_CopyString(char *, char *);

s32 Join_SelectPreviousUsJoinModel(void *sender, void *context, void *argument, s32 event) {
    s32 variant;
    s32 model;
    s32 id;

    if (event != 1) return 0;
    MarkMenuEventHandled();
    if (Menu_GetPreviousScreenOwner(0) == 0x16) return 0;
    variant = g_joinRequestEntries[g_courseOptionsScreen->selection].variant;
    model = Join_FindJoinModelIndex(variant, g_joinRequestEntries[g_courseOptionsScreen->selection].id);
    do {
        variant--;
        if (variant < 0) {
            variant = 2;
            model--;
            if (model < 0) model = 16;
        }
        id = g_rewardItemTiers[variant][model].id;
    } while (id == -1);
    g_joinRequestEntries[g_courseOptionsScreen->selection].variant = variant;
    g_joinRequestEntries[g_courseOptionsScreen->selection].id = id;
    XPlus_CopyString(g_joinRequestEntries[g_courseOptionsScreen->selection].name,
                    *g_rewardItemTiers[variant][id].text);
    g_joinRequestEntries[g_courseOptionsScreen->selection].variantC = variant;
    Join_UpdateJoinRequestDisplay(g_courseOptionsScreen->selection);
    SoundElement_PlayFlatSound(0xE81);
    return 0;
}
#endif

#if defined(VERSION_US)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void CJoinCharacter_CycleModelSelection(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "addiu      $sp, $sp, -0x18\n"
        "addiu      $v0, $zero, 0x1\n"
        "sw         $ra, 0x14($sp)\n"
        "bne        $a3, $v0, .LjoinCycleReturnZero\n"
        "sw        $s0, 0x10($sp)\n"
        "jal        MarkMenuEventHandled\n"
        "nop\n"
        "jal        Menu_GetPreviousScreenOwner\n"
        "addu      $a0, $zero, $zero\n"
        "addiu      $v1, $zero, 0x16\n"
        "beq        $v0, $v1, .LjoinCycleEpilogue\n"
        "addu      $v0, $zero, $zero\n"
        "lui        $v0, %hi(g_courseOptionsScreen)\n"
        "lw         $v0, %lo(g_courseOptionsScreen)($v0)\n"
        "lw         $v1, 0x14($v0)\n"
        "sll        $v0, $v1, 3\n"
        "subu       $v0, $v0, $v1\n"
        "sll        $v0, $v0, 2\n"
        "lui        $at, %hi(g_joinRequestEntryVariantBase)\n"
        "addu       $at, $at, $v0\n"
        "lw         $s0, %lo(g_joinRequestEntryVariantBase)($at)\n"
        "lui        $at, %hi(g_joinRequestEntries)\n"
        "addu       $at, $at, $v0\n"
        "lw         $a1, %lo(g_joinRequestEntries)($at)\n"
        "jal        Join_FindJoinModelIndex\n"
        "addu      $a0, $s0, $zero\n"
        "addu       $a2, $v0, $zero\n"
        "addiu      $t0, $zero, -0x1\n"
        "sll        $v0, $s0, 4\n"
        "addu       $v0, $v0, $s0\n"
        "sll        $a0, $v0, 3\n"
        ".LjoinCycleAdvanceVariant:\n"
        "addiu      $s0, $s0, 0x1\n"
        "slti       $v0, $s0, 0x3\n"
        "bnez       $v0, .LjoinCycleLoadCandidate\n"
        "addiu     $a0, $a0, 0x88\n"
        "addu       $a0, $zero, $zero\n"
        "addiu      $a2, $a2, 0x1\n"
        "slti       $v0, $a2, 0x11\n"
        "bnez       $v0, .LjoinCycleLoadCandidate\n"
        "addu      $s0, $a0, $zero\n"
        "addu       $a2, $a0, $zero\n"
        ".LjoinCycleLoadCandidate:\n"
        "sll        $v0, $a2, 3\n"
        "sll        $v1, $s0, 4\n"
        "addu       $v0, $v0, $a0\n"
        "lui        $at, %hi(g_rewardItemTiers)\n"
        "addu       $at, $at, $v0\n"
        "lw         $a1, %lo(g_rewardItemTiers)($at)\n"
        "beq        $a1, $t0, .LjoinCycleAdvanceVariant\n"
        "addu      $a3, $v1, $s0\n"
        "lui        $a0, %hi(g_courseOptionsScreen)\n"
        "lw         $a0, %lo(g_courseOptionsScreen)($a0)\n"
        "lw         $v1, 0x14($a0)\n"
        "sll        $v0, $v1, 3\n"
        "subu       $v0, $v0, $v1\n"
        "sll        $v0, $v0, 2\n"
        "lui        $at, %hi(g_joinRequestEntryVariantBase)\n"
        "addu       $at, $at, $v0\n"
        "sw         $s0, %lo(g_joinRequestEntryVariantBase)($at)\n"
        "lw         $v1, 0x14($a0)\n"
        "sll        $v0, $v1, 3\n"
        "subu       $v0, $v0, $v1\n"
        "sll        $v0, $v0, 2\n"
        "lui        $at, %hi(g_joinRequestEntries)\n"
        "addu       $at, $at, $v0\n"
        "sw         $a1, %lo(g_joinRequestEntries)($at)\n"
        "addu       $v0, $a3, $a1\n"
        "sll        $v0, $v0, 3\n"
        "lw         $v1, 0x14($a0)\n"
        "lui        $at, %hi(g_joinPlayerNamesDefault)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(g_joinPlayerNamesDefault)($at)\n"
        "sll        $a0, $v1, 3\n"
        "subu       $a0, $a0, $v1\n"
        "sll        $a0, $a0, 2\n"
        "lw         $a1, 0x0($v0)\n"
        "lui        $v0, %hi(g_joinRequestEntryNameBase)\n"
        "addiu      $v0, $v0, %lo(g_joinRequestEntryNameBase)\n"
        "jal        XPlus_CopyString\n"
        "addu      $a0, $a0, $v0\n"
        "lui        $a0, %hi(g_courseOptionsScreen)\n"
        "lw         $a0, %lo(g_courseOptionsScreen)($a0)\n"
        "lw         $v1, 0x14($a0)\n"
        "sll        $v0, $v1, 3\n"
        "subu       $v0, $v0, $v1\n"
        "sll        $v0, $v0, 2\n"
        "lui        $at, %hi(g_joinRequestEntryVariantCopyBase)\n"
        "addu       $at, $at, $v0\n"
        "sw         $s0, %lo(g_joinRequestEntryVariantCopyBase)($at)\n"
        "lw         $a0, 0x14($a0)\n"
        "jal        Join_UpdateJoinRequestDisplay\n"
        "nop\n"
        "jal        SoundElement_PlayFlatSound\n"
        "addiu     $a0, $zero, 0xE81\n"
        ".LjoinCycleReturnZero:\n"
        "addu       $v0, $zero, $zero\n"
        ".LjoinCycleEpilogue:\n"
        "lw         $ra, 0x14($sp)\n"
        "lw         $s0, 0x10($sp)\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x18\n"
    );
}
#else
INCLUDE_ASM("ovl_frontendMenu", CJoinCharacter_CycleModelSelection);
#endif
#endif
