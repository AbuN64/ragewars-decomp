

/* Rnc_ReadBits.s */
.set noreorder
.set noat
.section .text
.globl Rnc_ReadBits
Rnc_ReadBits:
    and $t0, $t6, $t0
    sub $t7, $t7, $t1
    bgez $t7, .LRnc_ReadBits_020
    nop
    addu $t9, $ra, $zero
    jal Rnc_RefillBitBuffer
    nop
    addu $ra, $t9, $zero
.LRnc_ReadBits_020:
    jr $ra
    srlv $t6, $t6, $t1

/* Rnc_RefillBitBuffer.s */
.set noreorder
.set noat
.section .text
.globl Rnc_RefillBitBuffer
Rnc_RefillBitBuffer:
    add $t7, $t7, $t1
    srlv $t6, $t6, $t7
    addi $s3, $s3, 0x4
    lbu $at, -0x2($s3)
    lbu $v0, -0x1($s3)
    addi $s3, $s3, -0x2
    sll $at, $at, 16
    sll $v0, $v0, 24
    or $t6, $t6, $v0
    or $t6, $t6, $at
    sub $t1, $t1, $t7
    addi $t7, $zero, 0x10
    jr $ra
    sub $t7, $t7, $t1
