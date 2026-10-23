#ifndef COMMON_SOUNDVOICEPOOL_H
#define COMMON_SOUNDVOICEPOOL_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
/* Sound voices move between the available and playing lists. */
typedef struct SoundVoicePool {
    IntrusiveList available;
    IntrusiveList playing;
    s32 state;
} SoundVoicePool;

struct SongHeader;

struct func_8025CA44_S2;
struct func_8025CA44_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    s32 unk8;
};

struct func_8025C97C_S2;
struct func_8025C97C_S2 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    Triple unk10;
    char pad10[0x1C - 0x10 - sizeof(Triple)];
    void * unk1C;
};

struct func_8025D370_S3;
typedef struct func_8025D370_S3 func_8025D370_S3;



struct func_8025C67C_S1;
struct func_8025C67C_S1 {
    int unk0;
    char pad0[0x8 - 0x0 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x38 - 0xC - sizeof(int)];
    short unk38;
    char pad38[0x3A - 0x38 - sizeof(short)];
    short unk3A;
    char pad3A[0xA8 - 0x3A - sizeof(short)];
    int unkA8;
    char padA8[0xB0 - 0xA8 - sizeof(int)];
    void * unkB0;
    char padB0[0xB4 - 0xB0 - sizeof(void*)];
    int unkB4;
};

extern float D_800C3FB0_de;

extern int D_800CBB18;

struct SlotArray;
struct SlotArray {
    char pad0[0x60];
    short slot[1];
};

struct IntegerStateB4_2;
typedef struct IntegerStateB4_2 IntegerStateB4_2;

struct CLoopingSoundData_t;
struct CLoopingSoundData_t {
    s32 unk0;
    struct CLoopingSoundData_t *next;
    s32 value;
    s32 state;
    CVector3 m_vSoundPos; /* 0x10: sound source in world coordinates */
    void *m_vSoundPosPtr; /* 0x1C */
};

struct CLoopingSoundData_t;
union func_8025CC0C_S1_U14;
union func_8025CC0C_S1_U14 {
    struct CLoopingSoundData_t * v0;
    char v1;
};

extern float D_800C3FC0_de;

struct func_8025CBA8_S2;
struct func_8025CBA8_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
};

struct func_8025D1DC_S1;
typedef struct func_8025D1DC_S1 func_8025D1DC_S1;


struct func_8025CBA8_S2;
typedef struct func_8025CBA8_S2 func_8025CBA8_S2;

struct Track;
typedef struct Track Track;

struct SlotArray;
typedef struct SlotArray SlotArray;

struct IntegerStateB4_2;
struct IntegerStateB4_2 {
    char pad0[0x4];
    s32 unk_4;
    char pad4[0x10 - 0x4 - sizeof(s32)];
    s32 unk_10;
    char pad10[0x50 - 0x10 - sizeof(s32)];
    s32 unk_50;
    char pad50[0xAC - 0x50 - sizeof(s32)];
    s32 unk_AC;
    char padAC[0xB0 - 0xAC - sizeof(s32)];
    s32 unk_B0;
};

extern void func_8025C8D0_de(void);

extern int D_800CBB14;

struct func_8025C67C_S2;
typedef struct func_8025C67C_S2 func_8025C67C_S2;

struct Resource;
typedef struct Resource Resource;

struct func_8025D370_S2;
typedef struct func_8025D370_S2 func_8025D370_S2;

struct Bank_func_8025CED0_de;
struct Bank_func_8025CED0_de {
    char pad0[0x2B60];
    s32 table;
    s32 count;
};

struct Bank_func_8025CED0_de;
struct PlayerRecAt1E;

union func_8025CC0C_S1_U14;
typedef union func_8025CC0C_S1_U14 func_8025CC0C_S1_U14;

struct func_8025D258_S1;
typedef struct func_8025D258_S1 func_8025D258_S1;

extern double D_800C3FB8_de;

struct func_8025CAD0_S1;
typedef struct func_8025CAD0_S1 func_8025CAD0_S1;

struct func_8025D258_S1;
struct func_8025D258_S1 {
    char pad0[0x2B60];
    s32 unk2B60;
    char pad2B60[0x2B64 - 0x2B60 - sizeof(s32)];
    s32 unk2B64;
};

