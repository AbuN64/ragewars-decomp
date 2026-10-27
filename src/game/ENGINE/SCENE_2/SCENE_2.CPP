#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/LONE/D_800E4680.H"
#include "SCENE/80286050.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/INTEGERSTATEB0.H"
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
#include "SCENE/SHAREDRECAT16E0V3.H"
#include "SCENE/SHARED_S21.H"
#include "COMMON/OUTPUT.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/INTEGERSTATE2C.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/S1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "AI/NAV/80208000_6.H"
#include "AI/NAV/80208000_8.H"
#include "OVLGAME/8044E2B8.H"
#include "SCHED/8023A284_29.H"
#include "OVLGAME/8044BD30.H"
#include "COMMON/LOCALDECODERANGE.H"
#include "include_asm.h"
#include "SCENE/SIMPLE_INSTANCE_RECORD.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/OBJB.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/OBJRECAT5F14.H"

/* 80286050_2.CPP */
/* Collects up to sixteen switch objects (descriptor type 0xD) of a world into its switch list, first syncing each one's flag 4 with the switch table D_800E4680 when its kind is 0xD34 to 0xD37: model 0xD2B follows table byte 1, models 0xD2C to 0xD2E follow their own table byte, and any other model clears the flag; the flag is set when the byte is zero. */

void Scene_CollectLevelSwitches(WorldRecAt1B660 *world) {
    ObjectRecAt18 *object;
    DescriptorRecAt20 *descriptor;
    s32 found;
    s32 i;

    found = 0;
    object = world->objects;
    world->switchCount = 0;
    for (i = 15; i >= 0; i--) {
        world->switches[i] = 0;
    }
    for (i = 0; i < world->count; object++, i++) {
        descriptor = object->descriptor;
        if (descriptor->type == 0xD) {
            if (D_800E4680 != 0 && (unsigned)(descriptor->kind - 0xD34) < 4) {
                switch (descriptor->model) {
                case 0xD2B:
                    if (D_800E4680[1] == 0) {
                        descriptor->flags |= 4;
                    } else {
                        descriptor->flags &= ~4;
                    }
                    break;
                case 0xD2C:
                case 0xD2D:
                case 0xD2E:
                    if (D_800E4680[object->descriptor->model - 0xD2A] == 0) {
                        object->descriptor->flags |= 4;
                        break;
                    }
                default:
                    object->descriptor->flags &= ~4;
                    break;
                }
            }
            world->switches[found] = object;
            found++;
        }
        if (found >= 16) {
            break;
        }
    }
    world->switchCount = found;
}

/* SCENE.CPP */
/* Unknown data types are explicit unresolved contracts, never guessed s32. */

extern void Nav_ResetPlayerState();
extern void Nav_AssignPlatformEndpoints();
extern s32 Nav_FindNearestPointIndex();
extern void * Player_GetPlayerByIndex();
extern void Camera_UpdateViewportLayoutAndBounds();
extern void func_80246E44_de(void *);
extern void func_8024B2D0_de(void *);
extern void func_8024BE3C_de(void *);
extern struct Shape_typemap_165 * Cache_AllocateResource();
extern void func_80253908_de(s32);
extern s32 func_80254284_de(s32, void *, s32, void *);
extern void **func_80254408_de(s32 arg0, void *handle, s32 arg2, s32 tempv0, void *world, void *arg5, void *arg6);
extern s32 func_80255228_de(void *);
extern void func_8025C8D8_de(void *, void *, s32);
extern void Scene_ShowResultsGoal();
extern s32 Scene_GetModelIdAtIndex();
extern void Scene_CopyLevelName();
extern void Scene_ClearSceneObjectCounts();
extern void Scene_UnlockActiveSectionResources();
extern void Scene_ResetTransitionViewport();
extern void Scene_ReleaseCachedLevelData();
extern int SetN64_GetDirectoryEntry();
extern s32 XPlus_NextRandomInteger();
extern s32 OnScreen_StartFirstStatusBar();
extern void OnScreen_StartSecondStatusBar();
extern void Menu_TriggerTrackEvent();
extern void Ovlgame_RefreshActivePlayerSceneState();
extern void Items_InitGroupPools();
extern void Ovlgame_InitializeSceneEffectPool();
extern void Items_InitEntryBatch();
extern void Items_InitSlotPool();
extern void OvlScene_LoadSceneLight();
extern void OvlScene_FreeSceneResources();
extern void OvlScene_UpdatePendingObjects();
extern void OvlScene_DispatchSelectedEntityKinds();
extern void Ovlgame_InitEffectPool();
extern void Ovlgame_InitializeWorldActorPools();
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

