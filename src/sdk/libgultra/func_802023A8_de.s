.set noreorder
.set noat
.section .text
.globl func_802023A8_de
func_802023A8_de:
    lui $t0, %hi(D_80003FE0)
    addiu $t1, $t0, %lo(D_80003FE0)
.Lfunc_802023A8_de_008:
    cache 0x00, 0x0($t0)
    bne $t0, $t1, .Lfunc_802023A8_de_008
    addiu $t0, $t0, 0x20
    jr $ra
    nop
