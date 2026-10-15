// Rage Wars us-rev1 L3DEX 2.05: symbolic line-resource reconstruction.
// Matrix/state/table definitions adapted from Mr-Wiseguy/f3dex2 (CC0-1.0).
// Instruction source recovered from owner ROM DECA0-DFE30, with named command
// handlers, DMA routines, line clipping/rasterization and native overlay tables.
// The main image executes at 1080; the two overlays replace IMEM at 1000.
.rsp
#include "rcp.h"
#include "sptask.h"
#include "rspboot.h"
#include "gbi.h"
#include "gbi_internal.h"
.macro OverlayEntry, loadStart, loadEnd, imemAddr
    .dw loadStart
    .dh (loadEnd - loadStart - 1) & 0xFFFF
    .dh (imemAddr) & 0xFFFF
.endmacro
.macro jumpTableEntry, addr
    .dh addr & 0xFFFF
.endmacro

.definelabel line_task_out, 0xFE8
.definelabel line_task_out_size, 0xFEC
.definelabel line_task_yield, 0xFF8
// RSP DMEM
.create DATA_FILE, 0x0000

/*
Matrices are stored and used in a transposed format compared to how they are
normally written in mathematics. For the integer part:
00 02 04 06  typical  Xscl Rot  Rot  0
08 0A 0C 0E  use:     Rot  Yscl Rot  0
10 12 14 16           Rot  Rot  Zscl 0
18 1A 1C 1E           Xpos Ypos Zpos 1
The fractional part comes next and is in the same format.
Applying this transformation is done by multiplying a row vector times the
matrix, like:
X  Y  Z  1  *  Xscl Rot  Rot  0  =  NewX NewY NewZ 1
               Rot  Yscl Rot  0
               Rot  Rot  Zscl 0
               Xpos Ypos Zpos 1
In C, the matrix is accessed as matrix[row][col], and the vector is vector[row].
*/
// 0x0000-0x0040: modelview matrix
mvMatrix:
    .fill 64

// 0x0040-0x0080: projection matrix
pMatrix:
    .fill 64

// 0x0080-0x00C0: modelviewprojection matrix
mvpMatrix:
    .fill 64
    
// 0x00C0-0x00C8: scissor (four 12-bit values)
scissorUpLeft: // the command byte is included since the command word is copied verbatim
    .dw (G_SETSCISSOR << 24) | ((  0 * 4) << 12) | ((  0 * 4) << 0)
scissorBottomRight:
    .dw ((320 * 4) << 12) | ((240 * 4) << 0)

// 0x00C8-0x00D0: othermode
otherMode0: // command byte included, same as above
    .dw (G_RDPSETOTHERMODE << 24) | (0x080CFF)
otherMode1:
    .dw 0x00000000

// 0x00D0-0x00D8: Saved texrect state for combining the multiple input commands into one RDP texrect command
texrectWord1:
    .fill 4 // first word, has command byte, xh and yh
texrectWord2:
    .fill 4 // second word, has tile, xl, yl

// 0x00D8: First half of RDP value for split commands (shared by perspNorm moveword to be able to write a 32-bit value)
rdpHalf1Val:
    .fill 4

// 0x00DC: perspective norm
perspNorm:
    .dh 0xFFFF

// 0x00DE: displaylist stack length
displayListStackLength:
    .db 0x00 // starts at 0, increments by 4 for each "return address" pushed onto the stack

    .db 0x48 // this seems to be the max displaylist length

// 0x00E0-0x00F0: viewport
viewport:
    .fill 16

// 0x00F0-0x00F4: Current RDP fifo output position
rdpFifoPos:
    .fill 4

// 0x00F4-0x00F8:
matrixStackPtr:
    .dw 0x00000000

// 0x00F8-0x0138: segment table
segmentTable:
    .fill (4 * 16) // 16 DRAM pointers

// 0x0138-0x0180: displaylist stack
displayListStack:

// 0x0138-0x0180: ucode text (shared with DL stack)
#if CFG_EXTRA_0A_BEFORE_ID_STR // F3DEX2 2.04H puts an extra 0x0A before the name
    .db 0x0A
#endif
    .ascii ID_STR, 0x0A

.align 16
.if . - displayListStack != 0x48
    .warning "ID_STR incorrect length, affects displayListStack"
.endif

// Base address for RSP effects DMEM region (see discussion in lighting below).
// Could pick a better name, basically a global fixed DMEM pointer used with
// fixed offsets to things in this region. It seems potentially data below this
// could be shared by different running microcodes whereas data after this is
// only used by the current microcode. Also this is used for a base address in
// vtx write / lighting because vector load offsets can't reach all of DMEM.
spFxBase:

// 0x0180-0x1B0: clipping values
clipRatio: // This is an array of 6 doublewords
// G_MWO_CLIP_R** point to the second word of each of these, and end up setting
// the Z scale (always 0 for X and Y components) and the W scale (clip ratio)
    .dw 0x00010000, 0x00000002 // 1 * x,    G_MWO_CLIP_RNX * w = negative x clip
    .dw 0x00000001, 0x00000002 // 1 * y,    G_MWO_CLIP_RNY * w = negative y clip
    .dw 0x00010000, 0x0000FFFE // 1 * x, (-)G_MWO_CLIP_RPX * w = positive x clip
    .dw 0x00000001, 0x0000FFFE // 1 * x, (-)G_MWO_CLIP_RPY * w = positive y clip
    .dw 0x00000000, 0x0001FFFF // 1 * z,  -1 * w = far clip
#if CFG_NoN
    .dw 0x00000000, 0x00000001 // 0 * all, 1 * w = no nearclipping
#else
    .dw 0x00000000, 0x00010001 // 1 * z,   1 * w = nearclipping
#endif

// 0x1B0: constants for register $v31
.align 0x10 // loaded with lqv
// VCC patterns used:
// vlt xxx, $v31, $v31[3]  = 11101110 in load_spfx_global_values
// vne xxx, $v31, $v31[3h] = 11101110 in lighting
// veq xxx, $v31, $v31[3h] = 00010001 in lighting
v31Value:
    .dh -1     // used in init, clipping
    .dh 4      // used in clipping, vtx write for Newton-Raphson reciprocal
    .dh 8      // old ucode only: used in tri write
    .dh 0x7F00 // used in vtx write and pre-jump instrs to there, also 4 put here during point lighting
    .dh -4     // used in clipping, vtx write for Newton-Raphson reciprocal
    .dh 0x4000 // used in tri write, texgen
    .dh vertexBuffer // 0x420; used in tri write
    .dh 0x7FFF // used in vtx write, tri write, lighting, point lighting

// 0x1C0: constants for register $v30
.align 0x10 // loaded with lqv
// VCC patterns used:
// vge xxx, $v30, $v30[7] = 11110001 in tri write
v30Value:
    .dh 0x7FFC // not used!
    .dh vtxSize << 7 // 0x1400; it's not 0x2800 because vertex indices are *2; used in tri write for vtx index to addr
#if CFG_OLD_TRI_WRITE // See discussion in tri write where v30 values used
    .dh 0x01CC // used in tri write, vcr?
    .dh 0x0200 // not used!
    .dh -16    // used in tri write for Newton-Raphson reciprocal 
    .dh 0x0010 // used in tri write for Newton-Raphson reciprocal
    .dh 0x0020 // used in tri write, both signed and unsigned multipliers
    .dh 0x0100 // used in tri write, vertex color >>= 8; also in lighting
#else
    .dh 0x1000 // used in tri write, some multiplier
    .dh 0x0100 // used in tri write, vertex color >>= 8 and vcr?; also in lighting and point lighting
    .dh -16    // used in tri write for Newton-Raphson reciprocal 
    .dh 0xFFF8 // used in tri write, mask away lower ST bits?
    .dh 0x0010 // used in tri write for Newton-Raphson reciprocal; value moved to elem 7 for point lighting
    .dh 0x0020 // used in tri write, both signed and unsigned multipliers; value moved from elem 6 from point lighting
