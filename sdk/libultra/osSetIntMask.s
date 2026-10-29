.set noreorder
.set noat
.section .text
.globl osSetIntMask
osSetIntMask:
    mfc0 $t4, $12
    lui $t0, %hi(g_audioAbortdisktransferDataConstantWords)
    addiu $t0, $t0, %lo(g_audioAbortdisktransferDataConstantWords)
    andi $v0, $t4, 0xFF01
    lw $t3, 0x0($t0)
    nop
    addiu $at, $zero, -0x1
    xor $t0, $t3, $at
    andi $t0, $t0, 0xFF00
    or $v0, $v0, $t0
    lui $t2, %hi(MI_INTERRUPT_MASK_REGISTER)
    lw $t2, %lo(MI_INTERRUPT_MASK_REGISTER)($t2)
    nop
    beqz $t2, .LosSetIntMask_04C
    srl $t1, $t3, 16
    addiu $at, $zero, -0x1
    xor $t1, $t1, $at
    andi $t1, $t1, 0x3F
    or $t2, $t2, $t1
.LosSetIntMask_04C:
    sll $t2, $t2, 16
    or $v0, $v0, $t2
    lui $at, 0x3F
    and $t0, $a0, $at
    and $t0, $t0, $t3
    srl $t0, $t0, 15
    lui $at, %hi(g_interruptMaskCommandTable)
    addu $at, $at, $t0
    lhu $t2, %lo(g_interruptMaskCommandTable)($at)
    lui $at, %hi(MI_INTERRUPT_MASK_REGISTER)
    sw $t2, %lo(MI_INTERRUPT_MASK_REGISTER)($at)
    andi $t0, $a0, 0xFF01
    andi $t1, $t3, 0xFF00
    and $t0, $t0, $t1
    lui $at, 0xFFFF
    ori $at, $at, 0xFF
    and $t4, $t4, $at
    or $t4, $t4, $t0
    mtc0 $t4, $12
    nop
    nop
    jr $ra
    nop