extern unsigned char s_matricesText[];                          /* unable to generate initializer: unknown type; const */

                          /* unable to generate initializer: unknown type; const */
extern unsigned char s_collisionText[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5128_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5134_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char s_visibilityText[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5154_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char s_linksText[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char s_levelPathsText[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char s_levelInfoText[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5180_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5190_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char s_levelNavVisionText[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char s_skyLayersText[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char s_animatedInstancesText[];                          /* unable to generate initializer: unknown type; const */
extern s32 D_800CD730;                          /* const */

       /* const */
extern struct Shared_SceneActorTables D_800F3CD0; /* const */

/* const */

/* Initializes scene resources, actors, and game mode state. */
void Scene_LoadLevelResources(void *table, s32 target, s32 arg2) {
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
    struct SharedRecAt28V1 *temp_v1_9;
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
        OvlScene_DispatchAndRecycleQueuedTriggers(table);
    }
    (((struct SharedRecAt1B92C *)(table))->unk1B6AC) = 0;
    if ((Cinema_IsSequenceActive() == 0) && (var_s5 != 0) && ((((struct SharedRecAt1B92C *)(table))->unk1B41C) != 0) && (D_801462C8.counters.transitionActive == 0)) {
        Scene_ResetTransitionViewport();
        temp_v0 = (((struct SharedRecAt1B92C *)(table))->unk1B434);
        if ((u32) (temp_v0 - 0xBC2) < 0x15FU) {
            Menu_TriggerTrackEvent(((temp_v0 - 0xBC2) / 10) + 0x259);
        }
        Scene_ShowResultsGoal();
    }
    Scene_UnlockActiveSectionResources(table);
    (((struct SharedRecAt1B92C *)(table))->unk0) = 0;
    func_80255228_de(&D_80106248);
    Scene_ReleaseCachedLevelData(table);
    func_80253908_de(0);
    if ((((struct SharedRecAt1B92C *)(table))->unk1B40C) != -1) {
        OvlScene_FreeSceneResources(table);
    }
    func_80253908_de(0);
    D_800CD730 = 0;
    func_8025476C_de(8);
    Scene_ClearSceneObjectCounts(table);
    Items_InitSlotPool(&((struct SharedRecAt1B92C *)table)->address1B08, *(((struct SharedRecAt1B92C *)(table))->unkB4));
    var_s2 = 0;
    Ovlgame_InitEffectPool(&((struct SharedRecAt1B92C *)table)->address11778);
    Ovlgame_InitializeSceneEffectPool(&((struct SharedRecAt1B92C *)table)->address15388);
    Ovlgame_InitializeWorldActorPools(&D_801376F8.actors);
    func_8023EE00_de();
    Ovlgame_InitializeDynamicLightPool(&((struct SharedRecAt1B92C *)table)->address1B320);
    func_8025C8D8_de(&D_8011F260, &D_8011AFC0, 0xF);
    Ovlgame_StartPanelMovers(&D_801376F8);
    do {
        var_s1_4 = Player_GetPlayerByIndex(&D_80145040, var_s2);
        if (var_s1_4 != 0) {
            temp_v1 = var_s1_4->unk5D8;
            if ((((struct SharedRecAt91 *)temp_v1)->unk78 == 1) && (((struct SharedRecAt91 *)temp_v1)->unk91 == 1)) {
                Nav_ResetPlayerState(var_s1_4->unk1454);
            }
            if ((((struct SharedRecAt98 *)(&D_801468A0))->unk98) != 0) {
                temp_a2 = var_s1_4->unk5D8;
                temp_v0_3 = (((struct SharedRecAt94 *)(temp_a2))->unk94);
                if (temp_v0_3 != 0) {
                    if (temp_v0_3 == 1) {
                        OnScreen_StartFirstStatusBar(&D_801376F8, var_s1_4, &((struct SharedRecAt94 *)temp_a2)->address84);
                    } else if (temp_v0_3 == 2) {
                        OnScreen_StartSecondStatusBar(&D_801376F8, var_s1_4, &((struct SharedRecAt94 *)temp_a2)->address84);
                    }
                    if (var_s1_4->unk5D8->unk80 == 0xB) {
                        OnScreen_StartFirstStatusBar(&D_801376F8, var_s1_4, D_800D3164);
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
    Scene_CopyLevelName(table, var_s6, &((struct SharedRecAt1B92C *)table)->address1B2BC, 0x3F);
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
    temp_v0_4 = Cache_AllocateResource(0, count << 6, 3, &s_matricesText);
    (((struct SharedRecAt1B92C *)(table))->unkE8) = (void *)temp_v0_4;
    Items_InitEntryBatch(&((struct SharedRecAt1B92C *)table)->address128, temp_v0_4->field_0, count);
    resourceKey = SetN64_GetDirectoryEntry((((struct SharedRecAt1B92C *)(table))->unk4C), (((struct SharedRecAt1B92C *)(table))->unk1C), var_s6);
    (((struct SharedRecAt1B92C *)(table))->unkB8) = func_80254284_de(0, &((struct SharedRecAt1B92C *)table)->sceneResources, resourceKey, g_levelIndexText);
    temp_v0_6 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 1, resourceKey, table, &D_0044C3D4, &s_collisionText);
    (((struct SharedRecAt1B92C *)(table))->unkBC) = temp_v0_6;
    (((struct SharedRecAt1B92C *)(table))->unk6C) = (void *) *temp_v0_6;
    temp_v0_7 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 4, resourceKey, table, &D_00285160, &D_800C5128_de);
    (((struct SharedRecAt1B92C *)(table))->unkC0) = temp_v0_7;
    (((struct SharedRecAt1B92C *)(table))->unk68) = (void *) *temp_v0_7;
    temp_v0_8 = SetN64_GetDirectoryEntry((((struct SharedRecAt1B92C *)(table))->sceneResources), resourceKey, 5);
    (((struct SharedRecAt1B92C *)(table))->unk30) = temp_v0_8;
    (((struct SharedRecAt1B92C *)(table))->unkC4) = func_80254284_de(0, &((struct SharedRecAt1B92C *)table)->address64, temp_v0_8, &D_800C5134_de);
    if (*(((struct SharedRecAt1B92C *)(table))->sceneResources) >= 0xD) {
        temp_v0_9 = SetN64_GetDirectoryEntry((((struct SharedRecAt1B92C *)(table))->sceneResources), resourceKey, 0xC);
        (((struct SharedRecAt1B92C *)(table))->unk40) = temp_v0_9;
        (((struct SharedRecAt1B92C *)(table))->unk100) = func_80254284_de(0, &((struct SharedRecAt1B92C *)table)->unk8C, temp_v0_9, &s_visibilityText);
        temp_v0_10 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->unk8C), 0, (((struct SharedRecAt1B92C *)(table))->unk40), table, 0, &D_800C5154_de);
        temp_v1_5 = *temp_v0_10;
        *(struct SharedRecAt14 *)&((struct SharedRecAt1B92C *)table)->unk1B910 = *temp_v1_5;
        Cache_ReleaseResource(0, temp_v0_10);
        if ((((struct SharedRecAt1B92C *)(table))->unk1B920) != 0 || (((struct SharedRecAt1B92C *)(table))->unk1B924) != 0) {
            (((struct SharedRecAt1B92C *)(table))->unk1B92C) = 1;
        } else {
            (((struct SharedRecAt1B92C *)(table))->unk1B92C) = 0;
        }
    } else {
        (((struct SharedRecAt1B92C *)(table))->unk1B92C) = 0;
    }
    (((struct SharedRecAt1B92C *)(table))->unkD4) = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 7, resourceKey, table, &D_0044C108, &s_linksText);
    (((struct SharedRecAt1B92C *)(table))->unkEC) = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 2, resourceKey, table, &D_0044DA54, &s_levelPathsText);
    temp_v0_11 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 0, resourceKey, table, 0, &s_levelInfoText);
    (((struct SharedRecAt1B92C *)(table))->unkC8) = temp_v0_11;
    (((struct SharedRecAt1B92C *)(table))->unk1B2B0) = (void *) *temp_v0_11;
    OvlScene_LoadSceneLight(table);
    resource_count = *(((struct SharedRecAt1B92C *)(table))->sceneResources);
    D_800CC380 = ((u8) (((struct SharedRecAt10V2 *)(((struct SharedRecAt1B92C *)(table))->unk1B2B0))->unk10) >> 2) & 1;
    if (resource_count >= 9) {
        temp_v0_12 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 9, resourceKey, table, &D_00285160, &D_800C5180_de);
        (((struct SharedRecAt1B92C *)(table))->unkF0) = temp_v0_12;
        temp_v0_13 = *temp_v0_12;
        (((struct SharedRecAt1B92C *)(table))->navPointSet) = temp_v0_13;
        (((struct SharedRecAt1B92C *)(table))->unk1B4E0) = (s32) temp_v0_13->unk4;
        temp_v0_14 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 0xA, resourceKey, table, &D_00285160, &D_800C5190_de);
        (((struct SharedRecAt1B92C *)(table))->unkF4) = temp_v0_14;
        temp_v0_15 = *temp_v0_14;
        (((struct SharedRecAt1B92C *)(table))->unk1B4E4) = temp_v0_15;
        (((struct SharedRecAt1B92C *)(table))->unk1B4E8) = (s32) temp_v0_15->unk4;
        func_80255CA0_de(&((struct SharedRecAt1B92C *)table)->address1B500, 0xC, 0x10);
        temp_v0_16 = (((struct SharedRecAt1B92C *)(table))->unk1B4E0);
        if (temp_v0_16 > 0) {
            record = Cache_AllocateMemory(temp_v0_16 * 0x50);

            var_s2 = 0;
            if ((((struct SharedRecAt1B92C *)(table))->unk1B4E0) > 0) {
                do {
                    Nav_InitSearchNode(record, var_s2);
                    func_80255D14_de(&((struct SharedRecAt1B92C *)table)->address1B500, record);
                    record = (void *)((char *)record + 0x50);
                } while ((((struct SharedRecAt1B92C *)table)->unk1B4E0) > ++var_s2);
            }
        }
    }
    if (*(((struct SharedRecAt1B92C *)(table))->sceneResources) >= 0xC) {
        temp_v0_17 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 0xB, resourceKey, table, &D_00285160, &s_levelNavVisionText);
        (((struct SharedRecAt1B92C *)(table))->unkFC) = temp_v0_17;
        temp_v0_18 = *temp_v0_17;
        (((struct SharedRecAt1B92C *)(table))->unk1B4EC) = temp_v0_18;
        (((struct SharedRecAt1B92C *)(table))->unk1B4F0) = (s32) temp_v0_18->unk4;
    }
    temp_v0_19 = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 6, resourceKey, table, &D_00285160, &s_skyLayersText);
    (((struct SharedRecAt1B92C *)(table))->unkCC) = temp_v0_19;
    temp_v1_6 = *temp_v0_19;
    (((struct SharedRecAt1B92C *)(table))->unk1B300) = (void *) (&((struct SharedRecAt8V1 *)temp_v1_6)->address8);
    (((struct SharedRecAt1B92C *)(table))->unk1B304) = (s32) (((struct SharedRecAt8V1 *)(temp_v1_6))->unk4);
    (((struct SharedRecAt1B92C *)(table))->unk0) = 1;
    (((struct SharedRecAt1B92C *)(table))->unk138) = 0;
    (((struct SharedRecAt1B92C *)(table))->unk140) = 0;
    (((struct SharedRecAt1B92C *)(table))->unkD0) = func_80254408_de(0, (((struct SharedRecAt1B92C *)(table))->sceneResources), 3, resourceKey, table, &D_0044C7B8, &s_animatedInstancesText);
    Scene_CollectLevelSwitches(table);

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
            if (Scene_GetModelIdAtIndex(&g_world, temp_v1_7->unk28) != actor_kind_bd7) {
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
        var_a1_2 = &((struct SharedRecAtE4V1 *)var_a2_2)->kind;
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
        D_801462C8.counters.m_nFragTagSkin = XPlus_NextRandomInteger(var_a0_3) % 3;
    }
    (((struct SharedRecAt1B92C *)(table))->unk0) = 2;
    OvlScene_UpdatePendingObjects(table);
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
            (((struct func_80203E78_S1 *)(((struct SharedRecAt16E0V3 *)(var_s1_4))->unk1454))->unk4) = Nav_FindNearestPointIndex(&((struct SharedRecAt1B92C *)table)->navPointSet, &((struct SharedRecAt16E0V3 *)var_s1_4)->address8);
            var_s1_4 = (((struct SharedRecAt16E0V3 *)(var_s1_4))->unk16E0);
            if (var_s1_4 == 0) {
                break;
            }
            temp_v0_2 = var_s1_4;
        } while (1);
    }
    OvlScene_DispatchSelectedEntityKinds(table);
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


    count = (char *)&((struct SharedRecAt1B92C *)table)->navPointSet - (char *)table;
    temp_v0_2 = (char *)table + count;
    Nav_LinkNavigationObjects(temp_v0_2);
    Nav_AssignPlatformEndpoints(temp_v0_2);
    (((struct SharedRecAt1B92C *)(table))->unk0) = 4;
    Ovlgame_RefreshActivePlayerSceneState(&D_80145040);
    group = &D_80145040.object;
    Items_InitGroupPools(group);
    Camera_UpdateViewportLayoutAndBounds(group);
}

