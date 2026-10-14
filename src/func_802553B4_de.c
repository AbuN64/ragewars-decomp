#include "span_1000/code_80254CE4.h"
#include "types.h"
/* Inserts or replaces a keyed value in the address hash table, probing odd overflow slots when its home chain is occupied. The new slot address is written as the scaled index plus the table address because the cartridge adds the index first; array indexing reorders the add and its registers (15 words). */

extern s32 D_80101190,D_80101198;
extern EntryRecAtCV1 *D_80101194;
void func_802553B4_de(u32 key,s32 value) {
 EntryRecAtCV1 *entry = D_80101194 + (((key<<5)^(key>>1)^(key>>9)^(key>>17)) & D_80101190);
 EntryRecAtCV1 *tail;
 EntryRecAtCV1 *slot;
 s32 index;
 if (entry->value == 0) {entry->key=key;entry->value=value;return;}
 tail=entry;
 for (;;) {
  if (entry->key==key) {entry->value=value;return;}
  entry=tail->next;
  if (!entry) break;
  tail=entry;
 }
 index=tail->index|1;
 while (D_80101194[index].value != 0) {index+=2; index &= D_80101198;}
 slot=(EntryRecAtCV1 *)((index << 4) + (u32)D_80101194);
 slot->key=key;slot->value=value;tail->next=slot;
}
