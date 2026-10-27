

/* Rnc_BuildHuffmanTable.s */
.set noreorder
.set noat
.section .text
.globl Rnc_BuildHuffmanTable
Rnc_BuildHuffmanTable:
    addi $t0, $zero, 0x1F
    addu $t8, $ra, $zero
    jal Rnc_ReadBits
    addi $t1, $zero, 0x5
    addu $ra, $t8, $zero
    addi $t0, $t0, -0x1
    bltz $t0, .LRnc_BuildHuffmanTable_14C
    nop
    addu $t2, $t0, $zero
    addu $t3, $t0, $zero
    addi $sp, $sp, -0x10
    addu $s1, $sp, $zero
.LRnc_BuildHuffmanTable_030:
    addi $t0, $zero, 0xF
    addu $t8, $ra, $zero
    jal Rnc_ReadBits
    addi $t1, $zero, 0x4
    addu $ra, $t8, $zero
    sb $t0, 0x0($s1)
    addi $s1, $s1, 0x1
    bnez $t2, .LRnc_BuildHuffmanTable_030
    addi $t2, $t2, -0x1
    addu $t0, $a1, $zero
    addi $t1, $zero, 0x1
    addu $t2, $zero, $zero
    addi $sp, $sp, -0x10
    sw $t5, 0x0($sp)
    sw $t6, 0x4($sp)
    sw $t7, 0x8($sp)
.LRnc_BuildHuffmanTable_070:
    addu $t4, $t3, $zero
    addi $s1, $sp, 0x10
.LRnc_BuildHuffmanTable_078:
    lbu $at, 0x0($s1)
    addi $s1, $s1, 0x1
    bne $t1, $at, .LRnc_BuildHuffmanTable_11C
    nop
    addi $t5, $zero, 0x1
    sllv $t5, $t5, $t1
    addi $t5, $t5, -0x1
    sh $t5, 0x0($s0)
    addi $s0, $s0, 0x2
    addu $t5, $t2, $zero
    sll $at, $t5, 16
    srl $t5, $t5, 16
    or $t5, $t5, $at
    addu $t7, $t1, $zero
    addi $t7, $t7, -0x1
.LRnc_BuildHuffmanTable_0B4:
    addi $at, $zero, -0x1
    srl $at, $at, 16
    and $t6, $at, $t6
    and $at, $t5, $a3
    sll $t5, $t5, 1
    srl $t6, $t6, 1
    beqz $at, .LRnc_BuildHuffmanTable_0D8
    nop
    or $t6, $t6, $a3
.LRnc_BuildHuffmanTable_0D8:
    bnez $t7, .LRnc_BuildHuffmanTable_0B4
    addi $t7, $t7, -0x1
    addi $t5, $zero, 0x10
    sub $t5, $t5, $t1
    srlv $t6, $t6, $t5
    sh $t6, 0x0($s0)
    addi $s0, $s0, 0x2
    sb $t1, 0x3C($s0)
    addu $t5, $t3, $zero
    subu $t5, $t5, $t4
    sb $t5, 0x3D($s0)
    addi $t6, $zero, 0x1
    addiu $t5, $t5, -0x1
    sllv $t6, $t6, $t5
    addiu $t6, $t6, -0x1
    sh $t6, 0x3E($s0)
    addu $t2, $t2, $t0
.LRnc_BuildHuffmanTable_11C:
    bnez $t4, .LRnc_BuildHuffmanTable_078
    addi $t4, $t4, -0x1
    srl $t0, $t0, 1
    addi $t1, $t1, 0x1
    addi $at, $zero, 0x11
    bne $t1, $at, .LRnc_BuildHuffmanTable_070
    nop
    lw $t5, 0x0($sp)
    lw $t6, 0x4($sp)
    lw $t7, 0x8($sp)
    addi $sp, $sp, 0x10
    addi $sp, $sp, 0x10
.LRnc_BuildHuffmanTable_14C:
    jr $ra
    nop

/* func_802AD8F4_de.s */
.set noreorder
.set noat
.section .text
.globl func_802AD8F4_de
func_802AD8F4_de:
    sll $a0, $a0, 4
    srl $a0, $a0, 4
    addi $v0, $zero, -0x8
    and $a0, $v0, $a0
    andi $a1, $a1, 0x3
    or $a0, $a1, $a0
    mtc0 $a0, $18
    nop
    nop
    nop
    nop
    mfc0 $zero, $19
    nop
    nop
    nop
    jr $ra
    nop
