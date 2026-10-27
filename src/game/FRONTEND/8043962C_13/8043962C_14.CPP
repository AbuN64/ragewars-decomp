#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "stddef.h"
#include "TYPES.H"

/* Initializes the six object parameters and clears its transient state. */
s32 Frontend_SetPreviewModel(void *, s32);

 /* extern */
void Frontend_SetPreviewRenderFlags(void *, s32);

 /* extern */
s32 Frontend_InitModelPreviewTransform(StateFrontendInitModelPreviewTransform *preview, s32 modelId, Triple first, Triple second) {
    preview->second = second;
    preview->first = first;
    preview->unk1C = 0;
    preview->unk20 = 0;
    preview->unk24 = 0;
    preview->unk28 = 0;
    preview->unk2C = 0;
    preview->unk30 = 0;
    Frontend_SetPreviewModel(preview, modelId);
    Frontend_SetPreviewRenderFlags(preview, 0);
    return preview->unk34;
}

/* Stores a three-word vector passed by value into offset 0x1C of an object. */




void Frontend_SetPreviewRotation(struct ObjRecAt1CV3 *object, struct Triple vector) {
    object->unk1C = vector;
}

/* Returns by value the three-word vector at offset 0x1C of an object. */




struct Triple Frontend_GetPreviewRotation(struct ObjRecAt1CV3 *object) {
    return object->unk1C;
}

/* Stores a three-word vector passed by value into offset 0x28 of an object. */




void Frontend_SetPreviewRotationSpeed(struct ObjectRecAt28 *object, struct Triple vector) {
    object->vector = vector;
}

/* Returns by value the three-word vector at offset 0x28 of an object. */




struct Triple Frontend_GetPreviewRotationSpeed(struct ObjectRecAt28 *object) {
    return object->vector;
}
