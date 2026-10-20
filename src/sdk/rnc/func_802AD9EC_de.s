.set noreorder
.set noat
.section .text
.globl func_802AD9EC_de
func_802AD9EC_de:
    addiu $t5, $zero, 0x0
    lui $t3, %hi(D_80147190)
    addiu $t3, $t3, %lo(D_80147190)
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
    j .Lfunc_802AD9EC_de_410
    andi $t7, $t7, 0x1
    addiu $v0, $zero, -0x1
    jr $ra
    nop
    addiu $v0, $zero, -0x2
    jr $ra
    nop
.Lfunc_802AD9EC_de_0D4:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_1D0
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_0F0:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_240
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_10C:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_260
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_128:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_284
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_144:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_2B8
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_160:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_2D8
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_17C:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_2F8
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_198:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_324
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_1B4:
    addiu $t0, $zero, 0x3
.Lfunc_802AD9EC_de_1B8:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_0D4
    nop
.Lfunc_802AD9EC_de_1D0:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
    addi $t0, $t0, -0x1
    bgez $t0, .Lfunc_802AD9EC_de_1B8
    nop
    addi $t1, $t1, 0x2
.Lfunc_802AD9EC_de_1F0:
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
    bgez $t1, .Lfunc_802AD9EC_de_1F0
    addi $a1, $a1, 0x4
    j .Lfunc_802AD9EC_de_410
    nop
.Lfunc_802AD9EC_de_228:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_0F0
    nop
.Lfunc_802AD9EC_de_240:
    addu $t0, $t0, $t0
    addu $t0, $t0, $t7
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_10C
    nop
.Lfunc_802AD9EC_de_260:
    beq $zero, $t7, .Lfunc_802AD9EC_de_2A0
    nop
    addi $t0, $t0, -0x1
    add $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_128
    nop
.Lfunc_802AD9EC_de_284:
    addu $t0, $t0, $t0
    addu $t0, $t0, $t7
    srl $t7, $t0, 16
    andi $t7, $t7, 0x1
    addi $t4, $t0, -0x9
    beq $zero, $t4, .Lfunc_802AD9EC_de_1B4
    nop
.Lfunc_802AD9EC_de_2A0:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_144
    nop
.Lfunc_802AD9EC_de_2B8:
    beq $zero, $t7, .Lfunc_802AD9EC_de_344
    nop
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_160
    nop
.Lfunc_802AD9EC_de_2D8:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_17C
    nop
.Lfunc_802AD9EC_de_2F8:
    bne $zero, $t7, .Lfunc_802AD9EC_de_4DC
    nop
    bne $zero, $t1, .Lfunc_802AD9EC_de_334
    nop
    addi $t1, $t1, 0x1
.Lfunc_802AD9EC_de_30C:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_198
    nop
.Lfunc_802AD9EC_de_324:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_334:
    sll $t4, $t1, 8
    andi $t4, $t4, 0xFF00
    srl $t1, $t1, 8
    or $t1, $t1, $t4
.Lfunc_802AD9EC_de_344:
    andi $s3, $t1, 0xFF00
    lbu $t1, 0x0($v1)
    addiu $v1, $v1, 0x1
    or $t1, $t1, $s3
    addu $t6, $a1, $zero
    sub $t6, $t6, $t1
    addi $t6, $t6, -0x1
    andi $t7, $t0, 0x1
    srl $t0, $t0, 1
    beq $zero, $t7, .Lfunc_802AD9EC_de_380
    nop
    lbu $t4, 0x0($t6)
    addi $t6, $t6, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
.Lfunc_802AD9EC_de_380:
    addi $t0, $t0, -0x1
    bne $zero, $t1, .Lfunc_802AD9EC_de_3B8
    nop
    andi $s3, $t1, 0xFF00
    lbu $t1, 0x0($t6)
    nop
    or $t1, $t1, $s3
