#ifndef UNBAKE_SPAN_1000_CODE_80291054_H
#define UNBAKE_SPAN_1000_CODE_80291054_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "gfx.h"
#include "shared/gameplay_camera.h"
#include "resident_event_handler.h"
#include "span_1000/code_8028DF6C.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8043F69C.h"
/* One state-dispatch row in D_800CD78C, stride 0xC. */
typedef struct SessionHandlerRow {
    void (*update)(void *);
    char reserved4[8];
} SessionHandlerRow;

struct Display;
typedef struct Display Display;

struct ObjRecAt255C8;
typedef struct ObjRecAt255C8 ObjRecAt255C8;

struct func_80293808_S1;
typedef struct func_80293808_S1 func_80293808_S1;

extern int func_802934F8_de();

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
struct ObjRecAt255C8 {
    char pad0[0x25580];
    char unk25580;
    char pad25580[0x255C8 - 0x25580 - sizeof(char)];
    char unk255C8;
};

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

struct FrameRecAt11C;
typedef struct FrameRecAt11C FrameRecAt11C;

struct FrameRecAt11C;
struct FrameRecAt11C {
    char pad[0x114];
    int color;
    int depth;
    char tail[0x24];
};

struct Display;
struct Display {
    FrameRecAt11C frames[3];
    void *current;
};

struct func_80293318_S1;
struct func_80293318_S1 {
    char pad0[0x25580];
    char unk25580;
};

extern void func_80292F24_de();

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

extern float func_802917D8_de();
extern void func_80293534_de(void);

typedef struct ObjRecAt26DC1 {
    char pad0[0x26DB0];
    f32 unk26DB0;
    char pad26DB4[0x26DBC - 0x26DB4];
    s32 unk26DBC;
    char pad26DC0[1];
    s8 unk26DC1;
} ObjRecAt26DC1;

typedef struct RenderView {
    char pad00[0x14]; Vec3 direction; char pad20[0xD0]; s16 kind; char padF2[0x1E]; void *buffer;
    char pad114[0x18]; struct RenderView *previous, *next; char pad134[0xC];
} RenderView;
typedef struct RenderState {
    union { RenderView views[4]; Display display; } ring; char pad500[0x2688C]; char settings[0x28]; s32 handle;
    char pad26DB8[0x10]; s32 enabled, field26DCC, field26DD0, field26DD4;
} RenderState;
typedef struct RenderCounters {
    s32 unk0, unk4, unk8, unkC;
    s32 unk10;
    f32 timeLimit;
    s32 mode;
    s32 elapsed;
    s32 state;
    s32 teams;
    s32 round;
    s32 scores[5];
    s32 counts[5];
    s32 option54;
    char pad58[0x14];
    s32 mask;
    char pad70[8];
    s32 option78;
    s32 unk7C;
    s32 counter80;
    s32 unk84;
    s32 first, second;
    char pad90[0x18];
    s32 humanWon;
} RenderCounters;
extern char D_801428C0[];
extern char D_80142CB8[];
extern char D_80146CC0[];
extern RenderCounters D_801468A0;
extern Gfx *D_80110634;
extern s32 D_800CD8C8_de;
extern u32 D_800DE850;
extern void *D_8014D468_de[];
extern void func_802BAC60_de(void *, s32, s32);
extern void func_8028F754_de(Panel *, s32, s32, s32, u8);
extern void func_8028F864_de(void *, void *, s32);
extern void func_80293590_de(void *);
extern void func_802B6B80_de(s32 *);
extern void func_80445074_eu(void *);
extern void func_8044DC60_de(void *);
extern void func_80293054_de(Display *);

typedef Node_func_80442A28_de TimingQueue;
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
extern s32 func_80245B0C_de(void);
extern u32 func_80245850_de(void);
extern s32 func_80442A28_de(Node_func_80442A28_de **);
extern void func_80253344_de(s32);
extern void func_80292308_de(TimingWorld *);
extern void func_80293C34_de(void *);
extern void func_804037D4_de(void);
extern u32 D_8011B9F8;
extern u32 D_801428AC;
extern u32 D_80142C34;
extern u32 D_80142CA4;
extern struct Frame *D_8011BDC0;
extern struct Frame *D_80146CD8;
extern f32 D_80142C38[2];
extern TimingQueue *D_8014561C;

extern u32 D_800CD884;
extern f32 rwFrameBuildSeconds;
extern f32 D_800C5468;
extern void func_802539EC_de(s32,s32);
extern void func_80293268_de(void *);

#endif