/* Native resident constant storage; absolute access symbols retain their addresses. */

/* SCENE_2.CPP */
/* Spawns an entity through Link_DispatchTrigger when its bit is set in the current level's placement mask and it either names no flag or its flag in the global flag table D_8011FF08 is clear. */

extern s32 SetN64_GetPackSectionSize(void *table, s32 index);

void Scene_DispatchEnabledEntityTrigger(WorldSceneDispatchEnabledEntityTrigger *world, Entity *entity) {
    s32 index;
    s32 level;
    void *mask;
    unsigned char *bits;
    void *flags;
    s32 flag;
    s32 bit;

    index = entity->index;
    level = world->level;
    mask = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(world->levels, 0), level), 2);
    SetN64_GetPackSection(mask, 0);
    SetN64_GetPackSectionSize(mask, 1);
    bits = SetN64_GetPackSection(mask, 1);
    bit = 1 << (index & 7);
    if (bits[index / 8] & bit) {
        if (entity->flag != 0) {
            flag = entity->flag;
            flags = SetN64_GetPackSection(g_world.bitSections, 1);
            SetN64_GetPackSection(flags, 0);
            if (((unsigned char *)SetN64_GetPackSection(flags, 1))[flag] != 0) {
                return;
            }
        }
        Link_DispatchTrigger(entity);
    }
}

