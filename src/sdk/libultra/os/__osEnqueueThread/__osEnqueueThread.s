

/* System_ExceptionEntry.s */
.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.if VERSION_EU
.globl System_ExceptionEntryEu
System_ExceptionEntryEu:
    addiu $sp, $sp, 0x40
    addu $a2, $zero, $zero
    lui $k0, %hi(System_ExceptionContextSaveAddressEu)
    addiu $k0, $k0, %lo(System_ExceptionContextSaveAddressEu)
.elseif VERSION_EU_X
.globl System_ExceptionEntryEuX
System_ExceptionEntryEuX:
    sw $v0, 0x0($s0)
    jal Audio_AbortDiskTransfer
    lui $k0, %hi(System_ExceptionContextSaveAddressEuX)
    addiu $k0, $k0, %lo(System_ExceptionContextSaveAddressEuX)
.elseif VERSION_US_REV1
.globl System_ExceptionEntryUsRev1
System_ExceptionEntryUsRev1:
    sw $v0, 0x0($s0)
    jal Audio_AbortDiskTransfer
    lui $k0, %hi(System_ExceptionContextSaveAddressUsRev1)
    addiu $k0, $k0, %lo(System_ExceptionContextSaveAddressUsRev1)
.elseif VERSION_US
.globl System_ExceptionEntryUs
System_ExceptionEntryUs:
    lui $k0, %hi(System_ExceptionContextSaveAddressUs)
    addiu $k0, $k0, %lo(System_ExceptionContextSaveAddressUs)
.else
.globl System_ExceptionEntryDe
System_ExceptionEntryDe:
.endif
    jr $k0
    nop
.if VERSION_EU
    lui $k0, %hi(g_exceptionScratchContextEu)
    addiu $k0, $k0, %lo(g_exceptionScratchContextEu)
.elseif VERSION_EU_X
    lui $k0, %hi(g_exceptionScratchContextEuX)
    addiu $k0, $k0, %lo(g_exceptionScratchContextEuX)
.elseif VERSION_US_REV1
    lui $k0, %hi(g_exceptionScratchContextUsRev1)
    addiu $k0, $k0, %lo(g_exceptionScratchContextUsRev1)
.elseif VERSION_US
    lui $k0, 0x8015
    addiu $k0, $k0, -0x7430
.else
    lui $k0, %hi(System_ExceptionContextSaveAddressDe)
    addiu $k0, $k0, %lo(System_ExceptionContextSaveAddressDe)
    jr $k0
    nop
    lui $k0, %hi(g_exceptionScratchContextDe)
    addiu $k0, $k0, %lo(g_exceptionScratchContextDe)
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
    lui $k0, %hi(g_osRunningThread)
    lw $k0, %lo(g_osRunningThread)($k0)
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
    beqz $t1, .LExceptionSaveMiMask
    nop
    lui $t0, %hi(g_globalInterruptMask)
    addiu $t0, $t0, %lo(g_globalInterruptMask)
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
.LExceptionSaveMiMask:
    lui $t1, %hi(MI_INTERRUPT_MASK_REGISTER)
    lw $t1, %lo(MI_INTERRUPT_MASK_REGISTER)($t1)
    nop
    beqz $t1, .LExceptionSaveEpc
    nop
    lui $t0, %hi(g_globalInterruptMask)
    addiu $t0, $t0, %lo(g_globalInterruptMask)
    lw $t0, 0x0($t0)
    nop
    srl $t0, $t0, 16
    addiu $at, $zero, -0x1
    xor $t0, $t0, $at
    lw $t4, 0x128($k0)
    andi $t0, $t0, 0x3F
    and $t0, $t0, $t4
    or $t1, $t1, $t0
.LExceptionSaveEpc:
    mfc0 $t0, $14
    sw $t1, 0x128($k0)
    sw $t0, 0x11C($k0)
    lw $t0, 0x18($k0)
    nop
    beqz $t0, .LExceptionSaveCause
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
    beqz $t1, .LExceptionSaveCause
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
.LExceptionSaveCause:
    mfc0 $t0, $13
    addiu $t1, $zero, 0x2
    sw $t0, 0x120($k0)
    sh $t1, 0x10($k0)
    andi $t1, $t0, 0x7C
    addiu $t2, $zero, 0x24
    beq $t1, $t2, .LExceptionBreak
    addiu $t2, $zero, 0x2C
    beq $t1, $t2, .Lsend_mesg_CC
    addiu $t2, $zero, 0x0
    bne $t1, $t2, .LExceptionThreadFault
    and $s0, $k1, $t0
