#include "span_1000/code_80200610.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_802022E0.h"
#include "span_1000/code_80206258.h"
#include "span_1000/code_80271B18.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "types.h"


void func_80203278_de(SharedPlayer *player, RiderRecAt130V1 *rider, Result *result);

void func_80272BCC_de(void *arg0, void *arg1, void *arg2);

void func_80202FDC_de(struct Owner *owner, Rider *rider, s32 mode, char *target);

void func_802172D0_de(void *arg0, void *arg1, s32 arg2);

void func_80217388_de(void *arg0, void *arg1);

f32 func_80274808_de(f32 arg0, f32 arg1, f32 arg2);

typedef union NavRider { RiderRecAt130V1 target; Rider rider; struct { char pad0[0x9C]; f32 heading; char padA0[0x124-0xA0]; f32 speed; char pad128[8]; Vec3 aim; } nav; } NavRider;

/* Callers reserve a 136-byte result workspace shared by both target searches. */
typedef union NavResult { Result result; Output80216D3C output; struct { s32 kind; void *target; f32 projection; char padC[0x88-0xC]; } workspace; } NavResult;

static inline void navProject(f32 *matrix,Vec3 *local,Vec3 *out,Vec3 *to,Vec3 *from) { func_80271F68_de(local,to,from); func_80272BCC_de(matrix,local,out); }

static inline void navRotation(Vector4f *q,Vec3 *aim) {
    extern Vector4f func_80202CA0_de(Vec3 *dir); ((void (*)(Vector4f *,Vec3 *))func_80202CA0_de)(q,aim); }

typedef struct NavWork {
    NavResult result;
    NavVec origin,destination,relative;
    f32 matrix[16];
    NavVec local;
    Vector4f rotation;
    NavVec aim;
    f32 heading;
} NavWork;

/* Installs a weapon record's handler table and routine pointers and, when its owner's id is 0x40C,
   clears its counters and sets its rate to 200 and its range and speed from D_800C6B2C and D_800C6B30. */










extern s32 func_80285F58_de(void *, void *);

/** Run the object's update hook, then advance its timer and fire the expiry action when due. */



typedef struct Owner Owner;

s32 func_802034A4_de(NavActor *arg0,NavRider *arg1) {
    NavWork work;
    SharedPlayer *temp_s6;
    f32 temp_fs1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv1;
    f32 var_fs0;
    f32 var_fs0f;
    s32 var_condition_bit;
    s32 var_s7;
    u16 temp_v1;
    u8 var_a2;
    SegmentRecAt71 *temp_s4;

    var_s7 = 0;
    temp_s4 = &arg0->player.views18.navigationTrack->segment;
    work.heading = arg0->player.views1C.view6C_4.unk6C - arg1->nav.heading;
    func_80274020_de(&work.heading);
    temp_v1 = arg0->player.views1C.viewE4_6.unkE4;
    switch (temp_v1) {                              /* irregular */
    case 0x40B:
        func_80216D3C_de(&arg0->input, arg1, &work.result.output, 0, 1);
        break;
    case 0x40C:
        func_80203278_de(&arg0->player,&arg1->target,&work.result.result);
        break;
    }
    temp_s6 = arg1->target.target;
    if ((temp_s6 != NULL) && (work.result.result.distance <= temp_s4->distanceLimit)) {
        temp_fs1 = D_800C1A28;
        work.origin.v=arg0->player.views0.view8_2.unk8;
        var_fs0f=func_8024D284_de(&arg0->player);
        work.origin.v.y+=var_fs0f*temp_fs1;
        work.destination.v=temp_s6->views0.view8_2.unk8;
        var_fs0f=func_8024D284_de(temp_s6);
        work.destination.v.y+=var_fs0f*temp_fs1;
        work.aim.v.x = arg1->nav.aim.x;
        work.aim.v.y = arg1->nav.aim.y;
        work.aim.v.z = arg1->nav.aim.z;
        /* SN64 struct-return ABI writes directly to the caller-supplied Vector4f. */
        navRotation(&work.rotation,&work.aim.v);
        func_80274244_de(&work.rotation.x,work.matrix);
        navProject(work.matrix,&work.local.v,&work.destination.v,&work.destination.v,&work.origin.v);
        func_80271F34_de(&work.destination.v, &work.destination.v, &work.origin.v);
        func_80271F68_de(&work.relative.v, &work.destination.v, &work.origin.v);
        var_fs0f = func_802725FC_de(&work.relative.v.x);
        var_fs0 = func_80216F44_de(&arg0->actor,work.destination.v);
        work.result.workspace.projection = var_fs0;
        if (work.result.result.distance <= temp_s4->range) {
            temp_fv0f = temp_s4->tolerance * temp_fs1;
            if (var_fs0 < 0.0f) {
                if (!(-var_fs0 < temp_fv0f)) {

                } else {
                    goto block_12;
                }
            } else if (var_fs0 < temp_fv0f) {
block_12:
                var_s7 = 1;
            }
        }
        temp_fv0f_2 = temp_s4->limit;
        if (temp_fv0f_2 < D_800C1A2C) {
            temp_fv0 = temp_fv0f_2 * D_800C1A30;
            temp_fv1 = work.heading + var_fs0;
            if (temp_fv0 < temp_fv1) {
                var_fs0 = temp_fv0 - work.heading;
            } else {
                temp_fv0_2 = -temp_fv0;
                if (temp_fv1 < temp_fv0_2) {
                    var_fs0 = temp_fv0_2 - work.heading;
                }
            }
        }
        func_80202FDC_de(&arg0->owner,&arg1->rider,temp_s4->activeMode,(void*)temp_s6);
    } else {
        var_fs0f = 0.0f;
        
        var_fs0 = -work.heading;
        func_80202FDC_de(&arg0->owner,&arg1->rider,temp_s4->inactiveMode,(void*)temp_s6);
    }

    if(var_fs0<0.0f) {
        if(D_800C1A34_de < -var_fs0) goto changed;
    } else if(D_800C1A38_de < var_fs0) goto changed;
    if(arg1->nav.speed != var_fs0f) {
changed:
        func_802172D0_de(arg0,arg1,0xC3F);
    } else func_80217388_de(arg0,arg1);
    /* The second ABI word is the actual rider pointer, used as such by this callee. */
    ((void (*)(void *,void *,f32,f32))func_80216808_de)(arg0,arg1, temp_s4->rate, var_fs0);
    arg1->nav.speed = func_80274808_de(arg1->nav.speed, var_fs0f, temp_s4->rate);
    return var_s7;
}

