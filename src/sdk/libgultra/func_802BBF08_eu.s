.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl func_802BBF08_eu
func_802BBF08_eu:
    addiu $sp, $sp, 0x40
    addu $a2, $zero, $zero
    lui $k0, %hi(D_002BBF20_eu)
    addiu $k0, $k0, %lo(D_002BBF20_eu)
    jr $k0
    nop
    lui $k0, %hi(D_8015ABD0_eu)
    addiu $k0, $k0, %lo(D_8015ABD0_eu)
    sd $at, 0x20($k0)
    mfc0 $k1, $12
    nop
    sw $k1, 0x118($k0)
    addiu $at, $zero, -0x4
    and $k1, $k1, $at
    mtc0 $k1, $12
    sd $t0, 0x58($k0)
    sd $t1, 0x60($k0)
    sd $t2, 0x68($k0)
    sw $zero, 0x18($k0)
    mfc0 $t0, $13
    addu $t0, $k0, $zero
    lui $k0, %hi(D_800D5270)
    lw $k0, %lo(D_800D5270)($k0)
    ld $t1, 0x20($t0)
    ld $t2, 0x118($t0)
    sd $t1, 0x20($k0)
    sd $t2, 0x118($k0)
    ld $t1, 0x58($t0)
    ld $t2, 0x60($t0)
    sd $t1, 0x58($k0)
    sd $t2, 0x60($k0)
    ld $t1, 0x68($t0)
    sd $v0, 0x28($k0)
    sd $t1, 0x68($k0)
    sd $v1, 0x30($k0)
    sd $a0, 0x38($k0)
    sd $a1, 0x40($k0)
    sd $a2, 0x48($k0)
    sd $a3, 0x50($k0)
    sd $t3, 0x70($k0)
    sd $t4, 0x78($k0)
    sd $t5, 0x80($k0)
    sd $t6, 0x88($k0)
    sd $t7, 0x90($k0)
    sd $s0, 0x98($k0)
    sd $s1, 0xA0($k0)
    sd $s2, 0xA8($k0)
    sd $s3, 0xB0($k0)
    sd $s4, 0xB8($k0)
    sd $s5, 0xC0($k0)
    sd $s6, 0xC8($k0)
    sd $s7, 0xD0($k0)
    sd $t8, 0xD8($k0)
    sd $t9, 0xE0($k0)
    sd $gp, 0xE8($k0)
    sd $sp, 0xF0($k0)
    sd $fp, 0xF8($k0)
    sd $ra, 0x100($k0)
    mflo $t0
    sd $t0, 0x108($k0)
    mfhi $t0
    sd $t0, 0x110($k0)
    lw $k1, 0x118($k0)
    nop
    andi $t1, $k1, 0xFF00
    beqz $t1, .Lfunc_802BBF08_eu_158
    nop
    lui $t0, %hi(D_800D5258)
    addiu $t0, $t0, %lo(D_800D5258)
    lw $t0, 0x0($t0)
    nop
    addiu $at, $zero, -0x1
    xor $t2, $t0, $at
    andi $t2, $t2, 0xFF00
    or $t4, $t1, $t2
    lui $at, 0xFFFF
    ori $at, $at, 0xFF
    and $t3, $k1, $at
    or $t3, $t3, $t4
    sw $t3, 0x118($k0)
    andi $t0, $t0, 0xFF00
    and $t1, $t1, $t0
    lui $at, 0xFFFF
    ori $at, $at, 0xFF
    and $k1, $k1, $at
    or $k1, $k1, $t1
.Lfunc_802BBF08_eu_158:
    lui $t1, %hi(D_A430000C)
    lw $t1, %lo(D_A430000C)($t1)
    nop
    beqz $t1, .Lfunc_802BBF08_eu_198
    nop
    lui $t0, %hi(D_800D5258)
    addiu $t0, $t0, %lo(D_800D5258)
    lw $t0, 0x0($t0)
    nop
    srl $t0, $t0, 16
    addiu $at, $zero, -0x1
    xor $t0, $t0, $at
    lw $t4, 0x128($k0)
    andi $t0, $t0, 0x3F
    and $t0, $t0, $t4
    or $t1, $t1, $t0
