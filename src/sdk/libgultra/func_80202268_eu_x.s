.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl func_80202268_eu_x
func_80202268_eu_x:
    ldc1 $f21, 0xA0($sp)
    ldc1 $f20, 0x98($sp)
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
