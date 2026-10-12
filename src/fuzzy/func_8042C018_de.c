#include "types.h"
typedef struct MenuWidget MenuWidget;
struct MenuWidget {
    u8 pad0[4]; MenuWidget *sibling, *child; s16 resource; u8 padE[2];
    u8 alpha; u8 pad11[3]; s16 x, y, width, height; u8 pad1C[16];
    s32 value; MenuWidget *next; s32 field34; void *text;
};
typedef struct MenuPanelRoot {
    u8 reserved0[0xE0]; void *window; s32 reservedE4;
    s32 first; s32 count; s32 players[8]; s32 badges[8];
    char scores[4][25]; char totals[4][25]; char percentages[4][25]; char secondary[4][25];
} MenuPanelRoot;
typedef struct func_8041F2A0_Config {
    s16 total, kills, score, deaths, secondaryStat; u8 reservedA[0x6E]; u8 active; u8 reserved79[7]; s8 character; u8 reserved81[3];
    char name[13]; u8 custom; u8 reserved92; u8 team; u8 reserved94[2];
} func_8041F2A0_Config;
typedef struct ResourceBank { u16 ids[20]; } ResourceBank;
typedef struct Slot_func_8041F140_de { s32 key, value; u8 reserved8[0x68]; } Slot_func_8041F140_de;
extern MenuPanelRoot *D_800E53C0;
extern ResourceBank D_800E12D2[];
extern func_8041F2A0_Config D_80146398[];
extern Slot_func_8041F140_de D_800E3A54[];
extern char D_80102B00[][400];
extern char *D_800DF964[];
extern s32 D_800E01B0_de[], D_800FF140_de[], D_800FEAE0[], D_8014DD98;
void func_8042CC74_de(void);
MenuWidget *func_8040EC30_de(void *, s32);
void func_8040E8D8_de(MenuWidget *, s32);
s32 func_8041F140_de(s32);
char *func_802A0494_de(char *);
char *func_802A025C_de(char *, char *);
char *func_80424DE8_de(s32);
s32 func_802A0C08_de(void *, const char *, ...);
void func_8042D304_de(s32, s32, u16);
void func_8042C018_de(void) {
    s32 row, player, ratio, value;
    MenuWidget *widget;
    func_8041F2A0_Config *config;
    func_8042CC74_de();
    for (row = 0; row < 4; row++) {
        if (row >= D_800E53C0->count) return;
        player = D_800E53C0->players[D_800E53C0->first + row];
        config = &D_80146398[player];
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[0]);
        func_8040E8D8_de(widget, 1); widget->alpha = 150;
        widget->value = D_800E3A54[func_8041F140_de(config->character)].value;
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[2]);
        func_8040E8D8_de(widget, 1); widget->alpha = 25;
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[4]);
        widget->alpha = 175; func_8040E8D8_de(widget, 1);
        if (!config->custom) widget->text = D_80102B00[player];
        else { func_802A025C_de(config->name, func_802A0494_de(config->name)); widget->text = config->name; }
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[6]);
        widget->alpha = 115; func_8040E8D8_de(widget, 1);
        if (!config->custom) widget->text = func_80424DE8_de(player);
        else widget->text = D_800DF964[config->team];
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[8]);
        widget->alpha = 175; func_8040E8D8_de(widget, 1);
        func_802A0C08_de(D_800E53C0->scores[row], "%d", config->score);
        widget->text = D_800E53C0->scores[row];
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[10]);
        widget->alpha = 175; func_8040E8D8_de(widget, 1);
        func_802A0C08_de(D_800E53C0->totals[row], "%d", config->kills + config->total);
        widget->text = D_800E53C0->totals[row];
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[12]);
        if (D_8014DD98 == 0) {
            func_8040E8D8_de(widget, 0);
            func_8042D304_de(player, row, 0x269);
        } else {
            widget->alpha = 175; func_8040E8D8_de(widget, 1);
            ratio = 0;
            if (D_800FF140_de[player] > 0) ratio = D_800FEAE0[player] * 100 / D_800FF140_de[player];
            func_802A0C08_de(D_800E53C0->percentages[row], "%d%%", ratio);
            widget->text = D_800E53C0->percentages[row];
        }
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[14]);
        if (D_8014DD98 == 3) {
            func_8040E8D8_de(widget, 0);
            func_8042D304_de(player, row, 0x26E);
        } else {
            widget->alpha = 175; func_8040E8D8_de(widget, 1);
            value = 0;
            if (!D_8014DD98) value = config->secondaryStat;
            else if (D_8014DD98 == 1) value = config->deaths;
            func_802A0C08_de(D_800E53C0->secondary[row], "%d", value);
            widget->text = D_800E53C0->secondary[row];
        }
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[16]);
        func_8040E8D8_de(widget, 0); widget->alpha = 150;
        widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[18]);
        func_8040E8D8_de(widget, 0); widget->alpha = 150;
        if (!config->custom) {
            if (D_800E53C0->badges[player * 2] != -1) {
                widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[16]);
                func_8040E8D8_de(widget, 1); widget->value = D_800E01B0_de[D_800E53C0->badges[player * 2]];
            }
            if (D_800E53C0->badges[player * 2 + 1] != -1) {
                widget = func_8040EC30_de(D_800E53C0->window, D_800E12D2[row].ids[18]);
                func_8040E8D8_de(widget, 1); widget->value = D_800E01B0_de[D_800E53C0->badges[player * 2 + 1]];
            }
        }
    }
}
