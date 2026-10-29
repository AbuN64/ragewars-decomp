.set noreorder
.set noat
.section .text
.globl osWritebackDCache
osWritebackDCache:
    blez $a1, .LwritebackDCacheReturn
    addiu $t3, $zero, 0x2000
    sltu $at, $a1, $t3
    beqz $at, .LwritebackDCacheAllEntry
    addu $t0, $a0, $zero
    addu $t1, $a0, $a1
    sltu $at, $t0, $t1
    beqz $at, .LwritebackDCacheReturn
    addiu $t1, $t1, -0x10
    andi $t2, $t0, 0xF
    subu $t0, $t0, $t2
.LwritebackDCacheLineLoop:
    cache 0x19, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LwritebackDCacheLineLoop
    addiu $t0, $t0, 0x10
.LwritebackDCacheReturn:
    jr $ra
    nop
.LwritebackDCacheAllEntry:
    lui $t0, 0x8000
    addu $t1, $t0, $t3
    addiu $t1, $t1, -0x10
.LwritebackDCacheAllLoop:
    cache 0x01, 0x0($t0)
    sltu $at, $t0, $t1
    bnez $at, .LwritebackDCacheAllLoop
    addiu $t0, $t0, 0x10
    jr $ra
    nop
