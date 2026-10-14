#include "span_1000/code_80233920.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "types.h"
#include "span_1000/menu_ABBDC_versions.h"

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



typedef struct Shared_PlayerMenuData Shared_PlayerMenuData;
struct Shared_PlayerMenuData {
    u8 pad0[16]; /* +0x0: src/func_802ACBCC.c */
    s32 amount; /* +0x10: src/func_802ACBCC.c */
    s8 bonus14; /* +0x14: src/func_802ACBCC.c */
    s8 bonus15; /* +0x15: src/func_802ACBCC.c */
    s8 bonus16; /* +0x16: src/func_802ACBCC.c */
    s8 bonus17; /* +0x17: src/func_802ACBCC.c */
    u8 pad18[376]; /* +0x18: src/func_802ACBCC.c */
};



typedef struct Shared_MenuBonusColumn Shared_MenuBonusColumn;
struct Shared_MenuBonusColumn {
    u8 value; /* +0x0: src/func_802ACBCC.c */
    u8 rest[399]; /* +0x1: src/func_802ACBCC.c */
};



typedef struct Shared_MenuAmountColumn Shared_MenuAmountColumn;
struct Shared_MenuAmountColumn {
    s32 value; /* +0x0: src/func_802ACBCC.c */
    u8 rest[396]; /* +0x4: src/func_802ACBCC.c */
};



typedef struct SharedRecAt13E0 SharedRecAt13E0;
struct SharedRecAt13E0 {
    char pad0[0x8];
    Vec3 position; /* +0x8: passed by value to func_8025DE54_de */
    char pad14[0x4];
    struct SharedRecAtC * unk18; /* +0x18: src/func_802ACBCC.c */
    char pad1C[0x5B8];
    s32 unk5D4; /* +0x5D4: src/func_802ACBCC.c */
    struct SharedRecAt92V1 * unk5D8; /* +0x5D8: src/func_802ACBCC.c */
    void * unk5DC; /* +0x5DC: src/func_802ACBCC.c */
    char pad5E0[0x4];
    s32 unk5E4; /* +0x5E4: src/func_802ACBCC.c */
    char pad5E8[0xC];
    u16 unk5F4; /* +0x5F4: src/func_802ACBCC.c */
    u16 unk5F6; /* +0x5F6: src/func_802ACBCC.c */
    u16 unk5F8; /* +0x5F8: src/func_802ACBCC.c */
    char pad5FA[0xBEA];
    f32 unk11E4; /* +0x11E4: src/func_802ACBCC.c */
    char pad11E8[0x44];
    s32 unk122C; /* +0x122C: src/func_802ACBCC.c */
    f32 unk1230; /* +0x1230: src/func_802ACBCC.c */
    char pad1234[0x4];
    s32 unk1238; /* +0x1238: src/func_802ACBCC.c */
    u8 unk123C; /* +0x123C: src/func_802ACBCC.c */
    u8 unk123D; /* +0x123D: src/func_802ACBCC.c */
    u8 unk123E; /* +0x123E: src/func_802ACBCC.c */
    char pad123F[0x1];
    f32 unk1240; /* +0x1240: src/func_802ACBCC.c */
    f32 unk1244; /* +0x1244: src/func_802ACBCC.c */
    char pad1248[0x198];
    s32 unk13E0; /* +0x13E0: src/func_802ACBCC.c */
};



typedef struct SharedRecAt8V2 SharedRecAt8V2;
struct SharedRecAt8V2 {
    u8 ** unk0; /* +0x0: src/func_802ACBCC.c */
    s16 unk4; /* +0x4: src/func_802ACBCC.c */
    s16 unk6; /* +0x6: src/func_802ACBCC.c */
    s16 unk8; /* +0x8: src/func_802ACBCC.c */
    char padA[0x2];
};



typedef struct SharedRecAtC SharedRecAtC;
struct SharedRecAtC {
    char pad0[0xC];
    s16 unkC; /* +0xC: src/func_802ACBCC.c */
};



typedef struct SharedRecV1 SharedRecV1;
struct SharedRecV1 {
    char pad0[0x8F];
    u8 unk8F; /* +0x8F: src/func_802ACBCC.c */
};



typedef struct SharedRecAt84 SharedRecAt84;
struct SharedRecAt84 {
    char pad0[0x24];
    s32 unk24; /* +0x24: src/func_802ACBCC.c */
    char pad28[0x2C];
    s32 unk54; /* +0x54: src/func_802ACBCC.c */
    char pad58[0x1C];
    s32 unk74; /* +0x74: src/func_802ACBCC.c */
    char pad78[0x8];
    s32 unk80; /* +0x80: src/func_802ACBCC.c */
    s32 unk84; /* +0x84: src/func_802ACBCC.c */
};



