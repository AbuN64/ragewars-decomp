#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/GROUP.H"
#include "CAMERA/80243A80.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "TYPES.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "CAMERA/80243A80_6.H"
#include "MENU_2/80400000_4.H"
#include "MENU_2/80400000_7.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

/* Starts the round once: unless already started, optionally resets the lead player (func_8022E290_de and its
 * three counters) and the player group, then when a new target id is pending selects it through
 * func_8044D3E8_de and Scene_LoadLevelResources, records the start time from func_8040332C_de, marks the round started with
 * no pending target and copies the viewport rectangle into the active camera as floats. */













extern Group D_80145060;

extern struct { struct GameplayCamera *unk0; } D_80140FE8_de;

extern char D_8010EC90;

extern struct Shape_func_8021A2D4_de_2 D_801371D4;

extern struct Shape_func_8021A2D4_de_2 D_801371E4;

extern char D_801371E8;

extern struct Shape_func_8021A2D4_de_2 D_8013B2BC;

extern void func_8022E290_de(void *);

extern void func_80239B64_de(void *);

extern void Rumble_FreeAllPoolNodes(void *);

extern s32 OvlScene_FindNearestPlacedObject(void *, Vec3Words *, s32, void *);

extern void Scene_LoadLevelResources(void *, s32, s32);

extern s32 func_8040332C_de(void);


extern u32 func_80245850_de(void);

extern f32 D_800D2988;

/* Advances the current audio cue once per new frame: when func_80244FB4_de has no resource to release, the
 * cue's position steps by the frame time (as func_80245C38_de, stopping the round via func_80244E58_de past its
 * threshold and looping or holding at its length) and func_80403458_de runs; a fading cue loses twice the
 * frame's fade step and, once below -0.5, stops fading and, if playing, runs its start and stop callbacks
 * (func_80245B74_de, func_80245BC0_de) and releases its sound; otherwise a playing, unpaused, non-looping cue with
 * no pending game event fires its cue callback past its cue point and, past its length, releases its sound
 * and fires its end callback; a still-playing cue then refreshes channel 10 through func_8025476C_de. */
typedef void (*FuncPtr)(void);

extern s32 D_800D2978;

extern GameState D_80140FB4;

extern void func_80245BC0_de(void);


extern void func_8025476C_de(s32);

void func_80244E58_de(void) {
    Vec3Words origin;
    struct GameplayCamera *camera;
    Player *player;
    Group *group;
    s32 target;
    s32 found;
    Shared_World *table;

    target = D_800E2830->targetD8;
    if (D_800E2830->unknown40 != 0) {
        return;
    }
    if (D_800E2830->pending != 0) {
        group = &D_80145060;
        player = group->lead;
        if (player != 0) {
            func_8022E290_de(player);
            player->weaponSpinStep = 0.0f;
            player->weaponSpin = 0.0f;
            player->weaponReset = 0;
        }
        func_80239B64_de(group->members);
        Rumble_FreeAllPoolNodes(&D_8010EC90);
    }
    if (target != -1) {
        table = &g_world;
        if (D_801371D4.field_0 != target) {
            origin.w[0] = 0;
            origin.w[1] = 0;
            origin.w[2] = 0;
            found = OvlScene_FindNearestPlacedObject(table, &origin, target, &D_801371E8);
            D_8013B2BC.field_0 = found;
            D_801371E4.field_0 = found != 0;
            Scene_LoadLevelResources(table, target, found != 0);
        }
    }
    D_800E2830->unknown5C = func_8040332C_de();
    D_800E2830->field50 = 1;
    D_800E2830->targetD8 = -1;
    D_800E2830->unknown40 = 1;
    camera = D_80140FE8_de.unk0;
    if (camera != 0) {
        camera->viewWidth = D_800E2830->unknown104[1];
        camera->viewHeight = D_800E2830->unknown104[2];
        camera->viewLeft = D_800E2830->unknown104[3];
        camera->viewTop = D_800E2830->unknown104[4];
    }
}

