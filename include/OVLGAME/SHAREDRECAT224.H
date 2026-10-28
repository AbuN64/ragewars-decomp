#ifndef OVLGAME_SHAREDRECAT224_H
#define OVLGAME_SHAREDRECAT224_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/8043D54C.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"

struct Holder;

struct SharedRecAt148;
typedef struct SharedRecAt148 SharedRecAt148;

struct Shared_func_8043DEDC_S3;
typedef struct Shared_func_8043DEDC_S3 Shared_func_8043DEDC_S3;

extern void Confirming_SelectConfirmingController(func_80250BD4_S1 *arg0);

struct SharedRecAt148;
struct SharedRecAt148 {
    char pad0[0x148];
    s8 unk148;
};

struct Shared_func_8043DEDC_S3;
struct Shared_func_8043DEDC_S3 {
    char pad0[0x78];
    s8 unk78;
    char pad79[0x6];
    s8 unk7F;
};

extern s32 Player_PlacePlayerForRound(s32 arg0);
#endif
