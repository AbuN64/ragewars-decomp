#include "TYPES.H"

/* Deals out random rewards for `count` entries at difficulty `level`: seeds each
   entry at 5 points and takes the level's budget from D_800E37B8[level * 5 +
   count - 1], then for up to 10001 random picks doubles an entry below 20 points
   while the budget covers it. Each entry finally records mode 4 and its tier
   (points / 10) in the 0x1C-byte D_80153F80 records, and keeps drawing random
   items from the seventeen prizes of that tier in D_800E381C, copying the item's
   name over, until a real item (id != -1) comes up. */

typedef struct {
    s32 id;
    char **name;
} Prize;

typedef struct {
    s32 id;
    s32 tier;
    s32 mode;
    s32 shown;
    char name[12];
} Reward;

extern s32 D_800E37B8[];
extern Prize D_800E381C[][17];
extern Reward D_80153F80[];

extern s32 func_802744D4_de(void);
extern void func_802A025C_de(char *dst, char *src);

void func_8041E81C_de(s32 count, s32 level) {
    s32 points[3];
    s32 *p;
    s32 budget;
    s32 last;
    s32 i;
    s32 *entry;
    s32 value;
    s32 tier;
    s32 pick;
    Prize *prize;

    if (count <= 0) {
        return;
    }
    for (i = 2, p = points + 2; i >= 0; i--) {
        *p-- = 0;
    }
    last = count - 1;
    budget = D_800E37B8[level * 5 + last];
    for (i = 0; i < count; i++) {
        points[i] = 5;
        budget -= 5;
    }
    i = 0;
    while (budget > 0) {
        entry = &points[func_802744D4_de() % count];
        value = *entry;
        if (value < 20 && budget >= value) {
            *entry = value * 2;
            budget -= value;
        }
        if (++i >= 10001) {
            break;
        }
    }
    for (i = 0; i < count; i++) {
        tier = points[i] / 10;
        D_80153F80[i].mode = 4;
        D_80153F80[i].tier = tier;
        D_80153F80[i].shown = tier;
        do {
            pick = func_802744D4_de() % 17;
            prize = &D_800E381C[tier][pick];
            D_80153F80[i].id = prize->id;
            func_802A025C_de(D_80153F80[i].name, *prize->name);
        } while (D_80153F80[i].id == -1);
    }
}
