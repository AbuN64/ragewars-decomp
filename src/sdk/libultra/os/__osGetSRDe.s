.set noreorder
.set noat
.section .text
.if VERSION_DE
.globl __osGetSRDe
__osGetSRDe:
.elseif VERSION_EU
.globl __osGetSREu
__osGetSREu:
.elseif VERSION_US
.globl __osGetSRUs
__osGetSRUs:
.else
.globl __osGetSREuX
__osGetSREuX:
.endif
    mfc0 $v0, $12
    jr $ra
    nop
