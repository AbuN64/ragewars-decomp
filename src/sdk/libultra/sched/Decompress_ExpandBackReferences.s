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
    j .Decompress_ReadControlBit
    andi $t7, $t7, 0x1
    addiu $v0, $zero, -0x1
    jr $ra
    nop
    addiu $v0, $zero, -0x2
    jr $ra
    nop
.Decompress_RefillBitsForAccumulateLongRun:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_AccumulateLongRun
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForAccumulateMatchLength:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_AccumulateMatchLength
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForTestMatchLength:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_TestMatchLength
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForAccumulateMatchEscape:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_AccumulateMatchEscape
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForTestOffsetFlag:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_TestOffsetFlag
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForAccumulateOffsetHigh:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_AccumulateOffsetHigh
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForTestOffsetEscape:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_TestOffsetEscape
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForAccumulateOffsetExtra:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_AccumulateOffsetExtra
    andi $t7, $t7, 0x1
.Decompress_StartLongRunBitCount:
    addiu $t0, $zero, 0x3
.Decompress_ReadLongRunBit:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForAccumulateLongRun
    nop
.Decompress_AccumulateLongRun:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
    addi $t0, $t0, -0x1
    bgez $t0, .Decompress_ReadLongRunBit
    nop
    addi $t1, $t1, 0x2
.Decompress_CopyLongRunWords:
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
    bgez $t1, .Decompress_CopyLongRunWords
    addi $a1, $a1, 0x4
    j .Decompress_ReadControlBit
    nop
.Decompress_ReadMatchLengthBit:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForAccumulateMatchLength
    nop
.Decompress_AccumulateMatchLength:
    addu $t0, $t0, $t0
    addu $t0, $t0, $t7
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForTestMatchLength
    nop
.Decompress_TestMatchLength:
    beq $zero, $t7, .Decompress_ReadOffsetFlagBit
    nop
    addi $t0, $t0, -0x1
    add $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForAccumulateMatchEscape
    nop
.Decompress_AccumulateMatchEscape:
    addu $t0, $t0, $t0
    addu $t0, $t0, $t7
    srl $t7, $t0, 16
    andi $t7, $t7, 0x1
    addi $t4, $t0, -0x9
    beq $zero, $t4, .Decompress_StartLongRunBitCount
    nop
.Decompress_ReadOffsetFlagBit:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForTestOffsetFlag
    nop
.Decompress_TestOffsetFlag:
    beq $zero, $t7, .Decompress_LoadOffsetLowByte
    nop
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForAccumulateOffsetHigh
    nop
.Decompress_AccumulateOffsetHigh:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForTestOffsetEscape
    nop
.Decompress_TestOffsetEscape:
    bne $zero, $t7, .Decompress_ReadShortOffsetBit
    nop
    bne $zero, $t1, .Decompress_SwapOffsetBytes
    nop
    addi $t1, $t1, 0x1
.Decompress_ReadOffsetExtraBit:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForAccumulateOffsetExtra
    nop
.Decompress_AccumulateOffsetExtra:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
.Decompress_SwapOffsetBytes:
    sll $t4, $t1, 8
    andi $t4, $t4, 0xFF00
    srl $t1, $t1, 8
    or $t1, $t1, $t4
.Decompress_LoadOffsetLowByte:
    andi $s3, $t1, 0xFF00
    lbu $t1, 0x0($v1)
    addiu $v1, $v1, 0x1
    or $t1, $t1, $s3
    addu $t6, $a1, $zero
    sub $t6, $t6, $t1
    addi $t6, $t6, -0x1
    andi $t7, $t0, 0x1
    srl $t0, $t0, 1
    beq $zero, $t7, .Decompress_CopyMatchRemainder
    nop
    lbu $t4, 0x0($t6)
    addi $t6, $t6, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
.Decompress_CopyMatchRemainder:
    addi $t0, $t0, -0x1
    bne $zero, $t1, .Decompress_CopyMatchBytePairs
    nop
    andi $s3, $t1, 0xFF00
    lbu $t1, 0x0($t6)
    nop
    or $t1, $t1, $s3
.Decompress_CopyRepeatedBytePairs:
    sb $t1, 0x0($a1)
    addi $t0, $t0, -0x1
    sb $t1, 0x1($a1)
    bgez $t0, .Decompress_CopyRepeatedBytePairs
    addi $a1, $a1, 0x2
    j .Decompress_ReadControlBit
    nop
