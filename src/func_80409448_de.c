#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80405454.h"
#include "shared/func_804235A8_eu_layout.h"
#include "common/unused.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_16E000/code_80405DC0.h"
#include "span_176000/code_80405DC4.h"
extern s32 D_8015375C;
extern s32 func_80406178_de(Menu_func_804066BC_de *, s32, s32);
extern void *func_80442574_de(struct func_8025E5B0_S1 *, struct List_func_80442574_de *, s32, s32, s32);

static __inline__ void pakShow(Menu_func_804066BC_de *menu) {
    s32 channel;
    if (D_8015375C) channel = D_800E28C8;
    else channel = menu->slot->unk4;
    if (func_80406178_de(menu, channel, 1)) {
        D_80153784 = 1;
        func_80442574_de(&D_80145040.dialogOwner, menu->prompt, (s32)menu->player, (s32)menu->slot, 0);
    } else {
        func_80442574_de(&D_80145040.dialogOwner, menu->prompt, (s32)menu->player, (s32)menu->slot, 0);
    }
}
static __inline__ void *pakPrompt(s32 *channel) {
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
static __inline__ void *menuPrompt(Menu_func_804066BC_de *menu) {
    s32 channel;
    void *prompt;
        prompt = 0;
        if (D_8014D4C0_de) {
            if (D_8014D4EC_de) {
                channel = menu->slot->unk4;
                prompt = pakPrompt(&channel);
            }
        } else if (D_80153760) {
            prompt = D_0044FFA4;
            if (D_8014D4EC_de) prompt = D_0044FB50;
        }
    return prompt;
}
/* Dialog resources are opaque ROM addresses. The list-builder ABI carries
 * player, slot, and optional formatting data as three raw 32-bit words. */
s32 func_80409448_de(void *unused, Menu_func_804066BC_de *menu) {
    s32 channel;
    void *prompt;
    void *owner;
    ObjRecAt5DC *player;
    func_80242278_S1 *slot;
    switch (D_80153778) {
    case 4: pakShow(menu); return 1;
    case 3: pakShow(menu); return 1;
    case 0: pakShow(menu); return 1;
    case 1:
    case 2:
        D_80153784 = 1;
        D_8014D480 = 0;
        if (D_8015375C) {
            D_8014ADA0 = 1;
            return 1;
        }
        prompt = menuPrompt(menu);
        if (!prompt) prompt = menu->prompt;
        if (menu->player) owner = menu->player->unk5DC + 0x554;
        else owner = &D_80145040.dialogOwner;
        func_80442574_de(owner, prompt, (s32)menu->player, (s32)menu->slot, 0);
        return 1;
    default: return 1;
    }
    func_80442574_de(owner, prompt, (s32)player, (s32)slot, 0);
    return 1;
}
