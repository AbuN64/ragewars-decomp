#ifndef UNBAKE_SPAN_16E000_CODE_80405454_H
#define UNBAKE_SPAN_16E000_CODE_80405454_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct ProfileRecAt84;
struct Record;
struct Rider;
struct Settings;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;

struct Menu_func_804066BC_de;
typedef struct Menu_func_804066BC_de Menu_func_804066BC_de;

extern void func_8040570C_de(u8 *arg0, s8 *arg1, s32 arg2);

struct Shape_typemap_110;
struct RecordRecAt1C;
extern void func_80405CDC_de(struct RecordRecAt1C *arg0);

struct func_80408C78_S1;
typedef struct func_80408C78_S1 func_80408C78_S1;

struct Owner_func_804066BC_de;
struct Owner_func_804066BC_de {
    char pad0[0x328];
    s32 flags;
};
struct Menu_func_804066BC_de;
struct Owner_func_804066BC_de;
struct Menu_func_804066BC_de {
    s16 state;
    char pad2[0xA];
    struct Owner_func_804066BC_de *owner;
    char pad10[4];
    char *dialogData; /* 0x14 */
    char pad18[4];
    ObjRecAt5DC *player;
    PakMenuSlot *slot;
    struct Dialog *prompt; /* 0x24: dialog resource */
};

struct func_80408C78_S1;
struct func_80408C78_S1 {
    u16 unk0;
    char pad0[0x2 - 0x0 - sizeof(u16)];
    u16 unk2;
    char pad2[0x4 - 0x2 - sizeof(u16)];
    u16 unk4;
    char pad4[0x6 - 0x4 - sizeof(u16)];
    u16 unk6;
};

struct Menu_func_80408C4C_de;
struct Menu_func_80408C4C_de {
    char pad0[0x1C];
    SharedPlayer *player;
    PakMenuSlot *slot;
    char *prompt;
};

struct RecordRecAt1C;
struct RecordRecAt1C {
    s32 a;
    s32 b;
    s32 c;
    s32 values[3];
    s32 d;
    s32 e;
};

struct RecordRecAt1C;
extern void func_80405CA8_de(struct RecordRecAt1C *record);

struct Shared_func_804069F4_S1;
struct ObjRecAtB0;
struct Shared_func_804069F4_S1 {
    char pad0[0x1C];
    s32 first;
    struct ObjRecAtB0 * second;
};

struct RecCode80405454;
typedef struct RecCode80405454 RecCode80405454;

struct Shape_typemap_110;
struct func_80405CDC_S2;
struct func_80405CDC_S2 {
    char pad0[0x8];
    struct Shape_typemap_110 unk8;
};

struct func_80405CDC_S2;
typedef struct func_80405CDC_S2 func_80405CDC_S2;

struct Shape_typemap_110;
struct RecCode80405454;
struct RecCode80405454 {
    char pad0[0x4];
    struct Shape_typemap_110 unk4;
};

struct PakRecord;
struct PakRecord {
    u8 present;
    char pad[7];
    char pak[0x68];
};

struct Shared_func_804069F4_S1;
typedef struct Shared_func_804069F4_S1 Shared_func_804069F4_S1;

struct Menu_func_80408C4C_de;
typedef struct Menu_func_80408C4C_de Menu_func_80408C4C_de;

struct PakRecord;
typedef struct PakRecord PakRecord;

extern int func_804058B0_de(struct RecordRecAt1C * arg0);
#endif