.Decompress_CopyMatchBytePairs:
    lbu $s2, 0x1($t6)
    lbu $t4, 0x0($t6)
    sb $s2, 0x1($a1)
    sb $t4, 0x0($a1)
    addi $t6, $t6, 0x2
    addi $t0, $t0, -0x1
    bgez $t0, .Decompress_CopyMatchBytePairs
    addi $a1, $a1, 0x2
    j .Decompress_ReadControlBit
    nop
.Decompress_RefillBitsForTestBackReferenceFlag:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    bne $zero, $t7, .Decompress_BeginBackReference
    nop
.Decompress_CopyLiteralByte:
    lbu $t4, 0x0($v1)
    addi $v1, $v1, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
.Decompress_ReadControlBit:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    bne $zero, $t7, .Decompress_CheckBitBufferEmpty
    nop
    lbu $t4, 0x0($v1)
    addi $v1, $v1, 0x1
    sb $t4, 0x0($a1)
    addi $a1, $a1, 0x1
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    beq $zero, $t7, .Decompress_CopyLiteralByte
    nop
.Decompress_CheckBitBufferEmpty:
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForTestBackReferenceFlag
    nop
.Decompress_BeginBackReference:
    addiu $t0, $zero, 0x2
    addiu $t1, $zero, 0x0
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForTestMatchLengthFirstBit
    nop
.Decompress_TestMatchLengthFirstBit:
    beq $zero, $t7, .Decompress_ReadMatchLengthBit
    nop
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForTestMatchLengthSecondBit
    nop
.Decompress_TestMatchLengthSecondBit:
    beq $zero, $t7, .Decompress_LoadOffsetLowByte
    nop
    addi $t0, $t0, 0x1
    add $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForTestMatchLengthThirdBit
    nop
.Decompress_TestMatchLengthThirdBit:
    beq $zero, $t7, .Decompress_ReadOffsetFlagBit
    nop
    lbu $t0, 0x0($v1)
    addi $v1, $v1, 0x1
    nop
    beq $zero, $t0, .Decompress_ReadEndMarkerBit
    addi $t0, $t0, 0x8
    j .Decompress_ReadOffsetFlagBit
    nop
.Decompress_ReadShortOffsetBit:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForAccumulateShortOffset
    nop
.Decompress_AccumulateShortOffset:
    addu $t1, $t1, $t1
    addu $t1, $t1, $t7
    srl $t7, $t1, 16
    andi $t7, $t7, 0x1
    ori $t1, $t1, 0x4
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    beq $zero, $t2, .Decompress_RefillBitsForTestShortOffsetFlag
    nop
.Decompress_TestShortOffsetFlag:
    bne $zero, $t7, .Decompress_SwapOffsetBytes
    nop
    j .Decompress_ReadOffsetExtraBit
    nop
.Decompress_RefillBitsForTestMatchLengthFirstBit:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_TestMatchLengthFirstBit
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForTestMatchLengthSecondBit:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_TestMatchLengthSecondBit
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForTestMatchLengthThirdBit:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_TestMatchLengthThirdBit
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForAccumulateShortOffset:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_AccumulateShortOffset
    andi $t7, $t7, 0x1
.Decompress_RefillBitsForTestShortOffsetFlag:
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    j .Decompress_TestShortOffsetFlag
    andi $t7, $t7, 0x1
.Decompress_ReadEndMarkerBit:
    addu $t2, $t2, $t2
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
    andi $t2, $t2, 0xFF
    bne $zero, $t2, .Decompress_TestEndMarkerBit
    nop
    lbu $t2, 0x0($v1)
    addi $v1, $v1, 0x1
    addu $t2, $t2, $t2
    addu $t2, $t2, $t7
    srl $t7, $t2, 8
    andi $t7, $t7, 0x1
.Decompress_TestEndMarkerBit:
    bne $zero, $t7, .Decompress_ReadControlBit
    nop
    lhu $t5, 0x0($t3)
    addi $t3, $t3, 0x2
    beq $zero, $t5, .Decompress_SkipTrailerStore
    nop
.Decompress_CopyTrailerBytes:
    lh $s0, 0x0($t3)
    addi $t3, $t3, 0x2
    sb $s0, 0x0($a1)
    addi $a1, $a1, 0x1
    addi $t5, $t5, -0x1
    bne $zero, $t5, .Decompress_CopyTrailerBytes
    nop
.Decompress_SkipTrailerStore:
    j .Decompress_ReturnSuccess
    nop
    sw $s0, 0x0($t3)
.Decompress_ReturnSuccess:
    addiu $v0, $zero, 0x0
    jr $ra
    nop
