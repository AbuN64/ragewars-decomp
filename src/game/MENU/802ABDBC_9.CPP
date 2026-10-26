#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "TYPES.H"
#include "COMMON/MENU_ABBDC_VERSIONS.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/ENTRYRECATE.H"
#include "SYSTEM_2/8025E280.H"
#include "COMMON/CHANNEL.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("span_1000", Pickup_ApplySpecialPickup);
#endif
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
extern float D_800C6264;
extern float D_800C626C;
extern float D_800C6278_de;
extern float D_800C62A0;
extern float D_800C62A8;
extern float D_800C62B0;
extern u8 *D_800D30AC[];
extern u8 *D_800D3128[];
extern u8 *D_800D312C[];
extern u8 *D_800D3130[];
extern u8 *D_800D3134[];
extern u8 *D_800D3138[];
extern u8 *D_800D313C[];
extern u8 *D_800D3140_de[];
extern u8 *D_800D3144[];
extern u8 *D_800D3148[];
extern u8 *D_800D3150[];
extern u8 *D_800D3154[];
extern u8 *D_800D3158[];
extern u8 *D_800D315C[];
extern u8 *D_800D3160[];
extern u8 *D_800D31B8[];



typedef struct CPersistentPlayerData_t CPersistentPlayerData;
struct CPersistentPlayerData_t {
    u8 pad0[16]; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    s32 m_PowerOfViper; /* +0x10: src/Pickup_ApplySpecialPickup.c */
    s8 m_PowerOfBear; /* +0x14: src/Pickup_ApplySpecialPickup.c */
    s8 m_SpiritOfCoyote; /* +0x15: src/Pickup_ApplySpecialPickup.c */
    s8 m_SpiritOfCougar; /* +0x16: src/Pickup_ApplySpecialPickup.c */
    s8 m_FragFestTimeTrialIcons; /* +0x17: src/Pickup_ApplySpecialPickup.c */
    u8 pad18[376]; /* +0x18: src/Pickup_ApplySpecialPickup.c */
};



typedef struct Shared_MenuBonusColumn Shared_MenuBonusColumn;
struct Shared_MenuBonusColumn {
    u8 value; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    u8 rest[399]; /* +0x1: src/Pickup_ApplySpecialPickup.c */
};



typedef struct Shared_MenuAmountColumn Shared_MenuAmountColumn;
struct Shared_MenuAmountColumn {
    s32 value; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    u8 rest[396]; /* +0x4: src/Pickup_ApplySpecialPickup.c */
};



typedef struct SharedRecAt13E0 SharedRecAt13E0;
struct SharedRecAt13E0 {
    char pad0[0x8];
    CVector3 position; /* +0x8: passed by value to SoundElement_PlaySoundAtPosition */
    char pad14[0x4];
    struct SharedRecAtC * unk18; /* +0x18: src/Pickup_ApplySpecialPickup.c */
    char pad1C[0x5B8];
    s32 unk5D4; /* +0x5D4: src/Pickup_ApplySpecialPickup.c */
    struct SharedRecAt92V1 * unk5D8; /* +0x5D8: src/Pickup_ApplySpecialPickup.c */
    void * unk5DC; /* +0x5DC: src/Pickup_ApplySpecialPickup.c */
    char pad5E0[0x4];
    s32 unk5E4; /* +0x5E4: src/Pickup_ApplySpecialPickup.c */
    char pad5E8[0xC];
    u16 unk5F4; /* +0x5F4: src/Pickup_ApplySpecialPickup.c */
    u16 unk5F6; /* +0x5F6: src/Pickup_ApplySpecialPickup.c */
    u16 unk5F8; /* +0x5F8: src/Pickup_ApplySpecialPickup.c */
    char pad5FA[0xBEA];
    f32 unk11E4; /* +0x11E4: src/Pickup_ApplySpecialPickup.c */
    char pad11E8[0x44];
    s32 unk122C; /* +0x122C: src/Pickup_ApplySpecialPickup.c */
    f32 unk1230; /* +0x1230: src/Pickup_ApplySpecialPickup.c */
    char pad1234[0x4];
    s32 unk1238; /* +0x1238: src/Pickup_ApplySpecialPickup.c */
    u8 unk123C; /* +0x123C: src/Pickup_ApplySpecialPickup.c */
    u8 unk123D; /* +0x123D: src/Pickup_ApplySpecialPickup.c */
    u8 unk123E; /* +0x123E: src/Pickup_ApplySpecialPickup.c */
    char pad123F[0x1];
    f32 unk1240; /* +0x1240: src/Pickup_ApplySpecialPickup.c */
    f32 rightAxisValue; /* +0x1244: src/Pickup_ApplySpecialPickup.c */
    char pad1248[0x198];
    s32 unk13E0; /* +0x13E0: src/Pickup_ApplySpecialPickup.c */
};



