#include "MAIN/8020F6E0.H"
#include "span_1000/code_802636D0.h"



/** Clear the object's fields, preserving the field at offset 0x10. */
void func_802636B0_de(void *object) {
    Shared_Input *input = object;
    input->word0 = 0;
    input->word4 = 0;
    input->word8 = 0;
    input->wordC = 0;
    input->word14 = 0;
    input->word18 = 0;
    input->word1C = 0;
    input->word20 = 0;
    input->held = 0;
    input->pressed = 0;
    input->unk2C = 0;
    input->unk30 = 0;
    input->unk34 = 0;
}
