.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl __osDispatchThread
__osDispatchThread:
    lui $a0, %hi(g_osRunnableThreadQueue)
    addiu $a0, $a0, %lo(g_osRunnableThreadQueue)
    jal __osPopThread
    nop
.if VERSION_US || VERSION_US_REV1
    lui $at, %hi(D_blob_5a9d95bf8283eca200f7)
    sw $v0, %lo(D_blob_5a9d95bf8283eca200f7)($at)
.else
    lui $at, %hi(g_osRunningThread)
    sw $v0, %lo(g_osRunningThread)($at)
.endif
    addiu $t0, $zero, 0x4
    sh $t0, 0x10($v0)
    addu $k0, $v0, $zero
    lw $k1, 0x118($k0)
    lui $t0, %hi(g_audioAbortdisktransferDataConstantWords)
    addiu $t0, $t0, %lo(g_audioAbortdisktransferDataConstantWords)
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
    beqz $k1, .L__osDispatchThread_1AC
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
    beqz $k1, .L__osDispatchThread_1AC
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
.L__osDispatchThread_1AC:
    lw $k1, 0x128($k0)
    lui $k0, %hi(g_audioAbortdisktransferDataConstantWords)
    addiu $k0, $k0, %lo(g_audioAbortdisktransferDataConstantWords)
    lw $k0, 0x0($k0)
    nop
    srl $k0, $k0, 16
    and $k1, $k1, $k0
    sll $k1, $k1, 1
    lui $k0, %hi(g_interruptMaskCommandTable)
    addiu $k0, $k0, %lo(g_interruptMaskCommandTable)
    addu $k1, $k1, $k0
    lhu $k1, 0x0($k1)
    lui $k0, %hi(MI_INTERRUPT_MASK_REGISTER)
    ori $k0, $k0, %lo(MI_INTERRUPT_MASK_REGISTER)
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
    lui $v1, %hi(g_currentDiskPeripheralHandle)
    lw $v1, %lo(g_currentDiskPeripheralHandle)($v1)
.elseif VERSION_EU
    addiu $s2, $zero, 0xFF
    beq $v0, $s2, __osLeoInterrupt+0x70
    nop
.elseif VERSION_US
    nop
    .word 0x00134348 # jr $zero # 00134340 <InstrIdType: CPU_SPECIAL>
    daddiu $at, $t3, 0x6C74
.else
    beqz $v0, __osLeoInterrupt
    addiu $s0, $zero, 0x20
    addu $s0, $s1, $zero
.endif
