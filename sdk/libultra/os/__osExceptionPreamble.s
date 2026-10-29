.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl __osExceptionPreamble
__osExceptionPreamble:
.if VERSION_DE
    jr $k0
    nop
.elseif VERSION_EU
    addiu $sp, $sp, 0x40
    addu $a2, $zero, $zero
.elseif VERSION_EU_X || VERSION_US_REV1
    sw $v0, 0x0($s0)
    jal Audio_AbortDiskTransfer
.endif
    lui $k0, %hi(__osExceptionKuseg)
    addiu $k0, $k0, %lo(__osExceptionKuseg)
    jr $k0
    nop
.if VERSION_US
    lui $k0, 0x8015
    addiu $k0, $k0, -0x7430
.else
    lui $k0, %hi(__osThreadSave)
    addiu $k0, $k0, %lo(__osThreadSave)
.endif
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
.if VERSION_US || VERSION_US_REV1
    lui $k0, %hi(D_blob_5a9d95bf8283eca200f7)
    lw $k0, %lo(D_blob_5a9d95bf8283eca200f7)($k0)
.else
    lui $k0, %hi(g_osRunningThread)
    lw $k0, %lo(g_osRunningThread)($k0)
.endif
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
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_150
.else
    beqz $t1, .L__osExceptionPreamble_158
.endif
    nop
    lui $t0, %hi(g_audioAbortdisktransferDataConstantWords)
    addiu $t0, $t0, %lo(g_audioAbortdisktransferDataConstantWords)
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
.if VERSION_US
.L__osExceptionPreamble_150:
.else
.L__osExceptionPreamble_158:
.endif
    lui $t1, %hi(MI_INTERRUPT_MASK_REGISTER)
    lw $t1, %lo(MI_INTERRUPT_MASK_REGISTER)($t1)
    nop
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_190
.else
    beqz $t1, .L__osExceptionPreamble_198
.endif
    nop
    lui $t0, %hi(g_audioAbortdisktransferDataConstantWords)
    addiu $t0, $t0, %lo(g_audioAbortdisktransferDataConstantWords)
    lw $t0, 0x0($t0)
    nop
    srl $t0, $t0, 16
    addiu $at, $zero, -0x1
    xor $t0, $t0, $at
    lw $t4, 0x128($k0)
    andi $t0, $t0, 0x3F
    and $t0, $t0, $t4
    or $t1, $t1, $t0
.if VERSION_US
.L__osExceptionPreamble_190:
.else
.L__osExceptionPreamble_198:
.endif
    mfc0 $t0, $14
    sw $t1, 0x128($k0)
    sw $t0, 0x11C($k0)
    lw $t0, 0x18($k0)
    nop
.if VERSION_US
    beqz $t0, .L__osExceptionPreamble_24C
.else
    beqz $t0, .L__osExceptionPreamble_254
.endif
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
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_24C
.else
    beqz $t1, .L__osExceptionPreamble_254
.endif
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
.if VERSION_US
.L__osExceptionPreamble_24C:
.else
.L__osExceptionPreamble_254:
.endif
    mfc0 $t0, $13
    addiu $t1, $zero, 0x2
    sw $t0, 0x120($k0)
    sh $t1, 0x10($k0)
    andi $t1, $t0, 0x7C
    addiu $t2, $zero, 0x24
.if VERSION_US
    beq $t1, $t2, .L__osExceptionPreamble_55C
.else
    beq $t1, $t2, .L__osExceptionPreamble_564
.endif
    addiu $t2, $zero, 0x2C
    beq $t1, $t2, send_mesg+0xCC
    addiu $t2, $zero, 0x0
.if VERSION_US
    bne $t1, $t2, .L__osExceptionPreamble_5C8
.else
    bne $t1, $t2, .L__osExceptionPreamble_5D0
.endif
    and $s0, $k1, $t0
.if VERSION_US
.L__osExceptionPreamble_27C:
.else
.L__osExceptionPreamble_284:
.endif
    andi $t1, $s0, 0xFF00
    srl $t2, $t1, 12
.if VERSION_US
    bnez $t2, .L__osExceptionPreamble_294
.else
    bnez $t2, .L__osExceptionPreamble_29C
.endif
    nop
    srl $t2, $t1, 8
    addi $t2, $t2, 0x10
.if VERSION_EU
.L__osExceptionPreamble_29C:
    lui $at, %hi(g_interruptDispatchOffsetsEu)
.elseif VERSION_EU_X
.L__osExceptionPreamble_29C:
    lui $at, %hi(g_interruptDispatchOffsetsEuX)
.elseif VERSION_US
.L__osExceptionPreamble_294:
    lui $at, 0x800C
