#include "shared/level_spawn.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802508E0.h"
/* Returns the matching resource entry index, or minus one when absent. */
extern void *func_8028FDB4_de(int,int);



int func_80250938_de(void *wanted,int key) {
 int result=-1; int i,count,offset; char *entries;
 LevelNode *h=func_8028FDB4_de(key,0);
 count=h->count; entries=(char *)h->records;
i=0; if(count>0) {offset=i; do {if(entries+offset!=wanted) {i++;offset+=232;} else {result=i;break;}}while(i<count);}return result;}
