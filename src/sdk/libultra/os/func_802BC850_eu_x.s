.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl func_802BC850_eu_x
func_802BC850_eu_x:
    lui $a0, %hi(D_800D5268_de)
    addiu $a0, $a0, %lo(D_800D5268_de)
    jal __osPopThread
    nop
    lui $at, %hi(D_800D5270)
    sw $v0, %lo(D_800D5270)($at)
    addiu $t0, $zero, 0x4
    sh $t0, 0x10($v0)
    addu $k0, $v0, $zero
    lw $k1, 0x118($k0)
    lui $t0, %hi(D_800D5258)
    addiu $t0, $t0, %lo(D_800D5258)
    lw $t0, 0x0($t0)
    nop
    andi $t0, $t0, 0xFF00
    andi $t1, $k1, 0xFF00
    and $t1, $t1, $t0
    lui $at, 0xFFFF
    ori $at, $at, 0xFF
    and $k1, $k1, $at
    or $k1, $k1, $t1
    nop
    mtc0 $k1, $12
    nop
    ld $at, 0x20($k0)
    ld $v0, 0x28($k0)
    ld $v1, 0x30($k0)
    ld $a0, 0x38($k0)
    ld $a1, 0x40($k0)
    ld $a2, 0x48($k0)
    ld $a3, 0x50($k0)
    ld $t0, 0x58($k0)
    ld $t1, 0x60($k0)
    ld $t2, 0x68($k0)
    ld $t3, 0x70($k0)
    ld $t4, 0x78($k0)
    ld $t5, 0x80($k0)
    ld $t6, 0x88($k0)
    ld $t7, 0x90($k0)
    ld $s0, 0x98($k0)
    ld $s1, 0xA0($k0)
    ld $s2, 0xA8($k0)
    ld $s3, 0xB0($k0)
    ld $s4, 0xB8($k0)
    ld $s5, 0xC0($k0)
    ld $s6, 0xC8($k0)
    ld $s7, 0xD0($k0)
    ld $t8, 0xD8($k0)
    ld $t9, 0xE0($k0)
    ld $gp, 0xE8($k0)
    ld $sp, 0xF0($k0)
    ld $fp, 0xF8($k0)
    ld $ra, 0x100($k0)
    ld $k1, 0x108($k0)
    nop
    mtlo $k1
    ld $k1, 0x110($k0)
    nop
    mthi $k1
    lw $k1, 0x11C($k0)
    nop
    mtc0 $k1, $14
    lw $k1, 0x18($k0)
    nop
    beqz $k1, .Lfunc_802BC850_eu_x_1AC
    nop
    lw $k1, 0x12C($k0)
    nop
    ctc1 $k1, $31
    ldc1 $f0, 0x130($k0)
    ldc1 $f2, 0x138($k0)
    ldc1 $f4, 0x140($k0)
    ldc1 $f6, 0x148($k0)
    ldc1 $f8, 0x150($k0)
    ldc1 $f10, 0x158($k0)
    ldc1 $f12, 0x160($k0)
    ldc1 $f14, 0x168($k0)
    ldc1 $f16, 0x170($k0)
    ldc1 $f18, 0x178($k0)
    ldc1 $f20, 0x180($k0)
    ldc1 $f22, 0x188($k0)
    ldc1 $f24, 0x190($k0)
    ldc1 $f26, 0x198($k0)
    ldc1 $f28, 0x1A0($k0)
    ldc1 $f30, 0x1A8($k0)
    lw $k1, 0x118($k0)
    nop
    srl $k1, $k1, 16
    andi $k1, $k1, 0x400
    beqz $k1, .Lfunc_802BC850_eu_x_1AC
    nop
    ldc1 $f1, 0x1B0($k0)
    ldc1 $f3, 0x1B8($k0)
    ldc1 $f5, 0x1C0($k0)
    ldc1 $f7, 0x1C8($k0)
    ldc1 $f9, 0x1D0($k0)
    ldc1 $f11, 0x1D8($k0)
    ldc1 $f13, 0x1E0($k0)
    ldc1 $f15, 0x1E8($k0)
    ldc1 $f17, 0x1F0($k0)
    ldc1 $f19, 0x1F8($k0)
    ldc1 $f21, 0x200($k0)
    ldc1 $f23, 0x208($k0)
    ldc1 $f25, 0x210($k0)
    ldc1 $f27, 0x218($k0)
    ldc1 $f29, 0x220($k0)
    ldc1 $f31, 0x228($k0)
