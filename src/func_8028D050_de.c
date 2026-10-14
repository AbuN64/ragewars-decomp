#include "span_1000/code_8028CCB8.h"
#include "types.h"







/* Collects up to max records of arg0 (indices unk13C to unk140) whose unkE4, unk18->unk0 and unk18->unkC match key0, key1 and key2 (each skipped when -1) into out, returning the count. */
s32 func_8028D050_de(Container *arg0, s32 key0, s32 key1, s32 key2, RecordRecAtE4 **out, s32 max) {
    s32 i = arg0->unk13C;
    s32 end = arg0->unk140;
    RecordRecAtE4 *base = arg0->unk138;
    s32 count = 0;
    RecordRecAtE4 *rec;

    for (; i < end; i++) {
        rec = &base[i];
        if (count >= max) {
            return count;
        }
        if ((key0 == -1 || rec->unkE4 == key0) && (key1 == -1 || rec->unk18->unk0 == key1)
            && (key2 == -1 || rec->unk18->unkC == key2)) {
            *out++ = rec;
            count++;
        }
    }
    return count;
}
