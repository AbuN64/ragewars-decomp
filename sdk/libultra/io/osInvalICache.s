.set noreorder
.set noat
.section .text
.globl osInvalICache
osInvalICache:
    blez $a1, .LosInvalICache_03C
    addiu $t3, $zero, 0x4000
    sltu $at, $a1, $t3
    beqz $at, .LosInvalICache_044
    addu $t0, $a0, $zero
    addu $t1, $a0, $a1
    sltu $at, $t0, $t1
    beqz $at, .LosInvalICache_03C
    addiu $t1, $t1, -0x20
    andi $t2, $t0, 0x1F
    subu $t0, $t0, $t2
.LosInvalICache_02C:
    cache 0x10, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LosInvalICache_02C
    addiu $t0, $t0, 0x20
.LosInvalICache_03C:
    jr $ra
    nop
.LosInvalICache_044:
    lui $t0, 0x8000
    addu $t1, $t0, $t3
    addiu $t1, $t1, -0x20
.LosInvalICache_050:
    cache 0x00, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LosInvalICache_050
    addiu $t0, $t0, 0x20
    jr $ra
    nop