#endif

/*
Quick note on Newton-Raphson:
https://en.wikipedia.org/wiki/Division_algorithm#Newton%E2%80%93Raphson_division
Given input D, we want to find the reciprocal R. The base formula for refining
the estimate of R is R_new = R*(2 - D*R). However, since the RSP reciprocal
instruction moves the radix point 1 to the left, the result has to be multiplied
by 2. So it's 2*R*(2 - D*2*R) = R*(4 - 4*D*R) = R*(1*4 + D*R*-4). This is where
the 4 and -4 come from. For tri write, the result needs to be multiplied by 4
for subpixels, so it's 16 and -16.
*/

.align 0x10 // loaded with lqv
linearGenerateCoefficients:
    .dh 0xC000
    .dh 0x44D3
    .dh 0x6CB3
    .dh 2

// 0x01D8
    .db 0x00 // Padding to allow mvpValid to be written to as a 32-bit word
mvpValid:
    .db 0x01

// 0x01DA
    .dh 0x0000 // Shared padding so that:
               // -- mvpValid can be written on its own for G_MW_FORCEMTX
               // -- Writing numLightsx18 with G_MW_NUMLIGHT sets lightsValid to 0
               // -- do_popmtx and load_mtx can invalidate both with one zero word write

// 0x01DC
lightsValid:   // Gets overwritten with 0 when numLights is written with moveword.
    .db 1
numLightsx18:
    .db 0

    .dh rdpCmdBuffer1 // initial RDP command-buffer address

// 0x01E0
fogFactor:
    .dw 0x00000000

// 0x01E4
textureSettings1:
    .dw 0x00000000 // first word, has command byte, bowtie val, level, tile, and on

// 0x01E8
textureSettings2:
    .dw 0x00000000 // second word, has s and t scale

// 0x01EC Geometry mode flags
// Considerations for each byte:
// - The first byte, containing zbuffer/texture/shade flags, gets OR'd with 0xC8
//   (G_TRI_FILL) to form the complete triangle opcode. So a modder could use
//   0x80, 0x40 and/or 0x08 for other purposes while remaining forward compatible.
//   (Of course, if you only care about backward compatibility, you can AND 0x07
//   before the OR 0xC8 and use all the extra bits.) Note that backward compatible
//   means a new/modded microcode will run old/vanilla DLs correctly, and forward
//   compatible means an old/vanilla microcode will run DLs made for a new/modded
//   microcode without any problems besides the specific new features missing.
// - The second byte, containing face culling flags, is used as an index into a
//   table, so using any other bits will break forwards compatibility. Again, if
//   you only want backwards compatibility, AND 0x06 when this is loaded and then
//   you can use all six other bits.
// - The top byte holds the geometry mode opcode in the clear mask, so all its
//   bits will either get cleared every time geom mode is set, or can never be
//   cleared. The info in gbi.h warning programmers not to use the high 8 bits
//   because they form a "clip code mask" is kind of irrelevant given that these
//   bits can't be properly set or cleared.
geometryModeLabel:
    .dw G_CLIPPING

// excluding ambient light
MAX_LIGHTS equ 7

// 0x01F0-0x02E0: Light data; a total of 10 * lightSize light slots.
// Each slot's data is either directional or point (each pair of letters is a byte):
//      Directional lights:
// 0x00 RR GG BB 00 RR GG BB -- NX NY NZ -- -- -- -- --
// 0x10 TX TY TZ -- TX TY TZ -- (Normals transformed to camera space)
//      Point lights: 
// 0x00 RR GG BB CC RR GG BB LL XXXX YYYY ZZZZ QQ --
// 0x10 -- -- -- -- -- -- -- -- (Invalid transformed normals get stored here)
// CC: constant attenuation factor (0 indicates directional light)
// LL: linear attenuation factor
// QQ: quadratic attenuation factor
//
// First there are two lights, whose directions define the X and Y directions
// for texgen, via g(s)SPLookAtX/Y. The colors are ignored. These lights get
// transformed normals. g(s)SPLight which point here start copying at n*24+24,
// where n starts from 1 for one light (or zero lights), which effectively
// points at lightBufferMain.
lightBufferLookat:
    .fill (2 * lightSize)
// Then there are the main 8 lights. This is between one and seven directional /
// point (if built with this enabled) lights, plus the ambient light at the end.
// Zero lights is not supported, and is encoded as one light with black color
// (does not affect the result). Directional and point lights can be mixed in
// any order; ambient is always at the end.
lightBufferMain:
    .fill (8 * lightSize)
// Code uses pointers relative to spFxBase, with immediate offsets, so that
// another register isn't needed to store the start or end address of the array.
// Pointers are kept relative to spFxBase; this offset gets them to point to
// lightBufferMain instead.
ltBufOfs equ (lightBufferMain - spFxBase)
// One more topic on lighting: The point lighting code uses MV transpose instead
// of MV inverse to transform from camera space to model space. If MV has a
// uniform scale (same scale in X, Y, and Z), MV transpose = MV inverse times a
// scale factor. The lighting code effectively gets rid of the scale factor, so
// this is okay. But, if the matrix has nonuniform scaling, and especially if it
// has shear (nonuniform scaling applied somewhere in the middle of the matrix
// stack, such as to a whole skeletal / skinned mesh), this will not be correct.

// 0x02E0-0x02F0: Overlay 0/1 Table
overlayInfo0:
    OverlayEntry orga(ovl0_start), orga(ovl0_end), ovl0_start
overlayInfo1:
    OverlayEntry orga(ovl1_start), orga(ovl1_end), ovl1_start

// 0x02F0-0x02FE: Movemem table
movememTable:
    // Temporary matrix in clipTempVerts scratch space, aligned to 16 bytes
    .dh (clipTempVerts + 15) & ~0xF // G_MTX multiply temp matrix (model)
    .dh mvMatrix          // G_MV_MMTX
    .dh (clipTempVerts + 15) & ~0xF // G_MTX multiply temp matrix (projection)
    .dh pMatrix           // G_MV_PMTX
    .dh viewport          // G_MV_VIEWPORT
    .dh lightBufferLookat // G_MV_LIGHT
    .dh vertexBuffer      // G_MV_POINT
// Further entries in the movemem table come from the moveword table

// 0x02FE-0x030E: moveword table
movewordTable:
    .dh mvpMatrix        // G_MW_MATRIX
    .dh numLightsx18 - 3 // G_MW_NUMLIGHT
    .dh clipRatio        // G_MW_CLIP
    .dh segmentTable     // G_MW_SEGMENT
    .dh fogFactor        // G_MW_FOG
    .dh lightBufferMain  // G_MW_LIGHTCOL
    .dh mvpValid - 1     // G_MW_FORCEMTX
    .dh perspNorm - 2    // G_MW_PERSPNORM

// 0x030E-0x0314: G_POPMTX, G_MTX, G_MOVEMEM Command Jump Table
movememHandlerTable:
jumpTableEntry G_POPMTX_end   // G_POPMTX
jumpTableEntry G_MTX_end      // G_MTX (multiply)
jumpTableEntry G_MOVEMEM_end  // G_MOVEMEM, G_MTX (load)

