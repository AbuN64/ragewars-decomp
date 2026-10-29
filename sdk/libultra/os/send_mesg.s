.set noreorder
.set noat
.section .text
.globl send_mesg
send_mesg:
    addu $s2, $ra, $zero
    lui $t2, %hi(g_osEventMessageBindings)
    addiu $t2, $t2, %lo(g_osEventMessageBindings)
    addu $t2, $t2, $a0
    lw $t1, 0x0($t2)
    nop
    beqz $t1, .Lsend_mesg_0C4
    nop
    lw $t3, 0x8($t1)
    lw $t4, 0x10($t1)
    nop
    slt $at, $t3, $t4
    beqz $at, .Lsend_mesg_0C4
    nop
    lw $t5, 0xC($t1)
    nop
    addu $t5, $t5, $t3
    div $zero, $t5, $t4
    bnez $t4, .Lsend_mesg_054
    nop
    break 7
.Lsend_mesg_054:
    addiu $at, $zero, -0x1
    bne $t4, $at, .Lsend_mesg_06C
    lui $at, 0x8000
    bne $t5, $at, .Lsend_mesg_06C
    nop
    break 6
.Lsend_mesg_06C:
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
    beqz $t3, .Lsend_mesg_0C4
    nop
    jal __osPopThread
    addu $a0, $t1, $zero
    addu $t2, $v0, $zero
    lui $a0, %hi(g_osRunnableThreadQueue)
    addiu $a0, $a0, %lo(g_osRunnableThreadQueue)
    jal __osEnqueueThread
    addu $a1, $t2, $zero
.Lsend_mesg_0C4:
    jr $s2
    nop
    lui $at, 0x3000
    and $t1, $t0, $at
    srl $t1, $t1, 28
    addiu $t2, $zero, 0x1
.if VERSION_US
    bne $t1, $t2, __osExceptionPreamble+0x5C8
.else
    bne $t1, $t2, __osExceptionPreamble+0x5D0
.endif
    addiu $t1, $zero, 0x1
    sw $t1, 0x18($k0)
    lw $k1, 0x118($k0)
    nop
    lui $at, 0x2000
    or $k1, $k1, $at
    sw $k1, 0x118($k0)
.if VERSION_US
    bgez $zero, __osExceptionPreamble+0x5AC
.else
    bgez $zero, __osExceptionPreamble+0x5B4
.endif
    nop
