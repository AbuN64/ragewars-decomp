#include "shared/game_options_labels.h"
#include "TYPES.H"

/* Builds screen state D_800E4514: allocates its 0x10 bytes, registers resources (0x1BD - OPTIONS_RESOURCE_SHIFT) and (0x1C2 - OPTIONS_RESOURCE_SHIFT),
   creates list 0x1BB/0x1BC at 0x4 with the three texts gameOptionsLabel(0), gameOptionsLabel(1) and gameOptionsLabel(2) and
   selects byte 0x1B of the settings D_801462C8, creates list (0x1BE - OPTIONS_RESOURCE_SHIFT)/(0x1BF - OPTIONS_RESOURCE_SHIFT) at 0x8 with gameOptionsLabel(3),
   plus gameOptionsLabel(4) and gameOptionsLabel(5) unless func_80265350_de reports 0x400000, and selects settings byte
   0x580, creates the 0x80-step slider (0x1C0 - OPTIONS_RESOURCE_SHIFT)/(0x1C1 - OPTIONS_RESOURCE_SHIFT) at 0x0 set to the settings word at 0x10,
   registers (0x1C3 - OPTIONS_RESOURCE_SHIFT) and (0x1C4 - OPTIONS_RESOURCE_SHIFT), clears the word at 0xC, resets through func_802A2394_de and returns
   zero. */
struct Screen {
    s32 slider;
    s32 first_list;
    s32 second_list;
    s32 state;
};

extern struct Screen *D_800E4514;
typedef struct Settings { char pad0[0x10]; s32 value; char pad14[7]; u8 first; char pad1C[0x564]; u8 second; } Settings;
extern Settings D_801462C8;
extern struct Screen *func_8025305C_de(s32);
extern void func_8041B110_de(s32);
extern s32 func_8041ABC0_de(s32, s32);
extern void func_8041AD34_de(s32, char *);
extern void func_8041AD10_de(s32, s32);
extern s32 func_80265350_de(void);
extern s32 func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(s32, s32);
extern void func_802A2394_de(void);

typedef struct func_8042362C_S1 func_8042362C_S1;
struct func_8042362C_S1 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_804234CC_de(void) {

    Settings *settings;
    s32 list;
    s32 slider;

    D_800E4514 = func_8025305C_de(0x10);
    func_8041B110_de((0x1BD - OPTIONS_RESOURCE_SHIFT));
    func_8041B110_de((0x1C2 - OPTIONS_RESOURCE_SHIFT));
    if (OPTIONS_HAS_FIRST_LIST) {
    list = func_8041ABC0_de(0x1BB, 0x1BC);
    {s32 *handle = &D_800E4514->first_list; *handle = list;}
    func_8041AD34_de(D_800E4514->first_list, gameOptionsLabel(0));
    func_8041AD34_de(D_800E4514->first_list, gameOptionsLabel(1));
    func_8041AD34_de(D_800E4514->first_list, gameOptionsLabel(2));
    settings = &D_801462C8;
    func_8041AD10_de(D_800E4514->first_list, settings->first);
    }
    list = func_8041ABC0_de((0x1BE - OPTIONS_RESOURCE_SHIFT), (0x1BF - OPTIONS_RESOURCE_SHIFT));
    {s32 *handle = &D_800E4514->second_list; *handle = list;}
    func_8041AD34_de(D_800E4514->second_list, gameOptionsLabel(3));
    if (func_80265350_de() != 0x400000) {
        func_8041AD34_de(D_800E4514->second_list, gameOptionsLabel(4));
        func_8041AD34_de(D_800E4514->second_list, gameOptionsLabel(5));
    }
    if (!OPTIONS_HAS_FIRST_LIST) settings = &D_801462C8;
    func_8041AD10_de(D_800E4514->second_list, settings->second);
    slider = func_8041A580_de((0x1C0 - OPTIONS_RESOURCE_SHIFT), (0x1C1 - OPTIONS_RESOURCE_SHIFT), 0x80);
    D_800E4514->slider = slider;

    func_8041A6EC_de(slider, settings->value);
    func_8041B110_de((0x1C3 - OPTIONS_RESOURCE_SHIFT));
    func_8041B110_de((0x1C4 - OPTIONS_RESOURCE_SHIFT));
    D_800E4514->state = 0;
    func_802A2394_de();
    return 0;
}
