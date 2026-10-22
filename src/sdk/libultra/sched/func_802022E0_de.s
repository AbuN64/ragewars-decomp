.set noreorder
.set noat
.section .text
.globl func_802022E0_de
func_802022E0_de:
    addi $sp, $sp, -0x8
    sw $ra, 0x0($sp)
    lui $t0, %hi(D_00202270)
    addiu $t0, $t0, %lo(D_00202270)
    lui $t1, %hi(D_00202284)
    addiu $t1, $t1, %lo(D_00202284)
    lui $t2, 0x8000
    ori $t2, $t2, 0x180
    lui $t3, %hi(D_00202284)
    addiu $t3, $t3, %lo(D_00202284)
.Lfunc_802022E0_de_028:
    lw $t4, 0x0($t2)
    lw $t5, 0x0($t0)
    addiu $t0, $t0, 0x4
    sw $t4, 0x0($t1)
    addiu $t1, $t1, 0x4
    sw $t5, 0x0($t2)
    bne $t0, $t3, .Lfunc_802022E0_de_028
    addiu $t2, $t2, 0x4
    lui $t0, %hi(D_002022A8)
    addiu $t0, $t0, %lo(D_002022A8)
    lui $t1, %hi(D_002022BC)
    addiu $t1, $t1, %lo(D_002022BC)
    lui $t2, %hi(D_80000000)
    lui $t3, %hi(D_002022BC)
    addiu $t3, $t3, %lo(D_002022BC)
.Lfunc_802022E0_de_064:
    lw $t4, %lo(D_80000000)($t2)
    lw $t5, 0x0($t0)
    addiu $t0, $t0, 0x4
    sw $t4, 0x0($t1)
    addiu $t1, $t1, 0x4
    sw $t5, 0x0($t2)
    bne $t0, $t3, .Lfunc_802022E0_de_064
    addiu $t2, $t2, 0x4
    jal Libgultra_TrwCacheFlush0
    nop
    jal Libgultra_TrwCacheFlush1
    nop
    addiu $t0, $zero, -0x802
    lui $at, %hi(D_800F3468)
    sw $t0, %lo(D_800F3468)($at)
    lw $ra, 0x0($sp)
    jr $ra
    addi $sp, $sp, 0x8
