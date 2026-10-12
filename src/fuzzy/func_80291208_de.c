#include "types.h"

typedef struct RenderView {
    char pad00[0xF0]; s16 kind; char padF2[0x1E]; void *buffer;
    char pad114[0x18]; struct RenderView *previous, *next; char pad134[0xC];
} RenderView;
typedef struct RenderState {
    RenderView views[4]; char pad500[0x2688C]; char settings[0x28]; s32 handle;
    char pad26DB8[0x10]; s32 enabled, field26DCC, field26DD0, field26DD4;
} RenderState;
typedef struct RenderCounters { char pad00[0x88]; s32 first, second; } RenderCounters;
extern char D_801428C0[], D_80142CB8[], D_80142928[], D_80146CC0[], D_80142C60[], D_801462C8[];
extern char D_800EFC80_de[0x2000];
extern RenderCounters D_801468A0;
extern void *D_80110634;
extern s32 D_800CD8C8_de, D_801470B0;
extern u32 D_800DE850;
extern void *D_8014D468_de[];
extern void func_802BAC60_de(void *, void *, s32);
extern void *func_802A001C_de(void *, s32, u32);
extern void func_8028F754_de(void *, void *, s32, s32, u8);
extern void func_8028F864_de(void *, void *, void *);
extern void func_80293590_de(void *);
extern void func_802B6B80_de(void *);
extern void func_80264B44_de(void);
extern void func_80445074_eu(void *);
extern void func_80244D70_de(void);
extern void func_8044DCC0_de(void);
extern void func_8044DC60_de(void *);
extern void func_80290A00_de(void *);
extern void func_80293054_de(void *);
extern void func_8025DE30_de(void);

void func_80291208_de(RenderState *state) {
    u32 i, count, previous, next;
    RenderView *view;
    func_802BAC60_de(D_801428C0, D_80142CB8, 0x1000);
    func_802A001C_de(D_800EFC80_de, 7, 0x2000);
    func_8028F754_de(D_80142928, D_800EFC80_de + 0x2000, D_800CD8C8_de, 0, 1);
    func_8028F864_de(D_80142928, D_80146CC0, D_801428C0);
    state->handle = -1;
    func_80293590_de(state);
    D_80110634 = 0;
    func_802B6B80_de(D_80142C60);
    if (D_801470B0) {
        func_80264B44_de();
        func_80445074_eu(D_801462C8);
    }
    i = 0;
    func_80244D70_de();
    func_8044DCC0_de();
    func_8044DC60_de(state->settings);
    count = D_800DE850;
    state->field26DD0 = 0;
    state->enabled = 1;
    state->field26DCC = 0;
    state->field26DD4 = 0;
    D_801468A0.first = 0;
    D_801468A0.second = 0;
    view = state->views;
    if (count) do {
        previous = (i + count - 1) % count;
        next = (i + count + 1) % count;
        view->kind = 2;
        view->buffer = D_8014D468_de[i];
        ++i;
        view->previous = &state->views[previous];
        view->next = &state->views[next];
        func_80290A00_de(view);
        count = D_800DE850;
        ++view;
    } while (i < count);
    func_80293054_de(state);
    func_8025DE30_de();
}
