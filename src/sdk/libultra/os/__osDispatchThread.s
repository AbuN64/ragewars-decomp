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
    lui $at, %hi(g_osRunningThread)
    sw $v0, %lo(g_osRunningThread)($at)
    addiu $t0, $zero, 0x4
    sh $t0, 0x10($v0)
    addu $k0, $v0, $zero
    lw $k1, 0x118($k0)
    lui $t0, %hi(g_globalInterruptMask)
    addiu $t0, $t0, %lo(g_globalInterruptMask)
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
    beqz $k1, .LdispatchRestoreRcpMask
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
    beqz $k1, .LdispatchRestoreRcpMask
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
.LdispatchRestoreRcpMask:
    lw $k1, 0x128($k0)
    lui $k0, %hi(g_globalInterruptMask)
    addiu $k0, $k0, %lo(g_globalInterruptMask)
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
    beq $v0, $s2, .LdiskPostEventMessage
    nop
.elseif VERSION_US
    nop
    .word 0x00134348 # jr $zero # 00134340 <InstrIdType: CPU_SPECIAL>
    daddiu $at, $t3, 0x6C74
.else
    beqz $v0, .LdiskEntrySkipMove
    addiu $s0, $zero, 0x20
    addu $s0, $s1, $zero
.LdiskEntrySkipMove:
.endif
    addiu $sp, $sp, -0x30
    lui $a1, 0xA460
    lui $v1, %hi(g_currentDiskPeripheralHandle)
    lw $v1, %lo(g_currentDiskPeripheralHandle)($v1)
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
    beqz $v1, .LdiskPiIdleRecheck
    addu $s0, $s1, $v0
    addiu $v0, $zero, 0x1D
    lui $a0, %hi(g_globalInterruptMask)
    addiu $a0, $a0, %lo(g_globalInterruptMask)
    sw $v0, 0x0($s0)
    lw $v0, 0x0($a0)
    addiu $v1, $zero, -0x801
    and $v0, $v0, $v1
.if VERSION_EU
.LdiskPostEventMessage:
.endif
    jal Audio_PostDiskEventMessage
    sw $v0, 0x0($a0)
    j .LdiskReturn
    addiu $v0, $zero, 0x1
.LdiskPiIdleRecheck:
    lw $v0, 0x0($a1)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    beqz $v0, .LdiskReadAsicStatus
    lui $v0, 0xA500
    lui $v1, 0xA460
    ori $v1, $v1, 0x10
.LdiskPiIdleSpinBeforeAsicRead:
    lw $v0, 0x0($v1)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    bnez $v0, .LdiskPiIdleSpinBeforeAsicRead
    lui $v0, 0xA500
.LdiskReadAsicStatus:
    ori $v0, $v0, 0x508
    lw $s2, 0x0($v0)
    lui $v0, 0x200
    and $v0, $s2, $v0
    beqz $v0, .LdiskCheckHandleState
    lui $v0, 0xA460
    ori $v0, $v0, 0x10
    lw $v0, 0x0($v0)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    beqz $v0, .LdiskWriteBmControl
    lui $v1, 0xA460
    ori $v1, $v1, 0x10
.LdiskPiIdleSpinBeforeBmWrite:
    lw $v0, 0x0($v1)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    bnez $v0, .LdiskPiIdleSpinBeforeBmWrite
    nop
.LdiskWriteBmControl:
    lui $a1, 0xA500
    ori $a1, $a1, 0x510
    lw $a0, 0x10($s1)
    lui $v1, 0x100
    sw $zero, 0x0($s0)
    or $a0, $a0, $v1
    sw $a0, 0x0($a1)
    j .LdiskReturn
    addu $v0, $zero, $zero
.LdiskCheckHandleState:
    lw $v1, 0x0($s1)
    addiu $a2, $zero, 0x2
    beq $v1, $a2, .LdiskReturn
    addiu $v0, $zero, 0x1
    lui $v0, 0x800
    and $v0, $s2, $v0
    beqz $v0, .LdiskCheckStateIsOne
    lui $v0, 0xA460
    ori $v0, $v0, 0x10
    lw $v0, 0x0($v0)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    beqz $v0, .LdiskPostErrorEvent
    lui $v1, 0xA460
    ori $v1, $v1, 0x10
.LdiskPiIdleSpinBeforeErrorEvent:
    lw $v0, 0x0($v1)
    sw $v0, 0x18($sp)
    lw $v0, 0x18($sp)
    andi $v0, $v0, 0x3
    bnez $v0, .LdiskPiIdleSpinBeforeErrorEvent
    nop
