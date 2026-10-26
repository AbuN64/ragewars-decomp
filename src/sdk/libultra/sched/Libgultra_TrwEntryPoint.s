.set noreorder
.set noat
.section .text
.if VERSION_EU
.globl Sched_BootEuropeanRom
Sched_BootEuropeanRom:
.elseif VERSION_EU_X
.globl Sched_BootEuropeanAlternateRom
Sched_BootEuropeanAlternateRom:
.elseif VERSION_US
.globl Libgultra_TrwEntryPoint
Libgultra_TrwEntryPoint:
.elseif VERSION_US_REV1
.globl Sched_BootUsRevisionOneRom
Sched_BootUsRevisionOneRom:
.else
.globl Sched_BootGermanRom
Sched_BootGermanRom:
.endif
    lui $sp, 0x803F
    ori $sp, $sp, 0xFFC0
    addiu $a0, $zero, 0x1E
.LLibgultra_TrwEntryPoint_00C:
    mfc0 $t0, $10
    mtc0 $a0, $0
    lui $t1, 0x8000
    mtc0 $t1, $10
    mtc0 $zero, $2
    mtc0 $zero, $3
    nop
    tlbwi
    nop
    nop
    nop
    nop
    mtc0 $t0, $10
    nop
    bnez $a0, .LLibgultra_TrwEntryPoint_00C
    addi $a0, $a0, -0x1
    addiu $a0, $zero, 0x1F
    lui $a1, 0x1F
    ori $a1, $a1, 0xE000
    lui $a2, 0x20
    addiu $a3, $zero, 0x0
    lui $t1, 0x10
    sw $t1, 0x10($sp)
    addiu $t0, $zero, 0x7
    jal rw_boot_entry+0x88
    sw $t0, 0x14($sp)
.if VERSION_EU
    lui $a0, %hi(D_002A72D0_eu)
    addiu $a0, $a0, %lo(D_002A72D0_eu)
.elseif VERSION_EU_X
    lui $a0, %hi(D_002A7310_eu_x)
    addiu $a0, $a0, %lo(D_002A7310_eu_x)
.elseif VERSION_US
    lui $a0, %hi(D_002A70F0_us)
    addiu $a0, $a0, %lo(D_002A70F0_us)
.elseif VERSION_US_REV1
    lui $a0, %hi(D_002A81B0_us_rev1)
    addiu $a0, $a0, %lo(D_002A81B0_us_rev1)
.else
    lui $a0, %hi(D_002A71C0_de)
    addiu $a0, $a0, %lo(D_002A71C0_de)
.endif
    jalr $a0
    nop
    break 1, 2
    lw $t8, 0x10($sp)
    addi $t0, $zero, 0x7
    lw $t9, 0x14($sp)
    addi $t7, $zero, -0x1
    and $t9, $t9, $t0
    ori $t9, $t9, 0x18
    mfc0 $t0, $10
    mtc0 $a0, $0
    mtc0 $a1, $5
    mtc0 $a2, $10
    beq $a3, $t7, .LLibgultra_TrwEntryPoint_0C8
    addi $t6, $zero, 0x1
    srl $t5, $a3, 6
    or $t5, $t5, $t9
    b .LLibgultra_TrwEntryPoint_0CC
    mtc0 $t5, $2
.LLibgultra_TrwEntryPoint_0C8:
    mtc0 $t6, $2
.LLibgultra_TrwEntryPoint_0CC:
    beq $t8, $t7, .LLibgultra_TrwEntryPoint_0E0
    mtc0 $t6, $3
    srl $t5, $t8, 6
    or $t5, $t5, $t9
    mtc0 $t5, $3
.LLibgultra_TrwEntryPoint_0E0:
    tlbwi
    nop
    nop
    nop
    nop
    mtc0 $t0, $10
    jr $ra
    nop
