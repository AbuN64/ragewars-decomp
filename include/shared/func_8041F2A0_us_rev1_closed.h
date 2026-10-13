#ifndef FUNC_8041F2A0_US_REV1_CLOSED_H
#define FUNC_8041F2A0_US_REV1_CLOSED_H
#include "types.h"
#include "span_16E000/code_8041B020.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* Remaining func_8041F2A0_* types are unresolved canonical identities. */
/* Builds the four-player selection screen state, its preview models and sliding panels, then marks active players. */
struct func_8041F2A0_Vec3 {
    f32 x;
    f32 y;
    f32 z;
};
typedef struct func_8041F2A0_Vec3 func_8041F2A0_Vec3;

/* Selection items are menu widgets; w is the legacy width spelling. */
typedef MenuWidget func_8041F2A0_Item;

struct func_8041F2A0_Player {
    func_8041F2A0_Item *highlight;
    s32 unk4;
    s32 kind;
    s32 unkC;
    s32 choice;
    char pad14[4];
    char model[0x4C0 - 0x18];
    s32 unk4C0;
    s32 pad4C4;
};
typedef struct func_8041F2A0_Player func_8041F2A0_Player;

struct SelectionScreenState {
    void *screen;
    struct Slots_func_8041B7FC_de *unk4;
    func_8041F2A0_Player players[4];
    func_8041F2A0_Item *header;
    s32 headerStep;
    func_8041F2A0_Item *footer;
    s32 footerStep;
    s32 phase;
    s32 timer;
    void *prompt;
    func_8041F2A0_Item *promptItem;
    func_8041F2A0_Item *pulse;
    s32 pulseStep;
    s32 clock;
    s32 result;
};
typedef struct SelectionScreenState SelectionScreenState;

struct func_8041F2A0_Cell {
    u16 pad;
    u16 id;
};
typedef struct func_8041F2A0_Cell func_8041F2A0_Cell;

struct func_8041F2A0_Layout {
    s32 kind;
    u16 pad4[3];
    u16 title;
    func_8041F2A0_Cell cells[3];
    func_8041F2A0_Cell options[3];
};
typedef struct func_8041F2A0_Layout func_8041F2A0_Layout;

struct func_8041F2A0_Row {
    s32 pad;
    f32 scale[4];
    f32 distance[4];
    func_8041F2A0_Vec3 position[4];
    s32 light[4];
    char tail[12];
};
typedef struct func_8041F2A0_Row func_8041F2A0_Row;

struct func_8041F2A0_Config {
    s16 total, score, kills, selected, other;
    s16 unkA; /* +0x0A: end-of-match reward statistic */
    char padC[0x78 - 0xC];
    u8 active;
    char pad79[7];
    s8 kind;
    char pad81[3];
    char name[13];
    u8 out, rankPad, rank;
    char tail[2];
};
typedef struct func_8041F2A0_Config func_8041F2A0_Config;

/* The 528-byte menu block at D_800E3590 that func_8041CEB0_us_rev1 allocates: its owner names each
   slot it writes, and the neighbouring menu units keep their own view structs over the same block,
   so consumers reach it through casts from this canonical spelling. */
struct func_8041F2A0_MenuBlock {
    void *root;
    s32 list;
    struct Record_func_80439C80_de record;
    char pad40[0xC8 - 0x40];
    func_8041F2A0_Item *item492;
    s32 round492;
    func_8041F2A0_Item *item491;
    s32 round491;
    s32 unk216;
    s32 unk220;
    s32 lookup486;
    func_8041F2A0_Item *item486;
    func_8041F2A0_Item *item563;
    s32 focus;
    func_8041F2A0_Item *item510;
    func_8041F2A0_Item *item512;
    s32 unk248;
    s32 style;
    func_8041F2A0_Item *item511;
    s32 unk260;
    s32 player;
    s32 unk268;
};
typedef struct func_8041F2A0_MenuBlock func_8041F2A0_MenuBlock;









extern SelectionScreenState *D_800E42D0;
extern func_8041F2A0_Layout D_800E42D4[];


/* func_8041DB30_de advances the cursor word it is handed, the menu block's slot at +0x10C. */
extern func_8041F2A0_MenuBlock *D_800E3590;
extern void func_8041DB30_de(int *cursor);
extern func_8041F2A0_Config D_80146398[];
extern SelectionScreenState *func_8025305C_de(s32);
extern Node_func_8041B610_de *func_8041B610_de(Owner_func_8041B610_de *, s32);
extern void func_8041B6E8_de(Owner_func_8041B6E8_de *, s32, s32);
extern void func_8042E9A0_de(s32, s32);
extern s32 func_8041F18C_de(s32);
extern void func_8041CAD8_de(void *, s32, s32, s32, s32, Vec3, Vec3, f32, s32);
extern MenuWidget *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(func_8041F2A0_Item *, s32);
extern void func_80420308_de(s32);
extern void func_802A2394_de(void);

#endif
