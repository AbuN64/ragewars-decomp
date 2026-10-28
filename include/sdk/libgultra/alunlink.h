#ifndef SDK_LIBGULTRA_ALUNLINK_H
#define SDK_LIBGULTRA_ALUNLINK_H
#include "TYPES.H"
struct ListLink;
extern void alUnlink(struct ListLink *arg0);
extern void alLink(void *arg0, void **arg1);
#include "COMMON/CARTRIDGEREADWORKER.H"
extern void alClose(s32 *);
#endif
