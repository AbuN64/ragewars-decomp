#include "include_asm.h"
#include "FX/EXTERNS.H"
#include "TYPES.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "FX/802631D0_2.H"

/** Clear the object's fields, preserving the field at offset 0x10. */
void Fx_ClearControllerInput(void *object) {
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

s32 ContPad_SwapButtonPairs(s32 arg0)
{
  int new_var;
  s32 var_v1;
  new_var = 0x80000;
  var_v1 = arg0 & 0xFFF6FFF3;
  if (arg0 & 0x10000)
  {
    var_v1 |= 8;
  }
  if (arg0 & 8)
  {
    var_v1 = var_v1 | 0x10000;
  }
  if (arg0 & new_var)
  {
    var_v1 |= 4;
  }
  if (arg0 & 4)
  {
    var_v1 |= 0x80000;
  }
  return var_v1;
}

#if defined(VERSION_US)
char rodata_unresolved_802636D4[12] =
    "LE_IMPACTS_A";
#endif
