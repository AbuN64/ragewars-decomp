#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028DF6C.h"
#include "types.h"

s32 func_8028DF90_de(void *arg0, s32 arg1) {
    void *temp_v0;
    temp_v0 = func_8028FDB4_de(((Shared_World *)arg0)->bitSections, 1);
    func_8028FDB4_de(temp_v0, 0);
    return func_8028FDB4_de(temp_v0, 1) + arg1;
}

void func_8028DFE4_de(WorldSortEntry *arg0, WorldSortEntry *arg1) {
    WorldSortEntry tmp;

    tmp = *arg0;
    *arg0 = *arg1;
    *arg1 = tmp;
}

s32 func_8028E020_de(void *arg0, void *arg1) {
    s32 var_v0;
    var_v0 = 1;
    if ((((WorldSortEntry *)arg0)->distance) < (((WorldSortEntry *)arg1)->distance)) {
        var_v0 = -1;
    }
    return var_v0;
}

s32 func_8028E044_de(void *arg0, void *arg1)
{
  f32 new_var;
  s32 var_v0;
  new_var = ((WorldSortEntry *)arg0)->distance;
  var_v0 = 1;
  if ((((WorldSortEntry *)arg1)->distance) < new_var)
  {
    var_v0 = -1;
  }
  return var_v0;
}

void func_8028E068_de(void *arg0) {
    s32 found;
    s32 clear_index;
    Actor_func_8028E284_de *record;
    struct Shared_Pickup **clear_ptr;
    struct Shared_Pickup **out;
    s32 wanted_type;

    found = 0;
    clear_index = 15;
    record = ((Shared_World *)arg0)->actors;
    ((Shared_World *)arg0)->specialActorCount = 0;
    do {
        ((Shared_World *)arg0)->specialActors[clear_index] = 0;
        clear_index--;
    } while (clear_index >= 0);

    if (((Shared_World *)arg0)->actorCount > 0) {
        clear_index = 0;
        wanted_type = 14;
        do {
            if (record->def->type == wanted_type) {
                ((Shared_World *)arg0)->specialActors[found] = record;
                found++;
            }
            if (found >= 16) {
                break;
            }
            clear_index++;
            if (clear_index >= ((Shared_World *)arg0)->actorCount) {
                break;
            }
            record++;
        } while (1);
    }
    ((Shared_World *)arg0)->specialActorCount = found;
}
