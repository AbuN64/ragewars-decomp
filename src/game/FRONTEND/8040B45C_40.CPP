#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "FRONTEND/LAYOUT.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_40.H"
#include "SCENE/802508E0_13.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/8040B45C_31.H"
#include "FRONTEND/8040B45C_33.H"

/* Visits every cell of a list's column-by-row grid, computing each cell's rectangle through func_804122CC_de and drawing it through func_8040D2D0_de with the given style. */







extern void func_804122CC_de(GridList *list, UnitMtx *cell, u32 column, u32 row);


/* Allocates and zeroes a 0x60-byte record, copies the header of the record func_8040EC30_de finds for the low half of the first argument, tags it 0xB, stores four byte arguments and three alternating pairs of the last two, allocates and zeroes a width-by-height table of eight-byte cells at 0x44, and registers the record through func_8040ED38_de.
   Adapted from func_8041A580_de with the record size, tag 0xB, the byte fields, the cell table and the func_8040ED38_de registration changed. */







extern s32 func_80299958_de(void);

extern void *func_80411DCC_de(s32 index);

extern void *func_8025305C_de(s32);


extern void func_8040ED38_de(s32 arg0, s32 arg1, MenuWidget *arg2, MenuWidget *arg3);

/* Looks up the entry with the given identifier among the list func_80411DCC_de returns for what func_80299958_de returns, through func_8040EC30_de, and stores two words into the eight-byte cell at the given row and column of its cell table at 0x44, whose row width is the byte at 0x4B.
   Adapted from func_80412A58_de with the three byte stores replaced by the two cell-word stores changed. */





extern s32 func_80299958_de();

/* When the fourth argument is set, lowers the byte at offset 0x4C of an entry by one while it is
   above the minimum at 0x50; then calls func_804121F0_de and func_8029973C_de. Returns zero. */
extern void func_804121F0_de(void *);

extern void func_8029973C_de();

/* Releases an object through func_802547E4_de, first releasing the object it holds at offset 0x44
   when there is one, and returns zero. */



void func_80412634_de(GridList *arg0, sm_dldc style) {
    GridList *list = arg0;
    UnitMtx cell;
    u32 column;
    u32 row;

    for (column = 0; column < list->columns; column++) {
        for (row = 0; row < list->rows; row++) {
            func_804122CC_de(list, &cell, column, row);
            func_8040D2D0_de((TextWidget *)&cell, style);
        }
    }
}

s32 func_80412710_de(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6) {
    MenuWidget *source;
    s32 context;
    MenuWidget *result;
    s32 size;
    void *cells;

    source = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 0xFFFF);
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x60);
    func_802A0748_de(result, 0, 0x60);
    *(Header44 *)result = *(Header44 *)source;
    result->kind = 0xB;
    result->field_4B = arg4;
    result->field_4A = arg3;
    result->field_49 = arg2;
    result->field_48 = arg1;
    result->field_51 = arg6;
    result->field_50 = arg5;
    result->field_4F = arg6;
    result->field_4E = arg5;
    result->field_4D = arg6;
    result->field_4C = arg5;
    size = arg3 * arg4 * 8;
    cells = func_8025305C_de(size);
    result->field_44 = cells;
    func_802A0748_de(cells, 0, size);
    func_8040ED38_de(context, 0, source, result);
    return 1;
}

void func_80412898_de(s32 identifier, s32 row, s32 column, s32 first, s32 second) {
    Entry_func_80412898_de *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), (u16)identifier);

    entry->cells[row * entry->width + column].field_0 = first;
    entry->cells[row * entry->width + column].field_4 = second;
}

void func_80412940_de(s32 identifier, s32 row, s32 column, s32 *first, s32 *second) {
    Entry_func_80412898_de *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), (u16)identifier);

    *first = entry->cells[row * entry->width + column].field_0;
    *second = entry->cells[row * entry->width + column].field_4;
}

void func_804129F0_de(s32 identifier, s32 first, s32 second, s32 third) {
    u8 *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), (u16)identifier);

    entry[0x54] = second;
    entry[0x56] = third;
    entry[0x52] = first;
}

void func_80412A58_de(s32 identifier, s32 first, s32 second, s32 third) {
    u8 *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), (u16)identifier);

    entry[0x55] = second;
    entry[0x57] = third;
    entry[0x53] = first;
}

void func_80412AC0_de(s32 identifier, s32 first, s32 second) {
    struct Entry_func_80412AC0_de *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), (u16)identifier);

    entry->second = second;
    entry->first = first;
}

void func_80412B18_de(s32 identifier, s32 *first, s32 *second) {
    struct MenuWidget *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), (u16)identifier);

    *first = entry->field_4C;
    *second = entry->field_4D;
}

s32 func_80412B78_de(u8 *entry, void *second, void *third, s32 active) {
    s32 value = entry[0x4C];

    if (active && entry[0x50] < value) {
        entry[0x4C] = value - 1;
    }
    func_804121F0_de(entry);
    func_8029973C_de();
    return 0;
}

s32 func_80412BC0_de(u8 *entry, void *second, void *third, s32 active) {
    u8 value = entry[0x4C];

    if (active && value < entry[0x4A] - 1) {
        entry[0x4C] = value + 1;
    }
    func_804121F0_de(entry);
    func_8029973C_de();
    return 0;
}

s32 func_80412C0C_de(u8 *entry, void *second, void *third, s32 active) {
    s32 value = entry[0x4D];

    if (active && entry[0x51] < value) {
        entry[0x4D] = value - 1;
    }
    func_804121F0_de(entry);
    func_8029973C_de();
    return 0;
}

s32 func_80412C54_de(u8 *entry, void *second, void *third, s32 active) {
    u8 value = entry[0x4D];

    if (active && value < entry[0x4B] - 1) {
        entry[0x4D] = value + 1;
    }
    func_804121F0_de(entry);
    func_8029973C_de();
    return 0;
}

s32 func_80412CA0_de(struct Object_func_80412CA0_de *object) {
    struct Object_func_80412CA0_de *self = object;

    if (object->child != 0) {
        func_802547E4_de(object->child);
    }
    func_802547E4_de(self);
    return 0;
}
