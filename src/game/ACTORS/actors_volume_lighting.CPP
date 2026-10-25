#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "ACTORS/80277444.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"

extern void func_80272B38_de(void *arg0, void *arg1, void *arg2);
extern s32 func_80277128_de(ObjectRecAtBC *arg0, f32 arg1, f32 arg2, f32 arg3,
                        f32 *arg4, f32 *arg5);
extern void Particle_ScaleVector(void *, void *, f32);





s32 Actors_EvaluateLightVolume(ObjectRecAtBC *arg0, CVector3 arg1, CVector3 arg4, f32 *arg7,
                  CVector3 *arg8, f32 *arg9) {
    CVector3 second;
    CVector3 first;
    CVector3 normal;
    f32 amount;
    f32 dot;
    f32 value;
    f32 objectValue;

    if (arg0->flagB9 != 0) {
        first.x = arg1.x * arg7[0];
        first.y = arg1.y * arg7[5];
        first.z = arg1.z * arg7[10];
        first.x += arg7[12];
        first.y += arg7[13];
        first.z += arg7[14];
        second.x = arg4.x * arg7[0];
        second.y = arg4.y * arg7[5];
        second.z = arg4.z * arg7[10];
    } else {
        Particle_TransformPoint(arg7, &arg1.x, &first);
        func_80272B38_de(arg7, &arg4.x, &second);
    }
    func_8027207C_de(&second.x);
    if (func_80277128_de(arg0, first.x, first.y, first.z,
                     &normal.x, &amount) == 0) {
        return 0;
    }
    {
        dot = -((normal.x * second.x) + (normal.y * second.y) +
                (normal.z * second.z));
        if (dot < 0.0f) {
            dot = 0.0f;
        }
        objectValue = arg0->value;
        value = amount * (objectValue +
                          (dot * (1.0f - objectValue)));
        amount = value;
        if (value <= 0.0f) {
            amount = 0.0f;
        }
        if (arg0->flagB8 != 0) {
            amount = -amount;
        }
        if (arg9 != 0) {
            *arg9 = amount;
        }
        Particle_ScaleVector(arg8, &arg0->direction, amount);
    }
    return 1;
}

extern void Rsp_ConvertMatrixToFloat(f32 *, PackedMatrixWords *);
extern void func_80271F34_de(CVector3 *, CVector3 *, CVector3 *);
void Actors_AccumulateVertexLighting(ObjectRecAtBC **lights, s32 lightCount, Vertices38 *mesh,
                     PackedMatrixWords *matrices, CVector3 *output, s32 multiple)
{
    f32 matrix[16];
    CVector3 sum, position, normal, worldPosition, worldNormal, contribution;
    f32 amount, selectedAmount;
    s32 count, i, j, mode, colour, level, drawn;
    CVector3 *dest;
    u32 pattern;
    Vertex38 *vertex, *base;
    ObjectRecAtBC *light;

    count = mesh->count;
    base = mesh->vertices;
    Rsp_ConvertMatrixToFloat(matrix, matrices);
    drawn = 0;
    for (i = 0; i < count; i++) {
        vertex = &base[i];
        dest = &output[drawn];
        mode = 0;
        selectedAmount = 0.0f;
        colour = 0;
        if (vertex->flags & 0x80) {
            continue;
        }
        if (multiple) {
            Rsp_ConvertMatrixToFloat(matrix, &matrices[vertex->flags >> 8]);
        }
        position.x = vertex->px;
        position.y = vertex->py;
        position.z = vertex->pz;
        Particle_TransformPoint(matrix, &position, &worldPosition);
        normal.x = vertex->x;
        normal.y = vertex->y;
        normal.z = vertex->z;
        func_80272B38_de(matrix, &normal, &worldNormal);
        sum.x = 0.0f;
        sum.y = 0.0f;
        sum.z = 0.0f;
        for (j = 0; j < lightCount; j++) {
            light = lights[j];
            contribution.x = 0.0f;
            contribution.y = 0.0f;
            contribution.z = 0.0f;
            if (light->bounds.max.x > worldPosition.x &&
                light->bounds.max.y > worldPosition.y &&
                light->bounds.max.z > worldPosition.z &&
                light->bounds.min.x <= worldPosition.x &&
                light->bounds.min.y <= worldPosition.y &&
                light->bounds.min.z <= worldPosition.z &&
                Actors_EvaluateLightVolume(light, worldPosition, worldNormal,
                                light->inverse, &contribution, &amount)) {
                if (light->animatedLight) {
                    mode = light->animatedLight;
                    colour = light->animationSeed;
                    selectedAmount = amount;
                }
                func_80271F34_de(&sum, &sum, &contribution);
            }
        }
        if (mode) {
            level = 0;
            if (selectedAmount < 0.6f) level = 1;
            if (selectedAmount < 0.3f) level = 2;
            if (mode == 1) {
                vertex->flags = (vertex->flags & 0xFF8F) |
                                (((colour % 7 + 1) << 4) & 0x70);
            }
            if (mode == 2) {
                pattern = 0;
                pattern += (u32)worldPosition.x / 10;
                pattern += (u32)worldPosition.y / 10;
                pattern += (u32)worldPosition.z / 10;
                pattern = pattern % 7 + 1;
                vertex->flags = (vertex->flags & 0xFF8F) |
                                ((pattern << 4) & 0x70);
            }
            vertex->flags = (vertex->flags & 0xFFF3) | (level << 2);
            if (selectedAmount < 0.1f) {
                vertex->flags &= 0xFF83;
            }
        }
        dest->x += sum.x;
        dest->y += sum.y;
        dest->z += sum.z;
        drawn++;
    }
}
