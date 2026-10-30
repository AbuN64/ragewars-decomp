#include "MENU/PICKUP_DRAWSCALEDINTENSITYTILEGRID.H"
#include "include_asm.h"
#include "TYPES.H"
#include "ONSCRN/ONSCREEN_DRAWSCALEDMASKEDTILEGRID.H"
extern void Hud_EmptyCallback(void);

extern void Lists_InitFromPool(void *lists, void *pool, s32 stride, s32 count);
extern void Lists_ClearHeader(void *list);
extern s32 Lists_Append(void *list, void *node);
extern void List_InitializeIntrusive(void *list, s32 nextOffset, s32 prevOffset);
extern void List_AppendIntrusive(void *list, void *node);
extern void Fx_UpdateEffectLists(s32 owner);
extern void OnScreen_InitMover(void *mover, s16 x, s16 y);
extern unsigned char g_hudPrimaryByteLookupSource[];
extern unsigned char g_hudSecondaryByteLookupSource[];
extern s32 g_hudFirstPanelMoverScript;
extern s32 g_hudSecondPanelMoverScript;


typedef struct ActorWorld {
    s32 mode;                                  /* +0x0 */
    char pad4[0x2588 - 4];
    s32 cursor;                                /* +0x2588 */
    char pad258C[4];
    char actors[96][0xB8];                   /* +0x2590 */
    char actorList[12];                       /* +0x6A90 */
    char shapePool[32 * 84];               /* +0x6A9C */
    char shapeLists[24];                     /* +0x751C */
    char tailPool[3 * 28];                   /* +0x7534 */
    char tailLists[24];                      /* +0x7588 */
    char records[100][0x50];                  /* +0x75A0 */
    char cells[10][0x14];                      /* +0x94E0 */
    char recordList[20];                     /* +0x95A8 */
} ActorWorld;

typedef struct HudTables {
    char pad0[0x90];
    s32 words[4];                              /* +0x90 */
    char padA0[0xC8 - 0xA0];
    unsigned char tableA[256];               /* +0xC8 */
    unsigned char tableB[256];               /* +0x1C8 */
} HudTables;

typedef struct PanelMovers {
    char first[64];                          /* +0x0 */
    s32 firstTarget;                           /* +0x40 */
    char pad44[4];
    char second[64];                         /* +0x48 */
    s32 secondTarget;                          /* +0x88 */
} PanelMovers;

/* Initialises the actor world: builds the two list pools (0x20 shapes of 0x54 bytes, 3 tails of 0x1C), links the
 * 96 actors of 0xB8 bytes into the actor list, empties the record list and its 10 cells, links the 100 records of
 * 0x50 bytes into it, clears the mode and cursor words and finishes through Fx_UpdateEffectLists. */
void Hud_InitializeWorldActorPools(ActorWorld *world) {
    s32 i;

    Lists_InitFromPool(world->shapeLists, world->shapePool, 84, 32);
    Lists_InitFromPool(world->tailLists, world->tailPool, 28, 3);
    Lists_ClearHeader(world->actorList);
    for (i = 0; i < 96; i++) {
        Lists_Append(world->actorList, world->actors[i]);
    }
    List_InitializeIntrusive(world->recordList, 0, 4);
    for (i = 0; i < 10; i++) {
        List_InitializeIntrusive(world->cells[i], 0, 4);
    }
    for (i = 0; i < 100; i++) {
        List_AppendIntrusive(world->recordList, world->records[i]);
    }
    world->mode = 0;
    world->cursor = 0;
    Fx_UpdateEffectLists(world);
}

/* Resets the hud: clears the four words at 0x90, runs Hud_EmptyCallback and OnScreen_LoadFontTexture, then fills the two
 * 0x100-byte tables at 0xC8 and 0x1C8 from the pair lists g_hudPrimaryByteLookupSource and g_hudSecondaryByteLookupSource (0x75 pairs each, 0x5C in de). */
void Hud_ResetHudCharTables(HudTables *hud) {
#if defined(VERSION_DE)
    s32 pairs = 92;
#else
    s32 pairs = 117;
#endif
    hud->words[0] = 0;
    hud->words[1] = 0;
    hud->words[2] = 0;
    hud->words[3] = 0;
    Hud_EmptyCallback();
    OnScreen_LoadFontTexture();
    Pickup_BuildByteLookup((int)hud, g_hudPrimaryByteLookupSource, pairs, hud->tableA);
    Pickup_BuildByteLookup((int)hud, g_hudSecondaryByteLookupSource, pairs, hud->tableB);
}

void Hud_EmptyCallback(void) {
}
/* Starts the panel's two movers: each is reset to (0, -0x28) and (0, -0x14) with its target word cleared, and
 * given its frame table (g_hudFirstPanelMoverScript, g_hudSecondPanelMoverScript) through OnScreen_StartMoverScript. */
void Hud_StartPanelMovers(PanelMovers *panel) {
    panel->firstTarget = 0;
    OnScreen_InitMover(panel->first, 0, -40);
    OnScreen_StartMoverScript(panel->first, &g_hudFirstPanelMoverScript);
    panel->secondTarget = 0;
    OnScreen_InitMover(panel->second, 0, -20);
    OnScreen_StartMoverScript(panel->second, &g_hudSecondPanelMoverScript);
}
