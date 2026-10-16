#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80405454.h"
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
