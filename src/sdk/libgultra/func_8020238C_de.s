.set noreorder
.set noat
.section .text
.globl func_8020238C_de
func_8020238C_de:
    lui $t0, %hi(D_80001FF0)
    addiu $t1, $t0, %lo(D_80001FF0)
.Lfunc_8020238C_de_008:
    cache 0x01, 0x0($t0)
    bne $t0, $t1, .Lfunc_8020238C_de_008
    addiu $t0, $t0, 0x10
    jr $ra
    nop
