#include "span_16E000/code_80444030.h"
#include "types.h"

/* Resets the byte fields from offset 0x78 of a record, sets 0x79 to 0x86, 0x7A to 0x84 and 0x7D to
   one, stores the second argument at 0x7F, and calls 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_80444F30_eu
#else
func_804440F0_de
#endif
 on the record. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void func_80444F30_eu(u8 *);
#else
extern void func_804440F0_de(u8 *);
#endif

void func_80444094_de(u8 *record, u8 value) {
    record[0x79] = 0x86;
    record[0x7A] = 0x84;
    record[0x78] = 0;
    record[0x7C] = 0;
    record[0x7B] = 0;
    record[0x7D] = 1;
    record[0x7E] = 0;
    record[0x7F] = value;
    record[0x80] = 0;
    record[0x82] = 0;
    record[0x83] = 0;
    record[0x81] = 0;
    record[0x94] = 0;
    record[0x95] = 0;
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_80444F30_eu
#else
func_804440F0_de
#endif
(record);
}