.elseif VERSION_US_REV1
.L__osExceptionPreamble_29C:
    lui $at, 0x800D
.else
.L__osExceptionPreamble_29C:
    lui $at, 0x800C
.endif
    addu $at, $at, $t2
.if VERSION_EU
    lbu $t2, %lo(g_interruptDispatchOffsetsEu)($at)
    lui $at, %hi(g_interruptDispatchHandlersEu)
.elseif VERSION_EU_X
    lbu $t2, %lo(g_interruptDispatchOffsetsEuX)($at)
    lui $at, 0x800D
.elseif VERSION_US
    lbu $t2, 0x7940($at)
    lui $at, 0x800C
.elseif VERSION_US_REV1
    lbu $t2, -0x3390($at)
    lui $at, 0x800D
.else
    lbu $t2, 0x7A20($at)
    lui $at, 0x800C
.endif
    addu $at, $at, $t2
.if VERSION_EU
    lw $t2, %lo(g_interruptDispatchHandlersEu)($at)
.elseif VERSION_EU_X
    lw $t2, -0x7000($at)
.elseif VERSION_US
    lw $t2, 0x7960($at)
.elseif VERSION_US_REV1
    lw $t2, -0x3370($at)
.else
    lw $t2, 0x7A40($at)
.endif
    nop
    jr $t2
    nop
    addiu $at, $zero, -0x2001
    and $s0, $s0, $at
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_27C
.else
    bgez $zero, .L__osExceptionPreamble_284
.endif
    nop
    addiu $at, $zero, -0x4001
    and $s0, $s0, $at
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_27C
.else
    bgez $zero, .L__osExceptionPreamble_284
.endif
    nop
    mfc0 $t1, $11
    lui $at, 0xFFFF
    ori $at, $at, 0x7FFF
    and $s0, $s0, $at
    mtc0 $t1, $11
    jal send_mesg
    addiu $a0, $zero, 0x18
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_27C
.else
    bgez $zero, .L__osExceptionPreamble_284
.endif
    nop
    addiu $a0, $zero, 0x10
    addiu $at, $zero, -0x801
    and $s0, $s0, $at
.if VERSION_EU
    lui $sp, %hi(g_exceptionStackTopEu)
    addiu $sp, $sp, %lo(g_exceptionStackTopEu)
.elseif VERSION_EU_X
    lui $sp, %hi(g_exceptionStackTopEuX)
    addiu $sp, $sp, %lo(g_exceptionStackTopEuX)
.elseif VERSION_US
    lui $sp, 0x8014
    addiu $sp, $sp, 0x7BD0
.elseif VERSION_US_REV1
    lui $sp, %hi(g_exceptionStackTopUsRev1)
    addiu $sp, $sp, %lo(g_exceptionStackTopUsRev1)
.else
    lui $sp, %hi(g_exceptionStackTopDe)
    addiu $sp, $sp, %lo(g_exceptionStackTopDe)
.endif
    addiu $sp, $sp, 0xFF0
    addiu $t2, $zero, 0x4
.if VERSION_DE || VERSION_US
    lui $at, 0x800D
.else
    lui $at, 0x800E
.endif
    addu $at, $at, $t2
.if VERSION_EU
    lw $t2, 0x5910($at)
.elseif VERSION_EU_X
    lw $t2, 0xAD0($at)
.elseif VERSION_US
    lw $t2, 0x3F40($at)
.elseif VERSION_US_REV1
    lw $t2, -0x6D40($at)
.else
    lw $t2, 0x5290($at)
.endif
    nop
.if VERSION_US
    beqz $t2, .L__osExceptionPreamble_348
.else
    beqz $t2, .L__osExceptionPreamble_350
.endif
    nop
    jalr $t2
    addiu $a0, $zero, 0x10
.if VERSION_US
    beqz $v0, .L__osExceptionPreamble_348
.else
    beqz $v0, .L__osExceptionPreamble_350
.endif
    nop
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_574
.else
    bgez $zero, .L__osExceptionPreamble_57C
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_348:
.else
.L__osExceptionPreamble_350:
.endif
    jal send_mesg
    nop
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_27C
.else
    bgez $zero, .L__osExceptionPreamble_284
.endif
    nop
    lui $s1, 0xA430
    lw $s1, 0x8($s1)
    lui $t0, %hi(g_audioAbortdisktransferDataConstantWords)
    addiu $t0, $t0, %lo(g_audioAbortdisktransferDataConstantWords)
    lw $t0, 0x0($t0)
    nop
    srl $t0, $t0, 16
    and $s1, $s1, $t0
    andi $t1, $s1, 0x1
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_3D0
.else
    beqz $t1, .L__osExceptionPreamble_3D8
