.set noreorder
.set noat
.section .text
.globl func_802023DC_de
func_802023DC_de:
    addi $sp, $sp, -0x10
    sw $a0, 0x0($sp)
    sw $a1, 0x4($sp)
    sw $a2, 0x8($sp)
    sw $a3, 0xC($sp)
    mfc0 $v0, $10
    addi $a0, $zero, 0x1F
    lui $a1, %hi(D_800F3660)
    addiu $a1, $a1, %lo(D_800F3660)
.Lfunc_802023DC_de_024:
    mtc0 $a0, $0
    addi $a0, $a0, -0x1
    tlbr
    nop
    nop
    nop
    nop
    mfc0 $a2, $5
    mfc0 $a3, $10
    sw $a2, 0x0($a1)
    sw $a3, 0x4($a1)
    mfc0 $a2, $2
    mfc0 $a3, $3
    sw $a2, 0x8($a1)
    sw $a3, 0xC($a1)
    bgez $a0, .Lfunc_802023DC_de_024
    addi $a1, $a1, -0x10
    mtc0 $v0, $10
    sw $a0, 0x0($sp)
    sw $a1, 0x4($sp)
    sw $a2, 0x8($sp)
    sw $a3, 0xC($sp)
    jr $ra
    addi $sp, $sp, 0x10
