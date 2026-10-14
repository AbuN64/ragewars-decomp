#include "span_16E000/code_80405DC0.h"
#include "types.h"

/* Stores a word at a byte offset beyond 0x60C in the block D_8011FECC points to. */
extern char *D_8011FECC;

void func_804098A4_de(s32 offset, s32 value) {
    ((struct IntegerState610 *) (D_8011FECC + offset))->unk_60C = value;
}
