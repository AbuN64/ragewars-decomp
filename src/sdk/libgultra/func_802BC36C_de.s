.set noreorder
.set noat
.set gp=64
.set fp=64
.section .text
.globl func_802BC36C_de
func_802BC36C_de:
    lui $a1, %hi(D_800D5270)
    lw $a1, %lo(D_800D5270)($a1)
    mfc0 $t0, $12
    nop
    ori $t0, $t0, 0x2
    sw $t0, 0x118($a1)
    sd $s0, 0x98($a1)
    sd $s1, 0xA0($a1)
    sd $s2, 0xA8($a1)
    sd $s3, 0xB0($a1)
    sd $s4, 0xB8($a1)
    sd $s5, 0xC0($a1)
    sd $s6, 0xC8($a1)
    sd $s7, 0xD0($a1)
    sd $gp, 0xE8($a1)
    sd $sp, 0xF0($a1)
    sd $fp, 0xF8($a1)
    sd $ra, 0x100($a1)
    sw $ra, 0x11C($a1)
    lw $k1, 0x18($a1)
    nop
    beqz $k1, .Lfunc_802BC36C_de_0FC
    nop
    cfc1 $k1, $31
    nop
    sw $k1, 0x12C($a1)
    sdc1 $f0, 0x130($a1)
    sdc1 $f2, 0x138($a1)
    sdc1 $f4, 0x140($a1)
    sdc1 $f8, 0x150($a1)
    sdc1 $f10, 0x158($a1)
    sdc1 $f12, 0x160($a1)
    sdc1 $f14, 0x168($a1)
    sdc1 $f16, 0x170($a1)
    sdc1 $f18, 0x178($a1)
    sdc1 $f20, 0x180($a1)
    sdc1 $f22, 0x188($a1)
    sdc1 $f24, 0x190($a1)
    sdc1 $f26, 0x198($a1)
    sdc1 $f28, 0x1A0($a1)
    sdc1 $f30, 0x1A8($a1)
    lw $k1, 0x118($a1)
    nop
    lui $at, 0x400
    and $k1, $k1, $at
    beqz $k1, .Lfunc_802BC36C_de_0FC
    nop
    sdc1 $f1, 0x1B0($a1)
    sdc1 $f3, 0x1B8($a1)
    sdc1 $f5, 0x1C0($a1)
    sdc1 $f7, 0x1C8($a1)
    sdc1 $f9, 0x1D0($a1)
    sdc1 $f11, 0x1D8($a1)
    sdc1 $f13, 0x1E0($a1)
    sdc1 $f15, 0x1E8($a1)
    sdc1 $f17, 0x1F0($a1)
    sdc1 $f19, 0x1F8($a1)
    sdc1 $f21, 0x200($a1)
    sdc1 $f23, 0x208($a1)
    sdc1 $f25, 0x210($a1)
    sdc1 $f27, 0x218($a1)
    sdc1 $f29, 0x220($a1)
    sdc1 $f31, 0x228($a1)
.Lfunc_802BC36C_de_0FC:
    lw $k1, 0x118($a1)
    nop
    andi $t1, $k1, 0xFF00
    beqz $t1, .Lfunc_802BC36C_de_148
    nop
    lui $t0, %hi(D_800D5258)
    addiu $t0, $t0, %lo(D_800D5258)
    nop
    lw $t0, 0x0($t0)
    nop
    addiu $at, $zero, -0x1
    xor $t0, $t0, $at
    andi $t0, $t0, 0xFF00
    or $t1, $t1, $t0
    lui $at, 0xFFFF
    ori $at, $at, 0xFF
    and $k1, $k1, $at
    or $k1, $k1, $t1
    sw $k1, 0x118($a1)
.Lfunc_802BC36C_de_148:
    lui $k1, %hi(D_A430000C)
    lw $k1, %lo(D_A430000C)($k1)
    nop
    beqz $k1, .Lfunc_802BC36C_de_188
    nop
    lui $k0, %hi(D_800D5258)
    addiu $k0, $k0, %lo(D_800D5258)
    lw $k0, 0x0($k0)
    nop
    srl $k0, $k0, 16
    addiu $at, $zero, -0x1
    xor $k0, $k0, $at
    lw $t0, 0x128($a1)
    andi $k0, $k0, 0x3F
    and $k0, $k0, $t0
    or $k1, $k1, $k0
.Lfunc_802BC36C_de_188:
    beqz $a0, .Lfunc_802BC36C_de_198
    sw $k1, 0x128($a1)
    jal .Lfunc_802BC36C_de_19C
    nop
.Lfunc_802BC36C_de_198:
    j func_802BC850_eu_x
.Lfunc_802BC36C_de_19C:
    addu $t9, $a0, $zero
