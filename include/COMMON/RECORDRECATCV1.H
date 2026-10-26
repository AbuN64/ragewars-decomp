#ifndef COMMON_RECORDRECATCV1_H
#define COMMON_RECORDRECATCV1_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTLAYERMETRICS.H"




struct TargetPakDisablePreviewSelection;
struct TargetPakDisablePreviewSelection {
    char pad0[0xA8];
    s32 first;
    char padAC[0xD0 - 0xAC];
    s32 second;
};
struct RecordRecAtCV1;
struct TargetPakDisablePreviewSelection;

struct RecordRecAtCV1;

struct PakPreview;
typedef struct PakPreview PakPreview;


struct RecordRecAt20V2;
struct PakMenuSlot;

struct PakPreview;


struct RecordRecAt24;

struct RecordRecAt24;

struct OwnerRecAt5D8V1;

struct Shared_PakMenu;

struct RecordRecAt20V2;

struct Shared_PakMenu;


#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 Pak_UpdateOwnerChannelLabel(struct LayeredText *field, struct Shared_PakMenu *holder);
#endif

extern s32 Control_PeekPakChange(s32);

extern void Pak_ProbeStatus(s32);
void Pak_ProbeStatus(s32);
s32 Pak_GetStatus(s32);

extern char D_800DCD80[];

extern char g_pakFormatDottedTriple[];

extern char g_pakFormatInt04[];
#endif
