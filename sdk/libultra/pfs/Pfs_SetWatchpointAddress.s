.set noreorder
.set noat
.section .text
.globl Pfs_SetWatchpointAddress
Pfs_SetWatchpointAddress:
.if VERSION_DE
    jr $ra
.elseif VERSION_US_REV1
    andi $v0, $v0, 0xC0
.endif
    sll $a0, $a0, 4
    srl $a0, $a0, 4
    addi $v0, $zero, -0x8
    and $a0, $v0, $a0
    andi $a1, $a1, 0x3
    or $a0, $a1, $a0
    mtc0 $a0, $18
    nop
    nop
    nop
    nop
    mfc0 $zero, $19
    nop
    nop
    nop
    jr $ra
    nop
