#ifndef COMMON_TARGET_H
#define COMMON_TARGET_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Target;
struct Target {
    u8 kind;
    char pad1[3];
    u16 type;
};

struct Vec4s;
typedef struct Vec4s Vec4s;


extern float D_800C442C_de;


struct ResourceManagerState;
struct Triple;


extern float D_800C4440_de;

struct Actor_func_802676EC_de;
struct PlayerRecAt122C;
struct Actor_func_802676EC_de {
    char pad0[8];
    CVector3 position;
    char pad14[0x70 - 0x14];
    f32 height;
    char pad74[0x100 - 0x74];
    s32 flags;
    char pad104[0x1D8 - 0x104];
    struct PlayerRecAt122C *player;
};


struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Record;
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
struct func_8023945C_S1;

struct Actor_func_80267958_de;

struct ResourceManagerState;
struct Triple;
typedef void ( *func_80267198_de_Callback)(void *, void *, signed int, CVector3, struct ResourceManagerState);

struct CallbackEntryRecAt4V1;

extern float D_800C4424_de;




struct ObjectRecAtD0;
typedef struct ObjectRecAtD0 ObjectRecAtD0;



struct s_CEventValueFormat7a;
typedef struct s_CEventValueFormat7a CEventValueFormat7a;

extern float D_800C4420_de;



struct Actor_func_80267958_de;
typedef struct Actor_func_80267958_de Actor_func_80267958_de;

struct Actor_func_802676EC_de;
struct Carrier;


struct CallbackEntryRecAt4V1;
typedef struct CallbackEntryRecAt4V1 CallbackEntryRecAt4V1;

struct Carrier;
typedef struct Carrier Carrier;

struct Actor_func_802676EC_de;
typedef struct Actor_func_802676EC_de Actor_func_802676EC_de;

struct ObjectRecAtD0;

struct Vec4s;

extern float D_800C9538;


struct Node_func_80267CE4_de;
struct Node_func_80267CE4_de {
    s32 unused;
    struct Node_func_80267CE4_de *next;
};


extern float D_800C46E8_eu;

struct s_CEventValueFormat7a;


extern float D_800C4428_de;

struct Node_func_80267CE4_de;
typedef struct Node_func_80267CE4_de Node_func_80267CE4_de;

extern float D_800C4430_de;

struct Target;
typedef struct Target Target;


extern s32 func_8025DEC0_de(s32 arg0, CVector3 arg1, s32 arg4, s32 arg5,
                         f32 arg6);

extern void func_80232744_de(void *arg0, s32 arg1, s32 arg2);
#endif