/* A resource's block set: the count of blocks and the byte offset of each from the set's start. */

/* A run of equal-sized records: record size, count, then the records. */
typedef struct RecordSet {
    s32 size;
    s32 count;
} RecordSet;

/* A simple (animated, unlit-by-grid) instance as the level resource stores it. */

/* A simple instance in the game: the header's position, its flags and id, and the lighting baked from the level's
 * light volumes. */
typedef struct SimpleInstance {
    u8 header[8];
    CVector3 position;
    u8 pad14[0x19C - 0x14];
    u16 flags;
    u16 id;
    u8 pad1A0[0x1A8 - 0x1A0];
    Shared_ParticleLighting light;
    u8 pad1C0[0x1C8 - 0x1C0];
} SimpleInstance;

/* A light volume as the level resource stores it. */
typedef struct LightVolumeRecord {
    u8 data[0x4C];
} LightVolumeRecord;

extern s32 SetN64_GetPackSize(void *table);
extern void *Cache_AllocResourceBlock(s32 pool, void *handle, s32 size);
extern void Cache_ReplaceResourceBlock(s32 pool, void *handle, void *block);
extern void func_802BD3A0_de(void *dst, void *src, s32 size);
extern void StaticInstance_InitializePlacedProp(PlacedProp *prop, RecordRecAt1A *record, s32 owner, char *segments, f32 spacing);
extern void StaticInstance_InitPlacedProp(PlacedProp *prop, PlacedPropRecord *record, s32 owner, char *segments);
extern void World_InitSimpleInstance(SimpleInstance *instance, CROMSimpleInstance *record, s32 owner, char *segments);
extern void Lighting_DecodeBoxTransform(ObjectRecAtBC *volume, LightVolumeRecord *record);

