#include "COMMON/WORLD.H"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON.H"
extern s32 D_800D2978;

#if !(defined(VERSION_DE))
/* Initialises a placed prop from its record: resets its state and owner, loads its model and caches the squared model radius, builds its rotation from the record's packed quaternion, scale and position into a matrix copied into the object, sets its bounding box either as a fixed cube for flag 0x40 or from the record's six extents through func_802B2350 with a half-unit margin, copies the position, links its path segment and takes the next colour key and colour frame. The fixed cube is written through do-while(0) vector macros, which the stores' order needs, and 102.4 is the cartridge's rounded 0x42CCCCCC. */



extern void InstHdr_ResetInstanceRenderIndices(PlacedProp *, PlacedPropRecord *, s32, char *);
extern PropGeometry *Scene_GetActorDefinition(void *, s32);

extern void MatrixFromQuaternion(f32 *, char *);
extern void ScaleMatrixLocal(char *, f32, f32, f32);
extern void TranslateMatrix(char *, f32, f32, f32);
extern void SwapMatrixUpForward(char *);

extern void CopyMatrix(char *, char *);
extern void GraphU64_ConvertMatrixToFixed(char *, char *);

static inline s32 advancePropKey(void) {
    s32 next;

    next = D_800D0910 + 1;
    D_800D0910 = next;
    if (next == 0x3FFFFF) {
        D_800D0910 = 0x380000;
    }
    return D_800D0910;
}

void World_InitPlacedProp(PlacedProp *prop, PlacedPropRecord *record, s32 owner, char *segments) {
    f32 rotation[4];
    char matrix[0x40];
    PropGeometry *model;

    InstHdr_ResetInstanceRenderIndices(prop, record, owner, segments);
    prop->state = 0;
    prop->id = record->id;
    prop->owner = owner;
    prop->fieldA8 = -1;
    prop->fieldAC = 0;
    prop->fieldB0 = 0;
    prop->fieldB4 = 0;
    prop->model = Scene_GetActorDefinition(&g_world, record->model);
    prop->fade = 16;
    prop->fieldDC = 0;
    model = prop->model;
    model->radiusSquared = model->radius * model->radius;
    prop->flags = record->flags;
    rotation[0] = record->rotation[0] * 0.007874016f;
    rotation[1] = record->rotation[1] * 0.007874016f;
    rotation[2] = record->rotation[2] * 0.007874016f;
    rotation[3] = record->rotation[3] * 0.007874016f;
    func_802741A4_de(rotation);
    MatrixFromQuaternion(rotation, matrix);
    ScaleMatrixLocal(matrix, record->scale.x, record->scale.y, record->scale.z);
    TranslateMatrix(matrix, record->position.x, record->position.y, record->position.z);
    SwapMatrixUpForward(matrix);
    if (prop->flags & 0x40) {
        do { (prop->min).x = (record->position).x - (102.399994f); (prop->min).y = (record->position).y - (102.399994f); (prop->min).z = (record->position).z - (102.399994f); } while (0);
        do { (prop->max).x = (record->position).x + (102.399994f); (prop->max).y = (record->position).y + (102.399994f); (prop->max).z = (record->position).z + (102.399994f); } while (0);
        prop->fieldD4 = D_800CD8D0;
    } else {
        prop->min.x = RW_BITS_TO_FLOAT(record->extents[0]) + record->position.x - 0.5f;
        prop->min.y = RW_BITS_TO_FLOAT(record->extents[1]) + record->position.y - 0.5f;
        prop->min.z = RW_BITS_TO_FLOAT(record->extents[2]) + record->position.z - 0.5f;
        prop->max.x = RW_BITS_TO_FLOAT(record->extents[3]) + record->position.x + 0.5f;
        prop->max.y = RW_BITS_TO_FLOAT(record->extents[4]) + record->position.y + 0.5f;
        prop->max.z = RW_BITS_TO_FLOAT(record->extents[5]) + record->position.z + 0.5f;
        prop->fieldD4 = record->value;
    }
    CopyMatrix(prop->matrix, matrix);
    GraphU64_ConvertMatrixToFixed(matrix, prop->transform);
    prop->position = record->position;
    if (record->segment == 0xFFFF) {
        prop->segment = 0;
    } else {
        prop->segment = segments + record->segment * 32;
    }
    prop->key = advancePropKey() << 10;
    prop->colorFrame = (u8)D_800D2978 - 1;

}
#endif
