#ifndef COMMON_RESIDENTSTATE_H
#define COMMON_RESIDENTSTATE_H
#include "TYPES.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ResidentState;
struct ResidentState {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct ResidentSlot;

struct ResidentEntry;







typedef struct ResidentState ResidentState;
typedef struct ResidentSlot ResidentSlot;
typedef struct ResidentEntry ResidentEntry;



struct Selection_func_802955EC_us_rev1;



extern void func_80294F1C_us_rev1();


extern ResidentState D_8014AEB8;



struct Selection_func_802955EC_us_rev1;
typedef struct Selection_func_802955EC_us_rev1 Selection_func_802955EC_us_rev1;


struct AnimationInfo;
typedef struct AnimationInfo AnimationInfo;




struct AnimationInfo;



struct ResourceData80295B84;
extern void func_80294C8C_de(s32 index, struct ResourceData80295B84 *resource);

extern s32 D_auto_800D2AE8;

extern s32 D_auto_800D2AE4;

extern s32 D_auto_800D2AF4;

extern s32 D_auto_800D2AF8;

extern void Engine_LoadSelectedTexture(void);
extern u8 D_800CA60C[0x14];
extern u8 D_auto_800CA620[0x14];
extern f32 D_auto_800CA634;
extern s32 D_auto_800D2AFC;


/* Texture animation metadata returned to material and texture consumers. */
struct Shared_AnimFrame;
typedef struct Shared_AnimInfo {
    s32 count;
    s32 unk4;
    struct Shared_AnimFrame *frame;
} Shared_AnimInfo;


extern void func_802955EC_us_rev1(s32 resource, s32 **data);
extern void func_802956AC_us_rev1(s32 resource, s32 **data);
extern s32 D_8014D070;
extern s32 D_8014D074;
extern s32 D_8014D078;
extern s32 D_8014D07C;
#endif
