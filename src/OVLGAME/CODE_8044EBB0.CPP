#include "include_asm.h"
#include "TYPES.H"
extern void func_8044E0CC_de(void);

extern void func_802795B0_de(void *lists, void *pool, s32 stride, s32 count);
extern void func_802794B0_de(void *list);
extern s32 func_80279508_de(void *list, void *node);
extern void func_80255CA0_de(void *list, s32 nextOffset, s32 prevOffset);
extern void func_80255D14_de(void *list, void *node);
extern void func_802A5680_de(void *world);
extern void func_802AAD14_de(void);
extern void func_802AB35C_de(int unused, unsigned char *pairs, int count, unsigned char *table);
extern void func_802AA6D0_de(void *mover, s16 x, s16 y);
extern s32 func_802AA70C_de(void *mover, s32 *frames);
extern unsigned char D_800D3080[];
extern unsigned char D_800D2F94[];
extern s32 D_800CDE94;
extern s32 D_800CDEA4;


typedef struct ActorWorld {
    s32 mode;                                  /* +0x0 */
    char pad4[0x2588 - 4];
    s32 cursor;                                /* +0x2588 */
    char pad258C[4];
    char actors[0x60][0xB8];                   /* +0x2590 */
    char actorList[0xC];                       /* +0x6A90 */
    char shapePool[0x20 * 0x54];               /* +0x6A9C */
    char shapeLists[0x18];                     /* +0x751C */
    char tailPool[3 * 0x1C];                   /* +0x7534 */
    char tailLists[0x18];                      /* +0x7588 */
    char records[0x64][0x50];                  /* +0x75A0 */
    char cells[10][0x14];                      /* +0x94E0 */
    char recordList[0x14];                     /* +0x95A8 */
} ActorWorld;

typedef struct HudTables {
    char pad0[0x90];
    s32 words[4];                              /* +0x90 */
    char padA0[0xC8 - 0xA0];
    unsigned char tableA[0x100];               /* +0xC8 */
    unsigned char tableB[0x100];               /* +0x1C8 */
} HudTables;

typedef struct PanelMovers {
    char first[0x40];                          /* +0x0 */
    s32 firstTarget;                           /* +0x40 */
    char pad44[4];
    char second[0x40];                         /* +0x48 */
    s32 secondTarget;                          /* +0x88 */
} PanelMovers;

/* Initialises the actor world: builds the two list pools (0x20 shapes of 0x54 bytes, 3 tails of 0x1C), links the
 * 96 actors of 0xB8 bytes into the actor list, empties the record list and its 10 cells, links the 100 records of
 * 0x50 bytes into it, clears the mode and cursor words and finishes through func_802A5680_de. */
void func_8044DF60_de(ActorWorld *world) {
    s32 i;

    func_802795B0_de(world->shapeLists, world->shapePool, 0x54, 0x20);
    func_802795B0_de(world->tailLists, world->tailPool, 0x1C, 3);
    func_802794B0_de(world->actorList);
    for (i = 0; i < 0x60; i++) {
        func_80279508_de(world->actorList, world->actors[i]);
    }
    func_80255CA0_de(world->recordList, 0, 4);
    for (i = 0; i < 10; i++) {
        func_80255CA0_de(world->cells[i], 0, 4);
    }
    for (i = 0; i < 0x64; i++) {
        func_80255D14_de(world->recordList, world->records[i]);
    }
    world->mode = 0;
    world->cursor = 0;
    func_802A5680_de(world);
}

/* Resets the hud: clears the four words at 0x90, runs func_8044E0CC_de and func_802AAD14_de, then fills the two
 * 0x100-byte tables at 0xC8 and 0x1C8 from the pair lists D_800D3080 and D_800D2F94 (0x75 pairs each, 0x5C in de). */
void Ovlgame_ResetHudCharTables(HudTables *hud) {
#if defined(VERSION_DE)
    s32 pairs = 0x5C;
#else
    s32 pairs = 0x75;
#endif
    hud->words[0] = 0;
    hud->words[1] = 0;
    hud->words[2] = 0;
    hud->words[3] = 0;
    func_8044E0CC_de();
    func_802AAD14_de();
    func_802AB35C_de((int)hud, D_800D3080, pairs, hud->tableA);
    func_802AB35C_de((int)hud, D_800D2F94, pairs, hud->tableB);
}

void func_8044E0CC_de(void) {
}
/* Starts the panel's two movers: each is reset to (0, -0x28) and (0, -0x14) with its target word cleared, and
 * given its frame table (D_800CDE94, D_800CDEA4) through func_802AA70C_de. */
void Ovlgame_StartPanelMovers(PanelMovers *panel) {
    panel->firstTarget = 0;
    func_802AA6D0_de(panel->first, 0, -0x28);
    func_802AA70C_de(panel->first, &D_800CDE94);
    panel->secondTarget = 0;
    func_802AA6D0_de(panel->second, 0, -0x14);
    func_802AA70C_de(panel->second, &D_800CDEA4);
}
