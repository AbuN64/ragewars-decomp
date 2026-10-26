#include "include_asm.h"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/GAME_SESSION.H"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "RENDER/80291054.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/EXTERNS_12.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GROUP.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/OBJRECAT20V1.H"
#include "COMMON/LEVEL.H"
#include "CAMERA/80243A80_3.H"
#include "OVLGAME/8044E2B8_5.H"
#include "RENDER/80291054_2.H"
#include "RENDER/80291054_7.H"
#include "RENDER/80291054_9.H"
#include "sdk/AUDIO/802BD1A8_19.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"
#include "OVLGAME/80405454_4.H"
#include "RESMGR/802A2230_6.H"
#include "TEXTURE/80256220_12.H"

void SetN64_InitFrameRing(RenderState *state) {
    u32 i, count, previous, next;
    CGameStatus *counters;
    Frame *view;
    osCreateMesgQueue(&D_801428C0, (s32)D_80142CB8, 0x1000);
    XPlus_FillMemory(D_800EFC80_de, 7, 0x2000);
    Sched_InitializeSchedulerThread((void *)&D_80142928, (s32)(D_800EFC80_de + 0x2000), D_800CD8C8_de, 0, 1);
    osScAddClient(&D_80142928, &D_80146CC0, &D_801428C0);
    state->handle = -1;
    SetN64_BeginSessionFadeIn(state);
    g_displayListCursor = 0;
    func_802B6B80_de((void *)&D_80142C60);
    if (D_801470B0) {
        Control_ResetActorSnapshot();
        Items_ResetGameOptions(&D_801462C8);
    }
    i = 0;
    func_80244D70_de();
    Ovlgame_InitParticleQuad();
    Ovlgame_InitializeRenderDirection(&state->settings);
    count = D_800DE850;
    state->field26DD0 = 0;
    state->enabled = 1;
    state->field26DCC = 0;
    state->field26DD4 = 0;
    counters = &D_801462C8.counters;
    counters->first = 0;
    counters->m_bCreditsSeenOnce = 0;
    view = state->ring.views;
    if (count) do {
        previous = count - 1;
        previous = (i + previous) % count;
        next = count + 1;
        next = (i + next) % count;
        view->done.type = 2;
        view->colorImage = D_8014D468_de[i];

        view->previous = &state->ring.views[previous];
        view->next = &state->ring.views[next];
        SetN64_ClearFrameDirection(view++);
        ++i;
        count = D_800DE850;

    } while (i < count);
    SetN64_AdvanceDisplayFrame(&state->ring.display);
    func_8025DE30_de();
}

#include "COMMON/GAME_SESSION.H"
#include "COMMON/DISPLAY.H"
#include "COMMON/MENURECAT24.H"
#include "COMMON/EXTERNS_3.H"
#include "SYSTEM/802BA5F0_22.H"
#if defined(VERSION_EU)
extern void func_802BA5F0_eu(s32 pri);
#endif
#include "COMMON/RECORDRECAT1C.H"
extern struct RecordRecAt1C D_8014D438; /* the render buffer record */
extern s16 *D_80146CBC;
extern s32 D_80142920;
extern s32 D_80146CC8;
extern s32 D_80146CCC;
extern s32 D_80146CD0;
extern s32 D_8011B9F4;
extern s32 D_80142C30;
#if defined(VERSION_US_REV1)
extern char D_002953FC_us_rev1[];
extern char D_801053E8_us_rev1[];
extern void Libultra_SetDebugLinkCallback(void *segment);
#endif
extern void osViBlack(s32 active);
extern void Items_ResetPlayers(void *players);
extern void Ovlgame_ResetMenuPool(void *menu);
extern void func_8023EE00_de(void);
extern s32 Defs_ReadResourceWord(s32 size);
extern void OvlScene_LoadSceneResources(Shared_World *world, s32 resource);
extern void Ovlgame_InitializeControllerSession(void);
extern void Ovlgame_ResetHudCharTables(void *hud);
extern void SetN64_BeginModeTransition(GameSession *session, s32 arg1);
extern void SetN64_UpdateGameMode(void *session);
extern void SetN64_UpdateFrameTiming(void *session);
/* The game settings record and its round counters. */
static inline Shared_Game *currentGame(void) {
    return &D_801462C8;
}
static inline CGameStatus *gameStatus(void) {
    return &D_801462C8.counters;
}
/* Main game thread: brings up video and the overlays, clears the frame buffers, starts the menu and
   player state, then serves the scheduler's messages forever. */
