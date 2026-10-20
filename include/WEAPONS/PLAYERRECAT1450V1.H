#ifndef WEAPONS_PLAYERRECAT1450V1_H
#define WEAPONS_PLAYERRECAT1450V1_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS14C.H"
struct PlayerRecAt1450V1;
typedef struct PlayerRecAt1450V1 PlayerRecAt1450V1;

struct func_80232A38_S1;
struct func_80232A38_S1 {
    char pad0[0x2C];
    char * unk2C;
    char pad2C[0x108 - 0x2C - sizeof(char*)];
    char * unk108;
    char pad108[0x10C - 0x108 - sizeof(char*)];
    char * unk10C;
    char pad10C[0x124 - 0x10C - sizeof(char*)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
    char pad128[0x12C - 0x128 - sizeof(s32)];
    f32 unk12C;
    char pad12C[0x130 - 0x12C - sizeof(f32)];
    s32 unk130;
    char pad130[0x138 - 0x130 - sizeof(s32)];
    s32 unk138;
    char pad138[0x13C - 0x138 - sizeof(s32)];
    s32 unk13C;
    char pad13C[0x144 - 0x13C - sizeof(s32)];
    s32 unk144;
    char pad144[0x148 - 0x144 - sizeof(s32)];
    s32 unk148;
    char pad148[0x14C - 0x148 - sizeof(s32)];
    s32 unk14C;
    char pad14C[0x150 - 0x14C - sizeof(s32)];
    s32 unk150;
};

extern float D_800C303C_de;

struct ObjectState140;
typedef struct ObjectState140 ObjectState140;

struct func_80232B54_S3;
struct func_80232B54_S3 {
    char pad0[0xCB];
    s8 unkCB;
    char padCB[0x124 - 0xCB - sizeof(s8)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
};

extern float D_800C3018_de;

struct Source_func_80232F8C_de;
struct Source_func_80232F8C_de {
    char pad[0x294];
    float speed;
};
struct Event;
struct Source_func_80232F8C_de;
struct Event {
    int unk0;
    int side;
    struct Source_func_80232F8C_de *source;
};

struct func_80232FE8_S2;
typedef struct func_80232FE8_S2 func_80232FE8_S2;

extern float D_800C3028_de;

extern float D_800C3038_de;

struct func_80232C78_S2;
typedef struct func_80232C78_S2 func_80232C78_S2;

struct func_80232CDC_S3;
struct func_80232CDC_S3 {
    char pad0[0x8];
    CVector3 unk8;
    char pad8[0x62E - 0x8 - sizeof(CVector3)];
    s16 unk62E;
    char pad62E[0x6AC - 0x62E - sizeof(s16)];
    s32 unk6AC;
    char pad6AC[0x788 - 0x6AC - sizeof(s32)];
    s32 unk788;
    char pad788[0x78C - 0x788 - sizeof(s32)];
    s32 unk78C;
};

struct func_80232B54_S2;
typedef struct func_80232B54_S2 func_80232B54_S2;

struct func_80232CDC_S3;
typedef struct func_80232CDC_S3 func_80232CDC_S3;

struct func_80232C78_S2;
struct func_80232C78_S2 {
    char pad0[0x62E];
    s16 unk62E;
    char pad62E[0x11C0 - 0x62E - sizeof(s16)];
    s32 unk11C0;
};

struct func_8023292C_S1;
struct func_8023292C_S1 {
    char pad0[0xB4];
    s32 unkB4;
    char padB4[0x1D8 - 0xB4 - sizeof(s32)];
    void * unk1D8;
};

extern float D_800C302C_de;



struct ObjectState134;
typedef struct ObjectState134 ObjectState134;

struct PlayerRecAt1450V1;
struct PlayerRecAt1450V1 {
    char pad0[0x5D4];
    int character;
    char pad5D8[4];
    void *hud;
    char pad5E0[0x62E - 0x5E0];
    short weapon;
    char pad630[0x11D8 - 0x630];
    float shield;
    char pad11DC[0x1450 - 0x11DC];
    int isBot;
};

struct func_8023292C_S3;
struct func_8023292C_S3 {
    char pad0[0x144];
    s32 unk144;
};

extern float D_800C2FC4_de;

struct ObjectState134;
struct ObjectState134 {
    char pad0[0x64];
    s32 unk_64;
    char pad64[0x130 - 0x64 - sizeof(s32)];
    f32 unk_130;
};

struct func_8023292C_S2;
struct func_8023292C_S2 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(void*)];
    s16 unk62E;
    char pad62E[0x11F8 - 0x62E - sizeof(s16)];
    s32 unk11F8;
};