.endif
    nop
    andi $s1, $s1, 0x3E
    lui $t4, 0xA404
    lw $t4, 0x10($t4)
    ori $t1, $zero, 0x8008
    lui $at, 0xA404
    sw $t1, 0x10($at)
    andi $t4, $t4, 0x300
.if VERSION_US
    beqz $t4, .L__osExceptionPreamble_3C0
.else
    beqz $t4, .L__osExceptionPreamble_3C8
.endif
    nop
    jal send_mesg
    addiu $a0, $zero, 0x20
.if VERSION_US
    beqz $s1, .L__osExceptionPreamble_49C
.else
    beqz $s1, .L__osExceptionPreamble_4A4
.endif
    nop
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_3D0
.else
    bgez $zero, .L__osExceptionPreamble_3D8
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_3C0:
.else
.L__osExceptionPreamble_3C8:
.endif
    jal send_mesg
    addiu $a0, $zero, 0x58
.if VERSION_US
    beqz $s1, .L__osExceptionPreamble_49C
.else
    beqz $s1, .L__osExceptionPreamble_4A4
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_3D0:
.else
.L__osExceptionPreamble_3D8:
.endif
    andi $t1, $s1, 0x8
    nop
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_3F8
.else
    beqz $t1, .L__osExceptionPreamble_400
.endif
    andi $s1, $s1, 0x37
    lui $at, 0xA440
    sw $zero, 0x10($at)
    jal send_mesg
    addiu $a0, $zero, 0x38
.if VERSION_US
    beqz $s1, .L__osExceptionPreamble_49C
.else
    beqz $s1, .L__osExceptionPreamble_4A4
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_3F8:
.else
.L__osExceptionPreamble_400:
.endif
    andi $t1, $s1, 0x4
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_424
.else
    beqz $t1, .L__osExceptionPreamble_42C
.endif
    nop
    andi $s1, $s1, 0x3B
    addiu $t1, $zero, 0x1
    lui $at, 0xA450
    sw $t1, 0xC($at)
    jal send_mesg
    addiu $a0, $zero, 0x30
.if VERSION_US
    beqz $s1, .L__osExceptionPreamble_49C
.else
    beqz $s1, .L__osExceptionPreamble_4A4
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_424:
.else
.L__osExceptionPreamble_42C:
.endif
    andi $t1, $s1, 0x2
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_44C
.else
    beqz $t1, .L__osExceptionPreamble_454
.endif
    nop
    andi $s1, $s1, 0x3D
    lui $at, 0xA480
    sw $zero, 0x18($at)
    jal send_mesg
    addiu $a0, $zero, 0x28
.if VERSION_US
    beqz $s1, .L__osExceptionPreamble_49C
.else
    beqz $s1, .L__osExceptionPreamble_4A4
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_44C:
.else
.L__osExceptionPreamble_454:
.endif
    andi $t1, $s1, 0x10
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_478
.else
    beqz $t1, .L__osExceptionPreamble_480
.endif
    nop
    andi $s1, $s1, 0x2F
    addiu $t1, $zero, 0x2
    lui $at, 0xA460
    sw $t1, 0x10($at)
    jal send_mesg
    addiu $a0, $zero, 0x40
.if VERSION_US
    beqz $s1, .L__osExceptionPreamble_49C
.else
    beqz $s1, .L__osExceptionPreamble_4A4
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_478:
.else
.L__osExceptionPreamble_480:
.endif
    andi $t1, $s1, 0x20
.if VERSION_US
    beqz $t1, .L__osExceptionPreamble_49C
.else
    beqz $t1, .L__osExceptionPreamble_4A4
.endif
    nop
    andi $s1, $s1, 0x1F
    addiu $t1, $zero, 0x800
    lui $at, 0xA430
    sw $t1, 0x0($at)
    jal send_mesg
    addiu $a0, $zero, 0x48
.if VERSION_US
.L__osExceptionPreamble_49C:
.else
.L__osExceptionPreamble_4A4:
.endif
    addiu $at, $zero, -0x401
    and $s0, $s0, $at
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_27C
.else
    bgez $zero, .L__osExceptionPreamble_284
.endif
    nop
    lw $k1, 0x118($k0)
.if VERSION_EU
    lui $t1, %hi(g_preNmiShutdownFlagEu)
    addiu $t1, $t1, %lo(g_preNmiShutdownFlagEu)
.elseif VERSION_EU_X
    lui $t1, %hi(g_preNmiShutdownFlagEuX)
    addiu $t1, $t1, %lo(g_preNmiShutdownFlagEuX)
