#include "types.h"
#include "span_16E000/code_80420E90.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "common/unused.h"
#include "shared/func_80421E70_eu_closed.h"

void func_80421568_de(void) {
    MenuWidget *item;
    char *text;
    s32 line;
    s32 index;

    line = D_800E4400->length;
    index = D_800E4400->value;
    do {
        text = D_800D3E14_de[0][index];

        if (text != 0) {
            index++;
        }
        item = func_8040EC30_de(D_800E4400->window, 952);
        switch (line) {
        case 0:
            item = func_8040EC30_de(D_800E4400->window, 952);
            break;
        case 1:
            item = func_8040EC30_de(D_800E4400->window, 953);
            break;
        case 2:
            item = func_8040EC30_de(D_800E4400->window, 954);
            break;
        case 3:
            item = func_8040EC30_de(D_800E4400->window, 955);
            break;
        case 4:
            item = func_8040EC30_de(D_800E4400->window, 956);
            break;
        case 5:
            item = func_8040EC30_de(D_800E4400->window, 957);
            break;
        case 6:
            item = func_8040EC30_de(D_800E4400->window, 958);
            break;
        case 7:
            item = func_8040EC30_de(D_800E4400->window, 959);
            break;
        case 8:
            item = func_8040EC30_de(D_800E4400->window, 960);
            break;
        case 9:
            item = func_8040EC30_de(D_800E4400->window, 961);
            break;
        }
        item->text = text;
        line++;
    } while (line < 10);
        if (D_800D3E14_de[0][D_800E4400->value] != 0)

    {
        if (D_800E4400->length == 0) {
            D_800E4400->value++;
        }
    } else {
        func_8040E8D8_de(D_800E4400->pad, 0);
        func_8040E8D8_de(func_8040EC30_de(D_800E4400->window, 939), 1);
        D_800E4400->cursor = 1;
    }
    if (D_800E4400->length > 0) {
        D_800E4400->length--;
    }
}