s32 func_80244FB4_de(void) {
    s32 none;
    f32 value;
    f32 limit;
    Shared_MenuContext *record;

    none = -1;
    if (D_800E2830->resourceDC == none) {
        return 0;
    }
    func_804009F4_de(D_800E2830->resourceDC);
    D_800E2830->resourceDC = none;
    if (Cinema_IsSequenceActive() != 0) {
        if (func_80245850_de() != 0) {
            D_800E2830->time20 = D_800E2830->time;
        } else {
            record = D_800E2830;
            record->time20 = *(volatile f32 *)&record->time;
            record->time += D_800D2988 * D_800C37B0_de;
            if (record->start <= record->time) {
                func_80244E58_de();
            }
            value = D_800E2830->time;
            limit = D_800E2830->clipEnd;
            if (limit <= value) {
                if (D_800E2830->unknown104[0] == 1) {
                    D_800E2830->time = value - limit;
                } else {
                    D_800E2830->time = limit;
                    if (D_800E2830->fieldB4 != 0) {
                        D_800E2830->state3C = 1;
                        D_800E2830->fieldB4 = 0;
                    }
                }
            }
        }
    }
    func_80403458_de();
    return 1;
}

void func_802450CC_de(void) {
    Shared_MenuContext *record;
    f32 value;
    f32 limit;

    if (D_800CB420_de == D_800D2978) {
        return;
    }
    D_800CB420_de = D_800D2978;
    if (func_80244FB4_de() == 0) {
        if (Cinema_IsSequenceActive() != 0) {
            if (func_80245850_de() != 0) {
                D_800E2830->time20 = D_800E2830->time;
            } else {
                record = D_800E2830;
                record->time20 = *(volatile f32 *)&record->time;
                record->time += D_800D2988 * 0.06666667f;
                if (record->start <= record->time) {
                    func_80244E58_de();
                }
                value = D_800E2830->time;
                limit = D_800E2830->clipEnd;
                if (limit <= value) {
                    if (D_800E2830->unknown104[0] == 1) {
                        D_800E2830->time = value - limit;
                    } else {
                        D_800E2830->time = limit;
                        if (D_800E2830->fieldB4 != 0) {
                            D_800E2830->state3C = 1;
                            D_800E2830->fieldB4 = 0;
                        }
                    }
                }
            }
        }
        func_80403458_de();
    }
    func_80244FB4_de();
    if (D_800E2830->unknown60 != 0 && (D_800E2830->fade -= 2.0f * (D_800D2988 * 0.06666667f)) < -0.5f) {
        D_800E2830->unknown60 = 0;
        D_800E2830->fade = 0.0f;
        if (Cinema_IsSequenceActive() != 0) {
            func_80245B74_de(1);
            func_80245BC0_de();
            if (D_800E2830->owner != 0) {
                Cache_ReleaseResource(0, D_800E2830->owner);
            }
            D_800E2830->owner = 0;
            D_800E2830->resource = 0;
            D_800E2830->active = 0;
            D_800E2830->state3C = 0;
            D_800E2830->unknown60 = 0;
        }
        return;
    }
    func_80244FB4_de();
    if (Cinema_IsSequenceActive() != 0 && func_80245850_de() == 0 && D_80140FB4.busy == 0 && D_80140FB4.paused == 0 &&
        D_800E2830->unknown104[0] == 0) {
        if (D_800E2830->time >= D_800E2830->end && D_800E2830->initialized44 == 0) {
            FuncPtr cue = D_800E2830->callback10;

            if (cue != 0) {
                D_800E2830->callback10 = 0;
                cue();
            }
            D_800E2830->initialized44 = 1;
        }
        if (D_800E2830->time >= D_800E2830->clipEnd && D_800E2830->closed == 0) {
            if (D_800E2830->owner != 0) {
                Cache_ReleaseResource(0, D_800E2830->owner);
            }
            {
                FuncPtr end = D_800E2830->onClose;

                D_800E2830->owner = 0;
                D_800E2830->resource = 0;
                D_800E2830->active = 0;
                D_800E2830->state3C = 0;
                D_800E2830->unknown60 = 0;
                if (end != 0) {
                    D_800E2830->onClose = 0;
                    end();
                }
            }
            D_800E2830->closed = 1;
        }
    }
    func_80244FB4_de();
    if (D_800E2830->active != 0) {
        func_8025476C_de(0xA);
    }
}
