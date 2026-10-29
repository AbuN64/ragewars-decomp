.set noreorder
.set noat
.section .text
.globl osWritebackDCache
osWritebackDCache:
    blez $a1, .LosWritebackDCache_03C
    addiu $t3, $zero, 0x2000
    sltu $at, $a1, $t3
    beqz $at, .LosWritebackDCache_044
    addu $t0, $a0, $zero
    addu $t1, $a0, $a1
    sltu $at, $t0, $t1
    beqz $at, .LosWritebackDCache_03C
    addiu $t1, $t1, -0x10
    andi $t2, $t0, 0xF
    subu $t0, $t0, $t2
.LosWritebackDCache_02C:
    cache 0x19, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LosWritebackDCache_02C
    addiu $t0, $t0, 0x10
.LosWritebackDCache_03C:
    jr $ra
    nop
.LosWritebackDCache_044:
    lui $t0, 0x8000
    addu $t1, $t0, $t3
    addiu $t1, $t1, -0x10
.LosWritebackDCache_050:
    cache 0x01, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LosWritebackDCache_050
    addiu $t0, $t0, 0x10
    jr $ra
    nop
