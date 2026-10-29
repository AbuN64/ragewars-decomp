.set noreorder
.set noat
.section .text
.globl osInvalDCache
osInvalDCache:
    blez $a1, .Lfunc_802BCF70_de_06C
    nop
    addiu $t3, $zero, 0x2000
    sltu $at, $a1, $t3
    beqz $at, .Lfunc_802BCF70_de_074
    addu $t0, $a0, $zero
    addu $t1, $a0, $a1
    sltu $at, $t0, $t1
    beqz $at, .Lfunc_802BCF70_de_06C
    addiu $t1, $t1, -0x10
    andi $t2, $t0, 0xF
    beqz $t2, .Lfunc_802BCF70_de_044
    subu $t0, $t0, $t2
    cache 0x15, 0x0($t0)
    sltu $at, $t0, $t1
    beqz $at, .Lfunc_802BCF70_de_06C
    addiu $t0, $t0, 0x10
.Lfunc_802BCF70_de_044:
    andi $t2, $t1, 0xF
    beqz $t2, .Lfunc_802BCF70_de_05C
    subu $t1, $t1, $t2
    cache 0x15, 0x10($t1)
    sltu $at, $t1, $t0
    bnez $at, .Lfunc_802BCF70_de_06C
.Lfunc_802BCF70_de_05C:
    cache 0x11, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .Lfunc_802BCF70_de_05C
    addiu $t0, $t0, 0x10
.Lfunc_802BCF70_de_06C:
    jr $ra
    nop
.Lfunc_802BCF70_de_074:
    lui $t0, 0x8000
    addu $t1, $t0, $t3
    addiu $t1, $t1, -0x10
.Lfunc_802BCF70_de_080:
    cache 0x01, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .Lfunc_802BCF70_de_080
    addiu $t0, $t0, 0x10
    jr $ra
    nop