// 0x0314-0x0370: RDP/Immediate Command Jump Table
jumpTableEntry G_SPECIAL_3_handler
jumpTableEntry G_SPECIAL_2_handler
jumpTableEntry G_SPECIAL_1_handler
jumpTableEntry G_DMA_IO_handler
jumpTableEntry G_TEXTURE_handler
jumpTableEntry G_POPMTX_handler
jumpTableEntry G_GEOMETRYMODE_handler
jumpTableEntry G_MTX_handler
jumpTableEntry G_MOVEWORD_handler
jumpTableEntry G_MOVEMEM_handler
jumpTableEntry G_LOAD_UCODE_handler
jumpTableEntry G_DL_handler
jumpTableEntry G_ENDDL_handler
jumpTableEntry G_SPNOOP_handler
jumpTableEntry G_RDPHALF_1_handler
jumpTableEntry G_SETOTHERMODE_L_handler
jumpTableEntry G_SETOTHERMODE_H_handler
jumpTableEntry G_TEXRECT_handler
jumpTableEntry G_TEXRECTFLIP_handler
jumpTableEntry G_SYNC_handler    // G_RDPLOADSYNC
jumpTableEntry G_SYNC_handler    // G_RDPPIPESYNC
jumpTableEntry G_SYNC_handler    // G_RDPTILESYNC
jumpTableEntry G_SYNC_handler    // G_RDPFULLSYNC
jumpTableEntry G_RDP_handler     // G_SETKEYGB
jumpTableEntry G_RDP_handler     // G_SETKEYR
jumpTableEntry G_RDP_handler     // G_SETCONVERT
jumpTableEntry G_SETSCISSOR_handler
jumpTableEntry G_RDP_handler     // G_SETPRIMDEPTH
jumpTableEntry G_RDPSETOTHERMODE_handler
jumpTableEntry G_RDP_handler     // G_LOADTLUT
jumpTableEntry G_RDPHALF_2_handler
jumpTableEntry G_RDP_handler     // G_SETTILESIZE
jumpTableEntry G_RDP_handler     // G_LOADBLOCK
jumpTableEntry G_RDP_handler     // G_LOADTILE
jumpTableEntry G_RDP_handler     // G_SETTILE
jumpTableEntry G_RDP_handler     // G_FILLRECT
jumpTableEntry G_RDP_handler     // G_SETFILLCOLOR
jumpTableEntry G_RDP_handler     // G_SETFOGCOLOR
jumpTableEntry G_RDP_handler     // G_SETBLENDCOLOR
jumpTableEntry G_RDP_handler     // G_SETPRIMCOLOR
jumpTableEntry G_RDP_handler     // G_SETENVCOLOR
jumpTableEntry G_RDP_handler     // G_SETCOMBINE
jumpTableEntry G_SETxIMG_handler // G_SETTIMG
jumpTableEntry G_SETxIMG_handler // G_SETZIMG
jumpTableEntry G_SETxIMG_handler // G_SETCIMG

commandJumpTable:
jumpTableEntry G_NOOP_handler

// 0x0370-0x0380: DMA Command Jump Table
jumpTableEntry G_VTX_handler
jumpTableEntry G_MODIFYVTX_handler
jumpTableEntry G_CULLDL_handler
jumpTableEntry G_BRANCH_WZ_handler // different for F3DZEX
jumpTableEntry G_TRI1_handler
jumpTableEntry G_TRI2_handler
jumpTableEntry G_QUAD_handler
jumpTableEntry G_LINE3D_handler

// 0x0380-0x03C4: vertex pointers
vertexTable:

// The vertex table is a list of pointers to the location of each vertex in the buffer
// After the last vertex pointer, there is a pointer to the address after the last vertex
// This means there are really 33 entries in the table

.macro vertexTableEntry, i
    .dh vertexBuffer + (i * vtxSize)
.endmacro

.macro vertexTableEntries, i
    .if i > 0
        vertexTableEntries (i - 1)
    .endif
    vertexTableEntry i
.endmacro

    vertexTableEntries 32

// Saved return address while clipping one line against the six planes.
lineClipReturn:
    .dh 0
activeClipPlanes:
    .dw ((CLIP_NX | CLIP_NY | CLIP_PX | CLIP_PY) << CLIP_SHIFT_SCAL) | ((CLIP_FAR | CLIP_NEAR) << CLIP_SHIFT_SCRN)
clipMaskList:
    .dw CLIP_NX << CLIP_SHIFT_SCAL
    .dw CLIP_NY << CLIP_SHIFT_SCAL
    .dw CLIP_PX << CLIP_SHIFT_SCAL
    .dw CLIP_PY << CLIP_SHIFT_SCAL
    .dw CLIP_FAR << CLIP_SHIFT_SCRN
    .dw CLIP_NEAR << CLIP_SHIFT_SCRN
// Quarter-pixel scissor bounds used by the line rasterizer.
lineScissor:
    .dh 0, 0, 320 * 4, 240 * 4
vertexBuffer:
    .skip vtxSize * 32
inputBuffer:
    .skip 0xA8
inputBufferEnd:
clipTempVerts:
    .skip vtxSize * 6
rdpCmdBuffer1:
    .skip 0x158
rdpCmdBuffer1End:
    .skip 0x90
rdpCmdBuffer2:
    .skip 0x158
rdpCmdBuffer2End:
    .skip 0x90
.org 0xFC0
OSTask:
    .skip 0x40
.org vertexBuffer
.fill 8 // Resident data-resource tail alignment; no vertex state is imported.
.close

.create CODE_FILE, 0x1080
line_start:
    vxor        $v0, $v0, $v0
    lqv         $v31[0], (v31Value)($zero)
line_main_join_1088:
    lqv         $v30[0], (v30Value)($zero)
    addi        $23, $zero, 0xA80
    addi        $22, $zero, 0xC68
    vsub        $v1, $v0, $v31[0]
    lw          $11, (rdpFifoPos)($zero)
    lw          $12, (OSTask + OS_TASK_OFF_FLAGS)($zero)
    addi        $1, $zero, 0x2800
    beqz        $11, line_main_join_10c0
    mtc0        $1, SP_STATUS
    andi        $12, $12, 0x1
    beqz        $12, line_relocate_overlay_tables
    sw          $zero, (OSTask + OS_TASK_OFF_FLAGS)($zero)
    j line_load_command_overlay
    lw          $26, 0xBF8($zero)
line_main_join_10c0:
    mfc0        $11, DPC_STATUS
    andi        $11, $11, 0x1
    bnez        $11, line_main_join_10f8
    mfc0        $2, DPC_END
    lw          $3, (line_task_out)($zero)
    sub         $11, $3, $2
    bgtz        $11, line_main_join_10f8
    mfc0        $1, DPC_CURRENT
    lw          $4, (line_task_out_size)($zero)
    beqz        $1, line_main_join_10f8
    sub         $11, $1, $4
    bgez        $11, line_main_join_10f8
    nop
    bne         $1, $2, line_main_join_1118
line_main_join_10f8:
    mfc0        $11, DPC_STATUS
    andi        $11, $11, 0x400
    bnez        $11, line_main_join_10f8
    addi        $11, $zero, 0x1
    mtc0        $11, DPC_STATUS
    lw          $2, (line_task_out_size)($zero)
    mtc0        $2, DPC_START
    mtc0        $2, DPC_END
line_main_join_1118:
    sw          $2, (rdpFifoPos)($zero)
    nop
    nop
    nop
line_init_matrix_stack:
    lw          $11, (matrixStackPtr)($zero)
    bnez        $11, line_relocate_overlay_tables
    lw          $11, (OSTask + OS_TASK_OFF_STACK)($zero)
    sw          $11, (matrixStackPtr)($zero)
line_relocate_overlay_tables:
    lw          $1, (OSTask + OS_TASK_OFF_UCODE)($zero)
    lw          $2, (overlayInfo0)($zero)
    lw          $3, (overlayInfo1)($zero)
    add         $2, $2, $1
    add         $3, $3, $1
    sw          $2, (overlayInfo0)($zero)
    sw          $3, (overlayInfo1)($zero)
    lw          $25, (scissorUpLeft)($zero)
    jal line_update_scissor
    lw          $24, (scissorBottomRight)($zero)
    lw          $26, (OSTask + OS_TASK_OFF_DATA)($zero)
line_load_command_overlay:
    addi        $11, $zero, 0x2E8
    jal load_overlay_and_enter
    ori         $12, $ra, 0x0
displaylist_dma:
    addi        $19, $zero, 0xA7
    ori         $24, $26, 0x0
    jal dma_read_write
    addiu       $20, $zero, 0x8E8
    addiu       $26, $26, 0xA8
    addi        $27, $zero, -0xA8
