#ifndef COMMON_RECORDRECAT1C_H
#define COMMON_RECORDRECAT1C_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
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


struct Shape_typemap_110;
struct RecordRecAt1C;

struct func_80408C78_S1;
typedef struct func_80408C78_S1 func_80408C78_S1;

struct Owner_func_804066BC_de;
struct Owner_func_804066BC_de {
    char pad0[0x328];
    s32 flags;
};
struct Menu_func_804066BC_de;
struct Owner_func_804066BC_de;

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

struct RecordRecAt1C;

struct RecordRecAt1C;

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