.LdiskPostErrorEvent:
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
    lui $a1, %hi(g_globalInterruptMask)
    addiu $a1, $a1, %lo(g_globalInterruptMask)
    lw $v1, 0x0($a1)
    addiu $a0, $zero, 0x2
    sw $a0, 0x0($a3)
    or $v1, $v1, $a2
    j .LdiskReturn
    sw $v1, 0x0($a1)
.LdiskCheckStateIsOne:
    addiu $v0, $zero, 0x1
    bne $v1, $v0, .LdiskCheckStateIsZero
    lui $v0, 0x4000
    and $v0, $s2, $v0
    bnez $v0, .LdiskAdvanceDmaBuffer
    addiu $a1, $zero, 0x1
    lw $a0, 0x8($s1)
    lhu $v1, 0x4($s1)
    addiu $a0, $a0, 0x1
    sll $v0, $v1, 2
    addu $v0, $v0, $v1
    sll $v1, $v0, 4
    addu $v0, $v0, $v1
    bne $a0, $v0, .LdiskStoreStatusCode
    addiu $v0, $zero, 0x18
    lui $a0, 0xA460
    ori $a0, $a0, 0x10
    lui $a1, 0x10
    lui $v1, %hi(g_globalInterruptMask)
    addiu $v1, $v1, %lo(g_globalInterruptMask)
    lw $v0, 0x0($v1)
    ori $a1, $a1, 0x401
    sw $a2, 0x0($a0)
    sw $zero, 0x0($s0)
    or $v0, $v0, $a1
    jal Audio_PostDiskEventMessage
    sw $v0, 0x0($v1)
    j .LdiskReturn
    addiu $v0, $zero, 0x1
.LdiskAdvanceDmaBuffer:
    lw $v0, 0x4($s0)
    lw $v1, 0xC($s0)
    addu $v0, $v0, $v1
    sw $v0, 0x4($s0)
    lw $v0, 0x8($s1)
    lui $a0, %hi(g_currentDiskPeripheralHandle)
    lw $a0, %lo(g_currentDiskPeripheralHandle)($a0)
    addu $v0, $v0, $a1
    sw $v0, 0x8($s1)
    lw $v0, 0xC($s0)
    lui $a2, 0x500
    sw $v0, 0x10($sp)
    lw $a3, 0x4($s0)
    jal __osEPiRawStartDma
    ori $a2, $a2, 0x400
    j .LdiskReturn
    addiu $v0, $zero, 0x1
.LdiskCheckStateIsZero:
    bnez $v1, .LdiskStoreStatusCode
    addiu $v0, $zero, 0x4
    lhu $v1, 0x4($s1)
    addiu $v0, $zero, 0x3
    bne $v1, $v0, .LdiskAdvanceBufferOffset
    nop
    lw $v0, 0x10($s0)
    lw $v1, 0x8($s1)
    addiu $v0, $v0, 0x11
    slt $v0, $v0, $v1
    beqz $v0, .LdiskCheckAsicBit30
    lui $v0, 0x4000
    j .LdiskAbortTransfer
    sw $zero, 0x0($s0)
.LdiskCheckAsicBit30:
    and $v0, $s2, $v0
    bnez $v0, .LdiskReadBmStatus
    lui $v0, 0xA500
    j .LdiskStoreStatusCode
    addiu $v0, $zero, 0x17
.LdiskAdvanceBufferOffset:
    lw $v0, 0x4($s0)
    lw $v1, 0xC($s0)
    addu $v0, $v0, $v1
    sw $v0, 0x4($s0)
    lui $v0, 0xA500
.LdiskReadBmStatus:
    ori $v0, $v0, 0x510
    lw $a0, 0x0($v0)
    lui $v1, 0x60
    and $v0, $a0, $v1
    beq $v0, $v1, .LdiskCheckRetryCount
    lui $v0, 0x200
    and $v0, $a0, $v0
    beqz $v0, .LdiskCheckAsicBit28
    lui $v0, 0x1000
.LdiskCheckRetryCount:
    lw $v1, 0x10($s0)
    sltiu $v0, $v1, 0x4
    bnez $v0, .LdiskStoreBlockIndex
    sll $v1, $v1, 2
    lhu $v1, 0x4($s1)
    addiu $v0, $zero, 0x3
    bne $v1, $v0, .LdiskStoreStatusCode
    addiu $v0, $zero, 0x17
    lw $v0, 0x8($s1)
    slti $v0, $v0, 0x53
    bnez $v0, .LdiskIncrementRetryCount
    addiu $v0, $zero, 0x17
    j .LdiskAbortTransfer
    sw $v0, 0x0($s0)
.LdiskStoreBlockIndex:
    lw $v0, 0x8($s1)
    addu $v1, $s0, $v1
    addiu $v0, $v0, 0x1
    sw $v0, 0x14($v1)