.Lfunc_802BC850_eu_x_1AC:
    lw $k1, 0x128($k0)
    lui $k0, %hi(D_800D5258)
    addiu $k0, $k0, %lo(D_800D5258)
    lw $k0, 0x0($k0)
    nop
    srl $k0, $k0, 16
    and $k1, $k1, $k0
    sll $k1, $k1, 1
    lui $k0, %hi(D_800C7A70_de)
    addiu $k0, $k0, %lo(D_800C7A70_de)
    addu $k1, $k1, $k0
    lhu $k1, 0x0($k1)
    lui $k0, %hi(D_A430000C)
    ori $k0, $k0, %lo(D_A430000C)
    sw $k1, 0x0($k0)
    nop
    nop
    nop
    nop
    eret
    jal Audio_DestroyThread
    addu $a0, $zero, $zero
.if VERSION_DE
    lui $a1, 0xA460
    lui $v1, %hi(D_801487B4)
    lw $v1, %lo(D_801487B4)($v1)
.elseif VERSION_EU
    addiu $s2, $zero, 0xFF
    beq $v0, $s2, .Lfunc_802BC850_eu_x_280
    nop
.elseif VERSION_US
    nop
    .word 0x00134348 # jr $zero # 00134340 <InstrIdType: CPU_SPECIAL>
    daddiu $at, $t3, 0x6C74
.else
    beqz $v0, .Lfunc_802BC850_eu_x_210
    addiu $s0, $zero, 0x20
    addu $s0, $s1, $zero
.Lfunc_802BC850_eu_x_210:
.endif
    addiu $sp, $sp, -0x30
    lui $a1, 0xA460
    lui $v1, %hi(D_801487B4)
    lw $v1, %lo(D_801487B4)($v1)
    ori $a1, $a1, 0x10
    sw $ra, 0x2C($sp)
    sw $s2, 0x28($sp)
    sw $s1, 0x24($sp)
    sw $s0, 0x20($sp)
    lw $v0, 0x0($a1)
    addiu $s1, $v1, 0x14
    sw $v0, 0x18($sp)
    lhu $a0, 0x1A($v1)
    lw $v1, 0x18($sp)
    sll $v0, $a0, 3
    addu $v0, $v0, $a0
    sll $v0, $v0, 2
    addiu $v0, $v0, 0x18
    andi $v1, $v1, 0x1
    beqz $v1, .Lfunc_802BC850_eu_x_290
    addu $s0, $s1, $v0
    addiu $v0, $zero, 0x1D
    lui $a0, %hi(D_800D5258)
    addiu $a0, $a0, %lo(D_800D5258)
    sw $v0, 0x0($s0)
    lw $v0, 0x0($a0)
    addiu $v1, $zero, -0x801
    and $v0, $v0, $v1
.if VERSION_EU
.Lfunc_802BC850_eu_x_280:
.endif
    jal Audio_PostDiskEventMessage
    sw $v0, 0x0($a0)
    j .Lfunc_802BC850_eu_x_708
    addiu $v0, $zero, 0x1
.Lfunc_802BC850_eu_x_290:
    lw $v0, 0x0($a1)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    beqz $v0, .Lfunc_802BC850_eu_x_2C8
    lui $v0, 0xA500
    lui $v1, 0xA460
    ori $v1, $v1, 0x10
.Lfunc_802BC850_eu_x_2B0:
    lw $v0, 0x0($v1)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    bnez $v0, .Lfunc_802BC850_eu_x_2B0
    lui $v0, 0xA500
.Lfunc_802BC850_eu_x_2C8:
    ori $v0, $v0, 0x508
    lw $s2, 0x0($v0)
    lui $v0, 0x200
    and $v0, $s2, $v0
    beqz $v0, .Lfunc_802BC850_eu_x_33C
    lui $v0, 0xA460
    ori $v0, $v0, 0x10
    lw $v0, 0x0($v0)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    beqz $v0, .Lfunc_802BC850_eu_x_318
    lui $v1, 0xA460
    ori $v1, $v1, 0x10
