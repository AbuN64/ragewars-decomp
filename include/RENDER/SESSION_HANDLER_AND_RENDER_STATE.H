#ifndef RENDER_SESSION_HANDLER_AND_RENDER_STATE_H
#define RENDER_SESSION_HANDLER_AND_RENDER_STATE_H
#include "TYPES.H"
#include "COMMON/RENDERSETTINGS.H"
#include "COMMON/DISPLAY.H"
/* One state-dispatch row in g_sessionUpdateHandlers, stride 0xC. */
typedef struct SessionHandlerRow {
    void (*update)(void *);
    char reserved4[8];
} SessionHandlerRow;
struct SessionPlayerItemResetView {
    char pad0[0x25580];
    char playerPool;
    char pad25580[0x255C8 - 0x25580 - sizeof(char)];
    char actorPools;
};
typedef struct RenderState {
    union { Frame views[4]; Display display; } ring; char pad500[0x2688C]; RenderSettings settings; char pad26DB0[4]; s32 handle;
    char pad26DB8[0x10]; s32 enabled, reservedTransitionState, transitionBlocked, clockPaused;
} RenderState;
#endif
