#ifndef MENU_8043F69C_H
#define MENU_8043F69C_H
#include "TYPES.H"
struct func_8022A404_S1 {
    char pad0[0x20];
    int unk20;
};
typedef struct MenuOption {
    u8 unobserved0[8];
    s32 flags;
    u8 unobservedC[8];
    s32 resource;
} MenuOption;
typedef struct MenuOptionFade {
    u8 unobserved0[0x30];
    f32 fade;
    f32 alpha;
    s32 field38;
    s32 highlighted;
} MenuOptionFade;
struct TextLayerMetrics {
    int field0;
    int width;
    int height;
    int rest[7];
};
struct ParamsPakAllocateMenu {
    char pad[0x14];
    s32 a;
    s32 pad18;
    s32 b;
    s32 c;
    s32 d;
};
struct ParamsRecAt24V2 {
    char pad[0x18];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
};
struct CMenuFontInfo_t {
    s32 unk0;
    char pad0[0x8];
    f32 unkC;
    f32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 pad1B;
};
struct Outer {
    char pad[0x14];
    struct MenuRules *inner;
};
struct WidgetRecAt20 {
    char reserved00[8];
    u32 flags; /* +0x08: 80440838 tests/sets 0x02000000. */
    char reserved0C[0x14];
    struct StateRecAt47C *state;
};
struct OwnerRecAt4 {
    char pad[4];
    struct NodeRecAt1D0 *head;
};
struct ObjectPakDrawMenuCharacter {
    char pad[0x17];
    u8 character;
};
struct ParamsRecAt24V1 {
    char pad[0x18];
    struct Dialog *list;
    s32 b;
    s32 c;
    s32 d;
};
struct func_8043FFAC_S5 {
    s32 unk0;
    char pad0[0x10];
    s32 unk14;
    char pad14[0x4];
    s32 unk1C;
};
struct TextBoundsData {
    char pad0[0x29C];
    f32 unk_29C;
    f32 unk_2A0;
    f32 x; /* 0x2A4 */
    f32 y; /* 0x2A8 */
};
struct TextBoundsFont {
    s32 kind;
    f32 width;
    f32 height;
    s32 rest[4];
};
struct TextBoundsRecord23 {
    char pad0[0x24];
    s32 unk_24;
    s32 unk_28;
};
#endif
