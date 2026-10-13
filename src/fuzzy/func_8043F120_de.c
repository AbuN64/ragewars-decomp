#include "shared/func_8043E444_de_closed.h"
extern char D_800DE380[], D_800DE388_de[], D_800DE390_de[];
extern char D_8014DE10[], D_8014DDD0[];
extern s32 func_802BD320_de(char *, const char *, ...);

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
