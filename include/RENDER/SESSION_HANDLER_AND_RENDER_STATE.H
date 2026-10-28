#ifndef RENDER_SESSION_HANDLER_AND_RENDER_STATE_H
#define RENDER_SESSION_HANDLER_AND_RENDER_STATE_H
#include "TYPES.H"
#include "COMMON/RENDERSETTINGS.H"
#include "COMMON/DISPLAY.H"
/* One state-dispatch row in D_800CD78C, stride 0xC. */
typedef struct SessionHandlerRow {
    void (*update)(void *);
    char reserved4[8];
} SessionHandlerRow;
struct ObjRecAt255C8 {
    char pad0[0x25580];
    char unk25580;
    char pad25580[0x255C8 - 0x25580 - sizeof(char)];
    char unk255C8;
};
typedef struct RenderState {
    union { Frame views[4]; Display display; } ring; char pad500[0x2688C]; RenderSettings settings; char pad26DB0[4]; s32 handle;
    char pad26DB8[0x10]; s32 enabled, field26DCC, field26DD0, field26DD4;
} RenderState;
#endif