.Lfunc_802BC850_eu_x_300:
    lw $v0, 0x0($v1)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    bnez $v0, .Lfunc_802BC850_eu_x_300
    nop
.Lfunc_802BC850_eu_x_318:
    lui $a1, 0xA500
    ori $a1, $a1, 0x510
    lw $a0, 0x10($s1)
    lui $v1, 0x100
    sw $zero, 0x0($s0)
    or $a0, $a0, $v1
    sw $a0, 0x0($a1)
    j .Lfunc_802BC850_eu_x_708
    addu $v0, $zero, $zero
.Lfunc_802BC850_eu_x_33C:
    lw $v1, 0x0($s1)
    addiu $a2, $zero, 0x2
    beq $v1, $a2, .Lfunc_802BC850_eu_x_708
    addiu $v0, $zero, 0x1
    lui $v0, 0x800
    and $v0, $s2, $v0
    beqz $v0, .Lfunc_802BC850_eu_x_3E0
    lui $v0, 0xA460
    ori $v0, $v0, 0x10
    lw $v0, 0x0($v0)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    beqz $v0, .Lfunc_802BC850_eu_x_394
    lui $v1, 0xA460
    ori $v1, $v1, 0x10
.Lfunc_802BC850_eu_x_37C:
    lw $v0, 0x0($v1)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    bnez $v0, .Lfunc_802BC850_eu_x_37C
    nop
.Lfunc_802BC850_eu_x_394:
    lui $v0, 0xA500
    ori $v0, $v0, 0x508
    lw $s2, 0x0($v0)
    addiu $v0, $zero, 0x16
    jal Audio_PostDiskEventMessage
    sw $v0, 0x0($s0)
    lui $a3, 0xA460
    ori $a3, $a3, 0x10
    lui $a2, 0x10
    ori $a2, $a2, 0x401
    addiu $v0, $zero, 0x1
    lui $a1, %hi(D_800D5258)
    addiu $a1, $a1, %lo(D_800D5258)
    lw $v1, 0x0($a1)
    addiu $a0, $zero, 0x2
    sw $a0, 0x0($a3)
    or $v1, $v1, $a2
    j .Lfunc_802BC850_eu_x_708
    sw $v1, 0x0($a1)
.Lfunc_802BC850_eu_x_3E0:
    addiu $v0, $zero, 0x1
    bne $v1, $v0, .Lfunc_802BC850_eu_x_498
    lui $v0, 0x4000
    and $v0, $s2, $v0
    bnez $v0, .Lfunc_802BC850_eu_x_454
    addiu $a1, $zero, 0x1
    lw $a0, 0x8($s1)
    lhu $v1, 0x4($s1)
    addiu $a0, $a0, 0x1
    sll $v0, $v1, 2
    addu $v0, $v0, $v1
    sll $v1, $v0, 4
    addu $v0, $v0, $v1
    bne $a0, $v0, .Lfunc_802BC850_eu_x_6F8
    addiu $v0, $zero, 0x18
    lui $a0, 0xA460
    ori $a0, $a0, 0x10
    lui $a1, 0x10
    lui $v1, %hi(D_800D5258)
    addiu $v1, $v1, %lo(D_800D5258)
    lw $v0, 0x0($v1)
    ori $a1, $a1, 0x401
    sw $a2, 0x0($a0)
    sw $zero, 0x0($s0)
    or $v0, $v0, $a1
    jal Audio_PostDiskEventMessage
    sw $v0, 0x0($v1)
    j .Lfunc_802BC850_eu_x_708
    addiu $v0, $zero, 0x1
.Lfunc_802BC850_eu_x_454:
    lw $v0, 0x4($s0)
    lw $v1, 0xC($s0)
    addu $v0, $v0, $v1
    sw $v0, 0x4($s0)
    lw $v0, 0x8($s1)
    lui $a0, %hi(D_801487B4)
    lw $a0, %lo(D_801487B4)($a0)
    addu $v0, $v0, $a1
    sw $v0, 0x8($s1)
    lw $v0, 0xC($s0)
    lui $a2, 0x500
    sw $v0, 0x10($sp)
    lw $a3, 0x4($s0)
    jal func_802B93B0_de
    ori $a2, $a2, 0x400
    j .Lfunc_802BC850_eu_x_708
    addiu $v0, $zero, 0x1