.Lfunc_802BBF08_eu_198:
    mfc0 $t0, $14
    sw $t1, 0x128($k0)
    sw $t0, 0x11C($k0)
    lw $t0, 0x18($k0)
    nop
    beqz $t0, .Lfunc_802BBF08_eu_254
    nop
    cfc1 $t0, $31
    nop
    sw $t0, 0x12C($k0)
    sdc1 $f0, 0x130($k0)
    sdc1 $f2, 0x138($k0)
    sdc1 $f4, 0x140($k0)
    sdc1 $f6, 0x148($k0)
    sdc1 $f8, 0x150($k0)
    sdc1 $f10, 0x158($k0)
    sdc1 $f12, 0x160($k0)
    sdc1 $f14, 0x168($k0)
    sdc1 $f16, 0x170($k0)
    sdc1 $f18, 0x178($k0)
    sdc1 $f20, 0x180($k0)
    sdc1 $f22, 0x188($k0)
    sdc1 $f24, 0x190($k0)
    sdc1 $f26, 0x198($k0)
    sdc1 $f28, 0x1A0($k0)
    lw $t1, 0x118($k0)
    sdc1 $f30, 0x1A8($k0)
    lui $at, 0x400
    and $t1, $t1, $at
    beqz $t1, .Lfunc_802BBF08_eu_254
    nop
    sdc1 $f1, 0x1B0($k0)
    sdc1 $f3, 0x1B8($k0)
    sdc1 $f5, 0x1C0($k0)
    sdc1 $f7, 0x1C8($k0)
    sdc1 $f9, 0x1D0($k0)
    sdc1 $f11, 0x1D8($k0)
    sdc1 $f13, 0x1E0($k0)
    sdc1 $f15, 0x1E8($k0)
    sdc1 $f17, 0x1F0($k0)
    sdc1 $f19, 0x1F8($k0)
    sdc1 $f21, 0x200($k0)
    sdc1 $f23, 0x208($k0)
    sdc1 $f25, 0x210($k0)
    sdc1 $f27, 0x218($k0)
    sdc1 $f29, 0x220($k0)
    sdc1 $f31, 0x228($k0)
.Lfunc_802BBF08_eu_254:
    mfc0 $t0, $13
    addiu $t1, $zero, 0x2
    sw $t0, 0x120($k0)
    sh $t1, 0x10($k0)
    andi $t1, $t0, 0x7C
    addiu $t2, $zero, 0x24
    beq $t1, $t2, .Lfunc_802BBF08_eu_564
    addiu $t2, $zero, 0x2C
    beq $t1, $t2, func_802BC268_de+0xCC
    addiu $t2, $zero, 0x0
    bne $t1, $t2, .Lfunc_802BBF08_eu_5D0
    and $s0, $k1, $t0
.Lfunc_802BBF08_eu_284:
    andi $t1, $s0, 0xFF00
    srl $t2, $t1, 12
    bnez $t2, .Lfunc_802BBF08_eu_29C
    nop
    srl $t2, $t1, 8
    addi $t2, $t2, 0x10
.Lfunc_802BBF08_eu_29C:
    lui $at, %hi(D_800C8610_eu)
    addu $at, $at, $t2
    lbu $t2, %lo(D_800C8610_eu)($at)
    lui $at, %hi(D_800C8630_eu)
    addu $at, $at, $t2
    lw $t2, %lo(D_800C8630_eu)($at)
    nop
    jr $t2
    nop
    addiu $at, $zero, -0x2001
    and $s0, $s0, $at
    bgez $zero, .Lfunc_802BBF08_eu_284
    nop
    addiu $at, $zero, -0x4001
    and $s0, $s0, $at
    bgez $zero, .Lfunc_802BBF08_eu_284
    nop
    mfc0 $t1, $11
    lui $at, 0xFFFF
    ori $at, $at, 0x7FFF
    and $s0, $s0, $at
    mtc0 $t1, $11
    jal func_802BC268_de
    addiu $a0, $zero, 0x18
    bgez $zero, .Lfunc_802BBF08_eu_284
    nop
    addiu $a0, $zero, 0x10
    addiu $at, $zero, -0x801
    and $s0, $s0, $at
    lui $sp, %hi(D_80159BD0_eu)
    addiu $sp, $sp, %lo(D_80159BD0_eu)
    addiu $sp, $sp, 0xFF0
    addiu $t2, $zero, 0x4
    lui $at, 0x800E
    addu $at, $at, $t2
    lw $t2, 0x5910($at)
    nop
    beqz $t2, .Lfunc_802BBF08_eu_350
    nop
    jalr $t2
    addiu $a0, $zero, 0x10
    beqz $v0, .Lfunc_802BBF08_eu_350
    nop
    bgez $zero, .Lfunc_802BBF08_eu_57C
    nop
