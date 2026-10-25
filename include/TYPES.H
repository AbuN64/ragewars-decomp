#ifndef TYPES_H
#define TYPES_H

struct ControllerProfile;

typedef signed char s8;

typedef unsigned char u8;

typedef signed short s16;

typedef unsigned short u16;

typedef signed int s32;

typedef unsigned int u32;

typedef signed long long s64;

typedef unsigned long long u64;

typedef float f32;

typedef double f64;

typedef struct IntrusiveList IntrusiveList;

/* A doubly linked list threaded through its nodes: head and tail are the end nodes, prevOffset and
   nextOffset are the byte offsets of the previous and next links inside each node, and count is the
   number of nodes. */
struct IntrusiveList {
    void *head;
    void *tail;
    s32 prevOffset;
    s32 nextOffset;
    s32 count;
};

struct IntrusiveList;

extern s32 func_802005A0_de(s32 arg0);

extern void func_80209988_de(void *arg0);

struct CloseAttackBrain;

extern s32 func_8020F2A8_de(struct CloseAttackBrain *arg0);

extern s32 func_8020F388_de(void *arg0);

struct AiController;

extern s32 func_8020F444_de(struct AiController *arg0);

extern void func_80212FDC_eu(void *object);

extern void func_80213340_de(void *arg0);

struct AimPlayer;

extern void func_8021A9A4_de(struct AimPlayer *arg0, s32 arg1);

extern s32 Weapons_HasAmmoForMode(void *, s32);

extern void func_8022B00C_de(void *arg0);

struct LevelActor;

extern void func_8022C894_de(void *arg0, struct LevelActor *arg1);

extern void func_8022CC34_de(void *arg0, void *arg1);

extern void func_8022CD78_de(void *arg0, void *arg1);

extern void func_8022CF38_de(void *arg0, struct LevelActor *arg1);

extern void func_8022D010_de(void *arg0, void *arg1);

extern void func_8022D164_de(void *arg0, struct LevelActor *arg1);

extern void func_8022D188_de(void *unused, void *object);

extern void func_8022F204_de(s32 arg0);

extern void func_80245A00_de(float arg0);

extern void func_80245A20_de(int arg0);

extern void func_80245A5C_de(int arg0, int arg1, int arg2, int arg3);

extern void func_80245B74_de(s32 unused);

extern s32 func_8024B6F4_de(void *arg0, s32 arg1, s32 arg2);

extern s32 func_80251328_de(s32 unused0, s32 unused1, s32 keep_recent);

extern void *func_80254B8C_de(s32 arg0, u32 arg1, s32 arg2, u32 arg3);

extern void func_80254D44_de(s32, s32);

extern void func_80255F70_de(IntrusiveList *arg0);

struct RecordD90;

extern s32 func_8025B920_de(struct RecordD90 *record, s16 value, s16 id);

extern void func_8025BB7C_de(void *arg0, int arg1);

extern void func_8025E11C_de(s32 arg0);

extern void func_8025E214_de(s32 arg0);

extern void func_8025E2D4_de(s32 a);

extern void func_8025E440_de(f32 arg0);

extern int func_80264388_de(struct ControllerProfile *object);

extern int func_802643A0_de(struct ControllerProfile *object);

extern s32 func_802644FC_de(s32 arg0);

extern int func_8026475C_de(int arg0);

extern void Render_SetControllerMode(s32 a);

extern void func_80268C7C_de(void *a, s32 b);

extern void func_80274020_de(f32 *value);

extern void func_802741A4_de(f32 *arg0);

extern f32 func_80274564_de(f32 arg0);

extern f32 func_802745D0_de(f32 arg0);

extern f32 func_802746A0_de(f32 arg0, f32 arg1, f32 arg2);

extern f32 Nav_DecayToZero(f32 arg0, f32 arg1);

extern f32 Nav_RandomBetween(f32 arg0, f32 arg1);

extern void func_80276968_de(u8 amount, u8 r, u8 g, u8 b, u8 *outR, u8 *outG, u8 *outB);

extern void func_80279990_de(void *arg0);