#define ALIGN8(size) (((size) + 7) & ~7)

/* Whether the instance's bit is set in the current level's instance mask (section 1 of the level's bit sections).
 * The same body as Scene_TestLevelRecordStateBit; the ROM inlines it here. */
static inline s32 Engine_TestInstanceBit(Shared_World *world, SimpleInstance *instance) {
    s32 index;
    void *sections;
    s32 level;
    void *mask;
    u8 *bits;
    s32 bit;

    index = instance->id;
    sections = world->bitSections;
    level = world->level;
    mask = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(sections, 0), level), 1);
    SetN64_GetPackSection(mask, 0);
    SetN64_GetPackSectionSize(mask, 1);
    bits = SetN64_GetPackSection(mask, 1);
    bit = 1 << (index & 7);
    return (bits[index / 8] & bit) != 0;
}

/* Builds a level's placed instances into one pool block of five sections: props (efficient then static records),
 * simple instances (flagged when the level's instance mask has their bit), light volumes, and a copy of the bit set.
 * Each simple instance then takes its lighting from the volumes at half its actor height. */
void Scene_BuildPlacedInstances(Shared_World *world, void ***handle) {
    ObjectRecAtBC *volumeList[128];
    CVector3 position;
    Pack *bitSet;
    RecordSet *efficientSet;
    RecordSet *simpleSet;
    RecordSet *volumeSet;
    char *base;
    s32 staticCount;
    s32 simpleCount;
    s32 volumeCount;
    s32 staticSize;
    s32 simpleSize;
    s32 volumeSize;
    s32 bitSize;
    PlacedPropRecord *statics;
    SimpleInstance *simples;
    char *segments;
    void **block;
    Pack *source;
    RecordSet *staticSet;
    s32 efficientCount;
    Pack *blocks;
    char *dst;
    s32 offset;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    PlacedProp *props;
    RecordRecAt1A *efficient;
    CROMSimpleInstance *simpleRecords;
    LightVolumeRecord *volumeRecords;
    ObjectRecAtBC *volumes;
    void *objects;

    if (PpDecom_UnpackResource(handle, 1) != 0) {
        source = **handle;
        efficientSet = SetN64_GetPackSection(source, 0);
        efficientCount = efficientSet->count;
        staticSet = SetN64_GetPackSection(source, 1);
        staticCount = staticSet->count;
        staticSize = ALIGN8((efficientCount + staticCount) * sizeof(PlacedProp) + sizeof(RecordSet));
        simpleSet = SetN64_GetPackSection(source, 2);
        simpleCount = simpleSet->count;
        simpleSize = ALIGN8(simpleCount * sizeof(SimpleInstance) + sizeof(RecordSet));
        volumeSet = SetN64_GetPackSection(source, 3);
        volumeCount = volumeSet->count;
        volumeSize = ALIGN8(volumeCount * sizeof(ObjectRecAtBC) + sizeof(RecordSet));
        bitSet = SetN64_GetPackSection(source, 4);
        bitSize = ALIGN8(bitSet->count * sizeof(s32) + sizeof(RecordSet));
        block = Cache_AllocResourceBlock(0, handle, staticSize + 0x18 + simpleSize + volumeSize + bitSize);
        if (block != 0) {
            n = 0;
            offset = 0x18;
            blocks = *block;
            dst = (char *)blocks + offset;
            blocks->count = n++;
            blocks->offsets[blocks->count] = offset;
            SetN64_TransposeRecords(efficientSet, dst, 1);
            SetN64_TransposeRecords(staticSet, dst, 1);
            ((RecordSet *)dst)->size = sizeof(PlacedProp);
            ((RecordSet *)dst)->count = efficientCount + staticCount;
            efficient = (RecordRecAt1A *)(efficientSet + 1);
            objects = SetN64_GetPackSection(world->modelSections, 2);
            statics = (PlacedPropRecord *)(staticSet + 1);
            props = (PlacedProp *)(dst + 8);
            base = (char *)blocks;
            segments = (char *)objects + 8;
            for (i = 0; i < efficientCount; i++) {
                StaticInstance_InitializePlacedProp(&props[i], &efficient[i],
                                 SetN64_GetDirectoryEntry(world->indexedDirectory, world->indexedBank, efficient[i].id),
                                 segments, world->levelInfo->m_GridDistance);
            }
            for (j = 0; j < staticCount; j++) {
                StaticInstance_InitPlacedProp(&props[j + efficientCount], &statics[j],
                                 SetN64_GetDirectoryEntry(world->indexedDirectory, world->indexedBank, statics[j].id),
                                 segments);
            }

            offset += staticSize;
            blocks->count = n++;
            blocks->offsets[blocks->count] = offset;
            SetN64_TransposeRecords(simpleSet, base + offset, 1);
            ((RecordSet *)(base + offset))->size = sizeof(SimpleInstance);
            ((RecordSet *)(base + offset))->count = simpleCount;
            simpleRecords = (CROMSimpleInstance *)(simpleSet + 1);
            simples = (SimpleInstance *)(base + offset + 8);
            for (k = 0; k < simpleCount; k++) {
                World_InitSimpleInstance(&simples[k], &simpleRecords[k],
                                 SetN64_GetDirectoryEntry(world->indexedDirectory, world->indexedBank, simpleRecords[k].type),
                                 segments);
                if (Engine_TestInstanceBit(world, &simples[k])) {
                    simples[k].flags |= 1;
                }
            }

            offset += simpleSize;
            blocks->count = n++;
            blocks->offsets[blocks->count] = offset;
            SetN64_TransposeRecords(volumeSet, base + offset, 1);
            ((RecordSet *)(base + offset))->size = sizeof(ObjectRecAtBC);
            ((RecordSet *)(base + offset))->count = volumeCount;
            volumeRecords = (LightVolumeRecord *)(volumeSet + 1);
            volumes = (ObjectRecAtBC *)(base + offset + 8);
            for (i = 0; i < volumeCount; i++) {
                Lighting_DecodeBoxTransform(&volumes[i], &volumeRecords[i]);
            }

            offset += volumeSize;
            blocks->count = n++;
            blocks->offsets[blocks->count] = offset;
            func_802BD3A0_de(base + offset, bitSet, SetN64_GetPackSize(bitSet));

            blocks->count = n++;
            offset += bitSize;
            blocks->offsets[blocks->count] = offset;

            for (i = 0; i < volumeCount; i++) {
                volumeList[i] = &volumes[i];
            }
            for (k = 0; k < simpleCount; k++) {
                position.x = simples[k].position.x;
                position.y = simples[k].position.y + GameObject_GetActorHeight(&simples[k]) * 0.5f;
                position.z = simples[k].position.z;
                Scene_SampleVolumeLighting(volumeList, volumeCount, &position, &simples[k].light);
            }
        }
        Cache_ReplaceResourceBlock(0, handle, block);
    }
}

