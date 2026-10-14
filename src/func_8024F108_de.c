#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E914.h"
#include "span_1000/code_8026E1F8.h"
#include "types.h"







extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern void func_80253838_de(void *arg0, void *arg1);
extern s32 func_802540F4_de(s32, void **, s32, void *, s32);
extern s32 func_8028FE28_de(s32 *, s32, s32);
extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);

extern void func_80253754_de(s32, void *);

extern char D_0026D7F4;
extern char D_800C3DA8_de;
extern char D_800C3DC0_de;
extern char D_800C3DD4_de;





void func_8024F108_de(void *arg0) {
    void *sp28;
    void **resource;
    s32 key;
    s32 found;
    s32 index;

    index = ((StaticObject *)arg0)->model;
    if (index != ((StaticObject *)arg0)->animation) {
        resource = func_8025193C_de(0, ((StaticObject *)arg0)->animationKey,
                                ((StaticObject *)arg0)->animationKey, 0x18,
                                0, 0, 0, &D_800C3DA8_de + 4, 1);
        if (resource != 0) {
            key = func_8028FE28_de(*resource, ((StaticObject *)arg0)->animationKey, 1);
            func_80253838_de(0, resource);
            found = func_802540F4_de(0, &sp28, key, &D_800C3DC0_de, 1);
            if (found != 0) {
                ((StaticObject *)arg0)->resource = func_8028FE3C_de((s32)sp28, key,
                                                    index % *(s32 *)sp28,
                                                    &((StaticObject *)arg0)->resourceSize);
                ((StaticObject *)arg0)->animation = index;
                func_80253838_de(0, (void *)found);
            }
        }
    }
    if (((StaticObject *)arg0)->resource != 0) {
        resource = func_8025193C_de(0, ((StaticObject *)arg0)->resource,
                                ((StaticObject *)arg0)->resource, ((StaticObject *)arg0)->resourceSize,
                                0, 0, &D_0026D7F4, &D_800C3DD4_de, 0);
    } else {
        resource = 0;
    }
    if (resource != 0) {
        func_8026E1F8_de(resource);
        func_80253754_de(0, resource);
    }
}
