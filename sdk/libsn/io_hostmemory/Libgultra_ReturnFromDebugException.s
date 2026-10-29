.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl Libgultra_ReturnFromDebugException
Libgultra_ReturnFromDebugException:
    lw $at, 0x33C($k0)
    nop
    bnez $at, .LLibgultra_ReturnFromDebugException_13C
    nop
    addiu $at, $zero, 0x64
.LLibgultra_ReturnFromDebugException_014:
    bnez $at, .LLibgultra_ReturnFromDebugException_014
    addi $at, $at, -0x1
    lui $at, 0xA460
    ori $at, $at, 0x10
.LLibgultra_ReturnFromDebugException_024:
    lw $v0, 0x0($at)
    nop
    andi $v0, $v0, 0x3
    bnez $v0, .LLibgultra_ReturnFromDebugException_024
    nop
    lui $at, %hi(g_debugCartridgeExceptionCheckRegister)
    lw $at, %lo(g_debugCartridgeExceptionCheckRegister)($at)
    nop
    beqz $at, .LLibgultra_ReturnFromDebugException_13C
    nop
    bgez $zero, Libgultra_TrwExceptionHandler+0x1B8
    nop
    addiu $at, $zero, -0x1
    j Libgultra_TrwExceptionHandler+0x1B0
    nop
    addiu $at, $zero, -0x1
    j Libgultra_TrwExceptionHandler+0x1B0
    nop
    j Libgultra_TrwExceptionHandler+0x1AC
    nop
    sd $v1, 0x18($k0)
    sd $a0, 0x20($k0)
    sd $ra, 0xF8($k0)
    bal .LLibgultra_ReturnFromDebugException_098
    nop
    ld $ra, 0xF8($k0)
    ld $a0, 0x20($k0)
    bgez $zero, .LLibgultra_ReturnFromDebugException_13C
    ld $v1, 0x18($k0)
.LLibgultra_ReturnFromDebugException_098:
    lui $v1, 0x8000
    ori $v1, $v1, 0x180
    lui $v0, %hi(Libgultra_SavedExceptionVectorAddress)
    addiu $v0, $v0, %lo(Libgultra_SavedExceptionVectorAddress)
    addi $a0, $v0, 0x14
.LLibgultra_ReturnFromDebugException_0AC:
    lw $at, 0x0($v0)
    addi $v0, $v0, 0x4
    sw $at, 0x0($v1)
    addi $v1, $v1, 0x4
    bne $v0, $a0, .LLibgultra_ReturnFromDebugException_0AC
    nop
    lui $v1, %hi(g_tlbMissExceptionVector)
    lui $v0, %hi(Libgultra_SavedTlbVectorAddress)
    addiu $v0, $v0, %lo(Libgultra_SavedTlbVectorAddress)
    addi $a0, $v0, 0x14
.LLibgultra_ReturnFromDebugException_0D4:
    lw $at, 0x0($v0)
    addi $v0, $v0, 0x4
    sw $at, %lo(g_tlbMissExceptionVector)($v1)
    addi $v1, $v1, 0x4
    bne $v0, $a0, .LLibgultra_ReturnFromDebugException_0D4
    nop
    jal Libgultra_TrwCacheFlush0
    nop
    jal Libgultra_TrwCacheFlush1
    nop
    jr $ra
    nop
    sw $a0, 0x338($k0)
    j .LLibgultra_ReturnFromDebugException_13C
    nop
    mfc0 $at, $14
    nop
    addiu $at, $at, 0x4
    mtc0 $at, $14
    addiu $at, $zero, 0x0
    j Libgultra_TrwExceptionHandler+0x1B0
    nop
    lui $v0, %hi(Libsn_InitializeHostMemoryAccess_Address)
    addiu $v0, $v0, %lo(Libsn_InitializeHostMemoryAccess_Address)
    j .LLibgultra_ReturnFromDebugException_140
    nop
.LLibgultra_ReturnFromDebugException_13C:
    ld $v0, 0x330($k0)
.LLibgultra_ReturnFromDebugException_140:
    mfc0 $at, $14
    nop
    addiu $at, $at, 0x4
    mtc0 $at, $14
    ld $at, 0x328($k0)
    mfc0 $k0, $30
    eret
