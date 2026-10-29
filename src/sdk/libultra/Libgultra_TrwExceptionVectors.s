.set noreorder
.set noat
.if VERSION_EU_X || VERSION_US_REV1
.set gp=64
.set fp=64
.endif
.section .text
.if VERSION_EU
.globl Libultra_DispatchEuropeanExceptionVectors
Libultra_DispatchEuropeanExceptionVectors:
    xori $v0, $v1, 0x2561
    swr $a1, 0x7728($t1)
.elseif VERSION_US
.globl Libgultra_TrwExceptionVectors
Libgultra_TrwExceptionVectors:
    bltz $t0, .LLibgultra_TrwExceptionVectors_024
    sll $zero, $a0, 0
.else
.globl Libultra_DispatchExceptionVectors
Libultra_DispatchExceptionVectors:
    ldc1 $f21, 0xA0($sp)
    ldc1 $f20, 0x98($sp)
.endif
    mtc0 $k0, $30
    lui $k0, %hi(Libgultra_TrwExceptionHandler_Address)
    addiu $k0, $k0, %lo(Libgultra_TrwExceptionHandler_Address)
    jr $k0
    nop
    nop
    nop
.if VERSION_US
.LLibgultra_TrwExceptionVectors_024:
.endif
    nop
    nop
    nop
    lui $k0, 0x8000
    ori $k0, $k0, 0x194
    jr $k0
    nop
    mtc0 $k0, $30
    lui $k0, %hi(Libgultra_TrwExceptionHandler_Address)
    addiu $k0, $k0, %lo(Libgultra_TrwExceptionHandler_Address)
    jr $k0
    nop
    nop
    nop
    nop
    nop
    nop
    lui $k0, 0x8000
    ori $k0, $k0, 0x14
    jr $k0
    nop
