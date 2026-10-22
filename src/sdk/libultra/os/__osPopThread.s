.set noreorder
.set noat
.section .text
.globl __osPopThread
__osPopThread:
    lw $v0, 0x0($a0)
    nop
    lw $t9, 0x0($v0)
    sw $zero, 0x0($v0)
    jr $ra
    sw $t9, 0x0($a0)
