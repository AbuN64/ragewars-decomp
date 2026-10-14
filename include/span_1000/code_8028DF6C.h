#include "span_1000/code_802BB15C.h"
#ifndef UNBAKE_SPAN_1000_CODE_8028DF6C_H
#define UNBAKE_SPAN_1000_CODE_8028DF6C_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "types.h"
typedef struct WorldSortEntry { s32 item; f32 distance; } WorldSortEntry;
struct View_func_8028FA60_de;
typedef struct View_func_8028FA60_de View_func_8028FA60_de;

struct Def;
struct Def {
    s32 type;
    s32 flags; /* 0x4 */
    char pad8[0x20];
    s16 id;
};
struct Actor_func_8028E284_de;
struct Def;
struct Actor_func_8028E284_de {
    char pad0[0x18];
    struct Def *def;
    char pad1C[0xC8];
    u16 id;
    char padE6[0x202];
};

struct SceneRecAt140;
typedef struct SceneRecAt140 SceneRecAt140;

extern s32 func_8028E6FC_de(void *arg0);

struct Node_func_8028E930_de;
struct Node_func_8028E930_de {
    struct Node_func_8028E930_de *next;
    void *queue;
};

extern float D_800C5350_de;

struct ObjRecAtE4V2;
struct ObjRecAtE4V2 {
    u8 unk0;
    char pad1[0x17];
    s32 *unk18;
    char pad2[0xE4 - 0x1C];
    u16 unkE4;
};

extern void *func_8028E770_de(void *object, int index);

struct func_8028F934_S2;
typedef struct func_8028F934_S2 func_8028F934_S2;

struct func_8028E6D8_S1;
typedef struct func_8028E6D8_S1 func_8028E6D8_S1;

struct func_8028E768_S1;
struct func_8028E768_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x18 - 0x8 - sizeof(Vec3)];
    s32 * unk18;
    char pad18[0xE4 - 0x18 - sizeof(s32*)];
    u16 unkE4;
    char padE4[0x174 - 0xE4 - sizeof(u16)];
    s32 unk174;
    char pad174[0x1A4 - 0x174 - sizeof(s32)];
    s8 unk1A4;
};

struct func_8028E044_S2;
struct func_8028E044_S2 {
    char pad0[0x1B664];
    char * unk1B664;
};

struct Panel;
struct Panel {
    s16 active;
    char pad2[0x20 - 2];
    s16 mode;
    char pad22[0x40 - 0x22];
    char row0[0x18];
    char row0Slots[0x20];
    char row1[0x18];
    char row1Slots[0x20];
    char elements[0x2E0 - 0xB0];
    s32 field2E0;
    s32 field2E4;
    s32 field2E8;
    s32 field2EC;
    s32 field2F0;
    s32 field2F4;
    s32 field2F8;
    s32 field2FC;
    s32 field300;
};

extern s32 func_8028E044_de(void *arg0, void *arg1);

extern int D_800CD710;

struct func_8028F934_S1;
struct func_8028F934_S1 {
    void * unk0;
    char pad0[0x4 - 0x0 - sizeof(void*)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0x10 - 0x8 - sizeof(s32)];
    s32 unk10;
};

struct ObjectLinks2F8;
struct ObjectLinks2F8 {
    unsigned char padding_0[756];
    void *unk_2F4;
};

struct Actor_func_8028E284_de;
struct SceneRecAt140;
struct SceneRecAt140 {
    char pad[0x138];
    struct Actor_func_8028E284_de *actors;
    s32 pad13C;
    s32 count;
};

extern float D_800C533C_de;

struct Actor_func_8028E284_de;
typedef struct Actor_func_8028E284_de Actor_func_8028E284_de;

struct func_8028E74C_S1;
struct func_8028E74C_S1 {
    char pad0[0xAC];
    char * unkAC;
};

struct ObjectLinks2E4;
struct ObjectLinks2E4 {
    unsigned char padding_0[736];
    void *unk_2E0;
};

struct Scene_func_8028FA60_de;
struct Scene_func_8028FA60_de {
    s32 pad0;
    s32 flags;
    s32 options;
    s32 padC;
    s32 mode;
    char pad14[0x38 - 0x14];
    s32 music;
    s64 *time;
};

struct func_8028FBF0_S1;
typedef struct func_8028FBF0_S1 func_8028FBF0_S1;

