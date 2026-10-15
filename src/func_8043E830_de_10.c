#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* Calls func_80293824_de on D_8011FAC0 with 8 and returns one. */
extern char D_8011FAC0[];


s32 func_8043ED50_de(void) {
    func_80293824_de(D_8011FAC0, 8);
    return 1;
}
