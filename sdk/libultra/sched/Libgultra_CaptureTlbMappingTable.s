.set noreorder
.set noat
.section .text
.globl Libgultra_CaptureTlbMappingTable
Libgultra_CaptureTlbMappingTable:
    add $v0, $zero, $zero
    addi $a1, $zero, 0x1E
    lui $a0, %hi(g_capturedTlbMappings)
    addiu $a0, $a0, %lo(g_capturedTlbMappings)
.if VERSION_EU
    addi $a2, $zero, 0x15E
.elseif VERSION_EU_X
    addi $a2, $zero, 0x158
.elseif VERSION_US
    addi $a2, $zero, 0x14C
.elseif VERSION_US_REV1
    addi $a2, $zero, 0x156
.else
    addi $a2, $zero, 0x14E
.endif
.LLibgultra_CaptureTlbMappingTable_014:
    mtc0 $v0, $0
    tlbr
    nop
    nop
    nop
    nop
    mfc0 $v1, $5
    nop
    srl $v1, $v1, 13
    sh $v1, 0x0($a0)
    mfc0 $v1, $10
    nop
    srl $v1, $v1, 12
    sh $v1, 0x2($a0)
    mfc0 $v1, $2
    nop
    srl $v1, $v1, 6
    sub $v1, $v1, $a2
    sh $v1, 0x4($a0)
    mfc0 $v1, $3
    nop
    srl $v1, $v1, 6
    sub $v1, $v1, $a2
    sh $v1, 0x6($a0)
    addi $a0, $a0, 0x8
    bne $a1, $v0, .LLibgultra_CaptureTlbMappingTable_014
    addi $v0, $v0, 0x1
    jr $ra
    nop
