#include "types.h"
#include "common/types_8a8189af7b05.h"

typedef struct DraftPackedMatrix { u32 upper[8], lower[8]; } DraftPackedMatrix;
typedef struct DraftLight {
    char pad0[0x20]; f32 matrix[16];
    char pad60[0x40]; Vec3 minimum, maximum;
    u8 flagB8, flagB9, mode, padBB, colour;
} DraftLight;
typedef struct DraftLitVertex {
    s16 x, y, z; u16 flags; s16 s, t;
    s8 nx, ny, nz; u8 alpha;
} DraftLitVertex;
typedef struct DraftLitMesh { s32 stride, count; DraftLitVertex vertices[1]; } DraftLitMesh;
extern f32 D_800C4ADC_de, D_800C4AE0_de, D_800C4AE4_de, D_800C4AE8_de;
extern void func_80270910_de(f32 *, DraftPackedMatrix *);
extern void func_80272898_de(void *, void *, void *);
extern void func_80272B38_de(void *, void *, void *);
extern s32 func_802773D4_de(DraftLight *, Vec3, Vec3, Matrix *, Vec3 *, f32 *);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);

void func_802775B0_de(DraftLight **lights, s32 lightCount, DraftLitMesh *mesh,
                     DraftPackedMatrix *matrices, Vec3 *output, s32 multiple)
{
    f32 matrix[16];
    Vec3 sum, position, normal, worldPosition, worldNormal, contribution;
    f32 amount, selectedAmount;
    s32 count, i, j, mode, colour, level;
    u32 pattern;
    DraftLitVertex *vertex;
    DraftLight *light;

    count = mesh->count;
    vertex = mesh->vertices;
    func_80270910_de(matrix, matrices);
    for (i = 0; i < count; i++, vertex++) {
        mode = 0;
        selectedAmount = 0.0f;
        colour = 0;
        if (vertex->flags & 0x80) {
            continue;
        }
        if (multiple) {
            func_80270910_de(matrix, &matrices[vertex->flags >> 8]);
        }
        position.x = vertex->x;
        position.y = vertex->y;
        position.z = vertex->z;
        func_80272898_de(matrix, &position, &worldPosition);
        normal.x = vertex->nx;
        normal.y = vertex->ny;
        normal.z = vertex->nz;
        func_80272B38_de(matrix, &normal, &worldNormal);
        sum.x = sum.y = sum.z = 0.0f;
        for (j = 0; j < lightCount; j++) {
            light = lights[j];
            contribution.x = contribution.y = contribution.z = 0.0f;
            if (worldPosition.x < light->maximum.x &&
                worldPosition.y < light->maximum.y &&
                worldPosition.z < light->maximum.z &&
                light->minimum.x <= worldPosition.x &&
                light->minimum.y <= worldPosition.y &&
                light->minimum.z <= worldPosition.z &&
                func_802773D4_de(light, worldPosition, worldNormal,
                                light->matrix, &contribution, &amount)) {
                if (light->mode) {
                    mode = light->mode;
                    colour = light->colour;
                    selectedAmount = amount;
                }
                func_80271F34_de(&sum, &sum, &contribution);
            }
        }
        if (mode) {
            level = 0;
            if (selectedAmount < D_800C4AE0_de) level = 1;
            if (selectedAmount < D_800C4AE4_de) level = 2;
            if (mode == 1) {
                vertex->flags = (vertex->flags & 0xFF8F) |
                                (((colour % 7 + 1) << 4) & 0x70);
            }
            if (mode == 2) {
                pattern = (u32)worldPosition.x / 10;
                pattern += (u32)worldPosition.y / 10;
                pattern += (u32)worldPosition.z / 10;
                pattern = pattern % 7 + 1;
                vertex->flags = (vertex->flags & 0xFF8F) |
                                ((pattern << 4) & 0x70);
            }
            vertex->flags = (vertex->flags & 0xFFF3) | (level << 2);
            if (selectedAmount < D_800C4AE8_de) {
                vertex->flags &= 0xFF83;
            }
        }
        output->x += sum.x;
        output->y += sum.y;
        output->z += sum.z;
        output++;
    }
}
