#include "COMMON/OUTPUT.H"
#include "COMMON/CHANNEL.H"

int Gsky_StartFadeModeTwo(void *outputStorage) {
    struct CCollisionResults *output = (void *)outputStorage;
    output->field100 = 0;
    output->typeFC = 2;
    return 2;
}
