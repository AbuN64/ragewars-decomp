#include "span_16E000/code_80400000.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_802453D4_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "shared/func_804235A8_eu_layout.h"
#include "shared/func_8044DA54_de_closed.h"
#include "shared/texture_request.h"
#include "shared/track_tables.h"
#include "shared/world.h"
#include "span_1000/code_80245980.h"
#include "span_1000/code_802609CC.h"
#include "span_C76B0/data.h"
#include "types.h"

extern struct Shape_typemap_165 *func_80254480_de(s32,void *,s32);

extern void func_804002D8_de(s32,Vec3 *,f32 *,Spline *);

extern void func_80253D10_de(s32,struct Shape_typemap_165 **,struct Shape_typemap_165 *);

/* The pack append API tests the second ABI word for a nonzero preparation flag. */
static inline char *packAppend(Pack *pack,void *prepare,s32 size) { return func_802610F0_de(pack,(s32)prepare,size); }

static inline s32 splineRecordSize(s32 left,s32 right) { s32 a=left*9,b=right*9; return (b+a)*4+48; }

extern char D_800E0B2C;

extern s32 func_8028FE3C_de(void *,s32,s32,s32 *);

extern void func_80253754_de(void *,Node80253610 *);

static inline void minTime(f32 *dest,f32 *src) {
    if(*dest>*src)*dest=*src;
}

static inline void maxTime(f32 *dest,f32 *src) {
    if(*dest<*src)*dest=*src;
}

static inline void setTimes(f32 *a,f32 *b,f32 *c,f32 *t) {
    *a=*t;
    *b=*t;
    *c=*t;
}

void func_8040067C_de(s32 unused, struct Shape_typemap_165 **handle) {
    struct Shape_typemap_165 *output;
    void *source, *a, *b, *c, *part, *extra;
    Pack *pack, *dest;
    SplineTable *parts;
    Pack *table;
    SplineSourceCursor p,q,r,s;
    s32 count, i, size, sa, sb, sc, np, nr, byteP, byteR;
    void *dp, *dr;
    if (!func_80285180_de((void **)handle, 1)) return;
    source = (*handle)->pack;
    parts = func_8028FDB4_de(source, 0);
    a = func_8028FDB4_de(source, 1);
    b = func_8028FDB4_de(source, 2);
    c = func_8028FDB4_de(source, 3);
    count = parts->count;
    size = (count * 4 + 15) & ~7;
    for (i = 0; i < parts->count; i++) {
        SplineSource *firstP,*firstR;
        void *firstPart;
        s32 byteP,byteR;
        firstPart = func_8028FDB4_de(parts, i);
        firstP = func_8028FDB4_de(firstPart, 0);
        firstR = func_8028FDB4_de(firstPart, 2);
        size += splineRecordSize(firstP->count,firstR->count);
    }
    sc = func_8028FEB8_de(c);
    sa = func_8028FEB8_de(a);
    sb = func_8028FEB8_de(b);
    output = func_80254480_de(0, handle, size + sa + sb + sc + 24);
    if (output == 0) return;
    pack = output->pack;
    func_802610A8_de(pack, 4);
    table = (void *)packAppend(pack, 0, size);
    packAppend(pack, a, sa);
    packAppend(pack, b, sb);
    packAppend(pack, c, sc);
    func_802610A8_de(table, count);
    for (i = 0; i < count; i++) {
        s32 byteP,byteR;
        SplineSource *sizeP,*sizeR;
        part = func_8028FDB4_de(parts, i);
        sizeP = func_8028FDB4_de(part, 0);
        sizeR = func_8028FDB4_de(part, 2);
        byteP = sizeP->count * 9;
        byteR = sizeR->count * 9;
        dest = (void *)packAppend(table, 0, (byteR + byteP)*4 + 48);
        func_802610A8_de(dest, 3);
        p.header = func_8028FDB4_de(part, 0);
        q.header = func_8028FDB4_de(part, 1);
        r.header = func_8028FDB4_de(part, 2);
        s.header = func_8028FDB4_de(part, 3);
        extra = func_8028FDB4_de(part, 4);
        np = p.header->count;
        nr = r.header->count;
        { s32 pointBytes,otherBytes;
        pointBytes = np * 36 + 8;
        otherBytes = nr * 36 + 8;
        dp = packAppend(dest, 0, pointBytes);
        dr = packAppend(dest, 0, otherBytes);
        }
        p.points = p.header->points;
        q.weights = q.header->weights;
        r.points = r.header->points;
        s.weights = s.header->weights;
        packAppend(dest, extra, 8);
        func_804002D8_de(np, p.points, q.weights, dp);
        func_804002D8_de(nr, r.points, s.weights, dr);
    }
    func_80253D10_de(0, handle, output);
}

