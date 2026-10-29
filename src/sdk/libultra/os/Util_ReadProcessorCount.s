.set noreorder
.set noat
.section .text
.globl Util_ReadProcessorCount
Util_ReadProcessorCount:
    mfc0 $v0, $9
    jr $ra
    nop
