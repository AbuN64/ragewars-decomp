#include "span_16E000/code_80429C10.h"
#include "types.h"
/* When the global session is mode 3 with no pending state and the caller's high word and empty flag agree, resets the mode, restarts five subsystems and queues one status message. */





extern G *D_800E4F60;
extern s32 D_80154020;

extern void func_8029973C_de(void);
extern void func_8042A7B4_de(s32 a0);
extern void func_8040E8D8_de(s32 a0, s32 a1);
extern void func_8025DF34_de(s32 a0);

s32 func_8042B3DC_de(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 v = D_800E4F60->unk3DC;

    if (v != 3) {
        return 0;
    }
    if (D_80154020 != -1) {
        return 0;
    }
    if ((u32)a2 >> 16 != v) {
        return 0;
    }
    if (a3 != 0) {
        return 0;
    }

    func_8029973C_de();
    D_800E4F60->unk3DC = 8;
    func_8042A7B4_de(0x41);

    func_8040E8D8_de(D_800E4F60->unk440, 0);
    func_8040E8D8_de(D_800E4F60->unk444, 0);
    func_8040E8D8_de(D_800E4F60->unk448, 0);
    func_8040E8D8_de(D_800E4F60->unk3EC, 0);
    func_8040E8D8_de(D_800E4F60->unk3F0, 0);

    D_800E4F60->unk44C->value = 0x5A;
    func_8025DF34_de(0xE7C);

    return 0;
}
