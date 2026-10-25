#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_10.H"
#include "COMMON/WORLD.H"
#include "SCENE/SCENEACTORSTRIDE.H"
#include "SCENE/SCENEGLOBAL.H"
#include "SCENE/SCENEFONTRESOURCES.H"
#include "SCENE/SCENEACTORRESOURCES.H"
#include "SCENE/SCENERESOURCES.H"
#include "SCENE/SCENEPRIMARYACTORS.H"
#include "SCENE/SCENEACTORPREFIX.H"
#include "SCENE/SCENEACTORKIND.H"
#include "SCENE/SCENEACTORTABLES.H"
#include "COMMON/SHAREDRECAT1B92C.H"
#include "SCENE/SHARED_S2.H"
#include "SCENE/SHAREDRECAT91.H"
#include "SCENE/SHAREDRECAT98.H"
#include "SCENE/SHAREDRECAT94.H"
#include "SCENE/SHARED_S6.H"
#include "SCENE/SHAREDRECAT14.H"
#include "SCENE/SHAREDRECAT10V2.H"
#include "SCENE/SHARED_S9.H"
#include "SCENE/SHARED_S10.H"
#include "SCENE/SHARED_S11.H"
#include "SCENE/SHAREDRECAT8V1.H"
#include "SCENE/SHAREDRECAT1B664V2.H"
#include "SCENE/SHARED_S14.H"
#include "SCENE/SHAREDRECAT1B664V1.H"
#include "SCENE/SHAREDRECATE4V1.H"
#include "SCENE/SHAREDRECAT28V1.H"
#include "SCENE/SHAREDRECATE4V2.H"
#include "SCENE/SHAREDRECAT28V2.H"
#include "SCENE/SHAREDRECAT16E0V3.H"
#include "SCENE/SHARED_S21.H"
#include "COMMON/OUTPUT.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/INTEGERSTATE2C.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "AI/NAV/80208000_6.H"
#include "AI/NAV/80208000_8.H"
#include "OVLGAME/8044E2B8.H"
#include "SCHED/8023A284_29.H"
extern void Scene_ReleaseResource(void *arg0, void *arg1);

/* Unknown data types are explicit unresolved contracts, never guessed s32. */

extern void World_ResetPlayerState();
extern void Nav_AssignPlatformEndpoints();
extern s32 func_8020CB3C_de();
extern void * Weapons_GetPlayerByIndex();
extern void func_80236874_de();
extern int Camera_IsSequenceActive();
extern void func_80246E44_de();
extern void func_8024B2D0_de();
extern void func_8024BE3C_de();
extern struct Shape_typemap_165 * Scene_AllocateResource();
extern void func_80253908_de();
extern s32 func_80254284_de();
extern void **func_80254408_de(s32 arg0, void *handle, s32 arg2, s32 tempv0, void *world, void *arg5, void *arg6);
extern void func_8025476C_de();
extern s32 func_80255228_de();
extern void func_8025C8D8_de();
extern void func_80286950_de();
extern void Scene_ShowResultsGoal();
extern s32 func_8028B25C_de();
extern void func_8028D380_de();
extern void func_8028D64C_de();
extern void func_8028D888_de();
extern void func_8028D90C_de();
extern void func_8028DA74_de();
extern int Render_GetDirectoryEntry();
extern s32 func_802A01E8_de();
extern s32 func_802AA730_de();
extern void func_802AA760_de();
extern void func_804037E8_de();
extern void func_80449E18_de();
extern void Items_InitGroupPools();
extern void func_8044ADF0_de();
extern void func_8044B0E0_de();
extern void Items_InitEntryBatch();
extern void Items_InitSlotPool();
extern void Items_LoadSceneLight();
extern void Items_FreeSceneResources();
extern void Items_UpdatePendingObjects();
extern void func_8044D668_de();
extern void Ovlgame_InitEffectPool();
extern void func_8044DF60_de();
extern void Ovlgame_StartPanelMovers(void *panel);


