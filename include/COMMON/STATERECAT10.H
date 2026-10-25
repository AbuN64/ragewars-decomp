#ifndef COMMON_STATERECAT10_H
#define COMMON_STATERECAT10_H
#include "TYPES.H"
struct CShakeAxis_t;
typedef struct CShakeAxis_t CShakeAxis;



extern float D_800C3080_de;

extern float D_800C3084_de;

extern float D_800C3060_de;

extern float D_800C3078_de;


extern float D_800C3050_de;

struct ObjectLinks11DC;
typedef struct ObjectLinks11DC ObjectLinks11DC;

struct CShakeAxis_t;
struct CShakeAxis_t {
    s32 mode;
    f32 value;
    f32 m_LastShake;
    f32 m_Amp;
    f32 m_Angle;
};

extern float D_800C3074_de;


extern float D_800C3054_de;


extern float D_800C3088_de;

extern float D_800C3064_de;

struct MeasuredRecAt1D8V3;

extern float D_800C3058_de;

extern float D_800C3070_de;

extern float D_800C308C_de;


extern float D_800C305C_de;

struct ObjectLinks11DC;
struct ObjectLinks11DC {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x62E - 0x5D8 - sizeof(char*)];
    s16 unk_62E;
    char pad62E[0x650 - 0x62E - sizeof(s16)];
    s16 unk_650;
    char pad650[0x6AC - 0x650 - sizeof(s16)];
    s32 unk_6AC;
    char pad6AC[0x770 - 0x6AC - sizeof(s32)];
    s16 unk_770;
    char pad770[0x11D8 - 0x770 - sizeof(s16)];
    f32 unk_11D8;
};
#endif
