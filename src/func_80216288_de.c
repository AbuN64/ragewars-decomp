#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"

/* The call sites in func_8026835C_de, func_8026E5E0_de and func_8026740C_de
 * pass a fourth incoming slot; the callee never reads it. The signature here
 * is the one those callers and this definition agree on across the ROM. */

extern f32 D_800C21C0_de[];
extern char D_8011D8D0;

extern void func_8024E79C_de(void *actor, Triple input, Triple *output,
                          s32 *actorField, s32 unused0, s32 unused1);
extern void func_8024796C_de(Vector4f *result, CActor_t *actor);
extern s32 func_8024BE80_de(CActor_t *actor);
extern void func_8024F478_de(Vector4f *result, CActor_t *actor);
extern void func_802800C0_de(void *system, CActor_t *source, CActor_t *owner,
                          s32 arg3, s32 eventValue, s32 arg1,
                          Vec3 position, Vector4f rotation,
                          Triple input, s32 arg16, s32 arg17, s32 mode);

void func_80216288_de(void *actor, s32 arg1, Triple input, s32 unused0) {
    Triple copiedInput;
    Vec3 position;
    Vector4f rotation;
    s32 actorField;
    CActor_t *typedActor;
    s32 mode;
    s32 eventValue;
    s32 value;

    typedActor = 0;
    mode = 1;
    func_8024E79C_de(actor, input, &copiedInput, &actorField, 0, mode);
    eventValue = 0;

    switch (((CActor_t *)actor)->type) {
    case 0:
    case 2:
        position.x = position.y = position.z = 0.0f;
        rotation.x = rotation.y = rotation.z = 0.0f;
        rotation.w = D_800C21C0_de[1];
        break;

    case 1:
        typedActor = actor;
        position = typedActor->position;
        func_8024796C_de(&rotation, typedActor);
        eventValue = typedActor->eventValue;
        if (func_8024BE80_de(typedActor) == 5) {
            mode = 3;
        }
        break;

    case 3:
        position = ((CActor_t *)actor)->position;
        func_8024F478_de(&rotation, actor);
        break;
    }

    func_802800C0_de(&D_8011D8D0, actor, actor, 0, eventValue, arg1,
                  position, rotation, copiedInput, 0, -1, mode);

    if ((((CActor_t *)actor)->type == 1) && (typedActor->objectId == 0x40C)) {
        value = typedActor->eventCount - 1;
        if (value < 0) {
            value = 0;
        }
        typedActor->eventCount = value;
    }
}