struct ObjectStateB4;
struct ObjectStateB4 {
    char unk_0;
    char pad0[0xB0 - 0x0 - sizeof(char)];
    s32 unk_B0;
};

struct SlotRecAtB4V2;

struct ContextRecAt2BB8;
typedef struct ContextRecAt2BB8 ContextRecAt2BB8;

struct func_8025CB2C_S2;
typedef struct func_8025CB2C_S2 func_8025CB2C_S2;

struct func_8025CB2C_S2;
struct func_8025CB2C_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    s32 unk8;
    char pad8[0xE - 0x8 - sizeof(s32)];
    s16 unkE;
    char padE[0x10 - 0xE - sizeof(s16)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
};



struct SongHeader;
typedef struct SongHeader SongHeader;

struct Bank;
struct Bank {
    char pad0[0x2B50];
    void *songs;
};

struct Bank;
struct PlayerRecAt24;

extern int D_800CBB10;

struct Resource;
struct Resource {
    s32 unk0;
    u16 unk4;
};

struct PlayerRecAt1E;
typedef struct PlayerRecAt1E PlayerRecAt1E;

struct ContextRecAt2BB8;
struct ContextRecAt2BB8 {
    char pad[0x2B50];
    s32 unk2B50;
    char p54[12];
    s32 unk2B60;
    s32 unk2B64;
    char p68[0x3C];
    f32 unk2BA4;
    char pa8[16];
    s32 unk2BB8;
};

struct QueueRec;
typedef struct QueueRec QueueRec;

extern void func_8025C8C0_de(void *arg0);

struct CLoopingSoundData_t;
typedef struct CLoopingSoundData_t CLoopingSoundData;

struct QueueRec;
struct QueueRec {
    void *sequence;
    s32 head;
    u8 kind;
    s32 tail;
};

struct Bank_func_8025CED0_de;
typedef struct Bank_func_8025CED0_de Bank_func_8025CED0_de;

struct func_8025D370_S2;
struct func_8025D370_S2 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    u16 unk4;
};

struct func_8025C67C_S2;
struct func_8025C67C_S2 {
    char pad0[0x7C];
    char unk7C;
    char pad7C[0x84 - 0x7C - sizeof(char)];
    char unk84;
};


extern int D_800CBB1C;

struct ContextRecAt2BB8;
struct IntPair;
struct Track;
struct Track {
    struct ContextRecAt2BB8 *unk0;
    s32 unk4;
    struct IntPair *unk8;
    void *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s32 unk38;
    f32 unk3C;
    f32 unk40; /* fade reset value */
};

struct func_8025D1DC_S1;
struct func_8025D1DC_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0x1E - 0x8 - sizeof(s32)];
    s16 unk1E;
};

struct RecCode8020061080203908;
typedef struct RecCode8020061080203908 RecCode8020061080203908;

struct func_8025C97C_S2;
typedef struct func_8025C97C_S2 func_8025C97C_S2;

struct ObjectStateB4;
typedef struct ObjectStateB4 ObjectStateB4;

struct RecCode8020061080203908;
struct RecCode8020061080203908 {
    char pad0[0x14];
    IntrusiveList unk14;
};


struct func_8025CA44_S2;
typedef struct func_8025CA44_S2 func_8025CA44_S2;


struct func_8025D370_S3;
struct func_8025D370_S3 {
    char pad0[0x20];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
};

struct Bank;
typedef struct Bank Bank;

struct PlayerRecAt24;
typedef struct PlayerRecAt24 PlayerRecAt24;


struct func_8025C67C_S1;
typedef struct func_8025C67C_S1 func_8025C67C_S1;

struct func_8025CAD0_S1;
struct func_8025CAD0_S1 {
    char pad0[0x14];
    void * unk14;
    char pad14[0x28 - 0x14 - sizeof(void*)];
    s32 unk28;
};

struct AudioHeapD844 {
    u8 *start;
    u8 *cursor;
    u32 size;
};
struct AudioRootD844 {
    char pad0[0x1DA8];
    struct AudioHeapD844 heap;
};
#endif
