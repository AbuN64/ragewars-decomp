#ifndef UNBAKE_SPAN_16E000_CODE_8041C67C_H
#define UNBAKE_SPAN_16E000_CODE_8041C67C_H
#include "TYPES.H"
#include "span_16E000/code_80403BCC.h"
#include "common/types_1dc8418c21db.h"


struct __OSContRequesFormatShort;
typedef struct __OSContRequesFormatShort __OSContRequesFormatShort;

struct __OSContRequesFormatShort;
struct __OSContRequesFormatShort {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
};

extern s32 func_80448BFC_de(OSPfs *pfs);
extern s32 func_804480E0_de(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no);
extern s32 func_80446C60_de(OSPfs *pfs, s32 *bytes_not_used);
extern s32 func_804488A4_de(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
extern s32 func_80446324_de(OSPfs *pfs, __OSInode *inode, int file_size_in_pages, int *first_page, u8 bank,
                         int *decleared, int *last_page);
extern s32 func_804464F0_de(OSPfs *pfs, int page_no, u8 *data, u8 bank);
extern s32 func_80448CC4_de(OSPfs *pfs);
extern s32 func_80448CC4_de(OSPfs *pfs);
extern s32 func_80448BFC_de(OSPfs *pfs);
extern s32 func_804480E0_de(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no);
extern s32 func_804488A4_de(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
extern s32 func_804467AC_de(OSPfs *pfs, __OSInode *inode, u8 start_page, u16 *sum, u8 bank,
                         __OSInodeUnit *last_page, int flag);
extern s32 func_8044694C_de(OSPfs *pfs, u8 page_no, u16 *sum, u8 bank);
extern s32 func_80448CC4_de(OSPfs *pfs);

extern void func_80446E58_de(int channel);
extern void func_80446EE4_de(int channel, EntryRecAt3 *data);

#endif
