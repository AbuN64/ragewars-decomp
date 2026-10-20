.set noreorder
.set noat
.section .text
.globl Rnc_ReadHuffmanValue
Rnc_ReadHuffmanValue:
.Lfunc_802AD69C_de_000:
    lhu $t0, 0x0($s0)
    addi $s0, $s0, 0x2
    and $t0, $t0, $t6
    lhu $at, 0x0($s0)
    addi $s0, $s0, 0x2
    sub $t0, $t0, $at
    bnez $t0, .Lfunc_802AD69C_de_000
    nop
    lbu $t1, 0x3C($s0)
    nop
    sub $t7, $t7, $t1
    bgez $t7, .Lfunc_802AD69C_de_044
    nop
    addu $t9, $ra, $zero
    jal Rnc_RefillBitBuffer
    nop
    addu $ra, $t9, $zero
.Lfunc_802AD69C_de_044:
    srlv $t6, $t6, $t1
    lbu $t0, 0x3D($s0)
    nop
    addi $at, $t0, -0x2
    bltz $at, .Lfunc_802AD69C_de_09C
    nop
    addi $t0, $t0, -0x1
    addu $t1, $t0, $zero
    addu $t2, $t0, $zero
    lhu $t0, 0x3E($s0)
    sub $t7, $t7, $t1
    and $t0, $t0, $t6
    bgez $t7, .Lfunc_802AD69C_de_08C
    nop
    addu $t9, $ra, $zero
    jal Rnc_RefillBitBuffer
    nop
    addu $ra, $t9, $zero
.Lfunc_802AD69C_de_08C:
    srlv $t6, $t6, $t1
    addi $at, $zero, 0x1
    sllv $at, $at, $t2
    or $t0, $at, $t0
.Lfunc_802AD69C_de_09C:
    jr $ra
    nop