typedef struct SharedRecAt8V2 SharedRecAt8V2;
struct SharedRecAt8V2 {
    u8 ** unk0; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    s16 unk4; /* +0x4: src/Pickup_ApplySpecialPickup.c */
    s16 unk6; /* +0x6: src/Pickup_ApplySpecialPickup.c */
    s16 unk8; /* +0x8: src/Pickup_ApplySpecialPickup.c */
    char padA[0x2];
};



typedef struct SharedRecAtC SharedRecAtC;
struct SharedRecAtC {
    char pad0[0xC];
    s16 unkC; /* +0xC: src/Pickup_ApplySpecialPickup.c */
};



typedef struct SharedRecV1 SharedRecV1;
struct SharedRecV1 {
    char pad0[0x8F];
    u8 unk8F; /* +0x8F: src/Pickup_ApplySpecialPickup.c */
};



typedef struct SharedRecAt84 SharedRecAt84;
struct SharedRecAt84 {
    char pad0[0x24];
    s32 unk24; /* +0x24: src/Pickup_ApplySpecialPickup.c */
    char pad28[0x2C];
    s32 unk54; /* +0x54: src/Pickup_ApplySpecialPickup.c */
    char pad58[0x1C];
    s32 unk74; /* +0x74: src/Pickup_ApplySpecialPickup.c */
    char pad78[0x8];
    s32 unk80; /* +0x80: src/Pickup_ApplySpecialPickup.c */
    s32 unk84; /* +0x84: src/Pickup_ApplySpecialPickup.c */
};



typedef struct SharedRecAt92V1 SharedRecAt92V1;
struct SharedRecAt92V1 {
    char pad0[0x8F];
    u8 unk8F; /* +0x8F: src/Pickup_ApplySpecialPickup.c */
    u8 unk90; /* +0x90: src/Pickup_ApplySpecialPickup.c */
    char pad91[0x1];
    u8 unk92; /* +0x92: src/Pickup_ApplySpecialPickup.c */
};



typedef struct SharedRecV2 SharedRecV2;
struct SharedRecV2 {
    char pad0[0x5DC];
    void * unk5DC; /* +0x5DC: src/Pickup_ApplySpecialPickup.c */
    char pad5E0[0x1100];
    void * unk16E0; /* +0x16E0: src/Pickup_ApplySpecialPickup.c */
};



typedef struct SharedRecAt16E0V1 SharedRecAt16E0V1;
struct SharedRecAt16E0V1 {
    char pad0[0x5D8];
    struct SharedRecAt92V2 * unk5D8; /* +0x5D8: src/Pickup_ApplySpecialPickup.c */
    void * unk5DC; /* +0x5DC: src/Pickup_ApplySpecialPickup.c */
    char pad5E0[0xBFC];
    f32 unk11DC; /* +0x11DC: src/Pickup_ApplySpecialPickup.c */
    char pad11E0[0x4C];
    s32 unk122C; /* +0x122C: src/Pickup_ApplySpecialPickup.c */
    char pad1230[0x4B0];
    struct SharedRecAt16E0V1 * unk16E0; /* +0x16E0: src/Pickup_ApplySpecialPickup.c */
    char pad16E4[0x4];
};



typedef struct SharedRecAt92V2 SharedRecAt92V2;
struct SharedRecAt92V2 {
    char pad0[0x92];
    u8 unk92; /* +0x92: src/Pickup_ApplySpecialPickup.c */
};



typedef struct Shared_PlayerListMenuGlobals Shared_PlayerListMenuGlobals;
struct Shared_PlayerListMenuGlobals {
    void * players; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    u8 padToMenu[6204]; /* +0x4: src/Pickup_ApplySpecialPickup.c */
    SharedRecAt84 menu; /* +0x1840: src/Pickup_ApplySpecialPickup.c */
};



typedef struct Shared_PlayerMenuGlobals Shared_PlayerMenuGlobals;
struct Shared_PlayerMenuGlobals {
    s32 count; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    u8 padToPlayers[20]; /* +0x4: src/Pickup_ApplySpecialPickup.c */
    Shared_PlayerListMenuGlobals list; /* +0x18: src/Pickup_ApplySpecialPickup.c */
};