extern float D_800C301C_de;

extern void func_802325FC_de(void *arg0, void *arg1);



struct func_80232CDC_S2;
typedef struct func_80232CDC_S2 func_80232CDC_S2;

struct Event;
typedef struct Event Event;


struct func_80232A38_S1;
typedef struct func_80232A38_S1 func_80232A38_S1;

struct func_80232B54_S2;
struct func_80232B54_S2 {
    char pad0[0x788];
    s32 unk788;
    char pad788[0x78C - 0x788 - sizeof(s32)];
    s32 unk78C;
    char pad78C[0x794 - 0x78C - sizeof(s32)];
    s32 unk794;
};

struct func_80232BC0_S1;
typedef struct func_80232BC0_S1 func_80232BC0_S1;

struct func_8023292C_S3;
typedef struct func_8023292C_S3 func_8023292C_S3;

struct func_80232BC0_S1;
struct func_80232BC0_S1 {
    char pad0[0x62E];
    s16 unk62E;
    char pad62E[0x6AC - 0x62E - sizeof(s16)];
    s32 unk6AC;
    char pad6AC[0x11B4 - 0x6AC - sizeof(s32)];
    s32 unk11B4;
    char pad11B4[0x11D8 - 0x11B4 - sizeof(s32)];
    f32 unk11D8;
    char pad11D8[0x1450 - 0x11D8 - sizeof(f32)];
    s32 unk1450;
    char pad1450[0x1454 - 0x1450 - sizeof(s32)];
    void * unk1454;
};

extern s32 func_802327D4_de(s32 arg0);

struct Shared_ActorView;
struct WeaponFireState;


extern float D_800C3020_de;

struct func_8023292C_S2;
typedef struct func_8023292C_S2 func_8023292C_S2;

struct func_80232B54_S3;
typedef struct func_80232B54_S3 func_80232B54_S3;



extern float D_800C8100;

struct func_8023292C_S1;
typedef struct func_8023292C_S1 func_8023292C_S1;

extern float D_800C8130;

struct ObjectState140;
struct ObjectState140 {
    char pad0[0x64];
    f32 unk_64;
    char pad64[0x130 - 0x64 - sizeof(f32)];
    f32 unk_130;
    char pad130[0x13C - 0x130 - sizeof(f32)];
    s32 unk_13C;
};

extern s32 func_80232780_de(s32 arg0);

struct func_80232FE8_S2;
struct func_80232FE8_S2 {
    char pad0[0x62E];
    s16 unk62E;
    char pad62E[0x650 - 0x62E - sizeof(s16)];
    s16 unk650;
    char pad650[0x770 - 0x650 - sizeof(s16)];
    s16 unk770;
};

struct func_80232CDC_S2;
struct func_80232CDC_S2 {
    char pad0[0x35];
    s8 unk35;
    char pad35[0xCB - 0x35 - sizeof(s8)];
    s8 unkCB;
};

struct Dest;
struct Lookup;
extern void func_8023293C_de(void *arg0, struct Dest *arg1, struct Lookup *arg2);

extern float D_800C2FC8_de;

extern void func_8022FDAC_de(void *arg0, void *arg1);


extern void func_802739C4_de(void *, float);
extern void func_8022AEA0_de(struct Shared_ActorView *arg0, s32 arg1);
extern void func_802739C4_de(void *, f32);
#endif
