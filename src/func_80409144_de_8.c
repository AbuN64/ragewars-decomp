#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "shared/pak_load.h"
#include "common/unused.h"
#include "shared/func_80245BC0_de_closed.h"
#include "shared/func_80404D84_de_closed.h"
#include "span_1000/code_802536F4.h"
#include "span_16E000/code_80405DC0.h"
extern u8 *D_800E28BC;
extern char D_0044E468[];
extern char D_0044E4B0[];
extern s32 D_8011FECC;
extern s32 D_8015375C;
s32 func_8040458C_de(s32, s32, s32 *, u8 *, u8 *, s32 *, u8 *, u8 *);
s32 func_802A0238_de(u8 *);
s32 func_802A037C_de(const void *, const void *);
s32 func_80404F58_de(s32, s32, s32, s32);
u32 func_804057F8_de(u8 *, u32, u32);
s32 func_804057BC_de(u8 *, s32);
u8 *func_802A025C_de(u8 *, u8 *);
void *func_80442574_de(struct func_8025E5B0_S1 *, struct Dialog *, s32, s32, s32);
s32 func_80406178_de(void *, s32, s32);
static __inline__ s32 pak_note_has_game_id(u8 *company, u8 *code) { if ((func_802A0238_de(code) == 4) && (func_802A0238_de(company) == 2) && (func_802A037C_de(code, rw_pak_game_code(&D_80145040.game)) == 0) && (func_802A037C_de(company, rw_pak_company(&D_80145040.game)) == 0)) return 1; return 0; }
static __inline__ s32 pak_block_has_size(u8 *data,s32 expected) { return *(s32 *)data==expected; }
/* Load a Controller Pak note, validate its profile or save-block
 * checksum, and open the corresponding selection or error dialog. */
