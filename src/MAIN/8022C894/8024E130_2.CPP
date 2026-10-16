#include "shared/level_actor.h"
#include "span_1000/code_8024D018.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8024E130.h"
#include "TYPES.H"
#include "common/unused.h"

/** Return the constant false result used by callers at VRAM 0x8024E2E4. */
int func_8024E2F4_de(void) {
    return 0;
}












/** Return the vertical offset selected by the actor's current state. */
f32 func_8024E2FC_de(Actor_u1 *arg0) {
    Resource_u1 *state;

    {
        s32 state_value = arg0->resource->kind;
        s32 sw_state_value = state_value - 1;
        if ((unsigned int)sw_state_value > 10) {
            goto sw_state_default;
        }
        switch (sw_state_value) {
        case 0: goto sw_state_1;
        case 1: goto sw_state_2;
        case 2: goto sw_state_default;
        case 3: goto sw_state_default;
        case 4: goto sw_state_5;
        case 5: goto sw_state_default;
        case 6: goto sw_state_default;
        case 7: goto sw_state_8;
        case 8: goto sw_state_default;
        case 9: goto sw_state_default;
        case 10: goto sw_state_11;
        }
    }
    do {
    sw_state_11:
        return arg0->resource->valueEC;
    sw_state_1:
        return arg0->resource->value2C;
    sw_state_2:
        state = arg0->resource;
        if (((CollisionShapeResource *)state)->mode == 0) {
            return D_800C3D6C_de;
        }
        return ((CollisionShapeResource *)state)->height;
    sw_state_5:
        return arg0->resource->radius;
    sw_state_8:
        state = arg0->resource;
        if ((state->flags14 & 1) != 0) {
            return D_800C3D70_de;
        }
        return state->radius;
    sw_state_default:
        return D_800C3D74_de;
    
    } while (0);
}

f32 func_8024E3C4_de(Actor_u1 *arg0) {
    Resource_u1 *temp_a0 = arg0->resource;
    s32 temp_v1 = temp_a0->kind;

    switch (temp_v1) {
    case 11:
        return temp_a0->valueF8;
    case 4:
    case 1:
        return temp_a0->value34;
    default:
        return 0.0f;
    }
}

f32 func_8024E420_de(void *arg0) {
    Resource_u1 *nested;
    if (*(u8 *)arg0 == 1) {
        return ((LevelActor *)arg0)->eyeHeight;
    }
    nested = ((Actor_u1 *)arg0)->resource;
    if (nested->kind == 0) {
        return nested->value20;
    }
    return 0.0f;
}
