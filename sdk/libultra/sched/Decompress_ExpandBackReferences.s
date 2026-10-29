.set noreorder
.set noat
.section .text
.globl Decompress_ExpandBackReferences
Decompress_ExpandBackReferences:
    addiu $t5, $zero, 0x0
    lui $t3, %hi(g_backReferenceOutputByteCount)
    addiu $t3, $t3, %lo(g_backReferenceOutputByteCount)
    addiu $t6, $t6, 0x4
    lbu $t5, 0x0($t6)
    lbu $t4, 0x1($t6)
    lbu $s2, 0x2($t6)
    lbu $t7, 0x3($t6)
    sll $t5, $t5, 24
    sll $t4, $t4, 16
    sll $s2, $s2, 8
    or $t5, $t5, $t4
    or $t5, $t5, $s2
    or $t5, $t5, $t7
    addiu $t6, $t6, 0x4
    sw $t5, 0x0($t3)
    addu $v1, $t6, $zero
    addi $v1, $v1, 0xA
    addu $a1, $s1, $zero
    addu $a2, $a1, $zero
    addu $a2, $a2, $t5
    lbu $t5, 0x0($t6)
    lbu $t4, 0x1($t6)
    lbu $s2, 0x2($t6)
    lbu $t7, 0x3($t6)
    sll $t5, $t5, 24
    sll $t4, $t4, 16
    sll $s2, $s2, 8
    or $t5, $t5, $t4
    or $t5, $t5, $s2
    or $t5, $t5, $t7
    addiu $t6, $t6, 0x4
    addu $a0, $v1, $zero
    add $a0, $a0, $t5
    addi $t3, $t3, -0x2
    sh $zero, 0x0($t3)
    lui $t2, 0xFFFF
    ori $t2, $t2, 0xFF00
    addiu $t7, $zero, 0x1
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_410
    andi $t7, $t7, 0x1
    addiu $v0, $zero, -0x1
    jr $ra
    nop
    addiu $v0, $zero, -0x2
    jr $ra
    nop
.LDecompress_ExpandBackReferences_0D4:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_1D0
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_0F0:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_240
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_10C:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_260
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_128:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_284
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_144:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_2B8
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_160:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_2D8
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_17C:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_2F8
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_198:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_324
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_1B4:
    addiu $t0, $zero, 0x3
.LDecompress_ExpandBackReferences_1B8:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_0D4
    nop
.LDecompress_ExpandBackReferences_1D0:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
    addi $t0, $t0, -0x1
    bgez $t0, .LDecompress_ExpandBackReferences_1B8
    nop
    addi $t1, $t1, 0x2
.LDecompress_ExpandBackReferences_1F0:
    lbu $t4, 0x0($v1)
    lbu $s2, 0x1($v1)
    sb $t4, 0x0($a1)
    sb $s2, 0x1($a1)
    lbu $t4, 0x2($v1)
    lbu $s2, 0x3($v1)
    sb $t4, 0x2($a1)
    sb $s2, 0x3($a1)
    addiu $v1, $v1, 0x4
    addi $t1, $t1, -0x1
    bgez $t1, .LDecompress_ExpandBackReferences_1F0
    addi $a1, $a1, 0x4
    j .LDecompress_ExpandBackReferences_410
    nop
.LDecompress_ExpandBackReferences_228:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_0F0
    nop
.LDecompress_ExpandBackReferences_240:
    addu $t0, $t0, $t0
    addu $t0, $t0, $t7
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_10C
    nop
.LDecompress_ExpandBackReferences_260:
    beq $zero, $t7, .LDecompress_ExpandBackReferences_2A0
    nop
    addi $t0, $t0, -0x1
    add $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_128
    nop
.LDecompress_ExpandBackReferences_284:
    addu $t0, $t0, $t0
    addu $t0, $t0, $t7
    srl $t7, $t0, 16
    andi $t7, $t7, 0x1
    addi $t4, $t0, -0x9
    beq $zero, $t4, .LDecompress_ExpandBackReferences_1B4
    nop
.LDecompress_ExpandBackReferences_2A0:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_144
    nop
.LDecompress_ExpandBackReferences_2B8:
    beq $zero, $t7, .LDecompress_ExpandBackReferences_344
    nop
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_160
    nop
.LDecompress_ExpandBackReferences_2D8:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_17C
    nop
.LDecompress_ExpandBackReferences_2F8:
    bne $zero, $t7, .LDecompress_ExpandBackReferences_4DC
    nop
    bne $zero, $t1, .LDecompress_ExpandBackReferences_334
    nop
    addi $t1, $t1, 0x1
.LDecompress_ExpandBackReferences_30C:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_198
    nop
.LDecompress_ExpandBackReferences_324:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_334:
    sll $t4, $t1, 8
    andi $t4, $t4, 0xFF00
    srl $t1, $t1, 8
    or $t1, $t1, $t4
