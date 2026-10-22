.set noreorder
.set noat
.section .text
.if VERSION_DE
.globl func_802BCF20_de
func_802BCF20_de:
.elseif VERSION_EU
.globl func_802BD1C0_eu
func_802BD1C0_eu:
.elseif VERSION_US
.globl func_802BCE50_us
func_802BCE50_us:
.else
.globl func_802BD200_eu_x
func_802BD200_eu_x:
.endif
    mfc0 $v0, $12
    jr $ra
    nop