extern void func_8022A1FC_de(void *pool, void *world);
extern s32 func_8024D160_de(void *actor);
extern s32 func_8024E1B4_de(void *actor);
extern void func_8024B8C4_de(void *actor);
extern f32 Sky_GetDistanceTo(void *camera, CVector3 *position);
extern s32 VisData_TestBoxAgainstFrustum(void *planes, void *bounds);
extern void AnimPool_UpdateSceneEffects(struct CAnimPool *scene, void *world);

typedef struct SceneVisibilitySettings {
    u32 mask;
    u8 reserved04[0x11];
    u8 local;
} SceneVisibilitySettings;

/* Whether the actor's bounding box overlaps the box. */
#define ACTOR_OVERLAPS(actor, box) ((box)->x > (actor)->bounds.min.x && \
    ((Box *)((u8 *)(box) - 12))->min.x < (actor)->bounds.max.x && \
    (box)->z > (actor)->bounds.min.z && \
    ((Box *)((u8 *)(box) - 12))->min.z < (actor)->bounds.max.z && \
    (box)->y > (actor)->bounds.min.y && \
    ((Box *)((u8 *)(box) - 12))->min.y < (actor)->bounds.max.y)

/* Per-frame visibility scan over the world's actors. Rebuilds the lists of registered, interactive, mover, flagged and
 * per-model actors from the actors that are visible this frame (inside the clip box and the camera frustum, or within
 * range for kind 14), copies each actor's visible bit into bit 15 of its flags, then culls the scene's effects. */