.LExceptionPendingLoop:
    andi $t1, $s0, 0xFF00
    srl $t2, $t1, 12
    bnez $t2, .LExceptionPendingLookup
    nop
    srl $t2, $t1, 8
    addi $t2, $t2, 0x10
.LExceptionPendingLookup:
.if VERSION_EU
    lui $at, %hi(g_interruptDispatchOffsetsEu)
.elseif VERSION_EU_X
    lui $at, %hi(g_interruptDispatchOffsetsEuX)
.elseif VERSION_US_REV1
    lui $at, 0x800D
.else
    lui $at, 0x800C
.endif
    addu $at, $at, $t2
.if VERSION_EU
    lbu $t2, %lo(g_interruptDispatchOffsetsEu)($at)
    lui $at, %hi(g_interruptDispatchHandlersEu)
.elseif VERSION_EU_X
    lbu $t2, %lo(g_interruptDispatchOffsetsEuX)($at)
    lui $at, 0x800D
.elseif VERSION_US_REV1
    lbu $t2, -0x3390($at)
    lui $at, 0x800D
.elseif VERSION_US
    lbu $t2, 0x7940($at)
    lui $at, 0x800C
.else
    lbu $t2, 0x7A20($at)
    lui $at, 0x800C
.endif
    addu $at, $at, $t2
.if VERSION_EU
    lw $t2, %lo(g_interruptDispatchHandlersEu)($at)
.elseif VERSION_EU_X
    lw $t2, -0x7000($at)
.elseif VERSION_US_REV1
    lw $t2, -0x3370($at)
.elseif VERSION_US
    lw $t2, 0x7960($at)
.else
    lw $t2, 0x7A40($at)
.endif
    nop
    jr $t2
    nop
    addiu $at, $zero, -0x2001
    and $s0, $s0, $at
    bgez $zero, .LExceptionPendingLoop
    nop
    addiu $at, $zero, -0x4001
    and $s0, $s0, $at
    bgez $zero, .LExceptionPendingLoop
    nop
    mfc0 $t1, $11
    lui $at, 0xFFFF
    ori $at, $at, 0x7FFF
    and $s0, $s0, $at
    mtc0 $t1, $11
    jal send_mesg
    addiu $a0, $zero, 0x18
    bgez $zero, .LExceptionPendingLoop
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
.elseif VERSION_US_REV1
    lui $sp, %hi(g_exceptionStackTopUsRev1)
    addiu $sp, $sp, %lo(g_exceptionStackTopUsRev1)
.elseif VERSION_US
    lui $sp, 0x8014
    addiu $sp, $sp, 0x7BD0
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
.elseif VERSION_US_REV1
    lw $t2, -0x6D40($at)
.elseif VERSION_US
    lw $t2, 0x3F40($at)
.else
    lw $t2, 0x5290($at)
.endif
    nop
    beqz $t2, .LExceptionHookFallbackMessage
    nop
    jalr $t2
    addiu $a0, $zero, 0x10
    beqz $v0, .LExceptionHookFallbackMessage
    nop
    bgez $zero, .LExceptionRedispatch
    nop
.LExceptionHookFallbackMessage:
    jal send_mesg
    nop
    bgez $zero, .LExceptionPendingLoop
    nop
    lui $s1, 0xA430
    lw $s1, 0x8($s1)
    lui $t0, %hi(g_globalInterruptMask)
    addiu $t0, $t0, %lo(g_globalInterruptMask)
    lw $t0, 0x0($t0)
    nop
    srl $t0, $t0, 16
    and $s1, $s1, $t0
    andi $t1, $s1, 0x1
    beqz $t1, .LExceptionRcpCheckVi
    nop
    andi $s1, $s1, 0x3E
    lui $t4, 0xA404
    lw $t4, 0x10($t4)
    ori $t1, $zero, 0x8008
    lui $at, 0xA404
    sw $t1, 0x10($at)
    andi $t4, $t4, 0x300
    beqz $t4, .LExceptionSpStatusClear
    nop
    jal send_mesg
    addiu $a0, $zero, 0x20
    beqz $s1, .LExceptionRcpDone
    nop
    bgez $zero, .LExceptionRcpCheckVi
    nop
.LExceptionSpStatusClear:
    jal send_mesg
    addiu $a0, $zero, 0x58
    beqz $s1, .LExceptionRcpDone
    nop