G_POPMTX_end:
G_MOVEMEM_end:
while_wait_displaylist_dma:
    jal while_wait_dma_busy
G_SPECIAL_3_handler:
G_SPECIAL_2_handler:
G_SPECIAL_1_handler:
G_SPNOOP_handler:
run_next_DL_command:
    mfc0        $1, SP_STATUS
    lw          $25, 0x990($27)
    beqz        $27, displaylist_dma
    andi        $1, $1, 0x80
    sra         $12, $25, 24
    sll         $11, $12, 1
    lhu         $11, 0x36E($11)
    bnez        $1, G_LOAD_UCODE_handler
    lw          $24, 0x994($27)
    jr          $11
    addiu       $27, $27, 0x8
G_DMA_IO_handler:
    jal segmented_to_physical
    lh          $20, 0x989($27)
    andi        $19, $25, 0xFF8
    sra         $20, $20, 2
    j dma_read_write
    addi        $ra, $zero, G_POPMTX_end
G_GEOMETRYMODE_handler:
    lw          $11, (geometryModeLabel)($zero)
    and         $11, $11, $25
    or          $11, $11, $24
    j G_SPECIAL_3_handler
    sw          $11, (geometryModeLabel)($zero)
G_ENDDL_handler:
    lbu         $1, (displayListStackLength)($zero)
    beqz        $1, G_LOAD_UCODE_handler
    addi        $1, $1, -0x4
    j line_displaylist_enter
    lw          $26, 0x138($1)
G_RDPHALF_2_handler:
    ldv         $v29[0], (scissorUpLeft)($zero)
    ldv         $v29[8], (texrectWord1)($zero)
    lw          $25, (rdpHalf1Val)($zero)
    addi        $23, $23, 0x10
    sdv         $v29[0], 0x3F0($23)
    sdv         $v29[8], 0x3F8($23)
G_RDP_handler:
    sw          $24, 0x4($23)
G_SYNC_handler:
G_NOOP_handler:
    sw          $25, 0x0($23)
    j flush_rdp_buffer
    addi        $23, $23, 0x8
G_SETxIMG_handler:
    addi        $ra, $zero, G_RDP_handler
segmented_to_physical:
    srl         $11, $24, 22
    andi        $11, $11, 0x3C
    lw          $11, 0xF8($11)
    sll         $24, $24, 8
    srl         $24, $24, 8
    jr          $ra
    add         $24, $24, $11
G_RDPSETOTHERMODE_handler:
    sw          $25, (otherMode0)($zero)
    j G_RDP_handler
    sw          $24, (otherMode1)($zero)
G_SETSCISSOR_handler:
    sw          $25, (scissorUpLeft)($zero)
    sw          $24, (scissorBottomRight)($zero)
    addi        $ra, $zero, G_RDP_handler
line_update_scissor:
    andi        $11, $25, 0xFFF
    sh          $11, (lineScissor + 2)($zero)
    srl         $11, $25, 12
    andi        $11, $11, 0xFFF
    sh          $11, (lineScissor)($zero)
    andi        $11, $24, 0xFFF
    sh          $11, (lineScissor + 6)($zero)
    srl         $11, $24, 12
    andi        $11, $11, 0xFFF
    jr          $ra
    sh          $11, (lineScissor + 4)($zero)
flush_rdp_buffer:
    addi        $ra, $zero, G_SPECIAL_3_handler
line_main_join_1288:
    sub         $11, $23, $22
    blez        $11, return_routine
line_main_join_1290:
    mfc0        $12, SP_DMA_BUSY
    lw          $24, (rdpFifoPos)($zero)
    addiu       $19, $11, 0x1E8
    bnez        $12, line_main_join_1290
    lw          $12, (line_task_out_size)($zero)
    mtc0        $24, DPC_END
    add         $11, $24, $19
    sub         $12, $12, $11
    bgez        $12, line_main_join_12d4
line_main_join_12b4:
    mfc0        $11, DPC_STATUS
    andi        $11, $11, 0x400
    bnez        $11, line_main_join_12b4
    lw          $24, (line_task_out)($zero)
line_main_join_12c4:
    mfc0        $11, DPC_CURRENT
    beq         $11, $24, line_main_join_12c4
    nop
    mtc0        $24, DPC_START
line_main_join_12d4:
    mfc0        $11, DPC_CURRENT
    sub         $11, $11, $24
    blez        $11, line_main_join_12e8
    sub         $11, $11, $19
    blez        $11, line_main_join_12d4
line_main_join_12e8:
    add         $11, $24, $19
    sw          $11, (rdpFifoPos)($zero)
    addi        $19, $19, -0x1
    addi        $20, $22, -0x21E8
    xori        $22, $22, 0x360
    j dma_read_write
    addi        $23, $22, -0x1E8
    nop
G_VTX_handler:
    lhu         $20, 0x380($25)
    jal segmented_to_physical
    lhu         $1, 0x989($27)
    sub         $20, $20, $1
    jal dma_read_write
    addi        $19, $1, -0x1
    lhu         $5, (geometryModeLabel)($zero)
    srl         $1, $1, 3
    sub         $15, $25, $1
    lhu         $15, 0x380($15)
    ori         $14, $20, 0x0
    lbu         $8, (mvpValid)($zero)
line_vertex_geometry_flags:
    andi        $7, $5, 0x1
    bnez        $8, line_main_join_1358
    sll         $7, $7, 3
    sb          $25, (mvpValid)($zero)
    addi        $21, $zero, 0x40
    addi        $20, $zero, 0x0
    jal line_main_join_1088
    addi        $19, $zero, 0x80
line_main_join_1358:
    lqv         $v8[0], (mvpMatrix)($zero)
    lqv         $v10[0], 0x90($zero)
    lqv         $v12[0], 0xA0($zero)
    lqv         $v14[0], 0xB0($zero)
    vadd        $v9, $v8, $v0[0]
    ldv         $v9[0], 0x88($zero)
    vadd        $v11, $v10, $v0[0]
    ldv         $v11[0], 0x98($zero)
    vadd        $v13, $v12, $v0[0]
    ldv         $v13[0], 0xA8($zero)
    vadd        $v15, $v14, $v0[0]
    ldv         $v15[0], 0xB8($zero)
    ldv         $v8[8], (mvpMatrix)($zero)
    ldv         $v10[8], 0x90($zero)
    jal load_spfx_global_values
    ldv         $v12[8], 0xA0($zero)
    jal while_wait_dma_busy
    ldv         $v14[8], 0xB0($zero)
    ldv         $v20[0], 0x0($14)
    vmov        $v16[5], $v21[1]
    ldv         $v20[8], 0x10($14)
line_vertices_process_pair:
    // Process two input vertices using MVP integer/fraction vectors.
    vmudn       $v29, $v15, $v1[0]
    lw          $11, 0x1C($14)
    vmadh       $v29, $v11, $v1[0]
    llv         $v22[12], 0x8($14)
    vmadn       $v29, $v12, $v20[0h]
    vmadh       $v29, $v8, $v20[0h]
    vmadn       $v29, $v13, $v20[1h]
    sw          $11, 0x8($14)
    vmadh       $v29, $v9, $v20[1h]
    vmadn       $v23, $v14, $v20[2h]
    vmadh       $v24, $v10, $v20[2h]
    vge         $v27, $v25, $v31[3]
    llv         $v22[4], 0x18($14)
    vge         $v3, $v25, $v0[0]
    addi        $1, $1, -0x4
    vmudl       $v29, $v23, $v18[4]
    sub         $11, $8, $7
    vmadm       $v2, $v24, $v18[4]
    sbv         $v27[15], 0x73($11)
    vmadn       $v21, $v0, $v0[0]
    sbv         $v27[7], 0x4B($11)
    vmov        $v26[1], $v3[2]
    ssv         $v3[12], 0xF4($8)
    vmudn       $v7, $v23, $v18[5]
    slv         $v25[8], 0x1F0($8)
    vmadh       $v6, $v24, $v18[5]
    sdv         $v25[0], 0x3C8($8)
    vrcph       $v29[0], $v2[3]
    ssv         $v26[12], 0xF6($8)
    vrcpl       $v5[3], $v21[3]
    slv         $v26[2], 0x1CC($8)
    vrcph       $v4[3], $v2[7]
