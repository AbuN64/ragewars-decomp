#include "span_16E000/code_80403BCC.h"
/* Returns whether a record's subtype at 0x12 is the one its kind at 0x11 requires: 5 for kind 1, 4 for
   kind 9 and 3 for kind 10; other kinds give 0. */


int func_80403E10_de(RecordRecAt12 *rec) {
    int result = 0;

    switch (rec->kind) {
    case 1:
        if (rec->subtype == 5) {
            result = 1;
        }
        break;
    case 9:
        if (rec->subtype == 4) {
            result = 1;
        }
        break;
    case 10:
        if (rec->subtype == 3) {
            result = 1;
        }
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
