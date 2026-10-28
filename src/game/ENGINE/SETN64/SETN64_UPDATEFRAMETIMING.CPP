#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"
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
static inline s32 idlePause(TimingWorld *world) {
 if(Menu_CountLiveNodes(&D_8014561C)==0 && Cinema_IsSequenceInWindow()!=0 && Cinema_GetSequenceRequest()==120) {
 if(D_801462C8.counters.first==0) {
 if(world->unk26DD4==0) { D_801462C8.counters.first=1;func_804037D4_de(); }
 goto checkFlag;
 }
 goto active;
 }
 checkFlag:
 if(D_801462C8.counters.first!=0) {
 active:
 if(func_80245850_de()!=0) return 1;
 }
 return 0;
}
/* Update the frame timestep, render the frame, and advance the session mode. */
void SetN64_UpdateFrameTiming(TimingWorld *world) {
    f32 scaledFrameTime;
    f32 var_fv0f;
    s32 temp_a2;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_v0_2;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    s32 var_v0_2;
    s32 idle;
    u32 temp_a1;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 sessionMode;
    u32 var_v1_2;
    u32 var_v1_3;
    u32 var_v1_4;
    u32 var_v1_5;
    u32 var_v1_6;
    u32 var_v1_7;
    u64 nowTicks;
    u64 elapsedUnits;
    u64 temp_v0;

    nowTicks = Audio_ReadSystemTime();
    elapsedUnits = __udivdi3((nowTicks-D_801428A0)<<6,3000);
#if defined(VERSION_DE)
    scaledFrameTime = (f32)elapsedUnits * D_800C546C * D_800C5470;
#else
    scaledFrameTime = (f32)elapsedUnits * D_800C546C * D_800CA560;
#endif
    D_801428A0 = nowTicks;
    if (Tsmos_IsFrontendActive() == 0) {
        if (SetN64_IsModeThirteen() == 0) {
            world->unk26DD4 = 0;
        } else {
            world->unk26DD4 = Menu_CountLiveNodes(&world->viewport.self.messageList.head);
        }
    }
    if (D_80154048 != 0) {
        sessionMode = world->unk26DB8;
        if (sessionMode == 0xB) {
            world->unk26DD4 = 1;
            goto block_10;
        }
    } else {
block_10:
        sessionMode = world->unk26DB8;
    }
 switch(sessionMode) { case 1: case 3: case 4: {
 D_801428A8=averageFour()>1 ? averageFour():2;
 break; } default: {
 D_801428A8=averageFour()>1 ? averageFour():2;
 if(Cinema_IsSequenceInWindow()!=0) {
 if((u32)(world->unk26DB8-16)<2 && D_800E28D4<223) {
 D_801428A8=averageFour()>1 ? averageFour():2;
 } else {
 D_801428A8=averageFour()>3 ? averageFour():4;
 }
 }
 }
 }
    D_800D2988 = (f32) (D_801428A8 * 0xF) / D_80142C38[1];
    if (Cinema_IsSequenceInWindow() != 0) {
        D_800D2988 = scaledFrameTime;
    }
#if defined(VERSION_DE)
    if (Cinema_IsSequenceInWindow() != 0) {
        D_800D2988 = D_800D2988 * D_800CA560;
    }
#endif
    Cache_RunCompactionPasses(0);
    D_80146CD8 = D_8011FAC0.ring.current;
    SetN64_BuildAndSubmitSessionFrame(world);
    world->unk26DB0 = world->unk26DB0 + D_800D2988;
    SetN64_AdvanceGameClock(world);
    idle=idlePause(world);
    if ((idle != 0) && (world->unk26DB8 != 0x10) && (world->unk26DBC != 0x10)) {
        world->unk26DC1 = 2;
        world->unk26DBC = 0x10;
    }
}
