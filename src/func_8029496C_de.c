#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802944E8.h"
#include "types.h"

extern s32 D_800CD780;
extern s32 D_8011B9F0;

extern s32 D_80142898;
extern s32 D_800CD784_de;





extern struct Shape_func_8027ABF4_de_2 D_800E28D0;
extern s8 D_80145040;
extern s32 D_801462C8;

extern int func_8022A414_de(void *arg0);
extern void func_8028D90C_de(void);


/* Initializes the game state for a new game phase with arg0 and updates the game state flag. */
void func_8029496C_de(s32 arg0) {
    s8 *base = &D_801462C8;

    ((ObjectState1E *)(base))->unk_1D = 0;
    D_800CD780 = 0;
    D_8011B9F0 = 0;
    D_80146CB8 = (f32)(D_800E28D0.field_4);
    D_80142898 = 0;
    func_8022A414_de(base - 0x1288);
    D_800CD784_de = 0;
    func_8028D90C_de();
    func_80293998_de(arg0, 0x82);
    D_800CD780 = 1;
    D_800CD784_de = 0;
}
