#include "COMMON/DESCRIPTORRECAT29.H"
#include "SCHED/8023A284.H"
#include "TYPES.H"
#include "SCHED/8023A284_8.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_3.H"



void func_8023B8F8_de(s32 sceneAddress, s32 effectNode) {
    func_80255ED8_de(sceneAddress + 0x8B4, effectNode);
    func_80255CB8_de(sceneAddress + 0x8A0, effectNode);
}

/** Swap the two words pointed to by arg0 and arg1. */
void func_8023B938_de(int *leftEntry, int *rightEntry) {
    int temp;

    temp = *leftEntry;
    *leftEntry = *rightEntry;
    *rightEntry = temp;
}

s32 func_8023B94C_de(void **arg0, void **arg1)
{
  f32 new_var2;
  int new_var;
  s32 comparisonResult;
  comparisonResult = 1;
  new_var2 = ((struct ObjRecAt210 *) ((s8 *) (*arg0)))->unk210;
  if ((((struct ObjRecAt210 *) ((s8 *) (*arg1)))->unk210) < new_var2)
  {
    new_var = 1;
    comparisonResult = -new_var;
  }
  return comparisonResult;
}

/** Compare two records by the float at nested offset 0x210. */
int func_8023B978_de(void *first, void *second) {
    Rotor *left = *(void **)first;
    Rotor *right = *(void **)second;
    int result = 1;
    if (left->speed <
        right->speed) {
        result = -1;
    }
    return result;
}
