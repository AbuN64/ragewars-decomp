#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
typedef struct DraftUi06434 { u8 pad[0x554]; char message[1]; } DraftUi06434;
typedef struct DraftPlayer06434 { u8 pad[0x5D8]; ProfileRecAt84 *settings; DraftUi06434 *ui; u8 pad5E0[0xB8]; void *model; } DraftPlayer06434;
typedef struct DraftSlot06434 { u8 pad[4]; s8 channel; } DraftSlot06434;
typedef struct DraftMenu06434 { u8 pad[0x1C]; DraftPlayer06434 *player; DraftSlot06434 *slot; } DraftMenu06434;
extern s32 D_8014D4C0_de, D_8014D4DC, D_80153760, D_8014D4EC_de, D_800DE874, D_80153784, D_8015375C, D_800E28C0, D_800E28C8;
typedef struct DraftSaved06434 { u16 values[4]; u8 flag, pad[3], bytes[8]; u32 checksum; } DraftSaved06434;
extern DraftSaved06434 D_80153738;
extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[], D_0044EA08[], D_0044ED44[], D_0044E48C[], D_0044E9C0[], D_8014561C[];
extern void func_80404E28_de(s32), func_80405F48_de(void *), func_80442574_de(void *, void *, void *, void *, void *);
extern s32 func_80404F04_de(s32), func_80404F3C_de(s32), func_80405598_de(s32);
extern u32 func_804057F8_de(void *, u32, u32);
void func_80406434_de(DraftMenu06434 *menu)
{
    DraftPlayer06434 *player;
    ProfileRecAt84 *settings;
    s32 channel, i;
    char *prompt;
    D_8014D4C0_de = 1; D_8014D4DC = 1; D_80153760 = 0; D_8014D4EC_de = 1;
    D_800DE874 = 0; D_80153784 = 0; D_8015375C = 0;
    channel = menu->slot->channel;
    player = menu->player;
    if (channel == 1) prompt = D_00450C14_de;
    else if (channel < 2) prompt = D_00450BF0_de;
    else if (channel == 2) prompt = D_00450C38_de;
    else if (channel == 3) prompt = D_00450C5C_de;
    else prompt = D_00450BF0_de;
    if (D_800E28C0) {
        D_80153784 = 1;
        func_80442574_de(menu->player->ui->message, prompt, player, player->model, 0);
        return;
    }
    if (D_8015375C) func_80404E28_de(D_800E28C8);
    else func_80404E28_de(menu->slot->channel);
    if (!func_80404F04_de(channel)) {
        settings = player->settings;
        D_80153738.flag = settings->flags;
        D_80153738.values[0] = settings->words[0];
        D_80153738.values[1] = settings->words[1];
        D_80153738.values[2] = settings->words[2];
        D_80153738.values[3] = settings->words[3];
        D_80153738.pad[0] = D_80153738.pad[1] = D_80153738.pad[2] = 0;
        for (i = 0; i < 8; i++) {
            D_80153738.bytes[i] = settings->name[i];
        }
        D_80153738.checksum = func_804057F8_de(&D_80153738, 0x14, 4);
        func_80405F48_de(menu);
        return;
    }
    D_80153784 = 1;
    if (func_80404F3C_de(channel)) func_80442574_de(D_8014561C, D_0044EA08, player, player->model, prompt);
    else if (func_80405598_de(channel)) func_80442574_de(D_8014561C, D_0044ED44, player, player->model, D_0044E48C);
    else func_80442574_de(D_8014561C, D_0044E9C0, player, player->model, prompt);
}
