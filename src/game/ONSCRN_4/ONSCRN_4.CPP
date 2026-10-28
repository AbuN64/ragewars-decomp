#include "COMMON/EXTERNS_6.H"
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
#include "ONSCRN_4/ONSCRN_4.H"

/* 802A8A94_4.CPP */
s32 OnScreen_UpdateMoverScript(void *);

extern void OnScreen_DrawStatusBar(void *arg0, int arg1);

void OnScreen_InitMover(void *arg0, s16 arg1, s16 arg2)
{
  COverlay *mover = arg0;
  mover->handle = -1;
  mover->active = 0;
  mover->state = 0;
  mover->x = (f32) arg1;
  mover->y = (f32) arg2;
}

s32 OnScreen_StartMoverScript(void *widget, s32 *arg1) {
    (((struct ObjectLinksC_2 *) ((s8 *) widget))->unk_4) = arg1;
    (((struct ObjectLinksC_2 *) ((s8 *) widget))->unk_8) = 2;
    return OnScreen_UpdateMoverScript(widget);
}

s32 OnScreen_StartFirstStatusBar(void *arg0, s32 arg1, s32 arg2) {
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_40) = arg1;
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_3C) = arg2;
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_44) = 0x64;
    return OnScreen_StartMoverScript(arg0, &D_800CDEB4);
}

void OnScreen_StartSecondStatusBar(void *arg0, s32 arg1, s32 arg2) {
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_88) = arg1;
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_84) = arg2;
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_8C) = 0x64;
    OnScreen_StartMoverScript(arg0 + 0x48, &D_800CDEC8);
}

void OnScreen_SetFirstBarTarget(char *object, int value) {
    Hud *hud = (void *)object;
    hud->bars[0].target = value;
}

void OnScreen_SetSecondBarTarget(void *object, int value) {
    Hud *hud = (void *)object;
    hud->bars[1].target = value;
}

