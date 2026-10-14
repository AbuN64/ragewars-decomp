#include "common/types_06e4f7ef1f9e.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"
/* Scrolls a menu one step in the direction its state word at offset 0x54 records: up through
   func_8041A8E8_de for state 0, down through func_8041A910_de for state 1, and returns zero. */



extern void func_8041A8E8_de(struct func_8022FD9C_Record *menu);
extern void func_8041A910_de(struct func_8022FD9C_Record *menu);

s32 func_8041AB1C_de(struct func_8022FD9C_Record *menu)
{
    struct func_8022FD9C_Record *target = menu;

    switch (menu->unk54) {
    case 0:
        func_8041A8E8_de(menu);
        break;
    case 1:
        func_8041A910_de(target);
        break;
    case 2:
        break;
    }
    return 0;
}
