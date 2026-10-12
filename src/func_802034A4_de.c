#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_802022E0.h"
#include "span_1000/code_80271B18.h"
#include "stddef.h"
#include "types.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
extern f32 D_800C1A28,D_800C1A2C,D_800C1A30,D_800C1A34_de,D_800C1A38_de;
void func_80203278_de(SharedPlayer *player, Rider_func_80203278_de *rider, Result *result);
Vector4f func_80202CA0_de(Vec3 *dir);
void func_80272BCC_de(void *arg0, void *arg1, void *arg2);
void func_80202FDC_de(struct Owner *owner, Rider *rider, s32 mode, char *target);
void func_802172D0_de(void *arg0, void *arg1, s32 arg2);
void func_80217388_de(void *arg0, void *arg1);
f32 func_80274808_de(f32 arg0, f32 arg1, f32 arg2);
typedef union NavRider { Rider_func_80203278_de target; Rider rider; struct { char pad0[0x9C]; f32 heading; char padA0[0x124-0xA0]; f32 speed; char pad128[8]; Vec3 aim; } nav; } NavRider;
/* Callers reserve a 136-byte result workspace shared by both target searches. */
typedef union NavResult { Result result; Output80216D3C output; struct { s32 kind; void *target; f32 projection; char padC[0x88-0xC]; } workspace; } NavResult;
static inline void navProject(f32 *matrix,Vec3 *local,Vec3 *out,Vec3 *to,Vec3 *from) { func_80271F68_de(local,to,from); func_80272BCC_de(matrix,local,out); }

static inline void navRotation(Vector4f *q,Vec3 *aim) { ((void (*)(Vector4f *,Vec3 *))func_80202CA0_de)(q,aim); }
typedef struct NavWork {
    NavResult result;
    NavVec origin,destination,relative;
    f32 matrix[16];
    NavVec local;
    Vector4f rotation;
    NavVec aim;
    f32 heading;
} NavWork;
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
    Segment_func_80203278_de *temp_s4;

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
