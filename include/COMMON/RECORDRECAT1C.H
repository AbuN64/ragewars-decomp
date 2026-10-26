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


struct Owner_func_804066BC_de;
struct Owner_func_804066BC_de {
    char pad0[0x328];
    s32 flags;
};
struct Menu_func_804066BC_de;
struct Owner_func_804066BC_de;


struct MenuPakConfirmProfileOrDeleteNote;

struct RecordRecAt1C;

struct RecordRecAt1C;

struct ObjRecAtB0;


struct Shape_typemap_110;


struct Shape_typemap_110;

struct PakRecord;
struct PakRecord {
    u8 present;
    char pad[7];
    char pak[0x68];
};


struct MenuPakConfirmProfileOrDeleteNote;
typedef struct MenuPakConfirmProfileOrDeleteNote MenuPakConfirmProfileOrDeleteNote;

struct PakRecord;
typedef struct PakRecord PakRecord;

extern int Pak_AllocateRenderBuffers(struct RecordRecAt1C * arg0);
#endif
