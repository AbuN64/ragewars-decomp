#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Returns one less than the word D_8011FEFC points to. */
extern s32 *D_8011FEFC;

s32 func_80403BCC_de(void) {
    return *D_8011FEFC - 1;
}