line_vertex_color_unpack:
    // Keep packed vertex colors in reversed pair order, as in graphics A.
    addi        $19, $zero, 0x2D0
    lw          $10, 0x8($14)
    sw          $10, 0x4($19)
    lw          $10, 0xC($14)
    sw          $10, 0x0($19)
    luv         $v3[0], 0x0($19)
    lw          $19, (geometryModeLabel)($zero)
    andi        $19, $19, 0x80
    beqz        $19, line_colors_ready
    nop
    ori         $12, $zero, 0x8
    addi        $11, $zero, 0x250
    vxor        $v27, $v27, $v27
    addi        $19, $zero, 0x7F80
    mtc2        $19, $v27[4]
line_light_next:
    // L3DEX retains the eight-record scan but omits the color contribution body.
    lh          $19, 0xA($11)
    andi        $19, $19, 0x8000
    bnez        $19, line_main_join_1478
    nop
line_main_join_1478:
    addi        $12, $12, -0x1
    bnez        $12, line_light_next
    addi        $11, $11, 0x10
line_colors_ready:
    addi        $19, $zero, 0x2D0
    suv         $v3[0], 0x0($19)
    ldv         $v3[0], 0x0($19)
    vrcpl       $v5[7], $v21[7]
    sra         $11, $1, 31
    vrcph       $v4[7], $v0[0]
    andi        $11, $11, 0x28
    vch         $v29, $v24, $v24[3h]
    addi        $15, $15, 0x50
    vcl         $v29, $v23, $v23[3h]
    sub         $8, $15, $11
    vmudl       $v29, $v21, $v5
    cfc2        $t2, $vcc
    vmadm       $v29, $v2, $v5
    sdv         $v23[8], 0x3E0($8)
    vmadn       $v21, $v21, $v4
    ldv         $v20[0], 0x20($14)
    vmadh       $v2, $v2, $v4
    sdv         $v23[0], 0x3B8($15)
    vge         $v29, $v24, $v0[0]
    lsv         $v23[14], 0xE4($8)
    vmudh       $v29, $v1, $v31[1]
    sdv         $v24[8], 0x3D8($8)
    vmadn       $v26, $v21, $v31[4]
    lsv         $v23[6], 0xBC($15)
    vmadh       $v25, $v2, $v31[4]
    sdv         $v24[0], 0x3B0($15)
    vmrg        $v2, $v0, $v31[7]
    ldv         $v20[8], 0x30($14)
    vch         $v29, $v24, $v6[3h]
    slv         $v3[4], 0x1E8($8)
    vmudl       $v29, $v26, $v5
    lsv         $v24[14], 0xDC($8)
    vmadm       $v29, $v25, $v5
    slv         $v3[0], 0x1C0($15)
    vmadn       $v5, $v26, $v4
    lsv         $v24[6], 0xB4($15)
    vmadh       $v4, $v25, $v4
    sh          $10, -0x2($8)
    vmadh       $v2, $v2, $v31[7]
    sll         $11, $10, 4
    vcl         $v29, $v23, $v7[3h]
    cfc2        $t2, $vcc
    vmudl       $v29, $v23, $v5[3h]
    ssv         $v5[14], 0xFA($8)
    vmadm       $v29, $v24, $v5[3h]
    addi        $14, $14, 0x20
    vmadn       $v26, $v23, $v2[3h]
    sh          $10, -0x4($8)
    vmadh       $v25, $v24, $v2[3h]
    sll         $10, $10, 4
    vmudm       $v3, $v22, $v18
    sh          $11, -0x2A($15)
    sh          $10, -0x2C($15)
    vmudl       $v29, $v26, $v18[4]
    ssv         $v5[6], 0xD2($15)
    vmadm       $v25, $v25, $v18[4]
    ssv         $v4[14], 0xF8($8)
    vmadn       $v26, $v0, $v0[0]
    ssv         $v4[6], 0xD0($15)
    slv         $v3[4], 0x1EC($8)
    vmudh       $v29, $v17, $v1[0]
    slv         $v3[12], 0x1C4($15)
    vmadh       $v29, $v19, $v31[3]
    vmadn       $v26, $v26, $v16
    bgtz        $1, line_vertices_process_pair
    vmadh       $v25, $v25, $v16
    bltz        $ra, line_main_join_1810
    vge         $v3, $v25, $v0[0]
    slv         $v25[8], 0x1F0($8)
    vge         $v27, $v25, $v31[3]
    slv         $v25[0], 0x1C8($15)
    ssv         $v26[12], 0xF6($8)
    ssv         $v26[4], 0xCE($15)
    ssv         $v3[12], 0xF4($8)
    beqz        $7, G_SPECIAL_3_handler
    ssv         $v3[4], 0xCC($15)
    sbv         $v27[15], 0x6B($8)
    j G_SPECIAL_3_handler
    sbv         $v27[7], 0x43($15)
load_spfx_global_values:
    addi        $13, $zero, 0x180
    ldv         $v16[0], (viewport)($zero)
    ldv         $v16[8], (viewport)($zero)
    llv         $v29[0], 0x60($13)
    ldv         $v17[0], (viewport + 8)($zero)
    ldv         $v17[8], (viewport + 8)($zero)
    vlt         $v19, $v31, $v31[3]
    vsub        $v21, $v0, $v16
    llv         $v18[4], 0x68($13)
    vmrg        $v16, $v16, $v29[0]
    llv         $v18[12], 0x68($13)
    vmrg        $v19, $v0, $v1[0]
    llv         $v18[8], (perspNorm)($zero)
    vmrg        $v17, $v17, $v29[1]
    lsv         $v18[10], 0x6($13)
    vmov        $v16[1], $v21[1]
    jr          $ra
    addi        $8, $23, 0x50
G_TRI2_handler:
G_QUAD_handler:
    lbu         $5, 0x98D($27)
    lbu         $29, 0x98E($27)
    lbu         $30, 0x98F($27)
    j line_triangle_edges
    addi        $25, $zero, G_TRI1_handler
G_TRI1_handler:
    lbu         $5, 0x989($27)
    lbu         $29, 0x98A($27)
    lbu         $30, 0x98B($27)
    addi        $25, $zero, G_SPECIAL_3_handler
line_triangle_edges:
    // Convert the three edges of a triangle into independent line primitives.
    lb          $4, 0x98C($27)
    lhu         $28, 0x380($5)
    lhu         $29, 0x380($29)
    lhu         $30, 0x380($30)
    lhu         $5, 0x380($5)
    addi        $4, $4, 0x3
    ori         $2, $28, 0x0
    jal line_clip_and_draw
    ori         $3, $29, 0x0
    ori         $2, $29, 0x0
    jal line_clip_and_draw
    ori         $3, $30, 0x0
    ori         $2, $30, 0x0
    ori         $3, $28, 0x0
    j line_clip_and_draw
    ori         $ra, $25, 0x0
G_LINE3D_handler:
    lb          $4, 0x98B($27)
    lbu         $5, 0x989($27)
    lbu         $3, 0x98A($27)
    addi        $4, $4, 0x3
    lhu         $2, 0x380($5)
    lhu         $3, 0x380($3)
    lhu         $5, 0x380($5)
    addi        $ra, $zero, G_SPECIAL_3_handler
line_clip_and_draw:
    lw          $6, 0x24($2)
    lw          $7, 0x24($3)
    lw          $12, (activeClipPlanes)($zero)
    andi        $11, $6, 0x7070
    and         $11, $11, $7
    bnez        $11, return_routine
    or          $11, $6, $7
    and         $11, $11, $12
    beqz        $11, line_draw_screen_space
    sh          $ra, (lineClipReturn)($zero)
    addiu       $6, $zero, 0x14
    addiu       $15, $zero, 0x990
