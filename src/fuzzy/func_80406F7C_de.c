#include "types.h"
typedef struct SaveOwner { u8 pad0[0x554]; u32 list; } SaveOwner;
typedef struct SavePlayer { u8 pad0[0x5dc]; SaveOwner *owner; u8 pad5e0[0xb8]; s32 value; } SavePlayer;
typedef struct SaveInfo { u8 pad0[4]; s8 id; } SaveInfo;
typedef struct SaveRequest { u8 pad0[0x1c]; SavePlayer *player; SaveInfo *info; } SaveRequest;
typedef struct SaveBuffer { u8 pad0[0x60c]; u32 checksums[0]; } SaveBuffer;
extern s32 D_8014D4C0_de,D_8014D4DC,D_80153760,D_8014D4EC_de,D_800DE874,D_80153784,D_8015375C,D_800E28C0,D_800DE868;
extern SaveBuffer *D_8011FECC;
extern u32 D_8014561C;
extern u8 D_0044EA08[],D_0044ED44[],D_0044E4D4[];
extern void func_80404E28_de(s32);
extern s32 func_80404F04_de(s32),func_80404F3C_de(s32),func_80405598_de(s32);
extern void func_80405DC0_de(SavePlayer *);
extern u32 func_804057F8_de(s32,void *,s32);
extern void func_80405F48_de(SaveRequest *);
extern void *func_80442574_de(void *,void *,SavePlayer *,s32,u32);
void func_80406F7C_de(SaveRequest *request) {
    s32 id;
    SavePlayer *player;
    u32 sum;
    D_8014D4C0_de = 1;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 0;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 0;
    id = request->info->id;
    player = request->player;
    if (D_800E28C0 != 0) { D_80153784 = 1; return; }
    func_80404E28_de(request->info->id);
    if (func_80404F04_de(id) == 0) {
        func_80405DC0_de(player);
        sum = func_804057F8_de(D_800DE868,D_8011FECC->checksums,11);
        D_8011FECC->checksums[D_800DE868 / 4] = sum;
        func_80405F48_de(request);
    } else {
        D_80153784 = 1;
        if (func_80404F3C_de(id) != 0) {
            func_80442574_de(&player->owner->list,D_0044EA08,player,player->value,1);
        } else {
            if (func_80405598_de(id) == 0) return;
            func_80442574_de(&D_8014561C,D_0044ED44,player,player->value,(u32)D_0044E4D4);
        }
    }
}