.Lfunc_802AD9EC_de_39C:
    sb $t1, 0x0($a1)
    addi $t0, $t0, -0x1
    sb $t1, 0x1($a1)
    bgez $t0, .Lfunc_802AD9EC_de_39C
    addi $a1, $a1, 0x2
    j .Lfunc_802AD9EC_de_410
    nop
.Lfunc_802AD9EC_de_3B8:
    lbu $s2, 0x1($t6)
    lbu $t4, 0x0($t6)
    sb $s2, 0x1($a1)
    sb $t4, 0x0($a1)
    addi $t6, $t6, 0x2
    addi $t0, $t0, -0x1
    bgez $t0, .Lfunc_802AD9EC_de_3B8
    addi $a1, $a1, 0x2
    j .Lfunc_802AD9EC_de_410
    nop
.Lfunc_802AD9EC_de_3E0:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    bne $zero, $t7, .Lfunc_802AD9EC_de_454
    nop
.Lfunc_802AD9EC_de_400:
    lbu $t4, 0x0($v1)
    addi $v1, $v1, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
.Lfunc_802AD9EC_de_410:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    bne $zero, $t7, .Lfunc_802AD9EC_de_448
    nop
    lbu $t4, 0x0($v1)
    addi $v1, $v1, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    beq $zero, $t7, .Lfunc_802AD9EC_de_400
    nop
.Lfunc_802AD9EC_de_448:
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_3E0
    nop
.Lfunc_802AD9EC_de_454:
    addiu $t0, $zero, 0x2
    addiu $t1, $zero, 0x0
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_530
    nop
.Lfunc_802AD9EC_de_474:
    beq $zero, $t7, .Lfunc_802AD9EC_de_228
    nop
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_54C
    nop
.Lfunc_802AD9EC_de_494:
    beq $zero, $t7, .Lfunc_802AD9EC_de_344
    nop
    addi $t0, $t0, 0x1
    add $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_568
    nop
.Lfunc_802AD9EC_de_4B8:
    beq $zero, $t7, .Lfunc_802AD9EC_de_2A0
    nop
    lbu $t0, 0x0($v1)
    addi $v1, $v1, 0x1
    nop
    beq $zero, $t0, .Lfunc_802AD9EC_de_5BC
    addi $t0, $t0, 0x8
    j .Lfunc_802AD9EC_de_2A0
    nop
.Lfunc_802AD9EC_de_4DC:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_584
    nop
.Lfunc_802AD9EC_de_4F4:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
    ori $t1, $t1, 0x4
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Lfunc_802AD9EC_de_5A0
    nop
.Lfunc_802AD9EC_de_520:
    bne $zero, $t7, .Lfunc_802AD9EC_de_334
    nop
    j .Lfunc_802AD9EC_de_30C
    nop
.Lfunc_802AD9EC_de_530:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_474
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_54C:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_494
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_568:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_4B8
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_584:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_4F4
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_5A0:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Lfunc_802AD9EC_de_520
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_5BC:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    bne $zero, $t2, .Lfunc_802AD9EC_de_5EC
    nop
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
.Lfunc_802AD9EC_de_5EC:
    bne $zero, $t7, .Lfunc_802AD9EC_de_410
    nop
    lhu $t5, 0x0($t3)
    addi $t3, $t3, 0x2
    beq $zero, $t5, .Lfunc_802AD9EC_de_620
    nop
.Lfunc_802AD9EC_de_604:
    lh $s0, 0x0($t3)
    addi $t3, $t3, 0x2
    sb $s0, 0x0($a1)
    addi $a1, $a1, 0x1
    addi $t5, $t5, -0x1
    bne $zero, $t5, .Lfunc_802AD9EC_de_604
    nop
.Lfunc_802AD9EC_de_620:
    j .Lfunc_802AD9EC_de_62C
    nop
    sw $s0, 0x0($t3)
.Lfunc_802AD9EC_de_62C:
    addiu $v0, $zero, 0x0
    jr $ra
    nop