typedef struct SharedRecAt92V1 SharedRecAt92V1;
struct SharedRecAt92V1 {
    char pad0[0x8F];
    u8 unk8F; /* +0x8F: src/func_802ACBCC.c */
    u8 unk90; /* +0x90: src/func_802ACBCC.c */
    char pad91[0x1];
    u8 unk92; /* +0x92: src/func_802ACBCC.c */
};



typedef struct SharedRecV2 SharedRecV2;
struct SharedRecV2 {
    char pad0[0x5DC];
    void * unk5DC; /* +0x5DC: src/func_802ACBCC.c */
    char pad5E0[0x1100];
    void * unk16E0; /* +0x16E0: src/func_802ACBCC.c */
};



typedef struct SharedRecAt16E0V1 SharedRecAt16E0V1;
struct SharedRecAt16E0V1 {
    char pad0[0x5D8];
    struct SharedRecAt92V2 * unk5D8; /* +0x5D8: src/func_802ACBCC.c */
    void * unk5DC; /* +0x5DC: src/func_802ACBCC.c */
    char pad5E0[0xBFC];
    f32 unk11DC; /* +0x11DC: src/func_802ACBCC.c */
    char pad11E0[0x4C];
    s32 unk122C; /* +0x122C: src/func_802ACBCC.c */
    char pad1230[0x4B0];
    struct SharedRecAt16E0V1 * unk16E0; /* +0x16E0: src/func_802ACBCC.c */
    char pad16E4[0x4];
};



typedef struct SharedRecAt92V2 SharedRecAt92V2;
struct SharedRecAt92V2 {
    char pad0[0x92];
    u8 unk92; /* +0x92: src/func_802ACBCC.c */
};



typedef struct Shared_PlayerListMenuGlobals Shared_PlayerListMenuGlobals;
struct Shared_PlayerListMenuGlobals {
    void * players; /* +0x0: src/func_802ACBCC.c */
    u8 padToMenu[6204]; /* +0x4: src/func_802ACBCC.c */
    SharedRecAt84 menu; /* +0x1840: src/func_802ACBCC.c */
};



typedef struct Shared_PlayerMenuGlobals Shared_PlayerMenuGlobals;
struct Shared_PlayerMenuGlobals {
    s32 count; /* +0x0: src/func_802ACBCC.c */
    u8 padToPlayers[20]; /* +0x4: src/func_802ACBCC.c */
    Shared_PlayerListMenuGlobals list; /* +0x18: src/func_802ACBCC.c */
};



typedef struct Shared_FullPlayerMenuGlobals Shared_FullPlayerMenuGlobals;
struct Shared_FullPlayerMenuGlobals {
    struct SharedRecAt16E0V1 * entries; /* +0x0: src/func_802ACBCC.c */
    Shared_PlayerMenuGlobals tail; /* +0x4: src/func_802ACBCC.c */
};

