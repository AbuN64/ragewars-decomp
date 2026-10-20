.set noreorder
.set noat
.section .text
.globl Libgultra_TrwCacheFlush0
Libgultra_TrwCacheFlush0:
    lui $t0, %hi(D_80001FF0)
    addiu $t1, $t0, %lo(D_80001FF0)
.Lfunc_8020238C_de_008:
    cache 0x01, 0x0($t0)
    bne $t0, $t1, .Lfunc_8020238C_de_008
    addiu $t0, $t0, 0x10
    jr $ra
    nop