extern int func_80284068_de(void *arg0);

extern void func_80284434_de(void *a);

extern void func_80285C78_de(void *arg0);

struct Shared_World;
struct CVector3_t;
extern s32 Scene_FindFloorPolygon(struct Shared_World *, struct CVector3_t *);

extern s32 func_8028B394_de(void *arg0, s32 arg1);

extern void func_8028EDA0_de(void *arg0);

struct OSSched;

extern void __scAppendList(struct OSSched *arg0, void *arg1);

extern void __scYield(void *arg0);

extern int func_80293440_de(u8 *a, u8 *b);

struct GameSession;

extern void Render_SetTransitionTarget(struct GameSession *object, int value);

extern void func_80293998_de(s32 arg0, s32 arg1);

extern void func_80293DF0_de(struct GameSession *arg0);

extern s32 DispatchElementEvent(s32 id, s32 event, s32, s32, s32);

extern s32 func_80297A34_de(s32 event, s32, s32, s32);

extern f32 func_8029B9FC_de(f32 arg0);

extern void func_8029BBB0_de(f32 angle, f32 *sinOut, f32 *cosOut);

extern f32 func_8029C044_de(f32 y, f32 x);

extern void func_8029CE3C_de(s32 arg0, s32 arg1, s32 arg2);

extern s32 func_8029DB58_de(s32 arg0);

extern void func_8029DD18_de(f32 arg0);

extern f32 func_8029DE48_de(f32 x);

extern s32 func_802A05D0_de(u8 *s);

extern void func_802A1918_de(int *arg0, int *arg1);

extern void func_802A23C4_de(s32 arg0);

extern void func_802A88F0_de(u8 *text, f32 x, f32 y, f32 width, f32 height, s32 shadow, s32 alpha, s32 language);

extern void func_802AA950_de(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);

extern void func_802AAB3C_de(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);

extern void func_802AAB68_de(float arg0, float arg1);

extern s32 func_802ACB18_de(void *arg0, void *arg1);

extern s32 func_802ACD28_de(void *arg0, void *arg1);

struct Actor_func_802AB400_de;

struct MultiChannelItemEffect;

extern s32 func_802ACFB0_de(struct Actor_func_802AB400_de *arg0, struct MultiChannelItemEffect *arg1);

extern void osUnmapTLB(int arg0);

extern void func_802AF150_de(void *rawPlayer);

extern void func_802AFD00_de(void *arg0);

extern void __setUsptFromTempo(void *arg0, f32 arg1);

extern f32 func_802AFE30_de(s32 arg0);

extern void func_802AFEB0_de(s32 arg0, s32 arg1);

extern void func_802AFF30_de(s32 arg0, s32 arg1);

extern void func_802AFF60_de(s32 arg0, s16 arg1);

extern void alCopy(unsigned char *source, unsigned char *destination, int count);

extern s32 func_802B15D0_de(void *arg0, s32 arg1, s32 arg2);

extern void func_802B1C34_de(void *arg0, void *arg1);

extern float func_802B6560_de(float x);

extern float func_802B7130_de(float x);

extern unsigned int func_802B7EF0_eu(void *arg0);

extern void osViSwapBuffer(s32 arg0);

typedef struct OSMesgQueue OSMesgQueue;

struct OSMesgQueue {
    void **mtqueue;
    void **fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    void **msg;
};

struct OSMesgQueue;

typedef struct Block40 Block40;

struct Block40 {
    u8 bytes[0x28];
};


struct Block40;

extern unsigned int func_802B80B4_eu(void *arg0);

typedef struct __OSContRamReadFormat __OSContRamReadFormat;

struct __OSContRamReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 address;
    u8 data[32];
    u8 datacrc;
};

struct __OSContRamReadFormat;

typedef struct OSPfs OSPfs;

struct OSPfs {
    int status;
    struct OSMesgQueue *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
};

struct OSPfs;

struct Triple;

extern u32 func_802B7B80_us(struct Triple *);

extern u32 func_802B7C50_de(struct Triple *);

extern u32 func_802B7F30_eu_x(struct Triple *);

#endif