.Lfunc_802BBF08_eu_350:
    jal func_802BC268_de
    nop
    bgez $zero, .Lfunc_802BBF08_eu_284
    nop
    lui $s1, 0xA430
    lw $s1, 0x8($s1)
    lui $t0, %hi(D_800D5258)
    addiu $t0, $t0, %lo(D_800D5258)
    lw $t0, 0x0($t0)
    nop
    srl $t0, $t0, 16
    and $s1, $s1, $t0
    andi $t1, $s1, 0x1
    beqz $t1, .Lfunc_802BBF08_eu_3D8
    nop
    andi $s1, $s1, 0x3E
    lui $t4, 0xA404
    lw $t4, 0x10($t4)
    ori $t1, $zero, 0x8008
    lui $at, 0xA404
    sw $t1, 0x10($at)
    andi $t4, $t4, 0x300
    beqz $t4, .Lfunc_802BBF08_eu_3C8
    nop
    jal func_802BC268_de
    addiu $a0, $zero, 0x20
    beqz $s1, .Lfunc_802BBF08_eu_4A4
    nop
    bgez $zero, .Lfunc_802BBF08_eu_3D8
    nop
.Lfunc_802BBF08_eu_3C8:
    jal func_802BC268_de
    addiu $a0, $zero, 0x58
    beqz $s1, .Lfunc_802BBF08_eu_4A4
    nop
.Lfunc_802BBF08_eu_3D8:
    andi $t1, $s1, 0x8
    nop
    beqz $t1, .Lfunc_802BBF08_eu_400
    andi $s1, $s1, 0x37
    lui $at, 0xA440
    sw $zero, 0x10($at)
    jal func_802BC268_de
    addiu $a0, $zero, 0x38
    beqz $s1, .Lfunc_802BBF08_eu_4A4
    nop
.Lfunc_802BBF08_eu_400:
    andi $t1, $s1, 0x4
    beqz $t1, .Lfunc_802BBF08_eu_42C
    nop
    andi $s1, $s1, 0x3B
    addiu $t1, $zero, 0x1
    lui $at, 0xA450
    sw $t1, 0xC($at)
    jal func_802BC268_de
    addiu $a0, $zero, 0x30
    beqz $s1, .Lfunc_802BBF08_eu_4A4
    nop
.Lfunc_802BBF08_eu_42C:
    andi $t1, $s1, 0x2
    beqz $t1, .Lfunc_802BBF08_eu_454
    nop
    andi $s1, $s1, 0x3D
    lui $at, 0xA480
    sw $zero, 0x18($at)
    jal func_802BC268_de
    addiu $a0, $zero, 0x28
    beqz $s1, .Lfunc_802BBF08_eu_4A4
    nop
.Lfunc_802BBF08_eu_454:
    andi $t1, $s1, 0x10
    beqz $t1, .Lfunc_802BBF08_eu_480
    nop
    andi $s1, $s1, 0x2F
    addiu $t1, $zero, 0x2
    lui $at, 0xA460
    sw $t1, 0x10($at)
    jal func_802BC268_de
    addiu $a0, $zero, 0x40
    beqz $s1, .Lfunc_802BBF08_eu_4A4
    nop
