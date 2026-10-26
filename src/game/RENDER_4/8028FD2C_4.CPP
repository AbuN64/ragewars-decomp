#include "COMMON/RESULTS.H"
#include "TYPES.H"
extern void SetN64_GetPackBaseAndSize(int *arg0, int **arg1, int *arg2);

s32 SetN64_GetPackSize(s32 *bitSet) {
    s32 *packBase;
    s32 packSize;
    SetN64_GetPackBaseAndSize(bitSet, &packBase, &packSize);
    return packSize;
}
