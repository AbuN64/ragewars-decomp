#include "span_1000/code_802661FC.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "span_1000/code_80275E44.h"
#include "types.h"
#include "span_1000/code_80204E78.h"

                                                                                             





                                                                                             





extern void func_8024E79C_de(void *arg0, Triple input, Triple *output,
                          s32 *value, s32 unused0, s32 unused1);

extern f32 func_8024BEDC_de(void *arg0);

extern s32 D_80146894;


/* Forwards the actor, event value and three-component input with a zero final flag. */


extern void func_80271FC8_de(Vec3 *arg0, f32 t, void *a, void *b);

extern f32 func_8024D284_de(void *arg0);

/* Decides whether one actor may affect another: always when the override D_801462E5 is set; never for actors of the same kind or a target lacking flags 0x310000, nor, while D_8013B290 is set, when neither actor carries 0x300000; otherwise only when the target is in state 1, 4, 7 or 11. */

extern u8 D_801462E5;

extern s32 D_8013B290;

void func_80267198_de(void *arg0, void *arg1, s32 arg2, Vec3 arg3, ResourceManagerState arg6) {
    extern CallbackEntryRecAt4V1 D_800CC130[];
    if (D_800CC130[arg2].callback != 0) {
        D_800CC130[arg2].callback(arg0, arg1, arg2, arg3, arg6);
    }
}

void func_802671FC_de(void *arg0, void *arg1, s32 arg2, Vec3 arg3, ResourceManagerState arg6) {
    extern CallbackEntryRecAt4V2 D_800CC130[];
    if (D_800CC130[arg2].callback != 0) {
        D_800CC130[arg2].callback(arg0, arg1, arg2, arg3, arg6);
    }
}

void func_80267260_de(void *arg0, Triple input, s32 arg4) {
    Triple output;
    s32 value;

    func_8024E79C_de(arg0, input, &output, &value, 0, 0);
    if (arg4 != 0) {
        func_80276184_de((void *)value);
    } else {
        func_802761B8_de((void *)value);
    }
}

f32 func_802672D0_de(u8 *arg0) {
    if (*arg0 == 1) {
        return func_8024BEDC_de(arg0);
    } else {
        return D_800C4420_de;
    }
}

void func_8026730C_de(s32 arg0, ObjectRecAtD0 *arg1, s32 arg2, Vec3 arg3,
                   Clip arg6) {
    s32 *global = &D_80146894;
    s32 selected;
    f32 scale;

    scale = D_800C4424_de;
    selected = -1;
    if (global[0] != 0) {
        return;
    }

    if (arg1 != 0) {
        switch (arg1->type) {
        case 1:
            if (*arg1->kind == arg1->type) {
                if (global[-371] & 0x40) {
                    scale = D_800C4428_de;
                } else if (global[-371] & 0x20) {
                    scale = D_800C442C_de;
                }
            }
            selected = (s32)arg1;
            break;
        case 0:
            selected = arg1->value;
            break;
        case 2:
            selected = (s32)arg1;
            break;
        }
    }

    func_8025DEC0_de(arg6.frames, arg3, 0, selected, scale);
}

void func_802673EC_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 *p = &arg3;
    func_8025E11C_de(p[3]);
}

void func_8026740C_de(void *actor,int unused1,int unused2,Triple input,int event) {
 func_80216288_de(actor,event,input,0);
}

s32 func_80267444_de(void *arg0, Vec3 *arg1) {
    Vec3 first;
    Vec3 second;
    LevelActor *object = arg0;
    Shared_ActorView *actor;
    s16 state;
    s32 result;

    result = 0;
    if ((object->kind == 1) &&
        ((object->flags & 0x300000) != 0)) {
        actor = object->controller;
        if (arg0 == &actor->weapon) {
            state = actor->selectedAction;
            if ((state == 0) || (state == 0x11) || (state == 0x10)) {
                first = *arg1;
                second = ((LevelActor *)actor)->position0;
                func_80271FC8_de(arg1, 0.75f, &first, &second);
                arg1->y += func_8024D284_de(actor) * D_800C4430_de;
                result = 1;
            }
        }
    }
    return result;
}

s32 func_80267528_de(char *actor, char *target)
{
    LevelActor *source = (LevelActor *)actor;
    LevelActor *destination = (LevelActor *)target;
    s32 flags;

    if (D_801462E5 != 0) {
        return 1;
    }
    if (source->type == destination->type) {
        return 0;
    }
    flags = destination->flags;
    if (!(flags & 0x310000)) {
        return 0;
    }
    if (D_8013B290 != 0 && !(source->flags & 0x300000) && !(flags & 0x300000)) {
        return 0;
    }
    switch (*destination->definition) {
    case 1:
    case 4:
    case 7:
    case 11:
        return 1;
    }
    return 0;
}
