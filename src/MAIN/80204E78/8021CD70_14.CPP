#include "shared/player_movement_interfaces.h"
#include "span_1000/code_8021CD70.h"
#include "TYPES.H"

/* Starts the effect at offset 0x740 of an object through func_80274870_de at half intensity, with a
   level taken from the owner at offset 0x18 scaled by D_800C7A38[0], or D_800C7A38[1] without an
   owner. */




extern void func_80274870_de(f32 *value, f32 target, f32 rate);




void func_8022404C_de(struct Object *object) {
    f32 level;

    if (object->owner != 0) {
        level = object->owner->height * D_800C7A38[0];
    } else {
        level = D_800C7A38[1];
    }
    func_80274870_de(&object->effect740, level, 0.5f);
}
