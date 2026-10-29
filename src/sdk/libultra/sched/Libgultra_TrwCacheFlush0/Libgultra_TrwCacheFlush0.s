

/* Libsn_InstallDebuggerExceptionHooks.s */
.set noreorder
.set noat
.section .text
.globl Libsn_InstallDebuggerExceptionHooks
Libsn_InstallDebuggerExceptionHooks:
    addi $sp, $sp, -0x8
    sw $ra, 0x0($sp)
    lui $t0, %hi(Libgultra_DebugExceptionVectorTemplateAddress)
    addiu $t0, $t0, %lo(Libgultra_DebugExceptionVectorTemplateAddress)
    lui $t1, %hi(Libgultra_SavedExceptionVectorAddress)
    addiu $t1, $t1, %lo(Libgultra_SavedExceptionVectorAddress)
    lui $t2, 0x8000
    ori $t2, $t2, 0x180
    lui $t3, %hi(Libgultra_SavedExceptionVectorAddress)
    addiu $t3, $t3, %lo(Libgultra_SavedExceptionVectorAddress)
.LLibsn_InstallDebuggerExceptionHooks_copyGeneralVector:
    lw $t4, 0x0($t2)
    lw $t5, 0x0($t0)
    addiu $t0, $t0, 0x4
    sw $t4, 0x0($t1)
    addiu $t1, $t1, 0x4
    sw $t5, 0x0($t2)
    bne $t0, $t3, .LLibsn_InstallDebuggerExceptionHooks_copyGeneralVector
    addiu $t2, $t2, 0x4
    lui $t0, %hi(Libgultra_DebugTlbVectorTemplateAddress)
    addiu $t0, $t0, %lo(Libgultra_DebugTlbVectorTemplateAddress)
    lui $t1, %hi(Libgultra_SavedTlbVectorAddress)
    addiu $t1, $t1, %lo(Libgultra_SavedTlbVectorAddress)
    lui $t2, %hi(g_tlbMissExceptionVector)
    lui $t3, %hi(Libgultra_SavedTlbVectorAddress)
    addiu $t3, $t3, %lo(Libgultra_SavedTlbVectorAddress)
.LLibsn_InstallDebuggerExceptionHooks_copyTlbVector:
    lw $t4, %lo(g_tlbMissExceptionVector)($t2)
    lw $t5, 0x0($t0)
    addiu $t0, $t0, 0x4
    sw $t4, 0x0($t1)
    addiu $t1, $t1, 0x4
    sw $t5, 0x0($t2)
    bne $t0, $t3, .LLibsn_InstallDebuggerExceptionHooks_copyTlbVector
    addiu $t2, $t2, 0x4
    jal Libgultra_TrwCacheFlush0
    nop
    jal Libgultra_TrwCacheFlush1
    nop
    addiu $t0, $zero, -0x802
    lui $at, %hi(g_debugExceptionStatusMask)
    sw $t0, %lo(g_debugExceptionStatusMask)($at)
    lw $ra, 0x0($sp)
    jr $ra
    addi $sp, $sp, 0x8

/* Libgultra_TrwCacheFlush0.s */
.set noreorder
.set noat
.section .text
.globl Libgultra_TrwCacheFlush0
Libgultra_TrwCacheFlush0:
    lui $t0, %hi(g_debugDataCacheLastIndex)
    addiu $t1, $t0, %lo(g_debugDataCacheLastIndex)
.LLibgultra_TrwCacheFlush0_008:
    cache 0x01, 0x0($t0)
    bne $t0, $t1, .LLibgultra_TrwCacheFlush0_008
    addiu $t0, $t0, 0x10
    jr $ra
    nop

/* Libgultra_TrwCacheFlush1.s */
.set noreorder
.set noat
.section .text
.globl Libgultra_TrwCacheFlush1
Libgultra_TrwCacheFlush1:
    lui $t0, %hi(g_debugInstructionCacheLastIndex)
    addiu $t1, $t0, %lo(g_debugInstructionCacheLastIndex)
.LLibgultra_TrwCacheFlush1_008:
    cache 0x00, 0x0($t0)
    bne $t0, $t1, .LLibgultra_TrwCacheFlush1_008
    addiu $t0, $t0, 0x20
    jr $ra
    nop

/* Libgultra_TrwGetSr.s */
.set noreorder
.set noat
.section .text
.globl Libgultra_TrwGetSr
Libgultra_TrwGetSr:
    mfc0 $v0, $12
    jr $ra
    nop