.Lfunc_802BC850_eu_x_498:
    bnez $v1, .Lfunc_802BC850_eu_x_6F8
    addiu $v0, $zero, 0x4
    lhu $v1, 0x4($s1)
    addiu $v0, $zero, 0x3
    bne $v1, $v0, .Lfunc_802BC850_eu_x_4E4
    nop
    lw $v0, 0x10($s0)
    lw $v1, 0x8($s1)
    addiu $v0, $v0, 0x11
    slt $v0, $v0, $v1
    beqz $v0, .Lfunc_802BC850_eu_x_4D0
    lui $v0, 0x4000
    j .Lfunc_802BC850_eu_x_6FC
    sw $zero, 0x0($s0)
.Lfunc_802BC850_eu_x_4D0:
    and $v0, $s2, $v0
    bnez $v0, .Lfunc_802BC850_eu_x_4F8
    lui $v0, 0xA500
    j .Lfunc_802BC850_eu_x_6F8
    addiu $v0, $zero, 0x17
.Lfunc_802BC850_eu_x_4E4:
    lw $v0, 0x4($s0)
    lw $v1, 0xC($s0)
    addu $v0, $v0, $v1
    sw $v0, 0x4($s0)
    lui $v0, 0xA500
.Lfunc_802BC850_eu_x_4F8:
    ori $v0, $v0, 0x510
    lw $a0, 0x0($v0)
    lui $v1, 0x60
    and $v0, $a0, $v1
    beq $v0, $v1, .Lfunc_802BC850_eu_x_51C
    lui $v0, 0x200
    and $v0, $a0, $v0
    beqz $v0, .Lfunc_802BC850_eu_x_574
    lui $v0, 0x1000
.Lfunc_802BC850_eu_x_51C:
    lw $v1, 0x10($s0)
    sltiu $v0, $v1, 0x4
    bnez $v0, .Lfunc_802BC850_eu_x_554
    sll $v1, $v1, 2
    lhu $v1, 0x4($s1)
    addiu $v0, $zero, 0x3
    bne $v1, $v0, .Lfunc_802BC850_eu_x_6F8
    addiu $v0, $zero, 0x17
    lw $v0, 0x8($s1)
    slti $v0, $v0, 0x53
    bnez $v0, .Lfunc_802BC850_eu_x_564
    addiu $v0, $zero, 0x17
    j .Lfunc_802BC850_eu_x_6FC
    sw $v0, 0x0($s0)
.Lfunc_802BC850_eu_x_554:
    lw $v0, 0x8($s1)
    addu $v1, $s0, $v1
    addiu $v0, $v0, 0x1
    sw $v0, 0x14($v1)
.Lfunc_802BC850_eu_x_564:
    lw $v0, 0x10($s0)
    addiu $v0, $v0, 0x1
    sw $v0, 0x10($s0)
    lui $v0, 0x1000
.Lfunc_802BC850_eu_x_574:
    and $v0, $s2, $v0
    beqz $v0, .Lfunc_802BC850_eu_x_630
    addiu $v1, $zero, 0x58
    lw $v0, 0x8($s1)
    addiu $v0, $v0, 0x1
    beq $v0, $v1, .Lfunc_802BC850_eu_x_598
    addiu $v0, $zero, 0x18
    jal Audio_AbortDiskTransfer
    sw $v0, 0x0($s0)
.Lfunc_802BC850_eu_x_598:
    lw $v1, 0x4($s1)
    lui $v0, 0x2
    bne $v1, $v0, .Lfunc_802BC850_eu_x_5D4
    lui $a1, 0xA460
    lw $v1, 0x40($s1)
    lw $a0, 0x48($s1)
    addiu $v0, $zero, 0x1
    sh $v0, 0x6($s1)
    addiu $v0, $zero, -0x1
    sw $v0, 0x8($s1)
    addiu $v0, $zero, 0x16
    subu $v1, $v1, $a0
    sw $v1, 0x40($s1)
    j .Lfunc_802BC850_eu_x_604
    sw $v0, 0x0($s0)
