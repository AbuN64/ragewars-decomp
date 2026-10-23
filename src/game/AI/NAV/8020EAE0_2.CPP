#include "include_asm.h"
#include "COMMON/OBJECTLINKS1458.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "TYPES.H"
#include "AI/NAV/8020EAE0_7.H"

extern s32 func_8020D1CC_de(void *arg0, s32 arg1, s32 arg2);

extern s32 func_8020BC50_de(void *arg0, s32 arg1, s32 arg2, void *arg3);

/** Reset the float field of each occupied player slot's table entry to the default value. */


extern char *func_8020CFE0_de(NavigationGraph *, int);
extern NavigationGraph D_8013B364;

extern void *func_8020C994_de(void *, s32);

s32 func_8020ED50_de(Func8020ED50Arg *arg0) {
    s32 *base;

    base = &D_8013B364;
    if (base != 0) {
        if (arg0->field10 == -1) {
            return 1;
        }
        if (arg0->field4 == arg0->field10) {
            return 1;
        }
        if (func_8020D1CC_de(base, arg0->field4, arg0->field10) == 0) {
            arg0->fieldC = func_8020BC50_de(base, arg0->field4, arg0->field10, arg0);
        }
    }
    return 1;
}

void func_8020EDCC_de(char *arg0) {
    NavigationGraph *table = &D_8013B364;
    int i;
    float value;

    if (table != 0) {
        value = D_800C1EDC_de;
        for (i = 0; i < 10; i++) {
            Actor1DC *a = ((struct ObjectLinks40 *) (arg0 + (i * 4)))->unk_3C;
            if (a != 0) {
                ((struct ObjRecAt18V3 *) func_8020CFE0_de(table, ((struct func_80203E78_S1 *) ((ObjectLinks1458 *) a->info)->unk_1454)->unk4))->unk18 = value;
            }
        }
    }
}

void func_8020EE50_de(void) {
    NavigationSearchNode *var_a0;
    f32 k;

    var_a0 = D_801372C8;
    if (var_a0 != 0) {
        k = D_800C1EE0_de;
        do {
            var_a0->extra =
                var_a0->extra +
                (f32) (var_a0->ticks * 0x1E) * k;
            var_a0 = var_a0->next;
        } while (var_a0 != 0);
    }
}

