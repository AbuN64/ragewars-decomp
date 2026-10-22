.set noreorder
.set noat
.section .text
.globl osUnmapTLBAll
osUnmapTLBAll:
    mfc0 $t0, $10
    addiu $t1, $zero, 0x1E
    lui $t2, 0x8000
    mtc0 $t2, $10
    mtc0 $zero, $2
    mtc0 $zero, $3
.LosUnmapTLBAll_018:
    mtc0 $t1, $0
    nop
    tlbwi
    nop
    nop
    addi $t1, $t1, -0x1
    bgez $t1, .LosUnmapTLBAll_018
    nop
    mtc0 $t0, $10
    jr $ra
    nop
