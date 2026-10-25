#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "MENU_2/80420E90.H"
extern NumberPadScreen *D_800E4400;
extern MenuWidget *func_8040EC30_de(void *, s32);

/* Copies the four checkboxes at 0xC to 0x18 of the screen D_800E4400 into the game flags word
   D_801462C8, setting or clearing bits 0x08000000, 0x10000000, 0x8 and 0x20000000 as
   func_8041AD04_de reports each box checked. */





extern struct Shape_func_8021A2D4_de_2 D_801462C8;

extern s32 func_8041AD04_de(void *);

/* Updates the limit markers of the screen D_800E4400: totals func_80426004_de over the four 400-byte
   records of D_80102B00 whose owner byte 0xD is not negative (or takes 40 when the word at 0x38 is
   1), enables items 0x3B4, 0x3B1, 0x3AD and 0x3AF of the window at 0x8 through func_8040E950_de, then
   disables 0x3B1 from a total of 10, 0x3B4 from 6, 0x3AD from 12 and 0x3AF from 14. Written from
   the assembly. */



extern s8 D_80102B0D[];

extern s32 func_80426004_de(s32);

extern void Frontend_SetWidgetFlag100(MenuWidget *record, int enable);

#if defined(VERSION_DE)
enum { MENU_804212A4_941 = 935, MENU_804212A4_943 = 937, MENU_804212A4_945 = 939, MENU_804212A4_948 = 942 };
#elif defined(VERSION_EU_X)
enum { MENU_804212A4_941 = 950, MENU_804212A4_943 = 952, MENU_804212A4_945 = 947, MENU_804212A4_948 = 944 };
#else
enum { MENU_804212A4_941 = 941, MENU_804212A4_943 = 943, MENU_804212A4_945 = 945, MENU_804212A4_948 = 948 };
#endif

/* Resets the number pad of the screen D_800E4400: shows the item at 0x20, hides item 0x3AB of the
   window at 0x8, sets the words at 0x2C, 0x28, 0x30 and 0x34 to 1, 8, 0 and 0, then for keys 0 to
   9 takes item 0x3B8 plus the key, sets its alpha to 0x96 and clears its word at 0x38, and
   finishes through func_80421568_de. */



extern void Frontend_SetWidgetFlag08(void *, s32);

extern void func_80421568_de();

#if defined(VERSION_DE)
enum { MENU_8042144C_939 = 933, MENU_8042144C_952 = 946, MENU_8042144C_953 = 947, MENU_8042144C_954 = 948, MENU_8042144C_955 = 949, MENU_8042144C_956 = 950, MENU_8042144C_957 = 951, MENU_8042144C_958 = 952, MENU_8042144C_959 = 953, MENU_8042144C_960 = 954, MENU_8042144C_961 = 955 };
#elif defined(VERSION_EU_X)
enum { MENU_8042144C_939 = 943, MENU_8042144C_952 = 956, MENU_8042144C_953 = 957, MENU_8042144C_954 = 958, MENU_8042144C_955 = 959, MENU_8042144C_956 = 960, MENU_8042144C_957 = 961, MENU_8042144C_958 = 962, MENU_8042144C_959 = 963, MENU_8042144C_960 = 964, MENU_8042144C_961 = 965 };
#else
enum { MENU_8042144C_939 = 939, MENU_8042144C_952 = 952, MENU_8042144C_953 = 953, MENU_8042144C_954 = 954, MENU_8042144C_955 = 955, MENU_8042144C_956 = 956, MENU_8042144C_957 = 957, MENU_8042144C_958 = 958, MENU_8042144C_959 = 959, MENU_8042144C_960 = 960, MENU_8042144C_961 = 961 };
#endif

void func_804210E8_de(void) {
    if (func_8041AD04_de(D_800E4400->buttons[0]) == 0) {
        D_801462C8.field_0 &= ~0x08000000;
    } else {
        D_801462C8.field_0 |= 0x08000000;
    }
    if (func_8041AD04_de(D_800E4400->buttons[1]) == 0) {
        D_801462C8.field_0 &= ~0x10000000;
    } else {
        D_801462C8.field_0 |= 0x10000000;
    }
    if (func_8041AD04_de(D_800E4400->buttons[2]) == 0) {
        D_801462C8.field_0 &= ~0x8;
    } else {
        D_801462C8.field_0 |= 0x8;
    }
    if (func_8041AD04_de(D_800E4400->buttons[3]) == 0) {
        D_801462C8.field_0 &= ~0x20000000;
    } else {
        D_801462C8.field_0 |= 0x20000000;
    }
}

void func_80421234_de(void) {
    s32 total;
    s32 i;

    total = 0;
    for (i = 0; i < 4; i++) {
        if (D_80102B0D[i * 400] >= 0) {
            total += func_80426004_de(i);
        }
    }
    if (D_800E4400->full == 1) {
        total = 40;
    }
    Frontend_SetWidgetFlag100(func_8040EC30_de(D_800E4400->window, MENU_804212A4_948), 1);
    Frontend_SetWidgetFlag100(func_8040EC30_de(D_800E4400->window, MENU_804212A4_945), 1);
    Frontend_SetWidgetFlag100(func_8040EC30_de(D_800E4400->window, MENU_804212A4_941), 1);
    Frontend_SetWidgetFlag100(func_8040EC30_de(D_800E4400->window, MENU_804212A4_943), 1);
    if (total >= 10) {
        Frontend_SetWidgetFlag100(func_8040EC30_de(D_800E4400->window, MENU_804212A4_945), 0);
    }
    if (total >= 6) {
        Frontend_SetWidgetFlag100(func_8040EC30_de(D_800E4400->window, MENU_804212A4_948), 0);
    }
    if (total >= 12) {
        Frontend_SetWidgetFlag100(func_8040EC30_de(D_800E4400->window, MENU_804212A4_941), 0);
    }
    if (total >= 14) {
        Frontend_SetWidgetFlag100(func_8040EC30_de(D_800E4400->window, MENU_804212A4_943), 0);
    }
}

void func_804213DC_de(void) {
    MenuWidget *item;
    s32 key;

    Frontend_SetWidgetFlag08(D_800E4400->pad, 1);
    Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E4400->window, MENU_8042144C_939), 0);
    D_800E4400->mode = 1;
    D_800E4400->length = 8;
    D_800E4400->value = 0;
    D_800E4400->cursor = 0;
    for (key = 0; key < 10; key++) {
        switch (key) {
        case 1:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_953);
            break;
        case 2:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_954);
            break;
        case 3:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_955);
            break;
        case 4:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_956);
            break;
        case 5:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_957);
            break;
        case 6:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_958);
            break;
        case 7:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_959);
            break;
        case 8:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_960);
            break;
        case 9:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_961);
            break;
        case 0:
        default:
            item = func_8040EC30_de(D_800E4400->window, MENU_8042144C_952);
            break;
        }
        item->alpha = 0x96;
        item->word38 = 0;
    }
    func_80421568_de();
}