s32 func_804009F4_de(s32 index) {
    s32 size,size2,i,count,previous,pending,loaded;
    SharedTrackObject *captured;
    Shared_World *resources;
    void **owner,**table;
    Shared_TrackCues *cues;
    PositionKey *cue;
    Shared_TrackClip *clip;
    Shared_MenuContext *context,*scanContext;
    f32 total;
    captured=D_80145060.actorList;
    pending=D_800E2830->field58;
    resources=&D_8011FE88;
    if(resources->trackLookup==0 || resources->trackBundle==0) {
        failed:
        return 0;
    }
    else {
        if(D_800E2830->active!=0)func_80245B28_de();
        loaded=func_8028FE3C_de(resources->trackBundle,resources->trackLookup,index+1,&size);
        owner=func_8025193C_de(0,loaded,loaded,size,0x33,0,D_0040067C,D_800DCB10,1);
        if(owner==0)goto failed;
        D_800E2830->owner=owner;
        D_800E2830->resource=*owner;
        cues=func_80403ADC_de();
        cue=cues->cues;
        count=cues->count;
        total=0.0f;
        for(i=0;i<func_80403A64_de();i++) {
            clip=func_80403A90_de(i);
             {
                s32 n=clip->count;
                KeyRecAt1C *base=clip->keys;
                if(n>0) {
                    total+=base[n-1].time;
                }
            }
        }
        D_800E2830->start=0.0f;
        D_800E2830->end=total;
        D_800E2830->clipStart=0.0f;
        D_800E2830->clipEnd=total;
        i=0;
        if(count>0) {
            scanContext=D_800E2830;
            do {
                PositionKey *c=&cue[i];
                minTime(&scanContext->clipStart,&c->time);
                maxTime(&scanContext->clipEnd,&c->time);
                i++;
            }
            while(i<count);
        }
        setTimes(&D_800E2830->time,&D_800E2830->time20,&D_800E2830->time24,&D_800E2830->clipStart);
        previous=D_800E2830->spec.id8;
        loaded=func_8028FE3C_de(D_8011FEFC,D_8011BDFC,0,&size2);
        if(loaded==0)table=0;
        else table=func_8025193C_de(0,loaded,loaded,size2,0x33,0,0,&D_800E0B2C,1);
         {
            Shared_TrackTable *entries=*table;
            EntryRecAt48 *base=entries->entries;
            D_800E2830->pending=pending;
            D_800E2830->active=1;
            D_800E2830->spec=base[index];
        }
        D_800E2830->field50=0;
        D_800E2830->unknown40=0;
        D_800E2830->initialized44=0;
        D_800E2830->closed=0;
        D_800E2830->requestE0=D_800E2830->spec.id8;
        if((D_800E2830->spec.flags&1) && D_800E2830->target!=0) {
            D_800E2830->position=D_800E2830->target->prefix.position;
            D_800E2830->yaw=D_800E2830->target->yaw+D_800DCB18_de;
        }
        if(D_800E2830->spec.flags&2) {
            if(captured!=0) {
                D_800E2830->position=captured->prefix.position;
                D_800E2830->yaw=captured->yaw;
            }
            else {
                D_800E2830->position.x=0.0f;
                D_800E2830->position.y=0.0f;
                D_800E2830->position.z=0.0f;
                D_800E2830->yaw=0.0f;
            }
        }
        func_80253754_de(0,(void *)table);
        if(pending) {
            void (*first)();
            Shared_MenuVoidCallback second;
            context=D_800E2830;
            first=context->callbackE4;
            second=context->callbackE8;
            context->pending=1;
            context->field4C=0;
            context->callbackE4=0;
            context->callbackE8=0;
            context->mode=context->spec.flags&8;
            context->onClose=first;
            context->callback10=second;
            if(context->requestE0-10U<0x47U)context->mode=0;
            if(D_800E2830->requestE0-400U<4U)D_800E2830->mode=0;
        }
        else {
            if(D_800E2830->spec.id8<3)D_800E2830->requestE0=previous;
            D_800E2830->pending=0;
            D_800E2830->time=D_800E2830->start;
        }
        if(D_800E2830->spec.id8==0x9F)D_800E2830->mode=0;
        return 1;
    }
}