.LdiskIncrementRetryCount:
    lw $v0, 0x10($s0)
    addiu $v0, $v0, 0x1
    sw $v0, 0x10($s0)
    lui $v0, 0x1000
.LdiskCheckAsicBit28:
    and $v0, $s2, $v0
    beqz $v0, .LdiskCheckBlockCounterReset
    addiu $v1, $zero, 0x58
    lw $v0, 0x8($s1)
    addiu $v0, $v0, 0x1
    beq $v0, $v1, .LdiskCheckTransferKind
    addiu $v0, $zero, 0x18
    jal Audio_AbortDiskTransfer
    sw $v0, 0x0($s0)
.LdiskCheckTransferKind:
    lw $v1, 0x4($s1)
    lui $v0, 0x2
    bne $v1, $v0, .LdiskResetPiStatus
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
    j .LdiskStartDmaFromBuffer
    sw $v0, 0x0($s0)
.LdiskResetPiStatus:
    ori $a1, $a1, 0x10
    lui $a2, 0x10
    ori $a2, $a2, 0x401
    lui $a0, %hi(g_globalInterruptMask)
    addiu $a0, $a0, %lo(g_globalInterruptMask)
    lw $v1, 0x0($a0)
    addiu $v0, $zero, 0x2
    sw $v0, 0x0($a1)
    sw $v0, 0x0($s1)
    sw $zero, 0x0($s0)
    or $v1, $v1, $a2
    sw $v1, 0x0($a0)
.LdiskStartDmaFromBuffer:
    addu $a1, $zero, $zero
    lw $v0, 0xC($s0)
    lui $a0, %hi(g_currentDiskPeripheralHandle)
    lw $a0, %lo(g_currentDiskPeripheralHandle)($a0)
    sll $v0, $v0, 2
    sw $v0, 0x10($sp)
    lw $a3, 0x8($s0)
    jal __osEPiRawStartDma
    lui $a2, 0x500
    j .LdiskReturn
    addiu $v0, $zero, 0x1
.LdiskCheckBlockCounterReset:
    lw $v1, 0x8($s1)
    addiu $v0, $zero, -0x1
    bne $v1, $v0, .LdiskAdvanceBlockCounter
    lui $v1, 0x2
    lw $v0, 0x4($s1)
    ori $v1, $v1, 0x1
    bne $v0, $v1, .LdiskAdvanceBlockCounter
    nop
    lw $v0, 0x28($s1)
    bnez $v0, .LdiskPostEventClearSlot
    addiu $a1, $s1, 0x18
    lw $v1, 0x8($a1)
    lw $v0, 0x0($v1)
    lw $a0, 0x4($v1)
    or $v0, $v0, $a0
    lw $a0, 0x8($v1)
    lw $v1, 0xC($v1)
    or $v0, $v0, $a0
    or $v0, $v0, $v1
    beqz $v0, .LdiskPostEventClearSlot
    addiu $v0, $zero, 0x18
    j .LdiskAbortTransfer
    sw $v0, 0x18($s1)
.LdiskPostEventClearSlot:
    jal Audio_PostDiskEventMessage
    sw $zero, 0x0($a1)
.LdiskAdvanceBlockCounter:
    lw $v0, 0x8($s1)
    addiu $v1, $v0, 0x1
    lui $v0, 0x4000
    and $v0, $s2, $v0
    beqz $v0, .LdiskCheckBlockLimit
    sw $v1, 0x8($s1)
    slti $v0, $v1, 0x55
    bnez $v0, .LdiskRestartDma
    addu $a1, $zero, $zero
    j .LdiskStoreStatusCode
    addiu $v0, $zero, 0x18
.LdiskRestartDma:
    lui $a0, %hi(g_currentDiskPeripheralHandle)
    lw $a0, %lo(g_currentDiskPeripheralHandle)($a0)
    lw $v0, 0xC($s0)
    lui $a2, 0x500
    sw $v0, 0x10($sp)
    lw $a3, 0x4($s0)
    jal __osEPiRawStartDma
    ori $a2, $a2, 0x400
    addiu $v0, $zero, 0x1
    j .LdiskReturn
    sw $zero, 0x0($s0)
.LdiskCheckBlockLimit:
    slti $v0, $v1, 0x55
    beqz $v0, .LdiskReturnOne
    addiu $v0, $zero, 0x18
.LdiskStoreStatusCode:
    sw $v0, 0x0($s0)
.LdiskAbortTransfer:
    jal Audio_AbortDiskTransfer
    nop
.LdiskReturnOne:
    addiu $v0, $zero, 0x1
.LdiskReturn:
    lw $ra, 0x2C($sp)
    lw $s2, 0x28($sp)
    lw $s1, 0x24($sp)
    lw $s0, 0x20($sp)
    jr $ra
    addiu $sp, $sp, 0x30
