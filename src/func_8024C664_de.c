#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"



extern char D_800CA8C4_de[];
extern void *D_800CB440_de[];
extern ObjectList D_80145040;




void *func_8024C664_de(char *arg0)
{
    s32 type;
    s32 i;
    s32 count;
    s32 limit;
    char *object;
    ObjectList *list;

    func_8024C654_S1 *actor = (void *)arg0;

    type = *actor->unk18;
    if ((unsigned int)type >= 15) {
        return 0;
    }
    if (type == 11) {
        list = &D_80145040;
        count = list->count;
        i = 0;
        if (count > 0) {
            limit = count;
            object = list->objects;
            do {
                if (object == arg0) {
                    return 0;
                }
                if (object + 0x2E8 == arg0) {
                    return D_800CA8C4_de;
                }
                i++;
                object += 0x16E8;
            } while (i < limit);
        }
    }
    return D_800CB440_de[type];
}
