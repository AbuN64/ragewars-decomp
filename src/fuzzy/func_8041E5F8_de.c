#include "types.h"

typedef struct {
    u8 pad0[0x78];
    u8 enabled;
    u8 pad79[6];
    u8 slot;
    u8 character;
    u8 variant;
    u8 pad82[2];
    char name[13];
    u8 bot;
    u8 mode;
    u8 shown;
    u8 pad94[2];
} Player_u1;
typedef struct { u8 pad0[0xD0]; Player_u1 players[8]; } Game_u1;
typedef union { s32 word; u8 bytes[4]; } Word_u1;
typedef struct { Word_u1 id, tier, mode, shown; char name[12]; } Request_u1;
extern Game_u1 D_801462C8;
extern Request_u1 D_80153F80[];
extern void func_802A025C_de(char *, char *);

void func_8041E5F8_de(void)
{
    Player_u1 *player;
    Player_u1 *probe;
    s32 slot = 7;
    s32 i = 0;
    player = &D_801462C8.players[7];
    do {
        if (slot <= 0) return;
        if (D_80153F80[i].id.word >= 0) {
            probe = &D_801462C8.players[slot];
            while (probe->enabled == 1) {
                probe--;
                slot--;
                player--;
                if (slot <= 0) break;
            }
            if (slot >= 0) {
                player->bot = 1;
                player->enabled = 1;
                player->slot = slot;
                slot--;
                player->character = D_80153F80[i].id.bytes[3];
                player->shown = D_80153F80[i].tier.bytes[3];
                player->mode = D_80153F80[i].mode.bytes[3];
                player->variant = D_80153F80[i].shown.bytes[3];
                func_802A025C_de(player->name, D_80153F80[i].name);
                player--;
            }
        }
        i++;
    } while (i < 3);
}
