#include "include_asm.h"
#include "COMMON/PAK_MENU.H"

INCLUDE_ASM("ovl_80400000", func_80405DC0_de);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_ASM("ovl_80400000", func_80405F48_de);
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
extern s32 D_800E28C8, D_800DE874;
extern char *D_800D36D4, *D_800D36D8, *D_800D36DC;

extern s32 D_8015375C;

extern char *D_800D36E0;

extern s32 func_8040458C_de(s32 ch, s32 index, s32 *exists, char *name, char *ext, s32 *size,
                         char *company, char *code);
extern s32 func_802A0238_de(char *);
extern s32 func_802A037C_de(char *a, char *b);

void func_80405F48_de(Shared_PakMenu *menu) {
    s32 ch;
    s32 i;
    s32 other;
    s32 result;
    s32 match;
    char *title;
    char ext[8];
    char company[8];
    char code[8];
    char name[16];
    s32 exists;
    s32 size;

    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->owner->unk4;
    }
    for (i = 0; i < 16; i++) {
        result = func_8040458C_de(ch, i, &exists, name, ext, &size, company, code);
        other = 1;
        if (result == 0 && exists != 0) {
            switch (D_800DE874) {
                case 1:
                    if (func_802A0238_de(code) == 4 && func_802A0238_de(company) == 2 &&
                        func_802A037C_de(code, D_800D36E0) == 0 && func_802A037C_de(company, D_800D36DC) == 0) {
                        match = 1;
                    } else {
                        match = 0;
                    }
                    title = D_800D36D4;
                    break;
                case 2:
                    if (func_802A0238_de(code) == 4 && func_802A0238_de(company) == 2 &&
                        func_802A037C_de(code, D_800D36E0) == 0 && func_802A037C_de(company, D_800D36DC) == 0) {
                        match = 1;
                    } else {
                        match = 0;
                    }
                    title = D_800D36D8;
                    break;
                case 0:
                default:
                    other = 0;
                    goto done;
            }
            if (func_802A037C_de(name, title) == 0 && match != 0) {
                other = 0;
            }
        }
    done:
        if (other) {
            menu->items[i + 3].flags &= ~0x1000000;
        } else {
            menu->items[i + 3].flags |= 0x1000000;
        }
    }
}
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RECORDRECAT1C.H"
extern s32 D_8014D4C0_de, D_8014D4EC_de, D_8015375C, D_80153760, D_80153784, D_800E28C8;
extern char D_8014561C[], D_0044E4F8[], D_0044FFA4[], D_0044FB50[];
extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
extern char D_0044EA98[], D_0044E9C0[], D_0044ED44[], D_0044EA2C[], D_0044EA08[], D_0044E9E4[];
extern void func_80404E28_de(s32);
extern s32 func_80404F04_de(s32), func_80404F3C_de(s32), func_80405598_de(s32), func_80264580_de(s32);
extern void func_80442574_de(char *, char *, ObjRecAt5DC *, PakMenuSlot *, char *);
s32 func_80406178_de(Menu_func_804066BC_de *menu, s32 channel, s32 quiet)
{
    s32 result, busy, slot;
    char *prompt = 0;
    char *message;
    func_80404E28_de(channel);
    result = func_80404F04_de(channel);
    if (D_8014D4C0_de) {
        if (D_8014D4EC_de) {
            if (D_8015375C) slot = D_800E28C8;
            else slot = menu->slot->unk4;
            if (slot == 1) prompt = D_00450C14_de;
            else if (slot < 2) prompt = D_00450BF0_de;
            else if (slot == 2) prompt = D_00450C38_de;
            else if (slot == 3) prompt = D_00450C5C_de;
            else prompt = D_00450BF0_de;
        }
    } else if (D_80153760) {
        prompt = D_0044FFA4;
        if (D_8014D4EC_de) prompt = D_0044FB50;
    } else if (D_8015375C) prompt = D_0044E4F8;
    if (!prompt) return 0;
    busy = func_80264580_de(channel);
    if ((result == 0 || busy != 0) && result != -2) {
        if (busy) {
            func_80442574_de(D_8014561C, D_0044EA98, menu->player, menu->slot, prompt);
            return -1;
        }
        return result;
    }
    if (func_80404F3C_de(channel)) {
        D_80153784 = 1;
        if (D_8015375C) message = D_0044E9E4;
        else {
            message = D_0044EA2C;
            if (D_8014D4C0_de) message = D_0044EA08;
        }
        func_80442574_de(D_8014561C, message, menu->player, menu->slot, prompt);
    } else if (!quiet) {
        D_80153784 = 1;
        if (func_80405598_de(channel))
            func_80442574_de(D_8014561C, D_0044ED44, menu->player, menu->slot, prompt);
        else func_80442574_de(D_8014561C, D_0044E9C0, menu->player, menu->slot, prompt);
    } else if (result != -2) result = 0;
    return result;
}
#else
INCLUDE_ASM("ovl_80400000", func_80406178_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
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
#else
INCLUDE_ASM("ovl_80400000", func_80406434_de);
#endif