struct func_8028E6D8_S2;
struct func_8028E6D8_S2 {
    char pad0[0xC];
    char unkC;
    char padC[0x1508 - 0xC - sizeof(char)];
    char unk1508;
};

struct OSScClientWork;
struct OSScClientWork {
    struct OSScClientWork *next;
    Queue_func_802517B4_de *queue;
};

struct ObjectLinks2E4;
typedef struct ObjectLinks2E4 ObjectLinks2E4;

struct Scene_func_8028FA60_de;
struct View_func_8028FA60_de;
struct View_func_8028FA60_de {
    char pad0[0x78];
    struct Queue_func_802BB2A0_de messages;
    char pad90[0x2F4 - 0x90];
    struct Scene_func_8028FA60_de *current;
    struct Scene_func_8028FA60_de *next;
    char pad2FC[4];
    s32 pending; /* 0x300 */
};

extern void func_8028E284_de(SceneRecAt140 *scene);

struct IntegerState14;
typedef struct IntegerState14 IntegerState14;

struct FrameSchedule;
struct FrameSchedule {
    char pad0[0x110];
    s32 task;
    char pad114[0x10];
    u32 duration;
    char pad128[0x18];
};

struct OSScTask_s;
struct OSScTask_s {
    struct OSScTask_s *next;
    u32 state;
    u32 flags;
    void *framebuffer;
    struct { s32 type; } list;
};

extern void func_8028F8BC_de(void *arg0, void *arg1);

struct func_8028FBF0_S1;
struct func_8028FBF0_S1 {
    char pad0[0x78];
    char unk78;
    char pad78[0x2F4 - 0x78 - sizeof(char)];
    s32 unk2F4;
    char pad2F4[0x2F8 - 0x2F4 - sizeof(s32)];
    s32 unk2F8;
    char pad2F8[0x300 - 0x2F8 - sizeof(s32)];
    s32 unk300;
};

struct FrameSchedule;
typedef struct FrameSchedule FrameSchedule;

struct Scene_func_8028FA60_de;
typedef struct Scene_func_8028FA60_de Scene_func_8028FA60_de;

struct ObjRecAt78V2;
typedef struct ObjRecAt78V2 ObjRecAt78V2;

struct Shape_func_802764D4_de_2;
extern void func_8028DFE4_de(WorldSortEntry *arg0, WorldSortEntry *arg1);

struct func_8028E74C_S1;
typedef struct func_8028E74C_S1 func_8028E74C_S1;

extern int D_800CD708;

struct OSScTask_s;
typedef struct OSScTask_s OSScTask_s;

struct func_8028F89C_S1;
typedef struct func_8028F89C_S1 func_8028F89C_S1;

struct func_8028E910_S1;
typedef struct func_8028E910_S1 func_8028E910_S1;

struct OSScClientWork;
struct OSScTask_s;
struct OSSched;
struct OSSched {
    char pad0[0x20];
    s16 retraceMessage; /* 0x20 */
    char pad22[0x40 - 0x22];
    Queue_func_802517B4_de interruptQueue; /* 0x40 */
    char pad58[0x78 - 0x58];
    Queue_func_802517B4_de commandQueue; /* 0x78 */
    char pad90[0x2E0 - 0x90];
    struct OSScClientWork *clientList;
    struct OSScTask_s *audioListHead;
    struct OSScTask_s *gfxListHead;
    struct OSScTask_s *audioListTail;
    struct OSScTask_s *gfxListTail;
    struct OSScTask_s *curRSPTask;
    struct OSScTask_s *curRDPTask;
    u32 frameCount;
    s32 doAudio;
};

extern s32 func_8028E020_de(void *arg0, void *arg1);

struct ImageSet;
struct ImageSet {
    u16 columns;
    u16 rows;
    u16 width;
    u16 height;
};

struct ImageSet;
typedef struct ImageSet ImageSet;

struct func_8028E044_S1;
typedef struct func_8028E044_S1 func_8028E044_S1;

struct OSScClientWork;
typedef struct OSScClientWork OSScClientWork;

