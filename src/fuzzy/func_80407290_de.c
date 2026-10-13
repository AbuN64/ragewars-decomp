#include "common/types_1dc8418c21db.h"
#include "shared/pak_save_text.h"
extern s32 D_8015375C, D_800E28C8, D_8014D4C0_de;
extern void *D_800DE860_de;
extern struct Shape_typemap_165 *D_800DE864_de;
extern s32 D_800DE868, D_800E28BC;
extern char D_80153738[], D_8014561C[];
extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
extern s32 func_804057EC_de(s32);
extern s32 func_80405160_de(s32, s32 *);
extern s32 func_804050CC_de(s32, s32 *);
extern s32 func_80405454_de(s32, char *);
extern s32 func_80404958_de(s32, s32, void *, char *, char *, char *);
extern void func_80442574_de(void *, void *, void *, void *, void *);
extern void func_80253908_de(s32);
extern void func_80253838_de(s32, void *);
/* Save the small controller-pak record when capacity allows, release the
 * pending resources, and show the channel-specific success/error dialog. */
s32 func_80407290_de(s32 unused, struct Record_func_80409BDC_de *menu)
{
    struct SharedPlayer_func_80226A34_de *player;
    char extension[8];
    char *label;
    char *dialog;
    s32 channel, freeBytes, slots, required, status = 0;
    s32 insufficient = 1;
    s32 attempted = 0;
    if (D_8015375C == 0) {
        player = menu->player;
        channel = menu->inner->unk4;
    } else {
        player = 0;
        channel = D_800E28C8;
    }
    if (D_8014D4C0_de != 0) {
        required = func_804057EC_de(0x18);
        status = func_80405160_de(channel, &freeBytes);
        if (status == 0) {
            if (required <= freeBytes) {
                status = func_804050CC_de(channel, &slots);
                if (status == 0 && slots != 0) {
                    insufficient = 0;
                    status = func_80405454_de(channel, extension);
                    if (status == 0) {
                        attempted = 1;
                        status = func_80404958_de(channel, 0x18, D_80153738,
                                                 rw_pak_save_name(), extension, rw_pak_save_code());
                    }
                }
            }
            if (insufficient != 0) {
                func_80442574_de(D_8014561C, rw_pak_no_space_dialog(), player,
                                player->views5E8.view698_34.unk698, menu->dialogData);
                return 0;
            }
        }
    }
    if (D_800DE860_de != 0 || D_800DE864_de != 0) func_80253908_de(0);
    if (D_800DE860_de != 0) func_80253838_de(0, D_800DE860_de);
    if (D_800DE864_de != 0) func_80253838_de(0, D_800DE864_de);
    D_800DE860_de = 0;
    D_800DE864_de = 0;
    D_800DE868 = 0;
    D_800E28BC = 0;
    if (!attempted) return 1;
    switch (channel) {
    case 1: label = D_00450C14_de; break;
    case 2: label = D_00450C38_de; break;
    case 3: label = D_00450C5C_de; break;
    default: label = D_00450BF0_de; break;
    }
    dialog = status != 0 ? rw_pak_save_error_dialog() : rw_pak_save_success_dialog();
    func_80442574_de(D_8014561C, dialog, player,
                    player->views5E8.view698_34.unk698, label);
    return 1;
}
