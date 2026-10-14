#include "span_16E000/code_80411B68.h"
#include "types.h"
/* Loads or unloads the images of a widget subtree: visits the later siblings when asked and the
   children, then for an image widget (type 3) loads its image through func_80410674_de or unloads it
   through func_80411AF0_de, and for a button (type 8) visits its normal, pressed and highlighted
   variants without their siblings; type 4 widgets and other types have nothing to do. */



extern void func_80410674_de(WidgetRecAt34 *image, s32 mode);
extern void func_80411AF0_de(s32 i);

void func_804120DC_de(WidgetRecAt34 *widget, s32 load, s32 siblings) {
    if (widget == 0) {
        return;
    }
    if (widget->next != 0 && siblings != 0) {
        func_804120DC_de(widget->next, load, siblings);
    }
    if (widget->child != 0) {
        func_804120DC_de(widget->child, load, siblings);
    }
    switch (widget->type) {
        case 4:
            break;
        case 3:
            if (load != 0) {
                func_80410674_de(widget->normal, 3);
            } else {
                func_80411AF0_de(widget->normal);
            }
            break;
        case 8:
            if (widget->normal != 0) {
                func_804120DC_de(widget->normal, load, 0);
            }
            if (widget->pressed != 0) {
                func_804120DC_de(widget->pressed, load, 0);
            }
            if (widget->highlighted != 0) {
                func_804120DC_de(widget->highlighted, load, 0);
            }
            break;
    }
}
