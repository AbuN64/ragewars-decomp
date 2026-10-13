#include "span_16E000/code_8042F988.h"
#include "shared/pak_save_text.h"
extern struct Block_func_804347CC_de *D_800E54A4;
extern s32 func_80404BE8_de(char *, s32, s32 *);
extern s32 func_80404858_de(s32, s32);
extern s32 func_80405160_de(s32, s32 *);
extern s32 func_804050CC_de(s32, s32 *);
extern s32 func_80435424_de(void);
extern s32 func_804057EC_de(s32);
extern s32 func_80405454_de(s32, char *);
extern void func_802A0724_de(void *, void *, s32);
extern u32 func_804057F8_de(void *, u32, u32);
extern char *func_802A025C_de(char *, char *);
extern s32 func_80404958_de(s32, s32, void *, char *, char *, char *);
extern void func_804322AC_de(s32);
/* Replace or create the selected port's four-profile Controller Pak note. */
s32 func_80434428_de(s32 channel)
{
    char extension[8];
    char name[16];
    s32 note, bytes, slots, status, required, i;
    s32 success = 0;
    status = func_80404BE8_de(rw_pak_save_name(), channel, &note);
    if (status == 1) {
        success = func_80404858_de(channel, note) == 0;
    } else {
        status = func_80405160_de(channel, &bytes);
        if (status == 0) {
            status = func_804050CC_de(channel, &slots);
            if (status == 0) {
                required = func_804057EC_de(func_80435424_de());
                success = slots != 0 && bytes >= required;
            }
        }
    }
    if (success) {
        success = 0;
        if (func_80405454_de(channel, extension) == 0) {
            func_802A0724_de(D_800E54A4->saved, D_800E54A4->players[channel].records, 0x640);
            D_800E54A4->savedProfile = D_800E54A4->players[channel].profile;
            D_800E54A4->checksum = func_804057F8_de(D_800E54A4->saved, 0x640, 7);
            for (i = 15; i >= 0; i--) name[i] = 0;
            func_802A025C_de(name, rw_pak_save_name());
            success = func_80404958_de(channel, 0x648, D_800E54A4->saved,
                                       name, extension, rw_pak_save_code()) == 0;
        }
    }
    if (!success) {
        D_800E54A4->players[channel].back = 2;
        D_800E54A4->players[channel].state = 2;
        func_804322AC_de(channel);
    }
    return success;
}
