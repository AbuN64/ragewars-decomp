#include "include_asm.h"
#include "COMMON/PAK_MENU.H"

#ifdef NON_MATCHING
typedef struct Copy70 { s32 words[28]; } Copy70;
typedef struct Copy580 { s32 words[0x160]; } Copy580;
extern u8 *D_8011FECC;
extern void *D_800DE860_de;
extern u8 *D_800DE868;
extern u8 D_800DCD60[];
extern u8 D_801462C8[];
extern f32 D_801468A0[];
extern u8 D_800F91F0[];
extern void func_80253908_de(s32);
extern void func_80253838_de(s32, void *);
extern u32 *func_8025343C_de(s32, void *, s32, void *);
extern void func_802A001C_de(u32, s32, void *);
extern void func_802BD3A0_de(void *, void *, void *);
void func_80405DC0_de(u8 *arg0) {
    u8 *base = D_8011FECC + 0x610;
    u8 *region;
    u32 *entry;
    if (D_800DE860_de != 0) {
        func_80253908_de(0);
        func_80253838_de(0, D_800DE860_de);
    }
    region = D_8011FECC + 0x610;
    entry = func_8025343C_de(0, region, 0x33, D_800DCD60);
    D_800DE860_de = entry;
    D_800DE868 = (u8 *)*entry;
    func_802A001C_de(*entry, 0, region);
    *(Copy70 *)(D_800DE868 + 0x18) = *(Copy70 *)(arg0 + 0x5E0);
    *(Copy580 *)(D_800DE868 + 0x88) = *(Copy580 *)D_801462C8;
    *(u32 *)(D_800DE868 + 0x608) = *(u32 *)(D_801462C8 + 0x580);
    *(f32 *)(D_800DE868 + 8) = D_801468A0[0];
    *(f32 *)(D_800DE868 + 0xC) = D_801468A0[1];
    *(f32 *)(D_800DE868 + 0x10) = D_801468A0[2];
    *(u8 **)D_800DE868 = base;
    *(f32 *)(D_800DE868 + 0x14) = D_801468A0[3];
    *(u8 **)(D_800DE868 + 4) = D_8011FECC;
    func_802BD3A0_de(D_800DE868 + 0x60C, D_800F91F0, D_8011FECC);
}
#else
INCLUDE_ASM("ovl_80400000", func_80405DC0_de);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("ovl_80400000", func_80405F48_de);
#endif
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern char *D_800E25D4[];
extern char *D_800E25C4[];
extern char *D_800E25A4[];
extern char *D_800E25B4[];
#define PAK_CODE D_800E25D4[D_80152789]
#define PAK_COMPANY D_800E25C4[D_80152789]
#define PAK_TITLE1 D_800E25A4[((u8 *)&D_801462C8)[0x581]]
#define PAK_TITLE2 D_800E25B4[((u8 *)&D_801462C8)[0x581]]
#else
#define PAK_CODE D_800D36E0
#define PAK_COMPANY D_800D36DC
#define PAK_TITLE1 D_800D36D4
#define PAK_TITLE2 D_800D36D8
#endif
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
                        func_802A037C_de(code, PAK_CODE) == 0 && func_802A037C_de(company, PAK_COMPANY) == 0) {
                        match = 1;
                    } else {
                        match = 0;
                    }
                    title = PAK_TITLE1;
                    break;
                case 2:
                    if (func_802A0238_de(code) == 4 && func_802A0238_de(company) == 2 &&
                        func_802A037C_de(code, PAK_CODE) == 0 && func_802A037C_de(company, PAK_COMPANY) == 0) {
                        match = 1;
                    } else {
                        match = 0;
                    }
                    title = PAK_TITLE2;
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

extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
static __inline__ char *pakPrompt(s32 *channel) {
    char *result;
    switch (*channel) {
    case 0:
    default: result = D_00450BF0_de; break;
    case 1: result = D_00450C14_de; break;
    case 2: result = D_00450C38_de; break;
    case 3: result = D_00450C5C_de; break;
    }
    return result;
}
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RECORDRECAT1C.H"
#include "MENU/80405DC0.H"
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
    char *prompt, *sel;
    char *message;
    func_80404E28_de(channel);
    result = func_80404F04_de(channel);
    sel = 0;
    if (D_8014D4C0_de) {
        if (D_8014D4EC_de) {
            if (D_8015375C) slot = D_800E28C8;
            else slot = menu->slot->unk4;
            sel = pakPrompt(&slot);
        }
    } else if (D_80153760) {
        sel = D_0044FFA4;
        if (D_8014D4EC_de) sel = D_0044FB50;
    } else if (D_8015375C) sel = D_0044E4F8;
    prompt = sel;
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
            if (D_8014D4C0_de) message = D_0044EA08;
            else message = D_0044EA2C;
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

#include "COMMON/SHAREDPLAYER.H"
extern s32 D_8014D4C0_de, D_8014D4DC, D_80153760, D_8014D4EC_de, D_800DE874, D_80153784, D_8015375C, D_800E28C0, D_800E28C8;
extern struct Saved D_80153738;
extern struct { u8 value; } D_8014D4B0_de;
extern u8 D_8014D4B1, D_8014D4B2, D_8014D4B3;
extern u8 D_8014D4B4[];
extern struct { u16 value; } D_8014D4AA, D_8014D4AC_de, D_8014D4AE;
extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
extern char D_0044EA08[], D_0044ED44[], D_0044E48C[], D_0044E9C0[], D_8014561C[];
extern void func_80404E28_de(s32 ch);
extern s32 func_80404F04_de(s32 ch);
extern s32 func_80404F3C_de(s32 ch);
extern s32 func_80405598_de(s32 ch);
extern u32 func_804057F8_de(void *data, u32 size, u32 seed);


/* Enters pak menu mode 1 on the selected channel: shows the pending message (D_800E28C0) with the channel's
   prompt, else probes the Controller Pak; with no pak data it saves the player's profile (flags, four words
   and eight name bytes) with its checksum and opens the note list through func_80405F48_de, otherwise it
   shows the D_0044EA08, D_0044ED44 or D_0044E9C0 prompt. */
void Pak_BeginProfileSave(Shared_PakMenu *menu) {
    ObjRecAt5DC *owner = menu->player;
    ObjRecAt5DC *player;
    ProfileRecAt84 *profile;
    s32 channel;
    char *prompt;
    s32 i;

    D_8014D4C0_de = 1;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 1;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 0;
    channel = menu->slot->unk4;
    player = owner;
    prompt = pakPrompt(&channel);
    if (D_800E28C0) {
        D_80153784 = 1;
        func_80442574_de(menu->player->unk5DC + 0x554, prompt, player, player->controller, 0);
        return;
    }
    if (D_8015375C) {
        func_80404E28_de(D_800E28C8);
    } else {
        func_80404E28_de(menu->slot->unk4);
    }
    if (!func_80404F04_de(channel)) {
        profile = player->profile;
        D_8014D4B0_de.value = profile->flags;
        D_80153738.values[0] = profile->words[0];
        D_8014D4AA.value = profile->words[1];
        D_8014D4AC_de.value = profile->words[2];
        D_8014D4AE.value = profile->words[3];
        D_8014D4B1 = 0;
        D_8014D4B2 = 0;
        D_8014D4B3 = 0;
        for (i = 0; i < 8; i++) {
            D_8014D4B4[i] = profile->name[i];
        }
        D_80153738.checksum = func_804057F8_de(&D_80153738, 0x14, 4);
        func_80405F48_de(menu);
        return;
    }
    D_80153784 = 1;
    if (func_80404F3C_de(channel)) {
        func_80442574_de(D_8014561C, D_0044EA08, player, player->controller, prompt);
    } else if (func_80405598_de(channel)) {
        func_80442574_de(D_8014561C, D_0044ED44, player, player->controller, D_0044E48C);
    } else {
        func_80442574_de(D_8014561C, D_0044E9C0, player, player->controller, prompt);
    }
}
