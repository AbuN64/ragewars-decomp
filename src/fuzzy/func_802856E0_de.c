#include "span_1000/code_8028567C.h"
#include "span_C76B0/data.h"
#include "common/unused.h"
extern s32 func_802BCF30_de(void);
extern void func_802BCF50_de(s32);
extern f32 func_80264EE0_de(PlayerRecAt8 *);

f32 func_802856E0_de(func_80285D00_S1 *pool, Vec3 position) {
    f32 value = pool->baseLevel;
    s32 mask = func_802BCF30_de();
    func_80285880_S1 *node;
    f32 x, y, z, distance, amount, first, second;
    if (D_8014288C == 1 || func_80245798_de() != 0) {
        value = 0.0f;
    } else {
        node = pool->unk14.head;
        while (node != 0) {
            x = position.x - node->position.x;
            y = position.y - node->position.y;
            z = position.z - node->position.z;
            distance = func_802B72B0_de(x * x + y * y + z * z);
            if (distance == 0.0f || node->unk18 == 0.0f) {
                amount = D_800C4EC4_de;
            } else if (distance < node->unk18) {
                amount = D_800C4EC0_de - distance / node->unk18;
            } else {
                amount = 0.0f;
            }
            amount *= node->unk1C;
            first = func_80264EE0_de(&node->amplitudeCurve);
            second = func_80264EE0_de(&node->lifetimeCurve);
            value += amount * first * second;
            node = node->next;
        }
    }
    func_802BCF50_de(mask);
    if (value < 0.0f) return 0.0f;
    if (D_800C4EC8_de < value) return D_800C4EC8_de;
    return value;
}
