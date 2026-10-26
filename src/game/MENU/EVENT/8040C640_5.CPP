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
#include "RENDER_2/8025DE50_5.H"
extern struct CourseOptionsScreen *D_800E39C0;

s32 Frontend_CreateUsJoinOptionsMenu(void *arg0) {
    MenuWidget *item;
    s32 row;

    { void *memory = Cache_AllocateMemory(0x20); D_800E39C0 = memory; }
    D_800E39C0->handle = arg0;
    D_800E39C0->mode = SmpOverlay_CreateOverlayNode((s32) arg0, 4);
    SmpOverlay_ShowSlotById((s32) arg0, 0, 0x389);
    SmpOverlay_ShowSlotById((s32) arg0, 1, 0x389);
    SmpOverlay_ShowSlotById((s32) arg0, 2, 0x389);
    SmpOverlay_ShowSlotById((s32) arg0, 3, 0x389);

    item = Frontend_FindWidgetByResourceId(arg0, 0x38B);
    item->alpha = 0x8C;
    if (func_802999A0_de(0) == 22) {
        Frontend_SetWidgetFlag08(item, 0);
    }

    D_800E39C0->timer = 0;
    D_800E39C0->selection = 0;
    item = Frontend_FindWidgetByResourceId(arg0, 0x38C);
    D_800E39C0->rows[0] = item;
    item = Frontend_FindWidgetByResourceId(arg0, 0x395);
    D_800E39C0->rows[1] = item;
    item = Frontend_FindWidgetByResourceId(arg0, 0x396);
    D_800E39C0->rows[2] = item;
    D_800E39C0->step = Frontend_CountUsedSlots();

    for (row = 0; row < 3; row++) {
        Frontend_UpdateJoinRequestDisplay(row);
        item = Frontend_FindWidgetByResourceId(D_800E39C0->rows[row], 0x392);
        Frontend_SetWidgetFlag08(item, 0);
    }

    Tsmos_ActivateControllerState();

    item = Frontend_FindWidgetByResourceId(D_800E39C0->rows[D_800E39C0->selection], 0x392);
    Frontend_SetWidgetFlag08(item, 1);
    return 0;
}
#endif

#if defined(VERSION_US)
#include "COMMON/ITEMRECAT20V1.H"
extern struct TextEntry D_800E381C[][17];
extern void MarkMenuEventHandled(void);
extern s32 func_802999A0_de(s32);
extern s32 Frontend_FindJoinModelIndex(s32, s32);
extern void XPlus_CopyString(char *, char *);
extern void Frontend_UpdateJoinRequestDisplay(s32);

s32 Frontend_SelectPreviousUsJoinModel(void *sender, void *context, void *argument, s32 event) {
    s32 variant;
    s32 model;
    s32 id;

    if (event != 1) return 0;
    MarkMenuEventHandled();
    if (func_802999A0_de(0) == 0x16) return 0;
    variant = D_80153F80[D_800E39C0->selection].variant;
    model = Frontend_FindJoinModelIndex(variant, D_80153F80[D_800E39C0->selection].id);
    do {
        variant--;
        if (variant < 0) {
            variant = 2;
            model--;
            if (model < 0) model = 16;
        }
        id = D_800E381C[variant][model].id;
    } while (id == -1);
    D_80153F80[D_800E39C0->selection].variant = variant;
    D_80153F80[D_800E39C0->selection].id = id;
    XPlus_CopyString(D_80153F80[D_800E39C0->selection].name,
                    *D_800E381C[variant][id].text);
    D_80153F80[D_800E39C0->selection].variantC = variant;
    Frontend_UpdateJoinRequestDisplay(D_800E39C0->selection);
    SoundElement_PlayFlatSound(0xE81);
    return 0;
}
#endif

