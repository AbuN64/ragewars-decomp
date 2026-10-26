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



struct SelectionTextLoadApplyArtsendTextureOverride;



extern void TEngine_UpdateArtsendTexturePreview();


extern ResidentState D_8014AEB8;



struct SelectionTextLoadApplyArtsendTextureOverride;
typedef struct SelectionTextLoadApplyArtsendTextureOverride SelectionTextLoadApplyArtsendTextureOverride;


struct AnimationInfo;
typedef struct AnimationInfo AnimationInfo;




struct AnimationInfo;



struct ResourceData80295B84;
extern void TextLoad_PrepareTextureVariation(s32 index, struct ResourceData80295B84 *resource);

extern s32 D_auto_800D2AE8;

extern s32 D_auto_800D2AE4;

extern s32 D_auto_800D2AF4;

extern s32 D_auto_800D2AF8;

extern void TEngine_LoadSelectedTexture(void);
extern u8 s_artsendActivatedText[0x14];
extern u8 s_artsendDeactivatedText[0x14];
extern f32 D_auto_800CA634;
extern s32 D_auto_800D2AFC;


/* Texture animation metadata returned to material and texture consumers. */
#include "ANIM/ANIMATION_FRAME.H"



extern void TextLoad_ApplyArtsendTextureOverride(s32 resource, s32 **data);
extern void TextLoad_ApplyArtsendPaletteOverride(s32 resource, s32 **data);
extern s32 D_8014D070;
extern s32 D_8014D074;
extern s32 D_8014D078;
extern s32 D_8014D07C;
#endif