.LDecompress_ExpandBackReferences_344:
    andi $s3, $t1, 0xFF00
    lbu $t1, 0x0($v1)
    addiu $v1, $v1, 0x1
    or $t1, $t1, $s3
    addu $t6, $a1, $zero
    sub $t6, $t6, $t1
    addi $t6, $t6, -0x1
    andi $t7, $t0, 0x1
    srl $t0, $t0, 1
    beq $zero, $t7, .LDecompress_ExpandBackReferences_380
    nop
    lbu $t4, 0x0($t6)
    addi $t6, $t6, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
.LDecompress_ExpandBackReferences_380:
    addi $t0, $t0, -0x1
    bne $zero, $t1, .LDecompress_ExpandBackReferences_3B8
    nop
    andi $s3, $t1, 0xFF00
    lbu $t1, 0x0($t6)
    nop
    or $t1, $t1, $s3
.LDecompress_ExpandBackReferences_39C:
    sb $t1, 0x0($a1)
    addi $t0, $t0, -0x1
    sb $t1, 0x1($a1)
    bgez $t0, .LDecompress_ExpandBackReferences_39C
    addi $a1, $a1, 0x2
    j .LDecompress_ExpandBackReferences_410
    nop
.LDecompress_ExpandBackReferences_3B8:
    lbu $s2, 0x1($t6)
    lbu $t4, 0x0($t6)
    sb $s2, 0x1($a1)
    sb $t4, 0x0($a1)
    addi $t6, $t6, 0x2
    addi $t0, $t0, -0x1
    bgez $t0, .LDecompress_ExpandBackReferences_3B8
    addi $a1, $a1, 0x2
    j .LDecompress_ExpandBackReferences_410
    nop
.LDecompress_ExpandBackReferences_3E0:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    bne $zero, $t7, .LDecompress_ExpandBackReferences_454
    nop
.LDecompress_ExpandBackReferences_400:
    lbu $t4, 0x0($v1)
    addi $v1, $v1, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
.LDecompress_ExpandBackReferences_410:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    bne $zero, $t7, .LDecompress_ExpandBackReferences_448
    nop
    lbu $t4, 0x0($v1)
    addi $v1, $v1, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    beq $zero, $t7, .LDecompress_ExpandBackReferences_400
    nop
.LDecompress_ExpandBackReferences_448:
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_3E0
    nop
.LDecompress_ExpandBackReferences_454:
    addiu $t0, $zero, 0x2
    addiu $t1, $zero, 0x0
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_530
    nop
.LDecompress_ExpandBackReferences_474:
    beq $zero, $t7, .LDecompress_ExpandBackReferences_228
    nop
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_54C
    nop
.LDecompress_ExpandBackReferences_494:
    beq $zero, $t7, .LDecompress_ExpandBackReferences_344
    nop
    addi $t0, $t0, 0x1
    add $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_568
    nop
.LDecompress_ExpandBackReferences_4B8:
    beq $zero, $t7, .LDecompress_ExpandBackReferences_2A0
    nop
    lbu $t0, 0x0($v1)
    addi $v1, $v1, 0x1
    nop
    beq $zero, $t0, .LDecompress_ExpandBackReferences_5BC
    addi $t0, $t0, 0x8
    j .LDecompress_ExpandBackReferences_2A0
    nop
.LDecompress_ExpandBackReferences_4DC:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_584
    nop
.LDecompress_ExpandBackReferences_4F4:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
    ori $t1, $t1, 0x4
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .LDecompress_ExpandBackReferences_5A0
    nop
.LDecompress_ExpandBackReferences_520:
    bne $zero, $t7, .LDecompress_ExpandBackReferences_334
    nop
    j .LDecompress_ExpandBackReferences_30C
    nop
.LDecompress_ExpandBackReferences_530:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_474
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_54C:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_494
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_568:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_4B8
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_584:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_4F4
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_5A0:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .LDecompress_ExpandBackReferences_520
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_5BC:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    bne $zero, $t2, .LDecompress_ExpandBackReferences_5EC
    nop
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
.LDecompress_ExpandBackReferences_5EC:
    bne $zero, $t7, .LDecompress_ExpandBackReferences_410
    nop
    lhu $t5, 0x0($t3)
    addi $t3, $t3, 0x2
    beq $zero, $t5, .LDecompress_ExpandBackReferences_620
    nop
.LDecompress_ExpandBackReferences_604:
    lh $s0, 0x0($t3)
    addi $t3, $t3, 0x2
    sb $s0, 0x0($a1)
    addi $a1, $a1, 0x1
    addi $t5, $t5, -0x1
    bne $zero, $t5, .LDecompress_ExpandBackReferences_604
    nop
.LDecompress_ExpandBackReferences_620:
    j .LDecompress_ExpandBackReferences_62C
    nop
    sw $s0, 0x0($t3)
.LDecompress_ExpandBackReferences_62C:
    addiu $v0, $zero, 0x0
    jr $ra
    nop
