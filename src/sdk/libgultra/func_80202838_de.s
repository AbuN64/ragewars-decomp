.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl func_80202838_de
func_80202838_de:
    lw $at, 0x33C($k0)
    nop
    bnez $at, .Lfunc_80202838_de_13C
    nop
    addiu $at, $zero, 0x64
.Lfunc_80202838_de_014:
    bnez $at, .Lfunc_80202838_de_014
    addi $at, $at, -0x1
    lui $at, 0xA460
    ori $at, $at, 0x10
.Lfunc_80202838_de_024:
    lw $v0, 0x0($at)
    nop
    andi $v0, $v0, 0x3
    bnez $v0, .Lfunc_80202838_de_024
    nop
    lui $at, %hi(D_B1FFFFF0)
    lw $at, %lo(D_B1FFFFF0)($at)
    nop
    beqz $at, .Lfunc_80202838_de_13C
    nop
    bgez $zero, func_80202460_de+0x1B8
    nop
    addiu $at, $zero, -0x1
    j func_80202460_de+0x1B0
    nop
    addiu $at, $zero, -0x1
    j func_80202460_de+0x1B0
    nop
    j func_80202460_de+0x1AC
    nop
    sd $v1, 0x18($k0)
    sd $a0, 0x20($k0)
    sd $ra, 0xF8($k0)
    bal .Lfunc_80202838_de_098
    nop
    ld $ra, 0xF8($k0)
    ld $a0, 0x20($k0)
    bgez $zero, .Lfunc_80202838_de_13C
    ld $v1, 0x18($k0)
.Lfunc_80202838_de_098:
    lui $v1, 0x8000
    ori $v1, $v1, 0x180
    lui $v0, %hi(D_00202284)
    addiu $v0, $v0, %lo(D_00202284)
    addi $a0, $v0, 0x14
.Lfunc_80202838_de_0AC:
    lw $at, 0x0($v0)
    addi $v0, $v0, 0x4
    sw $at, 0x0($v1)
    addi $v1, $v1, 0x4
    bne $v0, $a0, .Lfunc_80202838_de_0AC
    nop
    lui $v1, %hi(D_80000000)
    lui $v0, %hi(D_002022BC)
    addiu $v0, $v0, %lo(D_002022BC)
    addi $a0, $v0, 0x14
.Lfunc_80202838_de_0D4:
    lw $at, 0x0($v0)
    addi $v0, $v0, 0x4
    sw $at, %lo(D_80000000)($v1)
    addi $v1, $v1, 0x4
    bne $v0, $a0, .Lfunc_80202838_de_0D4
    nop
    jal func_8020238C_de
    nop
    jal func_802023A8_de
    nop
    jr $ra
    nop
    sw $a0, 0x338($k0)
    j .Lfunc_80202838_de_13C
    nop
    mfc0 $at, $14
    nop
    addiu $at, $at, 0x4
    mtc0 $at, $14
    addiu $at, $zero, 0x0
    j func_80202460_de+0x1B0
    nop
    lui $v0, %hi(D_002013D8)
    addiu $v0, $v0, %lo(D_002013D8)
    j .Lfunc_80202838_de_140
    nop
.Lfunc_80202838_de_13C:
    ld $v0, 0x330($k0)
.Lfunc_80202838_de_140:
    mfc0 $at, $14
    nop
    addiu $at, $at, 0x4
    mtc0 $at, $14
    ld $at, 0x328($k0)
    mfc0 $k0, $30
    eret
