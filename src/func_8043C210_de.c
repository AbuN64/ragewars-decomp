#include "span_16E000/code_8043A0A4.h"
#include "types.h"

/* Clears the words at offsets 0x10 to 0x18 of a record, then stores the first value through
   func_8043C2F0_de and the next three through func_8043C2F8_de. */
extern void func_8043C2F0_de(s32 *, s32);
extern void func_8043C2F8_de(s32 *, s32, s32, s32);

void func_8043C210_de(s32 *record, s32 first, s32 second, s32 third, s32 fourth) {
    record[4] = 0;
    record[5] = 0;
    record[6] = 0;
    func_8043C2F0_de(record, first);
    func_8043C2F8_de(record, second, third, fourth);
}

/* Sets the words at offsets 0x10, 0x14 and 0x18 of a record to one, zero and one, then calls
   func_8025DF34_de with 0xE83. */
extern void func_8025DF34_de(s32);

void func_8043C278_de(s32 *record) {
    record[4] = 1;
    record[5] = 0;
    record[6] = 1;
    func_8025DF34_de(0xE83);
}

/* Advances the counter at offset 0x14 of a record by the step at 0x10; once it reaches 0xD both
   are cleared and the state word at 0x18 becomes 2. */
void func_8043C2A4_de(s32 *record) {
    record[5] += record[4];
    if (record[5] >= 0xD) {
        record[5] = 0;
        record[4] = 0;
        record[6] = 2;
    }
}

/* Returns the word at offset 0x14 of a record. */
s32 func_8043C2D4_de(s32 *record) {
    return record[0x14 / 4];
}

/* Returns whether the word at offset 0x18 of a record equals 2; func_8043C308_de returns that word. */
s32 func_8043C2E0_de(s32 *record) {
    return record[0x18 / 4] == 2;
}

/* Stores a value into the first word of a record; func_8043C2F8_de, which follows it, fills the
   words after it. */
void func_8043C2F0_de(s32 *record, s32 value) {
    record[0] = value;
}

/* Stores three values into words 1 to 3 of a record; func_8043C2F0_de stores word 0. */
void func_8043C2F8_de(s32 *record, s32 first, s32 second, s32 third) {
    record[1] = first;
    record[2] = second;
    record[3] = third;
}

/* Returns the word at offset 0x18 of a record. */
s32 func_8043C308_de(s32 *record) {
    return record[0x18 / 4];
}
