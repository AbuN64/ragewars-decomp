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

void func_80291208_de(RenderState *state) {
    u32 i, count, previous, next;
    CGameStatus *counters;
    Frame *view;
    osCreateMesgQueue(&D_801428C0, (s32)D_80142CB8, 0x1000);
    func_802A001C_de(D_800EFC80_de, 7, 0x2000);
    func_8028F754_de((void *)&D_80142928, (s32)(D_800EFC80_de + 0x2000), D_800CD8C8_de, 0, 1);
    osScAddClient(&D_80142928, &D_80146CC0, &D_801428C0);
    state->handle = -1;
    func_80293590_de(state);
    D_80110634 = 0;
    func_802B6B80_de((void *)&D_80142C60);
    if (D_801470B0) {
        func_80264B44_de();
        Items_ResetGameOptions(&D_801462C8);
    }
    i = 0;
    func_80244D70_de();
    func_8044DCC0_de();
    func_8044DC60_de(&state->settings);
    count = D_800DE850;
    state->field26DD0 = 0;
    state->enabled = 1;
    state->field26DCC = 0;
    state->field26DD4 = 0;
    counters = &D_801462C8.counters;
    counters->first = 0;
    counters->second = 0;
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
        func_80290A00_de(view++);
        ++i;
        count = D_800DE850;

    } while (i < count);
    func_80293054_de(&state->ring.display);
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
extern char D_8014D438[];
extern s16 *D_80146CBC;
extern s32 D_80142920;
extern s32 D_80146CC8;
extern s32 D_80146CCC;
extern s32 D_80146CD0;
extern s32 D_8011B9F4;
extern s32 D_80142C30;
extern s32 D_801428D8;
#if defined(VERSION_US_REV1)
extern char D_002953FC_us_rev1[];
extern char D_801053E8_us_rev1[];
extern void func_802B155C_us_rev1(void *segment);
#endif
extern void func_802567D0_de(void);
extern void osViBlack(s32 active);
extern void func_80405CA8_de(void *record);
extern s32 Ovlgame_AllocateRenderBuffers(void *record);
extern void func_8044A62C_de(void *players);
extern void func_80449DB0_de(void *menu);
extern void func_8023EE00_de(void);
extern s32 func_80265964_de(s32 size);
extern void Items_ResetActorPools(void *players, s32 arg1);
extern void func_804499B0_de(void *menu, s32 arg1, s32 arg2);
extern void func_8044B7C0_de(Shared_World *world, s32 resource);
extern void func_8044AE70_de(void);
extern void Ovlgame_ResetHudCharTables(void *hud);
extern void func_80404D84_de(void);
extern void func_802A21F4_de(void);
extern void func_80298368_de(s32 arg0);
extern void func_8026479C_de(void);
extern void func_80293790_de(GameSession *session, s32 arg1);
extern void func_80293848_de(void *session);
extern void Render_UpdateFrameTiming(void *session);
extern void func_8026480C_de(void);
/* The game settings record and its round counters. */
static inline Shared_Game *currentGame(void) {
    return &D_801462C8;
}
static inline CGameStatus *gameStatus(void) {
    return &D_801462C8.counters;
}
/* Main game thread: brings up video and the overlays, clears the frame buffers, starts the menu and
   player state, then serves the scheduler's messages forever. */
void Render_RunGameLoop(GameSession *session) {
    u32 i;
    s16 *msg;
    func_802567D0_de();
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
    func_80405CA8_de(D_8014D438);
    Ovlgame_AllocateRenderBuffers(D_8014D438);
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
    func_80291208_de((RenderState *)session);
#if defined(VERSION_US_REV1)
    func_802B155C_us_rev1(D_002953FC_us_rev1);
    func_802BB420_de((OSMesgQueue *)D_801053E8_us_rev1, (OSMesg)0xBEEFDEAD, 0);
#endif
    for (i = 0; i < D_800DE850; i++) {
        func_802A001C_de(D_8014D468_de[i], 0, D_800E28D0 * D_800E28D4 * 2);
    }
    func_8044A62C_de(session->players);
    func_80449DB0_de(session->menu);
    func_8023EE00_de();
    session->resource = func_80265964_de(0x18) & 0x3FFFFFFF;
    Items_ResetActorPools(session->players, 0);
    func_804499B0_de(session->menu, 0, 0);
    func_8044B7C0_de(&D_8011FE88, session->resource);
    if (D_800CBC11[0] == 0) {
        func_8044AE70_de();
    }
    Ovlgame_ResetHudCharTables(&session->hud);
    func_80404D84_de();
    func_802A21F4_de();
    func_80298368_de(2);
    D_801428D8 = 3;
    D_8014AD94 = 0;
    D_8014ADA0 = 0;
    D_80146D60 = 0;
    D_8014AD9C = 1;
    D_80142CAC = 0;
    func_8026479C_de();
    gameStatus()->transitionActive = 0;
    func_80293790_de(session, 0);
    for (;;) {
        Shared_Game *game = currentGame();
        func_802BB2A0_de(&D_801428C0, (OSMesg *)&D_80146CBC, 1);
        msg = D_80146CBC;
        switch (*msg) {
        case 1:
            func_80293848_de(session);
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
                Render_UpdateFrameTiming(session);
            }
            /* The ROM keeps only the hoisted &D_801462C8 of this test: the store is dead (the next receive overwrites msg). */
            if (game->flags) {
                msg = 0;
            }
            break;
        case 4:
            D_800CDD10 = 0;
            func_8026480C_de();
            func_80264854_de(0);
            session->pad26DC0 = 1;
            session->transitionBlocked = 1;
            func_80293824_de(session, 0x14);
            break;
        }
    }
}

