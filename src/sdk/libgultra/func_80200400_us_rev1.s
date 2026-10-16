.set noreorder
.set noat
.section .text
.globl func_80200400_us_rev1
func_80200400_us_rev1:
    lui $sp, 0x803F
    ori $sp, $sp, 0xFFC0
    addiu $a0, $zero, 0x1E
.Lfunc_80200400_us_rev1_00C:
    mfc0 $t0, $10
    mtc0 $a0, $0
    lui $t1, 0x8000
    mtc0 $t1, $10
    mtc0 $zero, $2
    mtc0 $zero, $3
    nop
    tlbwi
    nop
    nop
    nop
    nop
    mtc0 $t0, $10
    nop
    bnez $a0, .Lfunc_80200400_us_rev1_00C
    addi $a0, $a0, -0x1
    addiu $a0, $zero, 0x1F
    lui $a1, 0x1F
    ori $a1, $a1, 0xE000
    lui $a2, 0x20
    addiu $a3, $zero, 0x0
    lui $t1, 0x10
    sw $t1, 0x10($sp)
    addiu $t0, $zero, 0x7
    jal func_auto_80000488
    sw $t0, 0x14($sp)
    lui $a0, %hi(D_auto_002A81B0)
    addiu $a0, $a0, %lo(D_auto_002A81B0)
    jalr $a0
    nop
    break 1, 2
    lw $t8, 0x10($sp)
    addi $t0, $zero, 0x7
    lw $t9, 0x14($sp)
    addi $t7, $zero, -0x1
    and $t9, $t9, $t0
    ori $t9, $t9, 0x18
    mfc0 $t0, $10
    mtc0 $a0, $0
    mtc0 $a1, $5
    mtc0 $a2, $10
    beq $a3, $t7, .Lfunc_80200400_us_rev1_0C8
    addi $t6, $zero, 0x1
    srl $t5, $a3, 6
    or $t5, $t5, $t9
    b .Lfunc_80200400_us_rev1_0CC
    mtc0 $t5, $2
.Lfunc_80200400_us_rev1_0C8:
    mtc0 $t6, $2
.Lfunc_80200400_us_rev1_0CC:
    beq $t8, $t7, .Lfunc_80200400_us_rev1_0E0
    mtc0 $t6, $3
    srl $t5, $t8, 6
    or $t5, $t5, $t9
    mtc0 $t5, $3
.Lfunc_80200400_us_rev1_0E0:
    tlbwi
    nop
    nop
    nop
    nop
    mtc0 $t0, $10
    jr $ra
    nop
