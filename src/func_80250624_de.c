#include "span_1000/code_8024E914.h"
#include "span_1000/code_8024E914.h"
#include "span_1000/code_8024E914.h"
#include "types.h"
#include "common/unused.h"

/* Starts the effects attached to an object's model: loads the model resource named by the object's id,
 * finds its attachment table (group 3) and loads it, then for each 0x1C-byte attachment (all of them, or
 * only type 8 when all is clear) transforms its offset by the object's matrix at 0x68 and starts the
 * attachment's effect at that point through func_80265E10_de, releasing both resources afterwards. */

extern char D_800C3E5C_de;
#if defined(VERSION_DE)
extern char D_800C3E70[];
#elif defined(VERSION_EU)
extern char D_800C4120[];
#elif defined(VERSION_EU_X)
extern char D_800C4160[];
#elif defined(VERSION_US)
extern char D_800C3DA0[];
#else
extern char D_800C8F60[];
#endif
extern s32 **func_8025193C_de(s32, s32, s32, s32, s32, s32, s32, char *, s32);
extern s32 func_8028FE3C_de(s32 *, s32, s32, s32 *);
extern void func_80272898_de(void *, Triple *, Triple *);
extern void func_80265E10_de(void *, void *, s32, s32, Triple, ResourceManagerState);
extern void func_80253754_de(s32, s32 **);

void func_80250624_de(void *object, s32 all) {
    s32 **model;
    s32 **table;
    s32 *header;
    Attachment *attachment;
    Attachment *entries;
    Triple position;
    s32 name;
    s32 size;
    s32 count;
    s32 i;

    model = func_8025193C_de(0, ((PlacedProp *)object)->owner, ((PlacedProp *)object)->owner, 0x18, 4, 0, 0,
                          &D_800C3E5C_de, 0);
    if (model == 0) {
        return;
    }
    name = func_8028FE3C_de(*model, ((PlacedProp *)object)->owner, 3, &size);
#if defined(VERSION_DE)
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C3E70, 0);
#elif defined(VERSION_EU)
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C4120, 0);
#elif defined(VERSION_EU_X)
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C4160, 0);
#elif defined(VERSION_US)
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C3DA0, 0);
#else
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C8F60, 0);
#endif
    if (table != 0) {
        header = *table;
        count = header[1];
        entries = (Attachment *)(header + 2);
        for (i = 0; i < count; i++) {
            attachment = &entries[i];
            if (all != 0 || attachment->type == 8) {
                func_80272898_de(((PlacedProp *)object)->matrix, &attachment->offset, &position);
                func_80265E10_de(object, object, attachment->type, -1, position, attachment->params);
            }
        }
        func_80253754_de(0, table);
    }
    func_80253754_de(0, model);
}
