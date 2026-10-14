#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"



extern s32 D_8014D4C0_de;
extern s32 D_8015375C;
extern s32 D_80153760;
extern s32 D_8014D4EC_de;
extern char *D_800D373C[];
extern char *D_800D3740[];
extern char *D_800D3744[];
extern char *D_800D3748[];
extern char *D_800D3750[];
extern char *D_800D3760[];
extern char *D_800D7E14[];

/* Selects a menu field's label table from the connection mode and the option index. */
s32 func_8040A37C_de(struct Field *field, s16 *arg1) {
    s32 option;
    u32 rel;

    option = *arg1;
    rel = option - 3;
    if (D_80153760 != 0) {
        if (D_8014D4EC_de != 0) {
            field->text = D_800D373C;
        } else {
            field->text = D_800D3744;
        }
        goto done;
    }
    if (D_8014D4C0_de != 0) {
        if (rel < 16) {
            field->text = D_800D3750;
            return 0;
        }
        if (option == 0x15) {
            field->text = D_800D7E14;
        } else if (D_8014D4EC_de != 0) {
            field->text = D_800D3740;
        } else {
            field->text = D_800D3748;
        }
        goto done;
    }
    if (D_8015375C != 0) {
        field->text = D_800D3760;
    }
done:
    return 0;
}