void OnScreen_DrawStatusBars(void *playerHud) {
    char pad[256];
    (void)pad;

    if (Tsmos_IsFrontendActive() == 1) {
        Tsmos_UpdateFrontend();
        Geometry_InvalidateMaterialKeys();
        TextLoad_ResetTextureCache();
    }
    OnScreen_SetupTextRendering();
    OnScreen_LoadTextTileModeOne();
    OnScreen_SetTextScale(D_800C61F0_de, D_800C61F0_de);
    OnScreen_SetTextColors(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    OnScreen_SetupSpriteMode(D_801462C8.hudFade);
    if (((Hud *)playerHud)->bars[0].enabled != 0) {
        OnScreen_DrawStatusBar(playerHud, 1);
    }
    if (((Hud *)playerHud)->bars[1].enabled != 0) {
        OnScreen_DrawStatusBar(playerHud, 2);
    }
}

/** Return the floating parameter selected by the current global mode. */
f32 OnScreen_GetGlyphWidth(void) {
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

void OnScreen_GetImageEntry(Table802AB8DC **handle, s32 index, void **out, u8 *tag) {
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

extern s32 Scene_StartWorldEffect(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void Cache_UnlockResource(s32 arg0, s32 arg1);
extern void Geometry_SetModePreset(u32);
extern void Geometry_SetCombineMode(u32);

#if defined(VERSION_EU_X)
void OnScreen_GetImageDimensions(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3)
{
  void *sp10;
  s32 sp14;
  void *imageData;
  s32 temp_v0;
  if (D_800CD764_de != 0)
  {
    temp_v0 = Scene_StartWorldEffect(&g_world, arg0, 0, 1);
    if (temp_v0 != 0)
    {
      OnScreen_GetImageEntry(temp_v0, arg1, &sp10, &sp14);
      imageData = sp10;
      *arg2 = ((ImageSet *)sp10)->width;
      *arg3 = ((ImageSet *)imageData)->height;
      Cache_UnlockResource(0, temp_v0);
    }
  }
}
#endif

#if defined(VERSION_EU_X)
void OnScreen_SetupFillMode(void) {

    Gfx *gfx;

    gfx = g_displayListCursor++;
    gDPPipeSync(gfx);
    gfx = g_displayListCursor++;
    gDPSetCycleType(gfx, G_CYC_1CYCLE);
    Geometry_SetModePreset(0x15);
    Geometry_SetCombineMode(0x19);
}
#endif

#if defined(VERSION_EU_X)
void OnScreen_FillRectangle(s32 x0,s32 y0,s32 x1,s32 y1,u8 r,u8 g,u8 b,u8 a) {

 gDPPipeSync(g_displayListCursor++);
 gDPSetPrimColor(g_displayListCursor++, 255, 255, r, g, b, a);
 gDPFillRectangle(g_displayListCursor++, ((x0))>((0))?((x0)):((0)), ((y0))>((0))?((y0)):((0)), ((x1))>((0))?((x1)):((0)), ((y1))>((0))?((y1)):((0)));
}
#endif

#if defined(VERSION_EU_X)
extern s32 Scene_StartWorldEffect(void *,s32,s32,s32);
extern void Cache_UnlockResource(s32,s32);

void OnScreen_SetTextColors(int arg0, int arg1, int arg2, int alpha, int arg4, int arg5) {
    D_801376F8.envR = arg0;
    D_801376F8.envG = arg1;
    D_801376F8.envB = arg2;
    D_801376F8.primR = alpha;
    D_801376F8.primG = arg4;
    D_801376F8.primB = arg5;
}
#endif

#if defined(VERSION_EU_X)
void OnScreen_SetTextScale(float arg0, float arg1) {
    D_801376F8.width = arg0;
    D_801376F8.height = arg1;
}
#endif

#if defined(VERSION_EU_X)
void OnScreen_DrawTextWithShadow(u8 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 alpha, s32 arg7) {
    if (arg5 != 0) {
        OnScreen_DrawTextGlyphs(arg0, arg1, arg2, arg3, arg4, 1, alpha, arg7);
    }
    OnScreen_DrawTextGlyphs(arg0, arg1, arg2, arg3, arg4, 0, alpha, arg7);
}
#endif

#if !(defined(VERSION_EU_X))

/* Appends a pipe synchronisation and an other-mode setting to the display list D_80110634 points
   into, then calls Geometry_SetModePreset with 0x15 and func_80268CE0_de with 0x19. */

/* Emits pipe sync, primitive color and a rectangle with nonnegative coordinates. */

extern void Text_DrawTileGrid(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);

void OnScreen_GetImageDimensions(s32 arg0, s32 arg1, s32 *outWidth, s32 *outHeight)
{
  void *image;
  s32 imageTag;
  void *new_var;
  s32 temp_v0;
  if (D_800CD764_de != 0)
  {
    temp_v0 = Scene_StartWorldEffect(&g_world, arg0, 0, 1);
    if (temp_v0 != 0)
    {
      OnScreen_GetImageEntry(temp_v0, arg1, &image, &imageTag);
      new_var = image;
      *outWidth = ((ImageSet *)image)->width;
      *outHeight = ((ImageSet *)new_var)->height;
      Cache_UnlockResource(0, temp_v0);
    }
  }
}

void OnScreen_SetupFillMode(void) {

    Gfx *gfx;

    gfx = g_displayListCursor++;
    gDPPipeSync(gfx);
    gfx = g_displayListCursor++;
    gDPSetCycleType(gfx, G_CYC_1CYCLE);
    Geometry_SetModePreset(0x15);
    Geometry_SetCombineMode(0x19);
}

void OnScreen_FillRectangle(s32 x0,s32 y0,s32 x1,s32 y1,u8 r,u8 g,u8 b,u8 a) {

 gDPPipeSync(g_displayListCursor++);
 gDPSetPrimColor(g_displayListCursor++, 255, 255, r, g, b, a);
 gDPFillRectangle(g_displayListCursor++, ((x0))>((0))?((x0)):((0)), ((y0))>((0))?((y0)):((0)), ((x1))>((0))?((x1)):((0)), ((y1))>((0))?((y1)):((0)));
}

/** Store six words into the global record. */
void OnScreen_SetTextColors(int environmentRed, int environmentGreen, int environmentBlue, int primitiveRed, int primitiveGreen, int primitiveBlue) {
    D_801376F8.envR = environmentRed;
    D_801376F8.envG = environmentGreen;
    D_801376F8.envB = environmentBlue;
    D_801376F8.primR = primitiveRed;
    D_801376F8.primG = primitiveGreen;
    D_801376F8.primB = primitiveBlue;
}

void OnScreen_SetTextScale(float horizontalScale, float verticalScale) {
    D_801376F8.width = horizontalScale;
    D_801376F8.height = verticalScale;
}

void OnScreen_DrawTextWithShadow(s32 arg0, f32 x, f32 arg2, f32 width, f32 height, s32 arg5, s32 arg6, s32 language) {
    if (arg5 != 0) {
        OnScreen_DrawTextGlyphs(arg0, x, arg2, width, height, 1, arg6, language);
    }
    OnScreen_DrawTextGlyphs(arg0, x, arg2, width, height, 0, arg6, language);
}

#endif

extern void Text_DrawTileGrid(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);
s32 OnScreen_DrawSpriteResource(s32 resourceId, s32 index, s16 arg2, s16 y, f32 scaleX, f32 scaleY, s32 arg6) {

    s32 resourceHandle;

    if ((u32)(D_800E28A4 - (((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) >> 3)) < 0x3E8
        || D_800CD764_de == 0
        || (resourceHandle = Scene_StartWorldEffect(&g_world, resourceId, 0, 1), resourceHandle == 0)) {
        return 0;
    }
    Text_DrawTileGrid(resourceHandle, index, arg2, y, scaleX, scaleY, arg6);
    Cache_UnlockResource(0, resourceHandle);
    return 1;
}

extern u8 D_801470C0_de[0x90];
extern void *func_802BD3A0_de(void *, const void *, int);
typedef struct ResourceView {
    u8 *data;
    u8 type;
} ResourceView;
void OnScreen_LoadFontTexture(void) {
    Table802AB8DC **handle;
    Table802AB8DC *table;
    Entry802AB8DC *entry;
    ResourceView view;
    u8 entryTag;
    s32 remainder;
    void *result;
    void *base;
    g_onScreenFontTexture = 0;
    handle = Scene_StartWorldEffect(&g_world, 2, 0, 1);
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
        Cache_UnlockResource(0, handle);
        g_onScreenFontTexture = D_801470C0_de;
    }
}

/** Return the global word at g_onScreenFontTexture. */

u8 *OnScreen_GetFontTexture(void) {
    return g_onScreenFontTexture;
}

/* Draws a grid of 16-bit image tiles with a 4-bit mask: the header holds the column and row counts,
   each tile holds its width, height, two bytes per pixel and then half a byte per pixel of mask,
   and every tile goes to OnScreen_DrawTextureWithOpacity at the running position, advancing x by the tile width and
   y by the last tile height per row. Adapted from Pickup_DrawIntensityTileGrid with the mask pointer added. */

extern void OnScreen_DrawTextureWithOpacity(s32 *pixels, char *mask, s32 x, s16 y, s32 w, s32 h);

void OnScreen_DrawMaskedTileGrid(u16 *grid, s16 x0, s32 y) {
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
            OnScreen_DrawTextureWithOpacity(tile + 2, (char *)tile + (area * 2 + 8), x, y, w, h);
            x += w;
            tile = (s32 *)((char *)tile + (area * 2 + (area >> 1)));
            tile += 2;
        }
        y += h;
    }
}

/* Draws a grid of 16-bit image tiles with a 4-bit mask scaled by sx and sy: the header holds the column
   and row counts, each tile holds its width, height, two bytes per pixel and then half a byte per pixel
   of mask, and every tile goes to OnScreen_DrawScaledMaskedImage at the running float position, advancing x by the
   scaled tile width and y by the scaled last tile height per row. Scaled counterpart of
   OnScreen_DrawMaskedTileGrid; the float counters count down with `rows-- != 0.0f` as in Pickup_DrawScaledIntensityTileGrid. */
extern void OnScreen_DrawScaledMaskedImage(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY);
void OnScreen_DrawScaledMaskedTileGrid(u16 *grid, f32 x0, f32 y, f32 sx, f32 sy) {
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
            OnScreen_DrawScaledMaskedImage(tile + 2, (char *)tile + (area * 2 + 8), x, y, w, h, sx, sy);
            x += w * sx;
            tile = (u32 *)((char *)tile + (area * 2 + (area >> 1)));
            tile += 2;
        }
        y += h * sy;
    }
}