.Lfunc_802BBF08_eu_480:
    andi $t1, $s1, 0x20
    beqz $t1, .Lfunc_802BBF08_eu_4A4
    nop
    andi $s1, $s1, 0x1F
    addiu $t1, $zero, 0x800
    lui $at, 0xA430
    sw $t1, 0x0($at)
    jal func_802BC268_de
    addiu $a0, $zero, 0x48
.Lfunc_802BBF08_eu_4A4:
    addiu $at, $zero, -0x401
    and $s0, $s0, $at
    bgez $zero, .Lfunc_802BBF08_eu_284
    nop
    lw $k1, 0x118($k0)
    lui $t1, %hi(rodata_unresolved_800E58D4)
    addiu $t1, $t1, %lo(rodata_unresolved_800E58D4)
    addiu $at, $zero, -0x1001
    and $k1, $k1, $at
    lw $t2, 0x0($t1)
    addiu $at, $zero, -0x1001
    and $s0, $s0, $at
    beqz $t2, .Lfunc_802BBF08_eu_4E4
    sw $k1, 0x118($k0)
    bgez $zero, .Lfunc_802BBF08_eu_57C
    nop
.Lfunc_802BBF08_eu_4E4:
    addiu $t2, $zero, 0x1
    sw $t2, 0x0($t1)
    jal func_802BC268_de
    addiu $a0, $zero, 0x70
    lui $t2, %hi(D_800D5268_de)
    lw $t2, %lo(D_800D5268_de)($t2)
    addiu $at, $zero, -0x1001
    and $s0, $s0, $at
    lw $k1, 0x118($t2)
    nop
    addiu $at, $zero, -0x1001
    and $k1, $k1, $at
    bgez $zero, .Lfunc_802BBF08_eu_57C
    sw $k1, 0x118($t2)
    addiu $at, $zero, -0x201
    and $t0, $t0, $at
    mtc0 $t0, $13
    addiu $at, $zero, -0x201
    and $s0, $s0, $at
    jal func_802BC268_de
    addiu $a0, $zero, 0x8
    bgez $zero, .Lfunc_802BBF08_eu_284
    nop
    addiu $at, $zero, -0x101
    and $t0, $t0, $at
    mtc0 $t0, $13
    addiu $at, $zero, -0x101
    and $s0, $s0, $at
    jal func_802BC268_de
    addiu $a0, $zero, 0x0
    bgez $zero, .Lfunc_802BBF08_eu_284
    nop
.Lfunc_802BBF08_eu_564:
    addiu $t1, $zero, 0x1
    sh $t1, 0x12($k0)
    jal func_802BC268_de
    addiu $a0, $zero, 0x50
    bgez $zero, .Lfunc_802BBF08_eu_57C
    nop
.Lfunc_802BBF08_eu_57C:
    lui $t2, %hi(D_800D5268_de)
    lw $t2, %lo(D_800D5268_de)($t2)
    lw $t1, 0x4($k0)
    lw $t3, 0x4($t2)
    nop
    slt $at, $t1, $t3
    beqz $at, .Lfunc_802BBF08_eu_5B4
    nop
    lui $a0, %hi(D_800D5268_de)
    addiu $a0, $a0, %lo(D_800D5268_de)
    jal __osEnqueueThread
    addu $a1, $k0, $zero
    j func_802BC850_eu_x
    nop
.Lfunc_802BBF08_eu_5B4:
    lui $t1, %hi(D_800D5268_de)
    addiu $t1, $t1, %lo(D_800D5268_de)
    lw $t2, 0x0($t1)
    nop
    sw $t2, 0x0($k0)
    j func_802BC850_eu_x
    sw $k0, 0x0($t1)
.Lfunc_802BBF08_eu_5D0:
    lui $at, %hi(D_800D92A4)
    sw $k0, %lo(D_800D92A4)($at)
    addiu $t1, $zero, 0x1
    sh $t1, 0x10($k0)
    addiu $t1, $zero, 0x2
    mfc0 $t2, $8
    sh $t1, 0x12($k0)
    sw $t2, 0x124($k0)
    jal func_802BC268_de
    addiu $a0, $zero, 0x60
    j func_802BC850_eu_x
    nop
