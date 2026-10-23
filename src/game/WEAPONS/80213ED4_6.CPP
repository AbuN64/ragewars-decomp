#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

/* The call sites in func_8026835C_de, Fx_DispatchAttachmentEffects and func_8026740C_de
 * pass a fourth incoming slot; the callee never reads it. The signature here
 * is the one those callers and this definition agree on across the ROM. */

extern char D_8011D8D0;

extern void func_8024E79C_de(void *actor, Triple input, Triple *output,
                          s32 *actorField, s32 unused0, s32 unused1);
extern void func_8024796C_de(CQuatern *result, CActor_t *actor);
extern s32 func_8024BE80_de(CActor_t *actor);
extern void func_8024F478_de(CQuatern *result, CActor_t *actor);
#include "particle/8027A0F4_8.H"

void func_80216288_de(void *actor, s32 arg1, Triple input, s32 unused0) {
    Triple copiedInput;
    CVector3 position;
    CQuatern rotation;
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

    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, eventValue, arg1,
                  position, rotation, *(CVector3 *)&copiedInput, 0, -1, mode);

    if ((((CActor_t *)actor)->type == 1) && (typedActor->objectId == 0x40C)) {
        value = typedActor->eventCount - 1;
        if (value < 0) {
            value = 0;
        }
        typedActor->eventCount = value;
    }
}