void Scene_UpdateActorVisibility(Shared_World *world) {
    SceneVisibilitySettings *settings;
    LevelActor *actors;
    LevelActor *actor;
    GameplayCamera *camera;
    ActorDefinitionHeader *definition;
    CVector3 *clipBox;
    CVector3 *rangeBox;
    s32 end;
    u32 mask;
    s32 i;
    s32 visible;
    s32 cull;

    settings = (SceneVisibilitySettings *)&D_80145040.game.sceneMask;
    mask = settings->mask;
    world->registeredCount = 0;
    world->kind1Count = 0;
    world->flaggedCount = 0;
    func_8022A1FC_de((u8 *)settings - 0x1290, world);
    camera = 0;
    if (settings->local == 0) {
        camera = *(GameplayCamera **)((u8 *)settings - 0x1228);
    }
    cull = 0;
    if (Cinema_IsSequenceInWindow() == 0) {
        cull = world->visibilityEnabled == 0;
    }
    i = world->actorCapacity;
    end = world->actorCount;
    actors = (LevelActor *)world->actors;
    for (; i < end; i++) {
        clipBox = &D_800FF208.max;
        rangeBox = &D_801031F0.max;
        actor = &actors[i];
        if (!(actor->flags & 0x100)) {
            continue;
        }
        definition = actor->definition;
        visible = 0;
        if (definition->gate & mask) {
            if (cull && !(actor->flags & 2) && actor->animationChanged == 0 &&
                !(actor->flags & 0x400) && definition->kind != 3) {
                if (definition->kind == 14) {
                    goto distance_visible;
                }
                if (!func_8024D160_de(actor)) {
                    if (ACTOR_OVERLAPS(actor, clipBox)) {
                        if (camera != 0) {
                            visible = VisData_TestBoxAgainstFrustum(camera->clipPlanes, &actor->bounds);
                        } else {
                            visible = 1;
                        }
                    }
                    goto visibility_ready;
                }
            }
            if (definition->kind == 14) {
            distance_visible:
                if (Sky_GetDistanceTo(camera, &actor->position0) < D_800C520C) {
                    visible = 1;
                }
            } else {
                visible = ACTOR_OVERLAPS(actor, rangeBox);
            }
        }
    visibility_ready:
        if (Cinema_IsSequenceInWindow() && D_800CD6E0_de) {
            if (!(definition->gate & 0x200)) {
                visible = 0;
            }
        } else if (!(definition->gate & 0x100) && definition->kind != 11 && definition->kind != 14) {
            visible = 0;
        }
        if (actor->flags < 0) {
            actor->flags |= 0x8000;
        } else {
            actor->flags &= ~0x8000;
        }
        if (visible) {
            actor->flags |= 0x80000000;
            if (definition->kind == 14) {
                continue;
            }
            func_8024B8C4_de(actor);
            if (func_8024D160_de(actor) && world->interactiveCount != 0x200) {
                world->interactive[world->interactiveCount++] = actor;
            }
            if (func_8024E1B4_de(actor) && world->moverCount != 0x80) {
                world->movers[world->moverCount++] = actor;
            }
            if (world->registeredCount < 0x80) {
                world->registered[world->registeredCount++] = actor;
            }
            if (world->kind1Count < 0x40 && actor->definition->kind == 1) {
                world->kind1[world->kind1Count] = actor;
                /* byte 0x23E of the word actionReady holds the slot */
                ((u8 *)&actor->actionReady)[2] = world->kind1Count++;
            }
            if (world->flaggedCount < 0x20 && (actor->flags & 2)) {
                world->flagged[world->flaggedCount++] = actor;
            }
            if (world->kind5Count < 0x10 && actor->definition->kind == 5) {
                world->kind5[world->kind5Count++] = actor;
            }
            if (world->model64FCount < 0x20 && actor->type == 0x64F) {
                world->model64F[world->model64FCount++] = actor;
            }
            if (actor->type == 0x64D && world->model64DCount < 4) {
                world->model64D[world->model64DCount++] = actor;
            }
        } else {
            actor->flags &= 0x7FFFFFFF;
            actor->flags &= ~0x200;
        }
    }
    AnimPool_UpdateSceneEffects((struct CAnimPool *)world->effectPool, world);
    world->kind1Cursor++;
    if (world->kind1Cursor >= world->kind1Count) {
        world->kind1Cursor = 0;
    }
}
#undef ACTOR_OVERLAPS

/* 800CA2FC.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80287F18_CAEFC[1] = {
    0x453B8000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80287F18_CAEFC_us_rev1.c */
const unsigned int D_blob_2dee24b4263488ecc3b2[1] = {
    0x453B8000,
};
#endif
