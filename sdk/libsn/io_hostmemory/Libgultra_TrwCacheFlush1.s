.set noreorder
.set noat
.section .text
.globl Libgultra_TrwCacheFlush1
Libgultra_TrwCacheFlush1:
    lui $t0, %hi(g_debugInstructionCacheLastIndex)
    addiu $t1, $t0, %lo(g_debugInstructionCacheLastIndex)
.LLibgultra_TrwCacheFlush1_008:
    cache 0x00, 0x0($t0)
    bne $t0, $t1, .LLibgultra_TrwCacheFlush1_008
    addiu $t0, $t0, 0x20
    jr $ra
    nop
