.set noreorder
.set noat
.section .text
.globl Rnc_DecodeMethod1
Rnc_DecodeMethod1:
    addi $v1, $zero, -0x1
    andi $v1, $v1, 0xFF
    sll $a0, $v1, 24
    sll $a1, $v1, 31
    srl $a3, $a1, 16
    nor $a2, $zero, $v1
    add $s5, $s1, $s3
    add $s6, $s0, $s2
    addu $s3, $s0, $zero
    addu $s4, $s1, $zero
    addi $sp, $sp, -0x180
    addu $s2, $sp, $zero
    lbu $t6, 0x1($s3)
    lbu $at, 0x0($s3)
    addu $t7, $zero, $zero
    sll $t6, $t6, 8
    or $t6, $t6, $at
    addi $t0, $zero, 0x2
    addu $t8, $ra, $zero
    jal Rnc_ReadBits
    addi $t1, $zero, 0x2
    addu $ra, $t8, $zero
.Lfunc_802AD530_de_058:
    addi $sp, $sp, -0x8
    sw $ra, 0x0($sp)
    jal Rnc_BuildHuffmanTable
    addu $s0, $s2, $zero
    jal Rnc_BuildHuffmanTable
    addi $s0, $s2, 0x80
    jal Rnc_BuildHuffmanTable
    addi $s0, $s2, 0x100
    addi $t0, $zero, -0x1
    jal Rnc_ReadBits
    addi $t1, $zero, 0x10
    lw $ra, 0x0($sp)
    addi $sp, $sp, 0x8
    addu $t4, $t0, $zero
    addi $at, $zero, -0x1
    srl $at, $at, 16
    addi $t4, $t4, -0x1
    j .Lfunc_802AD530_de_0F4
    and $t4, $at, $t4
.Lfunc_802AD530_de_0A4:
    addi $s0, $s2, 0x80
    addu $t8, $ra, $zero
    jal Rnc_ReadHuffmanValue
    addu $t0, $zero, $zero
    negu $t0, $t0
    add $s1, $s4, $t0
    addi $s1, $s1, -0x1
    jal Rnc_ReadHuffmanValue
    addi $s0, $s2, 0x100
    addu $ra, $t8, $zero
    addi $s4, $s4, 0x1
    lbu $at, 0x0($s1)
    addi $s1, $s1, 0x1
    sb $at, -0x1($s4)
.Lfunc_802AD530_de_0DC:
    addi $s4, $s4, 0x1
    lbu $at, 0x0($s1)
    addi $s1, $s1, 0x1
    sb $at, -0x1($s4)
    bnez $t0, .Lfunc_802AD530_de_0DC
    addi $t0, $t0, -0x1
.Lfunc_802AD530_de_0F4:
    addu $t8, $ra, $zero
    jal Rnc_ReadHuffmanValue
    addu $s0, $s2, $zero
    addu $ra, $t8, $zero
    addi $t0, $t0, -0x1
    bltz $t0, .Lfunc_802AD530_de_150
    nop
.Lfunc_802AD530_de_110:
    lbu $at, 0x0($s3)
    addi $s3, $s3, 0x1
    sb $at, 0x0($s4)
    addi $s4, $s4, 0x1
    bnez $t0, .Lfunc_802AD530_de_110
    addi $t0, $t0, -0x1
    lbu $at, 0x1($s3)
    lbu $t0, 0x0($s3)
    sll $at, $at, 8
    or $t0, $at, $t0
    sllv $t0, $t0, $t7
    addi $t1, $zero, 0x1
    sllv $t1, $t1, $t7
    addiu $t1, $t1, -0x1
    and $t6, $t6, $t1
    or $t6, $t0, $t6
.Lfunc_802AD530_de_150:
    bnez $t4, .Lfunc_802AD530_de_0A4
    addi $t4, $t4, -0x1
    sub $at, $s3, $s6
    bltz $at, .Lfunc_802AD530_de_058
    nop
    jr $ra
    addi $sp, $sp, 0x180