.LExceptionRcpCheckVi:
    andi $t1, $s1, 0x8
    nop
    beqz $t1, .LExceptionRcpCheckAi
    andi $s1, $s1, 0x37
    lui $at, 0xA440
    sw $zero, 0x10($at)
    jal send_mesg
    addiu $a0, $zero, 0x38
    beqz $s1, .LExceptionRcpDone
    nop
.LExceptionRcpCheckAi:
    andi $t1, $s1, 0x4
    beqz $t1, .LExceptionRcpCheckSi
    nop
    andi $s1, $s1, 0x3B
    addiu $t1, $zero, 0x1
    lui $at, 0xA450
    sw $t1, 0xC($at)
    jal send_mesg
    addiu $a0, $zero, 0x30
    beqz $s1, .LExceptionRcpDone
    nop
.LExceptionRcpCheckSi:
    andi $t1, $s1, 0x2
    beqz $t1, .LExceptionRcpCheckPi
    nop
    andi $s1, $s1, 0x3D
    lui $at, 0xA480
    sw $zero, 0x18($at)
    jal send_mesg
    addiu $a0, $zero, 0x28
    beqz $s1, .LExceptionRcpDone
    nop
.LExceptionRcpCheckPi:
    andi $t1, $s1, 0x10
    beqz $t1, .LExceptionRcpCheckDp
    nop
    andi $s1, $s1, 0x2F
    addiu $t1, $zero, 0x2
    lui $at, 0xA460
    sw $t1, 0x10($at)
    jal send_mesg
    addiu $a0, $zero, 0x40
    beqz $s1, .LExceptionRcpDone
    nop
.LExceptionRcpCheckDp:
    andi $t1, $s1, 0x20
    beqz $t1, .LExceptionRcpDone
    nop
    andi $s1, $s1, 0x1F
    addiu $t1, $zero, 0x800
    lui $at, 0xA430
    sw $t1, 0x0($at)
    jal send_mesg
    addiu $a0, $zero, 0x48
.LExceptionRcpDone:
    addiu $at, $zero, -0x401
    and $s0, $s0, $at
    bgez $zero, .LExceptionPendingLoop
    nop
    lw $k1, 0x118($k0)
.if VERSION_EU
    lui $t1, %hi(g_preNmiShutdownFlagEu)
    addiu $t1, $t1, %lo(g_preNmiShutdownFlagEu)
.elseif VERSION_EU_X
    lui $t1, %hi(g_preNmiShutdownFlagEuX)
    addiu $t1, $t1, %lo(g_preNmiShutdownFlagEuX)
.elseif VERSION_US_REV1
    lui $t1, %hi(g_preNmiShutdownFlagUsRev1)
    addiu $t1, $t1, %lo(g_preNmiShutdownFlagUsRev1)
.elseif VERSION_US
    lui $t1, 0x800D
    addiu $t1, $t1, 0x3F04
.else
    lui $t1, %hi(g_preNmiShutdownFlagDe)
    addiu $t1, $t1, %lo(g_preNmiShutdownFlagDe)
.endif
    addiu $at, $zero, -0x1001
    and $k1, $k1, $at
    lw $t2, 0x0($t1)
    addiu $at, $zero, -0x1001
    and $s0, $s0, $at
    beqz $t2, .LExceptionPreNmiFirstEntry
    sw $k1, 0x118($k0)
    bgez $zero, .LExceptionRedispatch
    nop
.LExceptionPreNmiFirstEntry:
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
    bgez $zero, .LExceptionRedispatch
    sw $k1, 0x118($t2)
    addiu $at, $zero, -0x201
    and $t0, $t0, $at
    mtc0 $t0, $13
    addiu $at, $zero, -0x201
    and $s0, $s0, $at
    jal send_mesg
    addiu $a0, $zero, 0x8
    bgez $zero, .LExceptionPendingLoop
    nop
    addiu $at, $zero, -0x101
    and $t0, $t0, $at
    mtc0 $t0, $13
    addiu $at, $zero, -0x101
    and $s0, $s0, $at
    jal send_mesg
    addiu $a0, $zero, 0x0
    bgez $zero, .LExceptionPendingLoop
    nop
.LExceptionBreak:
    addiu $t1, $zero, 0x1
    sh $t1, 0x12($k0)
    jal send_mesg
    addiu $a0, $zero, 0x50
    bgez $zero, .LExceptionRedispatch
    nop
