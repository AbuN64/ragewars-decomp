#include "include_asm.h"
#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "GFX/802A8A94.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/FRUSTUM.H"
#include "COMMON/STATEPAIR.H"
#include "COMMON/OBJRECAT18V6.H"
#include "TYPES.H"
#include "RESMGR/802A2230_6.H"
#include "SYSTEM/80296FF8_6.H"
#include "COMMON/LONE/D_800CD764_de.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/WORLD.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "GFX/TEXT/802A8A94_5.H"
#include "COMMON/DISPLAY.H"
#include "COMMON/AIPROFILE.H"
#include "GFX/TEXT/802A8A94_6.H"
#include "COMMON/ENTRYRECATE.H"
#include "MENU/802ABDBC_5.H"

s32 func_802A7AA4_de(void *);

extern s32 D_800CDEB4;

s32 func_802AA70C_de(void *, s32 *);

extern s32 D_800CDEC8;

extern int func_802A23B4_de(void);

extern void Text_SetupSpriteMode(s32);

extern void func_802A7660_de(void *arg0, int arg1);

extern f32 D_800CB3A8;

extern f32 D_800CB3B0;




void func_802AA6D0_de(void *arg0, s16 arg1, s16 arg2)
{
  Mover *mover = arg0;
  mover->handle = -1;
  mover->active = 0;
  mover->state = 0;
  mover->x = (f32) arg1;
  mover->y = (f32) arg2;
}

s32 func_802AA70C_de(void *widget, s32 *arg1) {
    (((struct ObjectLinksC_2 *) ((s8 *) widget))->unk_4) = arg1;
    (((struct ObjectLinksC_2 *) ((s8 *) widget))->unk_8) = 2;
    return func_802A7AA4_de(widget);
}

s32 func_802AA730_de(void *arg0, s32 arg1, s32 arg2) {
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_40) = arg1;
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_3C) = arg2;
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_44) = 0x64;
    return func_802AA70C_de(arg0, &D_800CDEB4);
}

void func_802AA760_de(void *arg0, s32 arg1, s32 arg2) {
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_88) = arg1;
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_84) = arg2;
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_8C) = 0x64;
    func_802AA70C_de(arg0 + 0x48, &D_800CDEC8);
}

void func_802AA794_de(char *object, int value) {
    Hud *hud = (void *)object;
    hud->bars[0].target = value;
}

void func_802AA79C_de(void *object, int value) {
    Hud *hud = (void *)object;
    hud->bars[1].target = value;
}

void func_802AA7A4_de(void *arg0) {
    char pad[256];
    (void)pad;

    if (func_802A23B4_de() == 1) {
        func_802A2090_de();
        func_8026D8F8_de();
        System_ResetTextureCache();
    }
    func_802A84F8_de();
    func_802A8710_de();
    func_802AAB68_de(D_800C61F0_de, D_800C61F0_de);
    func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    Text_SetupSpriteMode(D_801462C8.hudFade);
    if (((Hud *)arg0)->bars[0].enabled != 0) {
        func_802A7660_de(arg0, 1);
    }
    if (((Hud *)arg0)->bars[1].enabled != 0) {
        func_802A7660_de(arg0, 2);
    }
}

/** Return the floating parameter selected by the current global mode. */
f32 func_802AA864_de(void) {
    {
        s32 sw_mode_value = D_80147150;
        if ((unsigned int)sw_mode_value > 6) {
            goto sw_mode_default;
        }
        switch (sw_mode_value) {
        case 0: goto sw_mode_0;
        case 1: goto sw_mode_1;
        case 2: goto sw_mode_2;
        case 3: goto sw_mode_3;
        case 4: goto sw_mode_4;
        case 5: goto sw_mode_4;
        case 6: goto sw_mode_2;
        }
    }
    do {
    sw_mode_0:
        return 24.0f;
    sw_mode_1:
        return 12.0f;
    sw_mode_2:
    sw_mode_6:
        return 8.0f;
    sw_mode_3:
        return 6.0f;
    sw_mode_4:
    sw_mode_5:
        return 16.0f;
    sw_mode_default:
        return 1.0f;
    
    } while (0);
}

void func_802AA8EC_de(Table802AB8DC **handle, s32 index, void **out, u8 *tag) {
    Table802AB8DC *table;
    Entry802AB8DC *entry;
    void *result;
    u8 entryTag;
    s32 remainder;

    *out = 0;
    if (handle != 0) {
        table = *handle;
        entry = &table->entries[0];
        remainder = index % table->count;
        remainder *= 8;
        remainder += (s32)entry;
        entry = (Entry802AB8DC *)remainder;
        entryTag = entry->pad4[0];
        result = (u8 *)table + entry->offset;
        *tag = entryTag;
        *out = result;
    }
}

