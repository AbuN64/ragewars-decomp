#ifndef COMMON_COLORENTRY_H
#define COMMON_COLORENTRY_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern float D_800C52F8_de;


struct State_func_8028D67C_de;
typedef struct State_func_8028D67C_de State_func_8028D67C_de;

struct State_func_8028D67C_de;
struct State_func_8028D67C_de {
    char pad[0xB4C];
    s32 values[64];
    s32 unkC4C;
    char padc50[0x1A6CC];
    f32 unk1B31C;
};



struct ColorEntry;
struct ColorEntry {
    f32 value;
    u8 red;
    u8 green;
    u8 blue;
    u8 pad;
};





struct Object_func_8028CE94_de;
struct StridedTable;

struct Object_func_8028CE94_de;
typedef struct Object_func_8028CE94_de Object_func_8028CE94_de;

struct Container;
typedef struct Container Container;

struct RecordRecAtE4;
typedef struct RecordRecAtE4 RecordRecAtE4;

struct Sub18;
struct Sub18 {
    s32 unk0;
    char pad4[8];
    s16 unkC;
};
struct RecordRecAtE4;
struct Sub18;
struct RecordRecAtE4 {
    char pad0[0x18];
    struct Sub18 *unk18;
    char pad1C[0xC8];
    u16 unkE4;
    char padE6[0x2E8 - 0xE6];
};

struct Container;
struct RecordRecAtE4;



struct Owner_func_8028D888_de;
typedef struct Owner_func_8028D888_de Owner_func_8028D888_de;







struct ColorEntry;
typedef struct ColorEntry ColorEntry;




struct ObjRecAt78V1;

struct ObjRecAt10BC;
typedef struct ObjRecAt10BC ObjRecAt10BC;

struct ObjRecAt10BC;






struct ObjRecAt7C;


struct ObjRecAt78V1;
typedef struct ObjRecAt78V1 ObjRecAt78V1;



extern float D_800C5300_de;

struct Owner_func_8028D888_de;



struct ObjRecAt7C;
typedef struct ObjRecAt7C ObjRecAt7C;


/* Clip section 1 has a stride/count header and 0x38-byte pose records.
 * Position is used to select the nearest frame; the remaining pose data is
 * consumed by the animation routines reached through Engine_GetPlatformRoutePoint. */
typedef struct AnimationPoseFrame {
    CVector3 position;
    u8 poseData[0x38 - sizeof(CVector3)];
} AnimationPoseFrame;

#endif
