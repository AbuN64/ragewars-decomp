.set noreorder
.set noat
.section .text
.globl Util_WriteProcessorCompare
Util_WriteProcessorCompare:
    mtc0 $a0, $11
    jr $ra
    nop