extern Gfx *g_displayListCursor;

extern s32 Render_StartWorldEffect(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void Scene_UnlockResource(s32 arg0, s32 arg1);
extern void Render_SetModePreset(u32);
extern void Render_SetCombineMode(u32);

#if defined(VERSION_EU_X)
void func_802AA950_de(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3)
{
  void *sp10;
  s32 sp14;
  void *imageData;
  s32 temp_v0;
  if (D_800CD764_de != 0)
  {
    temp_v0 = Render_StartWorldEffect(&g_world, arg0, 0, 1);
    if (temp_v0 != 0)
    {
      func_802AA8EC_de(temp_v0, arg1, &sp10, &sp14);
      imageData = sp10;
      *arg2 = ((ImageSet *)sp10)->width;
      *arg3 = ((ImageSet *)imageData)->height;
      Scene_UnlockResource(0, temp_v0);
    }
  }
}
#endif

#if defined(VERSION_EU_X)
void Text_SetupFillMode(void) {

    Gfx *gfx;

    gfx = g_displayListCursor++;
    gDPPipeSync(gfx);
    gfx = g_displayListCursor++;
    gDPSetCycleType(gfx, G_CYC_1CYCLE);
    Render_SetModePreset(0x15);
    Render_SetCombineMode(0x19);
}
#endif

#if defined(VERSION_EU_X)
void func_802AAA54_de(s32 x0,s32 y0,s32 x1,s32 y1,u8 r,u8 g,u8 b,u8 a) {

 gDPPipeSync(g_displayListCursor++);
 gDPSetPrimColor(g_displayListCursor++, 255, 255, r, g, b, a);
 gDPFillRectangle(g_displayListCursor++, ((x0))>((0))?((x0)):((0)), ((y0))>((0))?((y0)):((0)), ((x1))>((0))?((x1)):((0)), ((y1))>((0))?((y1)):((0)));
}
#endif

#if defined(VERSION_EU_X)
extern s32 Render_StartWorldEffect(void *,s32,s32,s32);
extern void Scene_UnlockResource(s32,s32);

void func_802AAB3C_de(int arg0, int arg1, int arg2, int alpha, int arg4, int arg5) {
    D_801376F8.envR = arg0;
    D_801376F8.envG = arg1;
    D_801376F8.envB = arg2;
    D_801376F8.primR = alpha;
    D_801376F8.primG = arg4;
    D_801376F8.primB = arg5;
}
#endif

#if defined(VERSION_EU_X)
void func_802AAB68_de(float arg0, float arg1) {
    D_801376F8.width = arg0;
    D_801376F8.height = arg1;
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

    if ((u32)(D_800E28A4 - (((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) >> 3)) < 0x3E8
        || D_800CD764_de == 0
        || (temp_v0 = Render_StartWorldEffect(&g_world, icon, 0, 1), temp_v0 == 0)) {
        return 0;
    }
    Text_DrawTileGrid(temp_v0, arg1, arg2, arg3, arg4, arg5, which);
    Scene_UnlockResource(0, temp_v0);
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_802AAC28_de);
#endif
#endif

#if !(defined(VERSION_EU_X))

/* Appends a pipe synchronisation and an other-mode setting to the display list D_80110634 points
   into, then calls Render_SetModePreset with 0x15 and func_80268CE0_de with 0x19. */

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
    temp_v0 = Render_StartWorldEffect(&g_world, arg0, 0, 1);
    if (temp_v0 != 0)
    {
      func_802AA8EC_de(temp_v0, arg1, &sp10, &sp14);
      new_var = sp10;
      *arg2 = ((ImageSet *)sp10)->width;
      *arg3 = ((ImageSet *)new_var)->height;
      Scene_UnlockResource(0, temp_v0);
    }
  }
}

void Text_SetupFillMode(void) {

    Gfx *gfx;

    gfx = g_displayListCursor++;
    gDPPipeSync(gfx);
    gfx = g_displayListCursor++;
    gDPSetCycleType(gfx, G_CYC_1CYCLE);
    Render_SetModePreset(0x15);
    Render_SetCombineMode(0x19);
}

