#include "span_16E000/code_80420E90.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"
#include "span_16E000/code_80420E90.h"

/* Resets the number pad of the screen D_800E4400: shows the item at 0x20, hides item 0x3AB of the
   window at 0x8, sets the words at 0x2C, 0x28, 0x30 and 0x34 to 1, 8, 0 and 0, then for keys 0 to
   9 takes item 0x3B8 plus the key, sets its alpha to 0x96 and clears its word at 0x38, and
   finishes through func_80421568_de. */

extern NumberPadScreen *D_800E4400;
extern MenuWidget *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(void *, s32);
extern void func_80421568_de();

#if defined(VERSION_DE)
enum { MENU_8042144C_939 = 933, MENU_8042144C_952 = 946, MENU_8042144C_953 = 947, MENU_8042144C_954 = 948, MENU_8042144C_955 = 949, MENU_8042144C_956 = 950, MENU_8042144C_957 = 951, MENU_8042144C_958 = 952, MENU_8042144C_959 = 953, MENU_8042144C_960 = 954, MENU_8042144C_961 = 955 };
#elif defined(VERSION_EU_X)
enum { MENU_8042144C_939 = 943, MENU_8042144C_952 = 956, MENU_8042144C_953 = 957, MENU_8042144C_954 = 958, MENU_8042144C_955 = 959, MENU_8042144C_956 = 960, MENU_8042144C_957 = 961, MENU_8042144C_958 = 962, MENU_8042144C_959 = 963, MENU_8042144C_960 = 964, MENU_8042144C_961 = 965 };
#else
enum { MENU_8042144C_939 = 939, MENU_8042144C_952 = 952, MENU_8042144C_953 = 953, MENU_8042144C_954 = 954, MENU_8042144C_955 = 955, MENU_8042144C_956 = 956, MENU_8042144C_957 = 957, MENU_8042144C_958 = 958, MENU_8042144C_959 = 959, MENU_8042144C_960 = 960, MENU_8042144C_961 = 961 };
#endif

void func_804213DC_de(void) {
    MenuWidget *item;
    s32 key;

    func_8040E8D8_de(D_800E4400->pad, 1);
    func_8040E8D8_de(func_8040EC30_de(D_800E4400->window, MENU_8042144C_939), 0);
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
