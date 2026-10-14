#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80411B68.h"
extern char *D_80153C28;

short func_80411C60_de(int index) {
    return ((struct OSThread_s *) ((struct ObjectLinks490 *) (D_80153C28 + (index * 1180)))->unk_48C)->state;
}