struct func_8028F934_S2;
struct func_8028F934_S2 {
    char pad0[0x2E4];
    void * unk2E4;
    char pad2E4[0x2E8 - 0x2E4 - sizeof(void*)];
    void * unk2E8;
    char pad2E8[0x2EC - 0x2E8 - sizeof(void*)];
    void * unk2EC;
    char pad2EC[0x2F0 - 0x2EC - sizeof(void*)];
    void * unk2F0;
    char pad2F0[0x300 - 0x2F0 - sizeof(void*)];
    s32 unk300;
};

struct ObjectLinks2F8;
typedef struct ObjectLinks2F8 ObjectLinks2F8;

struct func_8028E044_S2;
typedef struct func_8028E044_S2 func_8028E044_S2;

struct Node_func_8028E930_de;
struct func_8028E910_S1;
struct func_8028E910_S1 {
    char pad0[0x20];
    char unk20;
    char pad20[0x40 - 0x20 - sizeof(char)];
    char unk40;
    char pad40[0x2E0 - 0x40 - sizeof(char)];
    struct Node_func_8028E930_de * unk2E0;
};

struct OSSched;
typedef struct OSSched OSSched;

struct ObjRecAtE4V2;
typedef struct ObjRecAtE4V2 ObjRecAtE4V2;

struct Node_func_8028FC10_de;
typedef struct Node_func_8028FC10_de Node_func_8028FC10_de;

struct ObjRecAt78V2;
struct ObjRecAt78V2 {
    char pad0[0x78];
    char unk78;
};

struct func_8028E6D8_S2;
typedef struct func_8028E6D8_S2 func_8028E6D8_S2;

extern int func_8028FD44_de(int arg0);

struct func_8028E6D8_S1;
struct func_8028E6D8_S1 {
    char pad0[0x1504];
    s32 unk1504;
};

extern void func_8028E068_de(void *arg0);

struct func_8028F934_S1;
typedef struct func_8028F934_S1 func_8028F934_S1;

extern s32 func_8028DF90_de(void *arg0, s32 arg1);

struct func_8028F89C_S1;
struct func_8028F89C_S1 {
    char pad0[0x2E0];
    char * unk2E0;
};

extern void *func_8028F9AC_de(void *arg0);

struct Panel;
typedef struct Panel Panel;

struct Node_func_8028FC10_de;
struct Node_func_8028FC10_de {
    char pad0[8];
    u32 flags;
    char padC[4];
    s32 type;
};

struct Node_func_8028E930_de;
typedef struct Node_func_8028E930_de Node_func_8028E930_de;

extern void *func_8028F94C_de(void *object);

struct func_8028E044_S1;
struct func_8028E044_S1 {
    char pad0[0x3C];
    char unk3C;
    char pad3C[0x138 - 0x3C - sizeof(char)];
    char * unk138;
    char pad138[0x140 - 0x138 - sizeof(char*)];
    s32 unk140;
    char pad140[0x1B6A4 - 0x140 - sizeof(s32)];
    s32 unk1B6A4;
};

struct func_8028E768_S1;
typedef struct func_8028E768_S1 func_8028E768_S1;

struct IntegerState14;
struct IntegerState14 {
    unsigned char padding_0[4];
    s32 unk_4;
    unsigned char padding_8[8];
    s32 unk_10;
};


struct Ctx_func_8028F544_de;
struct Node_func_8028F544_de;
struct Scene_func_8028FA60_de;
struct View_func_8028FA60_de;
extern s32 func_8028F544_de(struct Ctx_func_8028F544_de *, struct Node_func_8028F544_de **, struct Node_func_8028F544_de **, s32);
extern void func_8028FA60_de(struct View_func_8028FA60_de *, struct Scene_func_8028FA60_de *, struct Scene_func_8028FA60_de *);

typedef struct SchedulerTask {
 struct SchedulerTask *next; u32 state,flags;void *framebuffer;
 struct {s32 type;char pad[0x3C];} list; void *queue; void *message;
} SchedulerTask;
typedef struct Scheduler {
 char pad0[0x2E8];SchedulerTask *gfxHead,*audioTail,*gfxTail,*rsp,*rdp;
} Scheduler;
typedef struct SchedulerFrame {
 char pad0[0x110];void *framebuffer;s32 serial;char pad118[0x140-0x118];
} SchedulerFrame;
extern f32 D_800CD750;
extern s32 D_800CD700;
extern s32 D_8014D464;
extern void func_80253CEC_de(s32,s32);
extern s32 func_8028FA0C_de(void *,void *);

#endif
