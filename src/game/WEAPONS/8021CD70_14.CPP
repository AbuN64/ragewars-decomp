#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"

/* Starts the effect at offset 0x740 of an object through GraphU64_EaseValueToward at half intensity, with a
   level taken from the owner at offset 0x18 scaled by D_800C7A38[0], or D_800C7A38[1] without an
   owner. */




extern void GraphU64_EaseValueToward(f32 *value, f32 target, f32 rate);




void Weapons_EaseOwnerHeightEffect(struct Object *object) {
    f32 level;

    if (object->owner != 0) {
        level = object->owner->height * D_800C7A38[0];
    } else {
        level = D_800C7A38[1];
    }
    GraphU64_EaseValueToward(&object->effect740, level, 0.5f);
}
