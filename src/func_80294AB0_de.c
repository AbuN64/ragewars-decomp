#include "span_1000/code_80293A04.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_802944E8.h"
#include "types.h"




extern Entry80294AC4 D_800CD788[];







void func_80294AB0_de(void *arg0) {
    void (*callback)(void *arg0);
    s32 index;

    if ((D_80142CA8 == 2) &&
        (((struct Session_func_80293A20_de *)arg0)->transitionBlocked == 0)) {
        index = ((struct Session_func_80293A20_de *)arg0)->target;
        ((struct Session_func_80293A20_de *)arg0)->transitionTime = 0;
        ((struct Session_func_80293A20_de *)arg0)->mode = index;
        func_802456A0_de();
        func_8025E214_de(-1);
        func_80264854_de(0);
        callback = D_800CD788[((struct Session_func_80293A20_de *)arg0)->mode].callback;
        if (callback != 0) {
            callback(arg0);
        }
    }
}
