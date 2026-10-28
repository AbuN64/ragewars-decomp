#include "COMMON/PLAYERRECAT64E.H"
#include "MULTI/INITIAL.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHARED_DEBUGFIELD.H"
#include "COMMON/SHARED_MENUSELECTION.H"
#include "sdk/AUDIO/sprintf.H"


/* Read the descriptor's runtime value type and format the scaled value. */
char *func_8043F120_de(Shared_DebugWidget *widget) {
    Shared_DebugField *field = widget->field;
    void *value = field->get();
    f32 number;
    switch (field->type) {
    default: number = 0.0f; break;
    case 0: { f32 *p = value; number = *p; break; }
    case 3: { s8 *p = value; number = *p; break; }
    case 4: { s16 *p = value; number = *p; break; }
    case 1:
    case 2:
    case 5: { s32 *p = value; number = *p; break; }
    case 6: { u8 *p = value; number = *p; break; }
    case 7: { u16 *p = value; number = *p; break; }
    case 8: { u32 *p = value; number = (f64)*p; break; }
    }
    number /= field->scale;
    func_802BD320_de(D_8014DE10, D_800DE380, (f64)number);
    if (field->name != 0) {
        func_802BD320_de(D_8014DDD0, D_800DE388_de, field->name, D_8014DE10);
    } else {
        func_802BD320_de(D_8014DDD0, D_800DE390_de, D_8014DE10);
    }
    return D_8014DDD0;
}

s32 Multi_AdjustTypedMenuVariable(MenuRecAt14 *arg0, Shared_MenuInput *menuInput) {
    void *temp_a0_2;
    void *temp_v1;
    f32 temp_v0;
    f32 var_f0;
    f32 var_f20;
    f64 var_f1;
    s32 var_condition_bit;
    u32 temp_a0;
    u32 temp_v1_2;
    struct Variable *temp_s0;
    struct Variable *temp_s0_2;

    temp_s0 = arg0->unk14;
    temp_v1 = temp_s0->unk18();
    temp_a0 = temp_s0->unk4;
    switch (temp_a0) {                              
    default:                                        
        var_f20 = 0.0f;
        break;
    case 0:                                         
        var_f20 = *(float *)temp_v1;
        break;
    case 3:                                         
        var_f20 = (f32) *(signed char *)temp_v1;
        break;
    case 4:                                         
        var_f20 = (f32) *(short *)temp_v1;
        break;
    case 1:                                         
    case 2:                                         
    case 5:                                         
        var_f20 = (f32) *(int *)temp_v1;
        break;
    case 6:                                         
        var_f20 = (f32) *(unsigned char *)temp_v1;
        break;
    case 7:                                         
        var_f20 = (f32) *(unsigned short *)temp_v1;
        break;
    case 8:                                         
        var_f20 = (float)*(unsigned int *)temp_v1;
        break;
    }
    if (((s32 (*)(s32))Control_IsLeftPressed)(menuInput->buttons) != 0) {
        var_f20 -= temp_s0->unk10;
        if (var_f20 < temp_s0->unk8) var_f20 = temp_s0->unk8;
    } else if (((s32 (*)(s32))Control_IsRightPressed)(menuInput->buttons) != 0) {
        var_f20 += temp_s0->unk10;
        if (var_f20 > temp_s0->unkC) var_f20 = temp_s0->unkC;
    }
    temp_s0_2 = arg0->unk14;
    temp_a0_2 = temp_s0_2->unk18(arg0);
    temp_v1_2 = temp_s0_2->unk4;
    switch (temp_v1_2) {
    case 0: *(float *)temp_a0_2 = var_f20; break;
    case 3: *(signed char *)temp_a0_2 = (int)var_f20; break;
    case 4: *(short *)temp_a0_2 = (int)var_f20; break;
    case 1: case 2: case 5: *(int *)temp_a0_2 = var_f20; break;
    case 6: *(unsigned char *)temp_a0_2 = (unsigned int)var_f20; break;
    case 7: *(unsigned short *)temp_a0_2 = (unsigned int)var_f20; break;
    case 8: *(unsigned int *)temp_a0_2 = var_f20; break;
    }
    return 0;
}
