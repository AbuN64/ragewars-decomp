Rage Wars us-rev1 RSP resources

These sources describe the resident microcode resources with instructions,
labels, matrices, vectors, command dispatch and overlay tables. They contain
no ROM instruction arrays or binary imports.

ROM range        Resident address  Source / assembler output
DD834-DD83C       800DCC34          alignment.s / .rsp.alignment
DD83C-DD840       800DCC3C          Unresolved four-byte pre-boot span
DD840-DD910       800DCC40          boot.s / .rsp.boot
DD910-DECA0       800DCD10          graphics/f3dex2.s / code
DECA0-DFE30       800DE0A0          graphics/l3dex2.s / code
DFE30-E0C50       800DF230          audio.s / code
E0C50-E1070       800E0050          graphics/f3dex2.s / data
E1070-E1460       800E0470          graphics/l3dex2.s / data
E1460-E1720       800E0860          audio.s / data

The GNU boot section links at execution VMA 04001000 and resident LMA
800DCC40. Its first jump is 04001064. The host task boot entry is DD840;
the unresolved preceding word is outside the task's boot resource.

The audio source executes at 04001080. The graphics sources use the RSP
assembler's 1080 IMEM coordinates and switch .headersize for overlays that
execute at 1000. ARMIPS resolves those instruction and native table labels;
resident storage addresses must not replace the sources' IMEM coordinates.
All three programs use DMEM data address zero. Each program's code and data
outputs are a pair and must be built from the same source and flags.

Run the *-native.sh scripts from the repository root for bounded source-native
builds and literal ROM comparisons. boot-native.sh uses GNU MIPS binutils.
The vector scripts accept ARMIPS=/path/to/armips. The graphics scripts run
the C preprocessor with the bundled PR/rsp definitions before ARMIPS.
For ordinary builds, use the resource rows in versions/us-rev1/RageWars.yaml
and the generated Makefile resource targets, with ARMIPS set explicitly.

The scalar boot and audio sources refer to n64decomp/sm64's CC0 sources:
https://github.com/n64decomp/sm64/tree/master/rsp
See LICENSE.sm64.CC0.txt. The graphics common definitions and F3DEX2 program
are adapted from Mr-Wiseguy/f3dex2 commit
bd31393fd02b89e024b043c8c50c9a5a10143fb6 (graphics/LICENSE, CC0-1.0).
https://github.com/Mr-Wiseguy/f3dex2
The Rage Wars proximity-light additions and line-resource instructions were
recovered from the owner ROM. The embedded Nintendo identification strings
are preserved verbatim as resource data, independently of those attributions.
