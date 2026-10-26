#include "COMMON/PLAYERRECAT64E.H"
#include "MULTI/8043E9A8.H"
#include "TYPES.H"
#include "MULTI/8043E9A8_9.H"

/* Does nothing. Nothing in the cartridge image calls it or stores its address as a word. */
void func_8043F040_de(void) {
}

/* Reports whether an item is available to the player: for item type 0x10FE its index 0-2 must be below the player's count at 0x64D and 3-5 (less three) below the count at 0x64E, and for type 0x1194 the player's flag byte at 0x644 for the index must be set; any other type or index gives zero. */








/* Reports whether an item is available to the player: indices 0-2 and 3-5 of type 0x10FE are checked against the player's two counts, type 0x1194 against its flag table. */
s32 Multi_IsPlayerItemAvailable(struct ItemRecAt18V2 *item, struct HolderMultiIsPlayerItemAvailable *holder) {
    struct ItemDef *def = item->def;
    s32 type = def->type;
    s32 index = def->index;
    struct PlayerRecAt64E *player = holder->player;
    s32 result = 0;

    switch (type) {
    case 0x10FE:
        if (index >= 0) {
            if (index < 3) {
                goto low;
            }
            if (index < 6) {
                goto high;
            }
            break;
        low:
            result = index < player->count64D;
            break;
        high:
            result = index - 3;
            result = result < player->count64E;
        }
        break;
    case 0x1194:
        result = player->flags[index] != 0;
        break;
    }
    return result;
}

/* Calls func_8025E384_de and then returns what Pak_TryCreateMenu gives for the same three arguments. */
extern void func_8025E384_de();
extern s32 Pak_TryCreateMenu(void *, void *, void *);

s32 Multi_CreateMenuWithDefaultMusicGain(void *first, void *second, void *third) {
    func_8025E384_de();
    return Pak_TryCreateMenu(first, second, third);
}
