.set noreorder
.set noat
.section .text
.globl System_TranslateTlbVirtualAddress
System_TranslateTlbVirtualAddress:
    mfc0 $t0, $10
    nop
    andi $t1, $t0, 0xFF
    addiu $at, $zero, -0x2000
    and $t2, $a0, $at
    or $t1, $t1, $t2
    mtc0 $t1, $10
    nop
    nop
    nop
    tlbp
    nop
    nop
    mfc0 $t3, $0
    nop
    lui $at, 0x8000
    and $t3, $t3, $at
    bnez $t3, .Lfunc_802BD080_de_0B8
    nop
    tlbr
    nop
    nop
    nop
    mfc0 $t3, $5
    nop
    addi $t3, $t3, 0x2000
    srl $t3, $t3, 1
    and $t4, $t3, $a0
    bnez $t4, .Lfunc_802BD080_de_084
    addi $t3, $t3, -0x1
    mfc0 $v0, $2
    bgez $zero, .Lfunc_802BD080_de_088
    nop
.Lfunc_802BD080_de_084:
    mfc0 $v0, $3
.Lfunc_802BD080_de_088:
    nop
    andi $t5, $v0, 0x2
    beqz $t5, .Lfunc_802BD080_de_0B8
    nop
    lui $at, 0x3FFF
    ori $at, $at, 0xFFC0
    and $v0, $v0, $at
    sll $v0, $v0, 6
    and $t5, $a0, $t3
    add $v0, $v0, $t5
    bgez $zero, .Lfunc_802BD080_de_0BC
    nop
.Lfunc_802BD080_de_0B8:
    addiu $v0, $zero, -0x1
.Lfunc_802BD080_de_0BC:
    mtc0 $t0, $10
    jr $ra
    nop
