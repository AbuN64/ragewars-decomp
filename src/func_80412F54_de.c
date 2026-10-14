#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80413728.h"
#include "common/unused.h"
#include "span_16E000/code_80412270.h"
extern Format D_800E2B20[];
extern void *D_80153C70,*D_80153C64;

void func_80412F54_de(ImageDescriptor *destination, ImageDescriptor *source) {
    Format dst,src;
    D_80153CDC=0;
    D_80153CD8=0;
    D_80153CD4=0;
    D_80153CD0=0;
    D_80153C88=0;
    D_80153C7C=0;
    D_80153C70=0;
    D_80153C64=0;
    D_80153C84=0;
    D_80153C78=0;
    D_80153C6C=0;
    D_80153C60=0;
    D_80153D58=0;
    D_80153D54=0;
    if(destination) {
        D_80153D58=(void *)destination;
        dst=D_800E2B20[destination->format];
        D_8014DA90=dst;
        if(dst.word[1]) D_80153C70=destination->pixels;
        else D_80153C70=destination->palette;
        if(dst.word[1]) D_80153C88=destination->palette;
        else D_80153C88=0;
        if(dst.word[3]==16) D_80153CD4=D_0041406C;
        else if(dst.word[3]==24) D_80153CD4=D_004140BC;
        else if(dst.word[3]==32) D_80153CD4=D_00414094;
        if(dst.word[2]==4) D_80153CDC=D_00414244;
        else if(dst.word[2]==8) D_80153CDC=D_00414220;
        D_8014DA10=dst.word[5];
        D_8014DA14=dst.word[6];
        D_8014DA18=dst.word[7];
        D_8014DA1C=dst.word[8];
        D_8014DA30=dst.word[9];
        D_8014DA34=dst.word[10];
        D_8014DA38=dst.word[11];
        D_8014DA3C=dst.word[12];
    }
    if(source) {
        D_80153D54=(void *)source;
        src=D_800E2B20[source->format];
        D_8014DA50=src;
        if(src.word[1]) D_80153C64=source->pixels;
        else D_80153C64=source->palette;
        if(src.word[1]) D_80153C7C=source->palette;
        else D_80153C7C=0;
        if(src.word[3]==16) D_80153CD0=D_00413FCC;
        else if(src.word[3]==24) D_80153CD0=D_00414024;
        else if(src.word[3]==32) D_80153CD0=D_00413FF8;
        if(src.word[2]==4) D_80153CD8=D_00414168;
        else if(src.word[2]==8) D_80153CD8=D_00414138;
        else if(src.word[2]==16) D_80153CD8=D_004141C0;
        else if(src.word[2]==24) D_80153CD8=D_004141E0;
        else if(src.word[2]==32) D_80153CD8=D_00414200;
        D_8014DA00=src.word[5];
        D_8014DA04=src.word[6];
        D_8014DA08=src.word[7];
        D_8014DA0C=src.word[8];
        D_8014DA20=src.word[9];
        D_8014DA24=src.word[10];
        D_8014DA28=src.word[11];
        D_8014DA2C=src.word[12];
    }
}
