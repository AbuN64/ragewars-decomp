#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80203F04.h"
#include "types.h"


extern s32 D_800C8270_de;
extern s32 func_80285F58_de(void *, void *);
extern s32 func_80214178_de(void *, void *, s32);




/** Update actor state and clear flags for the relevant actor classes. */
void func_802044C8_de(SharedPlayer *actor, void *state) {
    s32 flags;

    if (func_80285F58_de(&D_8011FE88, actor) == 1) {
        func_80214178_de(actor, state, 1);
        switch (actor->views1C.viewE4_7.kind) {
        case 0x64C:
            flags = actor->views1C.view100_9.flags & ~0x2000;
            actor->views1C.view100_9.flags = flags & ~0x100;
            break;
        case 0x64B:
        case 0x64E:
            actor->views1C.view100_9.flags &= 0xF7FFFFFF;
            break;
        }
    } else {
        D_800C8270_de = 1;
        func_80214178_de(actor, state, 0);
        D_800C8270_de = 0;
    }
}
