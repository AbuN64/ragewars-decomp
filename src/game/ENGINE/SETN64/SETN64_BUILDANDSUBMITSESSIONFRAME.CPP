#include "TYPES.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/GFX.H"
#include "gbi.h"

/* Builds and submits the current frame, records its timing, and advances the fade transition. */
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/GROUP.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/FRUSTUM.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/TRIPLE.H"
#include "CAMERA/CCINEMA_UPDATESEQUENCE.H"
#include "FRONTEND/SCREEN_VIDEO_MODE.H"
#include "RENDER/SETN64.H"
#include "RENDER/SETN64_BUILDANDSUBMITSESSIONFRAME.H"
#include "SCENE/CACHE_ALLOCATERESOURCEAT.H"
#include "SYSTEM/TEXTLOAD_RESETTEXTURECACHE.H"
#include "SYSTEM/DEFS_TOGGLESAVEDFLAG.H"
#include "sdk/os.h"
extern void Camera_UpdateViewportLayoutAndBounds(RaceViewportState *);
extern void SetN64_DrawColorRectangle(void *, u8 *, s32,s32,s32,s32);
extern void SetN64_ClearDepthRect(void *, s32,s32,s32,s32,s32);
extern void SetN64_SubmitFrameTasks(TimingWorld *,Frame *);
static __inline__ s32 hasFadeMode(u8 *mode) { return *mode != 0; }
void SetN64_BuildAndSubmitSessionFrame(TimingWorld *world) {
    u8 color[4];
    void (*draw)(TimingWorld *);
    f32 updatedFade;
    f32 fadeLimit;
    f32 fade;
    f32 step;
    f32 speed;
    f32 fadeOutSpeed;
    f32 nextFade;
    f32 elapsed;
    s32 alpha;
    u32 previousMode;
    u32 listBytes;
    u32 maxListBytes;
    u64 start;
    u64 end;
    u64 duration;
    u64 startTime;
    u8 fadeMode;

    start = Audio_ReadSystemTime();
    previousMode = (u32) start;
    startTime = start;
    D_80146CD8 = D_8011FAC0.ring.current;
    Cache_SelectResourceSlot(0, D_800D297C);
    TextLoad_ResetTextureCache();
    Geometry_InitializeModelRenderState();
    SetN64_BeginFrameDisplayList(world);
    Defs_ToggleSavedFlag();
    Control_TrackControllerPakChanges();
    Camera_UpdateViewportLayoutAndBounds(&world->viewport);
    SetN64_CommitSessionInputs(world);
    draw = D_800CD790[world->unk26DB8].draw;
    if (draw != 0) {
        draw(world);
    }
    if (D_80146CD8->dual == 0) {
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        fadeLimit = world->fade;
        alpha = 0xFF;
        if (!(fadeLimit < 0.0f)) {
            alpha = 0;
            if (!(D_800C5448 < fadeLimit)) {
                alpha = 0xFF;
                if (!(fadeLimit < 0.0f)) {
                    alpha = ~(s32) (fadeLimit * D_800C544C);
                }
            }
        }
        color[3] = alpha;
        SetN64_DrawColorRectangle(world, &color[0], 0, 0, D_800E28D0, D_800E28D4);
    }
    if (D_800E28E0 != 0) {
        if (D_800E28E0 == 0x14) {
            Frontend_AdvanceVideoMode();
        }
        SetN64_ClearDepthRect(world, 0, 0x1E0, 0, 0x168, 0);
        gDPSetScissorFrac(g_displayListCursor++,0,0,0,0x77C,0x59C);
        gDPSetColorImage(g_displayListCursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,480,D_80146CD8->colorImage);
        gDPSetCycleType(g_displayListCursor++,G_CYC_FILL);
        gDPSetCombineLERP(g_displayListCursor++,0,0,0,SHADE,0,0,0,SHADE,0,0,0,SHADE,0,0,0,SHADE);
        gDPSetRenderMode(g_displayListCursor++,G_RM_NOOP,G_RM_NOOP2);
        gDPSetFillColor(g_displayListCursor++,0x10001);
        gDPFillRectangle(g_displayListCursor++,0,0,480,360);
        D_800E28E0--;
    }
    gDPFullSync(g_displayListCursor++);
    gSPEndDisplayList(g_displayListCursor++);
    maxListBytes = D_800CD884;
    listBytes = (u8 *)g_displayListCursor - (u8 *)D_80146CD8->commands;
    D_80146CD8->commandBytes = listBytes;
    if (maxListBytes < listBytes) {
        maxListBytes = listBytes;
    }
    D_800CD884 = maxListBytes;
    D_80146CD8->dual = 0;
    D_80146CD8->ticks = (s32) D_801428A8;
    end = Audio_ReadSystemTime();
    duration = ((end - startTime) << 6) / 3;
    elapsed = (f32)duration;
    rwFrameBuildSeconds = elapsed * D_800C5450_de;
    if (Cache_FinishResourceSlot(0) != 0) {
        SetN64_SubmitFrameTasks(world, D_80146CD8);
    } else {
        osSendMesg(&D_801428C0, &D_80146CD8->done, 1);
    }
    if (hasFadeMode(&world->unk26DC1)) {
        speed = D_800C5454;
        if(world->fadeFast) speed = D_800C5458_de;
        fadeOutSpeed = speed;
        fadeMode = world->unk26DC1;
        if (fadeMode != 1) {
            if (fadeMode == 2) {
                fade = world->fade;
                step = 0.0f;
                if (fade > step) {
                    speed = D_800D2988;
                    updatedFade = fade - (fadeOutSpeed * speed);
                    world->fade = updatedFade;
                    if (updatedFade < step) {
                        world->fade = 0.0f;
                    }
                } else {
                    world->fade = fade - D_800C545C;
                }
                if (world->fade < D_800C5460) {
                    previousMode = world->unk26DB8;
                    world->unk26DB8 = 0x14;
                    world->fade = 0;
                    world->unk26DC1 = 1;
                    world->previousMode = previousMode;
                }
            }
        } else {
            step = D_800D2988;
            fade = world->fade;
            if (step < D_800C5464_de) {
                nextFade = fade + (speed * D_800C5464_de);
            } else {
                nextFade = fade + (speed * step);
            }
            fadeLimit = D_800C5468;
            world->fade = nextFade;
            if (fadeLimit <= nextFade) {
                world->unk26DC1 = 0;
                world->fade = fadeLimit;
                world->fadeFast = 0;
            }
        }
    }
    CCinema_UpdateSequence();
}
