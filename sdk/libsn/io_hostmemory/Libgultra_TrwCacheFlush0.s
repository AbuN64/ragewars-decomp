.set noreorder
.set noat
.section .text
.globl Libgultra_TrwCacheFlush0
Libgultra_TrwCacheFlush0:
    lui $t0, %hi(g_debugDataCacheLastIndex)
    addiu $t1, $t0, %lo(g_debugDataCacheLastIndex)
.LLibgultra_TrwCacheFlush0_008:
    cache 0x01, 0x0($t0)
    bne $t0, $t1, .LLibgultra_TrwCacheFlush0_008
    addiu $t0, $t0, 0x10
    jr $ra
    nop