line_clip_plane_loop:
    // Six plane masks: choose outside endpoint and interpolate it to the plane.
    lw          $11, 0x3C8($6)
    lw          $9, 0x24($2)
    lw          $16, 0x24($3)
    and         $9, $9, $11
    and         $16, $16, $11
    beq         $9, $16, line_main_join_1828
    sll         $11, $6, 1
    beqz        $9, line_main_join_16ec
    ori         $12, $2, 0x0
    ori         $2, $3, 0x0
    ori         $3, $12, 0x0
line_main_join_16ec:
    ldv         $v2[0], 0x180($11)
    ldv         $v4[0], 0x8($2)
    ldv         $v5[0], 0x0($2)
    ldv         $v6[0], 0x8($3)
    ldv         $v7[0], 0x0($3)
    vmudh       $v3, $v2, $v31[0]
    vmudn       $v8, $v4, $v2
    vmadh       $v9, $v5, $v2
    vmadn       $v10, $v6, $v3
    vmadh       $v11, $v7, $v3
    vaddc       $v8, $v8, $v8[0q]
    lqv         $v2[0], 0x1D0($zero)
    vadd        $v9, $v9, $v9[0q]
    vaddc       $v10, $v10, $v10[0q]
    vadd        $v11, $v11, $v11[0q]
    vaddc       $v8, $v8, $v8[1h]
    vadd        $v9, $v9, $v9[1h]
    vaddc       $v10, $v10, $v10[1h]
    vadd        $v11, $v11, $v11[1h]
    vrcph       $v29[0], $v11[3]
    vrcpl       $v3[3], $v10[3]
    vrcph       $v12[3], $v0[0]
    vabs        $v29, $v11, $v2[3]
    vmudn       $v3, $v3, $v29[3]
    vmadh       $v12, $v12, $v29[3]
    veq         $v12, $v12, $v0[0]
    vmrg        $v3, $v3, $v31[0]
    vmudl       $v29, $v10, $v3[3]
    vmadm       $v11, $v11, $v3[3]
    vmadn       $v10, $v0, $v0[0]
    vrcph       $v13[3], $v11[3]
    vrcpl       $v12[3], $v10[3]
    vrcph       $v13[3], $v0[0]
    vmudn       $v14, $v12, $v31[4]
    vmadh       $v15, $v13, $v31[4]
    vmudh       $v29, $v1, $v31[1]
    vmadl       $v29, $v14, $v10
    vmadm       $v29, $v15, $v10
    vmadn       $v10, $v14, $v11
    vmadh       $v11, $v15, $v11
    vmudl       $v29, $v12, $v10
    vmadm       $v29, $v13, $v10
    vmadn       $v12, $v12, $v11
    vmadh       $v13, $v13, $v11
    vmudl       $v29, $v8, $v12
    luv         $v14[0], 0x10($3)
    vmadm       $v29, $v9, $v12
    llv         $v14[8], 0x14($3)
    vmadn       $v2, $v8, $v13
    luv         $v11[0], 0x10($2)
    vmadh       $v10, $v9, $v13
    llv         $v11[8], 0x14($2)
    vmudl       $v29, $v2, $v3[3]
    vmadm       $v10, $v10, $v3[3]
    vmadn       $v2, $v2, $v0[0]
    vlt         $v10, $v10, $v1[0]
    vmrg        $v2, $v2, $v31[0]
    vsubc       $v29, $v2, $v1[0]
    vge         $v10, $v10, $v0[0]
    vmrg        $v2, $v2, $v1[0]
    vmudn       $v3, $v2, $v31[0]
    vmudl       $v29, $v6, $v2[3]
    vmadm       $v29, $v7, $v2[3]
    vmadl       $v29, $v4, $v3[3]
    vmadm       $v24, $v5, $v3[3]
    vmadn       $v23, $v0, $v0[0]
    vmudm       $v29, $v14, $v2[3]
    vmadm       $v22, $v11, $v3[3]
    addi        $7, $zero, 0x0
    addi        $1, $zero, 0x2
    ori         $3, $15, 0x0
    j load_spfx_global_values
    addi        $ra, $zero, -0x6C20
line_main_join_1810:
    slv         $v25[0], 0x1C8($15)
    ssv         $v26[4], 0xCE($15)
    suv         $v22[0], 0x3C0($15)
    slv         $v22[8], 0x1C4($15)
    ssv         $v3[4], 0xCC($15)
    addi        $15, $15, -0x28
line_main_join_1828:
    bnez        $6, line_clip_plane_loop
    addi        $6, $6, -0x4
line_draw_screen_space:
    // Order endpoints by Y; select flat/smooth color, compute slopes and scissor.
    lh          $7, 0x1A($2)
    vnxor       $v2, $v0, $v31[7]
    lh          $8, 0x1A($3)
    vnxor       $v3, $v0, $v31[7]
    lw          $1, (geometryModeLabel)($zero)
    lbu         $6, 0x1E7($zero)
    sub         $11, $8, $7
    bgez        $11, line_main_join_185c
    ori         $11, $2, 0x0
    ori         $2, $3, 0x0
    ori         $3, $11, 0x0
line_main_join_185c:
    llv         $v4[0], 0x18($2)
    llv         $v5[0], 0x18($3)
    sll         $11, $1, 10
    bgez        $11, line_main_join_1884
    lbu         $9, 0x1E6($zero)
    vsub        $v8, $v5, $v4
    lpv         $v6[0], 0x10($2)
    vge         $v9, $v5, $v4
    j line_main_join_189c
    lpv         $v7[0], 0x10($3)
line_main_join_1884:
    lpv         $v6[0], 0x10($5)
    vsub        $v8, $v5, $v4
    lbv         $v6[6], 0x13($2)
    vge         $v9, $v5, $v4
    lpv         $v7[0], 0x10($5)
    lbv         $v7[6], 0x13($3)
line_main_join_189c:
    addi        $11, $zero, 0x3E0
    vabs        $v11, $v8, $v8
    ldv         $v12[0], 0x0($11)
    vlt         $v10, $v5, $v4
    lsv         $v2[14], 0x1E($2)
    vmudl       $v6, $v6, $v30[7]
    lsv         $v3[14], 0x1E($3)
    vmudl       $v7, $v7, $v30[7]
    lsv         $v6[14], 0x1C($2)
    vrcp        $v13[1], $v8[1]
    lsv         $v7[14], 0x1C($3)
    vrcph       $v14[1], $v0[0]
    llv         $v6[8], 0x14($2)
    vrcp        $v13[0], $v8[0]
    llv         $v7[8], 0x14($3)
    vrcph       $v14[0], $v0[0]
    vsubc       $v15, $v3, $v2
    vsub        $v16, $v7, $v6
    mfc2        $10, $v11[0]
    vmudl       $v29, $v13, $v31[2]
    mfc2        $13, $v11[2]
    vmadm       $v14, $v14, $v31[2]
    ldv         $v12[8], (scissorUpLeft)($zero)
    vmadn       $v13, $v0, $v0[0]
    or          $1, $1, $6
    vmudm       $v11, $v8, $v31[5]
    ori         $1, $1, 0xC8
    vmadn       $v7, $v0, $v0[0]
    sb          $1, 0x8($23)
    vmudn       $v29, $v15, $v14[1]
    mtc2        $4, $v19[0]
    vmadm       $v29, $v16, $v13[1]
    sdv         $v12[8], 0x0($23)
    vmadl       $v17, $v15, $v13[1]
    sub         $11, $10, $13
    vmadh       $v18, $v16, $v14[1]
    mtc2        $0, $v17[12]
    vmudl       $v29, $v7, $v13[1]
    mtc2        $0, $v18[12]
    vmadm       $v29, $v11, $v13[1]
    vmadn       $v7, $v7, $v14[1]
    bgtz        $11, line_main_join_1994
    vmadh       $v11, $v11, $v14[1]
    vmudn       $v20, $v4, $v31[5]
    vadd        $v22, $v0, $v0[0]
    sb          $9, 0x9($23)
    vadd        $v23, $v0, $v0[0]
    ssv         $v5[2], 0xA($23)
    vadd        $v24, $v17, $v0[0]
    ssv         $v5[2], 0xC($23)
    vadd        $v25, $v18, $v0[0]
    jal line_rdp_store_attributes
    ssv         $v4[2], 0xE($23)
    vmadn       $v20, $v19, $v31[5]
    ssv         $v7[0], 0x1E($23)
    vmadh       $v21, $v0, $v0[0]
    ssv         $v11[0], 0x1C($23)
    vmadn       $v26, $v19, $v3[0]
    ssv         $v7[0], 0x26($23)
    vmadh       $v27, $v0, $v0[0]
    j line_main_join_1a84
    ssv         $v11[0], 0x24($23)