.LExceptionRedispatch:
    lui $t2, %hi(g_osRunnableThreadQueue)
    lw $t2, %lo(g_osRunnableThreadQueue)($t2)
    lw $t1, 0x4($k0)
    lw $t3, 0x4($t2)
    nop
    slt $at, $t1, $t3
    beqz $at, .LExceptionRedispatchFront
    nop
    lui $a0, %hi(g_osRunnableThreadQueue)
    addiu $a0, $a0, %lo(g_osRunnableThreadQueue)
    jal __osEnqueueThread
    addu $a1, $k0, $zero
    j __osDispatchThread
    nop
.LExceptionRedispatchFront:
    lui $t1, %hi(g_osRunnableThreadQueue)
    addiu $t1, $t1, %lo(g_osRunnableThreadQueue)
    lw $t2, 0x0($t1)
    nop
    sw $t2, 0x0($k0)
    j __osDispatchThread
    sw $k0, 0x0($t1)
.LExceptionThreadFault:
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

/* libultra exceptasm.s send_mesg: queue the message for the event in $a0 and wake a blocked receiver.
   Handwritten: the caller is parked in $s2 and the routine returns with jr $s2. */
.globl send_mesg
send_mesg:
    addu $s2, $ra, $zero
    lui $t2, %hi(g_osEventMessageBindings)
    addiu $t2, $t2, %lo(g_osEventMessageBindings)
    addu $t2, $t2, $a0
    lw $t1, 0x0($t2)
    nop
    beqz $t1, .Lsend_mesg_C4
    nop
    lw $t3, 0x8($t1)
    lw $t4, 0x10($t1)
    nop
    slt $at, $t3, $t4
    beqz $at, .Lsend_mesg_C4
    nop
    lw $t5, 0xC($t1)
    nop
    addu $t5, $t5, $t3
    div $zero, $t5, $t4
    bnez $t4, .Lsend_mesg_54
    nop
    break 7
.Lsend_mesg_54:
    addiu $at, $zero, -0x1
    bne $t4, $at, .Lsend_mesg_6C
    lui $at, 0x8000
    bne $t5, $at, .Lsend_mesg_6C
    nop
    break 6
.Lsend_mesg_6C:
    mfhi $t5
    lw $t4, 0x14($t1)
    sll $t5, $t5, 2
    addu $t4, $t4, $t5
    lw $t5, 0x4($t2)
    nop
    sw $t5, 0x0($t4)
    addiu $t2, $t3, 0x1
    sw $t2, 0x8($t1)
    lw $t2, 0x0($t1)
    nop
    lw $t3, 0x0($t2)
    nop
    beqz $t3, .Lsend_mesg_C4
    nop
    jal __osPopThread
    addu $a0, $t1, $zero
    addu $t2, $v0, $zero
    lui $a0, %hi(g_osRunnableThreadQueue)
    addiu $a0, $a0, %lo(g_osRunnableThreadQueue)
    jal __osEnqueueThread
    addu $a1, $t2, $zero
.Lsend_mesg_C4:
    jr $s2
    nop
.Lsend_mesg_CC:
    lui $at, 0x3000
    and $t1, $t0, $at
    srl $t1, $t1, 28
    addiu $t2, $zero, 0x1
    bne $t1, $t2, send_mesg - 0x30
    addiu $t1, $zero, 0x1
    sw $t1, 0x18($k0)
    lw $k1, 0x118($k0)
    nop
    lui $at, 0x2000
    or $k1, $k1, $at
    sw $k1, 0x118($k0)
    bgez $zero, send_mesg - 0x4C
    nop