typedef struct Shared_FullPlayerMenuGlobals Shared_FullPlayerMenuGlobals;
struct Shared_FullPlayerMenuGlobals {
    struct SharedRecAt16E0V1 * entries; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    Shared_PlayerMenuGlobals tail; /* +0x4: src/Pickup_ApplySpecialPickup.c */
};

/* The values Pickup_ApplySpecialPickup loads by address:
 * 0x800CB3F0 = 105.0 (float, D_800C6260 in this cartridge's tables)
 * 0x800CB3F4 = 195.0 (float, D_800C6264 in this cartridge's tables)
 * 0x800CB3F8 = 300.0 (float, D_800CB3F8 in this cartridge's tables)
 * 0x800CB3FC = 255.0 (float, D_800C626C in this cartridge's tables)
 * 0x800CB400 = 225.0 (float, D_800C6270_de in this cartridge's tables)
 * 0x800CB404 = 150.0 (float, D_800C6274_de in this cartridge's tables)
 * 0x800CB408 = 255.0 (float, D_800C6278_de in this cartridge's tables)
 * 0x800CB40C = 150.0 (float, D_800C627C_de in this cartridge's tables)
 * 0x800CB410 = 255.0 (float, D_800CB410 in this cartridge's tables)
 * 0x800CB414 = 180.0 (float, D_800CB414 in this cartridge's tables)
 * 0x800CB418 = 225.0 (float, D_800C6288_de in this cartridge's tables)
 * 0x800CB41C = 225.0 (float, D_800C628C_de in this cartridge's tables)
 * 0x800CB420 = 450.0 (float, D_800C6290_de in this cartridge's tables)
 * 0x800CB424 = 270.0 (float, D_800C6294_de in this cartridge's tables)
 * 0x800CB428 = 255.0 (float, D_800C6298 in this cartridge's tables)
 * 0x800CB42C = 180.0 (float, D_800C629C in this cartridge's tables)
 * 0x800CB430 = 255.0 (float, D_800C62A0 in this cartridge's tables)
 * 0x800CB434 = 300.0 (float, D_800C62A4 in this cartridge's tables)
 * 0x800CB438 = 255.0 (float, D_800C62A8 in this cartridge's tables)
 * 0x800CB43C = 300.0 (float, D_800C62AC in this cartridge's tables)
 * 0x800CB440 = 255.0 (float, D_800C62B0 in this cartridge's tables)
 */
void Player_IncrementLevelProgress(void *, int);


s32 XPlus_NextRandomInteger(void);
s32 Menu_RequestTrackByKey(s32);
typedef CPersistentPlayerData PlayerMenuData;
extern PlayerMenuData D_80102B00[];
typedef Shared_MenuBonusColumn MenuBonusColumn;

extern MenuBonusColumn D_800FEB15[];
extern MenuBonusColumn D_800FEB16[];
extern MenuBonusColumn D_800FEB17[];
typedef Shared_MenuAmountColumn MenuAmountColumn;
extern MenuAmountColumn D_800FEB10[];
extern MenuBonusColumn D_80102B14[];
extern Shared_FullPlayerMenuGlobals D_80140F84;





extern f32 D_800CB410;



           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

 /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

typedef SharedRecAt13E0 ObjRecV4;
typedef SharedRecAt8V2 ObjRecV9;
typedef SharedRecAtC ObjRecV11;
typedef SharedRecV1 ObjRecV10;
typedef SharedRecAt84 ObjRecV12;
typedef SharedRecAt92V1 ObjRecV13;
typedef SharedRecV2 ObjRecV7;
typedef SharedRecAt16E0V1 ObjRecV3;
typedef SharedRecAt92V2 ObjRecV8;

typedef Shared_PlayerListMenuGlobals PlayerListMenuGlobals;
typedef Shared_PlayerMenuGlobals PlayerMenuGlobals;
typedef Shared_FullPlayerMenuGlobals FullPlayerMenuGlobals;

/* Handles player menu commands and updates selection and game mode state. */

