#include "COMMON/SCENERECAT10C0.H"
#include "SCENE/80286050.H"
#include "TYPES.H"

/* Collects up to sixteen switch objects (descriptor type 0xD) of a world into its switch list, first syncing each one's flag 4 with the switch table D_800E4680 when its kind is 0xD34 to 0xD37: model 0xD2B follows table byte 1, models 0xD2C to 0xD2E follow their own table byte, and any other model clears the flag; the flag is set when the byte is zero. */







extern unsigned char *D_800E4680;

void func_80286950_de(WorldRecAt1B660 *world) {
    ObjectRecAt18 *object;
    DescriptorRecAt20 *descriptor;
    s32 found;
    s32 i;

    found = 0;
    object = world->objects;
    world->switchCount = 0;
    for (i = 15; i >= 0; i--) {
        world->switches[i] = 0;
    }
    for (i = 0; i < world->count; object++, i++) {
        descriptor = object->descriptor;
        if (descriptor->type == 0xD) {
            if (D_800E4680 != 0 && (unsigned)(descriptor->kind - 0xD34) < 4) {
                switch (descriptor->model) {
                case 0xD2B:
                    if (D_800E4680[1] == 0) {
                        descriptor->flags |= 4;
                    } else {
                        descriptor->flags &= ~4;
                    }
                    break;
                case 0xD2C:
                case 0xD2D:
                case 0xD2E:
                    if (D_800E4680[object->descriptor->model - 0xD2A] == 0) {
                        object->descriptor->flags |= 4;
                        break;
                    }
                default:
                    object->descriptor->flags &= ~4;
                    break;
                }
            }
            world->switches[found] = object;
            found++;
        }
        if (found >= 16) {
            break;
        }
    }
    world->switchCount = found;
}
