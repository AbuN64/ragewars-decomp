#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802022E0.h"
#include "types.h"
/* Installs a weapon record's handler table and routine pointers and, when its owner's id is 0x40C,
   clears its counters and sets its rate to 200 and its range and speed from D_800C6B2C and D_800C6B30. */





extern char D_800C8170_de[];
extern void D_002039F8();
extern void D_00203E78();
extern void D_00202E4C();
extern void D_00203DF0();

extern f32 D_800C6B30;

void func_8020388C_de(struct OwnerRecAtE4 *owner, struct RecordRecAt13C *record)
{
    record->table = D_800C8170_de;
    record->first = D_002039F8;
    record->second = D_00203E78;
    record->third = D_00202E4C;
    record->fourth = D_00203DF0;
    if (owner->id == 0x40C) {
        record->a = 0;
        record->b = 0;
        record->fourth = D_00203DF0;
        record->rate = 0xC8;
        record->c = 0;
        record->range = D_800C6B2C;
        record->speed = D_800C6B30;
    }
}
