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
