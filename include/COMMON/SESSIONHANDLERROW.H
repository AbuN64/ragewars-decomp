#ifndef COMMON_SESSIONHANDLERROW_H
#define COMMON_SESSIONHANDLERROW_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GFX.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/DISPLAY.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "sdk/PFS/8044E8B0.H"



struct ObjRecAt255C8;
typedef struct ObjRecAt255C8 ObjRecAt255C8;

struct func_80293808_S1;
typedef struct func_80293808_S1 func_80293808_S1;


struct func_80292FA4_S1;
struct func_80292FA4_S1 {
    char pad0[0x26DC8];
    s32 unk26DC8;
};

struct func_8029382C_S1;
struct func_8029382C_S1 {
    char pad0[0x26DB8];
    s32 unk26DB8;
};

struct func_8029382C_S1;
typedef struct func_8029382C_S1 func_8029382C_S1;

struct ObjRecAt255C8;

struct func_80293318_S1;
typedef struct func_80293318_S1 func_80293318_S1;

extern int D_800CD8A4_de;

struct func_80293574_S1;
typedef struct func_80293574_S1 func_80293574_S1;

extern int D_800CD8A0_de;

struct func_80293808_S1;
struct func_80293808_S1 {
    char pad0[0x26DBC];
    int unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(int)];
    char unk26DC1;
};

struct func_80293574_S1;
struct func_80293574_S1 {
    char pad0[0x26DC0];
    unsigned char unk26DC0;
    char pad26DC0[0x26DC1 - 0x26DC0 - sizeof(unsigned char)];
    unsigned char unk26DC1;
    char pad26DC1[0x26DC4 - 0x26DC1 - sizeof(unsigned char)];
    int unk26DC4;
};

#include "COMMON/DISPLAY.H"

struct func_80293318_S1;
struct func_80293318_S1 {
    char pad0[0x25580];
    char unk25580;
};


struct func_80293774_S1;
struct func_80293774_S1 {
    char pad0[0x26DB4];
    s32 unk26DB4;
    char pad26DB4[0x26DB8 - 0x26DB4 - sizeof(s32)];
    s32 unk26DB8;
    char pad26DB8[0x26DBC - 0x26DB8 - sizeof(s32)];
    s32 unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(s32)];
    s8 unk26DC1;
    char pad26DC1[0x26DC4 - 0x26DC1 - sizeof(s8)];
    func_8022E280_S1_U744 unk26DC4;
};

struct func_80292FA4_S1;
typedef struct func_80292FA4_S1 func_80292FA4_S1;

extern int D_800CD8B4;

extern int D_800CD734;

struct func_80293774_S1;
typedef struct func_80293774_S1 func_80293774_S1;



#include "COMMON/RENDERCOUNTERS.H"

extern char D_80142CB8[];

extern Gfx *D_80110634;
extern s32 D_800CD8C8_de;
extern u32 D_800DE850;
extern void *D_8014D468_de[];
extern void func_8028F754_de(Panel *, s32, s32, s32, u8);
#include "sdk/SCHED/8028DF6C_7.H"
extern void func_802B6B80_de(s32 *);
extern void Items_ResetGameOptions(void *);

typedef Node_Pak_CountLiveNodes TimingQueue;
typedef struct TimingWorld {
 char pad0[0x255C8];
 RaceViewportState viewport;
 char pad267C8[0x5E8]; f32 unk26DB0;
 s32 previousMode; u32 unk26DB8,unk26DBC;
 u8 fadeFast; u8 unk26DC1;
 char pad26DC2[2]; f32 fade;
 char pad26DC8[0xC]; s32 unk26DD4;
} TimingWorld;
/* Drawing callback followed by the remaining two state-dispatch slots. */
typedef struct FrameCallback {
 void (*draw)(TimingWorld *);
 void (*auxiliary0)(TimingWorld *);
 void (*auxiliary1)(TimingWorld *);
} FrameCallback;
extern FrameCallback D_800CD790[];
extern u64 func_802BADC0_de(void);
extern s32 Camera_GetSequenceRequest(void);
extern u32 func_80245850_de(void);
extern s32 Pak_CountLiveNodes(Node_Pak_CountLiveNodes **);
struct GameSession;
extern void func_80293C34_de(struct GameSession *);
extern void func_804037D4_de(void);
extern u32 D_8011B9F8;
extern u32 D_801428AC;
extern u32 D_80142C34;
extern u32 D_80142CA4;
extern f32 D_80142C38[2];
extern TimingQueue *D_8014561C;

extern u32 D_800CD884;
extern f32 rwFrameBuildSeconds;
extern f32 D_800C5468;
extern void func_802539EC_de(s32,s32);
extern void func_80293268_de(void *);

extern int Render_IsSnapshotActive(void);

extern s32 func_802BCF10_de(void);
extern char D_80146CE8[];
extern char D_800C5400_de[];
extern char D_800C5408_de[];
extern char D_800C5414_de[];

extern s32 D_8014286C;
extern void func_802947C8_de(void *arg0, s32 arg1);

#endif
