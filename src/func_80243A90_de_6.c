#include "span_1000/code_80243A80.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/world.h"
#include "span_16E000/code_80400000.h"
#include "types.h"

/* Starts the round once: unless already started, optionally resets the lead player (func_8022E290_de and its
 * three counters) and the player group, then when a new target id is pending selects it through
 * func_8044D3E8_de and func_80286AA8_de, records the start time from func_8040332C_de, marks the round started with
 * no pending target and copies the viewport rectangle into the active camera as floats. */













extern Group D_80145060;

extern struct { ObjRecAt2A8 *unk0; } D_80140FE8_de;

extern char D_8010EC90;

extern struct Shape_func_8021A2D4_de_2 D_801371D4;

extern struct Shape_func_8021A2D4_de_2 D_801371E4;

extern char D_801371E8;

extern struct Shape_func_8021A2D4_de_2 D_8013B2BC;

extern void func_8022E290_de(void *);

extern void func_80239B64_de(void *);

extern void func_80285D30_de(void *);

extern s32 func_8044D3E8_de(void *, Vec3Words *, s32, void *);

extern void func_80286AA8_de(void *, s32, s32);

extern s32 func_8040332C_de(void);

extern s32 func_80245784_de(void);

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

extern void func_80253838_de(void *arg0, void *arg1);

extern void func_8025476C_de(s32);

void func_80244E58_de(void) {
    extern func_80244E48_S1 *D_800E2830;
    Vec3Words origin;
    ObjRecAt2A8 *camera;
    Player *player;
    Group *group;
    s32 target;
    s32 found;
    Shared_World *table;

    target = D_800E2830->unkD8;
    if (D_800E2830->unk40 != 0) {
        return;
    }
    if (D_800E2830->unk54 != 0) {
        group = &D_80145060;
        player = group->lead;
        if (player != 0) {
            func_8022E290_de(player);
            player->weaponSpinStep = 0.0f;
            player->weaponSpin = 0.0f;
            player->weaponReset = 0;
        }
        func_80239B64_de(group->members);
        func_80285D30_de(&D_8010EC90);
    }
    if (target != -1) {
        table = &D_8011FE88;
        if (D_801371D4.field_0 != target) {
            origin.w[0] = 0;
            origin.w[1] = 0;
            origin.w[2] = 0;
            found = func_8044D3E8_de(table, &origin, target, &D_801371E8);
            D_8013B2BC.field_0 = found;
            D_801371E4.field_0 = found != 0;
            func_80286AA8_de(table, target, found != 0);
        }
    }
    D_800E2830->unk5C = func_8040332C_de();
    D_800E2830->unk50 = 1;
    D_800E2830->unkD8 = -1;
    D_800E2830->unk40 = 1;
    camera = D_80140FE8_de.unk0;
    if (camera != 0) {
        camera->unk29C = D_800E2830->unk108;
        camera->unk2A0 = D_800E2830->unk10C;
        camera->unk2A4 = D_800E2830->unk110;
        camera->unk2A8 = D_800E2830->unk114;
    }
}

s32 func_80244FB4_de(void) {
    extern Record_func_80244FB4_de *D_800E2830;
    s32 none;
    f32 value;
    f32 limit;
    Record_func_80244FB4_de *record;

    none = -1;
    if (D_800E2830->resource == none) {
        return 0;
    }
    func_804009F4_de(D_800E2830->resource);
    D_800E2830->resource = none;
    if (func_80245784_de() != 0) {
        if (func_80245850_de() != 0) {
            D_800E2830->previous = D_800E2830->value;
        } else {
            record = D_800E2830;
            record->previous = *(volatile f32 *)&record->value;
            record->value += D_800D2988 * D_800C37B0_de;
            if (record->threshold <= record->value) {
                func_80244E58_de();
            }
            value = D_800E2830->value;
            limit = D_800E2830->limit;
            if (limit <= value) {
                if (D_800E2830->mode == 1) {
                    D_800E2830->value = value - limit;
                } else {
                    D_800E2830->value = limit;
                    if (D_800E2830->active != 0) {
                        D_800E2830->done = 1;
                        D_800E2830->active = 0;
                    }
                }
            }
        }
    }
    func_80403458_de();
    return 1;
}

void func_802450CC_de(void) {
    extern Record108 *D_800E2830;
    Record108 *record;
    f32 value;
    f32 limit;

    if (D_800CB420_de == D_800D2978) {
        return;
    }
    D_800CB420_de = D_800D2978;
    if (func_80244FB4_de() == 0) {
        if (func_80245784_de() != 0) {
            if (func_80245850_de() != 0) {
                D_800E2830->previous = D_800E2830->value;
            } else {
                record = D_800E2830;
                record->previous = *(volatile f32 *)&record->value;
                record->value += D_800D2988 * 0.06666667f;
                if (record->threshold <= record->value) {
                    func_80244E58_de();
                }
                value = D_800E2830->value;
                limit = D_800E2830->limit;
                if (limit <= value) {
                    if (D_800E2830->mode == 1) {
                        D_800E2830->value = value - limit;
                    } else {
                        D_800E2830->value = limit;
                        if (D_800E2830->active != 0) {
                            D_800E2830->done = 1;
                            D_800E2830->active = 0;
                        }
                    }
                }
            }
        }
        func_80403458_de();
    }
    func_80244FB4_de();
    if (D_800E2830->fading != 0 && (D_800E2830->fade -= 2.0f * (D_800D2988 * 0.06666667f)) < -0.5f) {
        D_800E2830->fading = 0;
        D_800E2830->fade = 0.0f;
        if (func_80245784_de() != 0) {
            func_80245B74_de(1);
            func_80245BC0_de();
            if (D_800E2830->sound != 0) {
                func_80253838_de(0, D_800E2830->sound);
            }
            D_800E2830->sound = 0;
            D_800E2830->unk_4 = 0;
            D_800E2830->playing = 0;
            D_800E2830->done = 0;
            D_800E2830->fading = 0;
        }
        return;
    }
    func_80244FB4_de();
    if (func_80245784_de() != 0 && func_80245850_de() == 0 && D_80140FB4.busy == 0 && D_80140FB4.paused == 0 &&
        D_800E2830->mode == 0) {
        if (D_800E2830->value >= D_800E2830->cue && D_800E2830->cueFired == 0) {
            FuncPtr cue = D_800E2830->onCue;

            if (cue != 0) {
                D_800E2830->onCue = 0;
                cue();
            }
            D_800E2830->cueFired = 1;
        }
        if (D_800E2830->value >= D_800E2830->limit && D_800E2830->endFired == 0) {
            if (D_800E2830->sound != 0) {
                func_80253838_de(0, D_800E2830->sound);
            }
            {
                FuncPtr end = D_800E2830->onEnd;

                D_800E2830->sound = 0;
                D_800E2830->unk_4 = 0;
                D_800E2830->playing = 0;
                D_800E2830->done = 0;
                D_800E2830->fading = 0;
                if (end != 0) {
                    D_800E2830->onEnd = 0;
                    end();
                }
            }
            D_800E2830->endFired = 1;
        }
    }
    func_80244FB4_de();
    if (D_800E2830->playing != 0) {
        func_8025476C_de(0xA);
    }
}
