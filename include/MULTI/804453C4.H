#ifndef MULTI_804453C4_H
#define MULTI_804453C4_H
#include "COMMON/MENURECAT20V1.H"
#include "COMMON/AIPROFILE.H"
struct MenuRecAt20V1 {
    s16 state;
    char pad2[0x1A];
    s32 id;
    s32 input;
};
struct PlayerRecAtC {
    s16 state;
    char pad2[0xA];
    struct Actor_func_8044560C_de *actor;
};
struct Style_func_80445BC0_de {
    char pad0[0x1C];
    s32 id;
    char pad20[0x10];
    f32 alpha;
    f32 fade;
};
struct EntryRecAtCV2 {
    s32 value;
    f32 timer;
    s32 count;
    u8 text[12];
};
struct EntryRecAt1C {
    char pad[0x1C];
    ObjRecAt5D8 *unk1C;
};
struct Spinner {
    s32 value;
    f32 timer;
    s32 max;
    char padC[0xC];
};
struct TextEntryRecAtC {
    s32 length;
    s32 cursor;
    s32 count;
    char text[12];
};
extern int func_80446330_us_rev1(void * arg0);
#endif
