#include "types.h"
#include "gfx.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_80245BC0_de_closed.h"
#include "span_1000/code_8024E914.h"
#include "span_16E000/code_8044ACCC.h"
extern char D_800C3E5C_de[];
extern void **func_8025193C_de(s32,s32,s32,s32,s32,s32,void *,void *,s32);
extern s32 func_8028FE28_de(s32 *,s32,s32);
extern s32 func_8028FE3C_de(void *,s32,s32,s32 *);
extern void func_80253670_de(void *,Node80253610 *);
void *func_802507AC_de(ResourceOwner *owner,s32 index) {
    void **block;
    void *allocation;
    s32 key;
    void *table;
    s32 *entries;
    if (owner->resource != 0) {
        func_80253670_de(0,owner->resource);
        return owner->resource;
    }
    if (index != owner->index) {
        block = func_8025193C_de(0,owner->key,owner->key,0x18,0,0,0,D_800C3E5C_de,1);
        if (block != 0) {
            key = func_8028FE28_de(*block,owner->key,1);
            func_80253838_de(0,block);
            allocation = func_802540F4_de(0,&table,key,D_800C8F70,1);
            if (allocation != 0) {
                entries = table;
                owner->selected = func_8028FE3C_de(table,key,index % *entries,&owner->size);
                owner->index = index;
                func_80253838_de(0,allocation);
            }
        }
    }
    if (owner->selected != 0) {
        return func_8025193C_de(0,owner->selected,owner->selected,owner->size,0,0,D_0026D7D4_de,D_800C3E94_de,0);
    } else { return 0; }
}
