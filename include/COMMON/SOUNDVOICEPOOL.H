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







extern float D_800C3FB0_de;

extern int D_800CBB18;



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

extern float D_800C3FC0_de;





struct Track;
typedef struct Track Track;



extern void func_8025C8D0_de(void);

extern int D_800CBB14;


struct Resource;
typedef struct Resource Resource;


struct Bank_func_8025CED0_de;
struct Bank_func_8025CED0_de {
    char pad0[0x2B60];
    s32 table;
    s32 count;
};

struct Bank_func_8025CED0_de;
struct PlayerRecAt1E;



extern double D_800C3FB8_de;




struct SlotRecAtB4V2;

struct ContextRecAt2BB8;
typedef struct ContextRecAt2BB8 ContextRecAt2BB8;





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










struct Bank;
typedef struct Bank Bank;

struct PlayerRecAt24;
typedef struct PlayerRecAt24 PlayerRecAt24;




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
