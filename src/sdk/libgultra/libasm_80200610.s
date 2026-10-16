.set noreorder
.set noat
.section .text
.globl func_80202268_eu
func_80202268_eu:
    xori $v0, $v1, 0x2561
    swr $a1, 0x7728($t1)
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
