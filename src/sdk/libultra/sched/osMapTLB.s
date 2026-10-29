.set noreorder
.set noat
.section .text
.globl osMapTLB
osMapTLB:
    lw $t8, 0x10($sp)
    addi $t0, $zero, 0x7
    lw $t9, 0x14($sp)
    addi $t7, $zero, -0x1
    and $t9, $t9, $t0
    and $t1, $a3, $t8
    beq $t1, $t7, osUnmapTLB
    ori $t9, $t9, 0x18
    mfc0 $t0, $10
    mtc0 $a0, $0
    mtc0 $a1, $5
    mtc0 $a2, $10
    beq $a3, $t7, .osMapTLB_UseInvalidEntryLo0
    addi $t6, $zero, 0x1
    srl $t5, $a3, 6
    or $t5, $t5, $t9
    b .osMapTLB_LoadEntryLo1
    mtc0 $t5, $2
.osMapTLB_UseInvalidEntryLo0:
    mtc0 $t6, $2
.osMapTLB_LoadEntryLo1:
    beq $t8, $t7, .osMapTLB_WriteIndexedEntry
    mtc0 $t6, $3
    srl $t5, $t8, 6
    or $t5, $t5, $t9
    mtc0 $t5, $3
.osMapTLB_WriteIndexedEntry:
    tlbwi
    nop
    nop
    nop
    nop
    mtc0 $t0, $10
    jr $ra
    nop
