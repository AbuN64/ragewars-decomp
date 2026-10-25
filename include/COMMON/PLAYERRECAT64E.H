#ifndef COMMON_PLAYERRECAT64E_H
#define COMMON_PLAYERRECAT64E_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"


struct PlayerRecAt64E;
struct PlayerRecAt64E {
    char pad[0x644];
    u8 flags[9];
    u8 count64D;
    u8 count64E;
};

struct Holder_func_8043F048_de;
struct PlayerRecAt64E;

struct Flagged;
struct Flagged {
    u8 pad0[0x58];
    u32 unk58;
};
struct Flagged;
struct Obj8043ECE8;


struct ItemDef;
struct ItemDef {
    char pad[0x20];
    s16 type;
    s16 index;
};

struct ItemDef;
struct ItemRecAt18V2;


struct Obj8043EB20;
typedef struct Obj8043EB20 Obj8043EB20;

struct ObjRecAt20V2;

struct Player_func_8041EAC4_de;

struct Inner8043E56C;
typedef struct Inner8043E56C Inner8043E56C;

struct Obj8043EB20;

struct Obj8043ECE8;
typedef struct Obj8043ECE8 Obj8043ECE8;


struct Player_func_8043EBE4_de;
struct Player_func_8043EBE4_de {
    u8 flag;
    u8 data[149];
};

struct Player_func_8043EBE4_de;

struct Shared_PakMenu;




extern f32 D_800E23A0[2];
extern f32 D_800E23A8;

extern char D_800DE380[];
extern char D_800DE388_de[];
extern char D_800DE390_de[];
extern char D_8014DE10[];
extern char D_8014DDD0[];
#endif
