#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"
#include "COMMON/ALDELAY28.H"
#include "TYPES.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_802B6380_de(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "addiu      $sp, $sp, -0x38\n"
        "sw         $s5, 0x2C($sp)\n"
        "addu       $s5, $a0, $zero\n"
        "sw         $s3, 0x24($sp)\n"
        "addu       $s3, $a1, $zero\n"
        "sw         $s2, 0x20($sp)\n"
        "addu       $s2, $a2, $zero\n"
        "sw         $s4, 0x28($sp)\n"
        "sw         $ra, 0x30($sp)\n"
        "sw         $s1, 0x1C($sp)\n"
        "sw         $s0, 0x18($sp)\n"
        "lw         $s1, 0x0($s5)\n"
        "lw         $s0, 0x48($sp)\n"
        "bnez       $s1, .Lauto_802B63D4\n"
        "addu      $s4, $a3, $zero\n"
        "lui        $a0, %hi(D_800C8DB0_eu_x)\n"
        "addiu      $a0, $a0, %lo(D_800C8DB0_eu_x)\n"
        "lui        $a1, %hi(g_audioSaveText)\n"
        "addiu      $a1, $a1, %lo(g_audioSaveText)\n"
        "jal        Audio_Assert\n"
        "addiu     $a2, $zero, 0x22\n"
        ".Lauto_802B63D4:\n"
        "addu       $a0, $s1, $zero\n"
        "addu       $a1, $s3, $zero\n"
        "addu       $a2, $s2, $zero\n"
        "sw         $s0, 0x10($sp)\n"
        "lw         $v0, 0x4($a0)\n"
        "jalr       $v0\n"
        "addu      $a3, $s4, $zero\n"
        "addu       $s0, $v0, $zero\n"
        "addu       $a0, $s0, $zero\n"
        "addiu      $s0, $s0, 0x8\n"
        "addu       $a1, $s0, $zero\n"
        "addiu      $s0, $s0, 0x8\n"
        "lui        $a3, (0x4400580 >> 16)\n"
        "ori        $a3, $a3, (0x4400580 & 0xFFFF)\n"
        "addu       $a2, $s0, $zero\n"
        "addiu      $s0, $s0, 0x8\n"
        "lui        $v1, (0x8000000 >> 16)\n"
        "sll        $v0, $s2, 1\n"
        "andi       $v0, $v0, 0xFFFF\n"
        "sw         $v0, 0x4($a0)\n"
        "lui        $v0, (0xD000000 >> 16)\n"
        "sw         $v1, 0x0($a0)\n"
        "sw         $v0, 0x0($a1)\n"
        "sll        $v0, $s2, 2\n"
        "andi       $v0, $v0, 0xFFFF\n"
        "sw         $a3, 0x4($a1)\n"
        "sw         $v1, 0x0($a2)\n"
        "addu       $v1, $s0, $zero\n"
        "sw         $v0, 0x4($a2)\n"
        "lui        $v0, (0x6000000 >> 16)\n"
        "sw         $v0, 0x0($v1)\n"
        "lw         $a0, 0x14($s5)\n"
        "sw         $a0, 0x4($v1)\n"
        "lw         $ra, 0x30($sp)\n"
        "lw         $s5, 0x2C($sp)\n"
        "lw         $s4, 0x28($sp)\n"
        "lw         $s3, 0x24($sp)\n"
        "lw         $s2, 0x20($sp)\n"
        "lw         $s1, 0x1C($sp)\n"
        "lw         $s0, 0x18($sp)\n"
        "addiu      $v0, $v1, 0x8\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x38\n"
    );
}
#else
INCLUDE_ASM("span_1000", func_802B6380_de);
#endif
#endif

s32 func_802B6480_de(ALSave *saveFilter, s32 parameterId, ALFilter_s14 *parameterValue)
{
  switch (parameterId)
  {
    case 1:
      saveFilter->filter.source = parameterValue;
      goto ret0;

    case 6:
      saveFilter->dramout = parameterValue;

    default:
      ret0:
    return 0;

      return 0;

  }

}
