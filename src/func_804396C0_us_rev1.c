/* Opens screen D_800E5950: reserves the screen block, clears the game-object pool and the course
 * state, resets the world record when no mode flag is set, opens window 0x397 on the tree given by
 * arg0, marks the settings bytes at 0x24/0x25 of the match block D_801462C8 with 10, and resets the
 * four player slots. */
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "shared/func_80286080_de_closed.h"
#include "shared/world.h"
#include "types.h"

struct Tree;
struct ObjectPool;
typedef struct ObjectPool ObjectPool;

struct Record_func_804396C0_us_rev1 {
    char pad0[0x78];
    s8 unk78;
    char pad79[0x96 - 0x79];
};

/* Every address in the original unit folds against the block's 0x48 member (the published scalar is a char, so its index 0x48 lands there): the first materialized
 * pointer is lui 0x8014 / addiu 20616, the pool base is that anchor minus 72, and the record table
 * sits on the same anchor at 5930. A view whose offset 0 is the 0x48 member reproduces that order. */
typedef struct {
    char unk48[0x1310];
    struct Record_func_804396C0_us_rev1 records[8];
} GameBlock48_func_804396C0_us_rev1;

typedef struct {
    char pad0[0x24];
    s8 unk24;
    s8 unk25;
} Settings_func_804396C0_us_rev1;

typedef struct {
    s32 window;
    s32 unk4;
} PulseScreen_func_804396C0_us_rev1;

typedef struct {
    char pad0[0x190];
} PlayerSlot_func_804396C0_us_rev1;

extern void func_8022EF30_de(void *arg0);
extern int func_8025477C_de(void);
extern void func_80286AA8_de(void *arg0, s32 arg1, s32 arg2);
extern void func_802A2400_de(float value);
extern void func_8040C428_de(s32 value);
extern void func_804499B0_de(ObjectPool *pool, s32 count, s32 force_active);
extern void func_8044A370_de(void *, s32);

extern PlayerSlot_func_804396C0_us_rev1 D_80102B00[];
extern PulseScreen_func_804396C0_us_rev1 *D_800E5950;

s32 func_804396C0_us_rev1(struct Tree *arg0) {
    s32 i;
    Settings_func_804396C0_us_rev1 *settings;
    struct Record_func_804396C0_us_rev1 *rec;
    GameBlock48_func_804396C0_us_rev1 *game;

    D_800E5950 = (PulseScreen_func_804396C0_us_rev1 *) func_8025305C_de(8);
    game = (GameBlock48_func_804396C0_us_rev1 *) &(&D_80145040)[0x48];
    func_8044A370_de(game->unk48, 0);
    func_804499B0_de((ObjectPool *) &D_80145040, 0, 0);
    func_80286AA8_de(&D_8011FE88, 0, 0);
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
    func_8040C428_de(0);
    i = 7;
    func_802A2394_de();
    rec = &game->records[7];
    do {
        rec->unk78 = 0;
        i--;
        rec--;
    } while (i >= 0);
    D_800E5950->window = (s32) func_8040EC30_de(arg0, 0x397);
    D_800E5950->unk4 = 0;
    settings = (Settings_func_804396C0_us_rev1 *) (&D_801462C8);
    settings->unk24 = 10;
    settings->unk25 = 10;
    for (i = 0; i < 4; i++) {
        func_8022EF30_de(&D_80102B00[i]);
    }
    func_802A2400_de(0.0f);
    return 0;
}