line_main_join_1994:
    vge         $v10, $v10, $v12[0]
    mfc2        $11, $v8[0]
    vlt         $v9, $v9, $v12[2]
    vadd        $v28, $v0, $v30[7]
    vabs        $v23, $v11, $v11
    vmudl       $v29, $v28, $v12[1]
    slt         $11, $11, $zero
    vmadn       $v10, $v10, $v30[5]
    sll         $11, $11, 7
    vmudl       $v29, $v28, $v12[3]
    or          $9, $9, $11
    vmadn       $v9, $v9, $v30[5]
    sb          $9, 0x9($23)
    vmudl       $v29, $v15, $v13[0]
    mfc2        $12, $v23[0]
    vmadm       $v29, $v16, $v13[0]
    addi        $11, $23, 0x1
    vmadn       $v22, $v15, $v14[0]
    ssv         $v10[0], 0x0($11)
    vmadh       $v23, $v16, $v14[0]
    ssv         $v9[0], 0x4($11)
    vadd        $v14, $v4, $v19[0]
    beq         $7, $8, line_main_join_1a44
    addi        $12, $12, -0x755
    vsub        $v13, $v4, $v19[0]
    bgtz        $12, line_main_join_1a48
    vadd        $v28, $v5, $v19[0]
    vmudn       $v20, $v13, $v31[5]
    ssv         $v28[2], 0xA($23)
    vadd        $v24, $v0, $v0[0]
    ssv         $v14[2], 0xC($23)
    vadd        $v25, $v0, $v0[0]
    ssv         $v13[2], 0xE($23)
    jal line_rdp_store_attributes
    ssv         $v7[0], 0x16($23)
    ssv         $v11[0], 0x14($23)
    vmudm       $v27, $v4, $v31[5]
    ssv         $v7[0], 0x1E($23)
    vmadn       $v26, $v0, $v0[0]
    ssv         $v11[0], 0x1C($23)
    slv         $v0[0], 0x24($23)
    ssv         $v27[0], 0x10($23)
    j line_main_join_1a84
    ssv         $v26[0], 0x12($23)
line_main_join_1a44:
    vsub        $v13, $v4, $v19[0]
line_main_join_1a48:
    vmudm       $v21, $v4, $v31[5]
    xori        $9, $9, 0x80
    vmadn       $v20, $v0, $v0[0]
    sb          $9, 0x9($23)
    vmudm       $v27, $v5, $v31[5]
    slv         $v0[0], 0x1C($23)
    vmadn       $v26, $v0, $v0[0]
    slv         $v0[0], 0x24($23)
    vadd        $v17, $v0, $v0[0]
    ssv         $v13[2], 0xE($23)
    vadd        $v18, $v0, $v0[0]
    ssv         $v14[2], 0xC($23)
    vadd        $v24, $v0, $v0[0]
    ssv         $v14[2], 0xA($23)
    vadd        $v25, $v0, $v0[0]
line_main_join_1a84:
    ssv         $v21[0], 0x18($23)
    vmov        $v6[6], $v1[0]
    ssv         $v20[0], 0x1A($23)
    vmov        $v2[6], $v0[0]
    ssv         $v27[0], 0x20($23)
    vmudn       $v5, $v2, $v30[6]
    ssv         $v26[0], 0x22($23)
    vmadh       $v8, $v6, $v30[6]
    addi        $23, $23, 0x28
    vmudn       $v9, $v22, $v30[6]
    andi        $11, $1, 0x4
    vmadh       $v10, $v23, $v30[6]
    vmudn       $v12, $v17, $v30[6]
    beqz        $11, line_main_join_1ae0
    andi        $11, $1, 0x2
    sdv         $v6[0], 0x0($23)
    sdv         $v23[0], 0x8($23)
    sdv         $v22[0], 0x18($23)
    sdv         $v18[0], 0x20($23)
    sdv         $v25[0], 0x28($23)
    sdv         $v17[0], 0x30($23)
    sdv         $v24[0], 0x38($23)
    addi        $23, $23, 0x40
line_main_join_1ae0:
    vmadh       $v13, $v18, $v30[6]
    beqz        $11, line_main_join_1b10
    andi        $11, $1, 0x1
    addi        $23, $23, 0x40
    sdv         $v6[8], 0x3C0($23)
    sdv         $v2[8], 0x3D0($23)
    sdv         $v23[8], 0x3C8($23)
    sdv         $v22[8], 0x3D8($23)
    sdv         $v18[8], 0x3E0($23)
    sdv         $v17[8], 0x3F0($23)
    sdv         $v25[8], 0x3E8($23)
    sdv         $v24[8], 0x3F8($23)
line_main_join_1b10:
    beqz        $11, line_main_join_1288
    lhu         $ra, (lineClipReturn)($zero)
    ssv         $v8[14], 0x0($23)
    addi        $23, $23, 0x10
    ssv         $v5[14], 0xF2($23)
    vmudn       $v24, $v24, $v30[6]
    ssv         $v10[14], 0xF4($23)
    vmadh       $v25, $v25, $v30[6]
    ssv         $v9[14], 0xF6($23)
    ssv         $v13[14], 0xF8($23)
    ssv         $v12[14], 0xFA($23)
    ssv         $v25[14], 0xFC($23)
    j line_main_join_1288
    ssv         $v24[14], 0xFE($23)
line_rdp_store_attributes:
    // Store vector-derived line edge/attribute coefficients into the RDP buffer.
    vsubc       $v20, $v0, $v20
    vsub        $v21, $v0, $v0
    vmudn       $v29, $v2, $v1[0]
    vmadh       $v29, $v6, $v1[0]
    vmadl       $v29, $v17, $v20[1]
    vmadm       $v29, $v18, $v20[1]
    vmadn       $v2, $v17, $v21[1]
    vmadh       $v6, $v18, $v21[1]
    vmudn       $v29, $v4, $v31[5]
    vmadl       $v29, $v7, $v20[1]
    vmadm       $v29, $v11, $v20[1]
    sdv         $v2[0], 0x38($23)
    vmadn       $v20, $v7, $v21[1]
    jr          $ra
    vmadh       $v21, $v11, $v21[1]
G_CULLDL_handler:
    lhu         $25, 0x380($25)
    lhu         $24, 0x380($24)
    addiu       $1, $zero, 0x7070
    lw          $11, 0x24($25)
line_main_join_1b94:
    and         $1, $1, $11
    beqz        $1, G_SPECIAL_3_handler
    lw          $11, 0x4C($25)
    bne         $25, $24, line_main_join_1b94
    addiu       $25, $25, 0x28
    j G_ENDDL_handler
G_BRANCH_WZ_handler:
    lhu         $25, 0x380($25)
    lw          $25, 0x1C($25)
    sub         $2, $25, $24
    bgez        $2, G_SPECIAL_3_handler
    lw          $24, (rdpHalf1Val)($zero)
    j line_ovl1_join_1008
