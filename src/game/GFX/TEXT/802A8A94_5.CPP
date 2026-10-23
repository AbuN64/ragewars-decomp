#include "include_asm.h"
#include "COMMON/OBJECTLINKSC_2.H"
#include "GFX/802A8A94.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/WORLD.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "TYPES.H"
#include "GFX/TEXT/802A8A94_5.H"

extern s32 D_800CD764_de;
extern Gfx *D_80110634;
#include "COMMON/DISPLAY.H"

extern int D_80137798[6];
extern float D_801377B0[2];
extern s32 Render_StartWorldEffect(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_802AA8EC_de(s32 arg0, s32 arg1, void **arg2, s32 *arg3);
extern void func_80253754_de(s32 arg0, s32 arg1);
extern void func_8026925C_de(u32);
extern void func_80268CE0_de(u32);

#if defined(VERSION_EU_X)
void func_802AA950_de(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3)
{
  void *sp10;
  s32 sp14;
  void *imageData;
  s32 temp_v0;
  if (D_800CD764_de != 0)
  {
    temp_v0 = Render_StartWorldEffect(&D_8011FE88, arg0, 0, 1);
    if (temp_v0 != 0)
    {
      func_802AA8EC_de(temp_v0, arg1, &sp10, &sp14);
      imageData = sp10;
      *arg2 = ((ImageSet *)sp10)->width;
      *arg3 = ((ImageSet *)imageData)->height;
      func_80253754_de(0, temp_v0);
    }
  }
}
#endif

#if defined(VERSION_EU_X)
void func_802AA9F4_de(void) {

    Gfx *gfx;

    gfx = D_80110634++;
    gDPPipeSync(gfx);
    gfx = D_80110634++;
    gDPSetCycleType(gfx, G_CYC_1CYCLE);
    func_8026925C_de(0x15);
    func_80268CE0_de(0x19);
}
#endif

#if defined(VERSION_EU_X)
void func_802AAA54_de(s32 x0,s32 y0,s32 x1,s32 y1,u8 r,u8 g,u8 b,u8 a) {

 gDPPipeSync(D_80110634++);
 gDPSetPrimColor(D_80110634++, 255, 255, r, g, b, a);
 gDPFillRectangle(D_80110634++, ((x0))>((0))?((x0)):((0)), ((y0))>((0))?((y0)):((0)), ((x1))>((0))?((x1)):((0)), ((y1))>((0))?((y1)):((0)));
}
#endif

#if defined(VERSION_EU_X)
#include "COMMON/AIPROFILE.H"
extern s32 D_80137798[6];
extern f32 D_801377B0[2];
extern s32 Render_StartWorldEffect(void *,s32,s32,s32);
extern void func_802AA8EC_de(s32,s32,void **,s32 *);
extern void func_80253754_de(s32,s32);

void func_802AAB3C_de(int arg0, int arg1, int arg2, int alpha, int arg4, int arg5) {
    D_80137798[0] = arg0;
    D_80137798[1] = arg1;
    D_80137798[2] = arg2;
    D_80137798[3] = alpha;
    D_80137798[4] = arg4;
    D_80137798[5] = arg5;
}
#endif

#if defined(VERSION_EU_X)
void func_802AAB68_de(float arg0, float arg1) {
    D_801377B0[0] = arg0;
    D_801377B0[1] = arg1;
}
#endif

#if defined(VERSION_EU_X)
void func_802AAB7C_de(u8 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 alpha, s32 arg7) {
    if (arg5 != 0) {
        func_802A88F0_de(arg0, arg1, arg2, arg3, arg4, 1, alpha, arg7);
    }
    func_802A88F0_de(arg0, arg1, arg2, arg3, arg4, 0, alpha, arg7);
}
#endif

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
s32 func_802AAC28_de(s32 icon, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 which) {

    s32 temp_v0;

    if ((u32)(D_800E28A4 - (((u32)D_80110634 - (u32)D_8011BDC0->commands) >> 3)) < 0x3E8
        || D_800CD764_de == 0
        || (temp_v0 = Render_StartWorldEffect(&D_8011FE88, icon, 0, 1), temp_v0 == 0)) {
        return 0;
    }
    Text_DrawTileGrid(temp_v0, arg1, arg2, arg3, arg4, arg5, which);
    func_80253754_de(0, temp_v0);
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_802AAC28_de);
#endif
#endif

#if !(defined(VERSION_EU_X))


/* Appends a pipe synchronisation and an other-mode setting to the display list D_80110634 points
   into, then calls func_8026925C_de with 0x15 and func_80268CE0_de with 0x19. */


/* Emits pipe sync, primitive color and a rectangle with nonnegative coordinates. */



extern void Text_DrawTileGrid(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);

void func_802AA950_de(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3)
{
  void *sp10;
  s32 sp14;
  void *new_var;
  s32 temp_v0;
  if (D_800CD764_de != 0)
  {
    temp_v0 = Render_StartWorldEffect(&D_8011FE88, arg0, 0, 1);
    if (temp_v0 != 0)
    {
      func_802AA8EC_de(temp_v0, arg1, &sp10, &sp14);
      new_var = sp10;
      *arg2 = ((ImageSet *)sp10)->width;
      *arg3 = ((ImageSet *)new_var)->height;
      func_80253754_de(0, temp_v0);
    }
  }
}

void func_802AA9F4_de(void) {

    Gfx *gfx;

    gfx = D_80110634++;
    gDPPipeSync(gfx);
    gfx = D_80110634++;
    gDPSetCycleType(gfx, G_CYC_1CYCLE);
    func_8026925C_de(0x15);
    func_80268CE0_de(0x19);
}

void func_802AAA54_de(s32 x0,s32 y0,s32 x1,s32 y1,u8 r,u8 g,u8 b,u8 a) {

 gDPPipeSync(D_80110634++);
 gDPSetPrimColor(D_80110634++, 255, 255, r, g, b, a);
 gDPFillRectangle(D_80110634++, ((x0))>((0))?((x0)):((0)), ((y0))>((0))?((y0)):((0)), ((x1))>((0))?((x1)):((0)), ((y1))>((0))?((y1)):((0)));
}

/** Store six words into the global record. */
void func_802AAB3C_de(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    D_80137798[0] = arg0;
    D_80137798[1] = arg1;
    D_80137798[2] = arg2;
    D_80137798[3] = arg3;
    D_80137798[4] = arg4;
    D_80137798[5] = arg5;
}

void func_802AAB68_de(float arg0, float arg1) {
    D_801377B0[0] = arg0;
    D_801377B0[1] = arg1;
}

void func_802AAB7C_de(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (arg5 != 0) {
        func_802A88F0_de(arg0, arg1, arg2, arg3, arg4, 1, arg6, arg7);
    }
    func_802A88F0_de(arg0, arg1, arg2, arg3, arg4, 0, arg6, arg7);
}

s32 func_802AAC28_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6) {

    s32 temp_v0;

    if ((u32)(D_800E28A4 - (((u32)D_80110634 - (u32)D_8011BDC0->commands) >> 3)) < 0x3E8
        || D_800CD764_de == 0
        || (temp_v0 = Render_StartWorldEffect(&D_8011FE88, arg0, 0, 1), temp_v0 == 0)) {
        return 0;
    }
    Text_DrawTileGrid(temp_v0, arg1, arg2, arg3, arg4, arg5, arg6);
    func_80253754_de(0, temp_v0);
    return 1;
}
#endif

#include "GFX/TEXT/802A8A94_6.H"
extern u8 D_801470C0_de[0x90];
extern void *func_802BD3A0_de(void *, const void *, int);
typedef struct ResourceView {
    u8 *data;
    u8 type;
} ResourceView;
void func_802AAD14_de(void) {
    Table802AB8DC **handle;
    Table802AB8DC *table;
    Entry802AB8DC *entry;
    ResourceView view;
    u8 entryTag;
    s32 remainder;
    void *result;
    void *base;
    D_800D2F90 = 0;
    handle = Render_StartWorldEffect(&D_8011FE88, 2, 0, 1);
    if (handle != 0) {
        table = *handle;
        view.data = 0;
        entry = &table->entries[0];
        remainder = 0 % table->count;
        entry += remainder;
        base = table;
        result = base + entry->offset;
        entryTag = entry->pad4[0];
        view.type = entryTag;
        view.data = result;
        if (view.data != 0) {
            view.data += 0x10;
        }
        func_802BD3A0_de(D_801470C0_de, view.data, 0x90);
        func_80253754_de(0, handle);
        D_800D2F90 = D_801470C0_de;
    }
}
