.set noreorder
.set noat
.section .text
.globl func_802BD010_de
func_802BD010_de:
    blez $a1, .Lfunc_802BD010_de_03C
    addiu $t3, $zero, 0x4000
    sltu $at, $a1, $t3
    beqz $at, .Lfunc_802BD010_de_044
    addu $t0, $a0, $zero
    addu $t1, $a0, $a1
    sltu $at, $t0, $t1
    beqz $at, .Lfunc_802BD010_de_03C
    addiu $t1, $t1, -0x20
    andi $t2, $t0, 0x1F
    subu $t0, $t0, $t2
.Lfunc_802BD010_de_02C:
    cache 0x10, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .Lfunc_802BD010_de_02C
    addiu $t0, $t0, 0x20
.Lfunc_802BD010_de_03C:
    jr $ra
    nop
.Lfunc_802BD010_de_044:
    lui $t0, 0x8000
    addu $t1, $t0, $t3
    addiu $t1, $t1, -0x20
.Lfunc_802BD010_de_050:
    cache 0x00, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .Lfunc_802BD010_de_050
    addiu $t0, $t0, 0x20
    jr $ra
    nop