G_MODIFYVTX_handler:
    lbu         $1, 0x989($27)
    j line_modify_vertex_store
    lhu         $25, 0x380($25)
.fill 0x1FAC - ., 0 // Unused IMEM instruction space before DMA tail.
G_LOAD_UCODE_handler:
load_overlay_0_and_enter:
    addi        $12, $zero, G_DL_handler
    addi        $11, $zero, 0x2E0
load_overlay_and_enter:
    lw          $24, 0x0($11)
    lhu         $19, 0x4($11)
    jal dma_read_write
    lhu         $20, 0x6($11)
    ori         $ra, $12, 0x0
while_wait_dma_busy:
    mfc0        $11, SP_DMA_BUSY
while_dma_busy:
    bnez        $11, while_dma_busy
    mfc0        $11, SP_DMA_BUSY
return_routine:
    jr          $ra
dma_read_write:
    mfc0        $11, SP_DMA_FULL
while_dma_full:
    bnez        $11, while_dma_full
    mfc0        $11, SP_DMA_FULL
    mtc0        $20, SP_MEM_ADDR
    bltz        $20, dma_write
    mtc0        $24, SP_DRAM_ADDR
    jr          $ra
    mtc0        $19, SP_RD_LEN
dma_write:
    jr          $ra
    mtc0        $19, SP_WR_LEN
.headersize 0x1000 - orga()
// Task end/yield/new-ucode overlay: flush RDP, DMA and halt.
ovl0_start:
    ldv         $v29[0], (scissorUpLeft)($zero)
    addi        $23, $23, 0x8
    sdv         $v29[0], 0x3F8($23)
    sub         $11, $23, $22
    addiu       $12, $11, 0x1E7
    bgezal      $12, line_main_join_1290
    nop
    jal while_wait_dma_busy
    lw          $24, (rdpFifoPos)($zero)
    bltz        $1, line_ovl0_join_1090
    mtc0        $24, DPC_END
    bnez        $1, line_ovl0_join_106c
    add         $26, $26, $27
    lw          $24, 0x98C($27)
    sw          $26, (OSTask + OS_TASK_OFF_DATA)($zero)
    sw          $24, (OSTask + OS_TASK_OFF_UCODE)($zero)
    addiu       $20, $zero, 0x1080
    jal dma_read_write
    addi        $19, $zero, 0xF47
    lw          $24, (rdpHalf1Val)($zero)
    addiu       $20, $zero, 0x180
    andi        $19, $25, 0xFFF
    add         $24, $24, $20
    jal dma_read_write
    sub         $19, $19, $20
    j while_wait_dma_busy
    addi        $ra, $zero, line_ovl0_join_1084
line_ovl0_join_106c:
    lw          $11, (OSTask + OS_TASK_OFF_UCODE)($zero)
    sw          $26, 0xBF8($zero)
    sw          $11, 0xBFC($zero)
    addi        $12, $zero, 0x5000
    lw          $24, (line_task_yield)($zero)
    addi        $20, $zero, -0x8000
line_ovl0_join_1084:
    addi        $19, $zero, 0xBFF
    j dma_read_write
    addi        $ra, $zero, line_ovl0_join_1094
line_ovl0_join_1090:
    addi        $12, $zero, 0x4000
line_ovl0_join_1094:
    mtc0        $12, SP_STATUS
    break
    nop
ovl0_end:
.headersize 0x1000 - orga()
// Command overlay: display-list stack, matrix multiply and DMA, render modes.
G_DL_handler:
ovl1_start:
    lbu         $1, (displayListStackLength)($zero)
    sll         $2, $25, 15
line_ovl1_join_1008:
    jal segmented_to_physical
    add         $3, $26, $27
    bltz        $2, displaylist_dma
    ori         $26, $24, 0x0
    sw          $3, 0x138($1)
    addi        $1, $1, 0x4
line_displaylist_enter:
    j displaylist_dma
    sb          $1, (displayListStackLength)($zero)
G_TEXTURE_handler:
    addi        $11, $zero, 0x1140
G_TEXRECT_handler:
G_TEXRECTFLIP_handler:
    sw          $25, -0xF5C($11)
G_RDPHALF_1_handler:
    j G_SPECIAL_3_handler
    sw          $24, -0xF58($11)
G_MOVEWORD_handler:
    srl         $2, $25, 16
    lhu         $1, 0x27FE($2)
line_modify_vertex_store:
    add         $1, $1, $25
    j G_SPECIAL_3_handler
    sw          $24, 0x0($1)
G_POPMTX_handler:
    lw          $11, (matrixStackPtr)($zero)
    lw          $2, (OSTask + OS_TASK_OFF_STACK)($zero)
    sub         $24, $11, $24
    sub         $1, $24, $2
    bgez        $1, line_ovl1_join_1068
    nop
    ori         $24, $2, 0x0
line_ovl1_join_1068:
    beq         $24, $11, G_SPECIAL_3_handler
    sw          $24, (matrixStackPtr)($zero)
    j line_matrix_dma
    sw          $zero, (mvpValid)($zero)
G_MTX_end:
    lhu         $19, 0x2F2($1)
    jal while_wait_dma_busy
    lhu         $21, 0x2F2($1)
    addi        $ra, $zero, G_SPECIAL_3_handler
    addi        $12, $20, 0x18
line_ovl1_join_108c:
    vmadn       $v9, $v0, $v0[0]
    addi        $11, $20, 0x8
    vmadh       $v8, $v0, $v0[0]
    addi        $21, $21, -0x20
    vmudh       $v29, $v0, $v0[0]
line_ovl1_join_10a0:
    ldv         $v5[0], 0x40($21)
    ldv         $v5[8], 0x40($21)
    lqv         $v3[0], 0x20($20)
    ldv         $v4[0], 0x20($21)
    ldv         $v4[8], 0x20($21)
    lqv         $v2[0], 0x0($20)
    vmadl       $v29, $v5, $v3[0h]
    addi        $20, $20, 0x2
    vmadm       $v29, $v4, $v3[0h]
    addi        $21, $21, 0x8
    vmadn       $v7, $v5, $v2[0h]
    bne         $20, $11, line_ovl1_join_10a0
    vmadh       $v6, $v4, $v2[0h]
    bne         $20, $12, line_ovl1_join_108c
    addi        $20, $20, 0x8
    sqv         $v9[0], 0x20($19)
    sqv         $v8[0], 0x0($19)
    sqv         $v7[0], 0x30($19)
    jr          $ra
    sqv         $v6[0], 0x10($19)
G_MTX_handler:
    andi        $11, $25, 0x5
    bnez        $11, line_ovl1_join_1118
    andi        $2, $25, 0x2
    lw          $24, (matrixStackPtr)($zero)
    addi        $20, $zero, -0x2000
    jal dma_read_write
    addi        $19, $zero, 0x3F
    addi        $24, $24, 0x40
    sw          $24, (matrixStackPtr)($zero)
    lw          $24, 0x98C($27)
line_ovl1_join_1118:
    add         $12, $12, $2
    sw          $zero, (mvpValid)($zero)
G_MOVEMEM_handler:
    jal segmented_to_physical
line_matrix_dma:
    andi        $1, $25, 0xFE
    lbu         $19, 0x989($27)
    lhu         $20, 0x2F0($1)
    srl         $2, $25, 5
    lhu         $ra, 0x336($12)
    j dma_read_write
G_SETOTHERMODE_H_handler:
    add         $20, $20, $2
G_SETOTHERMODE_L_handler:
    lw          $3, -0x1074($11)
    lui         $2, 0x8000
    srav        $2, $2, $25
    srl         $1, $25, 8
    srlv        $2, $2, $1
    not         $2, $2
    and         $3, $3, $2
    or          $3, $3, $24
    sw          $3, -0x1074($11)
    lw          $25, (otherMode0)($zero)
    j G_RDP_handler
    lw          $24, (otherMode1)($zero)
ovl1_end:
.close