s32 func_80407748_de(s32 *selection, Shared_PakMenu *menu) {
    u8 extension[8];
    u8 company[8];
    u8 code[8];
    u8 name[16];
    s32 exists;
    s32 pages;
    s32 length;
    s32 noteIndex;
    s32 expectedSize;
    s32 status;
    s32 copying;
    s32 current;
    s32 allocationSize;
    u8 *text;
    char *messageExtra;
    s32 readError;
    s32 blockState;
    s32 profileMatches;
    s32 channel;
    s32 result;
    s32 gameNote;
    s32 i;
    struct Dialog *dialog;
    struct Shape_typemap_165 *handle;
    struct Shape_typemap_165 *handle2;
    u8 *payload;
    u8 *payload2;

    readError = 0;
    noteIndex = *selection - 3;
    expectedSize = D_8011FECC + 0x610;
    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = menu->slot->unk4;
    }
    if (func_80406178_de(menu, channel, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_8014D4DC != 0) {
        status = func_8040458C_de(channel, noteIndex, &exists, name, extension, &pages, company, code);
        if ((status == 0) && (exists == 0)) {
            menu->state = 0x14;
            func_80405F48_de(menu);
            return 0;
        }
        gameNote = pak_note_has_game_id(company,code);
        if (gameNote != 0) {
            Shared_Game *settings = &D_80145040.game;
            profileMatches = func_802A037C_de(name, rw_pak_profile_name(settings)) == 0;
            blockState = func_802A037C_de(name, rw_pak_block_name(settings)) == 0;
        } else {
            profileMatches = 0;
            blockState = 0;
        }
        if ((status == 0) && (exists != 0)) {
            if (profileMatches != 0) {
                if (func_80404F58_de(channel, noteIndex, (s32)&D_80153738, 0x18)!=0) {
                    profileMatches=0;
                    goto profile_failed;
                }
                if (func_804057F8_de((u8 *)&D_80153738,0x14,4)!=D_80153738.checksum) {
                    profileMatches=0;
                    goto profile_failed;
                }
                    *rw_pak_loaded_profile() =D_80153738;
                    D_8014D4FC=noteIndex;
                    func_80442574_de(&D_80145040.dialogOwner, rw_pak_selected_profile_dialog(), (s32)menu->player, (s32)menu->slot, (s32)menu->dialogData);
                    return 1;
profile_failed:
                readError=1;
            }
            if ((blockState != 0) && (readError == 0)) {
                blockState = pages;
                if (D_800DE864_de != 0) {
                    func_80253908_de(0);
                    func_80253838_de(0, D_800DE864_de);
                }
                if (blockState != 0) blockState <<= 8;
                else {
                    blockState = D_8011FECC + 0x610;
                }
                handle = func_8025343C_de(0, blockState, 0x33U, D_800DCD60);
                payload = handle->data;
                D_800DE864_de = handle;
                D_800E28BC = payload;
                func_802A001C_de(payload, 0, (u32) blockState);
                if (func_80404F58_de(channel, noteIndex, (s32)D_800E28BC, pages << 8)==0 &&
                    pak_block_has_size(D_800E28BC,expectedSize) &&
                    func_804057F8_de(D_800E28BC,*(s32 *)D_800E28BC-4,11)==*(s32 *)(D_800E28BC+(*(s32 *)D_800E28BC-4)) &&
                    D_8011FECC==((s32 *)D_800E28BC)[1]) {
                    D_8014D4FC=noteIndex;
                    func_80442574_de(&D_80145040.dialogOwner, rw_pak_selected_block_dialog(), (s32)menu->player, (s32)menu->slot, (s32)menu->dialogData);
                    return 1;
                }
                blockState=0;
                readError=1;
            }
            if (profileMatches == 0) {
                if (blockState == 0) {
                    Shared_Game *settings = &D_80145040.game;
                    current = 0;
                    text = rw_pak_note_text(settings);
                    D_8014D4FC = noteIndex;
                    if (func_804057BC_de(name, 0x10) != 0) {
                        func_802A025C_de(name, (u8 *)rw_pak_invalid_name(settings));
                    }
                    copying = 1;
                    i = 0;
                    do {
                        if (copying != 0) {
                            current = (name)[i];
                        }
                        if (current == 0) {
                            copying = 0;
                            current = 0x20;
                        }
                        *text = current;
                        i += 1;
                        text += 1;
                    } while (i < 0x10);
                    copying = 1;
                    text += 1;
                    i = 0;
                    do {
                        if (copying != 0) {
                            current = (extension)[i];
                        }
                        if (current == 0) {
                            copying = 0;
                            current = 0x20;
                        }
                        *text = current;
                        i += 1;
                        text += 1;
                    } while (i < 4);
                    func_80442574_de(&D_80145040.dialogOwner, rw_pak_other_note_dialog(), (s32)menu->player, (s32)menu->slot, (s32)menu->dialogData);
                        return 1;
                }
            }
            goto done;
        }
        goto done;

    }
    if (D_80153760 != 0) {
        if ((D_8014D4EC_de != 0) && (readError == 0)) {
            if (((status=func_8040458C_de(channel, noteIndex, &exists, name, extension, &pages, company, code)) == 0) && (exists != 0)) {
                Shared_Game *settings = &D_80145040.game;
                if (func_802A037C_de(name,rw_pak_profile_name(settings)) == 0) {
                if (func_80404F58_de(channel, noteIndex, (s32)&D_80153738, 0x18)!=0) {
                    readError=1;
                    goto done;
                }
                if (func_804057F8_de((u8 *)&D_80153738,0x14,4)!=D_80153738.checksum) {
                    readError=1;
                    goto done;
                }
                    *rw_pak_loaded_profile() =D_80153738;
                    func_80442574_de(&D_80145040.dialogOwner, rw_pak_loaded_profile_dialog(), (s32)menu->player, (s32)menu->slot, 0);
                    return 1;
                }
            }
            goto done;
        }
        if ((D_80153760 != 0) && (D_8014D4EC_de == 0)) {
            if (readError != 0) goto show_error;
            {
                if (((status=func_8040458C_de(channel, noteIndex, &exists, name, extension, &pages, company, code)) == 0) && (exists != 0) && (func_802A037C_de(name, rw_pak_block_name(&D_80145040.game)) == 0)) {
                    allocationSize = pages;
                    if (D_800DE864_de != 0) {
                        func_80253908_de(0);
                        func_80253838_de(0, D_800DE864_de);
                    }
                    if (allocationSize != 0) allocationSize <<= 8;
                    else {
                        allocationSize = D_8011FECC + 0x610;
                    }
                    handle2 = func_8025343C_de(0, allocationSize, 0x33U, D_800DCD60);
                    payload2 = handle2->data;
                    D_800DE864_de = handle2;
                    D_800E28BC = payload2;
                    func_802A001C_de(payload2, 0, (u32) allocationSize);
                    if (func_80404F58_de(channel, noteIndex, (s32)D_800E28BC, pages << 8) == 0) {
                        length = *(s32 *)D_800E28BC;
                        if ((length == expectedSize) && (func_804057F8_de(D_800E28BC, length - 4, 0xBU) == *(s32 *)(D_800E28BC+(*(s32 *)D_800E28BC-4))) && (D_8011FECC == ((s32 *)D_800E28BC)[1])) {
                            func_80442574_de(&D_80145040.dialogOwner, rw_pak_loaded_block_dialog(), (s32)menu->player, (s32)menu->slot, 0);
                        return 1;
                        }
                    }
                    readError = 1;
                    if ((D_800DE860_de != 0) || (D_800DE864_de != 0)) {
                        func_80253908_de(0);
                    }
                    if (D_800DE860_de != 0) {
                        func_80253838_de(0, D_800DE860_de);
                    }
                    if (D_800DE864_de != 0) {
                        func_80253838_de(0, D_800DE864_de);
                    }
                    D_800DE860_de = 0;
                    D_800DE864_de = 0;
                    D_800DE868 = 0;
                    D_800E28BC = 0;
                    goto done;
                }
                goto done;
            }
            goto show_error;
        }
        goto done;
    }
done:
    result = 0;
    if (readError != 0) {
show_error:
        if (D_8014D4EC_de != 0) messageExtra = D_0044E468;
        else messageExtra = D_0044E4B0;
        dialog = rw_pak_load_error_dialog();
        D_8014D4C4 = noteIndex;
        func_80442574_de(&D_80145040.dialogOwner, dialog, (s32)menu->player, (s32)menu->slot, (s32)messageExtra);
        result = 1;
    }
    return result;
}
