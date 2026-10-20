.set noreorder
.set noat
.section .text
.globl Rnc_ReadBits
Rnc_ReadBits:
    and $t0, $t6, $t0
    sub $t7, $t7, $t1
    bgez $t7, .Lfunc_802AD740_de_020
    nop
    addu $t9, $ra, $zero
    jal Rnc_RefillBitBuffer
    nop
    addu $ra, $t9, $zero
.Lfunc_802AD740_de_020:
    jr $ra
    srlv $t6, $t6, $t1
