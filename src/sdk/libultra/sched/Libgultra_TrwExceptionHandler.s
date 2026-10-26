.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl Libgultra_TrwExceptionHandler
Libgultra_TrwExceptionHandler:
    lui $k0, %hi(D_800F3130)
    addiu $k0, $k0, %lo(D_800F3130)
    sd $at, 0x328($k0)
    sd $v0, 0x330($k0)
    mfc0 $at, $13
    lw $v0, 0x338($k0)
    srl $at, $at, 2
    andi $at, $at, 0x1F
    beqz $at, .LLibgultra_TrwExceptionHandler_044
    srlv $v0, $v0, $at
    andi $v0, $v0, 0x1
    bnez $v0, .LLibgultra_TrwExceptionHandler_180
    nop
.LLibgultra_TrwExceptionHandler_034:
    ld $at, 0x328($k0)
    ld $v0, 0x330($k0)
.if VERSION_DE
    bgez $zero, Libsn_SendHostTripleRequest+0xEC
.elseif VERSION_EU
    bgez $zero, Libultra_DispatchEuropeanExceptionVectors+0x1C
.elseif VERSION_US
    bgez $zero, Libgultra_TrwExceptionVectors+0x1C
.else
    bgez $zero, Libultra_DispatchExceptionVectors+0x1C
.endif
    nop
.LLibgultra_TrwExceptionHandler_044:
    mfc0 $at, $13
    nop
    andi $at, $at, 0x800
    beqz $at, .LLibgultra_TrwExceptionHandler_034
    nop
.LLibgultra_TrwExceptionHandler_058:
    lui $at, 0xA460
    ori $at, $at, 0x10
    lw $at, 0x0($at)
    nop
    andi $at, $at, 0x3
    bnez $at, .LLibgultra_TrwExceptionHandler_058
    nop
    lui $at, %hi(D_B1FFFFD8)
    lw $at, %lo(D_B1FFFFD8)($at)
    nop
    andi $at, $at, 0xFFFF
    addi $at, $at, -0x202
    bnez $at, .LLibgultra_TrwExceptionHandler_144
    nop
.LLibgultra_TrwExceptionHandler_090:
    lui $at, 0xA460
    ori $at, $at, 0x10
    lw $at, 0x0($at)
    nop
    andi $at, $at, 0x3
    bnez $at, .LLibgultra_TrwExceptionHandler_090
    nop
    lui $at, 0x303
    ori $at, $at, 0x303
    lui $v0, %hi(D_B1FFFFD8)
    sw $at, %lo(D_B1FFFFD8)($v0)
.LLibgultra_TrwExceptionHandler_0BC:
    lui $at, 0xA460
    ori $at, $at, 0x10
    lw $at, 0x0($at)
    nop
    andi $at, $at, 0x3
    bnez $at, .LLibgultra_TrwExceptionHandler_0BC
    nop
    lui $v0, %hi(D_B1FFFFD8)
    lw $at, %lo(D_B1FFFFD8)($v0)
    lui $v0, 0x303
    ori $v0, $v0, 0x303
    sub $at, $at, $v0
    bnez $at, .LLibgultra_TrwExceptionHandler_10C
    nop
    lui $at, 0x1
    ori $at, $at, 0x1
.LLibgultra_TrwExceptionHandler_0FC:
    bnez $at, .LLibgultra_TrwExceptionHandler_0FC
    addi $at, $at, -0x1
    beqz $at, .LLibgultra_TrwExceptionHandler_0BC
    nop
.LLibgultra_TrwExceptionHandler_10C:
    lui $at, 0xA460
    ori $at, $at, 0x10
    lw $at, 0x0($at)
    nop
    andi $at, $at, 0x3
    bnez $at, .LLibgultra_TrwExceptionHandler_10C
    nop
    lui $v0, %hi(D_B1FFFFD8)
    sw $zero, %lo(D_B1FFFFD8)($v0)
    mfc0 $at, $13
    nop
    ori $at, $at, 0x100
    j .LLibgultra_TrwExceptionHandler_034
    mtc0 $at, $13
.LLibgultra_TrwExceptionHandler_144:
    lui $at, 0xA460
    ori $at, $at, 0x10
    lw $at, 0x0($at)
    nop
    andi $at, $at, 0x3
    bnez $at, .LLibgultra_TrwExceptionHandler_144
    nop
    lui $at, %hi(D_B1FFFFF0)
    lw $at, %lo(D_B1FFFFF0)($at)
    nop
    andi $at, $at, 0xFFFF
    beqz $at, .LLibgultra_TrwExceptionHandler_034
    nop
    bgez $zero, .LLibgultra_TrwExceptionHandler_1B8
    nop
.LLibgultra_TrwExceptionHandler_180:
    addiu $v0, $zero, 0x9
    bne $at, $v0, .LLibgultra_TrwExceptionHandler_1B0
    nop
    mfc0 $v0, $14
    nop
    lw $v0, 0x0($v0)
    nop
    srl $v0, $v0, 6
    addiu $at, $v0, -0x400
    bgez $at, .LLibgultra_TrwExceptionHandler_384
    nop
.LLibgultra_TrwExceptionHandler_1AC:
    addiu $at, $zero, 0x9
