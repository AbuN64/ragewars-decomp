#include "COMMON/RESULTS.H"
#include "TYPES.H"
extern void SetN64_GetPackBaseAndSize(int *arg0, int **arg1, int *arg2);

s32 SetN64_GetPackSize(s32 *bitSet) {
    s32 *sp10;
    s32 sp14;
    SetN64_GetPackBaseAndSize(bitSet, &sp10, &sp14);
    return sp14;
}