extern unsigned char D_00285160[];
extern unsigned char D_0044C108[];
extern unsigned char D_0044C3D4[];
extern unsigned char D_0044C7B8[];
extern unsigned char D_0044DA54[];
extern unsigned char D_80106248[];
extern unsigned char D_8011AFC0[];





extern struct Shared_SceneResources D_801376F8;
extern unsigned char D_801468A0[];






extern unsigned char D_800C5104_de[];                          /* unable to generate initializer: unknown type; const */

                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C511C_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5128_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5134_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5148_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5154_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5160_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5168_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5174_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5180_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5190_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C51A0_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C51B4_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C51C0_de[];                          /* unable to generate initializer: unknown type; const */
extern s32 D_800CC380;                          /* const */
extern s32 D_800CD730;                          /* const */

       /* const */
extern struct Shared_SceneActorTables D_800F3CD0; /* const */






















/* const */

/* Initializes scene resources, actors, and game mode state. */
void func_80286AA8_de(void *table, s32 target, s32 arg2) {
    s32 *temp_a0;
    struct Shape_typemap_165 *temp_v0_4;
    s32 temp_s4; 
    s32 temp_s4_2;
    s32 temp_v0;
    s32 resource_count; 
    s32 temp_v0_16;
    s32 temp_v0_20;
    s32 temp_v0_21;
    s32 resourceKey;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 i;
    s32 j;
    s32 count;
    s32 kind_actor; 
    s32 kind_654;
    s32 kind_653;
    s32 kind_655;
    s32 second_type3; 
    s32 second_type10;
    s32 second_kind_bd6;
    s32 second_kind_64e;
    s32 header_copy0; 
    s32 header_copy1;
    s32 header_copy2;
    s32 header_copy3;
    s32 header_copy4;
    s32 header_copy5;
    Record *record;
    s32 loop_buffer; 
    s32 var_s0_4;
    s32 var_s1_3;
    s32 k;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_4;
    s32 var_s5;
    s32 var_s6;
    s32 kind_656; 
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v1;
    s32 actor_kind_bd7; 
    s32 first_actor_kind; 
    s32 actor_type3; 
    s32 var_v1_2;
    s32 kind;
    u8 temp_v0_3;
    void **temp_v0_10;
    void **temp_v0_11;
    void **temp_v0_12;
    void **temp_v0_14;
    void **temp_v0_17;
    void **temp_v0_19;
    void **temp_v0_6;
    void **temp_v0_7;
    void *temp_a2;
    void *temp_s0;
    void *temp_s0_2;
    void *group;
    struct func_80203E78_S1 *temp_v0_13;
    struct func_80203E78_S1 *temp_v0_15;
    struct func_80203E78_S1 *temp_v0_18;
    struct Shared_SceneActorKind *var_s2_3;
    void *temp_v0_2;
    struct Shared_func_80286A78_S2 *scene_actor_ptr;
    void *temp_v1;
    struct SharedRecAt14 *temp_v1_5;
    void *temp_v1_6;
    struct SharedRecAt28V1 *temp_v1_7;
    struct SharedRecAt28V2 *temp_v1_9;
    void *var_a0;
    void *var_a1;
    struct Shared_SceneActorKind *var_a1_2;
    void *var_a2_2;
    void *var_s0_5;
    struct Shared_func_80286A78_S2 *var_s1_4; 
    void *var_v0;

    var_s6 = target;
    (((struct SharedRecAt1B92C *)(table))->unk1B2FC) = D_800C51D4;
    var_s5 = arg2;
    if ((((struct SharedRecAt1B92C *)(table))->unk1B40C) != -1) {
        func_8044D794_de(table);
    }
    (((struct SharedRecAt1B92C *)(table))->unk1B6AC) = 0;
    if ((Camera_IsSequenceActive() == 0) && (var_s5 != 0) && ((((struct SharedRecAt1B92C *)(table))->unk1B41C) != 0) && (D_801462C8.counters.transitionActive == 0)) {
        func_8028D90C_de();
        temp_v0 = (((struct SharedRecAt1B92C *)(table))->unk1B434);
        if ((u32) (temp_v0 - 0xBC2) < 0x15FU) {
            func_804037E8_de(((temp_v0 - 0xBC2) / 10) + 0x259);
        }
        Scene_ShowResultsGoal();
    }
    func_8028D888_de(table);
    (((struct SharedRecAt1B92C *)(table))->unk0) = 0;
    func_80255228_de(&D_80106248);
    func_8028DA74_de(table);
    func_80253908_de(0);
    if ((((struct SharedRecAt1B92C *)(table))->unk1B40C) != -1) {
        Items_FreeSceneResources(table);
    }
    func_80253908_de(0);
    D_800CD730 = 0;
    func_8025476C_de(8);
    func_8028D64C_de(table);
    Items_InitSlotPool(&((struct SharedRecAt1B92C *)table)->address1B08, *(((struct SharedRecAt1B92C *)(table))->unkB4));
    var_s2 = 0;
    Ovlgame_InitEffectPool(&((struct SharedRecAt1B92C *)table)->address11778);
    func_8044ADF0_de(&((struct SharedRecAt1B92C *)table)->address15388);
    func_8044DF60_de(&D_801376F8.actors);
    func_8023EE00_de();
    func_8044B0E0_de(&((struct SharedRecAt1B92C *)table)->address1B320);
    func_8025C8D8_de(&D_8011F260, &D_8011AFC0, 0xF);
    Ovlgame_StartPanelMovers(&D_801376F8);
    do {
        var_s1_4 = Weapons_GetPlayerByIndex(&D_80145040, var_s2);
        if (var_s1_4 != 0) {
            temp_v1 = var_s1_4->unk5D8;
            if ((((struct SharedRecAt91 *)temp_v1)->unk78 == 1) && (((struct SharedRecAt91 *)temp_v1)->unk91 == 1)) {
                World_ResetPlayerState(var_s1_4->unk1454);
            }
            if ((((struct SharedRecAt98 *)(&D_801468A0))->unk98) != 0) {
                temp_a2 = var_s1_4->unk5D8;
                temp_v0_3 = (((struct SharedRecAt94 *)(temp_a2))->unk94);
                if (temp_v0_3 != 0) {
                    if (temp_v0_3 == 1) {
                        func_802AA730_de(&D_801376F8, var_s1_4, &((struct SharedRecAt94 *)temp_a2)->address84);
                    } else if (temp_v0_3 == 2) {
                        func_802AA760_de(&D_801376F8, var_s1_4, &((struct SharedRecAt94 *)temp_a2)->address84);
                    }
                    if (var_s1_4->unk5D8->unk80 == 0xB) {
                        func_802AA730_de(&D_801376F8, var_s1_4, D_800D3164);
                    }
                }
            }
        }
        var_s2 += 1;
    } while (var_s2 < 8);
    temp_v1_2 = *(((struct SharedRecAt1B92C *)(table))->unk4C);
    if (temp_v1_2 < var_s6) {
        var_s6 = temp_v1_2 - 1;
        var_s5 = 0;
    }
    (((struct SharedRecAt1B92C *)(table))->unk1B40C) = var_s6;
    if (var_s5 == 0) {
        (((struct SharedRecAt1B92C *)(table))->unk1B41C) = 0;
    }
    func_8028D380_de(table, var_s6, &((struct SharedRecAt1B92C *)table)->address1B2BC, 0x3F);
    temp_v1_3 = (((struct SharedRecAt1B92C *)(table))->unk1B434);
    if (temp_v1_3 < 0x1CEA) {
        if (temp_v1_3 < 0x1CE8) {
            if (temp_v1_3 != 0x1BBC) {
                if (temp_v1_3 < 0x1BBD) {
                    if (temp_v1_3 == 0x123A) {
                        goto scene_flag_on;
                    }
                    goto scene_flag_off;
                } else if (temp_v1_3 != 0x1C20) {
                    if (temp_v1_3 == 0x1C84) {
                        goto scene_flag_on;
                    }
                    goto scene_flag_off;
                }
            }
        }
    } else {
        if (temp_v1_3 < 0x1D4C) {
            goto scene_flag_off;
        }
        if (temp_v1_3 >= 0x1D4E) {
            if (temp_v1_3 >= 0x1DB3) {
                goto scene_flag_off;
            }
            if (temp_v1_3 < 0x1DB1) {
                goto scene_flag_off;
            }
        }
    }
scene_flag_on:
    (((struct SharedRecAt1B92C *)(table))->unk1B408) = 1;
    goto scene_flag_done;
scene_flag_off:
    (((struct SharedRecAt1B92C *)(table))->unk1B408) = 0;
scene_flag_done:
    temp_v1_4 = (((struct SharedRecAt1B92C *)(table))->unk1B434);
    if (temp_v1_4 < 0x1CEA) {
        if (temp_v1_4 < 0x1CE8) {
            if (temp_v1_4 != 0x1BBC) {
                if (temp_v1_4 < 0x1BBD) {
                    count = 0x320;
                    if (temp_v1_4 == 0x123A) {
                        goto scene_size_c80;
                    }
                    goto scene_size_done;
                }
                if (temp_v1_4 == 0x1C20) {
                    goto scene_size_c80;
                }
                count = 0x320;
                if (temp_v1_4 == 0x1C84) {
                    goto scene_size_c80;
                }
                goto scene_size_done;
            }
        }
        goto scene_size_c80;
    }
    if (temp_v1_4 == 0x1DB1) {
        goto scene_size_4b0;
    }
    if (temp_v1_4 < 0x1DB2) {
        if (temp_v1_4 < 0x1D4E) {
            count = 0x320;
            if (temp_v1_4 < 0x1D4C) {
                goto scene_size_done;
            }
            goto scene_size_c80;
        }
        goto scene_size_320;
    }
    count = 0x320;
    if (temp_v1_4 == 0x1DB2) {
        goto scene_size_c80;
    }
    goto scene_size_done;
scene_size_c80:
    count = 0xC80;
    goto scene_size_done;
scene_size_4b0:
    count = 0x4B0;
    goto scene_size_done;
scene_size_320:
    count = 0x320;
scene_size_done:
    if (D_80145088.settings.local != 0) {
        count += 0x200;
    }
    func_80253908_de(0);
    temp_v0_4 = Scene_AllocateResource(0, count << 6, 3, &D_800C5104_de);
    (((struct SharedRecAt1B92C *)(table))->unkE8) = (void *)temp_v0_4;
    Items_InitEntryBatch(&((struct SharedRecAt1B92C *)table)->address128, temp_v0_4->field_0, count);
    resourceKey = Render_GetDirectoryEntry((((struct SharedRecAt1B92C *)(table))->unk4C), (((struct SharedRecAt1B92C *)(table))->unk1C), var_s6);
    (((struct SharedRecAt1B92C *)(table))->unkB8) = func_80254284_de(0, &((struct SharedRecAt1B92C *)table)->unk60, resourceKey, D_800C5110_de);
    temp_v0_6 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 1, resourceKey, table, &D_0044C3D4, &D_800C511C_de);
    (((struct SharedRecAt1B92C *)(table))->unkBC) = temp_v0_6;
    (((struct SharedRecAt1B92C *)(table))->unk6C) = (void *) *temp_v0_6;
    temp_v0_7 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 4, resourceKey, table, &D_00285160, &D_800C5128_de);
    (((struct SharedRecAt1B92C *)(table))->unkC0) = temp_v0_7;
    (((struct SharedRecAt1B92C *)(table))->unk68) = (void *) *temp_v0_7;
    temp_v0_8 = Render_GetDirectoryEntry((((struct SharedRecAt1B92C *)(table))->unk60), resourceKey, 5);
    (((struct SharedRecAt1B92C *)(table))->unk30) = temp_v0_8;
    (((struct SharedRecAt1B92C *)(table))->unkC4) = func_80254284_de(0, &((struct SharedRecAt1B92C *)table)->address64, temp_v0_8, &D_800C5134_de);
    if (*(((struct SharedRecAt1B92C *)(table))->unk60) >= 0xD) {
        temp_v0_9 = Render_GetDirectoryEntry((((struct SharedRecAt1B92C *)(table))->unk60), resourceKey, 0xC);
        (((struct SharedRecAt1B92C *)(table))->unk40) = temp_v0_9;
        (((struct SharedRecAt1B92C *)(table))->unk100) = func_80254284_de(0, &((struct SharedRecAt1B92C *)table)->unk8C, temp_v0_9, &D_800C5148_de);
        temp_v0_10 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk8C), 0, (((struct SharedRecAt1B92C *)(table))->unk40), table, 0, &D_800C5154_de);
        temp_v1_5 = *temp_v0_10;
        *(struct SharedRecAt14 *)&((struct SharedRecAt1B92C *)table)->unk1B910 = *temp_v1_5;
        Scene_ReleaseResource(0, temp_v0_10);
        if ((((struct SharedRecAt1B92C *)(table))->unk1B920) != 0 || (((struct SharedRecAt1B92C *)(table))->unk1B924) != 0) {
            (((struct SharedRecAt1B92C *)(table))->unk1B92C) = 1;
        } else {
            (((struct SharedRecAt1B92C *)(table))->unk1B92C) = 0;
        }
    } else {
        (((struct SharedRecAt1B92C *)(table))->unk1B92C) = 0;
    }
    (((struct SharedRecAt1B92C *)(table))->unkD4) = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 7, resourceKey, table, &D_0044C108, &D_800C5160_de);
    (((struct SharedRecAt1B92C *)(table))->unkEC) = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 2, resourceKey, table, &D_0044DA54, &D_800C5168_de);
    temp_v0_11 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 0, resourceKey, table, 0, &D_800C5174_de);
    (((struct SharedRecAt1B92C *)(table))->unkC8) = temp_v0_11;
    (((struct SharedRecAt1B92C *)(table))->unk1B2B0) = (void *) *temp_v0_11;
    Items_LoadSceneLight(table);
    resource_count = *(((struct SharedRecAt1B92C *)(table))->unk60);
    D_800CC380 = ((u8) (((struct SharedRecAt10V2 *)(((struct SharedRecAt1B92C *)(table))->unk1B2B0))->unk10) >> 2) & 1;
    if (resource_count >= 9) {
        temp_v0_12 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 9, resourceKey, table, &D_00285160, &D_800C5180_de);
        (((struct SharedRecAt1B92C *)(table))->unkF0) = temp_v0_12;
        temp_v0_13 = *temp_v0_12;
        (((struct SharedRecAt1B92C *)(table))->unk1B4DC) = temp_v0_13;
        (((struct SharedRecAt1B92C *)(table))->unk1B4E0) = (s32) temp_v0_13->unk4;
        temp_v0_14 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 0xA, resourceKey, table, &D_00285160, &D_800C5190_de);
        (((struct SharedRecAt1B92C *)(table))->unkF4) = temp_v0_14;
        temp_v0_15 = *temp_v0_14;
        (((struct SharedRecAt1B92C *)(table))->unk1B4E4) = temp_v0_15;
        (((struct SharedRecAt1B92C *)(table))->unk1B4E8) = (s32) temp_v0_15->unk4;
        func_80255CA0_de(&((struct SharedRecAt1B92C *)table)->address1B500, 0xC, 0x10);
        temp_v0_16 = (((struct SharedRecAt1B92C *)(table))->unk1B4E0);
        if (temp_v0_16 > 0) {
            record = Scene_AllocateMemory(temp_v0_16 * 0x50);
            
            var_s2 = 0;
            if ((((struct SharedRecAt1B92C *)(table))->unk1B4E0) > 0) {
                do {
                    func_8020CA10_de(record, var_s2);
                    func_80255D14_de(&((struct SharedRecAt1B92C *)table)->address1B500, record);
                    record = (void *)((char *)record + 0x50);
                } while ((((struct SharedRecAt1B92C *)table)->unk1B4E0) > ++var_s2);
            }
        }
    }
    if (*(((struct SharedRecAt1B92C *)(table))->unk60) >= 0xC) {
        temp_v0_17 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 0xB, resourceKey, table, &D_00285160, &D_800C51A0_de);
        (((struct SharedRecAt1B92C *)(table))->unkFC) = temp_v0_17;
        temp_v0_18 = *temp_v0_17;
        (((struct SharedRecAt1B92C *)(table))->unk1B4EC) = temp_v0_18;
        (((struct SharedRecAt1B92C *)(table))->unk1B4F0) = (s32) temp_v0_18->unk4;
    }
    temp_v0_19 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 6, resourceKey, table, &D_00285160, &D_800C51B4_de);
    (((struct SharedRecAt1B92C *)(table))->unkCC) = temp_v0_19;
    temp_v1_6 = *temp_v0_19;
    (((struct SharedRecAt1B92C *)(table))->unk1B300) = (void *) (&((struct SharedRecAt8V1 *)temp_v1_6)->address8);
    (((struct SharedRecAt1B92C *)(table))->unk1B304) = (s32) (((struct SharedRecAt8V1 *)(temp_v1_6))->unk4);
    (((struct SharedRecAt1B92C *)(table))->unk0) = 1;
    (((struct SharedRecAt1B92C *)(table))->unk138) = 0;
    (((struct SharedRecAt1B92C *)(table))->unk140) = 0;
    (((struct SharedRecAt1B92C *)(table))->unkD0) = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk60), 3, resourceKey, table, &D_0044C7B8, &D_800C51C0_de);
    func_80286950_de(table);
    
    i = 0;
    var_v1 = 0xF;
    
    var_a0_3 = (s32)(((struct SharedRecAt1B92C *)(table))->unk138);
    var_v0 = &((struct SharedRecAt1B92C *)table)->address3C;
    (((struct SharedRecAt1B92C *)(table))->unk1B6A4) = 0;
    do {
        (((struct SharedRecAt1B664V2 *)(var_v0))->unk1B664) = 0;
        var_v1 -= 1;
        var_v0 -= 4;
    } while (var_v1 >= 0);
    
    var_v1 = 0;
    
    if ((((struct SharedRecAt1B92C *)(table))->unk140) > 0) {
        first_actor_kind = 0xE;
        var_a1 = (void *)(i * sizeof(void *) + (u32)table);
loop_81:
        if (*(((struct ObjRecAt18V2 *)((void *)var_a0_3))->unk18) == first_actor_kind) {
            (((struct SharedRecAt1B664V1 *)(var_a1))->unk1B664) = (void *)var_a0_3;
            var_a1 += 4;
            i += 1;
            var_v0_2 = i < 0x10;
        } else {
            var_v0_2 = i < 0x10;
        }
        if (var_v0_2 != 0) {
            var_a0_3 = (s32)NEXT_SCENE_ACTOR((void *)var_a0_3);
            var_v1 += 1;
            if (var_v1 < (((struct SharedRecAt1B92C *)(table))->unk140)) {
                goto loop_81;
            }
        }
    }
    
    var_s1_3 = 3;
    scene_actor_ptr = (((struct SharedRecAt1B92C *)(table))->unk138);
    actor_type3 = 3;
    actor_kind_bd7 = 0xBD7;
    var_v0_3 = 3 * sizeof(void *);
    
    
    (((struct SharedRecAt1B92C *)(table))->unk1B6A4) = i;
    D_800F3CD0.primary.kindBd7 = 0;
    do {
        *(void **)((char *)D_800F3CD0.primary.actors + var_v0_3) = 0;
        var_s1_3 -= 1;
        var_v0_3 -= sizeof(void *);
    } while (var_s1_3 >= 0);
    var_s1_3 = 0;
    if ((((struct SharedRecAt1B92C *)(table))->unk140) > 0) {
        kind_actor = 0xA;
        kind_654 = 0x654;
        kind_653 = 0x653;
        kind_655 = 0x655;
        kind_656 = 0x656;
        var_s2_3 = &((struct SharedRecAtE4V1 *)scene_actor_ptr)->kind;
loop_89:
        temp_v1_7 = ((struct Shared_SceneActorPrefix *)var_s2_3)[-1].definition;
        temp_v0_20 = temp_v1_7->unk0;
        if (temp_v0_20 == actor_type3) {
            if (func_8028B25C_de(&D_8011FE88, temp_v1_7->unk28) != actor_kind_bd7) {
                goto block_108;
            }
            D_800F3CD0.primary.kindBd7 = scene_actor_ptr;
            goto block_109;
        } else {
            if (temp_v0_20 == kind_actor) {
                kind = var_s2_3->kind;
                if (kind == kind_654) {
                    goto actor_kind_654;
                }
                if (kind < 0x655) {
                    if (kind == kind_653) {
                        goto actor_kind_653;
                    }
                        goto block_108;
                }
                if (kind == kind_655) {
                    goto actor_kind_655;
                }
                if (kind == kind_656) {
                        goto actor_kind_656;
                }
                goto block_108;
actor_kind_653:
                D_800F3CD0.primary.actors[0] = scene_actor_ptr;
                goto block_108;
actor_kind_654:
                D_800F3CD0.primary.actors[1] = scene_actor_ptr;
                goto block_108;
actor_kind_655:
                D_800F3CD0.primary.actors[2] = scene_actor_ptr;
                goto block_108;
actor_kind_656:
                D_800F3CD0.primary.actors[3] = scene_actor_ptr;
            }
block_108:
            var_s2_3 = NEXT_SCENE_ACTOR(var_s2_3);
            scene_actor_ptr = NEXT_SCENE_ACTOR(scene_actor_ptr);
            var_s1_3 += 1;
            if (var_s1_3 >= (((struct SharedRecAt1B92C *)(table))->unk140)) {
                goto block_109;
            }
            goto loop_89;
        }
    } else {
block_109:
        j = 0;
    }
    
    var_a0_3 = 9;
    var_a2_2 = (((struct SharedRecAt1B92C *)(table))->unk138);
    var_v0_4 = 9 * sizeof(void *);
    
    
    D_800F3CD0.kindBd6 = 0;
    do {
        *(void **)((char *)D_800F3CD0.kind64e + var_v0_4) = 0;
        var_a0_3 -= 1;
        var_v0_4 -= sizeof(void *);
    } while (var_a0_3 >= 0);
    var_a0_3 = 0;
    if ((((struct SharedRecAt1B92C *)(table))->unk140) > 0) {
        second_type3 = 3;
        second_kind_bd6 = 0xBD6;
        second_type10 = 0xA;
        second_kind_64e = 0x64E;
        var_a1_2 = &((struct SharedRecAtE4V2 *)var_a2_2)->kind;
loop_114:
        temp_v1_9 = ((struct Shared_SceneActorPrefix *)var_a1_2)[-1].definition;
        temp_v0_21 = temp_v1_9->unk0;
        if (temp_v0_21 == second_type3) {
            if (temp_v1_9->unk28 == second_kind_bd6) {
                D_800F3CD0.kindBd6 = var_a2_2;
            }
        } else if (temp_v0_21 == second_type10) {
            if (var_a1_2->kind == second_kind_64e) {
                D_800F3CD0.kind64e[j] = var_a2_2;
                j += 1;
            }
        }
        var_v0_5 = j < 0xA;
        if (var_v0_5 != 0) {
            var_a1_2 = NEXT_SCENE_ACTOR(var_a1_2);
            var_a2_2 = NEXT_SCENE_ACTOR(var_a2_2);
            var_a0_3 += 1;
            if (var_a0_3 >= (((struct SharedRecAt1B92C *)(table))->unk140)) {
                goto block_122;
            }
            goto loop_114;
        }
    } else {
block_122:
        D_801462C8.counters.m_nFragTagSkin = func_802A01E8_de(var_a0_3) % 3;
    }
    (((struct SharedRecAt1B92C *)(table))->unk0) = 2;
    Items_UpdatePendingObjects(table);
    temp_s4 = (((struct SharedRecAt1B92C *)(table))->unk140);
    var_s1_3 = (((struct SharedRecAt1B92C *)(table))->unk13C);
    (((struct SharedRecAt1B92C *)(table))->unk0) = 3;
    if (var_s1_3 < temp_s4) {
        var_s0_4 = var_s1_3 * sizeof(struct Shared_SceneActorStride);
        do {
            var_s1_3 += 1;
            func_8024B2D0_de((((struct SharedRecAt1B92C *)(table))->unk138) + var_s0_4);
            var_s0_4 += sizeof(struct Shared_SceneActorStride);
        } while (var_s1_3 < temp_s4);
    }
    var_s1_4 = D_80145060.actorList;
    if (var_s1_4 != 0) {
        
        temp_v0_2 = var_s1_4;
        do {
            func_8024B2D0_de(temp_v0_2);
            func_8024B2D0_de(NEXT_SCENE_ACTOR(temp_v0_2));
            (((struct func_80203E78_S1 *)(((struct SharedRecAt16E0V3 *)(var_s1_4))->unk1454))->unk4) = func_8020CB3C_de(&((struct SharedRecAt1B92C *)table)->unk1B4DC, &((struct SharedRecAt16E0V3 *)var_s1_4)->address8);
            var_s1_4 = (((struct SharedRecAt16E0V3 *)(var_s1_4))->unk16E0);
            if (var_s1_4 == 0) {
                break;
            }
            temp_v0_2 = var_s1_4;
        } while (1);
    }
    func_8044D668_de(table);
    temp_s4 = (((struct SharedRecAt1B92C *)(table))->unk140);
    k = (((struct SharedRecAt1B92C *)(table))->unk13C);
    if (k < temp_s4) {
        var_s2_4 = k * sizeof(struct Shared_SceneActorStride);
        do {
            k += 1;
            
            temp_v0_2 = (((struct SharedRecAt1B92C *)(table))->unk138) + var_s2_4;
            func_8024BE3C_de(temp_v0_2);
            func_80246E44_de(temp_v0_2);
            var_s2_4 += sizeof(struct Shared_SceneActorStride);
        } while (k < temp_s4);
    }
    
    
    count = (char *)&((struct SharedRecAt1B92C *)table)->unk1B4DC - (char *)table;
    temp_v0_2 = (char *)table + count;
    func_8020AA40_de(temp_v0_2);
    Nav_AssignPlatformEndpoints(temp_v0_2);
    (((struct SharedRecAt1B92C *)(table))->unk0) = 4;
    func_80449E18_de(&D_80145040);
    group = &D_80145040.object;
    Items_InitGroupPools(group);
    func_80236874_de(group);
}

/* Native resident constant storage; absolute access symbols retain their addresses. */