.Lfunc_802BC850_eu_x_5D4:
    ori $a1, $a1, 0x10
    lui $a2, 0x10
    ori $a2, $a2, 0x401
    lui $a0, %hi(D_800D5258)
    addiu $a0, $a0, %lo(D_800D5258)
    lw $v1, 0x0($a0)
    addiu $v0, $zero, 0x2
    sw $v0, 0x0($a1)
    sw $v0, 0x0($s1)
    sw $zero, 0x0($s0)
    or $v1, $v1, $a2
    sw $v1, 0x0($a0)
.Lfunc_802BC850_eu_x_604:
    addu $a1, $zero, $zero
    lw $v0, 0xC($s0)
    lui $a0, %hi(D_801487B4)
    lw $a0, %lo(D_801487B4)($a0)
    sll $v0, $v0, 2
    sw $v0, 0x10($sp)
    lw $a3, 0x8($s0)
    jal func_802B93B0_de
    lui $a2, 0x500
    j .Lfunc_802BC850_eu_x_708
    addiu $v0, $zero, 0x1
.Lfunc_802BC850_eu_x_630:
    lw $v1, 0x8($s1)
    addiu $v0, $zero, -0x1
    bne $v1, $v0, .Lfunc_802BC850_eu_x_694
    lui $v1, 0x2
    lw $v0, 0x4($s1)
    ori $v1, $v1, 0x1
    bne $v0, $v1, .Lfunc_802BC850_eu_x_694
    nop
    lw $v0, 0x28($s1)
    bnez $v0, .Lfunc_802BC850_eu_x_68C
    addiu $a1, $s1, 0x18
    lw $v1, 0x8($a1)
    lw $v0, 0x0($v1)
    lw $a0, 0x4($v1)
    or $v0, $v0, $a0
    lw $a0, 0x8($v1)
    lw $v1, 0xC($v1)
    or $v0, $v0, $a0
    or $v0, $v0, $v1
    beqz $v0, .Lfunc_802BC850_eu_x_68C
    addiu $v0, $zero, 0x18
    j .Lfunc_802BC850_eu_x_6FC
    sw $v0, 0x18($s1)
.Lfunc_802BC850_eu_x_68C:
    jal Audio_PostDiskEventMessage
    sw $zero, 0x0($a1)
.Lfunc_802BC850_eu_x_694:
    lw $v0, 0x8($s1)
    addiu $v1, $v0, 0x1
    lui $v0, 0x4000
    and $v0, $s2, $v0
    beqz $v0, .Lfunc_802BC850_eu_x_6EC
    sw $v1, 0x8($s1)
    slti $v0, $v1, 0x55
    bnez $v0, .Lfunc_802BC850_eu_x_6C0
    addu $a1, $zero, $zero
    j .Lfunc_802BC850_eu_x_6F8
    addiu $v0, $zero, 0x18
.Lfunc_802BC850_eu_x_6C0:
    lui $a0, %hi(D_801487B4)
    lw $a0, %lo(D_801487B4)($a0)
    lw $v0, 0xC($s0)
    lui $a2, 0x500
    sw $v0, 0x10($sp)
    lw $a3, 0x4($s0)
    jal func_802B93B0_de
    ori $a2, $a2, 0x400
    addiu $v0, $zero, 0x1
    j .Lfunc_802BC850_eu_x_708
    sw $zero, 0x0($s0)
.Lfunc_802BC850_eu_x_6EC:
    slti $v0, $v1, 0x55
    beqz $v0, .Lfunc_802BC850_eu_x_704
    addiu $v0, $zero, 0x18
.Lfunc_802BC850_eu_x_6F8:
    sw $v0, 0x0($s0)
.Lfunc_802BC850_eu_x_6FC:
    jal Audio_AbortDiskTransfer
    nop
.Lfunc_802BC850_eu_x_704:
    addiu $v0, $zero, 0x1
.Lfunc_802BC850_eu_x_708:
    lw $ra, 0x2C($sp)
    lw $s2, 0x28($sp)
    lw $s1, 0x24($sp)
    lw $s0, 0x20($sp)
    jr $ra
    addiu $sp, $sp, 0x30
