

/* Rnc_DecodeMethod1.s */
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
.LRnc_DecodeMethod1_058:
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
    j .LRnc_DecodeMethod1_0F4
    and $t4, $at, $t4
.LRnc_DecodeMethod1_0A4:
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
.LRnc_DecodeMethod1_0DC:
    addi $s4, $s4, 0x1
    lbu $at, 0x0($s1)
    addi $s1, $s1, 0x1
    sb $at, -0x1($s4)
    bnez $t0, .LRnc_DecodeMethod1_0DC
    addi $t0, $t0, -0x1
.LRnc_DecodeMethod1_0F4:
    addu $t8, $ra, $zero
    jal Rnc_ReadHuffmanValue
    addu $s0, $s2, $zero
    addu $ra, $t8, $zero
    addi $t0, $t0, -0x1
    bltz $t0, .LRnc_DecodeMethod1_150
    nop
.LRnc_DecodeMethod1_110:
    lbu $at, 0x0($s3)
    addi $s3, $s3, 0x1
    sb $at, 0x0($s4)
    addi $s4, $s4, 0x1
    bnez $t0, .LRnc_DecodeMethod1_110
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
.LRnc_DecodeMethod1_150:
    bnez $t4, .LRnc_DecodeMethod1_0A4
    addi $t4, $t4, -0x1
    sub $at, $s3, $s6
    bltz $at, .LRnc_DecodeMethod1_058
    nop
    jr $ra
    addi $sp, $sp, 0x180

/* Rnc_ReadHuffmanValue.s */
.set noreorder
.set noat
.section .text
.globl Rnc_ReadHuffmanValue
Rnc_ReadHuffmanValue:
.LRnc_ReadHuffmanValue_000:
    lhu $t0, 0x0($s0)
    addi $s0, $s0, 0x2
    and $t0, $t0, $t6
    lhu $at, 0x0($s0)
    addi $s0, $s0, 0x2
    sub $t0, $t0, $at
    bnez $t0, .LRnc_ReadHuffmanValue_000
    nop
    lbu $t1, 0x3C($s0)
    nop
    sub $t7, $t7, $t1
    bgez $t7, .LRnc_ReadHuffmanValue_044
    nop
    addu $t9, $ra, $zero
    jal Rnc_RefillBitBuffer
    nop
    addu $ra, $t9, $zero
.LRnc_ReadHuffmanValue_044:
    srlv $t6, $t6, $t1
    lbu $t0, 0x3D($s0)
    nop
    addi $at, $t0, -0x2
    bltz $at, .LRnc_ReadHuffmanValue_09C
    nop
    addi $t0, $t0, -0x1
    addu $t1, $t0, $zero
    addu $t2, $t0, $zero
    lhu $t0, 0x3E($s0)
    sub $t7, $t7, $t1
    and $t0, $t0, $t6
    bgez $t7, .LRnc_ReadHuffmanValue_08C
    nop
    addu $t9, $ra, $zero
    jal Rnc_RefillBitBuffer
    nop
    addu $ra, $t9, $zero
.LRnc_ReadHuffmanValue_08C:
    srlv $t6, $t6, $t1
    addi $at, $zero, 0x1
    sllv $at, $at, $t2
    or $t0, $at, $t0
.LRnc_ReadHuffmanValue_09C:
    jr $ra
    nop
