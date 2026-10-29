.set noreorder
.set noat
.section .text
.globl osInvalDCache
osInvalDCache:
    blez $a1, .LosInvalDCache_return
    nop
    addiu $t3, $zero, 0x2000
    sltu $at, $a1, $t3
    beqz $at, .LosInvalDCache_wholeCache
    addu $t0, $a0, $zero
    addu $t1, $a0, $a1
    sltu $at, $t0, $t1
    beqz $at, .LosInvalDCache_return
    addiu $t1, $t1, -0x10
    andi $t2, $t0, 0xF
    beqz $t2, .LosInvalDCache_alignTail
    subu $t0, $t0, $t2
    cache 0x15, 0x0($t0)
    sltu $at, $t0, $t1
    beqz $at, .LosInvalDCache_return
    addiu $t0, $t0, 0x10
.LosInvalDCache_alignTail:
    andi $t2, $t1, 0xF
    beqz $t2, .LosInvalDCache_lineLoop
    subu $t1, $t1, $t2
    cache 0x15, 0x10($t1)
    sltu $at, $t1, $t0
    bnez $at, .LosInvalDCache_return
.LosInvalDCache_lineLoop:
    cache 0x11, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LosInvalDCache_lineLoop
    addiu $t0, $t0, 0x10
.LosInvalDCache_return:
    jr $ra
    nop
.LosInvalDCache_wholeCache:
    lui $t0, 0x8000
    addu $t1, $t0, $t3
    addiu $t1, $t1, -0x10
.LosInvalDCache_wholeCacheLoop:
    cache 0x01, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LosInvalDCache_wholeCacheLoop
    addiu $t0, $t0, 0x10
    jr $ra
    nop