s32 Pickup_ApplySpecialPickup(ObjRecV4 *arg0, ObjRecV9 *arg1) {
    f32 temp_f20;
    f32 loopBonus; 
    f32 old_unk11E4;
    f32 temp_alpha; 
    f32 temp_duration; 
    s32 temp_s1;
    s32 temp_s3;
    s16 temp_v1;
    s32 temp_fp; 
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1_3;
    s32 temp_v1_4;
    register s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    u8 **temp_s0_2;
    u8 *var_a2;
    u8 temp_a0;
    void *temp_a1;
    void *temp_a1_10;
    void *temp_a1_11; 
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_a1_5;
    void *temp_a1_6;
    void *temp_a1_7;
    void *temp_a1_8;
    void *temp_a1_9;
    ObjRecV3 *temp_s0;
    ObjRecV3 **loopEntries;
    FullPlayerMenuGlobals *menuGlobals;
    ObjRecV12 *loopMenuData;
    ObjRecV12 *commandMenuData;
    ObjRecV13 *temp_v1_2;

    var_s4 = 0;
    if (arg0->unk5E4 > 0) {
        temp_v1 = arg1->unk4;
        {
            if (temp_v1 < 0x139F) {
                if (temp_v1 < 0x1399) {
                    if (temp_v1 == 0x1389) goto case_1389;
                    if (temp_v1 < 0x138A) {
                        if (temp_v1 == 0xBD7) goto case_BD7;
                        if (temp_v1 < 0xBD8) {
                            if (temp_v1 == 0xBD6) goto case_BD6;
                            goto command_done;
                        }
                        if (temp_v1 == 0xBD8) goto case_BD8;
                        if (temp_v1 == 0x1388) goto mark_handled;
                        goto command_done;
                    }
                    if (temp_v1 < 0x1398) {
                        var_s4 = 1;
                        if (temp_v1 >= 0x138B) goto mark_handled;
                        goto block_126;
                    }
                    goto case_1398;
                }
                var_s4 = 1;
                goto command_done;
            }
            if (temp_v1 < 0x13AB) {
                if (temp_v1 < 0x13A9) {
                    if (temp_v1 == 0x13A0) goto case_13A0;
                    if (temp_v1 < 0x13A0) goto case_139F;
                    if (temp_v1 < 0x13A8) var_s4 = 1;
                    goto command_done;
                }
                goto mark_handled;
            }
            if (temp_v1 == 0x13BC) { var_s4 = 1; goto command_done; }
            if (temp_v1 < 0x13BD) {
                if (temp_v1 == 0x13AD) goto mark_handled;
                goto command_done;
            }
            if (temp_v1 == 0x13BD) goto case_13BD;
            if (temp_v1 == 0x13C1) goto case_13C1;
            goto command_done;
case_BD6:
                temp_v1_2 = arg0->unk5D8;
                temp_a0 = temp_v1_2->unk8F;
                if ((temp_a0 == 1) && ((commandMenuData = &D_80140F84.tail.list.menu)->unk54 != 0)) {
                    temp_v1_2->unk8F = 0U;
                    arg0->unk5D8->unk90 = temp_a0;
                    commandMenuData->unk74 = 2;
                    D_800C91B8_de = func_8025E2C4_de();
                    if (func_8025E2C4_de() != 0) {
                        func_8025E2D4_de(0x3D);
                    }
                    var_s4 = 1;
                }
                goto command_done;
case_BD7:
            {
                ObjRecV12 *listMenuData = &D_80140F84.tail.list.menu;
                listMenuData->unk84 = 0;
                listMenuData->unk80 = 1;
                arg0->unk5D8->unk8F = 1U;
                temp_s0 = D_80140F84.tail.list.players;
                var_s4 = 1;
                if (temp_s0 != 0) {
loop_37:
                    if (temp_s0 != arg0) {
                        temp_a1 = temp_s0->unk5DC;
                        if (temp_a1 != 0) {
                            Camera_PostScreenMessage(&D_80145088, temp_a1, D_800D30AC[MENU_LANGUAGE]);
                        }
                    }
                    temp_s0 = temp_s0->unk16E0;
                    if (temp_s0 != 0) {
                        goto loop_37;
                    }
                }
                goto command_done;
            }
case_BD8:
                old_unk11E4 = arg0->unk11E4;
                arg0->unk1240 = 0.0f;
                temp_f20 = arg0->unk1240;
                var_s4 = 1;
                arg0->unk123C = 0;
                arg0->unk123D = 0;
                arg0->unk123E = 0;
                if (old_unk11E4 != temp_f20) {
                    temp_a1_2 = arg0->unk5DC;
                    arg0->unk11E4 = temp_f20;
                    arg0->unk13E0 = 0;
                    if (temp_a1_2 != 0) {
                        Camera_PostScreenMessage(&D_80145088, temp_a1_2, D_800D31B8[MENU_LANGUAGE]);
                    }
                } else {
                    temp_fp = arg0->unk122C & 0x6000;
                    temp_v0 = 1 << (XPlus_NextRandomInteger() % 13);
                    arg0->unk122C = temp_v0;
                    if (temp_v0 & 0x20) {
                        arg0->unk1238 = -1;
                        arg0->unk1230 = temp_f20;
                    } else {
                        arg0->unk1230 = D_800C6260;
                    }
                    temp_v1_3 = arg0->unk122C;
                    switch (temp_v1_3) {            /* switch 3; irregular */
                    case 0x1:                       /* switch 3 */
                        func_8025E11C_de(0x15E);
                        var_s1 = 0;
                        if (var_s1 < D_80140F84.tail.count) {
                            menuGlobals = &D_80140F84;
                            loopEntries = &menuGlobals->entries;
                            loopMenuData = &menuGlobals->tail.list.menu;
                            loopBonus = D_800C6264;
                            do {
                                temp_s0 = &(*loopEntries)[var_s1];
                                if ((temp_s0 != 0) && (temp_s0 != arg0) && (((loopMenuData->unk24) == 0) || (temp_s0->unk5D8->unk92 != arg0->unk5D8->unk92))) {
                                    temp_s0->unk122C = (s32) (temp_s0->unk122C | 0x2000);
                                    temp_s0->unk11DC = (f32) (temp_s0->unk11DC + loopBonus);
                                }
                                temp_a1_3 = temp_s0->unk5DC;
                                if (temp_a1_3 != 0) {
                                    Camera_PostScreenMessage(&D_80145088, temp_a1_3, D_800D3128[MENU_LANGUAGE]);
                                }
                            } while (++var_s1 < D_80140F84.tail.count);
                        }
                        break;
                    case 0x2:                       /* switch 3 */
                        arg0->unk1230 = D_800CB3F8;
                        func_8025E11C_de(0x164);
                        temp_a1_4 = arg0->unk5DC;
                        if (temp_a1_4 != 0) {
                            Camera_PostScreenMessage(&D_80145088, temp_a1_4, D_800D312C[MENU_LANGUAGE]);
                        }
                        temp_alpha = D_800C626C;
                        temp_duration = arg0->unk1230;
                        arg0->unk123C = 0xFF;
                        goto block_115;
                    case 0x4:                       /* switch 3 */
                        arg0->unk1230 = D_800C6270_de;
                        func_8025E11C_de(0x15F);
                        temp_a1_11 = arg0->unk5DC;
                        if (temp_a1_11 != 0) {
                            var_a2 = D_800D3130[MENU_LANGUAGE];
block_119:
                            Camera_PostScreenMessage(&D_80145088, temp_a1_11, var_a2);
                        }
                        break;
                    case 0x8:                       /* switch 3 */
                        arg0->unk1230 = D_800C6274_de;
                        func_8025E11C_de(0x165);
                        temp_a1_5 = arg0->unk5DC;
                        if (temp_a1_5 != 0) {
                            Camera_PostScreenMessage(&D_80145088, temp_a1_5, D_800D3134[MENU_LANGUAGE]);
                        }
                        temp_alpha = D_800C6278_de;
                        temp_duration = arg0->unk1230;
                        arg0->unk123C = 0xFF;
block_114:
                        arg0->unk123D = 0xFF;
                        goto block_115;
                    case 0x10:                      /* switch 3 */
                        arg0->unk1230 = D_800C627C_de;
                        func_8025E11C_de(0x160);
                        temp_a1_6 = arg0->unk5DC;
                        if (temp_a1_6 != 0) {
                            Camera_PostScreenMessage(&D_80145088, temp_a1_6, D_800D3138[MENU_LANGUAGE]);
                        }
                        temp_alpha = D_800CB410;
                        temp_duration = arg0->unk1230;
                        arg0->unk123C = 0xFF;
                        arg0->unk123E = 0xFF;
                        goto block_115;
                    case 0x20:                      /* switch 3 */
                        arg0->unk1230 = D_800CB414;
                        func_8025E11C_de(0x166);
                        temp_a1_11 = arg0->unk5DC;
                        if (temp_a1_11 != 0) {
                            var_a2 = D_800D313C[MENU_LANGUAGE];
                            goto block_119;
                        }
                        break;
                    case 0x40:                      /* switch 3 */
                        arg0->unk1230 = D_800C6288_de;
                        func_8025E11C_de(0x161);
                        temp_a1_11 = arg0->unk5DC;
                        if (temp_a1_11 != 0) {
                            var_a2 = D_800D3140_de[MENU_LANGUAGE];
                            goto block_119;
                        }
                        break;
                    case 0x80:                      /* switch 3 */
                        arg0->unk1230 = D_800C628C_de;
                        func_8025E11C_de(0x169);
                        temp_a1_11 = arg0->unk5DC;
                        if (temp_a1_11 != 0) {
                            var_a2 = D_800D3144[MENU_LANGUAGE];
                            goto block_119;
                        }
                        break;
                    case 0x100:                     /* switch 3 */
                        arg0->unk1230 = D_800C6290_de;
                        func_8025E11C_de(0x162);
                        temp_a1_11 = arg0->unk5DC;
                        if (temp_a1_11 != 0) {
                            var_a2 = D_800D3148[MENU_LANGUAGE];
                            goto block_119;
                        }
                        break;
                    case 0x200:                     /* switch 3 */
                        arg0->unk1230 = D_800C6294_de;
                        func_8025E11C_de(0x16A);
                        temp_a1_7 = arg0->unk5DC;
                        if (temp_a1_7 != 0) {
                            Camera_PostScreenMessage(&D_80145088, temp_a1_7, D_800D3150[MENU_LANGUAGE]);
                        }
                        temp_alpha = D_800C6298;
                        temp_duration = arg0->unk1230;
                        arg0->unk1240 = temp_alpha;
                        goto block_116;
                    case 0x400:                     /* switch 3 */
                        arg0->unk1230 = D_800C629C;
                        func_8025E11C_de(0x163);
                        temp_a1_8 = arg0->unk5DC;
                        if (temp_a1_8 != 0) {
                            Camera_PostScreenMessage(&D_80145088, temp_a1_8, D_800D3154[MENU_LANGUAGE]);
                        }
                        temp_alpha = D_800C62A0;
                        temp_duration = arg0->unk1230;
                        arg0->unk123C = 0xFF;
                        arg0->unk123D = 0xFF;
                        arg0->unk123E = 0xFF;
                        goto block_115;
                    case 0x800:                     /* switch 3 */
                        arg0->unk1230 = D_800C62A4;
                        func_8025E11C_de(0x168);
                        temp_a1_9 = arg0->unk5DC;
                        if (temp_a1_9 != 0) {
                            Camera_PostScreenMessage(&D_80145088, temp_a1_9, D_800D3158[MENU_LANGUAGE]);
                        }
                        temp_alpha = D_800C62A8;
                        temp_duration = arg0->unk1230;
                        arg0->unk123E = 0xFF;
                        goto block_115;
                    case 0x1000:                    /* switch 3 */
                        arg0->unk1230 = D_800C62AC;
                        func_8025E11C_de(0x15F);
                        temp_a1_10 = arg0->unk5DC;
                        if (temp_a1_10 != 0) {
                            Camera_PostScreenMessage(&D_80145088, temp_a1_10, D_800D315C[MENU_LANGUAGE]);
                        }
                        temp_alpha = D_800C62B0;
                        temp_duration = arg0->unk1230;
                        arg0->unk123D = 0xFF;
                        goto block_115;
                    default:                        /* switch 3 */
                        goto block_default;
                    }
                    goto block_after_alpha;
block_115:
                    arg0->unk1240 = temp_alpha;
block_116:
                    arg0->rightAxisValue = (f32) (temp_alpha / temp_duration);
                    goto block_after_alpha;
block_default:
                    temp_a1_11 = arg0->unk5DC;
                    if (temp_a1_11 != 0) {
                        Camera_PostScreenMessage(&D_80145088, temp_a1_11, D_800D3160[MENU_LANGUAGE]);
                    }
block_after_alpha:
                    arg0->unk122C = (s32) (arg0->unk122C | temp_fp);
                }
                goto command_done;
case_1398:
                temp_v0_2 = arg0->unk5D4 * 0x190;
                var_s4 = 1;
                D_80102B14[arg0->unk5D4].value += 0xA;
                arg0->unk5F8 = (u16) (arg0->unk5F8 + 0xA);
                Menu_RequestTrackByKey(0x1F5);
                goto command_done;
case_13A0:
            temp_v0_4 = arg0->unk5D4 * 0x190;
            var_s4 = 1;
            D_800FEB15[arg0->unk5D4].value += 0x32;
            arg0->unk5F4 = (u16) (arg0->unk5F4 + 0x32);
            Menu_RequestTrackByKey(0x1F7);
            goto command_done;
case_139F:
            var_s4 = 1;
            temp_v0_3 = arg0->unk5D4 * 0x190;
            D_800FEB16[arg0->unk5D4].value += 0x32;
            arg0->unk5F6 = (u16) (arg0->unk5F6 + 0x32);
            Menu_RequestTrackByKey(0x1F6);
            goto command_done;
case_13C1:
            var_s4 = 1;
            temp_v0_5 = arg0->unk5D4 * 0x190;
            D_800FEB10[arg0->unk5D4].value += 0x500;
            arg0->unk5E4 = (s32) (arg0->unk5E4 + 0x500);
            Menu_RequestTrackByKey(0x1F8);
            goto command_done;
case_1389:
                Player_IncrementLevelProgress(&D_80102B00[arg0->unk5D4], (s32) arg0->unk18->unkC);
block_126:
                var_s4 = 1;
                Player_IncrementLevelProgress(&D_80102B00[arg0->unk5D4], (s32) arg0->unk18->unkC);
                Menu_RequestTrackByKey(0x1F4);
                goto command_done;
case_13BD:
            temp_v1_4 = arg0->unk5D4 * 0x190;
            var_s4 = 1;
            D_800FEB17[arg0->unk5D4].value += 1;
            goto command_done;
mark_handled:
            var_s4 = 1;
            goto command_done;
        }
command_done:
        ;
    }
    if (var_s4 != 0) {
        temp_s0_2 = arg1->unk0;
        temp_s1 = arg1->unk6;
        temp_s3 = arg1->unk8;
        if (arg0->unk5DC != 0) {
            Sky_StartFade(arg0->unk5DC, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (temp_s0_2 != 0) {
                Camera_PostScreenMessage(&D_80145088, arg0->unk5DC, *temp_s0_2);
            }
        }
        if (temp_s1 != 0) {
            SoundElement_PlaySoundAtPosition(temp_s1, arg0->position, 0, -1);
        }
        if (temp_s3 != 0) {
            func_8025E11C_de((s32) temp_s3);
        }
    }
    return var_s4;
}
#endif

/* A D_800D31D0 powerup row (0x18 bytes, three rows): the item entry head shared with the other item tables,
   the action slot the powerup fills, the ammunition it grants and its pickup handler. */
typedef struct PowerupEntry {
    u8 **text; /* 0x0: pickup message, one per language */
    s16 id; /* 0x4: item id looked up by Pickup_DispatchHandler */
    s16 sound; /* 0x6 */
    s16 event; /* 0x8 */
    s16 reservedA; /* 0xA */
    s16 slot; /* 0xC: row in Player.actions */
    s16 ammoSlot; /* 0xE: Player.ammo index for func_80222BE8_de */
    s16 ammoCount; /* 0x10 */
    s32 (*handle)(struct Player *player, struct PowerupEntry *entry); /* 0x14 */
} PowerupEntry;
/* Team ids that may always pick up items (Pickup_CanCollect reads the same pair). */
extern s32 D_800CE474[2];
extern void Player_AddAmmo(void *, s16, s16);
/* Pickup feedback: flash the player's view, post the entry's message in the current language,
   play its sound at the player and raise its event. */
static inline void announcePowerup(struct Player *player, PowerupEntry *entry)
{
    u8 **text = entry->text;
    s32 sound = entry->sound;
    s32 event = entry->event;
    if (player->camera) {
        Sky_StartFade(player->camera, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (text) Camera_PostScreenMessage(&D_80145088, player->camera, text[MENU_LANGUAGE]);
    }
    if (sound) SoundElement_PlaySoundAtPosition(sound, player->pos, 0, -1);
    if (event) func_8025E11C_de(event);
}
/* Powerup pickup handler (D_800D31D0 rows). A powerup the player already holds, or any pickup in a tag match by a
   player not on one of the D_800CE474 teams, only gives the pickup feedback. Otherwise the powerup takes weapon key
   3 or 7, whichever no action slot uses yet (none free: refused, returns 0); outside tag matches it becomes the
   pending weapon. Then the feedback plays and the entry's ammunition is added. Returns 1 when taken. */
s32 Pickup_HandlePowerWeaponPickup(struct Player *player, PowerupEntry *entry)
{
    s32 key3Free = 1, key7Free = 1, i;
    s32 skipAmmo = 0;
    if (player->actions[entry->slot][1] != -1 &&
        (!player->profile->bonus || !D_80145088.modes.tag || player->objectId == D_800CE474[0] ||
         player->objectId == D_800CE474[1])) {
        announcePowerup(player, entry);
    } else {
        for (i = 0; i < 22; i++) {
            if (player->actions[i][1] == 3) key3Free = 0;
            else if (player->actions[i][1] == 7) key7Free = 0;
        }
        player->actions[entry->slot][0] = 1;
        if (key3Free || key7Free) {
            if (!player->profile->bonus || !D_80145088.modes.tag) {
                player->pendingWeapon = key3Free ? 3 : 7;
                player->actions[entry->slot][1] = key3Free ? 3 : 7;
            }
        } else {
            return 0;
        }
        announcePowerup(player, entry);
        if (!skipAmmo) Player_AddAmmo(player, entry->ammoSlot, entry->ammoCount);
    }
    return 1;
}

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Pickup effect handler: applies the pickup's effect id (0x708..0x70F) to the player (two float settings, an accumulated float
   or a sound/effect spawn through ItemMenu_SetEntry) then shows the pickup text in the current language, plays its sound and
   raises its event. Returns one. */
extern f32 rodata_func_802ACB58_eu_800C6578, D_auto_800C657C;
extern char D_002AD44C_eu[], D_002AD4FC_eu[];
extern void ItemMenu_SetEntry();
s32 Pickup_ApplyEuropeanExtendedPowerup(struct Player *player, PowerupEntry *pickup, void *obj) {
    u8 **text = pickup->text;
    s16 sound = pickup->sound;
    s16 event = pickup->event;
    f32 *data = (f32 *)(*(u8 **)((u8 *)obj + 0x18) + 0x14);

    switch ((s16)(pickup->id - 0x708)) {
    case 0: *(f32 *)((u8 *)player + 0x670) = rodata_func_802ACB58_eu_800C6578; break;
    case 1: *(f32 *)((u8 *)player + 0x674) = D_auto_800C657C; break;
    case 2: *(f32 *)((u8 *)player + 0x678) += data[3]; break;
    case 3: ItemMenu_SetEntry((u8 *)player + 0xD40, 1, 0, 0x7FD, 0, 0, 0, D_002AD44C_eu, D_002AD4FC_eu); break;
    }
    if (*(void **)((u8 *)player + 0x5DC) != 0) {
        Sky_StartFade(player->camera, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (text) Camera_PostScreenMessage(&D_80145088, player->camera, ((char **)text)[g_languageIndex]);
    }
    if (sound) SoundElement_PlaySoundAtPosition(sound, player->pos, 0, -1);
    if (event) func_8025E11C_de(event);
    return 1;
}
#else
INCLUDE_ASM("span_1000", Pickup_ApplyEuropeanExtendedPowerup);
#endif
#endif

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Pickup effect handler: applies the pickup's effect id (0x708..0x70F) to the player (two float settings, an accumulated float
   or a sound/effect spawn through ItemMenu_SetEntry) then shows the pickup text in the current language, plays its sound and
   raises its event. Returns one. */
extern f32 rodata_func_802ACB58_eu_800C6578, D_auto_800C657C;
extern char D_002AD44C_eu[], D_002AD4FC_eu[];
extern void ItemMenu_SetEntry();
s32 Pickup_ApplyEuropeanPowerup(struct Player *player, PowerupEntry *pickup, void *obj) {
    u8 **text = pickup->text;
    s16 sound = pickup->sound;
    s16 event = pickup->event;
    f32 *data = (f32 *)(*(u8 **)((u8 *)obj + 0x18) + 0x14);

    switch ((s16)(pickup->id - 0x708)) {
    case 0: *(f32 *)((u8 *)player + 0x670) = rodata_func_802ACB58_eu_800C6578; break;
    case 1: *(f32 *)((u8 *)player + 0x674) = D_auto_800C657C; break;
    case 2: *(f32 *)((u8 *)player + 0x678) += data[3]; break;
    case 3: ItemMenu_SetEntry((u8 *)player + 0xD40, 1, 0, 0x7FD, 0, 0, 0, D_002AD44C_eu, D_002AD4FC_eu); break;
    }
    if (*(void **)((u8 *)player + 0x5DC) != 0) {
        Sky_StartFade(player->camera, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (text) Camera_PostScreenMessage(&D_80145088, player->camera, ((char **)text)[g_languageIndex]);
    }
    if (sound) SoundElement_PlaySoundAtPosition(sound, player->pos, 0, -1);
    if (event) func_8025E11C_de(event);
    return 1;
}
#else
INCLUDE_ASM("span_1000", Pickup_ApplyEuropeanPowerup);
#endif
#endif