/* The values func_802ACBCC loads by address:
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
void func_8022F3F8_de(void *, int);
void * func_80237E80_de(void *, void *, u8 *);

int func_8025E2C4_de(void);

s32 func_802A01E8_de(void);
s32 func_804030E0_de(s32);
s32 func_8025DE54_de(s16, Vec3, s32, s32);
typedef Shared_PlayerMenuData PlayerMenuData;
extern PlayerMenuData D_80102B00[];
typedef Shared_MenuBonusColumn MenuBonusColumn;

extern MenuBonusColumn D_800FEB15[];
extern MenuBonusColumn D_800FEB16[];
extern MenuBonusColumn D_800FEB17[];
typedef Shared_MenuAmountColumn MenuAmountColumn;
extern MenuAmountColumn D_800FEB10[];
extern MenuBonusColumn D_80102B14[];
extern Shared_FullPlayerMenuGlobals D_80140F84;

#include "shared/menu_match_globals.h"

extern s32 D_800C91B8_de;
extern f32 D_800C6260;

extern f32 D_800CB3F8;

extern f32 D_800C6270_de;
extern f32 D_800C6274_de;

extern f32 D_800C627C_de;
extern f32 D_800CB410;
extern f32 D_800CB414;
extern f32 D_800C6288_de;
extern f32 D_800C628C_de;
extern f32 D_800C6290_de;
extern f32 D_800C6294_de;
extern f32 D_800C6298;
extern f32 D_800C629C;

extern f32 D_800C62A4;

extern f32 D_800C62AC;

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

s32 func_802ACBCC(ObjRecV4 *arg0, ObjRecV9 *arg1) {
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
                            func_80237E80_de(&D_80145088, temp_a1, D_800D30AC[MENU_LANGUAGE]);
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
                        func_80237E80_de(&D_80145088, temp_a1_2, D_800D31B8[MENU_LANGUAGE]);
                    }
                } else {
                    temp_fp = arg0->unk122C & 0x6000;
                    temp_v0 = 1 << (func_802A01E8_de() % 13);
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
                                    func_80237E80_de(&D_80145088, temp_a1_3, D_800D3128[MENU_LANGUAGE]);
                                }
                            } while (++var_s1 < D_80140F84.tail.count);
                        }
                        break;
                    case 0x2:                       /* switch 3 */
                        arg0->unk1230 = D_800CB3F8;
                        func_8025E11C_de(0x164);
                        temp_a1_4 = arg0->unk5DC;
                        if (temp_a1_4 != 0) {
                            func_80237E80_de(&D_80145088, temp_a1_4, D_800D312C[MENU_LANGUAGE]);
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
                            func_80237E80_de(&D_80145088, temp_a1_11, var_a2);
                        }
                        break;
                    case 0x8:                       /* switch 3 */
                        arg0->unk1230 = D_800C6274_de;
                        func_8025E11C_de(0x165);
                        temp_a1_5 = arg0->unk5DC;
                        if (temp_a1_5 != 0) {
                            func_80237E80_de(&D_80145088, temp_a1_5, D_800D3134[MENU_LANGUAGE]);
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
                            func_80237E80_de(&D_80145088, temp_a1_6, D_800D3138[MENU_LANGUAGE]);
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
                            func_80237E80_de(&D_80145088, temp_a1_7, D_800D3150[MENU_LANGUAGE]);
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
                            func_80237E80_de(&D_80145088, temp_a1_8, D_800D3154[MENU_LANGUAGE]);
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
                            func_80237E80_de(&D_80145088, temp_a1_9, D_800D3158[MENU_LANGUAGE]);
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
                            func_80237E80_de(&D_80145088, temp_a1_10, D_800D315C[MENU_LANGUAGE]);
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
                    arg0->unk1244 = (f32) (temp_alpha / temp_duration);
                    goto block_after_alpha;
block_default:
                    temp_a1_11 = arg0->unk5DC;
                    if (temp_a1_11 != 0) {
                        func_80237E80_de(&D_80145088, temp_a1_11, D_800D3160[MENU_LANGUAGE]);
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
                func_804030E0_de(0x1F5);
                goto command_done;
case_13A0:
            temp_v0_4 = arg0->unk5D4 * 0x190;
            var_s4 = 1;
            D_800FEB15[arg0->unk5D4].value += 0x32;
            arg0->unk5F4 = (u16) (arg0->unk5F4 + 0x32);
            func_804030E0_de(0x1F7);
            goto command_done;
case_139F:
            var_s4 = 1;
            temp_v0_3 = arg0->unk5D4 * 0x190;
            D_800FEB16[arg0->unk5D4].value += 0x32;
            arg0->unk5F6 = (u16) (arg0->unk5F6 + 0x32);
            func_804030E0_de(0x1F6);
            goto command_done;
case_13C1:
            var_s4 = 1;
            temp_v0_5 = arg0->unk5D4 * 0x190;
            D_800FEB10[arg0->unk5D4].value += 0x500;
            arg0->unk5E4 = (s32) (arg0->unk5E4 + 0x500);
            func_804030E0_de(0x1F8);
            goto command_done;
case_1389:
                func_8022F3F8_de(&D_80102B00[arg0->unk5D4], (s32) arg0->unk18->unkC);
block_126:
                var_s4 = 1;
                func_8022F3F8_de(&D_80102B00[arg0->unk5D4], (s32) arg0->unk18->unkC);
                func_804030E0_de(0x1F4);
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
            func_802391AC_de(arg0->unk5DC, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (temp_s0_2 != 0) {
                func_80237E80_de(&D_80145088, arg0->unk5DC, *temp_s0_2);
            }
        }
        if (temp_s1 != 0) {
            func_8025DE54_de(temp_s1, arg0->position, 0, -1);
        }
        if (temp_s3 != 0) {
            func_8025E11C_de((s32) temp_s3);
        }
    }
    return var_s4;
}
