#ifndef COMMON_GAMEPLAY_MOVEMENT_H
#define COMMON_GAMEPLAY_MOVEMENT_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
/* Shared records retained from origin/legacy include/shared and func_80220EB0.c. */

typedef struct Shared_Model Shared_Model;
struct Shared_Model {
    u16 unk0; /* +0x0: src/func_80220EB0.c */
    u16 flags; /* +0x2: src/func_80220EB0.c */
};


#include "COMMON/LEVEL_PLACEMENT.H"


typedef struct Shared_Scratch Shared_Scratch;
struct Shared_Scratch {
    union {
        struct {
            s32 damage[5]; /* +0x0: src/func_80220EB0.c */
        } view0_0;
        struct {
            CVector3 to; /* +0x0: src/func_80220EB0.c */
        } view0_1;
    } views0;
};


typedef struct Shared_StateInfo Shared_StateInfo;
struct Shared_StateInfo {
    s32 unk0; /* +0x0: src/func_80220EB0.c */
    void (*update)(void *, void *); /* +0x4: src/func_80220EB0.c */
    s32 * flags; /* +0x8: src/func_80220EB0.c */
    s32 pad0C[3]; /* +0xC: src/func_80220EB0.c */
};


typedef struct Shared_Surface Shared_Surface;
struct Shared_Surface {
    char pad0[0x28];
    f32 timer; /* +0x28: src/func_80220EB0.c */
    char pad2C[0x18];
    s32 flags; /* +0x44: src/func_80220EB0.c */
    char pad48[0x4];
    u16 item; /* +0x4C: src/func_80220EB0.c */
    u16 pad4E; /* +0x4E: src/func_80220EB0.c */
    u16 sound; /* +0x50: src/func_80220EB0.c */
    u16 flags52; /* 0x52 */
};


typedef struct Shared_PickupDef Shared_PickupDef;
struct Shared_PickupDef {
    s32 pad0; /* +0x0: src/func_80220EB0.c */
    s32 flags; /* +0x4: src/func_80220EB0.c */
    char pad8[0x10];
    f32 radius; /* +0x18: src/func_80220EB0.c */
    s32 pad1C; /* +0x1C: src/func_80220EB0.c */
    s32 item; /* +0x20: src/func_80220EB0.c */
};


typedef struct Shared_Pickup Shared_Pickup;
struct Shared_Pickup {
    char pad0[0x8];
    CVector3 pos; /* +0x8: src/func_80220EB0.c */
    s32 pad14; /* +0x14: src/func_80220EB0.c */
    struct Shared_PickupDef * def; /* +0x18: src/func_80220EB0.c */
};


typedef struct Shared_CharInfo Shared_CharInfo;
struct Shared_CharInfo {
    s32 pad0; /* +0x0: src/func_80220EB0.c */
    u16 sound; /* +0x4: src/func_80220EB0.c */
    s16 pad6; /* +0x6: src/func_80220EB0.c */
    s16 ammo; /* +0x8: src/func_80220EB0.c */
    s16 padA; /* +0xA: src/func_80220EB0.c */
    union {
        struct {
            s16 next_s; /* +0xC: src/func_80220EB0.c */
        } viewC_0;
        struct {
            u16 next_u; /* +0xC: src/func_80220EB0.c */
        } viewC_1;
    } viewsC;
    char padE[0x2];
};


typedef struct Shared_Floor Shared_Floor;
struct Shared_Floor {
    char pad0[0xE8];
    f32 y; /* +0xE8: src/func_80220EB0.c */
};


typedef struct Shared_Profile Shared_Profile;
struct Shared_Profile {
    char pad0[0x81];
    u8 team; /* +0x81: src/func_80220EB0.c */
    char pad82[0xD];
    u8 remote; /* +0x8F: src/func_80220EB0.c */
    char pad90[0x4];
    u8 counts; /* +0x94: src/func_80220EB0.c */
};


typedef struct Shared_Hud Shared_Hud;
struct Shared_Hud {
    char pad0[0x120];
    s32 score; /* +0x120: src/func_80220EB0.c */
    u16 pad124; /* +0x124: src/func_80220EB0.c */
    u16 bonus; /* +0x126: src/func_80220EB0.c */
};


typedef struct Shared_Shadow Shared_Shadow;
struct Shared_Shadow {
    char pad0[0x8];
    CVector3 pos; /* +0x8: src/func_80220EB0.c */
};


typedef struct Shared_Voice Shared_Voice;
struct Shared_Voice {
    char pad0[0x10];
    s32 bank; /* +0x10: src/func_80220EB0.c */
};




/* The per-character stride sound halfword has distinct auto symbols in each ROM. */
#if defined(VERSION_DE)
extern s16 D_auto_800C9FAA[];
#elif defined(VERSION_EU)
extern s16 D_auto_800CAB8E[];
#elif defined(VERSION_EU_X)
extern s16 D_auto_800CB55E[];
#elif defined(VERSION_US)
extern s16 D_auto_800C9EBE[];
#else
extern s16 D_auto_800CF1EE[];
#endif
static inline s32 strideSound(s32 index) {
#if defined(VERSION_DE)
    return (s16)((s32 *)((char *)D_auto_800C9FAA - 2))[index];
#elif defined(VERSION_EU)
    return (s16)((s32 *)((char *)D_auto_800CAB8E - 2))[index];
#elif defined(VERSION_EU_X)
    return (s16)((s32 *)((char *)D_auto_800CB55E - 2))[index];
#elif defined(VERSION_US)
    return (s16)((s32 *)((char *)D_auto_800C9EBE - 2))[index];
#else
    return (s16)((s32 *)((char *)D_auto_800CF1EE - 2))[index];
#endif
}

#include "COMMON/EXTERNS_9.H"
#endif