#if defined(VERSION_US)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_8041E2F0_us(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "addiu      $sp, $sp, -0x18\n"
        "addiu      $v0, $zero, 0x1\n"
        "sw         $ra, 0x14($sp)\n"
        "bne        $a3, $v0, .Lauto_8041E464\n"
        "sw        $s0, 0x10($sp)\n"
        "jal        MarkMenuEventHandled\n"
        "nop\n"
        "jal        func_802999A0_de\n"
        "addu      $a0, $zero, $zero\n"
        "addiu      $v1, $zero, 0x16\n"
        "beq        $v0, $v1, .Lauto_8041E468\n"
        "addu      $v0, $zero, $zero\n"
        "lui        $v0, %hi(D_800E39C0)\n"
        "lw         $v0, %lo(D_800E39C0)($v0)\n"
        "lw         $v1, 0x14($v0)\n"
        "sll        $v0, $v1, 3\n"
        "subu       $v0, $v0, $v1\n"
        "sll        $v0, $v0, 2\n"
        "lui        $at, %hi(D_8014DCF4)\n"
        "addu       $at, $at, $v0\n"
        "lw         $s0, %lo(D_8014DCF4)($at)\n"
        "lui        $at, %hi(D_80153F80)\n"
        "addu       $at, $at, $v0\n"
        "lw         $a1, %lo(D_80153F80)($at)\n"
        "jal        Frontend_FindJoinModelIndex\n"
        "addu      $a0, $s0, $zero\n"
        "addu       $a2, $v0, $zero\n"
        "addiu      $t0, $zero, -0x1\n"
        "sll        $v0, $s0, 4\n"
        "addu       $v0, $v0, $s0\n"
        "sll        $a0, $v0, 3\n"
        ".Lauto_8041E36C:\n"
        "addiu      $s0, $s0, 0x1\n"
        "slti       $v0, $s0, 0x3\n"
        "bnez       $v0, .Lauto_8041E394\n"
        "addiu     $a0, $a0, 0x88\n"
        "addu       $a0, $zero, $zero\n"
        "addiu      $a2, $a2, 0x1\n"
        "slti       $v0, $a2, 0x11\n"
        "bnez       $v0, .Lauto_8041E394\n"
        "addu      $s0, $a0, $zero\n"
        "addu       $a2, $a0, $zero\n"
        ".Lauto_8041E394:\n"
        "sll        $v0, $a2, 3\n"
        "sll        $v1, $s0, 4\n"
        "addu       $v0, $v0, $a0\n"
        "lui        $at, %hi(D_800E381C)\n"
        "addu       $at, $at, $v0\n"
        "lw         $a1, %lo(D_800E381C)($at)\n"
        "beq        $a1, $t0, .Lauto_8041E36C\n"
        "addu      $a3, $v1, $s0\n"
        "lui        $a0, %hi(D_800E39C0)\n"
        "lw         $a0, %lo(D_800E39C0)($a0)\n"
        "lw         $v1, 0x14($a0)\n"
        "sll        $v0, $v1, 3\n"
        "subu       $v0, $v0, $v1\n"
        "sll        $v0, $v0, 2\n"
        "lui        $at, %hi(D_8014DCF4)\n"
        "addu       $at, $at, $v0\n"
        "sw         $s0, %lo(D_8014DCF4)($at)\n"
        "lw         $v1, 0x14($a0)\n"
        "sll        $v0, $v1, 3\n"
        "subu       $v0, $v0, $v1\n"
        "sll        $v0, $v0, 2\n"
        "lui        $at, %hi(D_80153F80)\n"
        "addu       $at, $at, $v0\n"
        "sw         $a1, %lo(D_80153F80)($at)\n"
        "addu       $v0, $a3, $a1\n"
        "sll        $v0, $v0, 3\n"
        "lw         $v1, 0x14($a0)\n"
        "lui        $at, %hi(D_800DF7D0)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(D_800DF7D0)($at)\n"
        "sll        $a0, $v1, 3\n"
        "subu       $a0, $a0, $v1\n"
        "sll        $a0, $a0, 2\n"
        "lw         $a1, 0x0($v0)\n"
        "lui        $v0, %hi(D_8014DD00)\n"
        "addiu      $v0, $v0, %lo(D_8014DD00)\n"
        "jal        XPlus_CopyString\n"
        "addu      $a0, $a0, $v0\n"
        "lui        $a0, %hi(D_800E39C0)\n"
        "lw         $a0, %lo(D_800E39C0)($a0)\n"
        "lw         $v1, 0x14($a0)\n"
        "sll        $v0, $v1, 3\n"
        "subu       $v0, $v0, $v1\n"
        "sll        $v0, $v0, 2\n"
        "lui        $at, %hi(D_8014DCFC)\n"
        "addu       $at, $at, $v0\n"
        "sw         $s0, %lo(D_8014DCFC)($at)\n"
        "lw         $a0, 0x14($a0)\n"
        "jal        Frontend_UpdateJoinRequestDisplay\n"
        "nop\n"
        "jal        SoundElement_PlayFlatSound\n"
        "addiu     $a0, $zero, 0xE81\n"
        ".Lauto_8041E464:\n"
        "addu       $v0, $zero, $zero\n"
        ".Lauto_8041E468:\n"
        "lw         $ra, 0x14($sp)\n"
        "lw         $s0, 0x10($sp)\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x18\n"
    );
}
#else
INCLUDE_ASM("ovl_80400000", func_8041E2F0_us);
#endif
#endif
