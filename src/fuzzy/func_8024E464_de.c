#include "TYPES.H"
#include "packed_float.h"

typedef struct MeasureObject MeasureObject;
typedef struct MeasureDefinition {
    s32 kind;
    char pad4[0x14];
    f32 value18;
    char pad1C[0x10];
    f32 value2C;
    char pad30[0xC0];
    f32 valueF0;
} MeasureDefinition;
typedef struct MeasureResource {
    char pad0[0x14];
    u16 packedValue;
} MeasureResource;
typedef struct MeasureModel {
    char pad0[0x30];
    MeasureResource *resource;
} MeasureModel;
typedef struct MeasureOwner {
    char pad0[0x80C];
    MeasureObject *redirect;
} MeasureOwner;
struct MeasureObject {
    u8 kind;
    char pad1[0x17];
    MeasureDefinition *definition;
    char pad1C[0xE4];
    u32 flags;
    char pad104[0x14];
    MeasureModel *model;
    char pad11C[0xBC];
    MeasureOwner *owner;
};

f32 func_8024E464_de(MeasureObject *object) {
    MeasureDefinition *definition;
    for (;;) {
        definition = object->definition;
        switch (definition->kind) {
        case 4:
        case 1:
            return definition->value2C;
        case 5:
            return definition->value18;
        case 11:
            if (object->kind == 1 && (object->flags & 0x300000) != 0 &&
                object->owner->redirect != 0) {
                object = object->owner->redirect;
                continue;
            }
            return object->definition->valueF0;
        default:
            if (object->kind != 2) {
                return 0.0f;
            }
            return func_802B2350(object->model->resource->packedValue);
        }
    }
}
