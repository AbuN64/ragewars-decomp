.set noreorder
.set noat
.section .text
.globl Libgultra_TrwExceptionVectors
Libgultra_TrwExceptionVectors:
    bltz $t0, .Lfunc_80202268_us_024
    sll $zero, $a0, 0
    mtc0 $k0, $30
    lui $k0, %hi(D_00202460_eu_x)
    addiu $k0, $k0, %lo(D_00202460_eu_x)
    jr $k0
    nop
    nop
    nop
.Lfunc_80202268_us_024:
    nop
    nop
    nop
    lui $k0, 0x8000
    ori $k0, $k0, 0x194
    jr $k0
    nop
    mtc0 $k0, $30
    lui $k0, %hi(D_00202460_eu_x)
    addiu $k0, $k0, %lo(D_00202460_eu_x)
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