.elseif VERSION_US
    lui $t1, %hi(k_osaisetfrequencyDataConstantWordsTrailingZeroWord)
    addiu $t1, $t1, %lo(k_osaisetfrequencyDataConstantWordsTrailingZeroWord)
.elseif VERSION_US_REV1
    lui $t1, %hi(g_preNmiShutdownFlagUsRev1)
    addiu $t1, $t1, %lo(g_preNmiShutdownFlagUsRev1)
.else
    lui $t1, %hi(g_preNmiShutdownFlagDe)
    addiu $t1, $t1, %lo(g_preNmiShutdownFlagDe)
.endif
    addiu $at, $zero, -0x1001
    and $k1, $k1, $at
    lw $t2, 0x0($t1)
    addiu $at, $zero, -0x1001
    and $s0, $s0, $at
.if VERSION_US
    beqz $t2, .L__osExceptionPreamble_4DC
.else
    beqz $t2, .L__osExceptionPreamble_4E4
.endif
    sw $k1, 0x118($k0)
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_574
.else
    bgez $zero, .L__osExceptionPreamble_57C
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_4DC:
.else
.L__osExceptionPreamble_4E4:
.endif
    addiu $t2, $zero, 0x1
    sw $t2, 0x0($t1)
    jal send_mesg
    addiu $a0, $zero, 0x70
    lui $t2, %hi(g_osRunnableThreadQueue)
    lw $t2, %lo(g_osRunnableThreadQueue)($t2)
    addiu $at, $zero, -0x1001
    and $s0, $s0, $at
    lw $k1, 0x118($t2)
    nop
    addiu $at, $zero, -0x1001
    and $k1, $k1, $at
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_574
.else
    bgez $zero, .L__osExceptionPreamble_57C
.endif
    sw $k1, 0x118($t2)
    addiu $at, $zero, -0x201
    and $t0, $t0, $at
    mtc0 $t0, $13
    addiu $at, $zero, -0x201
    and $s0, $s0, $at
    jal send_mesg
    addiu $a0, $zero, 0x8
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_27C
.else
    bgez $zero, .L__osExceptionPreamble_284
.endif
    nop
    addiu $at, $zero, -0x101
    and $t0, $t0, $at
    mtc0 $t0, $13
    addiu $at, $zero, -0x101
    and $s0, $s0, $at
    jal send_mesg
    addiu $a0, $zero, 0x0
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_27C
.else
    bgez $zero, .L__osExceptionPreamble_284
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_55C:
.else
.L__osExceptionPreamble_564:
.endif
    addiu $t1, $zero, 0x1
    sh $t1, 0x12($k0)
    jal send_mesg
    addiu $a0, $zero, 0x50
.if VERSION_US
    bgez $zero, .L__osExceptionPreamble_574
.else
    bgez $zero, .L__osExceptionPreamble_57C
.endif
    nop
.if VERSION_US
.L__osExceptionPreamble_574:
.else
.L__osExceptionPreamble_57C:
.endif
    lui $t2, %hi(g_osRunnableThreadQueue)
    lw $t2, %lo(g_osRunnableThreadQueue)($t2)
    lw $t1, 0x4($k0)
    lw $t3, 0x4($t2)
    nop
    slt $at, $t1, $t3
.if VERSION_US
    beqz $at, .L__osExceptionPreamble_5AC
.else
    beqz $at, .L__osExceptionPreamble_5B4
.endif
    nop
    lui $a0, %hi(g_osRunnableThreadQueue)
    addiu $a0, $a0, %lo(g_osRunnableThreadQueue)
    jal __osEnqueueThread
    addu $a1, $k0, $zero
    j __osDispatchThread
    nop
.if VERSION_US
.L__osExceptionPreamble_5AC:
.else
.L__osExceptionPreamble_5B4:
.endif
    lui $t1, %hi(g_osRunnableThreadQueue)
    addiu $t1, $t1, %lo(g_osRunnableThreadQueue)
    lw $t2, 0x0($t1)
    nop
    sw $t2, 0x0($k0)
    j __osDispatchThread
    sw $k0, 0x0($t1)
.if VERSION_US
.L__osExceptionPreamble_5C8:
.else
.L__osExceptionPreamble_5D0:
.endif
    lui $at, %hi(g_audioInterruptMask)
    sw $k0, %lo(g_audioInterruptMask)($at)
    addiu $t1, $zero, 0x1
    sh $t1, 0x10($k0)
    addiu $t1, $zero, 0x2
    mfc0 $t2, $8
    sh $t1, 0x12($k0)
    sw $t2, 0x124($k0)
    jal send_mesg
    addiu $a0, $zero, 0x60
    j __osDispatchThread
    nop