.LLibgultra_TrwExceptionHandler_1B0:
    sb $at, 0x320($k0)
    sb $zero, 0x322($k0)
.LLibgultra_TrwExceptionHandler_1B8:
    addiu $at, $zero, 0x1
    sw $at, 0x33C($k0)
    ld $at, 0x328($k0)
    ld $v0, 0x330($k0)
    sd $ra, 0xF8($k0)
    jal Libgultra_TrwExceptionTail1
    nop
    lui $sp, %hi(D_800F3CB0)
    addiu $sp, $sp, %lo(D_800F3CB0)
    jal Libsn_ServiceHostCommands
    nop
    jal Libgultra_TrwCacheFlush0
    nop
    jal Libgultra_TrwCacheFlush1
    nop
    lui $k0, %hi(D_800F3130)
    addiu $k0, $k0, %lo(D_800F3130)
    addiu $at, $zero, 0x1
    sb $at, 0x320($k0)
    ld $t0, 0x108($k0)
    nop
    mthi $t0
    ld $t0, 0x100($k0)
    nop
    mtlo $t0
    ld $t0, 0x178($k0)
    nop
    mtc0 $t0, $12
    ld $t0, 0x110($k0)
    nop
    mtc0 $t0, $14
    ld $t0, 0xD0($k0)
    nop
    mtc0 $t0, $30
    ld $t0, 0x178($k0)
    lui $t1, 0x2000
    and $t1, $t1, $t0
    beqz $t1, .LLibgultra_TrwExceptionHandler_300
    nop
    lw $t0, 0x318($k0)
    nop
    ctc1 $t0, $0
    lw $t0, 0x31C($k0)
    nop
    ctc1 $t0, $31
    ldc1 $f0, 0x218($k0)
    ldc1 $f2, 0x228($k0)
    ldc1 $f4, 0x238($k0)
    ldc1 $f6, 0x248($k0)
    ldc1 $f8, 0x258($k0)
    ldc1 $f10, 0x268($k0)
    ldc1 $f12, 0x278($k0)
    ldc1 $f14, 0x288($k0)
    ldc1 $f16, 0x298($k0)
    ldc1 $f18, 0x2A8($k0)
    ldc1 $f20, 0x2B8($k0)
    ldc1 $f22, 0x2C8($k0)
    ldc1 $f24, 0x2D8($k0)
    ldc1 $f26, 0x2E8($k0)
    ldc1 $f28, 0x2F8($k0)
    ldc1 $f30, 0x308($k0)
    ld $t0, 0x178($k0)
    lui $t1, 0x400
    and $t1, $t1, $t0
    beqz $t1, .LLibgultra_TrwExceptionHandler_300
    nop
    ldc1 $f1, 0x220($k0)
    ldc1 $f3, 0x230($k0)
    ldc1 $f5, 0x240($k0)
    ldc1 $f7, 0x250($k0)
    ldc1 $f9, 0x260($k0)
    ldc1 $f11, 0x270($k0)
    ldc1 $f13, 0x280($k0)
    ldc1 $f15, 0x290($k0)
    ldc1 $f17, 0x2A0($k0)
    ldc1 $f19, 0x2B0($k0)
    ldc1 $f21, 0x2C0($k0)
    ldc1 $f23, 0x2D0($k0)
    ldc1 $f25, 0x2E0($k0)
    ldc1 $f27, 0x2F0($k0)
    ldc1 $f29, 0x300($k0)
    ldc1 $f31, 0x310($k0)
.LLibgultra_TrwExceptionHandler_300:
    ld $at, 0x8($k0)
    ld $v0, 0x10($k0)
    ld $v1, 0x18($k0)
    ld $a0, 0x20($k0)
    ld $a1, 0x28($k0)
    ld $a2, 0x30($k0)
    ld $a3, 0x38($k0)
    ld $t0, 0x40($k0)
    ld $t1, 0x48($k0)
    ld $t2, 0x50($k0)
    ld $t3, 0x58($k0)
    ld $t4, 0x60($k0)
    ld $t5, 0x68($k0)
    ld $t6, 0x70($k0)
    ld $t7, 0x78($k0)
    ld $s0, 0x80($k0)
    ld $s1, 0x88($k0)
    ld $s2, 0x90($k0)
    ld $s3, 0x98($k0)
    ld $s4, 0xA0($k0)
    ld $s5, 0xA8($k0)
    ld $s6, 0xB0($k0)
    ld $s7, 0xB8($k0)
    ld $t8, 0xC0($k0)
    ld $t9, 0xC8($k0)
    ld $k1, 0xD8($k0)
    ld $gp, 0xE0($k0)
    ld $sp, 0xE8($k0)
    ld $fp, 0xF0($k0)
    ld $ra, 0xF8($k0)
    sw $zero, 0x33C($k0)
    mfc0 $k0, $30
    eret
.LLibgultra_TrwExceptionHandler_384:
    addiu $at, $v0, -0x409
    bgez $at, .LLibgultra_TrwExceptionHandler_1AC
    nop
    lui $at, %hi(jtbl_00202814)
    addiu $at, $at, %lo(jtbl_00202814)
    addiu $v0, $v0, -0x400
    sll $v0, $v0, 2
    addu $v0, $v0, $at
    lw $v0, 0x0($v0)
    nop
    jr $v0
    nop