void func_802AAA54_de(s32 x0,s32 y0,s32 x1,s32 y1,u8 r,u8 g,u8 b,u8 a) {

 gDPPipeSync(g_displayListCursor++);
 gDPSetPrimColor(g_displayListCursor++, 255, 255, r, g, b, a);
 gDPFillRectangle(g_displayListCursor++, ((x0))>((0))?((x0)):((0)), ((y0))>((0))?((y0)):((0)), ((x1))>((0))?((x1)):((0)), ((y1))>((0))?((y1)):((0)));
}

/** Store six words into the global record. */
void func_802AAB3C_de(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    D_801376F8.envR = arg0;
    D_801376F8.envG = arg1;
    D_801376F8.envB = arg2;
    D_801376F8.primR = arg3;
    D_801376F8.primG = arg4;
    D_801376F8.primB = arg5;
}

void func_802AAB68_de(float arg0, float arg1) {
    D_801376F8.width = arg0;
    D_801376F8.height = arg1;
}

void func_802AAB7C_de(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (arg5 != 0) {
        func_802A88F0_de(arg0, arg1, arg2, arg3, arg4, 1, arg6, arg7);
    }
    func_802A88F0_de(arg0, arg1, arg2, arg3, arg4, 0, arg6, arg7);
}

s32 func_802AAC28_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6) {

    s32 temp_v0;

    if ((u32)(D_800E28A4 - (((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) >> 3)) < 0x3E8
        || D_800CD764_de == 0
        || (temp_v0 = Render_StartWorldEffect(&g_world, arg0, 0, 1), temp_v0 == 0)) {
        return 0;
    }
    Text_DrawTileGrid(temp_v0, arg1, arg2, arg3, arg4, arg5, arg6);
    Scene_UnlockResource(0, temp_v0);
    return 1;
}
#endif

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
    handle = Render_StartWorldEffect(&g_world, 2, 0, 1);
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
        Scene_UnlockResource(0, handle);
        D_800D2F90 = D_801470C0_de;
    }
}

/** Return the global word at D_800D2F90. */

u8 *func_802AADBC_de(void) {
    return D_800D2F90;
}

/* Draws a grid of 16-bit image tiles with a 4-bit mask: the header holds the column and row counts,
   each tile holds its width, height, two bytes per pixel and then half a byte per pixel of mask,
   and every tile goes to func_802A9364_de at the running position, advancing x by the tile width and
   y by the last tile height per row. Adapted from func_802AB0B0_de with the mask pointer added. */

extern void func_802A9364_de(s32 *pixels, char *mask, s32 x, s16 y, s32 w, s32 h);

void func_802AADCC_de(u16 *grid, s16 x0, s32 y) {
    s32 *tile;
    s32 rows;
    s32 cols;
    s32 x;
    s32 w;
    s32 h;
    u32 area;

    tile = (s32 *)(grid + 4);
    h = 0;
    rows = grid[1];
    while (--rows != -1) {
        x = x0;
        cols = grid[0];
        while (--cols != -1) {
            w = tile[0];
            h = tile[1];
            area = w * h;
            func_802A9364_de(tile + 2, (char *)tile + (area * 2 + 8), x, y, w, h);
            x += w;
            tile = (s32 *)((char *)tile + (area * 2 + (area >> 1)));
            tile += 2;
        }
        y += h;
    }
}

/* Draws a grid of 16-bit image tiles with a 4-bit mask scaled by sx and sy: the header holds the column
   and row counts, each tile holds its width, height, two bytes per pixel and then half a byte per pixel
   of mask, and every tile goes to Text_DrawScaledMaskedImage at the running float position, advancing x by the
   scaled tile width and y by the scaled last tile height per row. Scaled counterpart of
   func_802AADCC_de; the float counters count down with `rows-- != 0.0f` as in func_802AB1B0_de. */
extern void Text_DrawScaledMaskedImage(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY);
void Text_DrawScaledMaskedTileGrid(u16 *grid, f32 x0, f32 y, f32 sx, f32 sy) {
    u32 *tile;
    f32 rows;
    f32 cols;
    f32 x;
    u32 w;
    u32 h;
    u32 area;

    tile = (u32 *)(grid + 4);
    h = 0;
    rows = grid[1];
    while (rows-- != 0.0f) {
        x = x0;
        cols = grid[0];
        while (cols-- != 0.0f) {
            w = tile[0];
            h = tile[1];
            area = w * h;
            Text_DrawScaledMaskedImage(tile + 2, (char *)tile + (area * 2 + 8), x, y, w, h, sx, sy);
            x += w * sx;
            tile = (u32 *)((char *)tile + (area * 2 + (area >> 1)));
            tile += 2;
        }
        y += h * sy;
    }
}