#ifdef NON_MATCHING
#include "abi.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "gbi.h"

#include "COMMON/DISPLAY.H"
extern Gfx *D_80110634;
extern char D_800CBCC0;
extern char D_800CBCF0_de;
extern void *D_801536E8;
extern UnitVp D_80142C40[];
extern s32 D_800D297C;
extern s32 D_800E28D0;

f32 Render_BeginFrameDisplayList(void *world) {
    UnitVp *viewport;
    s32 height;
    s32 width;
    f32 right;
    f32 bottom;

    D_80110634 = D_8011FAC0.ring.current->commands;
    gSPSegment(D_80110634++, 0, 0);
    gSPDisplayList(D_80110634++, &D_800CBCC0);
    gSPDisplayList(D_80110634++, &D_800CBCF0_de);
    gDPSetDepthImage(D_80110634++, D_801536E8);
    viewport = &D_80142C40[D_800D297C];
    height = D_800E28D4;
    viewport->vscale[1] = height * 2;
    viewport->vtrans[1] = height * 2;
    viewport->vscale[2] = 0x3FF;
    bottom = (f32)(height - 1) * (4.0f);
    viewport->vscale[3] = 0;
    viewport->vtrans[2] = 0;
    viewport->vtrans[3] = 0;
    width = D_800E28D0;
    right = (f32)(width - 1) * (4.0f);
    viewport->vscale[0] = width * 2;
    viewport->vtrans[0] = width * 2;
    gSPMoveMem(D_80110634++, G_MV_VIEWPORT, 0, 16, viewport);
    gDPSetScissorFrac(D_80110634++, G_SC_NON_INTERLACE, 0, 0, (s32)right, (s32)bottom);
    return bottom;
}
#else
INCLUDE_ASM("span_1000", Render_BeginFrameDisplayList);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"

extern u64 D_800D8C10[], D_800D8CE0[], D_800DC020_de[], D_800DA070[], D_800DC440[], D_800E4000[];
extern u32 D_800D2978, D_800CD730;
extern s32 D_800D297C;
extern void osWritebackDCacheAll(void);
extern void func_8028FD4C_de(void *, OSScTask_s *);
/* Fills the frame's graphics task (and the second one when the frame is dual), hands them to the scheduler,
   then advances the ring and gives the next frame the other pair of command buffers. */
void Render_SubmitFrameTasks(Display *display, Frame *frame)
{
    OSScTask_s *task;
    s32 size;
    s32 bytes;
    u64 *base;
    task = &frame->task;
    task->list.data_ptr = (u64 *)frame->commands;
    bytes = frame->commandBytes;
    size = D_8014D424;
    task->list.type = 1;
    task->list.ucode_boot = D_800D8C10;
    base = D_8014D428;
    task->list.ucode_boot_size = (u8 *)D_800D8CE0 - (u8 *)D_800D8C10;
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
    frame->task.next = 0;
    task->msgQ = &D_801428C0;
    task->msg = &frame->done;
    task->framebuffer = frame->colorImage;
    if (frame->dual) task->flags = 3; else task->flags = 0x23;
    if (frame->dual) {
        task = &frame->secondTask;
        task->list.data_ptr = (u64 *)frame->secondCommands;
        bytes = frame->secondCommandBytes;
        size = D_8014D424;
        task->list.type = 1;
        task->list.ucode_boot = D_800D8C10;
        base = D_8014D428;
        task->list.ucode_boot_size = (u8 *)D_800D8CE0 - (u8 *)D_800D8C10;
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
    func_8028FD4C_de(&D_80142928, &frame->task);
    if (frame->dual) func_8028FD4C_de(&D_80142928, &frame->secondTask);
    D_800D2978++;
    D_800CD730++;
    D_800D297C ^= 1;
    display->current = &display->frames[D_800D2978 % D_800DE850];
    display->current->commands = D_800D297C ? D_8014D464 : D_8014D460;
    display->current->secondCommands = D_800D297C ? D_8014D42C : D_8014D430_de;
}
#else
INCLUDE_ASM("span_1000", Render_SubmitFrameTasks);
#endif
