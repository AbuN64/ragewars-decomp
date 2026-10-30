#ifndef MIPS_ENCODE_H
#define MIPS_ENCODE_H

/* Instruction word encoders for code that data tables hold as words (exception vector patches). */
#define MIPS_K0 26
#define MIPS_MTC0(rt, rd) (0x40800000 | ((rt) << 16) | ((rd) << 11))
#define MIPS_LUI(rt, imm) (0x3C000000 | ((rt) << 16) | (imm))
#define MIPS_ADDIU(rt, rs, imm) (0x24000000 | ((rs) << 21) | ((rt) << 16) | (imm))
#define MIPS_ORI(rt, rs, imm) (0x34000000 | ((rs) << 21) | ((rt) << 16) | (imm))
#define MIPS_JR(rs) (((rs) << 21) | 0x08)
#define MIPS_NOP 0
#define C0_ERROR_EPC 30

#endif
