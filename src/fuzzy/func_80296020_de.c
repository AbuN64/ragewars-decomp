#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802624A0.h"
#include "shared/func_8044DA54_de_closed.h"
#include "span_1000/code_80286050.h"

s32 func_80263154_de(BitReader *, s32);

void func_80296020_de(void *storage, s32 first, s32 second,
                     DraftStreamData *source, Vec3 *position) {
    ResourceBitGrid *grid = storage;
    union { s32 word; f32 value; } bounds[6];
    s32 count, selected, i, row, column, code, skip;
    grid->parameter8 = first;
    grid->parameterC = second;
    count = source->count;
    selected = 1;
    if ((u32)count > 1U) {
        do {
            grid->reader.data = func_8028FDB4_de(&source->count, selected);
            grid->reader.bitPos = 0;
            for (i = 0; i < 6; i++) bounds[i].word = func_80263154_de(&grid->reader, 32);
            if (bounds[0].value < position->x && position->x < bounds[3].value &&
                bounds[1].value < position->y && position->y < bounds[4].value &&
                bounds[2].value < position->z && position->z < bounds[5].value) break;
            selected++;
        } while ((u32)selected < (u32)count);
    }
    if (selected == count) {
        grid->reader.data = func_8028FDB4_de(&source->count, 0);
        grid->reader.bitPos = 0;
    }
    for (row = 0; row < 17; row++) {
        for (column = 0; column < 17; column++) {
            code = func_80263154_de(&grid->reader, 2);
            switch (code) {
            case 1: grid->cells[row][column] = -2; break;
            case 0: grid->cells[row][column] = -3; break;
            case 2: grid->cells[row][column] = 0; break;
            case 3: grid->cells[row][column] = 3; break;
            }
        }
    }
    for (row = 0; row < 17; row++) {
        for (column = 0; column < 17; column++) {
            if (grid->cells[row][column] == 0) {
                grid->cells[row][column] = (u16)grid->reader.bitPos;
                skip = func_80263154_de(&grid->reader, 9);
                grid->reader.bitPos += skip;
            }
        }
    }
}
