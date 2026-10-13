#include "types.h"
#include "span_1000/code_802BE0D0.h"
s32 func_802BEF84_de(DecodeBlock *arg0,u16 *arg1,s16 arg2,u16 *arg3,void *arg4) {
    u16 node;
    s16 block,output;
    DecodeTable *table;
    DecodeNode *tree;
    u16 value;
    s32 mask,high; u16 topbit;
    DecodeNode *entry;
    s16 j;
    s32 dictOffset;
    u16 next;
    u16 *bits,*available;
    DecodePhrase *phrase;
    u16 *out;
    node=0;
    block=0;
    *arg3=0;
    table=arg0->table;
    tree=table->tree;
    output=0;
    if(arg2>0) {
    available=&D_800D54BC; bits=&D_800D54BA;
    do {
        if(*available!=0) {
            (*available)--;
            topbit=*bits & 0x8000;
            *bits<<=1;
            if(topbit) mask=tree[(s16)node].second;
            else mask=tree[(s16)node].first;
            entry=(s16)mask+tree;
            if(entry->first==0x800) {
                value=entry->second;
                mask=value & 0xF00;
                node=0;
                if(mask==0 || mask==0xF00) {
                    arg1[(s16)output]=value;
                    output++;
                } else if((s16)value==0x900) {
                    value=*bits;
                    if(func_802BEDB0_de(bits,table->width,1,0,arg4)==0) return -1;
                    out=output+arg1;
                    output++;
                    high=*bits;
                    mask=D_800D54BC;
                    *bits=high << (16-mask);
                    *out=value | ((s32)high >> mask);
                } else if(mask==0xA00) {
                    j=0;
                    dictOffset=(value&0xFF)*sizeof(DecodePhrase);
                    out=(s16)output+arg1;
                    phrase=&table->phrases[value & 0xFF];
                    while((s16)j<phrase->count) {
                        out[(s16)j]=phrase->samples[(s16)j].value;
                        j++;
                    }
                    output+=(s16)j;
                } else if(mask==0xB00) {
                    while((s16)output<arg2) arg1[(s16)output++]=0;
                    while(arg2>=arg0[(s16)block].start+arg0[(s16)block].length) {
                        block++;
                        (*arg3)++;
                    }
                    return arg2;
                }
                if((s16)output>=arg0[(s16)block].start+arg0[(s16)block].length) {
                    block++;
                    (*arg3)++;
                    table=arg0[(s16)block].table;
                    tree=table->tree;
                }
            } else node=mask;
        } else {
            if(func_802BEDB0_de(&D_800D54BA,16,1,0,arg4)==0) return -1;
            *available+=16;
        }
    } while((s16)output<arg2);
    }
    return (s16)output;
}
