#ifndef COMMON_CHANNEL_H
#define COMMON_CHANNEL_H
struct Channel;
#ifndef SPAN_1000_CODE_802393F4_H
#define SPAN_1000_CODE_802393F4_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
struct ScreenMessageOwner;
extern void func_8023A1F4_de(struct ScreenMessageOwner *arg0);


extern float D_800C8664;



extern float D_800C8658;

extern float D_800C3598_de;

extern void Gsky_SetShakeChannel(struct Channel *arg0, float arg1, int arg2);




extern void Gsky_StartFadeModeOne(char *object);


struct Channel;
struct Channel {
    s32 mode;
    f32 level;
    s32 state[3]; /* 0x08..0x10 */
};

struct Channel;
struct RecordRecAt18;
struct RecordRecAt18 {
    char pad[8];
    Triple triple;
    f32 value;
    struct Channel channels[3];
};


extern void Gsky_InitializeShakeRecord(void *arg0);


struct IntegerStateF24;
typedef struct IntegerStateF24 IntegerStateF24;


extern float D_800C3548_de;


extern float D_800C3570_de;

extern int Gsky_StartFadeModeTwo(void *arg0);



struct ScreenMessagePool;
extern void Gsky_ActivateMessagePool(struct ScreenMessageOwner *arg0, struct ScreenMessagePool *arg1);

extern void func_8023A24C_de(void *arg0);

extern s32 Gsky_UpdateShakeRecord(s32 arg0);



struct IntegerStateF24;
struct IntegerStateF24 {
    unsigned char padding_0[3864];
    s32 unk_F18;
    s32 unk_F1C;
    s32 unk_F20;
};





struct Wave;
struct Wave {
    s32 kind;
    char pad4[0xC - 4];
    f32 amplitude;
    f32 phase;
};

extern float D_800C3590_de;

extern double D_800C3550_de;




extern void func_80239FCC_de(void);


extern void Gsky_InitializeShakeChannel(void *arg0);


extern float D_800C865C;


struct Wave;
extern f32 Gsky_SampleShakeWave(struct Wave *wave);

struct NodeGskyActivateMessagePool;

extern float D_800C8668;

extern void func_8023A114_de(void *arg0, s32 arg1);




struct RecordRecAt18;
extern void Gsky_SetShakeRecord(struct RecordRecAt18 *record, f32 first, f32 second, f32 third, f32 value, s32 mode, Triple triple);


extern void func_8023A190_de(void *arg0, int arg1);

extern float D_800C3594_de;

extern void Gsky_UpdateFloorSurface(void *arg0);

extern void func_80239404_de(void);






/* Allocation buffer used by message storage constructors. */
typedef struct MessageBuffer {
    s32 *allocation;
    s32 first;
    s32 count;
} MessageBuffer;

/* On-screen message recycling and distribution share these list owners. */
struct ScreenMessageOwner {
    s32 allocation; /* 0x00 */
    s32 allocationSize; /* 0x04 */
    s32 count; /* 0x08 */
    u8 padding00C[0x40 - 0xC];
    u8 rendering; /* 0x40 */
    u8 padding041[0xF18 - 0x41];
    MessageBuffer storage; /* 0xF18 */
    IntrusiveList activeMessages; /* 0xF24 */
    u8 paddingF38[0x1200 - 0xF38];
    s32 state; /* 0x1200 */
    s32 field1204; /* the owner initialized by func_8044A62C_de is0x1208 */
};
struct ScreenMessagePool {
    u8 padding000[4];
    struct ScreenMessagePool *next; /* 0x04, D_80140FE8 chain */
    u8 padding008[0xE38];
    IntrusiveList freeMessages; /* 0xE40 */
};

struct CCameraText_t;
extern CCameraText *Camera_PostScreenMessage(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool, u8 *text);

#endif
#endif
