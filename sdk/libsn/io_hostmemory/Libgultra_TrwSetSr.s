.set noreorder
.set noat
.section .text
.globl Libgultra_TrwSetSr
Libgultra_TrwSetSr:
    mtc0 $a0, $12
    jr $ra
    nop