void SetN64_RunGameLoop(GameSession *session) {
    u32 i;
    s16 *msg;
    AudioMgr_InitHeap();
#if defined(VERSION_EU)
    func_802BA5F0_eu(0xFE);
#else
    func_802BA350_de(0xFE);
#endif
    osViBlack(1);
#if defined(VERSION_US) || defined(VERSION_US_REV1)
    if (D_80000300 != 1 && D_80000300 != 2) {
#else
    if (D_80000300 != 0) {
#endif
        for (;;) {
        }
    }
    Pak_ClearRenderRecord(&D_8014D438);
    Pak_AllocateRenderBuffers(&D_8014D438);
    osViSwapBuffer((s32)D_8014D468_de[0]);
    osViBlack(0);
    if (D_80000300 == 0) {
        D_80142C38[1] = 50.0f;
    } else {
        D_80142C38[1] = 60.0f;
    }
    D_80146CBC = 0;
    D_80142CA8 = 2;
    D_80142920 = 0;
    D_80142CA4 = 0;
    D_8011B9F8 = 0;
    D_801428AC = 0;
    D_80142C34 = 0;
    D_80146CC8 = 0;
    D_80146CCC = 0;
    D_80146CD0 = 0;
    D_8011B9F4 = 0;
    D_80142C38[0] = 0.0f;
    D_80142C30 = 0;
    SetN64_InitFrameRing((RenderState *)session);
#if defined(VERSION_US_REV1)
    Libultra_SetDebugLinkCallback(D_002953FC_us_rev1);
    osSendMesg((OSMesgQueue *)D_801053E8_us_rev1, (OSMesg)0xBEEFDEAD, 0);
#endif
    for (i = 0; i < D_800DE850; i++) {
        XPlus_FillMemory(D_8014D468_de[i], 0, D_800E28D0 * D_800E28D4 * 2);
    }
    Items_ResetPlayers(session->players);
    Ovlgame_ResetMenuPool(session->menu);
    func_8023EE00_de();
    session->resource = Defs_ReadResourceWord(0x18) & 0x3FFFFFFF;
    Items_ResetActorPools(session->players, 0);
    Ovlgame_InitializePlayerPool(session->menu, 0, 0);
    OvlScene_LoadSceneResources(&g_world, session->resource);
    if (D_800CBC11[0] == 0) {
        Ovlgame_InitializeControllerSession();
    }
    Ovlgame_ResetHudCharTables(&session->hud);
    Pak_AllocateScratchBuffer();
    Tsmos_InitFrontendOnce();
    SmXlate_SwitchScreen(2);
    D_801428D8 = 3;
    D_8014AD94 = 0;
    D_8014ADA0 = 0;
    D_80146D60 = 0;
    D_8014AD9C = 1;
    D_80142CAC = 0;
    Control_EnableAllControllerPaks();
    gameStatus()->transitionActive = 0;
    SetN64_BeginModeTransition(session, 0);
    for (;;) {
        Shared_Game *game = currentGame();
        osRecvMesg(&D_801428C0, (OSMesg *)&D_80146CBC, 1);
        msg = D_80146CBC;
        switch (*msg) {
        case 1:
            SetN64_UpdateGameMode(session);
            break;
        case 2:
            if (msg == &session->ring.frames[0].done.type) {
                D_80146CD8 = &session->ring.frames[0];
            } else if (msg == &session->ring.frames[1].done.type) {
                D_80146CD8 = &session->ring.frames[1];
            } else if (msg == &session->ring.frames[2].done.type) {
                D_80146CD8 = &session->ring.frames[2];
            }
            if (session->mode == 0x14) {
                D_80142CA8++;
            } else {
                SetN64_UpdateFrameTiming(session);
            }
            /* The ROM keeps only the hoisted &D_801462C8 of this test: the store is dead (the next receive overwrites msg). */
            if (game->flags) {
                msg = 0;
            }
            break;
        case 4:
            D_800CDD10 = 0;
            Control_ResetControllerProfiles();
            Control_SetControllerMode(0);
            session->fastFade = 1;
            session->transitionBlocked = 1;
            SetN64_SetTransitionTarget(session, 0x14);
            break;
        }
    }
}

#include "abi.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "gbi.h"

#include "COMMON/DISPLAY.H"
extern UnitVp D_80142C40[];
extern s32 D_800D297C;

#include "COMMON/VIDEO_DIMENSIONS.H"
/* Starts the frame display list in the current ring buffer: segment 0, the two setup lists, the depth image, a
 * full-screen viewport (SCREEN_WD x SCREEN_HT) in D_80142C40[D_800D297C] and a full-screen scissor. */
void SetN64_BeginFrameDisplayList(void *world) {
    UnitVp *viewport;
    g_displayListCursor = D_8011FAC0.ring.current->commands;
    gSPSegment(g_displayListCursor++, 0, 0);
    gSPDisplayList(g_displayListCursor++, &D_800CBCC0);
    gSPDisplayList(g_displayListCursor++, &D_800CBCF0_de);
    viewport = &D_80142C40[D_800D297C];
    gDPSetDepthImage(g_displayListCursor++, D_801536E8);
    viewport->vscale[0] = SCREEN_WD * 2;
    viewport->vscale[1] = SCREEN_HT * 2;
    viewport->vscale[2] = 0x3FF;
    viewport->vscale[3] = 0;
    viewport->vtrans[0] = SCREEN_WD * 2;
    viewport->vtrans[1] = SCREEN_HT * 2;
    viewport->vtrans[2] = 0;
    viewport->vtrans[3] = 0;
    gSPViewport(g_displayListCursor++, viewport);
    gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
}

/* rspboot text is 0xD0 bytes: it ends where the first graphics microcode text (D_800D8CE0) starts. */
extern u64 rspbootTextStart[], rspbootTextEnd[], D_800D8CE0[], D_800DC020_de[], D_800DA070[], D_800DC440[], D_800E4000[];
extern u32 D_800D2978, D_800CD730;
extern s32 D_800D297C;
extern void osWritebackDCacheAll(void);
extern void Sched_SendSchedulerTask(void *, OSScTask_s *);
/* Fills the frame's graphics task (and the second one when the frame is dual), hands them to the scheduler,
   then advances the ring and gives the next frame the other pair of command buffers. */
void SetN64_SubmitFrameTasks(Display *display, Frame *frame)
{
    OSScTask_s *task;
    task = &frame->task;
    {
        s32 size, bytes;
        u64 *base;
        task->list.data_ptr = (u64 *)frame->commands;
        bytes = frame->commandBytes;
        size = D_8014D424;
        task->list.type = 1;
        task->list.ucode_boot = rspbootTextStart;
        base = D_8014D428;
        task->list.ucode_boot_size = (u8 *)rspbootTextEnd - (u8 *)rspbootTextStart;
        task->list.ucode_size = 0x1000;
        task->list.ucode_data_size = 0x800;
        task->list.yield_data_ptr = D_800E4000;
        task->list.yield_data_size = 0xC00;
        task->list.ucode = D_800D8CE0;
        task->list.ucode_data = D_800DC020_de;
        task->list.flags = 0;
        task->list.dram_stack = 0;
        task->list.dram_stack_size = 0;
        task->list.output_buff = base;
        task->list.output_buff_size = (u64 *)((u8 *)base + size);
        task->list.data_size = bytes;
    }
    frame->task.next = 0;
    task->msgQ = &D_801428C0;
    task->msg = &frame->done;
    task->framebuffer = frame->colorImage;
    if (frame->dual) task->flags = 3; else task->flags = 0x23;
    if (frame->dual) {
        s32 size, bytes;
        u64 *base;
        task = &frame->secondTask;
        task->list.data_ptr = (u64 *)frame->secondCommands;
        bytes = frame->secondCommandBytes;
        size = D_8014D424;
        task->list.type = 1;
        task->list.ucode_boot = rspbootTextStart;
        base = D_8014D428;
        task->list.ucode_boot_size = (u8 *)rspbootTextEnd - (u8 *)rspbootTextStart;
        task->list.ucode_size = 0x1000;
        task->list.ucode_data_size = 0x800;
        task->list.yield_data_ptr = D_800E4000;
        task->list.yield_data_size = 0xC00;
        task->list.ucode = D_800DA070;
        task->list.ucode_data = D_800DC440;
        task->list.flags = 0;
        task->list.dram_stack = 0;
        task->list.dram_stack_size = 0;
        task->list.output_buff = base;
        task->list.output_buff_size = (u64 *)((u8 *)base + size);
        task->list.data_size = bytes;
        frame->secondTask.next = 0;
        task->flags = 0x23;
        task->msgQ = &D_801428C0;
        task->msg = &frame->done;
        task->framebuffer = frame->colorImage;
    }
    osWritebackDCacheAll();
    Sched_SendSchedulerTask(&D_80142928, &frame->task);
    if (frame->dual) Sched_SendSchedulerTask(&D_80142928, &frame->secondTask);
    D_800D2978++;
    D_800CD730++;
    D_800D297C ^= 1;
    display->current = &display->frames[D_800D2978 % D_800DE850];
    display->current->commands = D_800D297C ? D_8014D464 : D_8014D460;
    display->current->secondCommands = D_800D297C ? D_8014D42C : D_8014D430_de;
}
