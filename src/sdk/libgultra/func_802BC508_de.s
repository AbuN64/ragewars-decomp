.set noreorder
.set noat
.section .text
.globl __osEnqueueThread
__osEnqueueThread:
    addu $t9, $a0, $zero
    lw $t8, 0x0($a0)
    lw $t7, 0x4($a1)
    lw $t6, 0x4($t8)
    nop
    slt $at, $t6, $t7
    bnez $at, .Lfunc_802BC508_de_03C
    nop
.Lfunc_802BC508_de_020:
    addu $t9, $t8, $zero
    lw $t8, 0x0($t8)
    nop
    lw $t6, 0x4($t8)
    nop
    slt $at, $t6, $t7
    beqz $at, .Lfunc_802BC508_de_020
.Lfunc_802BC508_de_03C:
    lw $t8, 0x0($t9)
    sw $a1, 0x0($t9)
    sw $t8, 0x0($a1)
    jr $ra
    sw $a0, 0x8($a1)
