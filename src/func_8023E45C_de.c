#include "span_1000/code_8023D370.h"
#include "types.h"












extern Output *D_80103FCC;

void func_8023E45C_de(Input *arg0) {
    {
        s32 type = arg0->type;
        s32 sw_type_value = type - 1;
        if ((unsigned int)sw_type_value > 8) {
            goto sw_type_default;
        }
        switch (sw_type_value) {
        case 0: goto sw_type_1;
        case 1: goto sw_type_1;
        case 2: goto sw_type_1;
        case 3: goto sw_type_1;
        case 4: goto sw_type_2;
        case 5: goto sw_type_6;
        case 6: goto sw_type_3;
        case 7: goto sw_type_4;
        case 8: goto sw_type_5;
        }
    }
    do {
    sw_type_1:
        D_80103FCC->instance0 = arg0->instance104;
        if (arg0->instance104 != 0) {
            D_80103FCC->instanceValue4 = arg0->instance104->field14;
        } else {
            D_80103FCC->instanceValue4 = 0;
        }
        D_80103FCC->vec8 = arg0->vec180;
        D_80103FCC->field14 = -1;
        break;
    sw_type_2:
        if (arg0->instance104 != 0) {
            D_80103FCC->fieldC4 = arg0->instance104->field14;
        } else {
            D_80103FCC->fieldC4 = 0;
        }
        D_80103FCC->vecC8 = arg0->vec180;
        D_80103FCC->fieldD4 = arg0->fieldBC;
        break;
    sw_type_3:
        D_80103FCC->instance0 = arg0->instance104;
        D_80103FCC->instanceValue4 = arg0->instance104->field14;
        D_80103FCC->vec8 = arg0->vec180;
        D_80103FCC->field14 = -1;
        break;
    sw_type_4:
        D_80103FCC->instance0 = arg0->instance104;
        D_80103FCC->instanceValue4 = arg0->instance104->field14;
        D_80103FCC->vec8 = arg0->vec180;
        D_80103FCC->field14 = arg0->field108;
        D_80103FCC->block18 = arg0->block10C;
        break;
    sw_type_5:
        D_80103FCC->instance88 = arg0->instance104;
        D_80103FCC->instanceValue8C = arg0->instance104->field14;
        D_80103FCC->vec90 = arg0->vec180;
        break;
    sw_type_6:
    sw_type_7:
    sw_type_8:
    sw_type_9:
        break;
    
    sw_type_default:;
    } while (0);
    D_80103FCC->vecF0 = arg0->vecF8;
    D_80103FCC->vecE4 = arg0->vec180;
    D_80103FCC->typeFC = arg0->type;
    D_80103FCC->field100 = arg0->fieldC0;
}