s32 func_80203848_de(s32 arg0, s32 arg1, struct RotationObject *arg2) {
    extern void func_80202CA0_de(s32, f32 *);
    f32 sp10[3];

    sp10[0] = arg2->angleX;
    sp10[1] = arg2->angleY;
    sp10[2] = arg2->angleZ;
    func_80202CA0_de(arg0, sp10);
    return arg0;
}

void func_8020388C_de(struct OwnerRecAtE4 *owner, struct RecordRecAt13C *record)
{
    extern f32 D_800C6B30;
    record->table = D_800C8170_de;
    record->first = D_002039F8;
    record->second = D_00203E78;
    record->third = D_00202E4C;
    record->fourth = D_00203DF0;
    if (owner->id == 0x40C) {
        record->a = 0;
        record->b = 0;
        record->fourth = D_00203DF0;
        record->rate = 0xC8;
        record->c = 0;
        record->range = D_800C6B2C;
        record->speed = D_800C6B30;
    }
}

void func_80203908_de(LevelActor *arg0, struct RecordRecAt13C *arg1) {
    extern s32 func_80214178_de(void *, void *, s32);
    extern f32 D_800C6B30[];
    s32 flags;
    ActorMotionDefinition *record;

    record = &((ActorMotionResource *)arg0->definition)->motion;
    if (arg0->type == 0x40C) {
        arg1->speed = D_800C6B30[1];
    } else {
        arg1->speed = 0.0f;
    }
    arg1->pad128 = 0;
    arg1->threshold = record->eventThreshold;

    if (func_80285F58_de(&D_8011FE88, arg0) == 0) {
        if (record->flags & 0x1000) {
            flags = arg0->flags & ~0x2000;
            flags = flags & ~0x100;
            arg0->flags = flags;
        }
        if (record->flags & 0x800) {
            arg0->flags =
                arg0->flags & ~0x100;
            func_80214178_de(arg0, arg1, 0);
        } else {
            func_80214178_de(arg0, arg1, 1);
        }
    } else {
        func_80214178_de(arg0, arg1, 0x40);
    }
    arg1->state = 0;
}

void func_802039F8_de(char *arg0, Obj *arg1) {
    extern void func_80214178_de(void *, void *, int);
    if (arg1->hook != 0 && arg1->hook->fn != 0) {
        arg1->hook->fn(arg0, arg1);
    }
    if (((struct OwnerRecAtE4 *)(arg0))->id == 0x40C) {
        arg1->timer += D_800D2988;
        if (D_800C1A48_de < arg1->timer || arg1->count <= 0) {
            func_80214178_de(arg0, arg1, 0x40);
        }
    }
}

/** Return the nested record's field, or a fallback constant when zero. */
int func_80203A94_de(void *arg0) {
    int temp = ((struct MenuRules *) ((Owner *) arg0)->track)->locked;
    if (temp != 0) {
        return temp;
    }
    return 0x2F44;
}

void func_80203AB0_de(void *a, struct WeaponEventSource *b) {
    extern void func_80214178_de(void *a, void *b, int c);
    if (b->eventEnabled != 0) {
        func_80214178_de(a, b, 0x3E);
    }
}
