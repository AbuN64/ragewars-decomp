#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_804264F0.h"
#include "types.h"

/* Rebuilds the item list for the player D_800E4690 selects: clears it through func_80428700_de, looks
   up that player's model in D_8011FE88, and for each of the model's eight slot ids at 0x4C that is
   at least 0x4C3 adds the nonzero id less 0x4C3 as the next row through func_8042854C_de when
   func_8022F4DC_de accepts it for the player's 400-byte record in D_80102B00. */





extern struct Screen_func_80428300_de *D_800E4690;
extern s8 D_80142358[];
extern char D_80102B00[];


extern struct Model *func_8028CFA0_de(void *, s32, s32);
extern s32 func_8022F4DC_de(char *, s32);
extern void func_8042854C_de(s32, s32, s32);

void func_80428300_de(void) {
    struct Model *model;
    s32 player;
    s32 id;
    s32 row;
    s32 i;

    func_80428700_de();
    player = D_800E4690->player;
    model = func_8028CFA0_de(&D_8011FE88, 0xB, D_80142358[player * 150]);
    row = 0;
    for (i = 0; i < 8; i++) {
        id = model->slots[i];
        if (id >= 0x4C3) {
            id -= 0x4C3;
            if (func_8022F4DC_de(&D_80102B00[player * 400], id) == 1 && id != 0) {
                func_8042854C_de(row, id, 0);
                row++;
            }
        }
    }
}