/* Evaluates a spline built by func_804002D8_de at weight w, returning the position: zero for no nodes, the first or last node's position outside the weight range, and otherwise locates the weight segment, eases the arc length across it with a cubic blend of the neighbouring arc-length spacings, locates the arc-length segment and interpolates the position with the stored second derivatives. */





Vec3 func_80400E50_de(SplineNode *nodes, s32 count, f32 w) {
    Vec3 out;
    SplineNode *a;
    SplineNode *b;
    s32 i;
    f32 before;
    f32 across;
    f32 after;
    f32 inSlope;
    f32 outSlope;
    f32 u;
    f32 aw;
    f32 bw;
    f32 as;
    f32 bs;
    f32 s;
    f32 start;
    f32 h;
    f32 hi;
    f32 lo;
    f32 h2;

    a = 0;
    b = 0;
    if (count == 0) {
        out.x = 0.0f;
        out.y = 0.0f;
        out.z = 0.0f;
    } else if (count == 1 || w <= nodes[0].w) {
        out.x = nodes[0].p.x;
        out.y = nodes[0].p.y;
        out.z = nodes[0].p.z;
    } else if (nodes[count - 1].w <= w) {
        out.x = nodes[count - 1].p.x;
        out.y = nodes[count - 1].p.y;
        out.z = nodes[count - 1].p.z;
    } else {
        for (i = 0; i < count - 1; i++) {
            a = &nodes[i];
            b = &nodes[i + 1];
            if (a->w <= w && w < b->w) {
                break;
            }
        }
        across = 0.0f;
        before = 0.0f;
        after = 0.0f;
        if (i > 0) {
            before = nodes[i].s - nodes[i - 1].s;
        }
        if (i < count - 1) {
            across = nodes[i + 1].s - nodes[i].s;
        }
        if (i < count - 2) {
            after = nodes[i + 2].s - nodes[i + 1].s;
        }
        inSlope = across;
        if (!(inSlope <= before)) {
            inSlope = before;
        }
        outSlope = after;
        if (!(outSlope <= across)) {
            outSlope = across;
        }
        aw = a->w;
        bw = b->w;
        as = a->s;
        bs = b->s;
        if (aw != bw) {
            u = (w - aw) / (bw - aw);
        } else {
            u = 0.0f;
        }
        s = as * (1.0f - u) + bs * u + (inSlope - (bs - as)) * (u - (u + u) * u + u * u * u) + (outSlope - (bs - as)) * (u * u * u - u * u);
        for (i = 0; i < count - 1; i++) {
            a = &nodes[i];
            b = &nodes[i + 1];
            if (a->s <= s && s < b->s) {
                break;
            }
        }
        start = a->s;
        h = b->s - start;
        hi = 0.0f;
        if (h != 0.0f) {
            hi = (s - start) / h;
        }
        h2 = h * h;
        lo = 1.0f - hi;
        out.x = a->p.x * lo + b->p.x * hi + (a->d2p.x * (lo * lo * lo - lo) + b->d2p.x * (hi * hi * hi - hi)) * h2 * 0.16666667f;
        out.y = a->p.y * lo + b->p.y * hi + (a->d2p.y * (lo * lo * lo - lo) + b->d2p.y * (hi * hi * hi - hi)) * h2 * 0.16666667f;
        out.z = a->p.z * lo + b->p.z * hi + (a->d2p.z * (lo * lo * lo - lo) + b->d2p.z * (hi * hi * hi - hi)) * h2 * 0.16666667f;
    }
    return out;
}
