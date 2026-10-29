#ifndef LIBGULTRA_ALUNLINK_H
#define LIBGULTRA_ALUNLINK_H
#include "TYPES.H"
struct ListLink;
extern void alUnlink(struct ListLink *node);
extern void alLink(void *node, void **previousNode);
#include "COMMON/CARTRIDGEREADWORKER.H"
extern void alClose(s32 *);
#endif
