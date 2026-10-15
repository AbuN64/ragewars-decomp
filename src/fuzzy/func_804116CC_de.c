#include "types.h"

typedef struct { s32 offset, size; void *data; } FileBlock;
typedef struct { u8 pad0[0x23C]; s32 dataOffset; } ArchiveHeader;
extern FileBlock *D_8014D9B4, *D_8014D9B8;
extern u16 *D_8014D9C0;
extern s32 D_8014D9C4, D_800E2AC4;
extern ArchiveHeader D_8014D724;
extern s32 D_801539B0;
extern char D_800DD0B0;
extern void *func_8025305C_de(s32);
extern void func_802A0724_de(void *, const void *, s32);
extern void func_8040F6DC_de(void *, void *, s32);
extern f64 func_802A18CC_de(void);
extern s32 func_802A0E8C_de(void *, void *);
extern void func_802A0F60_de(s32, s32, s32);
extern void func_802A0ED4_de(void *, s32, s32, s32);
extern void func_802A0EB0_de(s32);

void func_804116CC_de(s32 index) {
    void *data;
    D_8014D9C0[index]++;
    if (D_8014D9C4 == 1) {
        if (D_8014D9B4[index].data == 0) goto load;
        func_802A0724_de(D_8014D9B4[index].data, D_8014D9B8[index].data, D_8014D9B4[index].size);
        data = D_8014D9B4[index].data;
        func_8040F6DC_de(data, data, D_8014D9B4[index].offset - D_8014D9B4[0].offset);
    }
    if (D_8014D9B4[index].data != 0) return;
load:
    func_802A18CC_de();
    D_8014D9B4[index].data = func_8025305C_de(D_8014D9B4[index].size);
    D_801539B0 = func_802A0E8C_de(&D_8014D724, &D_800DD0B0);
    func_802A0F60_de(D_801539B0, D_8014D724.dataOffset + D_8014D9B4[index].offset, 0);
    func_802A0ED4_de(D_8014D9B4[index].data, D_8014D9B4[index].size, 1, D_801539B0);
    if (D_800E2AC4 != 0) {
        D_8014D9B8[index].data = func_8025305C_de(D_8014D9B4[index].size);
        func_802A0724_de(D_8014D9B8[index].data, D_8014D9B4[index].data, D_8014D9B4[index].size);
    }
    func_802A0EB0_de(D_801539B0);
    D_801539B0 = 0;
    data = D_8014D9B4[index].data;
    func_8040F6DC_de(data, data, D_8014D9B4[index].offset - D_8014D9B4[0].offset);
    func_802A18CC_de();
}
