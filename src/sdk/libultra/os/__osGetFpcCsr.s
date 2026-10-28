.set noreorder
.set noat
.section .text
.globl __osGetFpcCsr
__osGetFpcCsr:
    cfc1 $v0, $31
    jr $ra
    nop
