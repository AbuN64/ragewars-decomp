.set noreorder
.set noat
.section .text
.globl func_802BCF30_de
func_802BCF30_de:
    mfc0 $t0, $12
    addiu $at, $zero, -0x2
    and $t1, $t0, $at
    mtc0 $t1, $12
    andi $v0, $t0, 0x1
    nop
    jr $ra
    nop