/* __osEnqueueAndYield.s */
.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl __osEnqueueAndYield
__osEnqueueAndYield:
    lui $a1, %hi(g_osRunningThread)
    lw $a1, %lo(g_osRunningThread)($a1)
    mfc0 $t0, $12
    nop
    ori $t0, $t0, 0x2
    sw $t0, 0x118($a1)
    sd $s0, 0x98($a1)
    sd $s1, 0xA0($a1)
    sd $s2, 0xA8($a1)
    sd $s3, 0xB0($a1)
    sd $s4, 0xB8($a1)
    sd $s5, 0xC0($a1)
    sd $s6, 0xC8($a1)
    sd $s7, 0xD0($a1)
    sd $gp, 0xE8($a1)
    sd $sp, 0xF0($a1)
    sd $fp, 0xF8($a1)
    sd $ra, 0x100($a1)
    sw $ra, 0x11C($a1)
    lw $k1, 0x18($a1)
    nop
    beqz $k1, .LSaveThreadStatusMerge
    nop
    cfc1 $k1, $31
    nop
    sw $k1, 0x12C($a1)
    sdc1 $f0, 0x130($a1)
    sdc1 $f2, 0x138($a1)
    sdc1 $f4, 0x140($a1)
    sdc1 $f8, 0x150($a1)
    sdc1 $f10, 0x158($a1)
    sdc1 $f12, 0x160($a1)
    sdc1 $f14, 0x168($a1)
    sdc1 $f16, 0x170($a1)
    sdc1 $f18, 0x178($a1)
    sdc1 $f20, 0x180($a1)
    sdc1 $f22, 0x188($a1)
    sdc1 $f24, 0x190($a1)
    sdc1 $f26, 0x198($a1)
    sdc1 $f28, 0x1A0($a1)
    sdc1 $f30, 0x1A8($a1)
    lw $k1, 0x118($a1)
    nop
    lui $at, 0x400
    and $k1, $k1, $at
    beqz $k1, .LSaveThreadStatusMerge
    nop
    sdc1 $f1, 0x1B0($a1)
    sdc1 $f3, 0x1B8($a1)
    sdc1 $f5, 0x1C0($a1)
    sdc1 $f7, 0x1C8($a1)
    sdc1 $f9, 0x1D0($a1)
    sdc1 $f11, 0x1D8($a1)
    sdc1 $f13, 0x1E0($a1)
    sdc1 $f15, 0x1E8($a1)
    sdc1 $f17, 0x1F0($a1)
    sdc1 $f19, 0x1F8($a1)
    sdc1 $f21, 0x200($a1)
    sdc1 $f23, 0x208($a1)
    sdc1 $f25, 0x210($a1)
    sdc1 $f27, 0x218($a1)
    sdc1 $f29, 0x220($a1)
    sdc1 $f31, 0x228($a1)
.LSaveThreadStatusMerge:
    lw $k1, 0x118($a1)
    nop
    andi $t1, $k1, 0xFF00
    beqz $t1, .LSaveThreadMiMask
    nop
    lui $t0, %hi(g_globalInterruptMask)
    addiu $t0, $t0, %lo(g_globalInterruptMask)
    nop
    lw $t0, 0x0($t0)
    nop
    addiu $at, $zero, -0x1
    xor $t0, $t0, $at
    andi $t0, $t0, 0xFF00
    or $t1, $t1, $t0
    lui $at, 0xFFFF
    ori $at, $at, 0xFF
    and $k1, $k1, $at
    or $k1, $k1, $t1
    sw $k1, 0x118($a1)
.LSaveThreadMiMask:
    lui $k1, %hi(MI_INTERRUPT_MASK_REGISTER)
    lw $k1, %lo(MI_INTERRUPT_MASK_REGISTER)($k1)
    nop
    beqz $k1, .LSaveThreadEnqueueCheck
    nop
    lui $k0, %hi(g_globalInterruptMask)
    addiu $k0, $k0, %lo(g_globalInterruptMask)
    lw $k0, 0x0($k0)
    nop
    srl $k0, $k0, 16
    addiu $at, $zero, -0x1
    xor $k0, $k0, $at
    lw $t0, 0x128($a1)
    andi $k0, $k0, 0x3F
    and $k0, $k0, $t0
    or $k1, $k1, $k0
.LSaveThreadEnqueueCheck:
    beqz $a0, .LSaveThreadDispatch
    sw $k1, 0x128($a1)
    jal __osEnqueueThread
    nop
.LSaveThreadDispatch:
    j __osDispatchThread

/* __osEnqueueThread.s */
.set noreorder
.set noat
.section .text
.globl __osEnqueueThread
__osEnqueueThread:
    addu $t9, $a0, $zero
    lw $t8, 0x0($a0)
    lw $t7, 0x4($a1)
    lw $t6, 0x4($t8)
    nop
    slt $at, $t6, $t7
    bnez $at, .L__osEnqueueThread_03C
    nop
.L__osEnqueueThread_020:
    addu $t9, $t8, $zero
    lw $t8, 0x0($t8)
    nop
    lw $t6, 0x4($t8)
    nop
    slt $at, $t6, $t7
    beqz $at, .L__osEnqueueThread_020
.L__osEnqueueThread_03C:
    lw $t8, 0x0($t9)
    sw $a1, 0x0($t9)
    sw $t8, 0x0($a1)
    jr $ra
    sw $a0, 0x8($a1)

/* __osPopThread.s */
.set noreorder
.set noat
.section .text
.globl __osPopThread
__osPopThread:
    lw $v0, 0x0($a0)
    nop
    lw $t9, 0x0($v0)
    sw $zero, 0x0($v0)
    jr $ra
    sw $t9, 0x0($a0)