void func_8020EEA4_de(void) {
    NavigationGraph *base;
    NavigationSearchNode *node;
    NavigationPoint *result;
    f32 addVal;
    u16 field0E;

    base = &D_8013B364;
    node = base->nodes;
    if (node != 0) {
        addVal = D_800C1EE4_de;
        do {
            result = func_8020C994_de(base, node->key);
            if (navigation_point_flags(result) & 1) {
                field0E = navigation_point_object_id(result);
                if (func_8020F55C_de(field0E) != 0 || func_8020F57C_de(navigation_point_object_id(result)) != 0) {
                    node->extra = node->extra + addVal;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}

#if defined(VERSION_US)
INCLUDE_ASM("span_1000", func_8020EF54_us);
#endif

#if defined(VERSION_US)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_8020EF64_us(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "addiu      $sp, $sp, -0x98\n"
        "sw         $s1, 0x8C($sp)\n"
        "addu       $s1, $a0, $zero\n"
        "sw         $ra, 0x94($sp)\n"
        "sw         $s2, 0x90($sp)\n"
        "sw         $s0, 0x88($sp)\n"
        "lw         $v0, 0x68($s1)\n"
        "bnel       $v0, $zero, .Lauto_8020F138\n"
        "addiu     $v0, $zero, 0x1\n"
        "lui        $s2, %hi(D_8013B364)\n"
        "addiu      $s2, $s2, %lo(D_8013B364)\n"
        "addiu      $v1, $zero, 0x1D\n"
        "addiu      $v0, $sp, 0x84\n"
        ".Lauto_8020EF94:\n"
        "sw         $zero, 0x0($v0)\n"
        "addiu      $v1, $v1, -0x1\n"
        "bgez       $v1, .Lauto_8020EF94\n"
        "addiu     $v0, $v0, -0x4\n"
        "lw         $v1, 0xBC($s1)\n"
        "sltiu      $v0, $v1, 0x8\n"
        "beqz       $v0, .Lauto_8020F098\n"
        "sll       $v0, $v1, 2\n"
        "lui        $at, %hi(jtbl_800C21D0)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(jtbl_800C21D0)($at)\n"
        "jr         $v0\n"
        "nop\n"
        "addiu      $v0, $zero, 0xBC6\n"
        "sw         $v0, 0x10($sp)\n"
        "addiu      $v0, $zero, 0xBC7\n"
        "sw         $v0, 0x14($sp)\n"
        "addiu      $v0, $zero, 0xBC4\n"
        "sw         $v0, 0x18($sp)\n"
        "addiu      $v0, $zero, 0xBC5\n"
        "sw         $v0, 0x1C($sp)\n"
        "addiu      $v0, $zero, 0xBC8\n"
        "sw         $v0, 0x20($sp)\n"
        "addiu      $v0, $zero, 0xBC9\n"
        "sw         $v0, 0x24($sp)\n"
        "addiu      $v0, $zero, 0x6BA\n"
        "sw         $v0, 0x28($sp)\n"
        "addiu      $v0, $zero, 0x6BB\n"
        "j          .Lauto_8020F098\n"
        "sw        $v0, 0x2C($sp)\n"
        "addiu      $v0, $zero, 0x6BA\n"
        "sw         $v0, 0x10($sp)\n"
        "j          .Lauto_8020F094\n"
        "addiu     $v0, $zero, 0x6BB\n"
        "addiu      $v0, $zero, 0x6BA\n"
        "j          .Lauto_8020F098\n"
        "sw        $v0, 0x10($sp)\n"
        "addiu      $v0, $zero, 0x6BB\n"
        "j          .Lauto_8020F098\n"
        "sw        $v0, 0x10($sp)\n"
        "addiu      $v0, $zero, 0xBC6\n"
        "sw         $v0, 0x10($sp)\n"
        "addiu      $v0, $zero, 0xBC7\n"
        "sw         $v0, 0x14($sp)\n"
        "addiu      $v0, $zero, 0xBC4\n"
        "sw         $v0, 0x18($sp)\n"
        "addiu      $v0, $zero, 0xBC5\n"
        "sw         $v0, 0x1C($sp)\n"
        "addiu      $v0, $zero, 0xBC8\n"
        "sw         $v0, 0x20($sp)\n"
        "addiu      $v0, $zero, 0xBC9\n"
        "j          .Lauto_8020F098\n"
        "sw        $v0, 0x24($sp)\n"
        "addiu      $v0, $zero, 0xBC6\n"
        "sw         $v0, 0x10($sp)\n"
        "j          .Lauto_8020F094\n"
        "addiu     $v0, $zero, 0xBC7\n"
        "addiu      $v0, $zero, 0xBC4\n"
        "sw         $v0, 0x10($sp)\n"
        "j          .Lauto_8020F094\n"
        "addiu     $v0, $zero, 0xBC5\n"
        "addiu      $v0, $zero, 0xBC8\n"
        "sw         $v0, 0x10($sp)\n"
        "addiu      $v0, $zero, 0xBC9\n"
        ".Lauto_8020F094:\n"
        "sw         $v0, 0x14($sp)\n"
        ".Lauto_8020F098:\n"
        "lw         $v0, 0x10($sp)\n"
        "beqz       $v0, .Lauto_8020F12C\n"
        "addiu     $v0, $zero, -0x1\n"
        "jal        func_8020D014_de\n"
        "addu      $a0, $s2, $zero\n"
        "jal        func_8020D1FC_de\n"
        "addu      $a0, $s2, $zero\n"
        "jal        func_8020F150_de\n"
        "addiu     $a0, $sp, 0x10\n"
        "bnez       $v0, .Lauto_8020F0D8\n"
        "addiu     $s0, $zero, -0x1\n"
        "addiu      $v0, $zero, 0x1\n"
        "addiu      $v1, $zero, -0x1\n"
        "sw         $zero, 0x68($s1)\n"
        "j          .Lauto_8020F138\n"
        "sw        $v1, 0xBC($s1)\n"
        ".Lauto_8020F0D8:\n"
        "sw         $s0, 0x18($s2)\n"
        "lw         $a1, 0x4($s1)\n"
        "jal        func_8020D0CC_de\n"
        "addu      $a0, $s2, $zero\n"
        "lw         $a1, 0x18($s2)\n"
        "beql       $a1, $s0, .Lauto_8020F124\n"
        "sw        $zero, 0x68($s1)\n"
        "jal        func_8020CFE0_de\n"
        "addu      $a0, $s2, $zero\n"
        "addu       $a0, $s2, $zero\n"
        "lw         $v1, 0x18($s2)\n"
        "addiu      $a1, $s1, 0x14\n"
        "sw         $v1, 0xC($s1)\n"
        "lw         $v0, 0x34($v0)\n"
        "addiu      $a2, $zero, 0x4\n"
        "jal        func_8020D114_de\n"
        "sw        $v0, 0x68($s1)\n"
        "j          .Lauto_8020F138\n"
        "addiu     $v0, $zero, 0x1\n"
        ".Lauto_8020F124:\n"
        "j          .Lauto_8020F134\n"
        "sw        $a1, 0xBC($s1)\n"
        ".Lauto_8020F12C:\n"
        "sw         $zero, 0x68($s1)\n"
        "sw         $v0, 0xBC($s1)\n"
        ".Lauto_8020F134:\n"
        "addiu      $v0, $zero, 0x1\n"
        ".Lauto_8020F138:\n"
        "lw         $ra, 0x94($sp)\n"
        "lw         $s2, 0x90($sp)\n"
        "lw         $s1, 0x8C($sp)\n"
        "lw         $s0, 0x88($sp)\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x98\n"
    );
}
#else
INCLUDE_ASM("span_1000", func_8020EF64_us);
#endif
#endif

#if defined(VERSION_EU_X)
unsigned int func_8020EF74_eu_x_padding_FB74[3] = {
    0x1C400025, 0x00000000, 0x0C09D14D,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8020EF74_eu_padding_FB74[3] = {
    0x0C0829F4, 0x00452821, 0x08082800,
};
#endif
