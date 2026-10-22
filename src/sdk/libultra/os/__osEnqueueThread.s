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
    bnez $at, .L__osEnqueueThread_03C
    nop
.L__osEnqueueThread_020:
    addu $t9, $t8, $zero
    lw $t8, 0x0($t8)
    nop
    lw $t6, 0x4($t8)
    nop
    slt $at, $t6, $t7
    beqz $at, .L__osEnqueueThread_020
.L__osEnqueueThread_03C:
    lw $t8, 0x0($t9)
    sw $a1, 0x0($t9)
    sw $t8, 0x0($a1)
    jr $ra
    sw $a0, 0x8($a1)
