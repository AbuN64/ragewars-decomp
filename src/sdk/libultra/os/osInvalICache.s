.set noreorder
.set noat
.section .text
.globl osInvalICache
osInvalICache:
    blez $a1, .LOsInvalICacheDone
    addiu $t3, $zero, 0x4000
    sltu $at, $a1, $t3
    beqz $at, .LOsInvalICacheWhole
    addu $t0, $a0, $zero
    addu $t1, $a0, $a1
    sltu $at, $t0, $t1
    beqz $at, .LOsInvalICacheDone
    addiu $t1, $t1, -0x20
    andi $t2, $t0, 0x1F
    subu $t0, $t0, $t2
.LOsInvalICacheLineLoop:
    cache 0x10, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LOsInvalICacheLineLoop
    addiu $t0, $t0, 0x20
.LOsInvalICacheDone:
    jr $ra
    nop
.LOsInvalICacheWhole:
    lui $t0, 0x8000
    addu $t1, $t0, $t3
    addiu $t1, $t1, -0x20
.LOsInvalICacheWholeLoop:
    cache 0x00, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LOsInvalICacheWholeLoop
    addiu $t0, $t0, 0x20
    jr $ra
    nop
