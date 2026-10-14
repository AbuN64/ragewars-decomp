#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802944E8.h"
#include "types.h"

extern s32 D_800CD780;
extern s32 D_8011B9F0;

extern s32 D_80142898;
extern s32 D_800CD784_de;



extern func_80203E78_S1 D_800E28D0;
extern s8 D_80145040;

extern int func_8022A414_de(void *arg0);
extern void func_8028D90C_de(void);


/* Initializes the game state for a new game phase with arg0 as the phase identifier. */
void func_80294848_de(s32 arg0) {
    D_800CD780 = 0;
    D_8011B9F0 = 0;
    D_80146CB8 = (f32)(D_800E28D0.unk4);
    D_80142898 = 0;
    func_8022A414_de(&D_80145040);
    D_800CD784_de = 0;
    func_8028D90C_de();
    func_80293998_de(arg0, 0x82);
}
