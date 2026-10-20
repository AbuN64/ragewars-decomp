#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/UNSIGNED_QUOTIENT.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/TRIPLE.H"
#include "RENDER/80291054_4.H"
#include "RENDER/80291054_9.H"
#include "SCENE/802508E0_8.H"


#if defined(VERSION_DE)
extern f32 D_800C5470;
#endif
static inline u32 averageFour(void) {
 s32 sum;
 s32 maximum;
 sum=D_80142CA4+D_8011B9F8+D_801428AC+D_80142C34;
 maximum=D_80142C34;
 if((u32)maximum<D_801428AC)maximum=D_801428AC;
 if((u32)maximum<D_8011B9F8)maximum=D_8011B9F8;
 if((u32)maximum<D_80142CA4)maximum=D_80142CA4;
 { s32 adjusted=maximum-2; return ((u32)sum-(u32)adjusted)/3; }
}
static inline s32 idlePause(TimingWorld *arg0) {
 if(func_80442A28_de(&D_8014561C)==0 && func_80245798_de()!=0 && func_80245B0C_de()==120) {
 if(D_80142868==0) {
 if(arg0->unk26DD4==0) { D_80142868=1;func_804037D4_de(); }
 goto checkFlag;
 }
 goto active;
 }
 checkFlag:
 if(D_80142868!=0) {
 active:
 if(func_80245850_de()!=0) return 1;
 }
 return 0;
}
/* Update the frame timestep, render the frame, and advance the session mode. */
void Render_UpdateFrameTiming(TimingWorld *arg0) {
    f32 temp_fs0;
    f32 var_fv0f;
    s32 temp_a2;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_v0_2;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1_8;
    u32 temp_a1;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_v1;
    u32 var_v1_2;
    u32 var_v1_3;
    u32 var_v1_4;
    u32 var_v1_5;
    u32 var_v1_6;
    u32 var_v1_7;
    u64 temp_ret;
    u64 temp_ret_2;
    u64 temp_v0;

    temp_ret = func_802BADC0_de();
    temp_ret_2 = func_802C0DA0_de((temp_ret-D_801428A0)<<6,3000);
#if defined(VERSION_DE)
    temp_fs0 = (f32)temp_ret_2 * D_800C546C * D_800C5470;
#else
    temp_fs0 = (f32)temp_ret_2 * D_800C546C * D_800CA560;
#endif
    D_801428A0 = temp_ret;
    if (func_802A23B4_de() == 0) {
        if (func_802934F8_de() == 0) {
            arg0->unk26DD4 = 0;
        } else {
            arg0->unk26DD4 = func_80442A28_de(&arg0->viewport.self.messageList.head);
        }
    }
    if (D_80154048 != 0) {
        var_v1 = arg0->unk26DB8;
        if (var_v1 == 0xB) {
            arg0->unk26DD4 = 1;
            goto block_10;
        }
    } else {
block_10:
        var_v1 = arg0->unk26DB8;
    }
 switch(var_v1) { case 1: case 3: case 4: {
 D_801428A8=averageFour()>1 ? averageFour():2;
 break; } default: {
 D_801428A8=averageFour()>1 ? averageFour():2;
 if(func_80245798_de()!=0) {
 if((u32)(arg0->unk26DB8-16)<2 && D_800E28D4<223) {
 D_801428A8=averageFour()>1 ? averageFour():2;
 } else {
 D_801428A8=averageFour()>3 ? averageFour():4;
 }
 }
 }
 }
    D_800D2988 = (f32) (D_801428A8 * 0xF) / D_80142C38[1];
    if (func_80245798_de() != 0) {
        D_800D2988 = temp_fs0;
    }
#if defined(VERSION_DE)
    if (func_80245798_de() != 0) {
        D_800D2988 = D_800D2988 * D_800CA560;
    }
#endif
    func_80253344_de(0);
    D_80146CD8 = D_8011BDC0;
    func_80292308_de(arg0);
    arg0->unk26DB0 = arg0->unk26DB0 + D_800D2988;
    func_80293C34_de(arg0);
    var_v1_8=idlePause(arg0);
    if ((var_v1_8 != 0) && (arg0->unk26DB8 != 0x10) && (arg0->unk26DBC != 0x10)) {
        arg0->unk26DC1 = 2;
        arg0->unk26DBC = 0x10;
    }
}
