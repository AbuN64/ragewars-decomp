#include "span_1000/code_80217388.h"



/** Reset a record and mark its word at offset 0x6C as invalid. */
void func_80218F84_de(void *record) {
    TeamMenu *menu = record;
    menu->state = 0;
    menu->unused = 0;
    menu->cursor = -1;
    menu->open = 0;
}
